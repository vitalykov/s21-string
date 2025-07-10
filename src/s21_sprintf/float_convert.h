#ifndef S21_STRING_S21_SPRINTF_FLOAT_CONVERT_H_
#define S21_STRING_S21_SPRINTF_FLOAT_CONVERT_H_

#include "s21_sprintf/format_options.h"
#include "s21_sprintf/util.h"

int AppendFloat(char* dest, long double num, const FormatOptions* fmt_opts);
int AppendExponentialFloat(char* dest, long double num,
                           FormatOptions* fmt_opts);
int AppendGeneralFloat(char* dest, long double num, FormatOptions* fmt_opts);

#endif  // S21_STRING_S21_SPRINTF_FLOAT_CONVERT_H_
