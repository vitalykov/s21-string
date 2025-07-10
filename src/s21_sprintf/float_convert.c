#include "s21_sprintf/float_convert.h"

#include <math.h>
#include <stdlib.h>

#include "s21_sprintf/format_options.h"
#include "s21_sprintf/int_convert.h"
#include "s21_sprintf/util.h"
#include "s21_string.h"
#include "s21_strlib/s21_strlib.h"

#define LONG_DOUBLE_GARBAGE 48
#define LONG_DOUBLE_SIGN_BITS 1
#define LONG_DOUBLE_EXPONENT_BITS 15
#define LONG_DOUBLE_INT_BIT 1
#define LONG_DOUBLE_MANTISSA_BITS 63

#define MAX_PRECISION 32

static __uint128_t LongDoubleToBits(const long double f) {
  __uint128_t bits = 0;
  s21_memcpy(&bits, &f, sizeof(long double));
  return bits;
}

static void HandleSign(char* dest, int* i, long double num, bool prefix_sign,
                       bool prefix_space) {
  __uint128_t num_bits = LongDoubleToBits(num);

  bool sign = ((num_bits >> (LONG_DOUBLE_EXPONENT_BITS + LONG_DOUBLE_INT_BIT +
                             LONG_DOUBLE_MANTISSA_BITS)) &
               1) != 0;
  if (prefix_sign && !sign) {
    PutChar(dest + (*i), '+');
    ++(*i);
  } else if (sign) {
    PutChar(dest + (*i), '-');
    ++(*i);
  } else if (prefix_space) {
    PutChar(dest + (*i), ' ');
    ++(*i);
  }
}

static bool IsSpecialFloat(long double num) {
  return (isnan(num) || isinf(num));
}

static void HandleSpecialFloat(char* dest, int* i, long double num,
                               bool upper_case) {
  const char* nan_str = (upper_case ? "NAN" : "nan");
  const char* inf_str = (upper_case ? "INF" : "inf");
  const char* num_str = isnan(num) ? nan_str : inf_str;
  s21_size_t len_num_str = s21_strlen(num_str);
  s21_strncat(dest + (*i), num_str, len_num_str);
  *i += len_num_str;
}

static long double NormalizeFloat(long double num, int* decimal_exp) {
  long double normalized_num = num;

  if (normalized_num != 0) {
    long double pow = 1L;
    while (fabsl(normalized_num) * pow < 1) {
      pow *= 10;
      --(*decimal_exp);
    }
    normalized_num *= pow;
    pow = 1L;
    while (fabsl(normalized_num) / pow >= 10) {
      pow *= 10;
      ++(*decimal_exp);
    }
    normalized_num /= pow;
  }

  return normalized_num;
}

static void HandleNormalizedFloat(char* dest, long double num, int* i,
                                  int precision, bool alternative_form) {
  __uint128_t before_point = (__uint128_t)fabsl(num);
  FormatOptions default_opts = GetDefaultFmtOpts();
  int before_point_len =
      AppendUnsignedLongLongLong(dest + *i, before_point, &default_opts);
  *i += before_point_len;

  int max_after_point_precision =
      (int)fmin(precision, MAX_PRECISION - before_point_len);

  if (max_after_point_precision > 0 || alternative_form) {
    PutChar(dest + (*i), '.');
    ++(*i);
  }

  if (max_after_point_precision > 0) {
    __uint128_t after_point = (__uint128_t)roundl(
        (fabsl(num) - before_point) * powl(10L, max_after_point_precision));
    int after_point_len = 0;
    while (after_point &&
           after_point < (__uint128_t)powl(10L, max_after_point_precision -
                                                    after_point_len - 1)) {
      PutChar(dest + (*i), '0');
      ++(*i);
      ++after_point_len;
    }
    if (after_point) {
      int appended_len =
          AppendUnsignedLongLongLong(dest + *i, after_point, &default_opts);
      after_point_len += appended_len;
      *i += appended_len;
    }
    for (int j = after_point_len; j < precision; ++j) {
      PutChar(dest + (*i), '0');
      ++(*i);
    }
  }
}

static void HandleExponent(char* dest, int* i, int decimal_exp,
                           bool upper_case) {
  char exponent_ch = upper_case ? 'E' : 'e';
  PutChar(dest + (*i), exponent_ch);
  ++(*i);

  if (decimal_exp >= 0) {
    PutChar(dest + (*i), '+');
    ++(*i);
  } else {
    PutChar(dest + (*i), '-');
    ++(*i);
  }

  FormatOptions fmt_opts;
  InitFormatOptions(&fmt_opts);
  fmt_opts.precision = 2;
  (*i) += AppendUnsignedInt(dest + *i, abs(decimal_exp), &fmt_opts);
}

