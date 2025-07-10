#include "s21_sprintf/int_convert.h"

#include <stdint.h>

#include "s21_sprintf/util.h"
#include "s21_string.h"

#define DIGITS "0123456789abcdef"
#define BIG_DIGITS "0123456789ABCDEF"

#define CONVERT_NON_NEGATIVE_INTEGER(dest, num, num_str, prefix, base,      \
                                     fmt_opts)                              \
  const char* digits_alphabet = fmt_opts->upper_case ? BIG_DIGITS : DIGITS; \
  int precision = fmt_opts->precision;                                      \
  s21_size_t i = 0;                                                         \
  s21_size_t l = i;                                                         \
                                                                            \
  if (num == 0) {                                                           \
    num_str[i] = '0';                                                       \
    ++i;                                                                    \
  }                                                                         \
                                                                            \
  while (num != 0) {                                                        \
    int digit = num % base;                                                 \
    num_str[i] = digits_alphabet[digit];                                    \
                                                                            \
    ++i;                                                                    \
    num /= base;                                                            \
  }                                                                         \
  num_str[i] = '\0';                                                        \
  s21_size_t r = i - 1;                                                     \
                                                                            \
  ReverseString(num_str, l, r);                                             \
                                                                            \
  s21_size_t num_str_len = s21_strlen(num_str);                             \
  s21_size_t prefix_len = s21_strlen(prefix);                               \
  if (precision == -1 && fmt_opts->leading_zeros &&                         \
      fmt_opts->alignment == kRight) {                                      \
    precision = Max(0, fmt_opts->min_width - (int)prefix_len);              \
  }                                                                         \
  int zeroes_count = Max(0, precision - (int)i);                            \
  s21_strncat(dest, prefix, prefix_len);                                    \
  dest += prefix_len;                                                       \
  FillString(dest, '0', zeroes_count);                                      \
  dest += (s21_size_t)zeroes_count;                                         \
  s21_strncat(dest, num_str, num_str_len);                                  \
  return (int)prefix_len + zeroes_count + (int)num_str_len;

#define PLUS_PREFIX "+"
#define MINUS_PREFIX "-"
#define SPACE_PREFIX " "
#define EMPTY_PREFIX ""

#define CONVERT_INTEGER(dest, num, num_str, base, fmt_opts) \
  const char* prefix = "";                                  \
  if (fmt_opts->prefix_sign && num >= 0) {                  \
    prefix = PLUS_PREFIX;                                   \
  } else if (num < 0) {                                     \
    prefix = MINUS_PREFIX;                                  \
    num = -num;                                             \
  } else if (fmt_opts->prefix_space) {                      \
    prefix = SPACE_PREFIX;                                  \
  }                                                         \
  CONVERT_NON_NEGATIVE_INTEGER(dest, num, num_str, prefix, base, fmt_opts)

#define OCT_PREFIX "0"
#define HEX_PREFIX "0x"
#define BIG_HEX_PREFIX "0X"

#define HANDLE_ALTERNATIVE_FORM(dest, num, num_str, base, fmt_opts) \
  const char* prefix = "";                                          \
  if (fmt_opts->alternative_form && num != 0) {                     \
    if (base == 8) {                                                \
      prefix = OCT_PREFIX;                                          \
    } else if (base == 16) {                                        \
      prefix = fmt_opts->upper_case ? BIG_HEX_PREFIX : HEX_PREFIX;  \
    }                                                               \
  }

#define SHORT_STR_MAX_SIZE 7  // "-32768'\0'"
#define INT_STR_MAX_SIZE 12   // "−2147483648'\0'"
#define LONG_STR_MAX_SIZE 21  // "−9223372036854775808'\0'"
#define LONG_LONG_STR_MAX_SIZE 21
#define LONG_LONG_LONG_STR_MAX_SIZE \
  41  // "2^128 = 3,4028237×10^38" + 1 (sign) + 1('\0')

int AppendInt(char* dest, int num, const FormatOptions* fmt_opts) {
  char num_str[INT_STR_MAX_SIZE];

  CONVERT_INTEGER(dest, num, num_str, 10, fmt_opts);
}

int AppendUnsignedInt(char* dest, unsigned int num,
                      const FormatOptions* fmt_opts) {
  char num_str[INT_STR_MAX_SIZE];

  CONVERT_NON_NEGATIVE_INTEGER(dest, num, num_str, EMPTY_PREFIX, 10, fmt_opts);
}

int AppendShort(char* dest, short num, const FormatOptions* fmt_opts) {
  char num_str[SHORT_STR_MAX_SIZE];

  CONVERT_INTEGER(dest, num, num_str, 10, fmt_opts);
}

int AppendUnsignedShort(char* dest, unsigned short num,
                        const FormatOptions* fmt_opts) {
  char num_str[SHORT_STR_MAX_SIZE];

  CONVERT_NON_NEGATIVE_INTEGER(dest, num, num_str, EMPTY_PREFIX, 10, fmt_opts);
}

