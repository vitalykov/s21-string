#include "s21_sprintf/chars_convert.h"

#include <limits.h>

#include "s21_sprintf/util.h"

int AppendChar(char* dest, int ch) {
  PutChar(dest, ch);

  return 1;
}

int AppendLongChar(char* dest, wint_t ch) {
  PutChar(dest, (char)ch);

  return 1;
}

int AppendString(char* dest, char* str, int precision) {
  int chars_count = 0;
  if (precision == -1) {
    precision = INT_MAX;
  }

  while (*str != '\0' && chars_count < precision) {
    *dest = *str;
    ++chars_count;
    ++dest;
    ++str;
  }
  *dest = '\0';

  return chars_count;
}

int AppendLongString(char* dest, wchar_t* str, int precision) {
  const wchar_t kLineEnd = (wchar_t)0;
  int chars_count = 0;
  if (precision == -1) {
    precision = INT_MAX;
  }

  while (*str != kLineEnd && chars_count < precision) {
    *dest = (char)*str;
    ++chars_count;
    ++dest;
    ++str;
  }
  *dest = '\0';

  return chars_count;
}
