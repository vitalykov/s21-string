#include "s21_string.h"

__attribute__((__nonnull__(1, 2))) void* s21_memcpy(void* dest, const void* src,
                                                    s21_size_t n) {
  for (s21_size_t i = 0; i < n / sizeof(unsigned long); ++i) {
    ((unsigned long*)dest)[i] = ((unsigned long*)src)[i];
  }
  for (s21_size_t i = n / sizeof(unsigned long) * sizeof(unsigned long); i < n;
       ++i) {
    ((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
  }
  return dest;
}
