#include <errno.h>
#include <limits.h>
#include <stdlib.h>

#include "s21_strlib/s21_strlib.h"
#include "tests/test.h"

#define TEST_STRTOL(input, base)                                  \
  {                                                               \
    char* expected_endptr = NULL;                                 \
    char* got_endptr = NULL;                                      \
    long expected_result = strtol(input, &expected_endptr, base); \
    long got_result = s21_strtol(input, &got_endptr, base);       \
    ck_assert_int_eq(got_result, expected_result);                \
    ck_assert_ptr_eq(got_endptr, expected_endptr);                \
  }

START_TEST(basic_conversion) {
  const char str[] = "12345";
  TEST_STRTOL(str, 10);
}
END_TEST

START_TEST(partial_conversion) {
  const char str[] = "123abc";
  TEST_STRTOL(str, 10);
}
END_TEST

START_TEST(leading_whitespace) {
  const char str[] = "   \t\n+456";
  TEST_STRTOL(str, 10);
}
END_TEST

START_TEST(negative_number) {
  const char str[] = "-9876";
  TEST_STRTOL(str, 10);
}
END_TEST

START_TEST(hexadecimal) {
  const char str[] = "0x1aF3";
  TEST_STRTOL(str, 16);
}
END_TEST

START_TEST(hexadecimal_autodetect) {
  const char str[] = "0x1aF3";
  TEST_STRTOL(str, 0);
}
END_TEST

START_TEST(octal) {
  const char str[] = "0755";
  TEST_STRTOL(str, 8);
}
END_TEST

START_TEST(octal_autodetect) {
  const char str[] = "0755";
  TEST_STRTOL(str, 0);
}
END_TEST

START_TEST(decimal_with_leading_zero) {
  const char str[] = "0123";
  TEST_STRTOL(str, 10);
}
END_TEST

START_TEST(overflow) {
  const char str[] = "99999999999999999999";
  TEST_STRTOL(str, 10);
}
END_TEST

START_TEST(underflow) {
  const char str[] = "-99999999999999999999";
  TEST_STRTOL(str, 10);
}
END_TEST

START_TEST(border_overflow) {
  const char str[] = "9223372036854775807";
  TEST_STRTOL(str, 10);
}
END_TEST

START_TEST(border_underflow) {
  const char str[] = "-9223372036854775808";
  TEST_STRTOL(str, 10);
}
END_TEST

START_TEST(invalid_input) {
  const char str[] = "abc123";
  TEST_STRTOL(str, 10);
}
END_TEST

START_TEST(empty_string) {
  const char str[] = "";
  TEST_STRTOL(str, 10);
}
END_TEST

START_TEST(null_endptr) {
  const char str[] = "12345";
  errno = 0;
  long expected_result = strtol(str, NULL, 10);
  int expected_errno = errno;
  errno = 0;
  long got_result = s21_strtol(str, NULL, 10);
  int got_errno = errno;

  ck_assert_int_eq(got_result, expected_result);
  ck_assert_int_eq(got_errno, expected_errno);
}
END_TEST

START_TEST(binary_base) {
  const char str[] = "101010";
  TEST_STRTOL(str, 2);
}
END_TEST

START_TEST(uppercase_hex) {
  const char str[] = "0XABCDEF";
  TEST_STRTOL(str, 16);
}
END_TEST

START_TEST(mixed_case_hex) {
  const char str[] = "0XaBcDeF";
  TEST_STRTOL(str, 16);
}
END_TEST

START_TEST(plus_sign) {
  const char str[] = "+123";
  TEST_STRTOL(str, 10);
}
END_TEST

START_TEST(trailing_whitespace) {
  const char str[] = "123   ";
  TEST_STRTOL(str, 10);
}
END_TEST

Suite* suite_s21_strtol(void) {
  Suite* suite = suite_create("s21_strtol");
  TCase* tcase_core = tcase_create("core of s21_strtol");

  tcase_add_test(tcase_core, basic_conversion);
  tcase_add_test(tcase_core, partial_conversion);
  tcase_add_test(tcase_core, leading_whitespace);
  tcase_add_test(tcase_core, negative_number);
  tcase_add_test(tcase_core, hexadecimal);
  tcase_add_test(tcase_core, hexadecimal_autodetect);
  tcase_add_test(tcase_core, octal);
  tcase_add_test(tcase_core, octal_autodetect);
  tcase_add_test(tcase_core, decimal_with_leading_zero);
  tcase_add_test(tcase_core, overflow);
  tcase_add_test(tcase_core, underflow);
  tcase_add_test(tcase_core, border_overflow);
  tcase_add_test(tcase_core, border_underflow);
  tcase_add_test(tcase_core, invalid_input);
  tcase_add_test(tcase_core, empty_string);
  tcase_add_test(tcase_core, null_endptr);
  tcase_add_test(tcase_core, binary_base);
  tcase_add_test(tcase_core, uppercase_hex);
  tcase_add_test(tcase_core, mixed_case_hex);
  tcase_add_test(tcase_core, plus_sign);
  tcase_add_test(tcase_core, trailing_whitespace);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
