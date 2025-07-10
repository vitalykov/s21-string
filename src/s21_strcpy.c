#include "s21_string.h"

char* s21_strcpy(char* destination, const char* source) {
  for (int i = 0; source[i] != '\0'; i++) {
    destination[i] = source[i];
  }

  destination[s21_strlen(source)] = '\0';

  return destination;
}
