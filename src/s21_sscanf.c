#include "s21_sscanf.h"

#include "s21_string.h"
#include "s21_strlib/s21_strlib.h"

int s21_sscanf(const char* str, const char* format, ...) {
  int params_count = 0;
  if (str == S21_NULL || format == S21_NULL || *str == '\0' ||
      *format == '\0') {
    params_count = -1;
  }
  if (params_count != -1) {
    va_list params;
    va_start(params, format);
    params_count = ParseInput(str, format, &params);
    va_end(params);
  }

  return params_count;
}

int ParseInput(const char* str, const char* format, va_list* params) {
  int result = 0;
  bool stop = false;

  char* fmt_ptr = (char*)format;
  char* str_ptr = (char*)str;
  const char* start = (char*)str;

  while ((*fmt_ptr != '\0' || *str_ptr != '\0') && !stop) {
    if (*fmt_ptr == '%') {
      WidthLength mod = {0};
      ++fmt_ptr;
      while (s21_isspace(*str_ptr) && *fmt_ptr != 'c') ++str_ptr;
      ParseModifiers(&fmt_ptr, &mod);
      int parsed =
          ParseSpecifiers(&fmt_ptr, &str_ptr, params, &mod, &result, start);
      result += parsed;
    } else if (*fmt_ptr == *str_ptr) {
      ++fmt_ptr;
      ++str_ptr;
    } else {
      stop = true;
    }
    while (s21_isspace(*str_ptr) && *fmt_ptr != '%') ++str_ptr;
    while (s21_isspace(*fmt_ptr)) ++fmt_ptr;
  }

  if (result == 0 && *str_ptr == '\0') {
    result = -1;
  }
  return result;
}

void ParseModifiers(char** fmt_ptr, WidthLength* mod) {
  int not_found = 1;
  if (s21_isdigit(**fmt_ptr)) {
    mod->width = GetDigit(fmt_ptr);
  }
  if (**fmt_ptr == '*') {
    mod->star = 1;
    not_found = 0;
  } else if (**fmt_ptr == 'h') {
    mod->h = 1;
    not_found = 0;
  } else if (**fmt_ptr == 'l') {
    mod->l = 1;
    not_found = 0;
  } else if (**fmt_ptr == 'L') {
    mod->L = 1;
    not_found = 0;
  } else {
  }
  if (not_found == 0) {
    ++(*fmt_ptr);
  }
}

#define EMPTY_BASE -1

long double s21_strtold_with_base(const char* str_ptr, char** str_end_ptr,
                                  int base) {
  (void)base;
  return s21_strtold(str_ptr, str_end_ptr);
}

#define ASSIGN_FUNC(func_name, convert_func, short_type, default_type,       \
                    long_type, long_long_type)                               \
  int func_name(char** fmt_ptr, char** str_ptr, va_list* params,             \
                const WidthLength* mod, int base) {                          \
    bool err = false;                                                        \
    int result = 0;                                                          \
    char* str_end_ptr = S21_NULL;                                            \
    long_long_type converted_num = 0;                                        \
    if (mod->width) {                                                        \
      s21_size_t width_pos = 0;                                              \
      while ((*str_ptr)[width_pos] != '\0' && (int)width_pos < mod->width) { \
        ++width_pos;                                                         \
      }                                                                      \
      char* str_width = malloc((width_pos + 1) * sizeof(char));              \
      if (str_width == S21_NULL) {                                           \
        err = true;                                                          \
      }                                                                      \
      if (!err) {                                                            \
        s21_strncpy(str_width, *str_ptr, width_pos);                         \
        str_width[width_pos] = '\0';                                         \
        converted_num = convert_func(str_width, &str_end_ptr, base);         \
        str_end_ptr = *str_ptr + (str_end_ptr - str_width);                  \
        if (str_width != S21_NULL) free(str_width);                          \
      }                                                                      \
    } else {                                                                 \
      converted_num = convert_func(*str_ptr, &str_end_ptr, base);            \
    }                                                                        \
                                                                             \
    if (!err) {                                                              \
      if (str_end_ptr - *str_ptr > 0) {                                      \
        result = 1;                                                          \
        if (mod->h) {                                                        \
          short_type* num_ptr = va_arg(*params, short_type*);                \
          *num_ptr = (short_type)converted_num;                              \
        } else if (mod->l) {                                                 \
          long_type* num_ptr = va_arg(*params, long_type*);                  \
          *num_ptr = (long_type)converted_num;                               \
        } else if (mod->L) {                                                 \
          long_long_type* num_ptr = va_arg(*params, long_long_type*);        \
          *num_ptr = (long_long_type)converted_num;                          \
        } else if (mod->star) {                                              \
          result = 0;                                                        \
        } else {                                                             \
          default_type* num_ptr = va_arg(*params, default_type*);            \
          *num_ptr = (default_type)converted_num;                            \
        }                                                                    \
        *str_ptr = str_end_ptr;                                              \
      }                                                                      \
    }                                                                        \
    ++(*fmt_ptr);                                                            \
                                                                             \
    return result;                                                           \
  }

ASSIGN_FUNC(AssignInteger, s21_strtol, short, int, long int, long int)
ASSIGN_FUNC(AssignUnsignedInteger, s21_strtoul, unsigned short, unsigned int,
            unsigned long int, unsigned long int)
ASSIGN_FUNC(AssignFloatingPointInternal, s21_strtold_with_base, float, float,
            double, long double)
