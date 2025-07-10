#include <stdlib.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(regular_test) {
  const char* src = "Hello World";
  const char* str = "Beautiful ";
  s21_size_t index = 6;

  char* s21_res = s21_insert(src, str, index);

  ck_assert_str_eq(s21_res, "Hello Beautiful World");

  if (s21_res != S21_NULL) free(s21_res);
}
END_TEST

START_TEST(insert_to_beginning) {
  const char* src = "world";
  const char* str = "hello ";
  char* res = s21_insert(src, str, 0);

  ck_assert_str_eq(res, "hello world");
  if (res != S21_NULL) free(res);
}
END_TEST

START_TEST(insert_to_end) {
  const char* src = "hello";
  const char* str = " world";
  char* res = s21_insert(src, str, 5);

  ck_assert_str_eq(res, "hello world");
  if (res != S21_NULL) free(res);
}
END_TEST

START_TEST(insert_empty_string) {
  const char* src = "hello";
  const char* str = "";
  char* res = s21_insert(src, str, 2);

  ck_assert_str_eq(res, "hello");
  if (res != S21_NULL) free(res);
}
END_TEST

START_TEST(insert_into_empty_source) {
  const char* src = "";
  const char* str = "hello";
  char* res = s21_insert(src, str, 0);

  ck_assert_str_eq(res, "hello");
  if (res != S21_NULL) free(res);
}
END_TEST

START_TEST(insert_index_too_big) {
  const char* src = "short";
  const char* str = "longer";
  char* res = s21_insert(src, str, 10);

  ck_assert_ptr_eq(res, S21_NULL);
  if (res != S21_NULL) free(res);
}
END_TEST

START_TEST(insert_null_argument) {
  const char* src = "text";
  char* res1 = s21_insert(S21_NULL, src, 2);
  char* res2 = s21_insert(src, S21_NULL, 2);

  ck_assert_ptr_eq(res1, S21_NULL);
  ck_assert_ptr_eq(res2, S21_NULL);
  if (res1 != S21_NULL) free(res1);
  if (res2 != S21_NULL) free(res2);
}
END_TEST

Suite* suite_s21_insert(void) {
  Suite* suite = suite_create("s21_insert");
  TCase* tcase_core = tcase_create("core of s21_insert");

  tcase_add_test(tcase_core, regular_test);
  tcase_add_test(tcase_core, insert_to_beginning);
  tcase_add_test(tcase_core, insert_to_end);
  tcase_add_test(tcase_core, insert_empty_string);
  tcase_add_test(tcase_core, insert_into_empty_source);
  tcase_add_test(tcase_core, insert_index_too_big);
  tcase_add_test(tcase_core, insert_null_argument);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
