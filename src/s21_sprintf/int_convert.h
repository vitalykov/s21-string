#ifndef S21_STRING_S21_SPRINTF_INT_CONVERT_H_
#define S21_STRING_S21_SPRINTF_INT_CONVERT_H_

#include <stdbool.h>

#include "s21_sprintf/format_options.h"

int AppendInt(char* dest, int num, const FormatOptions* fmt_opts);
int AppendUnsignedInt(char* dest, unsigned int num,
                      const FormatOptions* fmt_opts);
int AppendShort(char* dest, short num, const FormatOptions* fmt_opts);
int AppendUnsignedShort(char* dest, unsigned short num,
                        const FormatOptions* fmt_opts);
int AppendLong(char* dest, long num, const FormatOptions* fmt_opts);
int AppendUnsignedLong(char* dest, unsigned long num,
                       const FormatOptions* fmt_opts);
int AppendUnsignedLongLongLong(char* dest, __uint128_t num,
                               const FormatOptions* fmt_opts);

int AppendIntUnsignedOct(char* dest, unsigned int num,
                         const FormatOptions* fmt_opts);
int AppendShortUnsignedOct(char* dest, unsigned short num,
                           const FormatOptions* fmt_opts);
int AppendLongUnsignedOct(char* dest, unsigned long num,
                          const FormatOptions* fmt_opts);
int AppendIntUnsignedHex(char* dest, unsigned int num,
                         const FormatOptions* fmt_opts);
int AppendShortUnsignedHex(char* dest, unsigned short num,
                           const FormatOptions* fmt_opts);
int AppendLongUnsignedHex(char* dest, unsigned long num,
                          const FormatOptions* fmt_opts);
int AppendVoidPointer(char* dest, void* ptr, const FormatOptions* fmt_opts);

#endif  // S21_STRING_S21_SPRINTF_INT_CONVERT_H_
