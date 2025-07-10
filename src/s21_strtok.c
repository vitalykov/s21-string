#include "s21_string.h"

__attribute__((__nonnull__(2))) char* s21_strtok(char* str, const char* delim) {
  static char* save_str = S21_NULL;
  if (str == S21_NULL) str = save_str;
  if (str != S21_NULL) {
    while ((*str != '\0') && (s21_strcspn(str, delim) == 0)) {
      ++str;
    }
    char* end = str + s21_strcspn(str, delim);
    save_str = (*end != '\0') ? end + 1 : S21_NULL;
    *end = '\0';
    str = (*str != '\0') ? str : S21_NULL;
  }
  return str;
}
