#include <stdlib.h>
#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(regular_test) {
  const char *src = "HELLO WORLD";
  char *s21_res = s21_to_lower(src);

  ck_assert_str_eq(s21_res, "hello world");
  free(s21_res);
}
END_TEST

START_TEST(mixed_case_test) {
  const char *src = "HeLLo WoRLd";
  char *s21_res = s21_to_lower(src);
  ck_assert_str_eq(s21_res, "hello world");
  free(s21_res);
}
END_TEST

START_TEST(only_lowercase_test) {
  const char *src = "hello";
  char *s21_res = s21_to_lower(src);
  ck_assert_str_eq(s21_res, "hello");
  free(s21_res);
}
END_TEST

START_TEST(with_numbers_and_symbols_test) {
  const char *src = "ABC123!@#";
  char *s21_res = s21_to_lower(src);
  ck_assert_str_eq(s21_res, "abc123!@#");
  free(s21_res);
}
END_TEST

START_TEST(empty_string_test) {
  const char *src = "";
  char *s21_res = s21_to_lower(src);
  ck_assert_str_eq(s21_res, "");
  free(s21_res);
}
END_TEST

START_TEST(one_letter_test) {
  const char *src = "Z";
  char *s21_res = s21_to_lower(src);
  ck_assert_str_eq(s21_res, "z");
  free(s21_res);
}
END_TEST

START_TEST(long_string_test) {
  const char *src = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *s21_res = s21_to_lower(src);
  ck_assert_str_eq(s21_res, "abcdefghijklmnopqrstuvwxyz");
  free(s21_res);
}
END_TEST

Suite *suite_s21_to_lower(void) {
  Suite *suite = suite_create("s21_to_lower");
  TCase *tcase_core = tcase_create("core of s21_to_lower");

  tcase_add_test(tcase_core, regular_test);
  tcase_add_test(tcase_core, mixed_case_test);
  tcase_add_test(tcase_core, only_lowercase_test);
  tcase_add_test(tcase_core, with_numbers_and_symbols_test);
  tcase_add_test(tcase_core, empty_string_test);
  tcase_add_test(tcase_core, one_letter_test);
  tcase_add_test(tcase_core, long_string_test);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