ASSIGN_FUNC(AssignPointerInternal, s21_strtoul, uintptr_t, uintptr_t, uintptr_t,
            uintptr_t)

int AssignFloatingPoint(char** fmt_ptr, char** str_ptr, va_list* params,
                        const WidthLength* mod) {
  return AssignFloatingPointInternal(fmt_ptr, str_ptr, params, mod, EMPTY_BASE);
}

int ParseSpecifiers(char** fmt_ptr, char** str_ptr, va_list* params,
                    const WidthLength* mod, int* result, const char* start) {
  int parsed = 0;
  switch (**fmt_ptr) {
    case 'c':
      parsed = AssignChar(fmt_ptr, str_ptr, params, mod);
      break;
    case 's':
      parsed = AssignString(fmt_ptr, str_ptr, params, mod);
      break;
    case 'd':
      parsed = AssignInteger(fmt_ptr, str_ptr, params, mod, 10);
      break;
    case 'i':
      parsed = AssignInteger(fmt_ptr, str_ptr, params, mod, 0);
      break;
    case 'e':
    case 'E':
    case 'f':
    case 'g':
    case 'G':
      parsed = AssignFloatingPoint(fmt_ptr, str_ptr, params, mod);
      break;
    case 'o':
      parsed = AssignUnsignedInteger(fmt_ptr, str_ptr, params, mod, 8);
      break;
    case 'u':
      parsed = AssignUnsignedInteger(fmt_ptr, str_ptr, params, mod, 10);
      break;
    case 'x':
    case 'X':
      parsed = AssignUnsignedInteger(fmt_ptr, str_ptr, params, mod, 16);
      break;
    case 'p':
      parsed = AssignPointer(fmt_ptr, str_ptr, params, mod);
      break;
    case 'n':
      parsed = AssignNumber(fmt_ptr, str_ptr, params, mod, start);
      break;
    case '%':
      parsed = ReadPercent(fmt_ptr, str_ptr);
      break;
    default:
      *result = -1;
  }

  return parsed;
}

int ReadPercent(char** fmt_ptr, char** str_ptr) {
  if (**str_ptr == '%') {
    ++(*str_ptr);
    ++(*fmt_ptr);
  }

  return 0;
}

int AssignNumber(char** fmt_ptr, char** const str_ptr, va_list* params,
                 const WidthLength* mod, const char* start) {
  int* n = S21_NULL;

  if (!mod->star) {
    n = va_arg(*params, int*);
    *n = *str_ptr - start;
  }
  ++(*fmt_ptr);

  return 0;
}

int AssignString(char** fmt_ptr, char** str_ptr, va_list* params,
                 const WidthLength* mod) {
  if (**str_ptr == '\0') {
    return 0;
  }
  int result = 0;
  int width = INT_MAX;
  if (mod->width > 0) {
    width = mod->width;
  }

  if (mod->star) {
    while (!s21_isspace(**str_ptr) && **str_ptr != '\0') ++(*str_ptr);
  } else if (mod->l) {
    wchar_t* ch = va_arg(*params, wchar_t*);
    while (!s21_isspace(**str_ptr) && **str_ptr != '\0' && width != 0) {
      wchar_t wc;
      int bytes_consumed = mbtowc(
          &wc, *str_ptr, MB_CUR_MAX);  // MB_CUR_MAX is max bytes for a char
      *ch = wc;
      ++ch;
      *str_ptr += bytes_consumed;
      --width;
    }
    *ch = L'\0';
    result = 1;
  } else {
    char* ch = va_arg(*params, char*);
    while (!s21_isspace(**str_ptr) && **str_ptr != '\0' && width != 0) {
      *ch = **str_ptr;
      ++ch;
      ++(*str_ptr);
      --width;
    }
    *ch = '\0';
    result = 1;
  }
  ++(*fmt_ptr);

  return result;
}

int AssignChar(char** fmt_ptr, char** str_ptr, va_list* params,
               const WidthLength* mod) {
  int result = 0;
  char* ch = S21_NULL;

  if (!mod->star) {
    ch = va_arg(*params, char*);
    *ch = **str_ptr;
    result = 1;
  }
  ++(*str_ptr);
  ++(*fmt_ptr);

  return result;
}

int AssignPointer(char** fmt_ptr, char** str_ptr, va_list* params,
                  const WidthLength* mod) {
  const char null_str[] = "(nil)";
  size_t null_str_len = s21_strlen(null_str);
  int result = 0;
  if (s21_strncmp(*str_ptr, null_str, null_str_len) == 0 && !mod->star) {
    void** num_ptr = va_arg(*params, void**);
    *num_ptr = S21_NULL;
    *str_ptr += null_str_len;
    ++(*fmt_ptr);
    result = 1;
  }

  if (!result) {
    result = AssignPointerInternal(fmt_ptr, str_ptr, params, mod, 16);
  }
  return result;
}

int GetDigit(char** fmt_ptr) {
  char ch = **fmt_ptr;
  int result = 0;
  while ('0' <= ch && ch <= '9') {
    result = result * 10 + ((int)ch - 48);
    ++(*fmt_ptr);
    ch = **fmt_ptr;
  }

  return result;
}

//  gcc -Wall -Werror -Wextra -std=c11 s21_sscanf.c -o 21

// gcc tests/sscanf_test_gen.c
// ./a.out
// make test
// ./test
