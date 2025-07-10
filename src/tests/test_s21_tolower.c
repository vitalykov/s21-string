#include <ctype.h>
#include <limits.h>

#include "s21_strlib/s21_strlib.h"
#include "tests/test.h"

// Test uppercase letters (A-Z)
START_TEST(test_uppercase_A) {
  ck_assert_int_eq(s21_tolower('A'), tolower('A'));
}
END_TEST

START_TEST(test_uppercase_M) {
  ck_assert_int_eq(s21_tolower('M'), tolower('M'));
}
END_TEST

START_TEST(test_uppercase_Z) {
  ck_assert_int_eq(s21_tolower('Z'), tolower('Z'));
}
END_TEST

// Test lowercase letters (a-z) should remain unchanged
START_TEST(test_lowercase_a) {
  ck_assert_int_eq(s21_tolower('a'), tolower('a'));
}
END_TEST

START_TEST(test_lowercase_z) {
  ck_assert_int_eq(s21_tolower('z'), tolower('z'));
}
END_TEST

// Test non-alphabetic characters
START_TEST(test_digit_0) { ck_assert_int_eq(s21_tolower('0'), tolower('0')); }
END_TEST

START_TEST(test_digit_9) { ck_assert_int_eq(s21_tolower('9'), tolower('9')); }
END_TEST

START_TEST(test_space) { ck_assert_int_eq(s21_tolower(' '), tolower(' ')); }
END_TEST

START_TEST(test_tab) { ck_assert_int_eq(s21_tolower('\t'), tolower('\t')); }
END_TEST

START_TEST(test_punctuation) {
  ck_assert_int_eq(s21_tolower('!'), tolower('!'));
}
END_TEST

// Test boundary cases
START_TEST(test_before_A) { ck_assert_int_eq(s21_tolower('@'), tolower('@')); }
END_TEST

START_TEST(test_after_Z) { ck_assert_int_eq(s21_tolower('['), tolower('[')); }
END_TEST

START_TEST(test_before_a) { ck_assert_int_eq(s21_tolower('`'), tolower('`')); }
END_TEST

START_TEST(test_after_z) { ck_assert_int_eq(s21_tolower('{'), tolower('{')); }
END_TEST

// Test extended ASCII and negative values
START_TEST(test_extended_ascii) {
  ck_assert_int_eq(s21_tolower(200), tolower(200));
}
END_TEST

Suite* suite_s21_tolower(void) {
  Suite* suite = suite_create("s21_tolower");
  TCase* tcase_core = tcase_create("core of s21_tolower");

  tcase_add_test(tcase_core, test_uppercase_A);
  tcase_add_test(tcase_core, test_uppercase_M);
  tcase_add_test(tcase_core, test_uppercase_Z);
  tcase_add_test(tcase_core, test_lowercase_a);
  tcase_add_test(tcase_core, test_lowercase_z);
  tcase_add_test(tcase_core, test_digit_0);
  tcase_add_test(tcase_core, test_digit_9);
  tcase_add_test(tcase_core, test_space);
  tcase_add_test(tcase_core, test_tab);
  tcase_add_test(tcase_core, test_punctuation);
  tcase_add_test(tcase_core, test_before_A);
  tcase_add_test(tcase_core, test_after_Z);
  tcase_add_test(tcase_core, test_before_a);
  tcase_add_test(tcase_core, test_after_z);
  tcase_add_test(tcase_core, test_extended_ascii);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
