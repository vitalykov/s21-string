#include "s21_sprintf/formatter.h"

#include "s21_sprintf/chars_convert.h"
#include "s21_sprintf/float_convert.h"
#include "s21_sprintf/format_options.h"
#include "s21_sprintf/int_convert.h"
#include "s21_sprintf/parser.h"
#include "s21_sprintf/util.h"
#include "s21_string.h"

static int HandleIntSpecifier(char* value_str, const FormatOptions* fmt_opts,
                              va_list* params) {
  int chars_count = 0;
  switch (fmt_opts->modifier) {
    case kDefault:
      chars_count += AppendInt(value_str, va_arg(*params, int), fmt_opts);
      break;
    case kShort:
      chars_count +=
          AppendShort(value_str, (short)va_arg(*params, int), fmt_opts);
      break;
    case kLong:
    case kLongDouble:
      chars_count += AppendLong(value_str, va_arg(*params, long), fmt_opts);
      break;
  }

  return chars_count;
}

static int HandleUnsignedIntSpecifier(char* value_str,
                                      const FormatOptions* fmt_opts,
                                      va_list* params) {
  int chars_count = 0;
  switch (fmt_opts->modifier) {
    case kDefault:
      chars_count +=
          AppendUnsignedInt(value_str, va_arg(*params, unsigned), fmt_opts);
      break;
    case kShort:
      chars_count += AppendUnsignedShort(
          value_str, (unsigned short)va_arg(*params, int), fmt_opts);
      break;
    case kLong:
    case kLongDouble:
      chars_count += AppendUnsignedLong(
          value_str, va_arg(*params, unsigned long), fmt_opts);
      break;
  }

  return chars_count;
}

static int HandleFloatSpecifier(char* value_str, const FormatOptions* fmt_opts,
                                va_list* params) {
  int chars_count = 0;
  switch (fmt_opts->modifier) {
    case kDefault:
    case kShort:
    case kLong:
      chars_count += AppendFloat(value_str, va_arg(*params, double), fmt_opts);
      break;
    case kLongDouble:
      chars_count +=
          AppendFloat(value_str, va_arg(*params, long double), fmt_opts);
      break;
  }

  return chars_count;
}

static int HandleExpFloatSpecifier(char* value_str, FormatOptions* fmt_opts,
                                   va_list* params) {
  int chars_count = 0;
  switch (fmt_opts->modifier) {
    case kDefault:
    case kShort:
    case kLong:
      chars_count +=
          AppendExponentialFloat(value_str, va_arg(*params, double), fmt_opts);
      break;
    case kLongDouble:
      chars_count += AppendExponentialFloat(
          value_str, va_arg(*params, long double), fmt_opts);
      break;
  }

  return chars_count;
}

static int HandleGeneralFloatSpecifier(char* value_str, FormatOptions* fmt_opts,
                                       va_list* params) {
  int chars_count = 0;
  switch (fmt_opts->modifier) {
    case kDefault:
    case kShort:
    case kLong:
      chars_count +=
          AppendGeneralFloat(value_str, va_arg(*params, double), fmt_opts);
      break;
    case kLongDouble:
      chars_count +=
          AppendGeneralFloat(value_str, va_arg(*params, long double), fmt_opts);
      break;
  }

  return chars_count;
}

static int HandleOctIntSpecifier(char* value_str, const FormatOptions* fmt_opts,
                                 va_list* params) {
  int chars_count = 0;
  switch (fmt_opts->modifier) {
    case kDefault:
      chars_count +=
          AppendIntUnsignedOct(value_str, va_arg(*params, unsigned), fmt_opts);
      break;
    case kShort:
      chars_count += AppendShortUnsignedOct(
          value_str, (unsigned short)va_arg(*params, unsigned), fmt_opts);
      break;
    case kLong:
    case kLongDouble:
      chars_count += AppendLongUnsignedOct(
          value_str, va_arg(*params, unsigned long), fmt_opts);
      break;
  }

  return chars_count;
}

static int HandleHexIntSpecifier(char* value_str, const FormatOptions* fmt_opts,
                                 va_list* params) {
  int chars_count = 0;
  switch (fmt_opts->modifier) {
    case kDefault:
      chars_count +=
          AppendIntUnsignedHex(value_str, va_arg(*params, unsigned), fmt_opts);
      break;
    case kShort:
      chars_count += AppendShortUnsignedHex(
          value_str, (unsigned short)va_arg(*params, unsigned), fmt_opts);
      break;
    case kLong:
    case kLongDouble:
      chars_count += AppendLongUnsignedHex(
          value_str, va_arg(*params, unsigned long), fmt_opts);
      break;
  }

  return chars_count;
}

