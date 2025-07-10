#include "s21_string.h"

char* s21_strpbrk(const char* str1, const char* str2) {
  const char* ptr = S21_NULL;

  for (int i = 0; str1[i] != '\0' && ptr == S21_NULL; ++i) {
    for (int j = 0; str2[j] != '\0'; j++) {
      if (str2[j] == str1[i]) {
        ptr = str1 + i;
      }
    }
  }

  return (char*)ptr;
}
