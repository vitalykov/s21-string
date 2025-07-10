#include <errno.h>
#include <limits.h>
#include <stdlib.h>

#include "s21_strlib/s21_strlib.h"
#include "tests/test.h"

#define TEST_STRTOUL(input, base)                                           \
  {                                                                         \
    char* expected_endptr = NULL;                                           \
    char* got_endptr = NULL;                                                \
    unsigned long expected_result = strtoul(input, &expected_endptr, base); \
    unsigned long got_result = s21_strtoul(input, &got_endptr, base);       \
    ck_assert_uint_eq(got_result, expected_result);                         \
    ck_assert_ptr_eq(got_endptr, expected_endptr);                          \
  }

START_TEST(basic_decimal) {
  const char str[] = "12345";
  TEST_STRTOUL(str, 10);
}
END_TEST

START_TEST(basic_hex) {
  const char str[] = "1aF3";
  TEST_STRTOUL(str, 16);
}
END_TEST

START_TEST(basic_octal) {
  const char str[] = "755";
  TEST_STRTOUL(str, 8);
}
END_TEST

START_TEST(basic_binary) {
  const char str[] = "101010";
  TEST_STRTOUL(str, 2);
}
END_TEST

START_TEST(zero_value) {
  const char str[] = "0";
  TEST_STRTOUL(str, 10);
}
END_TEST

START_TEST(leading_whitespace) {
  const char str[] = "   \t\n+456";
  TEST_STRTOUL(str, 10);
}
END_TEST

START_TEST(trailing_whitespace) {
  const char str[] = "123   ";
  TEST_STRTOUL(str, 10);
}
END_TEST

START_TEST(plus_sign) {
  const char str[] = "+123";
  TEST_STRTOUL(str, 10);
}
END_TEST

START_TEST(partial_conversion) {
  const char str[] = "123abc";
  TEST_STRTOUL(str, 10);
}
END_TEST

START_TEST(empty_string) {
  const char str[] = "";
  TEST_STRTOUL(str, 10);
}
END_TEST

START_TEST(null_endptr) {
  const char str[] = "12345";
  errno = 0;
  unsigned long expected_result = strtoul(str, NULL, 10);
  int expected_errno = errno;
  errno = 0;
  unsigned long got_result = s21_strtoul(str, NULL, 10);
  int got_errno = errno;

  ck_assert_uint_eq(got_result, expected_result);
  ck_assert_int_eq(got_errno, expected_errno);
}
END_TEST

START_TEST(autodetect_hex) {
  const char str[] = "0x1aF3";
  TEST_STRTOUL(str, 0);
}
END_TEST

START_TEST(autodetect_octal) {
  const char str[] = "0755";
  TEST_STRTOUL(str, 0);
}
END_TEST

START_TEST(autodetect_decimal) {
  const char str[] = "123";
  TEST_STRTOUL(str, 0);
}
END_TEST

START_TEST(simple_negative) {
  const char str[] = "-123";
  TEST_STRTOUL(str, 10);
}
END_TEST

START_TEST(negative_zero) {
  const char str[] = "-0";
  TEST_STRTOUL(str, 10);
}
END_TEST

START_TEST(negative_hex) {
  const char str[] = "-0xABC";
  TEST_STRTOUL(str, 16);
}
END_TEST

START_TEST(negative_octal) {
  const char str[] = "-0777";
  TEST_STRTOUL(str, 8);
}
END_TEST

START_TEST(negative_with_whitespace) {
  const char str[] = "  \t\n-123";
  TEST_STRTOUL(str, 10);
}
END_TEST

START_TEST(double_negative) {
  const char str[] = "--123";
  TEST_STRTOUL(str, 10);
}
END_TEST

START_TEST(negative_with_plus) {
  const char str[] = "-+123";
  TEST_STRTOUL(str, 10);
}
END_TEST

START_TEST(max_unsigned) {
  const char str[] = "18446744073709551615";  // ULONG_MAX for 64-bit
  TEST_STRTOUL(str, 10);
}
END_TEST

START_TEST(overflow) {
  const char str[] = "18446744073709551616";  // ULONG_MAX + 1
  TEST_STRTOUL(str, 10);
}
END_TEST

START_TEST(negative_overflow) {
  const char str[] = "-18446744073709551616";  // Special case for wrap around
  TEST_STRTOUL(str, 10);
}
END_TEST

START_TEST(hex_overflow) {
  const char str[] = "0xFFFFFFFFFFFFFFFFF";  // Too large for unsigned long
  TEST_STRTOUL(str, 16);
}
END_TEST

START_TEST(uppercase_hex) {
  const char str[] = "0XABCDEF";
  TEST_STRTOUL(str, 16);
}
END_TEST

START_TEST(mixed_case_hex) {
  const char str[] = "0XaBcDeF";
  TEST_STRTOUL(str, 16);
}
END_TEST

Suite* suite_s21_strtoul(void) {
  Suite* suite = suite_create("s21_strtoul");
  TCase* tcase_core = tcase_create("core of s21_strtoul");

  tcase_add_test(tcase_core, basic_decimal);
  tcase_add_test(tcase_core, basic_hex);
  tcase_add_test(tcase_core, basic_octal);
  tcase_add_test(tcase_core, basic_binary);
  tcase_add_test(tcase_core, zero_value);
  tcase_add_test(tcase_core, leading_whitespace);
  tcase_add_test(tcase_core, trailing_whitespace);
  tcase_add_test(tcase_core, plus_sign);
  tcase_add_test(tcase_core, partial_conversion);
  tcase_add_test(tcase_core, empty_string);
  tcase_add_test(tcase_core, null_endptr);
  tcase_add_test(tcase_core, autodetect_hex);
  tcase_add_test(tcase_core, autodetect_octal);
  tcase_add_test(tcase_core, autodetect_decimal);
  tcase_add_test(tcase_core, simple_negative);
  tcase_add_test(tcase_core, negative_zero);
  tcase_add_test(tcase_core, negative_hex);
  tcase_add_test(tcase_core, negative_octal);
  tcase_add_test(tcase_core, negative_with_whitespace);
  tcase_add_test(tcase_core, double_negative);
  tcase_add_test(tcase_core, negative_with_plus);
  tcase_add_test(tcase_core, max_unsigned);
  tcase_add_test(tcase_core, overflow);
  tcase_add_test(tcase_core, negative_overflow);
  tcase_add_test(tcase_core, hex_overflow);
  tcase_add_test(tcase_core, uppercase_hex);
  tcase_add_test(tcase_core, mixed_case_hex);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
