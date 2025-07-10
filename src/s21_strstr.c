#include <stdio.h>

#include "s21_string.h"

char* s21_strstr(const char* haystack, const char* needle) {
  int stop = 0;
  const char* result = S21_NULL;
  s21_size_t i = 0;

  do {
    s21_size_t j = 0;
    size_t matched_i = i;
    while (haystack[matched_i] == needle[j] && needle[j] != '\0') {
      matched_i++;
      j++;
    }
    if (needle[j] == '\0') {
      result = haystack + i;
      stop = 1;
    }
    ++i;
  } while (haystack[i] != '\0' && !stop);

  return (char*)result;
}
