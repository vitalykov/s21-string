#include <stdlib.h>

#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *lower_copy_str = S21_NULL;
  if (str != S21_NULL) {
    s21_size_t len_str = s21_strlen(str);
    lower_copy_str = malloc(len_str + 1);
    if (lower_copy_str != S21_NULL) {
      for (s21_size_t i = 0; i <= len_str; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z')
          lower_copy_str[i] = str[i] + ('a' - 'A');
        else
          lower_copy_str[i] = str[i];
      }
    }
  }
  return lower_copy_str;
}
