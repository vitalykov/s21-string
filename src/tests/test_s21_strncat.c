#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(general_test) {
  const char src[] = "more";
  s21_size_t n = 4;
  char got_str[14] = "leetcode ";
  s21_strncat(got_str, src, n);
  char expected_str[14] = "leetcode ";
  strncat(expected_str, src, n);
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST

START_TEST(concatenate_more) {
  const char src[] = "m";
  s21_size_t n = 4;
  char got_str[14] = "leetcode ";
  s21_strncat(got_str, src, n);
  char expected_str[14] = "leetcode ";
  strncat(expected_str, src, n);
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST

START_TEST(empty_src) {
  const char src[] = "";
  s21_size_t n = 4;
  char got_str[14] = "leetcode ";
  s21_strncat(got_str, src, n);
  char expected_str[14] = "leetcode ";
  strncat(expected_str, src, n);
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST

START_TEST(empty_dest) {
  const char src[] = "leetcode";
  s21_size_t n = 4;
  char got_str[14] = "";
  s21_strncat(got_str, src, n);
  char expected_str[14] = "";
  strncat(expected_str, src, n);
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST

START_TEST(concatenate_zero) {
  const char* src = "more";
  s21_size_t n = 0;
  char got_str[14] = "leetcode ";
  s21_strncat(got_str, src, n);
  char expected_str[14] = "leetcode ";
  strncat(expected_str, src, n);
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST

Suite* suite_s21_strncat(void) {
  Suite* suite = suite_create("s21_strncat");
  TCase* tcase_core = tcase_create("core of s21_strncat");

  tcase_add_test(tcase_core, general_test);
  tcase_add_test(tcase_core, concatenate_more);
  tcase_add_test(tcase_core, empty_src);
  tcase_add_test(tcase_core, empty_dest);
  tcase_add_test(tcase_core, concatenate_zero);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
