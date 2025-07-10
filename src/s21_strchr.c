#include "s21_string.h"

char* s21_strchr(const char* str, int c) {
  const char* ptr = S21_NULL;
  s21_size_t i = 0;

  do {
    if (str[i] == c) {
      ptr = str + i;
    }
  } while (str[i++] != '\0' && ptr == S21_NULL);

  return (char*)ptr;
}
