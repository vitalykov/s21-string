#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(general_test_equal) {
  const char* str1 = "good vibes only";
  const char* str2 = "good vibes only";
  s21_size_t n = 7;
  int got_int = s21_strncmp(str1, str2, n);
  int expected_int = strncmp(str1, str2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(general_test_greater_str1) {
  const char* str1 = "good vibes only";
  const char* str2 = "GOOD VIBES ONLY";
  s21_size_t n = 7;
  int got_int = s21_strncmp(str1, str2, n);
  int expected_int = strncmp(str1, str2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(general_test_greater_str2) {
  const char* str1 = "GOOD VIBES ONLY";
  const char* str2 = "good vibes only";
  s21_size_t n = 7;
  int got_int = s21_strncmp(str1, str2, n);
  int expected_int = strncmp(str1, str2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(empty_str1) {
  const char* str1 = "";
  const char* str2 = "good vibes only";
  s21_size_t n = 4;
  int got_int = s21_strncmp(str1, str2, n);
  int expected_int = strncmp(str1, str2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(empty_str2) {
  const char* str1 = "good vibes only";
  const char* str2 = "";
  s21_size_t n = 4;
  int got_int = s21_strncmp(str1, str2, n);
  int expected_int = strncmp(str1, str2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(empty_both) {
  const char* str1 = "";
  const char* str2 = "";
  s21_size_t n = 4;
  int got_int = s21_strncmp(str1, str2, n);
  int expected_int = strncmp(str1, str2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(compare_zero) {
  const char* str1 = "good vibes only";
  const char* str2 = "good vibes only";
  s21_size_t n = 0;
  int got_int = s21_strncmp(str1, str2, n);
  int expected_int = strncmp(str1, str2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

Suite* suite_s21_strncmp(void) {
  Suite* suite = suite_create("s21_strncmp");
  TCase* tcase_core = tcase_create("core of s21_strncmp");

  tcase_add_test(tcase_core, general_test_equal);
  tcase_add_test(tcase_core, general_test_greater_str1);
  tcase_add_test(tcase_core, general_test_greater_str2);
  tcase_add_test(tcase_core, empty_str1);
  tcase_add_test(tcase_core, empty_str2);
  tcase_add_test(tcase_core, empty_both);
  tcase_add_test(tcase_core, compare_zero);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
