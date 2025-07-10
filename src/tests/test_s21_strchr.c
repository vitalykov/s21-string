#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(general_test) {
  const char* str = "rubber duck";
  int c = 'd';
  char* got_str = s21_strchr(str, c);
  char* expected_str = strchr(str, c);
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST

START_TEST(not_found) {
  const char* str = "rubber duck";
  int c = 'z';
  char* got_str = s21_strchr(str, c);
  char* expected_str = strchr(str, c);
  ck_assert_pstr_eq(got_str, expected_str);
}
END_TEST

START_TEST(empty_str) {
  const char* str = "";
  int c = '7';
  char* got_str = s21_strchr(str, c);
  char* expected_str = strchr(str, c);
  ck_assert_pstr_eq(got_str, expected_str);
}
END_TEST

START_TEST(empty_int) {
  const char* str = "rubber duck";
  int c = '\0';
  char* got_str = s21_strchr(str, c);
  char* expected_str = strchr(str, c);
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST

Suite* suite_s21_strchr(void) {
  Suite* suite = suite_create("s21_strchr");
  TCase* tcase_core = tcase_create("core of s21_strchr");

  tcase_add_test(tcase_core, general_test);
  tcase_add_test(tcase_core, not_found);
  tcase_add_test(tcase_core, empty_str);
  tcase_add_test(tcase_core, empty_int);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
