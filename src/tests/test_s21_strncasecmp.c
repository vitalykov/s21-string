#include <strings.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(test_equal_basic) {
  const char *a = "hello";
  const char *b = "HELLO";
  ck_assert_int_eq(s21_strncasecmp(a, b, 5), strncasecmp(a, b, 5));
}
END_TEST

START_TEST(test_partial_comparison) {
  const char *a = "prefix";
  const char *b = "PREFER";
  ck_assert_int_eq(s21_strncasecmp(a, b, 4), strncasecmp(a, b, 4));
}
END_TEST

START_TEST(test_empty_strings) {
  const char *a = "";
  const char *b = "";
  ck_assert_int_eq(s21_strncasecmp(a, b, 1), strncasecmp(a, b, 1));
}
END_TEST

START_TEST(test_zero_length) {
  const char *a = "anything";
  const char *b = "different";
  ck_assert_int_eq(s21_strncasecmp(a, b, 0), strncasecmp(a, b, 0));
}
END_TEST

START_TEST(test_special_chars) {
  const char *a = "Hello123";
  const char *b = "hELLO123";
  ck_assert_int_eq(s21_strncasecmp(a, b, 8), strncasecmp(a, b, 8));
}
END_TEST

Suite *suite_s21_strncasecmp(void) {
  Suite *s = suite_create("s21_strncasecmp");
  TCase *tc = tcase_create("core of s21_strncasecmp");

  tcase_add_test(tc, test_equal_basic);
  tcase_add_test(tc, test_partial_comparison);
  tcase_add_test(tc, test_empty_strings);
  tcase_add_test(tc, test_zero_length);
  tcase_add_test(tc, test_special_chars);

  suite_add_tcase(s, tc);
  return s;
}
