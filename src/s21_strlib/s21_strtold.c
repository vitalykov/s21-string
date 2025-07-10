#include <errno.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>

#include "s21_string.h"
#include "s21_strlib/s21_strlib.h"

void HandleSpacesLD(char** curptr) {
  while (s21_isspace(**curptr)) {
    ++(*curptr);
  }
}

bool HandleSignLD(char** curptr) {
  bool neg = false;
  if (**curptr == '-') {
    neg = true;
    ++(*curptr);
  } else if (**curptr == '+') {
    ++(*curptr);
  }
  return neg;
}

void HandleBasePrefixLD(char** curptr, int* base) {
  if (s21_strncasecmp(*curptr, "0x", s21_strlen("0x")) == 0) {
    int next_ch = *(*curptr + s21_strlen("0x"));
    if (s21_isdigit(next_ch) ||
        (s21_tolower(next_ch) >= 'a' && s21_tolower(next_ch) <= 'f')) {
      *base = 16;
      *curptr += 2;
    }
  }
}

bool HandleSpecialLD(long double* result, char** curptr) {
  bool is_special = true;
  if (s21_strncasecmp(*curptr, "nan", s21_strlen("nan")) == 0) {
    *result = NAN;
    *curptr += s21_strlen("nan");
  } else if (s21_strncasecmp(*curptr, "INFINITY", s21_strlen("INFINITY")) ==
             0) {
    *result = INFINITY;
    *curptr += s21_strlen("INFINITY");
  } else if (s21_strncasecmp(*curptr, "INF", s21_strlen("INF")) == 0 &&
             !s21_isalpha((*curptr)[s21_strlen("INF")])) {
    *result = INFINITY;
    *curptr += s21_strlen("INF");
  } else {
    is_special = false;
  }
  return is_special;
}

bool AssignDigitLD(int* digit, const char* curptr, bool* is_after_point) {
  bool stop = false;
  if (s21_isdigit(*curptr)) {
    *digit = *curptr - '0';
  } else if (s21_isalpha(*curptr)) {
    *digit = s21_tolower(*curptr) - 'a' + 10;
  } else if (*curptr == '.' && !*is_after_point) {
    *digit = '.';
    *is_after_point = true;
  } else {
    stop = true;
  }
  return stop;
}

void UpdateResultWithDigitLD(long double* result, int* exp, int digit, int base,
                             bool is_after_point) {
  *result *= base;
  *result += digit;
  if (is_after_point) {
    --*exp;
  }
}

void HandleExpPartLD(long double* result, char** curptr, int base) {
  if ((base == 10 && s21_tolower(**curptr) == 'e') ||
      (base == 16 && s21_tolower(**curptr) == 'p')) {
    char* exp_endptr;
    long int exp = s21_strtol(*curptr + 1, &exp_endptr, 10);
    if ((exp_endptr - (*curptr + 1) > 0) && (*(*curptr + 1) != ' ')) {
      *curptr = exp_endptr;
      *result *= (base == 16) ? powl(2, exp) : powl(10, exp);
    }
  }
}

__attribute__((__nonnull__(1))) long double s21_strtold(const char* nptr,
                                                        char** endptr) {
  int base = 10;
  char* curptr = (char*)nptr;

  HandleSpacesLD(&curptr);
  bool neg = HandleSignLD(&curptr);
  if (endptr) *endptr = curptr;
  HandleBasePrefixLD(&curptr, &base);

  long double result = 0;

  if (!HandleSpecialLD(&result, &curptr)) {
    bool stop = 0;
    int exp = 0;
    bool is_after_point = false;
    while (!stop) {
      int digit = 0;
      stop = AssignDigitLD(&digit, curptr, &is_after_point);
      if (!stop && digit == '.') {
        ++curptr;
        stop = AssignDigitLD(&digit, curptr, &is_after_point);
      }
      stop = stop || (digit >= base);
      if (!stop) {
        ++curptr;
        UpdateResultWithDigitLD(&result, &exp, digit, base, is_after_point);
      }
    }
    result *= powl(base, exp);
    HandleExpPartLD(&result, &curptr, base);

    if (isinf(result)) {
      errno = ERANGE;
    }
  }

  if (endptr) {
    if (*endptr == curptr)
      *endptr = (char*)nptr;
    else
      *endptr = curptr;
  }

  result = (neg) ? -result : result;
  return result;
}