static int HandlePointerSpecifier(char* value_str,
                                  const FormatOptions* fmt_opts,
                                  va_list* params) {
  int chars_count = 0;

  void* ptr = va_arg(*params, void*);
  if (ptr != S21_NULL) {
    chars_count += AppendVoidPointer(value_str, ptr, fmt_opts);
  } else {
    chars_count += AppendString(value_str, "(nil)", -1);
  }

  return chars_count;
}

static int HandleCharSpecifier(char* value_str, const FormatOptions* fmt_opts,
                               va_list* params) {
  int chars_count = 0;
  switch (fmt_opts->modifier) {
    case kDefault:
    case kShort:
      chars_count += AppendChar(value_str, va_arg(*params, int));
      break;
    case kLong:
    case kLongDouble:
      chars_count += AppendLongChar(value_str, va_arg(*params, wint_t));
      break;
  }

  return chars_count;
}

static int HandleStringSpecifier(char* value_str, const FormatOptions* fmt_opts,
                                 va_list* params) {
  int chars_count = 0;
  switch (fmt_opts->modifier) {
    case kDefault:
    case kShort:
      chars_count +=
          AppendString(value_str, va_arg(*params, char*), fmt_opts->precision);
      break;
    case kLong:
    case kLongDouble:
      chars_count += AppendLongString(value_str, va_arg(*params, wchar_t*),
                                      fmt_opts->precision);
      break;
  }

  return chars_count;
}

static int ApplyFormatting(char* str, const char* value_str, int chars_count,
                           const FormatOptions* fmt_opts) {
  int width = fmt_opts->min_width;

  if (fmt_opts->alignment == kLeft) {
    s21_strncat(str, value_str, chars_count);
    str += chars_count;
    int suffix_len = Max(width - chars_count, 0);
    FillString(str, ' ', suffix_len);
  } else {
    int prefix_len = Max(width - chars_count, 0);
    FillString(str, ' ', prefix_len);
    str += (s21_size_t)prefix_len;
    s21_strncat(str, value_str, chars_count);
  }

  return Max(chars_count, width);
}

static int AppendFormattedValue(char* str, FormatOptions* fmt_opts,
                                va_list* params) {
  int chars_count = 0;
  char value_str[MAX_VALUE_LEN] = "";
  Specifier specifier = fmt_opts->specifier;

  switch (specifier) {
    case kInt:
      chars_count = HandleIntSpecifier(value_str, fmt_opts, params);
      break;
    case kUnsignedInt:
      chars_count = HandleUnsignedIntSpecifier(value_str, fmt_opts, params);
      break;
    case kFloat:
      chars_count = HandleFloatSpecifier(value_str, fmt_opts, params);
      break;
    case kExpFloat:
      chars_count = HandleExpFloatSpecifier(value_str, fmt_opts, params);
      break;
    case kGeneralFloat:
      chars_count = HandleGeneralFloatSpecifier(value_str, fmt_opts, params);
      break;
    case kOctInt:
      chars_count = HandleOctIntSpecifier(value_str, fmt_opts, params);
      break;
    case kHexInt:
      chars_count = HandleHexIntSpecifier(value_str, fmt_opts, params);
      break;
    case kPointer:
      chars_count = HandlePointerSpecifier(value_str, fmt_opts, params);
      break;
    case kChar:
      chars_count = HandleCharSpecifier(value_str, fmt_opts, params);
      break;
    case kString:
      chars_count = HandleStringSpecifier(value_str, fmt_opts, params);
      break;
    case kPercent:
      chars_count = AppendChar(str, '%');
      break;
    case kInvalid:
      chars_count = -1;
      break;
  }

  if (specifier != kPercent && specifier != kInvalid) {
    chars_count = ApplyFormatting(str, value_str, chars_count, fmt_opts);
  }

  return chars_count;
}

int ProcessFormat(char** fmt_ptr, char* str, va_list* params) {
  FormatOptions fmt_opts;
  InitFormatOptions(&fmt_opts);
  ParseFormat(fmt_ptr, &fmt_opts, params);
  int chars_count = AppendFormattedValue(str, &fmt_opts, params);

  return chars_count;
}
