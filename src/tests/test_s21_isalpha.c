#include <ctype.h>

#include "s21_strlib/s21_strlib.h"
#include "tests/test.h"

START_TEST(test_lowercase_a) {
  ck_assert_int_eq(!!s21_isalpha('a'), !!isalpha('a'));
}
END_TEST

START_TEST(test_lowercase_z) {
  ck_assert_int_eq(!!s21_isalpha('z'), !!isalpha('z'));
}
END_TEST

START_TEST(test_uppercase_A) {
  ck_assert_int_eq(!!s21_isalpha('A'), !!isalpha('A'));
}
END_TEST

START_TEST(test_uppercase_Z) {
  ck_assert_int_eq(!!s21_isalpha('Z'), !!isalpha('Z'));
}
END_TEST

START_TEST(test_digit_0) {
  ck_assert_int_eq(!!s21_isalpha('0'), !!isalpha('0'));
}
END_TEST

START_TEST(test_digit_9) {
  ck_assert_int_eq(!!s21_isalpha('9'), !!isalpha('9'));
}
END_TEST

START_TEST(test_space) { ck_assert_int_eq(!!s21_isalpha(' '), !!isalpha(' ')); }
END_TEST

START_TEST(test_tab) { ck_assert_int_eq(!!s21_isalpha('\t'), !!isalpha('\t')); }
END_TEST

START_TEST(test_newline) {
  ck_assert_int_eq(!!s21_isalpha('\n'), !!isalpha('\n'));
}
END_TEST

START_TEST(test_punctuation) {
  ck_assert_int_eq(!!s21_isalpha('!'), !!isalpha('!'));
}
END_TEST

START_TEST(test_before_A) {
  ck_assert_int_eq(!!s21_isalpha('@'), !!isalpha('@'));
}
END_TEST

START_TEST(test_after_Z) {
  ck_assert_int_eq(!!s21_isalpha('['), !!isalpha('['));
}
END_TEST

START_TEST(test_before_a) {
  ck_assert_int_eq(!!s21_isalpha('`'), !!isalpha('`'));
}
END_TEST

START_TEST(test_after_z) {
  ck_assert_int_eq(!!s21_isalpha('{'), !!isalpha('{'));
}
END_TEST

START_TEST(test_extended_ascii) {
  ck_assert_int_eq(!!s21_isalpha(128), !!isalpha(128));
}
END_TEST

Suite* suite_s21_isalpha(void) {
  Suite* suite = suite_create("s21_isalpha");
  TCase* tcase_core = tcase_create("core of s21_isalpha");

  tcase_add_test(tcase_core, test_lowercase_a);
  tcase_add_test(tcase_core, test_lowercase_z);
  tcase_add_test(tcase_core, test_uppercase_A);
  tcase_add_test(tcase_core, test_uppercase_Z);
  tcase_add_test(tcase_core, test_digit_0);
  tcase_add_test(tcase_core, test_digit_9);
  tcase_add_test(tcase_core, test_space);
  tcase_add_test(tcase_core, test_tab);
  tcase_add_test(tcase_core, test_newline);
  tcase_add_test(tcase_core, test_punctuation);
  tcase_add_test(tcase_core, test_before_A);
  tcase_add_test(tcase_core, test_after_Z);
  tcase_add_test(tcase_core, test_before_a);
  tcase_add_test(tcase_core, test_after_z);
  tcase_add_test(tcase_core, test_extended_ascii);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
