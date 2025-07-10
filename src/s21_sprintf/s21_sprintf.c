#include <stdarg.h>

#include "s21_sprintf/formatter.h"
#include "s21_string.h"

#define FORMAT_START_CHAR '%'

int s21_sprintf(char* str, const char* format, ...) {
  int chars_count = 0;

  va_list params;
  va_start(params, format);

  char* format_ptr = (char*)format;
  char ch;
  while ((ch = *format_ptr) != '\0' && chars_count != -1) {
    if (ch != FORMAT_START_CHAR) {
      *str = ch;
      ++str;
      ++chars_count;
    } else {
      *str = '\0';
      int printed = ProcessFormat(&format_ptr, str, &params);
      if (printed != -1) {
        chars_count += printed;
        str += printed;
      } else {
        chars_count = -1;
      }
    }

    if (chars_count != -1) {
      ++format_ptr;
    }
  }

  *str = '\0';
  va_end(params);
  return chars_count;
}