static int RemoveTrailingZeros(char* dest, int cur_pos, int precision,
                               bool alternative_form) {
  int count_zeros = 0;

  if (!alternative_form && !(precision == 0)) {
    while (cur_pos > 0 && dest[cur_pos - 1] == '0') {
      dest[cur_pos - 1] = '\0';
      ++count_zeros;
      --cur_pos;
    }
    if (cur_pos > 0 && dest[cur_pos - 1] == '.') {
      dest[cur_pos - 1] = '\0';
      ++count_zeros;
    }
  }

  return count_zeros;
}

static void HandleLeadingZeros(char** dest, const char* num_str, int width,
                               int* i) {
  int num_i = 0;
  int zeros_count = Max(0, width - *i);
  *i += zeros_count;
  if (!s21_isdigit(num_str[num_i])) {
    **dest = num_str[num_i];
    *dest += 1;
    ++num_i;
  }

  FillString(*dest, '0', zeros_count);
  *dest += zeros_count;
  s21_strncat(*dest, num_str + num_i, s21_strlen(num_str));
}

int AppendFloat(char* dest, long double num, const FormatOptions* fmt_opts) {
  int i = 0;
  int precision = (fmt_opts->precision == -1) ? 6 : fmt_opts->precision;

  char* num_str;
  if (fmt_opts->specifier == kFloat && fmt_opts->leading_zeros &&
      !IsSpecialFloat(num)) {
    num_str = malloc(MAX_VALUE_LEN * sizeof(char));
  } else {
    num_str = dest;
  }

  HandleSign(num_str, &i, num, fmt_opts->prefix_sign, fmt_opts->prefix_space);
  if (IsSpecialFloat(num)) {
    HandleSpecialFloat(num_str, &i, num, fmt_opts->upper_case);
  } else {
    HandleNormalizedFloat(num_str, num, &i, precision,
                          fmt_opts->alternative_form);
    if (fmt_opts->specifier == kFloat && fmt_opts->leading_zeros) {
      HandleLeadingZeros(&dest, num_str, fmt_opts->min_width, &i);
    }
  }

  if (num_str != dest) free(num_str);
  return i;
}

int AppendExponentialFloat(char* dest, long double num,
                           FormatOptions* fmt_opts) {
  int i = 0;
  fmt_opts->precision = (fmt_opts->precision == -1) ? 6 : fmt_opts->precision;

  char* num_str;
  if (fmt_opts->leading_zeros && !IsSpecialFloat(num)) {
    num_str = malloc(MAX_VALUE_LEN * sizeof(char));
  } else {
    num_str = dest;
  }

  if (IsSpecialFloat(num)) {
    i += AppendFloat(num_str, num, fmt_opts);
  } else {
    int decimal_exp = 0;
    long double normalized_num = NormalizeFloat(num, &decimal_exp);
    i += AppendFloat(num_str, normalized_num, fmt_opts);
    HandleExponent(num_str, &i, decimal_exp, fmt_opts->upper_case);

    if (fmt_opts->leading_zeros) {
      HandleLeadingZeros(&dest, num_str, fmt_opts->min_width, &i);
    }
  }

  if (num_str != dest) free(num_str);

  return i;
}

int AppendGeneralFloat(char* dest, long double num, FormatOptions* fmt_opts) {
  int i = 0;
  if (fmt_opts->precision == -1) {
    fmt_opts->precision = 6;
  } else if (fmt_opts->precision == 0) {
    fmt_opts->precision = 1;
  }

  char* num_str;
  if (fmt_opts->leading_zeros && !IsSpecialFloat(num)) {
    num_str = malloc(MAX_VALUE_LEN * sizeof(char));
  } else {
    num_str = dest;
  }

  if (IsSpecialFloat(num)) {
    i += AppendFloat(num_str, num, fmt_opts);
  } else {
    int decimal_exp = 0;
    long double normalized_num = NormalizeFloat(num, &decimal_exp);
    if (decimal_exp < -4 || decimal_exp >= fmt_opts->precision) {
      fmt_opts->precision -= 1;
      i += AppendFloat(num_str, normalized_num, fmt_opts);
      i -= RemoveTrailingZeros(num_str, i, fmt_opts->precision,
                               fmt_opts->alternative_form);
      HandleExponent(num_str, &i, decimal_exp, fmt_opts->upper_case);
    } else {
      fmt_opts->precision -= (decimal_exp + 1);
      i += AppendFloat(num_str, num, fmt_opts);
      i -= RemoveTrailingZeros(num_str, i, fmt_opts->precision,
                               fmt_opts->alternative_form);
    }
    if (fmt_opts->leading_zeros) {
      HandleLeadingZeros(&dest, num_str, fmt_opts->min_width, &i);
    }
  }

  if (num_str != dest) free(num_str);

  return i;
}
