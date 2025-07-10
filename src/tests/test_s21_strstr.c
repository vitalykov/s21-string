#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(general_test_1) {
  const char* haystack = "Hello, darkness, my old friend";
  const char* needle = "old";
  char* got_str = s21_strstr(haystack, needle);
  char* expected_str = strstr(haystack, needle);
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST

START_TEST(general_test_2) {
  const char* haystack = "mississippi";
  const char* needle = "issip";
  char* got_str = s21_strstr(haystack, needle);
  char* expected_str = strstr(haystack, needle);
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST

START_TEST(not_found) {
  const char* haystack = "Hello, darkness, my old friend";
  const char* needle = "new";
  char* got_str = s21_strstr(haystack, needle);
  char* expected_str = strstr(haystack, needle);
  ck_assert_pstr_eq(got_str, expected_str);
}
END_TEST

START_TEST(all_different) {
  const char* haystack = "123";
  const char* needle = "456";
  char* got_str = s21_strstr(haystack, needle);
  char* expected_str = strstr(haystack, needle);
  ck_assert_pstr_eq(got_str, expected_str);
}
END_TEST

START_TEST(equal_suffix_prefix) {
  const char* haystack = "running barefoot";
  const char* needle = "football";
  char* got_str = s21_strstr(haystack, needle);
  char* expected_str = strstr(haystack, needle);
  ck_assert_pstr_eq(got_str, expected_str);
}
END_TEST

START_TEST(equal_suffix_prefix_num) {
  const char* haystack = "001";
  const char* needle = "123";
  char* got_str = s21_strstr(haystack, needle);
  char* expected_str = strstr(haystack, needle);
  ck_assert_pstr_eq(got_str, expected_str);
}
END_TEST

START_TEST(empty_haystack) {
  const char* haystack = "";
  const char* needle = "old";
  char* got_str = s21_strstr(haystack, needle);
  char* expected_str = strstr(haystack, needle);
  ck_assert_pstr_eq(got_str, expected_str);
}
END_TEST

START_TEST(empty_needle) {
  const char* haystack = "Hello, darkness, my old friend";
  const char* needle = "";
  char* got_str = s21_strstr(haystack, needle);
  char* expected_str = strstr(haystack, needle);
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST

START_TEST(empty_both) {
  const char* haystack = "";
  const char* needle = "";
  char* got_str = s21_strstr(haystack, needle);
  char* expected_str = strstr(haystack, needle);
  ck_assert_pstr_eq(got_str, expected_str);
}
END_TEST

Suite* suite_s21_strstr(void) {
  Suite* suite = suite_create("s21_strstr");
  TCase* tcase_core = tcase_create("core of s21_strstr");

  tcase_add_test(tcase_core, general_test_1);
  tcase_add_test(tcase_core, general_test_2);
  tcase_add_test(tcase_core, not_found);
  tcase_add_test(tcase_core, all_different);
  tcase_add_test(tcase_core, equal_suffix_prefix);
  tcase_add_test(tcase_core, equal_suffix_prefix_num);
  tcase_add_test(tcase_core, empty_haystack);
  tcase_add_test(tcase_core, empty_needle);
  tcase_add_test(tcase_core, empty_both);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
