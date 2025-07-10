#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(cpy_eq_dest_size) {
  char got_str[] = "Hello";
  char expected_str[] = "Hello";
  const char src[] = "Night";
  size_t size = 6 * sizeof(char);
  size_t n = 6;
  s21_strncpy(got_str, src, n);
  strncpy(expected_str, src, n);
  ck_assert_mem_eq(got_str, expected_str, size);
}
END_TEST

START_TEST(cpy_lt_dest_size) {
  char got_str[] = "Hello World";
  char expected_str[] = "Hello World";
  const char src[] = "Night";
  size_t size = sizeof(got_str);
  size_t n = 6;
  s21_strncpy(got_str, src, n);
  strncpy(expected_str, src, n);
  ck_assert_mem_eq(got_str, expected_str, size);
}
END_TEST

START_TEST(cpy_lt_src_size) {
  char got_str[] = "Hello World";
  char expected_str[] = "Hello World";
  const char src[] = "Night";
  size_t size = sizeof(got_str);
  size_t n = 3;
  s21_strncpy(got_str, src, n);
  strncpy(expected_str, src, n);
  ck_assert_mem_eq(got_str, expected_str, size);
}
END_TEST

START_TEST(cpy_null_n) {
  char got_str[] = "Hello";
  char expected_str[] = "Hello";
  const char src[] = "Night";
  size_t size = sizeof(got_str);
  size_t n = 0;
  s21_strncpy(got_str, src, n);
  strncpy(expected_str, src, n);
  ck_assert_mem_eq(got_str, expected_str, size);
}
END_TEST

START_TEST(cpy_long_str) {
  char got_str[] =
      "Hello World Hello World Hello World Hello World Hello World Hello World "
      "Hello World Hello World Hello World Hello World Hello World";
  char expected_str[] =
      "Hello World Hello World Hello World Hello World Hello World Hello World "
      "Hello World Hello World Hello World Hello World Hello World";
  const char src[] = "Night Night Night Night Night Night Night Night";
  size_t size = sizeof(got_str);
  size_t n = strlen(src);
  s21_strncpy(got_str, src, n);
  strncpy(expected_str, src, n);
  ck_assert_mem_eq(got_str, expected_str, size);
}
END_TEST

Suite *suite_s21_strncpy(void) {
  Suite *suite = suite_create("s21_strncpy");
  TCase *tcase_core = tcase_create("core of s21_strncpy");

  tcase_add_test(tcase_core, cpy_eq_dest_size);
  tcase_add_test(tcase_core, cpy_lt_dest_size);
  tcase_add_test(tcase_core, cpy_lt_src_size);
  tcase_add_test(tcase_core, cpy_null_n);
  tcase_add_test(tcase_core, cpy_long_str);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
