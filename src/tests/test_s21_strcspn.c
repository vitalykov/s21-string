#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(general_test) {
  const char* str1 = "it's not a bug, it's a feature";
  const char* str2 = "feature";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(all_different) {
  const char* str1 = "it's not a bug, it's a feature";
  const char* str2 = "zzzz";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(empty_str1) {
  const char* str1 = "";
  const char* str2 = "bug";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(empty_str2) {
  const char* str1 = "feature";
  const char* str2 = "";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(empty_both) {
  const char* str1 = "";
  const char* str2 = "";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

START_TEST(diff_register) {
  const char* str1 = "it's not a bug, it's a feature";
  const char* str2 = "NOT BUG BUT FEATURE";

  ck_assert_int_eq(s21_strcspn(str1, str2), strcspn(str1, str2));
}
END_TEST

Suite* suite_s21_strcspn(void) {
  Suite* suite = suite_create("s21_strcspn");
  TCase* tcase_core = tcase_create("core of s21_strcspn");

  tcase_add_test(tcase_core, general_test);
  tcase_add_test(tcase_core, all_different);
  tcase_add_test(tcase_core, empty_str1);
  tcase_add_test(tcase_core, empty_str2);
  tcase_add_test(tcase_core, empty_both);
  tcase_add_test(tcase_core, diff_register);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
