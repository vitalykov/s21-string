#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(general_test) {
  const char* str1 = "fizzbuzz";
  const char* str2 = "xyz";
  char* got_str = s21_strpbrk(str1, str2);
  char* expected_str = strpbrk(str1, str2);
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST

START_TEST(not_found) {
  const char* str1 = "fizzbuzz";
  const char* str2 = "arr";
  char* got_str = s21_strpbrk(str1, str2);
  char* expected_str = strpbrk(str1, str2);
  ck_assert_pstr_eq(got_str, expected_str);
}
END_TEST

START_TEST(empty_str2) {
  const char* str1 = "fizzbuzz";
  const char* str2 = "";
  char* got_str = s21_strpbrk(str1, str2);
  char* expected_str = strpbrk(str1, str2);
  ck_assert_pstr_eq(got_str, expected_str);
}
END_TEST

START_TEST(empty_str1) {
  const char* str1 = "";
  const char* str2 = "fizzbuzz";
  char* got_str = s21_strpbrk(str1, str2);
  char* expected_str = strpbrk(str1, str2);
  ck_assert_pstr_eq(got_str, expected_str);
}
END_TEST

START_TEST(empty_both) {
  const char* str1 = "";
  const char* str2 = "";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(find_capital) {
  const char* str1 = "fizzBUZZ";
  const char* str2 = "Z";
  char* got_str = s21_strpbrk(str1, str2);
  char* expected_str = strpbrk(str1, str2);
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST

Suite* suite_s21_strpbrk(void) {
  Suite* suite = suite_create("s21_strpbrk");
  TCase* tcase_core = tcase_create("core of s21_strpbrk");

  tcase_add_test(tcase_core, general_test);
  tcase_add_test(tcase_core, not_found);
  tcase_add_test(tcase_core, empty_str2);
  tcase_add_test(tcase_core, empty_str1);
  tcase_add_test(tcase_core, empty_both);
  tcase_add_test(tcase_core, find_capital);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
