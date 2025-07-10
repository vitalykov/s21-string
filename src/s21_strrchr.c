#include "s21_string.h"

char* s21_strrchr(const char* str, int c) {
  const char* last = S21_NULL;
  unsigned char ch = (unsigned char)c;

  while (*str != '\0') {
    if ((unsigned char)*str == ch) {
      last = str;
    }
    str++;
  }

  return ch == '\0' ? (char*)str : (char*)last;
}
