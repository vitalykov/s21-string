#include <stdlib.h>

#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *upper_copy_str = S21_NULL;

  if (str != S21_NULL) {
    s21_size_t len_str = s21_strlen(str);
    upper_copy_str = malloc(len_str + 1);
    if (upper_copy_str != S21_NULL) {
      for (s21_size_t i = 0; i <= len_str; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z')
          upper_copy_str[i] = str[i] - ('a' - 'A');
        else
          upper_copy_str[i] = str[i];
      }
    }
  }

  return upper_copy_str;
}
