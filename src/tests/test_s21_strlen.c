#include <stdlib.h>
#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(general_test) {
  const char* str = "super chill kitty cat";
  s21_size_t got_size = s21_strlen(str);
  s21_size_t expected_size = strlen(str);
  ck_assert_int_eq(got_size, expected_size);
}
END_TEST

START_TEST(empty_str) {
  const char* str = "";
  s21_size_t got_size = s21_strlen(str);
  s21_size_t expected_size = strlen(str);
  ck_assert_int_eq(got_size, expected_size);
}
END_TEST

START_TEST(diff_chars) {
  const char* str = "-=_+!@#$^&*()_/';./]";
  s21_size_t got_size = s21_strlen(str);
  s21_size_t expected_size = strlen(str);
  ck_assert_int_eq(got_size, expected_size);
}
END_TEST

Suite* suite_s21_strlen(void) {
  Suite* suite = suite_create("s21_strlen");
  TCase* tcase_core = tcase_create("core of s21_strlen");

  tcase_add_test(tcase_core, general_test);
  tcase_add_test(tcase_core, empty_str);
  tcase_add_test(tcase_core, diff_chars);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
