#include "s21_strlib/s21_strlib.h"

int s21_isdigit(int ch) {
  int result = 0;
  if ('0' <= ch && ch <= '9') {
    result = 1;
  }
  return result;
}
