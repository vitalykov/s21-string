#include "s21_string.h"

s21_size_t s21_strcspn(const char* str1, const char* str2) {
  s21_size_t length = s21_strlen(str1);
  int stop = 1;

  for (s21_size_t i = 0; str1[i] != '\0'; ++i) {
    for (s21_size_t j = 0; str2[j] != '\0' && stop; ++j) {
      if (str1[i] == str2[j]) {
        length = i;
        stop = 0;
      }
    }
  }

  return length;
}
