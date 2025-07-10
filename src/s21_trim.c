#include <stdlib.h>

#include "s21_string.h"

void *s21_trim(const char *src, const char *trim_chars) {
  char *result = S21_NULL;
  if (src != S21_NULL) {
    if (trim_chars == S21_NULL) trim_chars = " \t\n\r\f\v";
    s21_size_t src_len = s21_strlen(src);
    s21_size_t start = 0;
    s21_size_t end = src_len > 0 ? src_len - 1 : 0;

    while (start < src_len && s21_strchr(trim_chars, src[start]) != S21_NULL) {
      start++;
    }

    while (end > start && s21_strchr(trim_chars, src[end]) != S21_NULL) {
      end--;
    }

    s21_size_t trimmed_len = (start <= end) ? (end - start + 1) : 0;
    result = malloc(trimmed_len + 1);

    if (result != S21_NULL) {
      for (s21_size_t i = 0; i < trimmed_len; i++) {
        result[i] = src[start + i];
      }
      result[trimmed_len] = '\0';
    }
  }
  return result;
}
