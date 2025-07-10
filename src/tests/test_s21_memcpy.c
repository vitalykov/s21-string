#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(cpy_eq_size) {
  char got_str[] = "Hello";
  char expected_str[] = "Hello";
  const char src[] = "Night";
  size_t size = 6 * sizeof(char);
  s21_memcpy(got_str, src, size);
  memcpy(expected_str, src, size);
  ck_assert_mem_eq(got_str, expected_str, size);
}
END_TEST

START_TEST(cpy_lt_size) {
  char got_str[] = "Hello World";
  char expected_str[] = "Hello World";
  const char src[] = "Night";
  size_t size = sizeof(got_str);
  size_t size_memcpy = sizeof(src) - sizeof(char);
  s21_memcpy(got_str, src, size_memcpy);
  memcpy(expected_str, src, size_memcpy);
  ck_assert_mem_eq(got_str, expected_str, size);
}
END_TEST

START_TEST(cpy_null_size) {
  char got_str[] = "Hello";
  char expected_str[] = "Hello";
  const char src[] = "Night";
  size_t size = 6 * sizeof(char);
  size_t size_memcpy = 0;
  s21_memcpy(got_str, src, size_memcpy);
  memcpy(expected_str, src, size_memcpy);
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
  const char src[] = "Night";
  size_t size = sizeof(got_str);
  size_t size_memcpy = sizeof(src) - sizeof(char);
  s21_memcpy(got_str, src, size_memcpy);
  memcpy(expected_str, src, size_memcpy);
  ck_assert_mem_eq(got_str, expected_str, size);
}
END_TEST

Suite *suite_s21_memcpy(void) {
  Suite *suite = suite_create("s21_memcpy");
  TCase *tcase_core = tcase_create("core of s21_memcpy");

  tcase_add_test(tcase_core, cpy_eq_size);
  tcase_add_test(tcase_core, cpy_lt_size);
  tcase_add_test(tcase_core, cpy_null_size);
  tcase_add_test(tcase_core, cpy_long_str);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