int AppendLong(char* dest, long num, const FormatOptions* fmt_opts) {
  char num_str[LONG_STR_MAX_SIZE];

  CONVERT_INTEGER(dest, num, num_str, 10, fmt_opts);
}

int AppendUnsignedLong(char* dest, unsigned long num,
                       const FormatOptions* fmt_opts) {
  char num_str[LONG_STR_MAX_SIZE];

  CONVERT_NON_NEGATIVE_INTEGER(dest, num, num_str, EMPTY_PREFIX, 10, fmt_opts);
}

int AppendUnsignedLongLongLong(char* dest, __uint128_t num,
                               const FormatOptions* fmt_opts) {
  char num_str[LONG_LONG_LONG_STR_MAX_SIZE];

  CONVERT_NON_NEGATIVE_INTEGER(dest, num, num_str, EMPTY_PREFIX, 10, fmt_opts);
}

#define SHORT_OCT_STR_MAX_SIZE \
  8                              // 16 / 3 + 1 (alternative_form '0') + 1 ('\0')
#define INT_OCT_STR_MAX_SIZE 13  // 32 / 3 + 1 (alternative_form '0') + 1 ('\0')
#define LONG_OCT_STR_MAX_SIZE \
  24  // 64 / 3 + 1 (alternative_form '0') + 1 ('\0')
#define SHORT_HEX_STR_MAX_SIZE \
  7  // 16 / 4 + 2 (alternative_form '0x') + 1 ('\0')
#define INT_HEX_STR_MAX_SIZE \
  11  // 32 / 4 + 2 (alternative_form '0x') + 1 ('\0')
#define LONG_HEX_STR_MAX_SIZE \
  19  // 64 / 4 + 2 (alternative_form '0x') + 1 ('\0')

int AppendIntUnsignedOct(char* dest, unsigned int num,
                         const FormatOptions* fmt_opts) {
  char num_str[INT_OCT_STR_MAX_SIZE];

  HANDLE_ALTERNATIVE_FORM(dest, num, num_str, 8, fmt_opts);
  CONVERT_NON_NEGATIVE_INTEGER(dest, num, num_str, prefix, 8, fmt_opts);
}

int AppendShortUnsignedOct(char* dest, unsigned short num,
                           const FormatOptions* fmt_opts) {
  char num_str[SHORT_OCT_STR_MAX_SIZE];

  HANDLE_ALTERNATIVE_FORM(dest, num, num_str, 8, fmt_opts);
  CONVERT_NON_NEGATIVE_INTEGER(dest, num, num_str, prefix, 8, fmt_opts);
}

int AppendLongUnsignedOct(char* dest, unsigned long num,
                          const FormatOptions* fmt_opts) {
  char num_str[LONG_OCT_STR_MAX_SIZE];

  HANDLE_ALTERNATIVE_FORM(dest, num, num_str, 8, fmt_opts);
  CONVERT_NON_NEGATIVE_INTEGER(dest, num, num_str, prefix, 8, fmt_opts);
}

int AppendIntUnsignedHex(char* dest, unsigned int num,
                         const FormatOptions* fmt_opts) {
  char num_str[INT_HEX_STR_MAX_SIZE];

  HANDLE_ALTERNATIVE_FORM(dest, num, num_str, 16, fmt_opts);
  CONVERT_NON_NEGATIVE_INTEGER(dest, num, num_str, prefix, 16, fmt_opts);
}

int AppendShortUnsignedHex(char* dest, unsigned short num,
                           const FormatOptions* fmt_opts) {
  char num_str[SHORT_HEX_STR_MAX_SIZE];

  HANDLE_ALTERNATIVE_FORM(dest, num, num_str, 16, fmt_opts);
  CONVERT_NON_NEGATIVE_INTEGER(dest, num, num_str, prefix, 16, fmt_opts);
}

int AppendLongUnsignedHex(char* dest, unsigned long num,
                          const FormatOptions* fmt_opts) {
  char num_str[LONG_HEX_STR_MAX_SIZE];

  HANDLE_ALTERNATIVE_FORM(dest, num, num_str, 16, fmt_opts);
  CONVERT_NON_NEGATIVE_INTEGER(dest, num, num_str, prefix, 16, fmt_opts);
}

#define PLUS_POINTER_PREFIX "+0x"
#define SPACE_POINTER_PREFIX " 0x"

int AppendVoidPointer(char* dest, void* ptr, const FormatOptions* fmt_opts) {
  char num_str[LONG_HEX_STR_MAX_SIZE];
  uintptr_t num = (uintptr_t)ptr;

  const char* prefix = "0x";
  if (fmt_opts->prefix_sign) {
    prefix = PLUS_POINTER_PREFIX;
  } else if (fmt_opts->prefix_space) {
    prefix = SPACE_POINTER_PREFIX;
  }

  CONVERT_NON_NEGATIVE_INTEGER(dest, num, num_str, prefix, 16, fmt_opts);
}
