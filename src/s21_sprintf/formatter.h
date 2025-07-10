#ifndef S21_STRING_S21_SPRINTF_FORMATTER_H_
#define S21_STRING_S21_SPRINTF_FORMATTER_H_

#include <stdarg.h>

int ProcessFormat(char** fmt_ptr, char* str, va_list* params);

#endif  // S21_STRING_S21_SPRINTF_FORMATTER_H_
