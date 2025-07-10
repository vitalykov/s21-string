#include <errno.h>
#include <limits.h>
#include <stdbool.h>

#include "s21_string.h"
#include "s21_strlib/s21_strlib.h"

typedef long int long_int;
typedef unsigned long unsigned_long;

void HandleSpacesL(char** curptr) {
  while (s21_isspace(**curptr)) {
    ++(*curptr);
  }
}

bool HandleSignL(char** curptr) {
  bool neg = false;
  if (**curptr == '-') {
    neg = true;
    ++(*curptr);
  } else if (**curptr == '+') {
    ++(*curptr);
  }
  return neg;
}

void HandleBasePrefixL(char** curptr, int* base) {
  if (s21_strncasecmp(*curptr, "0x", s21_strlen("0x")) == 0) {
    int next_ch = *(*curptr + s21_strlen("0x"));
    if (s21_isdigit(next_ch) ||
        (s21_tolower(next_ch) >= 'a' && s21_tolower(next_ch) <= 'f')) {
      if (*base == 0) {
        *base = 16;
      }
      if (*base == 16) {
        *curptr += 2;
      }
    }
  } else if (s21_strncasecmp(*curptr, "0", s21_strlen("0")) == 0) {
    int next_ch = *(*curptr + s21_strlen("0"));
    if (next_ch >= '0' && next_ch <= '7') {
      if (*base == 0) {
        *base = 8;
      }
      if (*base == 8) {
        *curptr += 1;
      }
    }
  }
  if (*base == 0) {
    *base = 10;
  }
}

#define DefineMoreCmp(T) \
  bool MoreCmp_##T(T a, T b) { return a >= b; }
DefineMoreCmp(long_int);
#define MoreCmp(T) MoreCmp_##T

#define DefineLessCmp(T) \
  bool LessCmp_##T(T a, T b) { return a <= b; }
DefineLessCmp(long_int);
DefineLessCmp(unsigned_long);
#define LessCmp(T) LessCmp_##T

#define DefineLim(T)        \
  struct Lim_##T {          \
    T value;                \
    T cutoff;               \
    int cutlim;             \
    bool (*cmp_func)(T, T); \
  }
DefineLim(long_int);
DefineLim(unsigned_long);
#define Lim(T) Lim_##T

bool AssignDigitL(int* digit, const char* curptr) {
  bool stop = false;
  if (s21_isdigit(*curptr)) {
    *digit = *curptr - '0';
  } else if (s21_isalpha(*curptr)) {
    *digit = s21_tolower(*curptr) - 'a' + 10;
  } else {
    stop = true;
  }
  return stop;
}

#define DefineUpdateResultWithDigitL(T)                           \
  bool UpdateResultWithDigitL_##T(T* result, int digit, int base, \
                                  struct Lim(T) lim) {            \
    bool overflow = false;                                        \
    if (lim.cmp_func(*result, lim.cutoff)) {                      \
      *result *= base;                                            \
      if (lim.cmp_func(*result, lim.cutoff) ||                    \
          lim.cmp_func(digit, lim.cutlim)) {                      \
        *result += digit;                                         \
      } else {                                                    \
        overflow = true;                                          \
      }                                                           \
    } else {                                                      \
      overflow = true;                                            \
    }                                                             \
    if (overflow) {                                               \
      *result = lim.value;                                        \
      errno = ERANGE;                                             \
    }                                                             \
    return overflow;                                              \
  }
DefineUpdateResultWithDigitL(long_int);
DefineUpdateResultWithDigitL(unsigned_long);
#define UpdateResultWithDigitL(T) UpdateResultWithDigitL_##T

#define DefineAssignDigitsL(T)                                                \
  T AssignDigitsL_##T(char* curptr, char** endptr, int base,                  \
                      struct Lim(T) lim, bool neg) {                          \
    T result = 0;                                                             \
                                                                              \
    bool stop = 0;                                                            \
    bool overflow = false;                                                    \
    while (!stop) {                                                           \
      int digit = 0;                                                          \
      stop = AssignDigitL(&digit, curptr);                                    \
      stop = stop || (digit >= base);                                         \
                                                                              \
      if (!stop) {                                                            \
        ++curptr;                                                             \
        digit = (neg) ? -digit : digit;                                       \
        overflow = !overflow                                                  \
                       ? UpdateResultWithDigitL(T)(&result, digit, base, lim) \
                       : overflow;                                            \
      }                                                                       \
    }                                                                         \
                                                                              \
    if (endptr) *endptr = curptr;                                             \
    return result;                                                            \
  }
DefineAssignDigitsL(long_int);
DefineAssignDigitsL(unsigned_long);
#define AssignDigitsL(T) AssignDigitsL_##T

#define DefineStrToNumConvertL(T)                                              \
  T StrToNumConvertL_##T(const char* nptr, char** endptr, int base, bool* neg, \
                         T lim_min, T lim_max, bool (*MoreCmp)(T, T),          \
                         bool (*LessCmp)(T, T), const bool* neg_digits_sign) { \
    T result = 0;                                                              \
    if (base == 0 || (base >= 2 && base <= 36)) {                              \
      char* curptr = (char*)nptr;                                              \
                                                                               \
      HandleSpacesL(&curptr);                                                  \
      *neg = HandleSignL(&curptr);                                             \
      HandleBasePrefixL(&curptr, &base);                                       \
      T lim_value = (*neg) ? lim_min : lim_max;                                \
      struct Lim(T) lim = {.value = lim_value,                                 \
                           .cutoff = lim_value / base,                         \
                           .cutlim = lim_value % base,                         \
                           .cmp_func = (*neg) ? MoreCmp : LessCmp};            \
      result = AssignDigitsL(T)(curptr, endptr, base, lim, *neg_digits_sign);  \
                                                                               \
      if (endptr) {                                                            \
        if (curptr == *endptr) *endptr = (char*)nptr;                          \
      }                                                                        \
    } else {                                                                   \
      errno = EINVAL;                                                          \
    }                                                                          \
    return result;                                                             \
  }
DefineStrToNumConvertL(long_int);
DefineStrToNumConvertL(unsigned_long);
#define StrToNumConvertL(T) StrToNumConvertL_##T

__attribute__((__nonnull__(1))) long int s21_strtol(const char* nptr,
                                                    char** endptr, int base) {
  bool neg = false;
  bool* neg_digit_sign = &neg;
  long int result = StrToNumConvertL(long_int)(
      nptr, endptr, base, &neg, LONG_MIN, LONG_MAX, MoreCmp(long_int),
      LessCmp(long_int), neg_digit_sign);

  return result;
}

__attribute__((__nonnull__(1))) unsigned long s21_strtoul(const char* nptr,
                                                          char** endptr,
                                                          int base) {
  bool neg = false;
  bool neg_digit_sign = false;
  unsigned long result = StrToNumConvertL(unsigned_long)(
      nptr, endptr, base, &neg, ULONG_MAX, ULONG_MAX, LessCmp(unsigned_long),
      LessCmp(unsigned_long), &neg_digit_sign);

  if (errno != ERANGE && neg) result = -result;

  return result;
}
