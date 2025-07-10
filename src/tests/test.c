#include "tests/test.h"

void run_test_suite(Suite* test_suite) {
  SRunner* suite_runner = srunner_create(test_suite);
  srunner_run_all(suite_runner, CK_NORMAL);
  srunner_free(suite_runner);
}

void run_tests(void) {
  Suite* test_suites[] = {suite_s21_memcpy(),
                          suite_s21_memset(),
                          suite_s21_memchr(),
                          suite_s21_memcmp(),

                          suite_s21_strcpy(),
                          suite_s21_strncpy(),
                          suite_s21_strtok(),
                          suite_s21_strrchr(),
                          suite_s21_strerror(),
                          suite_s21_strstr(),
                          suite_s21_strcspn(),
                          suite_s21_strpbrk(),
                          suite_s21_strncmp(),
                          suite_s21_strncat(),
                          suite_s21_strchr(),
                          suite_s21_strlen(),

                          suite_s21_to_upper(),
                          suite_s21_to_lower(),
                          suite_s21_insert(),
                          suite_s21_trim(),

                          suite_s21_sprintf(),

                          suite_s21_sscanf(),
                          suite_s21_isalpha(),
                          suite_s21_isdigit(),
                          suite_s21_isspace(),
                          suite_s21_strncasecmp(),
                          suite_s21_strtol(),
                          suite_s21_strtoul(),
                          suite_s21_strtold(),
                          suite_s21_tolower(),

                          NULL};
  for (Suite** test_suite = test_suites; *test_suite != NULL; ++test_suite) {
    run_test_suite(*test_suite);
  }
}

int main(void) {
  run_tests();
  return 0;
}
