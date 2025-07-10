#include "s21_string.h"
#include "s21_strlib/s21_strlib.h"

__attribute__((__nonnull__(1, 2))) int s21_strncasecmp(const char* str1,
                                                       const char* str2,
                                                       s21_size_t n) {
  int res = 0;
  int stop = 0;

  for (s21_size_t i = 0; i < n && !stop; ++i) {
    if (str1[i] == '\0' || str2[i] == '\0' ||
        s21_tolower(str1[i]) != s21_tolower(str2[i])) {
      res = (int)str1[i] - (int)str2[i];
      stop = 1;
    }
  }

  return res;
}
