#include "s21_strlib/s21_strlib.h"

int s21_tolower(int ch) {
  if ('A' <= ch && ch <= 'Z') {
    ch += ('a' - 'A');
  }
  return ch;
}
