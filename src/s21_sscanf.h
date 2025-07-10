#ifndef S21_STRING_S21_SSCANF_H
#define S21_STRING_S21_SSCANF_H

#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>

#include "s21_strlib/s21_strlib.h"

typedef struct {
  int width;
  int star;
  int h;
  int l;
  int L;
} WidthLength;

int s21_sscanf(const char* str, const char* format, ...);
int ParseInput(const char* str, const char* format, va_list* params);
void ParseModifiers(char** fmt_ptr, WidthLength* mod);
int ParseSpecifiers(char** fmt_ptr, char** str_ptr, va_list* params,
                    const WidthLength* mod, int* result, const char* start);
int ReadPercent(char** fmt_ptr, char** str_ptr);
int AssignNumber(char** fmt_ptr, char** const str_ptr, va_list* params,
                 const WidthLength* mod, const char* start);
int AssignString(char** fmt_ptr, char** str_ptr, va_list* params,
                 const WidthLength* mod);
int AssignChar(char** fmt_ptr, char** str_ptr, va_list* params,
               const WidthLength* mod);
int AssignPointer(char** fmt_ptr, char** str_ptr, va_list* params,
                  const WidthLength* mod);
int GetDigit(char** fmt_ptr);

#endif  // S21_STRING_S21_SSCANF_H
