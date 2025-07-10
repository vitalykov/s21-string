#include <ctype.h>

#include "s21_strlib/s21_strlib.h"
#include "tests/test.h"

START_TEST(test_space) { ck_assert_int_eq(!!s21_isspace(' '), !!isspace(' ')); }
END_TEST

START_TEST(test_tab) { ck_assert_int_eq(!!s21_isspace('\t'), !!isspace('\t')); }
END_TEST

START_TEST(test_newline) {
  ck_assert_int_eq(!!s21_isspace('\n'), !!isspace('\n'));
}
END_TEST

START_TEST(test_carriage_return) {
  ck_assert_int_eq(!!s21_isspace('\r'), !!isspace('\r'));
}
END_TEST

START_TEST(test_form_feed) {
  ck_assert_int_eq(!!s21_isspace('\f'), !!isspace('\f'));
}
END_TEST

START_TEST(test_vertical_tab) {
  ck_assert_int_eq(!!s21_isspace('\v'), !!isspace('\v'));
}
END_TEST

START_TEST(test_non_space_letter) {
  ck_assert_int_eq(!!s21_isspace('a'), !!isspace('a'));
}
END_TEST

START_TEST(test_non_space_digit) {
  ck_assert_int_eq(!!s21_isspace('5'), !!isspace('5'));
}
END_TEST

START_TEST(test_non_space_punctuation) {
  ck_assert_int_eq(!!s21_isspace('!'), !!isspace('!'));
}
END_TEST

START_TEST(test_non_space_control_char) {
  ck_assert_int_eq(!!s21_isspace('\0'), !!isspace('\0'));
}
END_TEST

START_TEST(test_non_space_extended_ascii) {
  ck_assert_int_eq(!!s21_isspace(200), !!isspace(200));
}
END_TEST

Suite* suite_s21_isspace(void) {
  Suite* suite = suite_create("s21_isspace");
  TCase* tcase_core = tcase_create("core of s21_isspace");

  tcase_add_test(tcase_core, test_space);
  tcase_add_test(tcase_core, test_tab);
  tcase_add_test(tcase_core, test_newline);
  tcase_add_test(tcase_core, test_carriage_return);
  tcase_add_test(tcase_core, test_form_feed);
  tcase_add_test(tcase_core, test_vertical_tab);
  tcase_add_test(tcase_core, test_non_space_letter);
  tcase_add_test(tcase_core, test_non_space_digit);
  tcase_add_test(tcase_core, test_non_space_punctuation);
  tcase_add_test(tcase_core, test_non_space_control_char);
  tcase_add_test(tcase_core, test_non_space_extended_ascii);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
