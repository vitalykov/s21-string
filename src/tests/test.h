#ifndef TEST_H
#define TEST_H

#include <check.h>

Suite* suite_s21_sprintf(void);
Suite* suite_s21_sscanf(void);

Suite* suite_s21_memcpy(void);
Suite* suite_s21_memcmp(void);
Suite* suite_s21_memset(void);
Suite* suite_s21_memchr(void);

Suite* suite_s21_strcpy(void);
Suite* suite_s21_strncpy(void);
Suite* suite_s21_strtok(void);
Suite* suite_s21_strstr(void);
Suite* suite_s21_strcspn(void);
Suite* suite_s21_strncmp(void);
Suite* suite_s21_strpbrk(void);
Suite* suite_s21_strncat(void);
Suite* suite_s21_strlen(void);
Suite* suite_s21_strchr(void);

Suite* suite_s21_isalpha(void);
Suite* suite_s21_isdigit(void);
Suite* suite_s21_isspace(void);
Suite* suite_s21_strncasecmp(void);
Suite* suite_s21_strtol(void);
Suite* suite_s21_strtoul(void);
Suite* suite_s21_strtold(void);
Suite* suite_s21_tolower(void);

Suite* suite_s21_to_upper(void);
Suite* suite_s21_to_lower(void);
Suite* suite_s21_insert(void);
Suite* suite_s21_trim(void);

Suite* suite_s21_strrchr(void);
Suite* suite_s21_strerror(void);

void run_test_suite(Suite* test_suite);
void run_tests(void);

#endif
