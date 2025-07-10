#include <ctype.h>

#include "s21_strlib/s21_strlib.h"
#include "tests/test.h"

START_TEST(test_digit_0) {
  ck_assert_int_eq(!!s21_isdigit('0'), !!isdigit('0'));
}
END_TEST

START_TEST(test_digit_5) {
  ck_assert_int_eq(!!s21_isdigit('5'), !!isdigit('5'));
}
END_TEST

START_TEST(test_digit_9) {
  ck_assert_int_eq(!!s21_isdigit('9'), !!isdigit('9'));
}
END_TEST

START_TEST(test_below_0) {
  ck_assert_int_eq(!!s21_isdigit('/'),
                   !!isdigit('/'));  // '/' is before '0' in ASCII
}
END_TEST

START_TEST(test_above_9) {
  ck_assert_int_eq(!!s21_isdigit(':'),
                   !!isdigit(':'));  // ':' is after '9' in ASCII
}
END_TEST

START_TEST(test_lowercase_a) {
  ck_assert_int_eq(!!s21_isdigit('a'), !!isdigit('a'));
}
END_TEST

START_TEST(test_uppercase_A) {
  ck_assert_int_eq(!!s21_isdigit('A'), !!isdigit('A'));
}
END_TEST

START_TEST(test_space) { ck_assert_int_eq(!!s21_isdigit(' '), !!isdigit(' ')); }
END_TEST

START_TEST(test_tab) { ck_assert_int_eq(!!s21_isdigit('\t'), !!isdigit('\t')); }
END_TEST

START_TEST(test_newline) {
  ck_assert_int_eq(!!s21_isdigit('\n'), !!isdigit('\n'));
}
END_TEST

START_TEST(test_punctuation) {
  ck_assert_int_eq(!!s21_isdigit('!'), !!isdigit('!'));
}
END_TEST

START_TEST(test_extended_ascii) {
  ck_assert_int_eq(!!s21_isdigit(200), !!isdigit(200));
}
END_TEST

Suite* suite_s21_isdigit(void) {
  Suite* suite = suite_create("s21_isdigit");
  TCase* tcase_core = tcase_create("core of s21_isdigit");

  tcase_add_test(tcase_core, test_digit_0);
  tcase_add_test(tcase_core, test_digit_5);
  tcase_add_test(tcase_core, test_digit_9);
  tcase_add_test(tcase_core, test_below_0);
  tcase_add_test(tcase_core, test_above_9);
  tcase_add_test(tcase_core, test_lowercase_a);
  tcase_add_test(tcase_core, test_uppercase_A);
  tcase_add_test(tcase_core, test_space);
  tcase_add_test(tcase_core, test_tab);
  tcase_add_test(tcase_core, test_newline);
  tcase_add_test(tcase_core, test_punctuation);
  tcase_add_test(tcase_core, test_extended_ascii);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
