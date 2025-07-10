#include <string.h>

#include "s21_string.h"
#include "tests/test.h"

START_TEST(memchr_middle_match) {
  const char str[] = "abcdef";
  int find = 'c';
  s21_size_t size = 6;

  char *res_from_lib = memchr(str, find, size);
  char *res_from_s21 = s21_memchr(str, find, size);

  ck_assert_mem_eq(res_from_lib, res_from_s21, 1);
}
END_TEST

START_TEST(memchr_start_match) {
  const char str[] = "aAbcdesf";
  int find = 'a';
  s21_size_t size = strlen(str);

  char *res_from_lib = memchr(str, find, size);
  char *res_from_s21 = s21_memchr(str, find, size);

  ck_assert_mem_eq(res_from_lib, res_from_s21, 1);
}

START_TEST(memchr_upper_match) {
  const char str[] = "asfhkjZZZOOOVVV";
  int find = 'Z';
  s21_size_t size = strlen(str);

  char *res_from_lib = memchr(str, find, size);
  char *res_from_s21 = s21_memchr(str, find, size);

  ck_assert_mem_eq(res_from_lib, res_from_s21, 1);
}

START_TEST(memchr_find_num_in_array_num) {
  int str[] = {1, 2, 3, 666, 5, 99, 100};
  s21_size_t size = sizeof(int) * 7;
  int find = 666;

  char *res_from_lib = memchr(str, find, size);
  char *res_from_s21 = s21_memchr(str, find, size);

  ck_assert_mem_eq(res_from_lib, res_from_s21, 1);
}
END_TEST
START_TEST(memchr_not_find) {
  s21_size_t n_byte = 5;
  char str[10] = "aboba";
  int find_byte = 'c';

  ck_assert_ptr_eq(s21_memchr(str, find_byte, n_byte),
                   memchr(str, find_byte, n_byte));
}
END_TEST

Suite *suite_s21_memchr(void) {
  Suite *suite = suite_create("s21_memchr");
  TCase *tcase_core = tcase_create("core of s21_memchr");

  tcase_add_test(tcase_core, memchr_middle_match);
  tcase_add_test(tcase_core, memchr_start_match);
  tcase_add_test(tcase_core, memchr_upper_match);
  tcase_add_test(tcase_core, memchr_find_num_in_array_num);
  tcase_add_test(tcase_core, memchr_not_find);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
