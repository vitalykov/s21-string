#include "s21_strlib/s21_strlib.h"

int s21_isspace(int ch) {
  int result = 0;
  if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\f' || ch == '\r' ||
      ch == '\v') {
    result = 1;
  }
  return result;
}
