#ifndef S21_STRING_S21_SPRINTF_PARSER_H_
#define S21_STRING_S21_SPRINTF_PARSER_H_

#include <stdarg.h>

#include "s21_sprintf/format_options.h"

void ParseFormat(char** fmt_ptr, FormatOptions* fmt_opts, va_list* params);

#endif  // S21_STRING_S21_SPRINTF_PARSER_H_
