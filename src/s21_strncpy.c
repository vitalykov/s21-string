#include "s21_string.h"

__attribute__((__nonnull__(1, 2))) char* s21_strncpy(char* dest,
                                                     const char* src,
                                                     s21_size_t n) {
  s21_size_t len_src = s21_strlen(src);
  s21_size_t size = (len_src > n) ? n : len_src;
  s21_memcpy(dest, src, size);
  s21_memset(dest + len_src, '\0', n - size);
  return dest;
}
