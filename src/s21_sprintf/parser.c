#include "s21_sprintf/parser.h"

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

#include "s21_sprintf/util.h"
#include "s21_string.h"
#include "s21_strlib/s21_strlib.h"

#define FLAGS "+-#0 "
#define LEFT_JUSTIFIED '-'
#define PREFIX_SIGN '+'
#define PREFIX_SPACE ' '
#define LEADING_ZEROS '0'
#define ALTERNATIVE_FORMAT '#'

static int HandleFlags(char** fmt_ptr, FormatOptions* fmt_opts) {
  int ch = NextChar(fmt_ptr);
  while (s21_strchr(FLAGS, ch) != S21_NULL && ch != '\0') {
    switch (ch) {
      case LEFT_JUSTIFIED:
        fmt_opts->alignment = kLeft;
        break;
      case PREFIX_SIGN:
        fmt_opts->prefix_sign = true;
        fmt_opts->prefix_space = false;
        break;
      case PREFIX_SPACE:
        fmt_opts->prefix_space = !fmt_opts->prefix_sign;
        break;
      case LEADING_ZEROS:
        fmt_opts->leading_zeros = true;
        break;
      case ALTERNATIVE_FORMAT:
        fmt_opts->alternative_form = true;
        break;
    }

    ch = NextChar(fmt_ptr);
  }

  return ch;
}

#define ASTERISK '*'
#define INT_STR_MAX_SIZE 12

static int HandleFieldWidth(char** fmt_ptr, FormatOptions* fmt_opts,
                            va_list* params, int last_ch) {
  char width_str[INT_STR_MAX_SIZE];
  int ch = last_ch;
  s21_size_t i = 0;
  while (s21_isdigit(ch)) {
    width_str[i] = ch;
    ++i;
    ch = NextChar(fmt_ptr);
  }
  width_str[i] = '\0';
  if (s21_strlen(width_str) != 0) {
    fmt_opts->min_width = (int)s21_strtol(width_str, NULL, 10);
  } else if (ch == ASTERISK) {
    fmt_opts->min_width = va_arg(*params, int);
    ch = NextChar(fmt_ptr);
  }

  return ch;
}

#define PRECISION '.'

static int HandlePrecision(char** fmt_ptr, FormatOptions* fmt_opts,
                           va_list* params, int last_ch) {
  int ch = last_ch;
  if (ch == PRECISION) {
    ch = NextChar(fmt_ptr);
    char precision_str[INT_STR_MAX_SIZE];
    s21_size_t i = 0;
    while (s21_isdigit(ch)) {
      precision_str[i] = ch;
      ++i;
      ch = NextChar(fmt_ptr);
    }
    precision_str[i] = '\0';
    if (s21_strlen(precision_str) != 0) {
      fmt_opts->precision = (int)s21_strtol(precision_str, NULL, 10);
    } else if (ch == ASTERISK) {
      fmt_opts->precision = va_arg(*params, int);
      ch = NextChar(fmt_ptr);
    }
  }

  return ch;
}

#define MODIFIERS "lhL"
#define LONG_MODIFIER 'l'
#define SHORT_MODIFIER 'h'
#define LONG_DOUBLE_MODIFIER 'L'

static int HandleModifier(char** fmt_ptr, FormatOptions* fmt_opts,
                          int last_ch) {
  int ch = last_ch;
  if (s21_strchr(MODIFIERS, ch) != S21_NULL && ch != '\0') {
    switch (ch) {
      case SHORT_MODIFIER:
        fmt_opts->modifier = kShort;
        break;
      case LONG_MODIFIER:
        fmt_opts->modifier = kLong;
        break;
      case LONG_DOUBLE_MODIFIER:
        fmt_opts->modifier = kLongDouble;
        break;
    }

    ch = NextChar(fmt_ptr);
  }

  return ch;
}

#define INT_SPECIFIER 'd'
#define ALT_INT_SPECIFIER 'i'
#define UNSIGNED_INT_SPECIFIER 'u'
#define DEFAULT_FLOAT_SPECIFIER 'f'
#define EXPONENTIAL_FLOAT_SPECIFIER 'e'
#define BIG_EXPONENTIAL_SPECIFIER 'E'
#define GENERAL_FLOAT_SPECIFIER 'g'
#define BIG_GENERAL_FLOAT_SPECIFIER 'G'
#define OCT_SPECIFIER 'o'
#define HEX_SPECIFIER 'x'
#define BIG_HEX_SPECIFIER 'X'
#define POINTER_SPECIFIER 'p'
#define CHAR_SPECIFIER 'c'
#define STRING_SPECIFIER 's'
#define PERCENT_SPECIFIER '%'

static void HandleSpecifier(FormatOptions* fmt_opts, int last_ch) {
  switch (last_ch) {
    case INT_SPECIFIER:
    case ALT_INT_SPECIFIER:
      fmt_opts->specifier = kInt;
      break;
    case UNSIGNED_INT_SPECIFIER:
      fmt_opts->specifier = kUnsignedInt;
      break;
    case DEFAULT_FLOAT_SPECIFIER:
      fmt_opts->specifier = kFloat;
      break;
    case EXPONENTIAL_FLOAT_SPECIFIER:
      fmt_opts->specifier = kExpFloat;
      break;
    case BIG_EXPONENTIAL_SPECIFIER:
      fmt_opts->specifier = kExpFloat;
      fmt_opts->upper_case = true;
      break;
    case GENERAL_FLOAT_SPECIFIER:
      fmt_opts->specifier = kGeneralFloat;
      break;
    case BIG_GENERAL_FLOAT_SPECIFIER:
      fmt_opts->specifier = kGeneralFloat;
      fmt_opts->upper_case = true;
      break;
    case OCT_SPECIFIER:
      fmt_opts->specifier = kOctInt;
      break;
    case HEX_SPECIFIER:
      fmt_opts->specifier = kHexInt;
      break;
    case BIG_HEX_SPECIFIER:
      fmt_opts->specifier = kHexInt;
      fmt_opts->upper_case = true;
      break;
    case POINTER_SPECIFIER:
      fmt_opts->specifier = kPointer;
      fmt_opts->alternative_form = true;
      break;
    case CHAR_SPECIFIER:
      fmt_opts->specifier = kChar;
      break;
    case STRING_SPECIFIER:
      fmt_opts->specifier = kString;
      break;
    case PERCENT_SPECIFIER:
      fmt_opts->specifier = kPercent;
      break;
  }
}

void ParseFormat(char** fmt_ptr, FormatOptions* fmt_opts, va_list* params) {
  int ch = HandleFlags(fmt_ptr, fmt_opts);
  ch = HandleFieldWidth(fmt_ptr, fmt_opts, params, ch);
  ch = HandlePrecision(fmt_ptr, fmt_opts, params, ch);
  ch = HandleModifier(fmt_ptr, fmt_opts, ch);
  HandleSpecifier(fmt_opts, ch);
}
