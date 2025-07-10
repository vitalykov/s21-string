#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(several_tokens) {
  char str1[] = "ab - cd, efg";
  char str2[] = "ab - cd, efg";
  char* got_tok = s21_strtok(str1, " ,.-");
  char* expected_tok = strtok(str2, " ,.-");
  ck_assert_pstr_eq(got_tok, expected_tok);
  while (got_tok && expected_tok) {
    got_tok = s21_strtok(NULL, " ,.-");
    expected_tok = strtok(NULL, " ,.-");
    ck_assert_pstr_eq(got_tok, expected_tok);
  }
}
END_TEST

START_TEST(several_tokens_delims_before) {
  char str1[] = " ,.-ab - cd, efg";
  char str2[] = " ,.-ab - cd, efg";
  char* got_tok = s21_strtok(str1, " ,.-");
  char* expected_tok = strtok(str2, " ,.-");
  ck_assert_pstr_eq(got_tok, expected_tok);
  while (got_tok && expected_tok) {
    got_tok = s21_strtok(NULL, " ,.-");
    expected_tok = strtok(NULL, " ,.-");
    ck_assert_pstr_eq(got_tok, expected_tok);
  }
}
END_TEST

START_TEST(several_tokens_delims_after) {
  char str1[] = "ab - cd, efg ,.-";
  char str2[] = "ab - cd, efg ,.-";
  char* got_tok = s21_strtok(str1, " ,.-");
  char* expected_tok = strtok(str2, " ,.-");
  ck_assert_pstr_eq(got_tok, expected_tok);
  while (got_tok && expected_tok) {
    got_tok = s21_strtok(NULL, " ,.-");
    expected_tok = strtok(NULL, " ,.-");
    ck_assert_pstr_eq(got_tok, expected_tok);
  }
}
END_TEST

START_TEST(several_tokens_delims_before_and_after) {
  char str1[] = "-., ab - cd, efg ,.-";
  char str2[] = "ab - cd, efg";
  char* got_tok = s21_strtok(str1, " ,.-");
  char* expected_tok = strtok(str2, " ,.-");
  ck_assert_pstr_eq(got_tok, expected_tok);
  while (got_tok && expected_tok) {
    got_tok = s21_strtok(NULL, " ,.-");
    expected_tok = strtok(NULL, " ,.-");
    ck_assert_pstr_eq(got_tok, expected_tok);
  }
}
END_TEST

START_TEST(one_token) {
  char str1[] = "abcdefg";
  char str2[] = "abcdefg";
  char* got_tok = s21_strtok(str1, " ,.-");
  char* expected_tok = strtok(str2, " ,.-");
  ck_assert_pstr_eq(got_tok, expected_tok);
  while (got_tok && expected_tok) {
    got_tok = s21_strtok(NULL, " ,.-");
    expected_tok = strtok(NULL, " ,.-");
    ck_assert_pstr_eq(got_tok, expected_tok);
  }
}
END_TEST

START_TEST(only_delims) {
  char str1[] = "., -";
  char str2[] = "., -";
  char* got_tok = s21_strtok(str1, " ,.-");
  char* expected_tok = strtok(str2, " ,.-");
  ck_assert_pstr_eq(got_tok, expected_tok);
  while (got_tok && expected_tok) {
    got_tok = s21_strtok(NULL, " ,.-");
    expected_tok = strtok(NULL, " ,.-");
    ck_assert_pstr_eq(got_tok, expected_tok);
  }
}
END_TEST

START_TEST(empty_string) {
  char str1[] = "";
  char str2[] = "";
  char* got_tok = s21_strtok(str1, " ,.-");
  char* expected_tok = strtok(str2, " ,.-");
  ck_assert_pstr_eq(got_tok, expected_tok);
  while (got_tok && expected_tok) {
    got_tok = s21_strtok(NULL, " ,.-");
    expected_tok = strtok(NULL, " ,.-");
    ck_assert_pstr_eq(got_tok, expected_tok);
  }
}
END_TEST

Suite* suite_s21_strtok(void) {
  Suite* suite = suite_create("s21_strtok");
  TCase* tcase_core = tcase_create("core of s21_strtok");

  tcase_add_test(tcase_core, several_tokens);
  tcase_add_test(tcase_core, several_tokens_delims_before);
  tcase_add_test(tcase_core, several_tokens_delims_after);
  tcase_add_test(tcase_core, several_tokens_delims_before_and_after);
  tcase_add_test(tcase_core, one_token);
  tcase_add_test(tcase_core, only_delims);
  tcase_add_test(tcase_core, empty_string);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
