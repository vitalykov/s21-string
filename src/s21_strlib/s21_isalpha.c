#include "s21_strlib/s21_strlib.h"

int s21_isalpha(int ch) {
  int result = 0;
  if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
    result = 1;
  }
  return result;
}
