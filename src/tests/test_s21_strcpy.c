#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(cpy_eq_dest_size) {
  char got_str[] = "Hello";
  char expected_str[] = "Hello";
  const char src[] = "Night";
  size_t size = 6 * sizeof(char);
  s21_strcpy(got_str, src);
  strcpy(expected_str, src);
  ck_assert_mem_eq(got_str, expected_str, size);
}
END_TEST

START_TEST(cpy_lt_dest_size) {
  char got_str[] = "Hello World";
  char expected_str[] = "Hello World";
  const char src[] = "Night";
  size_t size = sizeof(got_str);
  s21_strcpy(got_str, src);
  strcpy(expected_str, src);
  ck_assert_mem_eq(got_str, expected_str, size);
}
END_TEST

START_TEST(cpy_lt_src_size) {
  char got_str[] = "Hello World";
  char expected_str[] = "Hello World";
  const char src[] = "Night";
  size_t size = sizeof(got_str);
  s21_strcpy(got_str, src);
  strcpy(expected_str, src);
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
  s21_strcpy(got_str, src);
  strcpy(expected_str, src);
  ck_assert_mem_eq(got_str, expected_str, size);
}
END_TEST

Suite *suite_s21_strcpy(void) {
  Suite *suite = suite_create("s21_strcpy");
  TCase *tcase_core = tcase_create("core of s21_strcpy");

  tcase_add_test(tcase_core, cpy_eq_dest_size);
  tcase_add_test(tcase_core, cpy_lt_dest_size);
  tcase_add_test(tcase_core, cpy_lt_src_size);
  tcase_add_test(tcase_core, cpy_long_str);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
