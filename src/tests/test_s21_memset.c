#include <stdlib.h>
#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(set_eq_size) {
  size_t len = 5;
  size_t size = len * sizeof(char);
  char* got_str = malloc(size);
  char* expected_str = malloc(size);
  if (got_str && expected_str) {
    int src = '1';
    s21_memset(got_str, src, size);
    memset(expected_str, src, size);
  }
  ck_assert_mem_eq(got_str, expected_str, size);
  if (got_str != NULL) free(got_str);
  if (expected_str != NULL) free(expected_str);
}
END_TEST

START_TEST(set_lt_size) {
  size_t len = 5;
  size_t len_memset = 3;
  size_t size = len * sizeof(char);
  size_t size_memset = len_memset * sizeof(char);
  char* got_str = calloc(len, sizeof(char));
  char* expected_str = calloc(len, sizeof(char));
  if (got_str && expected_str) {
    int src = '1';
    s21_memset(got_str, src, size_memset);
    memset(expected_str, src, size_memset);
  }
  ck_assert_mem_eq(got_str, expected_str, size);
  if (got_str != NULL) free(got_str);
  if (expected_str != NULL) free(expected_str);
}
END_TEST

START_TEST(set_null_size) {
  size_t len = 5;
  size_t size = len * sizeof(char);
  char* got_str = calloc(len, sizeof(char));
  char* expected_str = calloc(len, sizeof(char));
  if (got_str && expected_str) {
    int src = '1';
    size_t size_memset = 0;
    s21_memset(got_str, src, size_memset);
    memset(expected_str, src, size_memset);
  }
  ck_assert_mem_eq(got_str, expected_str, size);
  if (got_str != NULL) free(got_str);
  if (expected_str != NULL) free(expected_str);
}
END_TEST

Suite* suite_s21_memset(void) {
  Suite* suite = suite_create("s21_memset");
  TCase* tcase_core = tcase_create("core of s21_memset");

  tcase_add_test(tcase_core, set_eq_size);
  tcase_add_test(tcase_core, set_lt_size);
  tcase_add_test(tcase_core, set_null_size);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
