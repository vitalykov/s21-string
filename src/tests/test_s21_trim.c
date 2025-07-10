#include <stdlib.h>
#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(trim_regular_spaces) {
  const char *src = "   Hello, world!   ";
  const char *trim_chars = " ";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, "Hello, world!");
  free(res);
}
END_TEST

START_TEST(trim_tabs_and_newlines) {
  const char *src = "\n\t  Hello\t\n";
  const char *trim_chars = " \t\n";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, "Hello");
  free(res);
}
END_TEST

START_TEST(trim_custom_chars) {
  const char *src = "---++hello++---";
  const char *trim_chars = "-+";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, "hello");
  free(res);
}
END_TEST

START_TEST(trim_no_trimming_needed) {
  const char *src = "clean";
  const char *trim_chars = "*";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, "clean");
  free(res);
}
END_TEST

START_TEST(trim_all_trimmed) {
  const char *src = "****";
  const char *trim_chars = "*";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(trim_empty_string) {
  const char *src = "";
  const char *trim_chars = " ";
  char *res = s21_trim(src, trim_chars);
  ck_assert_str_eq(res, "");
  free(res);
}
END_TEST

START_TEST(trim_null_trim_chars) {
  const char *src = " \t\nHello World\n\t ";
  char *res = s21_trim(src, S21_NULL);
  ck_assert_str_eq(res, "Hello World");
  free(res);
}
END_TEST

Suite *suite_s21_trim(void) {
  Suite *suite = suite_create("s21_trim");
  TCase *tcase_core = tcase_create("core of s21_trim");

  tcase_add_test(tcase_core, trim_regular_spaces);
  tcase_add_test(tcase_core, trim_tabs_and_newlines);
  tcase_add_test(tcase_core, trim_custom_chars);
  tcase_add_test(tcase_core, trim_no_trimming_needed);
  tcase_add_test(tcase_core, trim_all_trimmed);
  tcase_add_test(tcase_core, trim_empty_string);
  tcase_add_test(tcase_core, trim_null_trim_chars);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
