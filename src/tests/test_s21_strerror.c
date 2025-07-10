#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(strerror_valid_code_1) {
  int err = 1;
  char *res_from_lib = strerror(err);
  char *res_from_s21 = s21_strerror(err);

  ck_assert_str_eq(res_from_lib, res_from_s21);
}
END_TEST

START_TEST(strerror_valid_code_2) {
  int err = 5;
  char *res_from_lib = strerror(err);
  char *res_from_s21 = s21_strerror(err);

  ck_assert_str_eq(res_from_lib, res_from_s21);
}
END_TEST

START_TEST(strerror_valid_code_10) {
  int err = 10;
  char *res_from_lib = strerror(err);
  char *res_from_s21 = s21_strerror(err);

  ck_assert_str_eq(res_from_lib, res_from_s21);
}
END_TEST

START_TEST(strerror_unknown_negative_code) {
  int err = -100;
  char *res_from_lib = strerror(err);
  char *res_from_s21 = s21_strerror(err);

  ck_assert_str_eq(res_from_lib, res_from_s21);
}
END_TEST

START_TEST(strerror_unknown_large_code) {
  int err = 300;  // Вне диапазона strerror
  char *res_from_lib = strerror(err);
  char *res_from_s21 = s21_strerror(err);

  ck_assert_str_eq(res_from_lib, res_from_s21);
}
END_TEST

START_TEST(strerror_zero_code) {
  int err = 0;
  char *res_from_lib = strerror(err);
  char *res_from_s21 = s21_strerror(err);

  ck_assert_str_eq(res_from_lib, res_from_s21);
}
END_TEST

Suite *suite_s21_strerror(void) {
  Suite *suite = suite_create("s21_strerror");
  TCase *tcase_core = tcase_create("core of s21_strerror");

  tcase_add_test(tcase_core, strerror_valid_code_1);
  tcase_add_test(tcase_core, strerror_valid_code_2);
  tcase_add_test(tcase_core, strerror_valid_code_10);
  tcase_add_test(tcase_core, strerror_zero_code);
  tcase_add_test(tcase_core, strerror_unknown_negative_code);
  tcase_add_test(tcase_core, strerror_unknown_large_code);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
