#include <errno.h>
#include <limits.h>
#include <math.h>
#include <stdlib.h>

#include "s21_strlib/s21_strlib.h"
#include "tests/test.h"

#define TEST_STRTOLD(input)                                         \
  {                                                                 \
    char* expected_endptr = NULL;                                   \
    char* got_endptr = NULL;                                        \
    errno = 0;                                                      \
    long double expected_result = strtold(input, &expected_endptr); \
    int expected_errno = errno;                                     \
    errno = 0;                                                      \
    long double got_result = s21_strtold(input, &got_endptr);       \
    int got_errno = errno;                                          \
    if (isnan(expected_result)) {                                   \
      ck_assert(isnan(got_result));                                 \
    } else if (isinf(expected_result)) {                            \
      ck_assert(isinf(got_result));                                 \
      ck_assert(signbit(expected_result) == signbit(got_result));   \
    } else {                                                        \
      ck_assert_ldouble_eq_tol(got_result, expected_result, 1e-10); \
    }                                                               \
    ck_assert_ptr_eq(got_endptr, expected_endptr);                  \
    ck_assert_int_eq(got_errno, expected_errno);                    \
  }

START_TEST(basic_decimal) {
  const char str[] = "123.45";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(basic_scientific) {
  const char str[] = "1.23e4";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(basic_negative) {
  const char str[] = "-123.456";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(basic_positive) {
  const char str[] = "+123.456";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(zero_value) {
  const char str[] = "0.0";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(negative_zero) {
  const char str[] = "-0.0";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(leading_whitespace) {
  const char str[] = "   \t\n123.45";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(trailing_whitespace) {
  const char str[] = "123.45   ";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(partial_conversion) {
  const char str[] = "123.45abc";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(empty_string) {
  const char str[] = "";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(null_endptr) {
  const char str[] = "123.45";
  errno = 0;
  long double expected_result = strtold(str, NULL);
  int expected_errno = errno;
  errno = 0;
  long double got_result = s21_strtold(str, NULL);
  int got_errno = errno;

  if (isnan(expected_result)) {
    ck_assert(isnan(got_result));
  } else if (isinf(expected_result)) {
    ck_assert(isinf(got_result));
    ck_assert(signbit(expected_result) == signbit(got_result));
  } else {
    ck_assert_ldouble_eq_tol(got_result, expected_result, 1e-10);
  }
  ck_assert_int_eq(got_errno, expected_errno);
}
END_TEST

START_TEST(hex_float) {
  const char str[] = "0x1.2p3";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(hex_float_negative) {
  const char str[] = "-0x1.2p3";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(hex_float_scientific) {
  const char str[] = "0x1.2P-3";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(infinity) {
  const char str[] = "inf";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(negative_infinity) {
  const char str[] = "-inf";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(nan_value) {
  const char str[] = "nan";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(overflow) {
  const char str[] = "1e10000";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(underflow) {
  const char str[] = "-1e10000";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(large_precision) {
  const char str[] = "1.234567890123456789012345678901234567890";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(no_integer_part) {
  const char str[] = ".123";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(no_fractional_part) {
  const char str[] = "123.";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(multiple_signs) {
  const char str[] = "+-123";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(multiple_decimal_points) {
  const char str[] = "123.45.67";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(invalid_exponent) {
  const char str[] = "1.2e3.4";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(invalid_hex_float) {
  const char str[] = "0xa.2.3p4";
  TEST_STRTOLD(str);
}
END_TEST

START_TEST(locale_specific) {
  const char str[] = "123,456";
  TEST_STRTOLD(str);
}
END_TEST

Suite* suite_s21_strtold(void) {
  Suite* suite = suite_create("s21_strtold");
  TCase* tcase_core = tcase_create("core of s21_strtold");

  tcase_add_test(tcase_core, basic_decimal);
  tcase_add_test(tcase_core, basic_scientific);
  tcase_add_test(tcase_core, basic_negative);
  tcase_add_test(tcase_core, basic_positive);
  tcase_add_test(tcase_core, zero_value);
  tcase_add_test(tcase_core, negative_zero);
  tcase_add_test(tcase_core, leading_whitespace);
  tcase_add_test(tcase_core, trailing_whitespace);
  tcase_add_test(tcase_core, partial_conversion);
  tcase_add_test(tcase_core, empty_string);
  tcase_add_test(tcase_core, null_endptr);
  tcase_add_test(tcase_core, hex_float);
  tcase_add_test(tcase_core, hex_float_negative);
  tcase_add_test(tcase_core, hex_float_scientific);
  tcase_add_test(tcase_core, infinity);
  tcase_add_test(tcase_core, negative_infinity);
  tcase_add_test(tcase_core, nan_value);
  tcase_add_test(tcase_core, overflow);
  tcase_add_test(tcase_core, underflow);
  tcase_add_test(tcase_core, large_precision);
  tcase_add_test(tcase_core, no_integer_part);
  tcase_add_test(tcase_core, no_fractional_part);
  tcase_add_test(tcase_core, multiple_signs);
  tcase_add_test(tcase_core, multiple_decimal_points);
  tcase_add_test(tcase_core, invalid_exponent);
  tcase_add_test(tcase_core, invalid_hex_float);
  tcase_add_test(tcase_core, locale_specific);

  suite_add_tcase(suite, tcase_core);

  return suite;
}
