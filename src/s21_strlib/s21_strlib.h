#ifndef S21_STRLIB_H_
#define S21_STRLIB_H_

int s21_isalpha(int ch);
int s21_isdigit(int ch);
int s21_isspace(int ch);
int s21_tolower(int ch);
__attribute__((__nonnull__(1))) long int s21_strtol(const char* nptr,
                                                    char** endptr, int base);
__attribute__((__nonnull__(1))) unsigned long int s21_strtoul(const char* nptr,
                                                              char** endptr,
                                                              int base);
__attribute__((__nonnull__(1))) long double s21_strtold(const char* nptr,
                                                        char** endptr);

#endif  // S21_STRLIB_H_
