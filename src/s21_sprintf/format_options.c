#include "s21_sprintf/format_options.h"

void InitFormatOptions(FormatOptions* fmt_opts) {
  fmt_opts->alignment = kRight;
  fmt_opts->prefix_sign = false;
  fmt_opts->prefix_space = false;
  fmt_opts->alternative_form = false;
  fmt_opts->leading_zeros = false;
  fmt_opts->upper_case = false;
  fmt_opts->min_width = 0;
  fmt_opts->precision = -1;
  fmt_opts->modifier = kDefault;
  fmt_opts->specifier = kInvalid;
}

FormatOptions GetDefaultFmtOpts(void) {
  FormatOptions fmt_opts;
  InitFormatOptions(&fmt_opts);

  return fmt_opts;
}
