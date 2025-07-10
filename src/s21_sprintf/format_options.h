#ifndef S21_STRING_S21_SPRINTF_FORMAT_OPTIONS_H_
#define S21_STRING_S21_SPRINTF_FORMAT_OPTIONS_H_

#include <stdbool.h>

enum Alignment { kRight, kLeft };
typedef enum Alignment Alignment;

enum Specifier {
  kInt,
  kUnsignedInt,
  kHexInt,
  kOctInt,
  kFloat,
  kExpFloat,
  kGeneralFloat,
  kChar,
  kString,
  kPointer,
  kPercent,
  kInvalid,
};
typedef enum Specifier Specifier;

enum Modifier { kDefault, kShort, kLong, kLongDouble };
typedef enum Modifier Modifier;

struct FormatOptions {
  Alignment alignment;
  bool prefix_sign;
  bool prefix_space;
  bool alternative_form;
  bool leading_zeros;
  bool upper_case;
  int min_width;
  int precision;
  Modifier modifier;
  Specifier specifier;
};
typedef struct FormatOptions FormatOptions;

void InitFormatOptions(FormatOptions* opts);
FormatOptions GetDefaultFmtOpts(void);

#endif  // S21_STRING_S21_SPRINTF_FORMAT_OPTIONS_H_
