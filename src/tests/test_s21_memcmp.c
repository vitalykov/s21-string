#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(str_equal) {
  const char str1[] = "good vibes only";
  const char str2[] = "good vibes only";
  s21_size_t n = sizeof(str1);
  int got_int = s21_memcmp(str1, str2, n);
  int expected_int = memcmp(str1, str2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(greater_str1) {
  const char str1[] = "good vibes only";
  const char str2[] = "GOOD VIBES ONLY";
  s21_size_t n = sizeof(str1);
  int got_int = s21_memcmp(str1, str2, n);
  int expected_int = memcmp(str1, str2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(greater_str2) {
  const char str1[] = "GOOD VIBES ONLY";
  const char str2[] = "good vibes only";
  s21_size_t n = sizeof(str1);
  int got_int = s21_memcmp(str1, str2, n);
  int expected_int = memcmp(str1, str2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(empty_str1) {
  const char str1[] = "";
  const char str2[] = "good vibes only";
  s21_size_t n = sizeof(str1);
  int got_int = s21_memcmp(str1, str2, n);
  int expected_int = memcmp(str1, str2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(empty_str2) {
  const char str1[] = "good vibes only";
  const char str2[] = "";
  s21_size_t n = sizeof(str2);
  int got_int = s21_memcmp(str1, str2, n);
  int expected_int = memcmp(str1, str2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(empty_both_str) {
  const char str1[] = "";
  const char str2[] = "";
  s21_size_t n = sizeof(str1);
  int got_int = s21_memcmp(str1, str2, n);
  int expected_int = memcmp(str1, str2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(int_array_equal) {
  int arr1[] = {1, 2, 3, 4};
  const int arr2[] = {1, 2, 3, 4};
  s21_size_t n = sizeof(arr1);
  int got_int = s21_memcmp(arr1, arr2, n);
  int expected_int = memcmp(arr1, arr2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(int_greater_arr1) {
  int arr1[] = {1, 2, 4, 5};
  const int arr2[] = {1, 2, 3, 4};
  s21_size_t n = sizeof(arr1);
  int got_int = s21_memcmp(arr1, arr2, n);
  int expected_int = memcmp(arr1, arr2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(int_greater_arr2) {
  int arr1[] = {1, 2, 3, 4};
  const int arr2[] = {1, 2, 4, 5};
  s21_size_t n = sizeof(arr1);
  int got_int = s21_memcmp(arr1, arr2, n);
  int expected_int = memcmp(arr1, arr2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(empty_both_int_arr) {
  int arr1[] = {};
  const int arr2[] = {};
  s21_size_t n = sizeof(arr1);
  int got_int = s21_memcmp(arr1, arr2, n);
  int expected_int = memcmp(arr1, arr2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

START_TEST(compare_zero) {
  const char str1[] = "good vibes only";
  const char str2[] = "good vibes only";
  s21_size_t n = 0;
  int got_int = s21_memcmp(str1, str2, n);
  int expected_int = memcmp(str1, str2, n);
  ck_assert_int_eq(got_int, expected_int);
}
END_TEST

Suite* suite_s21_memcmp(void) {
  Suite* suite = suite_create("s21_memcmp");
  TCase* tcase_core = tcase_create("core of s21_memcmp");

  tcase_add_test(tcase_core, str_equal);
  tcase_add_test(tcase_core, greater_str1);
  tcase_add_test(tcase_core, greater_str2);
  tcase_add_test(tcase_core, empty_str1);
  tcase_add_test(tcase_core, empty_str2);
  tcase_add_test(tcase_core, empty_both_str);
  tcase_add_test(tcase_core, int_array_equal);
  tcase_add_test(tcase_core, int_greater_arr1);
  tcase_add_test(tcase_core, int_greater_arr2);
  tcase_add_test(tcase_core, empty_both_int_arr);
  tcase_add_test(tcase_core, compare_zero);

  suite_add_tcase(suite, tcase_core);
  return suite;
}