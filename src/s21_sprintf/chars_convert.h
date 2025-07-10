#ifndef S21_STRING_S21_SPRINTF_CHARS_CONVERT_H_
#define S21_STRING_S21_SPRINTF_CHARS_CONVERT_H_

#include <wchar.h>

#include "s21_sprintf/format_options.h"

int AppendChar(char* dest, int ch);
int AppendLongChar(char* dest, wint_t ch);
int AppendString(char* dest, char* str, int precision);
int AppendLongString(char* dest, wchar_t* w_str, int precision);

#endif  // S21_STRING_S21_SPRINTF_CHARS_CONVERT_H_
