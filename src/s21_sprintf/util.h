#ifndef S21_STRING_S21_SPRINTF_UTIL_H_
#define S21_STRING_S21_SPRINTF_UTIL_H_

#include "s21_string.h"

#define MAX_VALUE_LEN 4096

int NextChar(char** str_ptr);
void PutChar(char* str_ptr, char ch);
void ReverseString(char* str, s21_size_t l, s21_size_t r);
void FillString(char* str, char ch, int n);
int Max(int a, int b);

#endif  // S21_STRING_S21_SPRINTF_UTIL_H_
