#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(strrchr_empty_str) {
  const char str[] = "";
  int c = '1';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_some_cin_str) {
  const char str[] = "hellell556o";
  int c = '5';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_empty_str_and_c) {
  const char str[] = "";
  int c = '\0';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_empty_c) {
  const char str[] = "Some meaningless text";
  int c = '\0';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_regular_test) {
  const char str[] = "1Greetings";
  int c = '1';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_no_match_test) {
  const char str[] = "i need this text";
  int c = '5';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_one_symbol_test) {
  const char str[] = "1";
  int c = '1';

  ck_assert_pstr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

Suite *suite_s21_strrchr(void) {
  Suite *suite = suite_create("s21_strrchr");
  TCase *tcase_core = tcase_create("core of s21_strrchr");

  tcase_add_test(tcase_core, strrchr_empty_str);
  tcase_add_test(tcase_core, strrchr_some_cin_str);
  tcase_add_test(tcase_core, strrchr_empty_str_and_c);
  tcase_add_test(tcase_core, strrchr_empty_c);
  tcase_add_test(tcase_core, strrchr_no_match_test);
  tcase_add_test(tcase_core, strrchr_regular_test);
  tcase_add_test(tcase_core, strrchr_one_symbol_test);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
