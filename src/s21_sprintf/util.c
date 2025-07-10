#include "s21_sprintf/util.h"

int NextChar(char** str_ptr) {
  *str_ptr += 1;
  char ch = **str_ptr;

  return (int)ch;
}

void PutChar(char* str_ptr, char ch) {
  *str_ptr = ch;
  *(str_ptr + 1) = '\0';
}

void ReverseString(char* str, s21_size_t l, s21_size_t r) {
  while (l < r) {
    char temp = str[l];
    str[l] = str[r];
    str[r] = temp;

    ++l, --r;
  }
}

void FillString(char* str, char ch, int n) {
  while (n-- != 0) {
    *str = ch;
    ++str;
  }
  *str = '\0';
}

int Max(int a, int b) { return a > b ? a : b; }
