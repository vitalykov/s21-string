#include "s21_string.h"

void* s21_memchr(const void* str, int c, s21_size_t n) {
  unsigned char* ptr = (unsigned char*)str;
  void* out = S21_NULL;
  for (s21_size_t i = 0; i < n && ptr != S21_NULL && out == S21_NULL; ++i) {
    if (*ptr == (unsigned char)c) {
      out = ptr;
    }
    ptr++;
  }
  return out;
}
