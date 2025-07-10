#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  char* final_str = S21_NULL;

  if (src != S21_NULL && str != S21_NULL) {
    s21_size_t len_src = s21_strlen(src);

    if (len_src >= start_index) {
      s21_size_t len_str = s21_strlen(str);

      final_str = malloc(len_src + len_str + 1);
      if (final_str != S21_NULL) {
        s21_size_t i = 0;

        for (; i < start_index; ++i) final_str[i] = src[i];
        for (s21_size_t j = 0; j < len_str; ++j, ++i) final_str[i] = str[j];
        for (s21_size_t j = start_index; j < len_src; ++j, ++i)
          final_str[i] = src[j];
        final_str[i] = '\0';
      }
    }
  }
  return final_str;
}
