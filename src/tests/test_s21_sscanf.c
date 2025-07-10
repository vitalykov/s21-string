#include <math.h>
#include <stdio.h>
#include <wchar.h>

#include "s21_string.h"
#include "tests/test.h"

#define RUN_TEST(var_type, str_val, str_fmt, assert_func)    \
  var_type got_var;                                          \
  var_type expected_var;                                     \
  ck_assert_int_eq(s21_sscanf(str_val, str_fmt, &got_var),   \
                   sscanf(str_val, str_fmt, &expected_var)); \
  assert_func(got_var, expected_var);

START_TEST(f_null_no_width) {
  RUN_TEST(float, "0.0", "%f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_null_neg_no_width) {
  RUN_TEST(float, "-0.0", "%f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_fraction_short_no_width) {
  RUN_TEST(float, "0.1234567", "%f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_fraction_medium_no_width) {
  RUN_TEST(float, "0.123456789101112", "%f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_fraction_long_no_width) {
  RUN_TEST(float, "0.12356789101112131415", "%f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_general_short_no_width) {
  RUN_TEST(float, "1234.567", "%f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_general_medium_no_width) {
  RUN_TEST(float, "1234.56789101112", "%f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_general_long_no_width) {
  RUN_TEST(float, "12345678.9101112131415", "%f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_infinity_no_width) {
  RUN_TEST(float, "INFINITY", "%f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_infinity_neg_no_width) {
  RUN_TEST(float, "-INFINITY", "%f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_null_small_width) {
  RUN_TEST(float, "0.0", "%10f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_null_neg_small_width) {
  RUN_TEST(float, "-0.0", "%10f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_fraction_short_small_width) {
  RUN_TEST(float, "0.1234567", "%10f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_fraction_medium_small_width) {
  RUN_TEST(float, "0.123456789101112", "%10f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_fraction_long_small_width) {
  RUN_TEST(float, "0.12356789101112131415", "%10f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_general_short_small_width) {
  RUN_TEST(float, "1234.567", "%10f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_general_medium_small_width) {
  RUN_TEST(float, "1234.56789101112", "%10f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_general_long_small_width) {
  RUN_TEST(float, "12345678.9101112131415", "%10f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_infinity_small_width) {
  RUN_TEST(float, "INFINITY", "%10f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_infinity_neg_small_width) {
  RUN_TEST(float, "-INFINITY", "%10f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_null_medium_width) {
  RUN_TEST(float, "0.0", "%25f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_null_neg_medium_width) {
  RUN_TEST(float, "-0.0", "%25f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_fraction_short_medium_width) {
  RUN_TEST(float, "0.1234567", "%25f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_fraction_medium_medium_width) {
  RUN_TEST(float, "0.123456789101112", "%25f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_fraction_long_medium_width) {
  RUN_TEST(float, "0.12356789101112131415", "%25f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_general_short_medium_width) {
  RUN_TEST(float, "1234.567", "%25f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_general_medium_medium_width) {
  RUN_TEST(float, "1234.56789101112", "%25f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_general_long_medium_width) {
  RUN_TEST(float, "12345678.9101112131415", "%25f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_infinity_medium_width) {
  RUN_TEST(float, "INFINITY", "%25f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_infinity_neg_medium_width) {
  RUN_TEST(float, "-INFINITY", "%25f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_null_big_width) {
  RUN_TEST(float, "0.0", "%70f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_null_neg_big_width) {
  RUN_TEST(float, "-0.0", "%70f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_fraction_short_big_width) {
  RUN_TEST(float, "0.1234567", "%70f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_fraction_medium_big_width) {
  RUN_TEST(float, "0.123456789101112", "%70f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_fraction_long_big_width) {
  RUN_TEST(float, "0.12356789101112131415", "%70f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_general_short_big_width) {
  RUN_TEST(float, "1234.567", "%70f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_general_medium_big_width) {
  RUN_TEST(float, "1234.56789101112", "%70f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_general_long_big_width) {
  RUN_TEST(float, "12345678.9101112131415", "%70f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_infinity_big_width) {
  RUN_TEST(float, "INFINITY", "%70f", ck_assert_float_eq);
}
END_TEST
START_TEST(f_infinity_neg_big_width) {
  RUN_TEST(float, "-INFINITY", "%70f", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_null_no_width) {
  RUN_TEST(double, "0.0", "%lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_null_neg_no_width) {
  RUN_TEST(double, "-0.0", "%lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_fraction_short_no_width) {
  RUN_TEST(double, "0.1234567", "%lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_fraction_medium_no_width) {
  RUN_TEST(double, "0.123456789101112", "%lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_fraction_long_no_width) {
  RUN_TEST(double, "0.12356789101112131415", "%lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_general_short_no_width) {
  RUN_TEST(double, "1234.567", "%lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_general_medium_no_width) {
  RUN_TEST(double, "1234.56789101112", "%lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_general_long_no_width) {
  RUN_TEST(double, "12345678.9101112131415", "%lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_infinity_no_width) {
  RUN_TEST(double, "INFINITY", "%lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_infinity_neg_no_width) {
  RUN_TEST(double, "-INFINITY", "%lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_null_small_width) {
  RUN_TEST(double, "0.0", "%10lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_null_neg_small_width) {
  RUN_TEST(double, "-0.0", "%10lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_fraction_short_small_width) {
  RUN_TEST(double, "0.1234567", "%10lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_fraction_medium_small_width) {
  RUN_TEST(double, "0.123456789101112", "%10lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_fraction_long_small_width) {
  RUN_TEST(double, "0.12356789101112131415", "%10lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_general_short_small_width) {
  RUN_TEST(double, "1234.567", "%10lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_general_medium_small_width) {
  RUN_TEST(double, "1234.56789101112", "%10lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_general_long_small_width) {
  RUN_TEST(double, "12345678.9101112131415", "%10lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_infinity_small_width) {
  RUN_TEST(double, "INFINITY", "%10lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_infinity_neg_small_width) {
  RUN_TEST(double, "-INFINITY", "%10lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_null_medium_width) {
  RUN_TEST(double, "0.0", "%25lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_null_neg_medium_width) {
  RUN_TEST(double, "-0.0", "%25lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_fraction_short_medium_width) {
  RUN_TEST(double, "0.1234567", "%25lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_fraction_medium_medium_width) {
  RUN_TEST(double, "0.123456789101112", "%25lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_fraction_long_medium_width) {
  RUN_TEST(double, "0.12356789101112131415", "%25lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_general_short_medium_width) {
  RUN_TEST(double, "1234.567", "%25lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_general_medium_medium_width) {
  RUN_TEST(double, "1234.56789101112", "%25lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_general_long_medium_width) {
  RUN_TEST(double, "12345678.9101112131415", "%25lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_infinity_medium_width) {
  RUN_TEST(double, "INFINITY", "%25lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_infinity_neg_medium_width) {
  RUN_TEST(double, "-INFINITY", "%25lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_null_big_width) {
  RUN_TEST(double, "0.0", "%70lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_null_neg_big_width) {
  RUN_TEST(double, "-0.0", "%70lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_fraction_short_big_width) {
  RUN_TEST(double, "0.1234567", "%70lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_fraction_medium_big_width) {
  RUN_TEST(double, "0.123456789101112", "%70lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_fraction_long_big_width) {
  RUN_TEST(double, "0.12356789101112131415", "%70lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_general_short_big_width) {
  RUN_TEST(double, "1234.567", "%70lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_general_medium_big_width) {
  RUN_TEST(double, "1234.56789101112", "%70lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_general_long_big_width) {
  RUN_TEST(double, "12345678.9101112131415", "%70lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_infinity_big_width) {
  RUN_TEST(double, "INFINITY", "%70lf", ck_assert_float_eq);
}
END_TEST
START_TEST(lf_infinity_neg_big_width) {
  RUN_TEST(double, "-INFINITY", "%70lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_null_no_width) {
  RUN_TEST(long double, "0.0", "%Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_null_neg_no_width) {
  RUN_TEST(long double, "-0.0", "%Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_fraction_short_no_width) {
  RUN_TEST(long double, "0.1234567", "%Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_fraction_medium_no_width) {
  RUN_TEST(long double, "0.123456789101112", "%Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_fraction_long_no_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_general_short_no_width) {
  RUN_TEST(long double, "1234.567", "%Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_general_medium_no_width) {
  RUN_TEST(long double, "1234.56789101112", "%Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_general_long_no_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_infinity_no_width) {
  RUN_TEST(long double, "INFINITY", "%Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_infinity_neg_no_width) {
  RUN_TEST(long double, "-INFINITY", "%Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_null_small_width) {
  RUN_TEST(long double, "0.0", "%10Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_null_neg_small_width) {
  RUN_TEST(long double, "-0.0", "%10Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_fraction_short_small_width) {
  RUN_TEST(long double, "0.1234567", "%10Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_fraction_medium_small_width) {
  RUN_TEST(long double, "0.123456789101112", "%10Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_fraction_long_small_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%10Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_general_short_small_width) {
  RUN_TEST(long double, "1234.567", "%10Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_general_medium_small_width) {
  RUN_TEST(long double, "1234.56789101112", "%10Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_general_long_small_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%10Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_infinity_small_width) {
  RUN_TEST(long double, "INFINITY", "%10Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_infinity_neg_small_width) {
  RUN_TEST(long double, "-INFINITY", "%10Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_null_medium_width) {
  RUN_TEST(long double, "0.0", "%25Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_null_neg_medium_width) {
  RUN_TEST(long double, "-0.0", "%25Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_fraction_short_medium_width) {
  RUN_TEST(long double, "0.1234567", "%25Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_fraction_medium_medium_width) {
  RUN_TEST(long double, "0.123456789101112", "%25Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_fraction_long_medium_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%25Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_general_short_medium_width) {
  RUN_TEST(long double, "1234.567", "%25Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_general_medium_medium_width) {
  RUN_TEST(long double, "1234.56789101112", "%25Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_general_long_medium_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%25Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_infinity_medium_width) {
  RUN_TEST(long double, "INFINITY", "%25Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_infinity_neg_medium_width) {
  RUN_TEST(long double, "-INFINITY", "%25Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_null_big_width) {
  RUN_TEST(long double, "0.0", "%70Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_null_neg_big_width) {
  RUN_TEST(long double, "-0.0", "%70Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_fraction_short_big_width) {
  RUN_TEST(long double, "0.1234567", "%70Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_fraction_medium_big_width) {
  RUN_TEST(long double, "0.123456789101112", "%70Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_fraction_long_big_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%70Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_general_short_big_width) {
  RUN_TEST(long double, "1234.567", "%70Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_general_medium_big_width) {
  RUN_TEST(long double, "1234.56789101112", "%70Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_general_long_big_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%70Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_infinity_big_width) {
  RUN_TEST(long double, "INFINITY", "%70Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(Lf_infinity_neg_big_width) {
  RUN_TEST(long double, "-INFINITY", "%70Lf", ck_assert_float_eq);
}
END_TEST
START_TEST(e_null_no_width) {
  RUN_TEST(float, "0.0", "%e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_null_neg_no_width) {
  RUN_TEST(float, "-0.0", "%e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_fraction_short_no_width) {
  RUN_TEST(float, "0.1234567", "%e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_fraction_medium_no_width) {
  RUN_TEST(float, "0.123456789101112", "%e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_fraction_long_no_width) {
  RUN_TEST(float, "0.12356789101112131415", "%e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_general_short_no_width) {
  RUN_TEST(float, "1234.567", "%e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_general_medium_no_width) {
  RUN_TEST(float, "1234.56789101112", "%e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_general_long_no_width) {
  RUN_TEST(float, "12345678.9101112131415", "%e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_infinity_no_width) {
  RUN_TEST(float, "INFINITY", "%e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_infinity_neg_no_width) {
  RUN_TEST(float, "-INFINITY", "%e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_null_small_width) {
  RUN_TEST(float, "0.0", "%10e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_null_neg_small_width) {
  RUN_TEST(float, "-0.0", "%10e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_fraction_short_small_width) {
  RUN_TEST(float, "0.1234567", "%10e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_fraction_medium_small_width) {
  RUN_TEST(float, "0.123456789101112", "%10e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_fraction_long_small_width) {
  RUN_TEST(float, "0.12356789101112131415", "%10e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_general_short_small_width) {
  RUN_TEST(float, "1234.567", "%10e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_general_medium_small_width) {
  RUN_TEST(float, "1234.56789101112", "%10e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_general_long_small_width) {
  RUN_TEST(float, "12345678.9101112131415", "%10e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_infinity_small_width) {
  RUN_TEST(float, "INFINITY", "%10e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_infinity_neg_small_width) {
  RUN_TEST(float, "-INFINITY", "%10e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_null_medium_width) {
  RUN_TEST(float, "0.0", "%25e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_null_neg_medium_width) {
  RUN_TEST(float, "-0.0", "%25e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_fraction_short_medium_width) {
  RUN_TEST(float, "0.1234567", "%25e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_fraction_medium_medium_width) {
  RUN_TEST(float, "0.123456789101112", "%25e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_fraction_long_medium_width) {
  RUN_TEST(float, "0.12356789101112131415", "%25e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_general_short_medium_width) {
  RUN_TEST(float, "1234.567", "%25e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_general_medium_medium_width) {
  RUN_TEST(float, "1234.56789101112", "%25e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_general_long_medium_width) {
  RUN_TEST(float, "12345678.9101112131415", "%25e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_infinity_medium_width) {
  RUN_TEST(float, "INFINITY", "%25e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_infinity_neg_medium_width) {
  RUN_TEST(float, "-INFINITY", "%25e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_null_big_width) {
  RUN_TEST(float, "0.0", "%70e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_null_neg_big_width) {
  RUN_TEST(float, "-0.0", "%70e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_fraction_short_big_width) {
  RUN_TEST(float, "0.1234567", "%70e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_fraction_medium_big_width) {
  RUN_TEST(float, "0.123456789101112", "%70e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_fraction_long_big_width) {
  RUN_TEST(float, "0.12356789101112131415", "%70e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_general_short_big_width) {
  RUN_TEST(float, "1234.567", "%70e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_general_medium_big_width) {
  RUN_TEST(float, "1234.56789101112", "%70e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_general_long_big_width) {
  RUN_TEST(float, "12345678.9101112131415", "%70e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_infinity_big_width) {
  RUN_TEST(float, "INFINITY", "%70e", ck_assert_float_eq);
}
END_TEST
START_TEST(e_infinity_neg_big_width) {
  RUN_TEST(float, "-INFINITY", "%70e", ck_assert_float_eq);
}
END_TEST
START_TEST(E_null_no_width) {
  RUN_TEST(float, "0.0", "%E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_null_neg_no_width) {
  RUN_TEST(float, "-0.0", "%E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_fraction_short_no_width) {
  RUN_TEST(float, "0.1234567", "%E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_fraction_medium_no_width) {
  RUN_TEST(float, "0.123456789101112", "%E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_fraction_long_no_width) {
  RUN_TEST(float, "0.12356789101112131415", "%E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_general_short_no_width) {
  RUN_TEST(float, "1234.567", "%E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_general_medium_no_width) {
  RUN_TEST(float, "1234.56789101112", "%E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_general_long_no_width) {
  RUN_TEST(float, "12345678.9101112131415", "%E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_infinity_no_width) {
  RUN_TEST(float, "INFINITY", "%E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_infinity_neg_no_width) {
  RUN_TEST(float, "-INFINITY", "%E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_null_small_width) {
  RUN_TEST(float, "0.0", "%10E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_null_neg_small_width) {
  RUN_TEST(float, "-0.0", "%10E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_fraction_short_small_width) {
  RUN_TEST(float, "0.1234567", "%10E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_fraction_medium_small_width) {
  RUN_TEST(float, "0.123456789101112", "%10E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_fraction_long_small_width) {
  RUN_TEST(float, "0.12356789101112131415", "%10E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_general_short_small_width) {
  RUN_TEST(float, "1234.567", "%10E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_general_medium_small_width) {
  RUN_TEST(float, "1234.56789101112", "%10E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_general_long_small_width) {
  RUN_TEST(float, "12345678.9101112131415", "%10E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_infinity_small_width) {
  RUN_TEST(float, "INFINITY", "%10E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_infinity_neg_small_width) {
  RUN_TEST(float, "-INFINITY", "%10E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_null_medium_width) {
  RUN_TEST(float, "0.0", "%25E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_null_neg_medium_width) {
  RUN_TEST(float, "-0.0", "%25E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_fraction_short_medium_width) {
  RUN_TEST(float, "0.1234567", "%25E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_fraction_medium_medium_width) {
  RUN_TEST(float, "0.123456789101112", "%25E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_fraction_long_medium_width) {
  RUN_TEST(float, "0.12356789101112131415", "%25E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_general_short_medium_width) {
  RUN_TEST(float, "1234.567", "%25E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_general_medium_medium_width) {
  RUN_TEST(float, "1234.56789101112", "%25E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_general_long_medium_width) {
  RUN_TEST(float, "12345678.9101112131415", "%25E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_infinity_medium_width) {
  RUN_TEST(float, "INFINITY", "%25E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_infinity_neg_medium_width) {
  RUN_TEST(float, "-INFINITY", "%25E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_null_big_width) {
  RUN_TEST(float, "0.0", "%70E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_null_neg_big_width) {
  RUN_TEST(float, "-0.0", "%70E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_fraction_short_big_width) {
  RUN_TEST(float, "0.1234567", "%70E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_fraction_medium_big_width) {
  RUN_TEST(float, "0.123456789101112", "%70E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_fraction_long_big_width) {
  RUN_TEST(float, "0.12356789101112131415", "%70E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_general_short_big_width) {
  RUN_TEST(float, "1234.567", "%70E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_general_medium_big_width) {
  RUN_TEST(float, "1234.56789101112", "%70E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_general_long_big_width) {
  RUN_TEST(float, "12345678.9101112131415", "%70E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_infinity_big_width) {
  RUN_TEST(float, "INFINITY", "%70E", ck_assert_float_eq);
}
END_TEST
START_TEST(E_infinity_neg_big_width) {
  RUN_TEST(float, "-INFINITY", "%70E", ck_assert_float_eq);
}
END_TEST
START_TEST(le_null_no_width) {
  RUN_TEST(double, "0.0", "%le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_null_neg_no_width) {
  RUN_TEST(double, "-0.0", "%le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_fraction_short_no_width) {
  RUN_TEST(double, "0.1234567", "%le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_fraction_medium_no_width) {
  RUN_TEST(double, "0.123456789101112", "%le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_fraction_long_no_width) {
  RUN_TEST(double, "0.12356789101112131415", "%le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_general_short_no_width) {
  RUN_TEST(double, "1234.567", "%le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_general_medium_no_width) {
  RUN_TEST(double, "1234.56789101112", "%le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_general_long_no_width) {
  RUN_TEST(double, "12345678.9101112131415", "%le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_infinity_no_width) {
  RUN_TEST(double, "INFINITY", "%le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_infinity_neg_no_width) {
  RUN_TEST(double, "-INFINITY", "%le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_null_small_width) {
  RUN_TEST(double, "0.0", "%10le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_null_neg_small_width) {
  RUN_TEST(double, "-0.0", "%10le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_fraction_short_small_width) {
  RUN_TEST(double, "0.1234567", "%10le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_fraction_medium_small_width) {
  RUN_TEST(double, "0.123456789101112", "%10le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_fraction_long_small_width) {
  RUN_TEST(double, "0.12356789101112131415", "%10le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_general_short_small_width) {
  RUN_TEST(double, "1234.567", "%10le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_general_medium_small_width) {
  RUN_TEST(double, "1234.56789101112", "%10le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_general_long_small_width) {
  RUN_TEST(double, "12345678.9101112131415", "%10le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_infinity_small_width) {
  RUN_TEST(double, "INFINITY", "%10le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_infinity_neg_small_width) {
  RUN_TEST(double, "-INFINITY", "%10le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_null_medium_width) {
  RUN_TEST(double, "0.0", "%25le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_null_neg_medium_width) {
  RUN_TEST(double, "-0.0", "%25le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_fraction_short_medium_width) {
  RUN_TEST(double, "0.1234567", "%25le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_fraction_medium_medium_width) {
  RUN_TEST(double, "0.123456789101112", "%25le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_fraction_long_medium_width) {
  RUN_TEST(double, "0.12356789101112131415", "%25le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_general_short_medium_width) {
  RUN_TEST(double, "1234.567", "%25le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_general_medium_medium_width) {
  RUN_TEST(double, "1234.56789101112", "%25le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_general_long_medium_width) {
  RUN_TEST(double, "12345678.9101112131415", "%25le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_infinity_medium_width) {
  RUN_TEST(double, "INFINITY", "%25le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_infinity_neg_medium_width) {
  RUN_TEST(double, "-INFINITY", "%25le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_null_big_width) {
  RUN_TEST(double, "0.0", "%70le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_null_neg_big_width) {
  RUN_TEST(double, "-0.0", "%70le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_fraction_short_big_width) {
  RUN_TEST(double, "0.1234567", "%70le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_fraction_medium_big_width) {
  RUN_TEST(double, "0.123456789101112", "%70le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_fraction_long_big_width) {
  RUN_TEST(double, "0.12356789101112131415", "%70le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_general_short_big_width) {
  RUN_TEST(double, "1234.567", "%70le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_general_medium_big_width) {
  RUN_TEST(double, "1234.56789101112", "%70le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_general_long_big_width) {
  RUN_TEST(double, "12345678.9101112131415", "%70le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_infinity_big_width) {
  RUN_TEST(double, "INFINITY", "%70le", ck_assert_float_eq);
}
END_TEST
START_TEST(le_infinity_neg_big_width) {
  RUN_TEST(double, "-INFINITY", "%70le", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_null_no_width) {
  RUN_TEST(double, "0.0", "%lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_null_neg_no_width) {
  RUN_TEST(double, "-0.0", "%lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_fraction_short_no_width) {
  RUN_TEST(double, "0.1234567", "%lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_fraction_medium_no_width) {
  RUN_TEST(double, "0.123456789101112", "%lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_fraction_long_no_width) {
  RUN_TEST(double, "0.12356789101112131415", "%lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_general_short_no_width) {
  RUN_TEST(double, "1234.567", "%lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_general_medium_no_width) {
  RUN_TEST(double, "1234.56789101112", "%lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_general_long_no_width) {
  RUN_TEST(double, "12345678.9101112131415", "%lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_infinity_no_width) {
  RUN_TEST(double, "INFINITY", "%lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_infinity_neg_no_width) {
  RUN_TEST(double, "-INFINITY", "%lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_null_small_width) {
  RUN_TEST(double, "0.0", "%10lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_null_neg_small_width) {
  RUN_TEST(double, "-0.0", "%10lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_fraction_short_small_width) {
  RUN_TEST(double, "0.1234567", "%10lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_fraction_medium_small_width) {
  RUN_TEST(double, "0.123456789101112", "%10lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_fraction_long_small_width) {
  RUN_TEST(double, "0.12356789101112131415", "%10lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_general_short_small_width) {
  RUN_TEST(double, "1234.567", "%10lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_general_medium_small_width) {
  RUN_TEST(double, "1234.56789101112", "%10lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_general_long_small_width) {
  RUN_TEST(double, "12345678.9101112131415", "%10lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_infinity_small_width) {
  RUN_TEST(double, "INFINITY", "%10lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_infinity_neg_small_width) {
  RUN_TEST(double, "-INFINITY", "%10lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_null_medium_width) {
  RUN_TEST(double, "0.0", "%25lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_null_neg_medium_width) {
  RUN_TEST(double, "-0.0", "%25lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_fraction_short_medium_width) {
  RUN_TEST(double, "0.1234567", "%25lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_fraction_medium_medium_width) {
  RUN_TEST(double, "0.123456789101112", "%25lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_fraction_long_medium_width) {
  RUN_TEST(double, "0.12356789101112131415", "%25lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_general_short_medium_width) {
  RUN_TEST(double, "1234.567", "%25lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_general_medium_medium_width) {
  RUN_TEST(double, "1234.56789101112", "%25lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_general_long_medium_width) {
  RUN_TEST(double, "12345678.9101112131415", "%25lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_infinity_medium_width) {
  RUN_TEST(double, "INFINITY", "%25lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_infinity_neg_medium_width) {
  RUN_TEST(double, "-INFINITY", "%25lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_null_big_width) {
  RUN_TEST(double, "0.0", "%70lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_null_neg_big_width) {
  RUN_TEST(double, "-0.0", "%70lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_fraction_short_big_width) {
  RUN_TEST(double, "0.1234567", "%70lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_fraction_medium_big_width) {
  RUN_TEST(double, "0.123456789101112", "%70lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_fraction_long_big_width) {
  RUN_TEST(double, "0.12356789101112131415", "%70lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_general_short_big_width) {
  RUN_TEST(double, "1234.567", "%70lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_general_medium_big_width) {
  RUN_TEST(double, "1234.56789101112", "%70lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_general_long_big_width) {
  RUN_TEST(double, "12345678.9101112131415", "%70lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_infinity_big_width) {
  RUN_TEST(double, "INFINITY", "%70lE", ck_assert_float_eq);
}
END_TEST
START_TEST(lE_infinity_neg_big_width) {
  RUN_TEST(double, "-INFINITY", "%70lE", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_null_no_width) {
  RUN_TEST(long double, "0.0", "%Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_null_neg_no_width) {
  RUN_TEST(long double, "-0.0", "%Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_fraction_short_no_width) {
  RUN_TEST(long double, "0.1234567", "%Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_fraction_medium_no_width) {
  RUN_TEST(long double, "0.123456789101112", "%Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_fraction_long_no_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_general_short_no_width) {
  RUN_TEST(long double, "1234.567", "%Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_general_medium_no_width) {
  RUN_TEST(long double, "1234.56789101112", "%Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_general_long_no_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_infinity_no_width) {
  RUN_TEST(long double, "INFINITY", "%Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_infinity_neg_no_width) {
  RUN_TEST(long double, "-INFINITY", "%Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_null_small_width) {
  RUN_TEST(long double, "0.0", "%10Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_null_neg_small_width) {
  RUN_TEST(long double, "-0.0", "%10Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_fraction_short_small_width) {
  RUN_TEST(long double, "0.1234567", "%10Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_fraction_medium_small_width) {
  RUN_TEST(long double, "0.123456789101112", "%10Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_fraction_long_small_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%10Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_general_short_small_width) {
  RUN_TEST(long double, "1234.567", "%10Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_general_medium_small_width) {
  RUN_TEST(long double, "1234.56789101112", "%10Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_general_long_small_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%10Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_infinity_small_width) {
  RUN_TEST(long double, "INFINITY", "%10Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_infinity_neg_small_width) {
  RUN_TEST(long double, "-INFINITY", "%10Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_null_medium_width) {
  RUN_TEST(long double, "0.0", "%25Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_null_neg_medium_width) {
  RUN_TEST(long double, "-0.0", "%25Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_fraction_short_medium_width) {
  RUN_TEST(long double, "0.1234567", "%25Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_fraction_medium_medium_width) {
  RUN_TEST(long double, "0.123456789101112", "%25Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_fraction_long_medium_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%25Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_general_short_medium_width) {
  RUN_TEST(long double, "1234.567", "%25Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_general_medium_medium_width) {
  RUN_TEST(long double, "1234.56789101112", "%25Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_general_long_medium_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%25Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_infinity_medium_width) {
  RUN_TEST(long double, "INFINITY", "%25Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_infinity_neg_medium_width) {
  RUN_TEST(long double, "-INFINITY", "%25Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_null_big_width) {
  RUN_TEST(long double, "0.0", "%70Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_null_neg_big_width) {
  RUN_TEST(long double, "-0.0", "%70Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_fraction_short_big_width) {
  RUN_TEST(long double, "0.1234567", "%70Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_fraction_medium_big_width) {
  RUN_TEST(long double, "0.123456789101112", "%70Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_fraction_long_big_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%70Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_general_short_big_width) {
  RUN_TEST(long double, "1234.567", "%70Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_general_medium_big_width) {
  RUN_TEST(long double, "1234.56789101112", "%70Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_general_long_big_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%70Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_infinity_big_width) {
  RUN_TEST(long double, "INFINITY", "%70Le", ck_assert_float_eq);
}
END_TEST
START_TEST(Le_infinity_neg_big_width) {
  RUN_TEST(long double, "-INFINITY", "%70Le", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_null_no_width) {
  RUN_TEST(long double, "0.0", "%LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_null_neg_no_width) {
  RUN_TEST(long double, "-0.0", "%LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_fraction_short_no_width) {
  RUN_TEST(long double, "0.1234567", "%LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_fraction_medium_no_width) {
  RUN_TEST(long double, "0.123456789101112", "%LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_fraction_long_no_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_general_short_no_width) {
  RUN_TEST(long double, "1234.567", "%LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_general_medium_no_width) {
  RUN_TEST(long double, "1234.56789101112", "%LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_general_long_no_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_infinity_no_width) {
  RUN_TEST(long double, "INFINITY", "%LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_infinity_neg_no_width) {
  RUN_TEST(long double, "-INFINITY", "%LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_null_small_width) {
  RUN_TEST(long double, "0.0", "%10LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_null_neg_small_width) {
  RUN_TEST(long double, "-0.0", "%10LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_fraction_short_small_width) {
  RUN_TEST(long double, "0.1234567", "%10LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_fraction_medium_small_width) {
  RUN_TEST(long double, "0.123456789101112", "%10LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_fraction_long_small_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%10LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_general_short_small_width) {
  RUN_TEST(long double, "1234.567", "%10LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_general_medium_small_width) {
  RUN_TEST(long double, "1234.56789101112", "%10LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_general_long_small_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%10LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_infinity_small_width) {
  RUN_TEST(long double, "INFINITY", "%10LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_infinity_neg_small_width) {
  RUN_TEST(long double, "-INFINITY", "%10LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_null_medium_width) {
  RUN_TEST(long double, "0.0", "%25LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_null_neg_medium_width) {
  RUN_TEST(long double, "-0.0", "%25LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_fraction_short_medium_width) {
  RUN_TEST(long double, "0.1234567", "%25LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_fraction_medium_medium_width) {
  RUN_TEST(long double, "0.123456789101112", "%25LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_fraction_long_medium_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%25LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_general_short_medium_width) {
  RUN_TEST(long double, "1234.567", "%25LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_general_medium_medium_width) {
  RUN_TEST(long double, "1234.56789101112", "%25LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_general_long_medium_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%25LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_infinity_medium_width) {
  RUN_TEST(long double, "INFINITY", "%25LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_infinity_neg_medium_width) {
  RUN_TEST(long double, "-INFINITY", "%25LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_null_big_width) {
  RUN_TEST(long double, "0.0", "%70LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_null_neg_big_width) {
  RUN_TEST(long double, "-0.0", "%70LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_fraction_short_big_width) {
  RUN_TEST(long double, "0.1234567", "%70LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_fraction_medium_big_width) {
  RUN_TEST(long double, "0.123456789101112", "%70LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_fraction_long_big_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%70LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_general_short_big_width) {
  RUN_TEST(long double, "1234.567", "%70LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_general_medium_big_width) {
  RUN_TEST(long double, "1234.56789101112", "%70LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_general_long_big_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%70LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_infinity_big_width) {
  RUN_TEST(long double, "INFINITY", "%70LE", ck_assert_float_eq);
}
END_TEST
START_TEST(LE_infinity_neg_big_width) {
  RUN_TEST(long double, "-INFINITY", "%70LE", ck_assert_float_eq);
}
END_TEST
START_TEST(g_null_no_width) {
  RUN_TEST(float, "0.0", "%g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_null_neg_no_width) {
  RUN_TEST(float, "-0.0", "%g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_fraction_short_no_width) {
  RUN_TEST(float, "0.1234567", "%g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_fraction_medium_no_width) {
  RUN_TEST(float, "0.123456789101112", "%g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_fraction_long_no_width) {
  RUN_TEST(float, "0.12356789101112131415", "%g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_general_short_no_width) {
  RUN_TEST(float, "1234.567", "%g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_general_medium_no_width) {
  RUN_TEST(float, "1234.56789101112", "%g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_general_long_no_width) {
  RUN_TEST(float, "12345678.9101112131415", "%g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_infinity_no_width) {
  RUN_TEST(float, "INFINITY", "%g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_infinity_neg_no_width) {
  RUN_TEST(float, "-INFINITY", "%g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_null_small_width) {
  RUN_TEST(float, "0.0", "%10g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_null_neg_small_width) {
  RUN_TEST(float, "-0.0", "%10g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_fraction_short_small_width) {
  RUN_TEST(float, "0.1234567", "%10g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_fraction_medium_small_width) {
  RUN_TEST(float, "0.123456789101112", "%10g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_fraction_long_small_width) {
  RUN_TEST(float, "0.12356789101112131415", "%10g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_general_short_small_width) {
  RUN_TEST(float, "1234.567", "%10g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_general_medium_small_width) {
  RUN_TEST(float, "1234.56789101112", "%10g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_general_long_small_width) {
  RUN_TEST(float, "12345678.9101112131415", "%10g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_infinity_small_width) {
  RUN_TEST(float, "INFINITY", "%10g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_infinity_neg_small_width) {
  RUN_TEST(float, "-INFINITY", "%10g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_null_medium_width) {
  RUN_TEST(float, "0.0", "%25g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_null_neg_medium_width) {
  RUN_TEST(float, "-0.0", "%25g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_fraction_short_medium_width) {
  RUN_TEST(float, "0.1234567", "%25g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_fraction_medium_medium_width) {
  RUN_TEST(float, "0.123456789101112", "%25g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_fraction_long_medium_width) {
  RUN_TEST(float, "0.12356789101112131415", "%25g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_general_short_medium_width) {
  RUN_TEST(float, "1234.567", "%25g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_general_medium_medium_width) {
  RUN_TEST(float, "1234.56789101112", "%25g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_general_long_medium_width) {
  RUN_TEST(float, "12345678.9101112131415", "%25g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_infinity_medium_width) {
  RUN_TEST(float, "INFINITY", "%25g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_infinity_neg_medium_width) {
  RUN_TEST(float, "-INFINITY", "%25g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_null_big_width) {
  RUN_TEST(float, "0.0", "%70g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_null_neg_big_width) {
  RUN_TEST(float, "-0.0", "%70g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_fraction_short_big_width) {
  RUN_TEST(float, "0.1234567", "%70g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_fraction_medium_big_width) {
  RUN_TEST(float, "0.123456789101112", "%70g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_fraction_long_big_width) {
  RUN_TEST(float, "0.12356789101112131415", "%70g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_general_short_big_width) {
  RUN_TEST(float, "1234.567", "%70g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_general_medium_big_width) {
  RUN_TEST(float, "1234.56789101112", "%70g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_general_long_big_width) {
  RUN_TEST(float, "12345678.9101112131415", "%70g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_infinity_big_width) {
  RUN_TEST(float, "INFINITY", "%70g", ck_assert_float_eq);
}
END_TEST
START_TEST(g_infinity_neg_big_width) {
  RUN_TEST(float, "-INFINITY", "%70g", ck_assert_float_eq);
}
END_TEST
START_TEST(G_null_no_width) {
  RUN_TEST(float, "0.0", "%G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_null_neg_no_width) {
  RUN_TEST(float, "-0.0", "%G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_fraction_short_no_width) {
  RUN_TEST(float, "0.1234567", "%G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_fraction_medium_no_width) {
  RUN_TEST(float, "0.123456789101112", "%G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_fraction_long_no_width) {
  RUN_TEST(float, "0.12356789101112131415", "%G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_general_short_no_width) {
  RUN_TEST(float, "1234.567", "%G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_general_medium_no_width) {
  RUN_TEST(float, "1234.56789101112", "%G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_general_long_no_width) {
  RUN_TEST(float, "12345678.9101112131415", "%G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_infinity_no_width) {
  RUN_TEST(float, "INFINITY", "%G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_infinity_neg_no_width) {
  RUN_TEST(float, "-INFINITY", "%G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_null_small_width) {
  RUN_TEST(float, "0.0", "%10G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_null_neg_small_width) {
  RUN_TEST(float, "-0.0", "%10G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_fraction_short_small_width) {
  RUN_TEST(float, "0.1234567", "%10G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_fraction_medium_small_width) {
  RUN_TEST(float, "0.123456789101112", "%10G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_fraction_long_small_width) {
  RUN_TEST(float, "0.12356789101112131415", "%10G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_general_short_small_width) {
  RUN_TEST(float, "1234.567", "%10G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_general_medium_small_width) {
  RUN_TEST(float, "1234.56789101112", "%10G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_general_long_small_width) {
  RUN_TEST(float, "12345678.9101112131415", "%10G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_infinity_small_width) {
  RUN_TEST(float, "INFINITY", "%10G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_infinity_neg_small_width) {
  RUN_TEST(float, "-INFINITY", "%10G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_null_medium_width) {
  RUN_TEST(float, "0.0", "%25G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_null_neg_medium_width) {
  RUN_TEST(float, "-0.0", "%25G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_fraction_short_medium_width) {
  RUN_TEST(float, "0.1234567", "%25G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_fraction_medium_medium_width) {
  RUN_TEST(float, "0.123456789101112", "%25G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_fraction_long_medium_width) {
  RUN_TEST(float, "0.12356789101112131415", "%25G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_general_short_medium_width) {
  RUN_TEST(float, "1234.567", "%25G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_general_medium_medium_width) {
  RUN_TEST(float, "1234.56789101112", "%25G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_general_long_medium_width) {
  RUN_TEST(float, "12345678.9101112131415", "%25G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_infinity_medium_width) {
  RUN_TEST(float, "INFINITY", "%25G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_infinity_neg_medium_width) {
  RUN_TEST(float, "-INFINITY", "%25G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_null_big_width) {
  RUN_TEST(float, "0.0", "%70G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_null_neg_big_width) {
  RUN_TEST(float, "-0.0", "%70G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_fraction_short_big_width) {
  RUN_TEST(float, "0.1234567", "%70G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_fraction_medium_big_width) {
  RUN_TEST(float, "0.123456789101112", "%70G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_fraction_long_big_width) {
  RUN_TEST(float, "0.12356789101112131415", "%70G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_general_short_big_width) {
  RUN_TEST(float, "1234.567", "%70G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_general_medium_big_width) {
  RUN_TEST(float, "1234.56789101112", "%70G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_general_long_big_width) {
  RUN_TEST(float, "12345678.9101112131415", "%70G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_infinity_big_width) {
  RUN_TEST(float, "INFINITY", "%70G", ck_assert_float_eq);
}
END_TEST
START_TEST(G_infinity_neg_big_width) {
  RUN_TEST(float, "-INFINITY", "%70G", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_null_no_width) {
  RUN_TEST(double, "0.0", "%lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_null_neg_no_width) {
  RUN_TEST(double, "-0.0", "%lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_fraction_short_no_width) {
  RUN_TEST(double, "0.1234567", "%lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_fraction_medium_no_width) {
  RUN_TEST(double, "0.123456789101112", "%lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_fraction_long_no_width) {
  RUN_TEST(double, "0.12356789101112131415", "%lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_general_short_no_width) {
  RUN_TEST(double, "1234.567", "%lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_general_medium_no_width) {
  RUN_TEST(double, "1234.56789101112", "%lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_general_long_no_width) {
  RUN_TEST(double, "12345678.9101112131415", "%lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_infinity_no_width) {
  RUN_TEST(double, "INFINITY", "%lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_infinity_neg_no_width) {
  RUN_TEST(double, "-INFINITY", "%lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_null_small_width) {
  RUN_TEST(double, "0.0", "%10lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_null_neg_small_width) {
  RUN_TEST(double, "-0.0", "%10lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_fraction_short_small_width) {
  RUN_TEST(double, "0.1234567", "%10lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_fraction_medium_small_width) {
  RUN_TEST(double, "0.123456789101112", "%10lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_fraction_long_small_width) {
  RUN_TEST(double, "0.12356789101112131415", "%10lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_general_short_small_width) {
  RUN_TEST(double, "1234.567", "%10lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_general_medium_small_width) {
  RUN_TEST(double, "1234.56789101112", "%10lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_general_long_small_width) {
  RUN_TEST(double, "12345678.9101112131415", "%10lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_infinity_small_width) {
  RUN_TEST(double, "INFINITY", "%10lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_infinity_neg_small_width) {
  RUN_TEST(double, "-INFINITY", "%10lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_null_medium_width) {
  RUN_TEST(double, "0.0", "%25lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_null_neg_medium_width) {
  RUN_TEST(double, "-0.0", "%25lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_fraction_short_medium_width) {
  RUN_TEST(double, "0.1234567", "%25lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_fraction_medium_medium_width) {
  RUN_TEST(double, "0.123456789101112", "%25lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_fraction_long_medium_width) {
  RUN_TEST(double, "0.12356789101112131415", "%25lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_general_short_medium_width) {
  RUN_TEST(double, "1234.567", "%25lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_general_medium_medium_width) {
  RUN_TEST(double, "1234.56789101112", "%25lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_general_long_medium_width) {
  RUN_TEST(double, "12345678.9101112131415", "%25lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_infinity_medium_width) {
  RUN_TEST(double, "INFINITY", "%25lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_infinity_neg_medium_width) {
  RUN_TEST(double, "-INFINITY", "%25lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_null_big_width) {
  RUN_TEST(double, "0.0", "%70lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_null_neg_big_width) {
  RUN_TEST(double, "-0.0", "%70lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_fraction_short_big_width) {
  RUN_TEST(double, "0.1234567", "%70lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_fraction_medium_big_width) {
  RUN_TEST(double, "0.123456789101112", "%70lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_fraction_long_big_width) {
  RUN_TEST(double, "0.12356789101112131415", "%70lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_general_short_big_width) {
  RUN_TEST(double, "1234.567", "%70lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_general_medium_big_width) {
  RUN_TEST(double, "1234.56789101112", "%70lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_general_long_big_width) {
  RUN_TEST(double, "12345678.9101112131415", "%70lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_infinity_big_width) {
  RUN_TEST(double, "INFINITY", "%70lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lg_infinity_neg_big_width) {
  RUN_TEST(double, "-INFINITY", "%70lg", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_null_no_width) {
  RUN_TEST(double, "0.0", "%lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_null_neg_no_width) {
  RUN_TEST(double, "-0.0", "%lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_fraction_short_no_width) {
  RUN_TEST(double, "0.1234567", "%lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_fraction_medium_no_width) {
  RUN_TEST(double, "0.123456789101112", "%lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_fraction_long_no_width) {
  RUN_TEST(double, "0.12356789101112131415", "%lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_general_short_no_width) {
  RUN_TEST(double, "1234.567", "%lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_general_medium_no_width) {
  RUN_TEST(double, "1234.56789101112", "%lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_general_long_no_width) {
  RUN_TEST(double, "12345678.9101112131415", "%lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_infinity_no_width) {
  RUN_TEST(double, "INFINITY", "%lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_infinity_neg_no_width) {
  RUN_TEST(double, "-INFINITY", "%lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_null_small_width) {
  RUN_TEST(double, "0.0", "%10lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_null_neg_small_width) {
  RUN_TEST(double, "-0.0", "%10lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_fraction_short_small_width) {
  RUN_TEST(double, "0.1234567", "%10lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_fraction_medium_small_width) {
  RUN_TEST(double, "0.123456789101112", "%10lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_fraction_long_small_width) {
  RUN_TEST(double, "0.12356789101112131415", "%10lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_general_short_small_width) {
  RUN_TEST(double, "1234.567", "%10lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_general_medium_small_width) {
  RUN_TEST(double, "1234.56789101112", "%10lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_general_long_small_width) {
  RUN_TEST(double, "12345678.9101112131415", "%10lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_infinity_small_width) {
  RUN_TEST(double, "INFINITY", "%10lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_infinity_neg_small_width) {
  RUN_TEST(double, "-INFINITY", "%10lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_null_medium_width) {
  RUN_TEST(double, "0.0", "%25lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_null_neg_medium_width) {
  RUN_TEST(double, "-0.0", "%25lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_fraction_short_medium_width) {
  RUN_TEST(double, "0.1234567", "%25lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_fraction_medium_medium_width) {
  RUN_TEST(double, "0.123456789101112", "%25lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_fraction_long_medium_width) {
  RUN_TEST(double, "0.12356789101112131415", "%25lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_general_short_medium_width) {
  RUN_TEST(double, "1234.567", "%25lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_general_medium_medium_width) {
  RUN_TEST(double, "1234.56789101112", "%25lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_general_long_medium_width) {
  RUN_TEST(double, "12345678.9101112131415", "%25lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_infinity_medium_width) {
  RUN_TEST(double, "INFINITY", "%25lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_infinity_neg_medium_width) {
  RUN_TEST(double, "-INFINITY", "%25lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_null_big_width) {
  RUN_TEST(double, "0.0", "%70lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_null_neg_big_width) {
  RUN_TEST(double, "-0.0", "%70lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_fraction_short_big_width) {
  RUN_TEST(double, "0.1234567", "%70lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_fraction_medium_big_width) {
  RUN_TEST(double, "0.123456789101112", "%70lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_fraction_long_big_width) {
  RUN_TEST(double, "0.12356789101112131415", "%70lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_general_short_big_width) {
  RUN_TEST(double, "1234.567", "%70lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_general_medium_big_width) {
  RUN_TEST(double, "1234.56789101112", "%70lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_general_long_big_width) {
  RUN_TEST(double, "12345678.9101112131415", "%70lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_infinity_big_width) {
  RUN_TEST(double, "INFINITY", "%70lG", ck_assert_float_eq);
}
END_TEST
START_TEST(lG_infinity_neg_big_width) {
  RUN_TEST(double, "-INFINITY", "%70lG", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_null_no_width) {
  RUN_TEST(long double, "0.0", "%Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_null_neg_no_width) {
  RUN_TEST(long double, "-0.0", "%Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_fraction_short_no_width) {
  RUN_TEST(long double, "0.1234567", "%Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_fraction_medium_no_width) {
  RUN_TEST(long double, "0.123456789101112", "%Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_fraction_long_no_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_general_short_no_width) {
  RUN_TEST(long double, "1234.567", "%Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_general_medium_no_width) {
  RUN_TEST(long double, "1234.56789101112", "%Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_general_long_no_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_infinity_no_width) {
  RUN_TEST(long double, "INFINITY", "%Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_infinity_neg_no_width) {
  RUN_TEST(long double, "-INFINITY", "%Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_null_small_width) {
  RUN_TEST(long double, "0.0", "%10Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_null_neg_small_width) {
  RUN_TEST(long double, "-0.0", "%10Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_fraction_short_small_width) {
  RUN_TEST(long double, "0.1234567", "%10Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_fraction_medium_small_width) {
  RUN_TEST(long double, "0.123456789101112", "%10Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_fraction_long_small_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%10Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_general_short_small_width) {
  RUN_TEST(long double, "1234.567", "%10Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_general_medium_small_width) {
  RUN_TEST(long double, "1234.56789101112", "%10Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_general_long_small_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%10Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_infinity_small_width) {
  RUN_TEST(long double, "INFINITY", "%10Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_infinity_neg_small_width) {
  RUN_TEST(long double, "-INFINITY", "%10Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_null_medium_width) {
  RUN_TEST(long double, "0.0", "%25Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_null_neg_medium_width) {
  RUN_TEST(long double, "-0.0", "%25Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_fraction_short_medium_width) {
  RUN_TEST(long double, "0.1234567", "%25Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_fraction_medium_medium_width) {
  RUN_TEST(long double, "0.123456789101112", "%25Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_fraction_long_medium_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%25Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_general_short_medium_width) {
  RUN_TEST(long double, "1234.567", "%25Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_general_medium_medium_width) {
  RUN_TEST(long double, "1234.56789101112", "%25Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_general_long_medium_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%25Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_infinity_medium_width) {
  RUN_TEST(long double, "INFINITY", "%25Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_infinity_neg_medium_width) {
  RUN_TEST(long double, "-INFINITY", "%25Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_null_big_width) {
  RUN_TEST(long double, "0.0", "%70Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_null_neg_big_width) {
  RUN_TEST(long double, "-0.0", "%70Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_fraction_short_big_width) {
  RUN_TEST(long double, "0.1234567", "%70Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_fraction_medium_big_width) {
  RUN_TEST(long double, "0.123456789101112", "%70Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_fraction_long_big_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%70Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_general_short_big_width) {
  RUN_TEST(long double, "1234.567", "%70Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_general_medium_big_width) {
  RUN_TEST(long double, "1234.56789101112", "%70Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_general_long_big_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%70Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_infinity_big_width) {
  RUN_TEST(long double, "INFINITY", "%70Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(Lg_infinity_neg_big_width) {
  RUN_TEST(long double, "-INFINITY", "%70Lg", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_null_no_width) {
  RUN_TEST(long double, "0.0", "%LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_null_neg_no_width) {
  RUN_TEST(long double, "-0.0", "%LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_fraction_short_no_width) {
  RUN_TEST(long double, "0.1234567", "%LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_fraction_medium_no_width) {
  RUN_TEST(long double, "0.123456789101112", "%LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_fraction_long_no_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_general_short_no_width) {
  RUN_TEST(long double, "1234.567", "%LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_general_medium_no_width) {
  RUN_TEST(long double, "1234.56789101112", "%LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_general_long_no_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_infinity_no_width) {
  RUN_TEST(long double, "INFINITY", "%LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_infinity_neg_no_width) {
  RUN_TEST(long double, "-INFINITY", "%LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_null_small_width) {
  RUN_TEST(long double, "0.0", "%10LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_null_neg_small_width) {
  RUN_TEST(long double, "-0.0", "%10LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_fraction_short_small_width) {
  RUN_TEST(long double, "0.1234567", "%10LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_fraction_medium_small_width) {
  RUN_TEST(long double, "0.123456789101112", "%10LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_fraction_long_small_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%10LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_general_short_small_width) {
  RUN_TEST(long double, "1234.567", "%10LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_general_medium_small_width) {
  RUN_TEST(long double, "1234.56789101112", "%10LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_general_long_small_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%10LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_infinity_small_width) {
  RUN_TEST(long double, "INFINITY", "%10LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_infinity_neg_small_width) {
  RUN_TEST(long double, "-INFINITY", "%10LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_null_medium_width) {
  RUN_TEST(long double, "0.0", "%25LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_null_neg_medium_width) {
  RUN_TEST(long double, "-0.0", "%25LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_fraction_short_medium_width) {
  RUN_TEST(long double, "0.1234567", "%25LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_fraction_medium_medium_width) {
  RUN_TEST(long double, "0.123456789101112", "%25LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_fraction_long_medium_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%25LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_general_short_medium_width) {
  RUN_TEST(long double, "1234.567", "%25LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_general_medium_medium_width) {
  RUN_TEST(long double, "1234.56789101112", "%25LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_general_long_medium_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%25LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_infinity_medium_width) {
  RUN_TEST(long double, "INFINITY", "%25LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_infinity_neg_medium_width) {
  RUN_TEST(long double, "-INFINITY", "%25LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_null_big_width) {
  RUN_TEST(long double, "0.0", "%70LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_null_neg_big_width) {
  RUN_TEST(long double, "-0.0", "%70LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_fraction_short_big_width) {
  RUN_TEST(long double, "0.1234567", "%70LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_fraction_medium_big_width) {
  RUN_TEST(long double, "0.123456789101112", "%70LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_fraction_long_big_width) {
  RUN_TEST(long double, "0.12356789101112131415", "%70LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_general_short_big_width) {
  RUN_TEST(long double, "1234.567", "%70LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_general_medium_big_width) {
  RUN_TEST(long double, "1234.56789101112", "%70LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_general_long_big_width) {
  RUN_TEST(long double, "12345678.9101112131415", "%70LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_infinity_big_width) {
  RUN_TEST(long double, "INFINITY", "%70LG", ck_assert_float_eq);
}
END_TEST
START_TEST(LG_infinity_neg_big_width) {
  RUN_TEST(long double, "-INFINITY", "%70LG", ck_assert_float_eq);
}
END_TEST

START_TEST(d_null_no_width) { RUN_TEST(int, "0", "%d", ck_assert_int_eq); }
END_TEST
START_TEST(d_null_neg_no_width) { RUN_TEST(int, "-0", "%d", ck_assert_int_eq); }
END_TEST
START_TEST(d_int_short_no_width) { RUN_TEST(int, "1", "%d", ck_assert_int_eq); }
END_TEST
START_TEST(d_int_short_neg_no_width) {
  RUN_TEST(int, "-1", "%d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_medium_no_width) {
  RUN_TEST(int, "12345", "%d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_medium_neg_no_width) {
  RUN_TEST(int, "-12345", "%d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_long_no_width) {
  RUN_TEST(int, "123456789", "%d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_long_neg_no_width) {
  RUN_TEST(int, "-123456789", "%d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_null_small_width) { RUN_TEST(int, "0", "%10d", ck_assert_int_eq); }
END_TEST
START_TEST(d_null_neg_small_width) {
  RUN_TEST(int, "-0", "%10d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_short_small_width) {
  RUN_TEST(int, "1", "%10d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_short_neg_small_width) {
  RUN_TEST(int, "-1", "%10d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_medium_small_width) {
  RUN_TEST(int, "12345", "%10d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_medium_neg_small_width) {
  RUN_TEST(int, "-12345", "%10d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_long_small_width) {
  RUN_TEST(int, "123456789", "%10d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_long_neg_small_width) {
  RUN_TEST(int, "-123456789", "%10d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_null_medium_width) {
  RUN_TEST(int, "0", "%25d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_null_neg_medium_width) {
  RUN_TEST(int, "-0", "%25d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_short_medium_width) {
  RUN_TEST(int, "1", "%25d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_short_neg_medium_width) {
  RUN_TEST(int, "-1", "%25d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_medium_medium_width) {
  RUN_TEST(int, "12345", "%25d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_medium_neg_medium_width) {
  RUN_TEST(int, "-12345", "%25d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_long_medium_width) {
  RUN_TEST(int, "123456789", "%25d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_long_neg_medium_width) {
  RUN_TEST(int, "-123456789", "%25d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_null_big_width) { RUN_TEST(int, "0", "%70d", ck_assert_int_eq); }
END_TEST
START_TEST(d_null_neg_big_width) {
  RUN_TEST(int, "-0", "%70d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_short_big_width) {
  RUN_TEST(int, "1", "%70d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_short_neg_big_width) {
  RUN_TEST(int, "-1", "%70d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_medium_big_width) {
  RUN_TEST(int, "12345", "%70d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_medium_neg_big_width) {
  RUN_TEST(int, "-12345", "%70d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_long_big_width) {
  RUN_TEST(int, "123456789", "%70d", ck_assert_int_eq);
}
END_TEST
START_TEST(d_int_long_neg_big_width) {
  RUN_TEST(int, "-123456789", "%70d", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_null_no_width) { RUN_TEST(short, "0", "%hd", ck_assert_int_eq); }
END_TEST
START_TEST(hd_null_neg_no_width) {
  RUN_TEST(short, "-0", "%hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_short_no_width) {
  RUN_TEST(short, "1", "%hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_short_neg_no_width) {
  RUN_TEST(short, "-1", "%hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_medium_no_width) {
  RUN_TEST(short, "12345", "%hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_medium_neg_no_width) {
  RUN_TEST(short, "-12345", "%hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_long_no_width) {
  RUN_TEST(short, "123456789", "%hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_long_neg_no_width) {
  RUN_TEST(short, "-123456789", "%hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_null_small_width) {
  RUN_TEST(short, "0", "%10hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_null_neg_small_width) {
  RUN_TEST(short, "-0", "%10hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_short_small_width) {
  RUN_TEST(short, "1", "%10hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_short_neg_small_width) {
  RUN_TEST(short, "-1", "%10hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_medium_small_width) {
  RUN_TEST(short, "12345", "%10hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_medium_neg_small_width) {
  RUN_TEST(short, "-12345", "%10hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_long_small_width) {
  RUN_TEST(short, "123456789", "%10hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_long_neg_small_width) {
  RUN_TEST(short, "-123456789", "%10hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_null_medium_width) {
  RUN_TEST(short, "0", "%25hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_null_neg_medium_width) {
  RUN_TEST(short, "-0", "%25hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_short_medium_width) {
  RUN_TEST(short, "1", "%25hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_short_neg_medium_width) {
  RUN_TEST(short, "-1", "%25hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_medium_medium_width) {
  RUN_TEST(short, "12345", "%25hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_medium_neg_medium_width) {
  RUN_TEST(short, "-12345", "%25hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_long_medium_width) {
  RUN_TEST(short, "123456789", "%25hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_long_neg_medium_width) {
  RUN_TEST(short, "-123456789", "%25hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_null_big_width) {
  RUN_TEST(short, "0", "%70hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_null_neg_big_width) {
  RUN_TEST(short, "-0", "%70hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_short_big_width) {
  RUN_TEST(short, "1", "%70hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_short_neg_big_width) {
  RUN_TEST(short, "-1", "%70hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_medium_big_width) {
  RUN_TEST(short, "12345", "%70hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_medium_neg_big_width) {
  RUN_TEST(short, "-12345", "%70hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_long_big_width) {
  RUN_TEST(short, "123456789", "%70hd", ck_assert_int_eq);
}
END_TEST
START_TEST(hd_int_long_neg_big_width) {
  RUN_TEST(short, "-123456789", "%70hd", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_null_no_width) {
  RUN_TEST(long int, "0", "%ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_null_neg_no_width) {
  RUN_TEST(long int, "-0", "%ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_short_no_width) {
  RUN_TEST(long int, "1", "%ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_short_neg_no_width) {
  RUN_TEST(long int, "-1", "%ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_medium_no_width) {
  RUN_TEST(long int, "12345", "%ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_medium_neg_no_width) {
  RUN_TEST(long int, "-12345", "%ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_long_no_width) {
  RUN_TEST(long int, "123456789", "%ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_long_neg_no_width) {
  RUN_TEST(long int, "-123456789", "%ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_null_small_width) {
  RUN_TEST(long int, "0", "%10ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_null_neg_small_width) {
  RUN_TEST(long int, "-0", "%10ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_short_small_width) {
  RUN_TEST(long int, "1", "%10ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_short_neg_small_width) {
  RUN_TEST(long int, "-1", "%10ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_medium_small_width) {
  RUN_TEST(long int, "12345", "%10ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_medium_neg_small_width) {
  RUN_TEST(long int, "-12345", "%10ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_long_small_width) {
  RUN_TEST(long int, "123456789", "%10ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_long_neg_small_width) {
  RUN_TEST(long int, "-123456789", "%10ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_null_medium_width) {
  RUN_TEST(long int, "0", "%25ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_null_neg_medium_width) {
  RUN_TEST(long int, "-0", "%25ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_short_medium_width) {
  RUN_TEST(long int, "1", "%25ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_short_neg_medium_width) {
  RUN_TEST(long int, "-1", "%25ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_medium_medium_width) {
  RUN_TEST(long int, "12345", "%25ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_medium_neg_medium_width) {
  RUN_TEST(long int, "-12345", "%25ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_long_medium_width) {
  RUN_TEST(long int, "123456789", "%25ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_long_neg_medium_width) {
  RUN_TEST(long int, "-123456789", "%25ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_null_big_width) {
  RUN_TEST(long int, "0", "%70ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_null_neg_big_width) {
  RUN_TEST(long int, "-0", "%70ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_short_big_width) {
  RUN_TEST(long int, "1", "%70ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_short_neg_big_width) {
  RUN_TEST(long int, "-1", "%70ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_medium_big_width) {
  RUN_TEST(long int, "12345", "%70ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_medium_neg_big_width) {
  RUN_TEST(long int, "-12345", "%70ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_long_big_width) {
  RUN_TEST(long int, "123456789", "%70ld", ck_assert_int_eq);
}
END_TEST
START_TEST(ld_int_long_neg_big_width) {
  RUN_TEST(long int, "-123456789", "%70ld", ck_assert_int_eq);
}
END_TEST
START_TEST(i_null_no_width) { RUN_TEST(int, "0", "%i", ck_assert_int_eq); }
END_TEST
START_TEST(i_null_neg_no_width) { RUN_TEST(int, "-0", "%i", ck_assert_int_eq); }
END_TEST
START_TEST(i_int_short_no_width) { RUN_TEST(int, "1", "%i", ck_assert_int_eq); }
END_TEST
START_TEST(i_int_short_neg_no_width) {
  RUN_TEST(int, "-1", "%i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_medium_no_width) {
  RUN_TEST(int, "12345", "%i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_medium_neg_no_width) {
  RUN_TEST(int, "-12345", "%i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_long_no_width) {
  RUN_TEST(int, "123456789", "%i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_long_neg_no_width) {
  RUN_TEST(int, "-123456789", "%i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_null_small_width) { RUN_TEST(int, "0", "%10i", ck_assert_int_eq); }
END_TEST
START_TEST(i_null_neg_small_width) {
  RUN_TEST(int, "-0", "%10i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_short_small_width) {
  RUN_TEST(int, "1", "%10i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_short_neg_small_width) {
  RUN_TEST(int, "-1", "%10i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_medium_small_width) {
  RUN_TEST(int, "12345", "%10i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_medium_neg_small_width) {
  RUN_TEST(int, "-12345", "%10i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_long_small_width) {
  RUN_TEST(int, "123456789", "%10i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_long_neg_small_width) {
  RUN_TEST(int, "-123456789", "%10i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_null_medium_width) {
  RUN_TEST(int, "0", "%25i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_null_neg_medium_width) {
  RUN_TEST(int, "-0", "%25i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_short_medium_width) {
  RUN_TEST(int, "1", "%25i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_short_neg_medium_width) {
  RUN_TEST(int, "-1", "%25i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_medium_medium_width) {
  RUN_TEST(int, "12345", "%25i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_medium_neg_medium_width) {
  RUN_TEST(int, "-12345", "%25i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_long_medium_width) {
  RUN_TEST(int, "123456789", "%25i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_long_neg_medium_width) {
  RUN_TEST(int, "-123456789", "%25i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_null_big_width) { RUN_TEST(int, "0", "%70i", ck_assert_int_eq); }
END_TEST
START_TEST(i_null_neg_big_width) {
  RUN_TEST(int, "-0", "%70i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_short_big_width) {
  RUN_TEST(int, "1", "%70i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_short_neg_big_width) {
  RUN_TEST(int, "-1", "%70i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_medium_big_width) {
  RUN_TEST(int, "12345", "%70i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_medium_neg_big_width) {
  RUN_TEST(int, "-12345", "%70i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_long_big_width) {
  RUN_TEST(int, "123456789", "%70i", ck_assert_int_eq);
}
END_TEST
START_TEST(i_int_long_neg_big_width) {
  RUN_TEST(int, "-123456789", "%70i", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_null_no_width) { RUN_TEST(short, "0", "%hi", ck_assert_int_eq); }
END_TEST
START_TEST(hi_null_neg_no_width) {
  RUN_TEST(short, "-0", "%hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_short_no_width) {
  RUN_TEST(short, "1", "%hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_short_neg_no_width) {
  RUN_TEST(short, "-1", "%hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_medium_no_width) {
  RUN_TEST(short, "12345", "%hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_medium_neg_no_width) {
  RUN_TEST(short, "-12345", "%hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_long_no_width) {
  RUN_TEST(short, "123456789", "%hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_long_neg_no_width) {
  RUN_TEST(short, "-123456789", "%hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_null_small_width) {
  RUN_TEST(short, "0", "%10hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_null_neg_small_width) {
  RUN_TEST(short, "-0", "%10hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_short_small_width) {
  RUN_TEST(short, "1", "%10hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_short_neg_small_width) {
  RUN_TEST(short, "-1", "%10hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_medium_small_width) {
  RUN_TEST(short, "12345", "%10hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_medium_neg_small_width) {
  RUN_TEST(short, "-12345", "%10hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_long_small_width) {
  RUN_TEST(short, "123456789", "%10hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_long_neg_small_width) {
  RUN_TEST(short, "-123456789", "%10hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_null_medium_width) {
  RUN_TEST(short, "0", "%25hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_null_neg_medium_width) {
  RUN_TEST(short, "-0", "%25hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_short_medium_width) {
  RUN_TEST(short, "1", "%25hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_short_neg_medium_width) {
  RUN_TEST(short, "-1", "%25hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_medium_medium_width) {
  RUN_TEST(short, "12345", "%25hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_medium_neg_medium_width) {
  RUN_TEST(short, "-12345", "%25hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_long_medium_width) {
  RUN_TEST(short, "123456789", "%25hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_long_neg_medium_width) {
  RUN_TEST(short, "-123456789", "%25hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_null_big_width) {
  RUN_TEST(short, "0", "%70hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_null_neg_big_width) {
  RUN_TEST(short, "-0", "%70hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_short_big_width) {
  RUN_TEST(short, "1", "%70hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_short_neg_big_width) {
  RUN_TEST(short, "-1", "%70hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_medium_big_width) {
  RUN_TEST(short, "12345", "%70hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_medium_neg_big_width) {
  RUN_TEST(short, "-12345", "%70hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_long_big_width) {
  RUN_TEST(short, "123456789", "%70hi", ck_assert_int_eq);
}
END_TEST
START_TEST(hi_int_long_neg_big_width) {
  RUN_TEST(short, "-123456789", "%70hi", ck_assert_int_eq);
}
END_TEST
START_TEST(li_null_no_width) {
  RUN_TEST(long int, "0", "%li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_null_neg_no_width) {
  RUN_TEST(long int, "-0", "%li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_short_no_width) {
  RUN_TEST(long int, "1", "%li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_short_neg_no_width) {
  RUN_TEST(long int, "-1", "%li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_medium_no_width) {
  RUN_TEST(long int, "12345", "%li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_medium_neg_no_width) {
  RUN_TEST(long int, "-12345", "%li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_long_no_width) {
  RUN_TEST(long int, "123456789", "%li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_long_neg_no_width) {
  RUN_TEST(long int, "-123456789", "%li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_null_small_width) {
  RUN_TEST(long int, "0", "%10li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_null_neg_small_width) {
  RUN_TEST(long int, "-0", "%10li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_short_small_width) {
  RUN_TEST(long int, "1", "%10li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_short_neg_small_width) {
  RUN_TEST(long int, "-1", "%10li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_medium_small_width) {
  RUN_TEST(long int, "12345", "%10li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_medium_neg_small_width) {
  RUN_TEST(long int, "-12345", "%10li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_long_small_width) {
  RUN_TEST(long int, "123456789", "%10li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_long_neg_small_width) {
  RUN_TEST(long int, "-123456789", "%10li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_null_medium_width) {
  RUN_TEST(long int, "0", "%25li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_null_neg_medium_width) {
  RUN_TEST(long int, "-0", "%25li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_short_medium_width) {
  RUN_TEST(long int, "1", "%25li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_short_neg_medium_width) {
  RUN_TEST(long int, "-1", "%25li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_medium_medium_width) {
  RUN_TEST(long int, "12345", "%25li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_medium_neg_medium_width) {
  RUN_TEST(long int, "-12345", "%25li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_long_medium_width) {
  RUN_TEST(long int, "123456789", "%25li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_long_neg_medium_width) {
  RUN_TEST(long int, "-123456789", "%25li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_null_big_width) {
  RUN_TEST(long int, "0", "%70li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_null_neg_big_width) {
  RUN_TEST(long int, "-0", "%70li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_short_big_width) {
  RUN_TEST(long int, "1", "%70li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_short_neg_big_width) {
  RUN_TEST(long int, "-1", "%70li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_medium_big_width) {
  RUN_TEST(long int, "12345", "%70li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_medium_neg_big_width) {
  RUN_TEST(long int, "-12345", "%70li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_long_big_width) {
  RUN_TEST(long int, "123456789", "%70li", ck_assert_int_eq);
}
END_TEST
START_TEST(li_int_long_neg_big_width) {
  RUN_TEST(long int, "-123456789", "%70li", ck_assert_int_eq);
}
END_TEST
START_TEST(u_null_no_width) {
  RUN_TEST(unsigned int, "0", "%u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_null_neg_no_width) {
  RUN_TEST(unsigned int, "-0", "%u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_short_no_width) {
  RUN_TEST(unsigned int, "1", "%u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_short_neg_no_width) {
  RUN_TEST(unsigned int, "-1", "%u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_medium_no_width) {
  RUN_TEST(unsigned int, "12345", "%u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_medium_neg_no_width) {
  RUN_TEST(unsigned int, "-12345", "%u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_long_no_width) {
  RUN_TEST(unsigned int, "123456789", "%u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_long_neg_no_width) {
  RUN_TEST(unsigned int, "-123456789", "%u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_null_small_width) {
  RUN_TEST(unsigned int, "0", "%10u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_null_neg_small_width) {
  RUN_TEST(unsigned int, "-0", "%10u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_short_small_width) {
  RUN_TEST(unsigned int, "1", "%10u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_short_neg_small_width) {
  RUN_TEST(unsigned int, "-1", "%10u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_medium_small_width) {
  RUN_TEST(unsigned int, "12345", "%10u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_medium_neg_small_width) {
  RUN_TEST(unsigned int, "-12345", "%10u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_long_small_width) {
  RUN_TEST(unsigned int, "123456789", "%10u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_long_neg_small_width) {
  RUN_TEST(unsigned int, "-123456789", "%10u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_null_medium_width) {
  RUN_TEST(unsigned int, "0", "%25u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_null_neg_medium_width) {
  RUN_TEST(unsigned int, "-0", "%25u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_short_medium_width) {
  RUN_TEST(unsigned int, "1", "%25u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_short_neg_medium_width) {
  RUN_TEST(unsigned int, "-1", "%25u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_medium_medium_width) {
  RUN_TEST(unsigned int, "12345", "%25u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_medium_neg_medium_width) {
  RUN_TEST(unsigned int, "-12345", "%25u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_long_medium_width) {
  RUN_TEST(unsigned int, "123456789", "%25u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_long_neg_medium_width) {
  RUN_TEST(unsigned int, "-123456789", "%25u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_null_big_width) {
  RUN_TEST(unsigned int, "0", "%70u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_null_neg_big_width) {
  RUN_TEST(unsigned int, "-0", "%70u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_short_big_width) {
  RUN_TEST(unsigned int, "1", "%70u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_short_neg_big_width) {
  RUN_TEST(unsigned int, "-1", "%70u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_medium_big_width) {
  RUN_TEST(unsigned int, "12345", "%70u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_medium_neg_big_width) {
  RUN_TEST(unsigned int, "-12345", "%70u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_long_big_width) {
  RUN_TEST(unsigned int, "123456789", "%70u", ck_assert_uint_eq);
}
END_TEST
START_TEST(u_int_long_neg_big_width) {
  RUN_TEST(unsigned int, "-123456789", "%70u", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_null_no_width) {
  RUN_TEST(unsigned short, "0", "%hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_null_neg_no_width) {
  RUN_TEST(unsigned short, "-0", "%hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_short_no_width) {
  RUN_TEST(unsigned short, "1", "%hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_short_neg_no_width) {
  RUN_TEST(unsigned short, "-1", "%hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_medium_no_width) {
  RUN_TEST(unsigned short, "12345", "%hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_medium_neg_no_width) {
  RUN_TEST(unsigned short, "-12345", "%hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_long_no_width) {
  RUN_TEST(unsigned short, "123456789", "%hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_long_neg_no_width) {
  RUN_TEST(unsigned short, "-123456789", "%hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_null_small_width) {
  RUN_TEST(unsigned short, "0", "%10hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_null_neg_small_width) {
  RUN_TEST(unsigned short, "-0", "%10hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_short_small_width) {
  RUN_TEST(unsigned short, "1", "%10hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_short_neg_small_width) {
  RUN_TEST(unsigned short, "-1", "%10hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_medium_small_width) {
  RUN_TEST(unsigned short, "12345", "%10hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_medium_neg_small_width) {
  RUN_TEST(unsigned short, "-12345", "%10hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_long_small_width) {
  RUN_TEST(unsigned short, "123456789", "%10hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_long_neg_small_width) {
  RUN_TEST(unsigned short, "-123456789", "%10hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_null_medium_width) {
  RUN_TEST(unsigned short, "0", "%25hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_null_neg_medium_width) {
  RUN_TEST(unsigned short, "-0", "%25hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_short_medium_width) {
  RUN_TEST(unsigned short, "1", "%25hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_short_neg_medium_width) {
  RUN_TEST(unsigned short, "-1", "%25hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_medium_medium_width) {
  RUN_TEST(unsigned short, "12345", "%25hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_medium_neg_medium_width) {
  RUN_TEST(unsigned short, "-12345", "%25hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_long_medium_width) {
  RUN_TEST(unsigned short, "123456789", "%25hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_long_neg_medium_width) {
  RUN_TEST(unsigned short, "-123456789", "%25hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_null_big_width) {
  RUN_TEST(unsigned short, "0", "%70hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_null_neg_big_width) {
  RUN_TEST(unsigned short, "-0", "%70hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_short_big_width) {
  RUN_TEST(unsigned short, "1", "%70hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_short_neg_big_width) {
  RUN_TEST(unsigned short, "-1", "%70hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_medium_big_width) {
  RUN_TEST(unsigned short, "12345", "%70hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_medium_neg_big_width) {
  RUN_TEST(unsigned short, "-12345", "%70hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_long_big_width) {
  RUN_TEST(unsigned short, "123456789", "%70hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(hu_int_long_neg_big_width) {
  RUN_TEST(unsigned short, "-123456789", "%70hu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_null_no_width) {
  RUN_TEST(unsigned long int, "0", "%lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_null_neg_no_width) {
  RUN_TEST(unsigned long int, "-0", "%lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_short_no_width) {
  RUN_TEST(unsigned long int, "1", "%lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_short_neg_no_width) {
  RUN_TEST(unsigned long int, "-1", "%lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_medium_no_width) {
  RUN_TEST(unsigned long int, "12345", "%lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_medium_neg_no_width) {
  RUN_TEST(unsigned long int, "-12345", "%lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_long_no_width) {
  RUN_TEST(unsigned long int, "123456789", "%lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_long_neg_no_width) {
  RUN_TEST(unsigned long int, "-123456789", "%lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_null_small_width) {
  RUN_TEST(unsigned long int, "0", "%10lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_null_neg_small_width) {
  RUN_TEST(unsigned long int, "-0", "%10lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_short_small_width) {
  RUN_TEST(unsigned long int, "1", "%10lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_short_neg_small_width) {
  RUN_TEST(unsigned long int, "-1", "%10lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_medium_small_width) {
  RUN_TEST(unsigned long int, "12345", "%10lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_medium_neg_small_width) {
  RUN_TEST(unsigned long int, "-12345", "%10lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_long_small_width) {
  RUN_TEST(unsigned long int, "123456789", "%10lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_long_neg_small_width) {
  RUN_TEST(unsigned long int, "-123456789", "%10lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_null_medium_width) {
  RUN_TEST(unsigned long int, "0", "%25lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_null_neg_medium_width) {
  RUN_TEST(unsigned long int, "-0", "%25lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_short_medium_width) {
  RUN_TEST(unsigned long int, "1", "%25lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_short_neg_medium_width) {
  RUN_TEST(unsigned long int, "-1", "%25lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_medium_medium_width) {
  RUN_TEST(unsigned long int, "12345", "%25lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_medium_neg_medium_width) {
  RUN_TEST(unsigned long int, "-12345", "%25lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_long_medium_width) {
  RUN_TEST(unsigned long int, "123456789", "%25lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_long_neg_medium_width) {
  RUN_TEST(unsigned long int, "-123456789", "%25lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_null_big_width) {
  RUN_TEST(unsigned long int, "0", "%70lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_null_neg_big_width) {
  RUN_TEST(unsigned long int, "-0", "%70lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_short_big_width) {
  RUN_TEST(unsigned long int, "1", "%70lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_short_neg_big_width) {
  RUN_TEST(unsigned long int, "-1", "%70lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_medium_big_width) {
  RUN_TEST(unsigned long int, "12345", "%70lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_medium_neg_big_width) {
  RUN_TEST(unsigned long int, "-12345", "%70lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_long_big_width) {
  RUN_TEST(unsigned long int, "123456789", "%70lu", ck_assert_uint_eq);
}
END_TEST
START_TEST(lu_int_long_neg_big_width) {
  RUN_TEST(unsigned long int, "-123456789", "%70lu", ck_assert_uint_eq);
}
END_TEST

START_TEST(o_oct_null_no_width) {
  RUN_TEST(unsigned int, "0", "%o", ck_assert_uint_eq);
}
END_TEST
START_TEST(o_oct_medium_no_width) {
  RUN_TEST(unsigned int, "0755", "%o", ck_assert_uint_eq);
}
END_TEST
START_TEST(o_oct_long_no_width) {
  RUN_TEST(unsigned int, "01234567", "%o", ck_assert_uint_eq);
}
END_TEST
START_TEST(o_oct_null_small_width) {
  RUN_TEST(unsigned int, "0", "%10o", ck_assert_uint_eq);
}
END_TEST
START_TEST(o_oct_medium_small_width) {
  RUN_TEST(unsigned int, "0755", "%10o", ck_assert_uint_eq);
}
END_TEST
START_TEST(o_oct_long_small_width) {
  RUN_TEST(unsigned int, "01234567", "%10o", ck_assert_uint_eq);
}
END_TEST
START_TEST(o_oct_null_medium_width) {
  RUN_TEST(unsigned int, "0", "%25o", ck_assert_uint_eq);
}
END_TEST
START_TEST(o_oct_medium_medium_width) {
  RUN_TEST(unsigned int, "0755", "%25o", ck_assert_uint_eq);
}
END_TEST
START_TEST(o_oct_long_medium_width) {
  RUN_TEST(unsigned int, "01234567", "%25o", ck_assert_uint_eq);
}
END_TEST
START_TEST(o_oct_null_big_width) {
  RUN_TEST(unsigned int, "0", "%70o", ck_assert_uint_eq);
}
END_TEST
START_TEST(o_oct_medium_big_width) {
  RUN_TEST(unsigned int, "0755", "%70o", ck_assert_uint_eq);
}
END_TEST
START_TEST(o_oct_long_big_width) {
  RUN_TEST(unsigned int, "01234567", "%70o", ck_assert_uint_eq);
}
END_TEST
START_TEST(ho_oct_null_no_width) {
  RUN_TEST(unsigned short, "0", "%ho", ck_assert_uint_eq);
}
END_TEST
START_TEST(ho_oct_medium_no_width) {
  RUN_TEST(unsigned short, "0755", "%ho", ck_assert_uint_eq);
}
END_TEST
START_TEST(ho_oct_long_no_width) {
  RUN_TEST(unsigned short, "01234567", "%ho", ck_assert_uint_eq);
}
END_TEST
START_TEST(ho_oct_null_small_width) {
  RUN_TEST(unsigned short, "0", "%10ho", ck_assert_uint_eq);
}
END_TEST
START_TEST(ho_oct_medium_small_width) {
  RUN_TEST(unsigned short, "0755", "%10ho", ck_assert_uint_eq);
}
END_TEST
START_TEST(ho_oct_long_small_width) {
  RUN_TEST(unsigned short, "01234567", "%10ho", ck_assert_uint_eq);
}
END_TEST
START_TEST(ho_oct_null_medium_width) {
  RUN_TEST(unsigned short, "0", "%25ho", ck_assert_uint_eq);
}
END_TEST
START_TEST(ho_oct_medium_medium_width) {
  RUN_TEST(unsigned short, "0755", "%25ho", ck_assert_uint_eq);
}
END_TEST
START_TEST(ho_oct_long_medium_width) {
  RUN_TEST(unsigned short, "01234567", "%25ho", ck_assert_uint_eq);
}
END_TEST
START_TEST(ho_oct_null_big_width) {
  RUN_TEST(unsigned short, "0", "%70ho", ck_assert_uint_eq);
}
END_TEST
START_TEST(ho_oct_medium_big_width) {
  RUN_TEST(unsigned short, "0755", "%70ho", ck_assert_uint_eq);
}
END_TEST
START_TEST(ho_oct_long_big_width) {
  RUN_TEST(unsigned short, "01234567", "%70ho", ck_assert_uint_eq);
}
END_TEST
START_TEST(lo_oct_null_no_width) {
  RUN_TEST(unsigned long int, "0", "%lo", ck_assert_uint_eq);
}
END_TEST
START_TEST(lo_oct_medium_no_width) {
  RUN_TEST(unsigned long int, "0755", "%lo", ck_assert_uint_eq);
}
END_TEST
START_TEST(lo_oct_long_no_width) {
  RUN_TEST(unsigned long int, "01234567", "%lo", ck_assert_uint_eq);
}
END_TEST
START_TEST(lo_oct_null_small_width) {
  RUN_TEST(unsigned long int, "0", "%10lo", ck_assert_uint_eq);
}
END_TEST
START_TEST(lo_oct_medium_small_width) {
  RUN_TEST(unsigned long int, "0755", "%10lo", ck_assert_uint_eq);
}
END_TEST
START_TEST(lo_oct_long_small_width) {
  RUN_TEST(unsigned long int, "01234567", "%10lo", ck_assert_uint_eq);
}
END_TEST
START_TEST(lo_oct_null_medium_width) {
  RUN_TEST(unsigned long int, "0", "%25lo", ck_assert_uint_eq);
}
END_TEST
START_TEST(lo_oct_medium_medium_width) {
  RUN_TEST(unsigned long int, "0755", "%25lo", ck_assert_uint_eq);
}
END_TEST
START_TEST(lo_oct_long_medium_width) {
  RUN_TEST(unsigned long int, "01234567", "%25lo", ck_assert_uint_eq);
}
END_TEST
START_TEST(lo_oct_null_big_width) {
  RUN_TEST(unsigned long int, "0", "%70lo", ck_assert_uint_eq);
}
END_TEST
START_TEST(lo_oct_medium_big_width) {
  RUN_TEST(unsigned long int, "0755", "%70lo", ck_assert_uint_eq);
}
END_TEST
START_TEST(lo_oct_long_big_width) {
  RUN_TEST(unsigned long int, "01234567", "%70lo", ck_assert_uint_eq);
}
END_TEST

START_TEST(x_hex_null_no_width) {
  RUN_TEST(unsigned int, "0x0", "%x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_short_no_width) {
  RUN_TEST(unsigned int, "0x1a", "%x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_medium_no_width) {
  RUN_TEST(unsigned int, "0XDEAA", "%x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_no_prefix_no_width) {
  RUN_TEST(unsigned int, "123abc", "%x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_long_no_width) {
  RUN_TEST(unsigned int, "0x123456789ABCDEF", "%x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_null_small_width) {
  RUN_TEST(unsigned int, "0x0", "%10x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_short_small_width) {
  RUN_TEST(unsigned int, "0x1a", "%10x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_medium_small_width) {
  RUN_TEST(unsigned int, "0XDEAA", "%10x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_no_prefix_small_width) {
  RUN_TEST(unsigned int, "123abc", "%10x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_long_small_width) {
  RUN_TEST(unsigned int, "0x123456789ABCDEF", "%10x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_null_medium_width) {
  RUN_TEST(unsigned int, "0x0", "%25x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_short_medium_width) {
  RUN_TEST(unsigned int, "0x1a", "%25x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_medium_medium_width) {
  RUN_TEST(unsigned int, "0XDEAA", "%25x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_no_prefix_medium_width) {
  RUN_TEST(unsigned int, "123abc", "%25x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_long_medium_width) {
  RUN_TEST(unsigned int, "0x123456789ABCDEF", "%25x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_null_big_width) {
  RUN_TEST(unsigned int, "0x0", "%70x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_short_big_width) {
  RUN_TEST(unsigned int, "0x1a", "%70x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_medium_big_width) {
  RUN_TEST(unsigned int, "0XDEAA", "%70x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_no_prefix_big_width) {
  RUN_TEST(unsigned int, "123abc", "%70x", ck_assert_uint_eq);
}
END_TEST
START_TEST(x_hex_long_big_width) {
  RUN_TEST(unsigned int, "0x123456789ABCDEF", "%70x", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_null_no_width) {
  RUN_TEST(unsigned int, "0x0", "%X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_short_no_width) {
  RUN_TEST(unsigned int, "0x1a", "%X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_medium_no_width) {
  RUN_TEST(unsigned int, "0XDEAA", "%X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_no_prefix_no_width) {
  RUN_TEST(unsigned int, "123abc", "%X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_long_no_width) {
  RUN_TEST(unsigned int, "0x123456789ABCDEF", "%X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_null_small_width) {
  RUN_TEST(unsigned int, "0x0", "%10X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_short_small_width) {
  RUN_TEST(unsigned int, "0x1a", "%10X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_medium_small_width) {
  RUN_TEST(unsigned int, "0XDEAA", "%10X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_no_prefix_small_width) {
  RUN_TEST(unsigned int, "123abc", "%10X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_long_small_width) {
  RUN_TEST(unsigned int, "0x123456789ABCDEF", "%10X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_null_medium_width) {
  RUN_TEST(unsigned int, "0x0", "%25X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_short_medium_width) {
  RUN_TEST(unsigned int, "0x1a", "%25X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_medium_medium_width) {
  RUN_TEST(unsigned int, "0XDEAA", "%25X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_no_prefix_medium_width) {
  RUN_TEST(unsigned int, "123abc", "%25X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_long_medium_width) {
  RUN_TEST(unsigned int, "0x123456789ABCDEF", "%25X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_null_big_width) {
  RUN_TEST(unsigned int, "0x0", "%70X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_short_big_width) {
  RUN_TEST(unsigned int, "0x1a", "%70X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_medium_big_width) {
  RUN_TEST(unsigned int, "0XDEAA", "%70X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_no_prefix_big_width) {
  RUN_TEST(unsigned int, "123abc", "%70X", ck_assert_uint_eq);
}
END_TEST
START_TEST(X_hex_long_big_width) {
  RUN_TEST(unsigned int, "0x123456789ABCDEF", "%70X", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_null_no_width) {
  RUN_TEST(unsigned short, "0x0", "%hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_short_no_width) {
  RUN_TEST(unsigned short, "0x1a", "%hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_medium_no_width) {
  RUN_TEST(unsigned short, "0XDEAA", "%hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_no_prefix_no_width) {
  RUN_TEST(unsigned short, "123abc", "%hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_long_no_width) {
  RUN_TEST(unsigned short, "0x123456789ABCDEF", "%hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_null_small_width) {
  RUN_TEST(unsigned short, "0x0", "%10hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_short_small_width) {
  RUN_TEST(unsigned short, "0x1a", "%10hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_medium_small_width) {
  RUN_TEST(unsigned short, "0XDEAA", "%10hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_no_prefix_small_width) {
  RUN_TEST(unsigned short, "123abc", "%10hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_long_small_width) {
  RUN_TEST(unsigned short, "0x123456789ABCDEF", "%10hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_null_medium_width) {
  RUN_TEST(unsigned short, "0x0", "%25hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_short_medium_width) {
  RUN_TEST(unsigned short, "0x1a", "%25hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_medium_medium_width) {
  RUN_TEST(unsigned short, "0XDEAA", "%25hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_no_prefix_medium_width) {
  RUN_TEST(unsigned short, "123abc", "%25hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_long_medium_width) {
  RUN_TEST(unsigned short, "0x123456789ABCDEF", "%25hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_null_big_width) {
  RUN_TEST(unsigned short, "0x0", "%70hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_short_big_width) {
  RUN_TEST(unsigned short, "0x1a", "%70hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_medium_big_width) {
  RUN_TEST(unsigned short, "0XDEAA", "%70hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_no_prefix_big_width) {
  RUN_TEST(unsigned short, "123abc", "%70hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hx_hex_long_big_width) {
  RUN_TEST(unsigned short, "0x123456789ABCDEF", "%70hx", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_null_no_width) {
  RUN_TEST(unsigned short, "0x0", "%hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_short_no_width) {
  RUN_TEST(unsigned short, "0x1a", "%hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_medium_no_width) {
  RUN_TEST(unsigned short, "0XDEAA", "%hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_no_prefix_no_width) {
  RUN_TEST(unsigned short, "123abc", "%hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_long_no_width) {
  RUN_TEST(unsigned short, "0x123456789ABCDEF", "%hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_null_small_width) {
  RUN_TEST(unsigned short, "0x0", "%10hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_short_small_width) {
  RUN_TEST(unsigned short, "0x1a", "%10hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_medium_small_width) {
  RUN_TEST(unsigned short, "0XDEAA", "%10hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_no_prefix_small_width) {
  RUN_TEST(unsigned short, "123abc", "%10hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_long_small_width) {
  RUN_TEST(unsigned short, "0x123456789ABCDEF", "%10hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_null_medium_width) {
  RUN_TEST(unsigned short, "0x0", "%25hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_short_medium_width) {
  RUN_TEST(unsigned short, "0x1a", "%25hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_medium_medium_width) {
  RUN_TEST(unsigned short, "0XDEAA", "%25hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_no_prefix_medium_width) {
  RUN_TEST(unsigned short, "123abc", "%25hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_long_medium_width) {
  RUN_TEST(unsigned short, "0x123456789ABCDEF", "%25hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_null_big_width) {
  RUN_TEST(unsigned short, "0x0", "%70hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_short_big_width) {
  RUN_TEST(unsigned short, "0x1a", "%70hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_medium_big_width) {
  RUN_TEST(unsigned short, "0XDEAA", "%70hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_no_prefix_big_width) {
  RUN_TEST(unsigned short, "123abc", "%70hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(hX_hex_long_big_width) {
  RUN_TEST(unsigned short, "0x123456789ABCDEF", "%70hX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_null_no_width) {
  RUN_TEST(unsigned long int, "0x0", "%lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_short_no_width) {
  RUN_TEST(unsigned long int, "0x1a", "%lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_medium_no_width) {
  RUN_TEST(unsigned long int, "0XDEAA", "%lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_no_prefix_no_width) {
  RUN_TEST(unsigned long int, "123abc", "%lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_long_no_width) {
  RUN_TEST(unsigned long int, "0x123456789ABCDEF", "%lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_null_small_width) {
  RUN_TEST(unsigned long int, "0x0", "%10lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_short_small_width) {
  RUN_TEST(unsigned long int, "0x1a", "%10lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_medium_small_width) {
  RUN_TEST(unsigned long int, "0XDEAA", "%10lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_no_prefix_small_width) {
  RUN_TEST(unsigned long int, "123abc", "%10lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_long_small_width) {
  RUN_TEST(unsigned long int, "0x123456789ABCDEF", "%10lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_null_medium_width) {
  RUN_TEST(unsigned long int, "0x0", "%25lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_short_medium_width) {
  RUN_TEST(unsigned long int, "0x1a", "%25lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_medium_medium_width) {
  RUN_TEST(unsigned long int, "0XDEAA", "%25lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_no_prefix_medium_width) {
  RUN_TEST(unsigned long int, "123abc", "%25lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_long_medium_width) {
  RUN_TEST(unsigned long int, "0x123456789ABCDEF", "%25lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_null_big_width) {
  RUN_TEST(unsigned long int, "0x0", "%70lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_short_big_width) {
  RUN_TEST(unsigned long int, "0x1a", "%70lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_medium_big_width) {
  RUN_TEST(unsigned long int, "0XDEAA", "%70lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_no_prefix_big_width) {
  RUN_TEST(unsigned long int, "123abc", "%70lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lx_hex_long_big_width) {
  RUN_TEST(unsigned long int, "0x123456789ABCDEF", "%70lx", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_null_no_width) {
  RUN_TEST(unsigned long int, "0x0", "%lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_short_no_width) {
  RUN_TEST(unsigned long int, "0x1a", "%lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_medium_no_width) {
  RUN_TEST(unsigned long int, "0XDEAA", "%lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_no_prefix_no_width) {
  RUN_TEST(unsigned long int, "123abc", "%lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_long_no_width) {
  RUN_TEST(unsigned long int, "0x123456789ABCDEF", "%lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_null_small_width) {
  RUN_TEST(unsigned long int, "0x0", "%10lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_short_small_width) {
  RUN_TEST(unsigned long int, "0x1a", "%10lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_medium_small_width) {
  RUN_TEST(unsigned long int, "0XDEAA", "%10lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_no_prefix_small_width) {
  RUN_TEST(unsigned long int, "123abc", "%10lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_long_small_width) {
  RUN_TEST(unsigned long int, "0x123456789ABCDEF", "%10lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_null_medium_width) {
  RUN_TEST(unsigned long int, "0x0", "%25lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_short_medium_width) {
  RUN_TEST(unsigned long int, "0x1a", "%25lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_medium_medium_width) {
  RUN_TEST(unsigned long int, "0XDEAA", "%25lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_no_prefix_medium_width) {
  RUN_TEST(unsigned long int, "123abc", "%25lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_long_medium_width) {
  RUN_TEST(unsigned long int, "0x123456789ABCDEF", "%25lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_null_big_width) {
  RUN_TEST(unsigned long int, "0x0", "%70lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_short_big_width) {
  RUN_TEST(unsigned long int, "0x1a", "%70lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_medium_big_width) {
  RUN_TEST(unsigned long int, "0XDEAA", "%70lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_no_prefix_big_width) {
  RUN_TEST(unsigned long int, "123abc", "%70lX", ck_assert_uint_eq);
}
END_TEST
START_TEST(lX_hex_long_big_width) {
  RUN_TEST(unsigned long int, "0x123456789ABCDEF", "%70lX", ck_assert_uint_eq);
}
END_TEST

START_TEST(p_zero_ptr_no_width) {
  RUN_TEST(void*, "0x0", "%p", ck_assert_ptr_eq);
}
END_TEST
START_TEST(p_small_ptr_no_width) {
  RUN_TEST(void*, "0x1234", "%p", ck_assert_ptr_eq);
}
END_TEST
START_TEST(p_medium_ptr_no_width) {
  RUN_TEST(void*, "0xdeadbeef", "%p", ck_assert_ptr_eq);
}
END_TEST
START_TEST(p_large_ptr_no_width) {
  RUN_TEST(void*, "0x7fff12345678", "%p", ck_assert_ptr_eq);
}
END_TEST
START_TEST(p_zero_ptr_small_width) {
  RUN_TEST(void*, "0x0", "%10p", ck_assert_ptr_eq);
}
END_TEST
START_TEST(p_small_ptr_small_width) {
  RUN_TEST(void*, "0x1234", "%10p", ck_assert_ptr_eq);
}
END_TEST
START_TEST(p_medium_ptr_small_width) {
  RUN_TEST(void*, "0xdeadbeef", "%10p", ck_assert_ptr_eq);
}
END_TEST
START_TEST(p_large_ptr_small_width) {
  RUN_TEST(void*, "0x7fff12345678", "%10p", ck_assert_ptr_eq);
}
END_TEST
START_TEST(p_zero_ptr_medium_width) {
  RUN_TEST(void*, "0x0", "%25p", ck_assert_ptr_eq);
}
END_TEST
START_TEST(p_small_ptr_medium_width) {
  RUN_TEST(void*, "0x1234", "%25p", ck_assert_ptr_eq);
}
END_TEST
START_TEST(p_medium_ptr_medium_width) {
  RUN_TEST(void*, "0xdeadbeef", "%25p", ck_assert_ptr_eq);
}
END_TEST
START_TEST(p_large_ptr_medium_width) {
  RUN_TEST(void*, "0x7fff12345678", "%25p", ck_assert_ptr_eq);
}
END_TEST
START_TEST(p_zero_ptr_big_width) {
  RUN_TEST(void*, "0x0", "%70p", ck_assert_ptr_eq);
}
END_TEST
START_TEST(p_small_ptr_big_width) {
  RUN_TEST(void*, "0x1234", "%70p", ck_assert_ptr_eq);
}
END_TEST
START_TEST(p_medium_ptr_big_width) {
  RUN_TEST(void*, "0xdeadbeef", "%70p", ck_assert_ptr_eq);
}
END_TEST
START_TEST(p_large_ptr_big_width) {
  RUN_TEST(void*, "0x7fff12345678", "%70p", ck_assert_ptr_eq);
}
END_TEST

START_TEST(c_lowercase_no_width) {
  RUN_TEST(char, "a", "%c", ck_assert_int_eq);
}
END_TEST
START_TEST(c_uppercase_no_width) {
  RUN_TEST(char, "Z", "%c", ck_assert_int_eq);
}
END_TEST
START_TEST(c_digit_no_width) { RUN_TEST(char, "9", "%c", ck_assert_int_eq); }
END_TEST
START_TEST(c_symbol_no_width) { RUN_TEST(char, "@", "%c", ck_assert_int_eq); }
END_TEST
START_TEST(c_newline_no_width) { RUN_TEST(char, "\n", "%c", ck_assert_int_eq); }
END_TEST
START_TEST(c_tab_no_width) { RUN_TEST(char, "\t", "%c", ck_assert_int_eq); }
END_TEST
START_TEST(c_space_no_width) { RUN_TEST(char, " ", "%c", ck_assert_int_eq); }
END_TEST
START_TEST(c_multiple_chars_no_width) {
  RUN_TEST(char, "aaa", "%c", ck_assert_int_eq);
}
END_TEST

START_TEST(s_basic_default_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("hello", "%1023s", got_str),
                   sscanf("hello", "%1023s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_with_space_default_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("hello world", "%1023s", got_str),
                   sscanf("hello world", "%1023s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_digits_default_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("12345", "%1023s", got_str),
                   sscanf("12345", "%1023s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_multiple_spaces_default_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("a b c d e", "%1023s", got_str),
                   sscanf("a b c d e", "%1023s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_leading_spaces_default_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("  leading", "%1023s", got_str),
                   sscanf("  leading", "%1023s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_trailing_spaces_default_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("trailing  ", "%1023s", got_str),
                   sscanf("trailing  ", "%1023s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_symbols_default_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("!@#$%^&*()", "%1023s", got_str),
                   sscanf("!@#$%^&*()", "%1023s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_empty_string_default_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("", "%1023s", got_str),
                   sscanf("", "%1023s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_very_long_default_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(
      s21_sscanf("verylongstringverylongstringverylongstringverylongstring",
                 "%1023s", got_str),
      sscanf("verylongstringverylongstringverylongstringverylongstring",
             "%1023s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_only_spaces_default_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("        ", "%1023s", got_str),
                   sscanf("        ", "%1023s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_basic_small_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("hello", "%1s", got_str),
                   sscanf("hello", "%1s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_with_space_small_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("hello world", "%1s", got_str),
                   sscanf("hello world", "%1s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_digits_small_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("12345", "%1s", got_str),
                   sscanf("12345", "%1s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_multiple_spaces_small_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("a b c d e", "%1s", got_str),
                   sscanf("a b c d e", "%1s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_leading_spaces_small_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("  leading", "%1s", got_str),
                   sscanf("  leading", "%1s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_trailing_spaces_small_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("trailing  ", "%1s", got_str),
                   sscanf("trailing  ", "%1s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_symbols_small_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("!@#$%^&*()", "%1s", got_str),
                   sscanf("!@#$%^&*()", "%1s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_empty_string_small_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("", "%1s", got_str),
                   sscanf("", "%1s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_very_long_small_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(
      s21_sscanf("verylongstringverylongstringverylongstringverylongstring",
                 "%1s", got_str),
      sscanf("verylongstringverylongstringverylongstringverylongstring", "%1s",
             expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_only_spaces_small_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("        ", "%1s", got_str),
                   sscanf("        ", "%1s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_basic_medium_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("hello", "%5s", got_str),
                   sscanf("hello", "%5s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_with_space_medium_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("hello world", "%5s", got_str),
                   sscanf("hello world", "%5s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_digits_medium_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("12345", "%5s", got_str),
                   sscanf("12345", "%5s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_multiple_spaces_medium_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("a b c d e", "%5s", got_str),
                   sscanf("a b c d e", "%5s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_leading_spaces_medium_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("  leading", "%5s", got_str),
                   sscanf("  leading", "%5s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_trailing_spaces_medium_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("trailing  ", "%5s", got_str),
                   sscanf("trailing  ", "%5s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_symbols_medium_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("!@#$%^&*()", "%5s", got_str),
                   sscanf("!@#$%^&*()", "%5s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_empty_string_medium_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("", "%5s", got_str),
                   sscanf("", "%5s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_very_long_medium_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(
      s21_sscanf("verylongstringverylongstringverylongstringverylongstring",
                 "%5s", got_str),
      sscanf("verylongstringverylongstringverylongstringverylongstring", "%5s",
             expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_only_spaces_medium_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("        ", "%5s", got_str),
                   sscanf("        ", "%5s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_basic_big_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("hello", "%70s", got_str),
                   sscanf("hello", "%70s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_with_space_big_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("hello world", "%70s", got_str),
                   sscanf("hello world", "%70s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_digits_big_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("12345", "%70s", got_str),
                   sscanf("12345", "%70s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_multiple_spaces_big_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("a b c d e", "%70s", got_str),
                   sscanf("a b c d e", "%70s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_leading_spaces_big_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("  leading", "%70s", got_str),
                   sscanf("  leading", "%70s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_trailing_spaces_big_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("trailing  ", "%70s", got_str),
                   sscanf("trailing  ", "%70s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_symbols_big_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("!@#$%^&*()", "%70s", got_str),
                   sscanf("!@#$%^&*()", "%70s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_empty_string_big_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("", "%70s", got_str),
                   sscanf("", "%70s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_very_long_big_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(
      s21_sscanf("verylongstringverylongstringverylongstringverylongstring",
                 "%70s", got_str),
      sscanf("verylongstringverylongstringverylongstringverylongstring", "%70s",
             expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(s_only_spaces_big_width) {
  char got_str[1024] = "";
  char expected_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("        ", "%70s", got_str),
                   sscanf("        ", "%70s", expected_str));
  ck_assert_str_eq(got_str, expected_str);
}
END_TEST
START_TEST(ls_basic_default_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("hello", "%1023ls", got_wstr),
                   sscanf("hello", "%1023ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_with_space_default_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("hello world", "%1023ls", got_wstr),
                   sscanf("hello world", "%1023ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_digits_default_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("12345", "%1023ls", got_wstr),
                   sscanf("12345", "%1023ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_multiple_spaces_default_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("a b c d e", "%1023ls", got_wstr),
                   sscanf("a b c d e", "%1023ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_leading_spaces_default_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("  leading", "%1023ls", got_wstr),
                   sscanf("  leading", "%1023ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_trailing_spaces_default_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("trailing  ", "%1023ls", got_wstr),
                   sscanf("trailing  ", "%1023ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_symbols_default_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("!@#$%^&*()", "%1023ls", got_wstr),
                   sscanf("!@#$%^&*()", "%1023ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_empty_string_default_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("", "%1023ls", got_wstr),
                   sscanf("", "%1023ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_very_long_default_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(
      s21_sscanf("verylongstringverylongstringverylongstringverylongstring",
                 "%1023ls", got_wstr),
      sscanf("verylongstringverylongstringverylongstringverylongstring",
             "%1023ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_only_spaces_default_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("        ", "%1023ls", got_wstr),
                   sscanf("        ", "%1023ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_basic_small_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("hello", "%1ls", got_wstr),
                   sscanf("hello", "%1ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_with_space_small_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("hello world", "%1ls", got_wstr),
                   sscanf("hello world", "%1ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_digits_small_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("12345", "%1ls", got_wstr),
                   sscanf("12345", "%1ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_multiple_spaces_small_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("a b c d e", "%1ls", got_wstr),
                   sscanf("a b c d e", "%1ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_leading_spaces_small_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("  leading", "%1ls", got_wstr),
                   sscanf("  leading", "%1ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_trailing_spaces_small_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("trailing  ", "%1ls", got_wstr),
                   sscanf("trailing  ", "%1ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_symbols_small_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("!@#$%^&*()", "%1ls", got_wstr),
                   sscanf("!@#$%^&*()", "%1ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_empty_string_small_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("", "%1ls", got_wstr),
                   sscanf("", "%1ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_very_long_small_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(
      s21_sscanf("verylongstringverylongstringverylongstringverylongstring",
                 "%1ls", got_wstr),
      sscanf("verylongstringverylongstringverylongstringverylongstring", "%1ls",
             expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_only_spaces_small_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("        ", "%1ls", got_wstr),
                   sscanf("        ", "%1ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_basic_medium_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("hello", "%5ls", got_wstr),
                   sscanf("hello", "%5ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_with_space_medium_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("hello world", "%5ls", got_wstr),
                   sscanf("hello world", "%5ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_digits_medium_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("12345", "%5ls", got_wstr),
                   sscanf("12345", "%5ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_multiple_spaces_medium_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("a b c d e", "%5ls", got_wstr),
                   sscanf("a b c d e", "%5ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_leading_spaces_medium_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("  leading", "%5ls", got_wstr),
                   sscanf("  leading", "%5ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_trailing_spaces_medium_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("trailing  ", "%5ls", got_wstr),
                   sscanf("trailing  ", "%5ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_symbols_medium_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("!@#$%^&*()", "%5ls", got_wstr),
                   sscanf("!@#$%^&*()", "%5ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_empty_string_medium_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("", "%5ls", got_wstr),
                   sscanf("", "%5ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_very_long_medium_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(
      s21_sscanf("verylongstringverylongstringverylongstringverylongstring",
                 "%5ls", got_wstr),
      sscanf("verylongstringverylongstringverylongstringverylongstring", "%5ls",
             expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_only_spaces_medium_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("        ", "%5ls", got_wstr),
                   sscanf("        ", "%5ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_basic_big_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("hello", "%70ls", got_wstr),
                   sscanf("hello", "%70ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_with_space_big_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("hello world", "%70ls", got_wstr),
                   sscanf("hello world", "%70ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_digits_big_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("12345", "%70ls", got_wstr),
                   sscanf("12345", "%70ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_multiple_spaces_big_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("a b c d e", "%70ls", got_wstr),
                   sscanf("a b c d e", "%70ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_leading_spaces_big_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("  leading", "%70ls", got_wstr),
                   sscanf("  leading", "%70ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_trailing_spaces_big_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("trailing  ", "%70ls", got_wstr),
                   sscanf("trailing  ", "%70ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_symbols_big_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("!@#$%^&*()", "%70ls", got_wstr),
                   sscanf("!@#$%^&*()", "%70ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_empty_string_big_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("", "%70ls", got_wstr),
                   sscanf("", "%70ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_very_long_big_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(
      s21_sscanf("verylongstringverylongstringverylongstringverylongstring",
                 "%70ls", got_wstr),
      sscanf("verylongstringverylongstringverylongstringverylongstring",
             "%70ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST
START_TEST(ls_only_spaces_big_width) {
  wchar_t got_wstr[1024] = L"";
  wchar_t expected_wstr[1024] = L"";
  ck_assert_int_eq(s21_sscanf("        ", "%70ls", got_wstr),
                   sscanf("        ", "%70ls", expected_wstr));
  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);
}
END_TEST

START_TEST(number_in_the_start) {
  int got_var1, expected_var1;
  char got_var2, expected_var2;
  float got_var3, expected_var3;
  int got_var4, expected_var4;
  ck_assert_int_eq(s21_sscanf("Sometest w 1.234 and a bit more 1234567",
                              "%n Sometest %c %f and a bit more %d", &got_var1,
                              &got_var2, &got_var3, &got_var4),
                   sscanf("Sometest w 1.234 and a bit more 1234567",
                          "%n Sometest %c %f and a bit more %d", &expected_var1,
                          &expected_var2, &expected_var3, &expected_var4));
  ck_assert_int_eq(got_var1, expected_var1);
  ck_assert_int_eq(got_var2, expected_var2);
  ck_assert_float_eq(got_var3, expected_var3);
  ck_assert_int_eq(got_var4, expected_var4);
}
END_TEST
START_TEST(number_in_the_middle) {
  char got_var1, expected_var1;
  float got_var2, expected_var2;
  int got_var3, expected_var3;
  int got_var4, expected_var4;
  ck_assert_int_eq(s21_sscanf("Sometest w 1.234 and a bit more 1234567",
                              "Sometest %c %f %n and a bit more %d", &got_var1,
                              &got_var2, &got_var3, &got_var4),
                   sscanf("Sometest w 1.234 and a bit more 1234567",
                          "Sometest %c %f %n and a bit more %d", &expected_var1,
                          &expected_var2, &expected_var3, &expected_var4));
  ck_assert_int_eq(got_var1, expected_var1);
  ck_assert_float_eq(got_var2, expected_var2);
  ck_assert_int_eq(got_var3, expected_var3);
  ck_assert_int_eq(got_var4, expected_var4);
}
END_TEST
START_TEST(number_in_the_end) {
  char got_var1, expected_var1;
  float got_var2, expected_var2;
  int got_var3, expected_var3;
  int got_var4, expected_var4;
  ck_assert_int_eq(s21_sscanf("Sometest w 1.234 and a bit more 1234567",
                              "Sometest %c %f and a bit more %d %n", &got_var1,
                              &got_var2, &got_var3, &got_var4),
                   sscanf("Sometest w 1.234 and a bit more 1234567",
                          "Sometest %c %f and a bit more %d %n", &expected_var1,
                          &expected_var2, &expected_var3, &expected_var4));
  ck_assert_int_eq(got_var1, expected_var1);
  ck_assert_float_eq(got_var2, expected_var2);
  ck_assert_int_eq(got_var3, expected_var3);
  ck_assert_int_eq(got_var4, expected_var4);
}
END_TEST

START_TEST(percent_in_the_middle) {
  int got_var1, expected_var1;
  float got_var2, expected_var2;
  int got_var3, expected_var3;
  ck_assert_int_eq(s21_sscanf("   -123 % 1.234e-1 texttextetext 1234567",
                              "  %i %% %g texttextetext %d", &got_var1,
                              &got_var2, &got_var3),
                   sscanf("   -123 % 1.234e-1 texttextetext 1234567",
                          "  %i %% %g texttextetext %d", &expected_var1,
                          &expected_var2, &expected_var3));
  ck_assert_int_eq(got_var1, expected_var1);
  ck_assert_float_eq(got_var2, expected_var2);
  ck_assert_int_eq(got_var3, expected_var3);
}
END_TEST
START_TEST(percent_scan) {
  char got_var1, expected_var1;
  ck_assert_int_eq(s21_sscanf("%%", "%% %c", &got_var1),
                   sscanf("%%", "%% %c", &expected_var1));
  ck_assert_int_eq(got_var1, expected_var1);
}
END_TEST

START_TEST(star) {
  int got_var1, expected_var1;
  int got_var2, expected_var2;
  ck_assert_int_eq(
      s21_sscanf("123 ignore 456", "%d %*s %d", &got_var1, &got_var2),
      sscanf("123 ignore 456", "%d %*s %d", &expected_var1, &expected_var2));
  ck_assert_int_eq(got_var1, expected_var1);
  ck_assert_int_eq(got_var2, expected_var2);
}
END_TEST
START_TEST(wrong_specif) {
  char got_str[1024] = "";
  ck_assert_int_eq(s21_sscanf("a", "a %r", got_str), -1);
}
END_TEST

START_TEST(sscanf_all_specifiers) {
  char got_var1, expected_var1;
  short got_var2, expected_var2;
  long got_var3, expected_var3;
  int got_var4, expected_var4;
  float got_var5, expected_var5;
  float got_var6, expected_var6;
  float got_var7, expected_var7;
  float got_var8, expected_var8;
  long double got_var9, expected_var9;
  unsigned int got_var10, expected_var10;
  unsigned int got_var11, expected_var11;
  unsigned int got_var12, expected_var12;
  unsigned int got_var13, expected_var13;
  char got_var14, expected_var14;
  int got_var15, expected_var15;
  ck_assert_int_eq(
      s21_sscanf("A -12345 987654321 0x1a3 1.2345e6 1.2345E6 3.14159 6.022e23 "
                 "3.141592653589793238 755 4294967295 1a3b 1A3B W %",
                 "%c %hd %ld %i %e %E %f %g %Le %o %u %x %X %c %% %n",
                 &got_var1, &got_var2, &got_var3, &got_var4, &got_var5,
                 &got_var6, &got_var7, &got_var8, &got_var9, &got_var10,
                 &got_var11, &got_var12, &got_var13, &got_var14, &got_var15),
      sscanf("A -12345 987654321 0x1a3 1.2345e6 1.2345E6 3.14159 6.022e23 "
             "3.141592653589793238 755 4294967295 1a3b 1A3B W %",
             "%c %hd %ld %i %e %E %f %g %Le %o %u %x %X %c %% %n",
             &expected_var1, &expected_var2, &expected_var3, &expected_var4,
             &expected_var5, &expected_var6, &expected_var7, &expected_var8,
             &expected_var9, &expected_var10, &expected_var11, &expected_var12,
             &expected_var13, &expected_var14, &expected_var15));
  ck_assert_int_eq(got_var1, expected_var1);
  ck_assert_int_eq(got_var2, expected_var2);
  ck_assert_int_eq(got_var3, expected_var3);
  ck_assert_int_eq(got_var4, expected_var4);
  ck_assert_float_eq(got_var5, expected_var5);
  ck_assert_float_eq(got_var6, expected_var6);
  ck_assert_float_eq(got_var7, expected_var7);
  ck_assert_float_eq(got_var8, expected_var8);
  ck_assert_float_eq(got_var9, expected_var9);
  ck_assert_uint_eq(got_var10, expected_var10);
  ck_assert_uint_eq(got_var11, expected_var11);
  ck_assert_uint_eq(got_var12, expected_var12);
  ck_assert_uint_eq(got_var13, expected_var13);
  ck_assert_int_eq(got_var14, expected_var14);
  ck_assert_int_eq(got_var15, expected_var15);
}
END_TEST
Suite* suite_s21_sscanf(void) {
  Suite* suite = suite_create("s21_sscanf");
  TCase* tcase_core = tcase_create("core of s21_sscanf");

  tcase_add_test(tcase_core, f_null_no_width);
  tcase_add_test(tcase_core, f_null_neg_no_width);
  tcase_add_test(tcase_core, f_fraction_short_no_width);
  tcase_add_test(tcase_core, f_fraction_medium_no_width);
  tcase_add_test(tcase_core, f_fraction_long_no_width);
  tcase_add_test(tcase_core, f_general_short_no_width);
  tcase_add_test(tcase_core, f_general_medium_no_width);
  tcase_add_test(tcase_core, f_general_long_no_width);
  tcase_add_test(tcase_core, f_infinity_no_width);
  tcase_add_test(tcase_core, f_infinity_neg_no_width);
  tcase_add_test(tcase_core, f_null_small_width);
  tcase_add_test(tcase_core, f_null_neg_small_width);
  tcase_add_test(tcase_core, f_fraction_short_small_width);
  tcase_add_test(tcase_core, f_fraction_medium_small_width);
  tcase_add_test(tcase_core, f_fraction_long_small_width);
  tcase_add_test(tcase_core, f_general_short_small_width);
  tcase_add_test(tcase_core, f_general_medium_small_width);
  tcase_add_test(tcase_core, f_general_long_small_width);
  tcase_add_test(tcase_core, f_infinity_small_width);
  tcase_add_test(tcase_core, f_infinity_neg_small_width);
  tcase_add_test(tcase_core, f_null_medium_width);
  tcase_add_test(tcase_core, f_null_neg_medium_width);
  tcase_add_test(tcase_core, f_fraction_short_medium_width);
  tcase_add_test(tcase_core, f_fraction_medium_medium_width);
  tcase_add_test(tcase_core, f_fraction_long_medium_width);
  tcase_add_test(tcase_core, f_general_short_medium_width);
  tcase_add_test(tcase_core, f_general_medium_medium_width);
  tcase_add_test(tcase_core, f_general_long_medium_width);
  tcase_add_test(tcase_core, f_infinity_medium_width);
  tcase_add_test(tcase_core, f_infinity_neg_medium_width);
  tcase_add_test(tcase_core, f_null_big_width);
  tcase_add_test(tcase_core, f_null_neg_big_width);
  tcase_add_test(tcase_core, f_fraction_short_big_width);
  tcase_add_test(tcase_core, f_fraction_medium_big_width);
  tcase_add_test(tcase_core, f_fraction_long_big_width);
  tcase_add_test(tcase_core, f_general_short_big_width);
  tcase_add_test(tcase_core, f_general_medium_big_width);
  tcase_add_test(tcase_core, f_general_long_big_width);
  tcase_add_test(tcase_core, f_infinity_big_width);
  tcase_add_test(tcase_core, f_infinity_neg_big_width);
  tcase_add_test(tcase_core, lf_null_no_width);
  tcase_add_test(tcase_core, lf_null_neg_no_width);
  tcase_add_test(tcase_core, lf_fraction_short_no_width);
  tcase_add_test(tcase_core, lf_fraction_medium_no_width);
  tcase_add_test(tcase_core, lf_fraction_long_no_width);
  tcase_add_test(tcase_core, lf_general_short_no_width);
  tcase_add_test(tcase_core, lf_general_medium_no_width);
  tcase_add_test(tcase_core, lf_general_long_no_width);
  tcase_add_test(tcase_core, lf_infinity_no_width);
  tcase_add_test(tcase_core, lf_infinity_neg_no_width);
  tcase_add_test(tcase_core, lf_null_small_width);
  tcase_add_test(tcase_core, lf_null_neg_small_width);
  tcase_add_test(tcase_core, lf_fraction_short_small_width);
  tcase_add_test(tcase_core, lf_fraction_medium_small_width);
  tcase_add_test(tcase_core, lf_fraction_long_small_width);
  tcase_add_test(tcase_core, lf_general_short_small_width);
  tcase_add_test(tcase_core, lf_general_medium_small_width);
  tcase_add_test(tcase_core, lf_general_long_small_width);
  tcase_add_test(tcase_core, lf_infinity_small_width);
  tcase_add_test(tcase_core, lf_infinity_neg_small_width);
  tcase_add_test(tcase_core, lf_null_medium_width);
  tcase_add_test(tcase_core, lf_null_neg_medium_width);
  tcase_add_test(tcase_core, lf_fraction_short_medium_width);
  tcase_add_test(tcase_core, lf_fraction_medium_medium_width);
  tcase_add_test(tcase_core, lf_fraction_long_medium_width);
  tcase_add_test(tcase_core, lf_general_short_medium_width);
  tcase_add_test(tcase_core, lf_general_medium_medium_width);
  tcase_add_test(tcase_core, lf_general_long_medium_width);
  tcase_add_test(tcase_core, lf_infinity_medium_width);
  tcase_add_test(tcase_core, lf_infinity_neg_medium_width);
  tcase_add_test(tcase_core, lf_null_big_width);
  tcase_add_test(tcase_core, lf_null_neg_big_width);
  tcase_add_test(tcase_core, lf_fraction_short_big_width);
  tcase_add_test(tcase_core, lf_fraction_medium_big_width);
  tcase_add_test(tcase_core, lf_fraction_long_big_width);
  tcase_add_test(tcase_core, lf_general_short_big_width);
  tcase_add_test(tcase_core, lf_general_medium_big_width);
  tcase_add_test(tcase_core, lf_general_long_big_width);
  tcase_add_test(tcase_core, lf_infinity_big_width);
  tcase_add_test(tcase_core, lf_infinity_neg_big_width);
  tcase_add_test(tcase_core, Lf_null_no_width);
  tcase_add_test(tcase_core, Lf_null_neg_no_width);
  tcase_add_test(tcase_core, Lf_fraction_short_no_width);
  tcase_add_test(tcase_core, Lf_fraction_medium_no_width);
  tcase_add_test(tcase_core, Lf_fraction_long_no_width);
  tcase_add_test(tcase_core, Lf_general_short_no_width);
  tcase_add_test(tcase_core, Lf_general_medium_no_width);
  tcase_add_test(tcase_core, Lf_general_long_no_width);
  tcase_add_test(tcase_core, Lf_infinity_no_width);
  tcase_add_test(tcase_core, Lf_infinity_neg_no_width);
  tcase_add_test(tcase_core, Lf_null_small_width);
  tcase_add_test(tcase_core, Lf_null_neg_small_width);
  tcase_add_test(tcase_core, Lf_fraction_short_small_width);
  tcase_add_test(tcase_core, Lf_fraction_medium_small_width);
  tcase_add_test(tcase_core, Lf_fraction_long_small_width);
  tcase_add_test(tcase_core, Lf_general_short_small_width);
  tcase_add_test(tcase_core, Lf_general_medium_small_width);
  tcase_add_test(tcase_core, Lf_general_long_small_width);
  tcase_add_test(tcase_core, Lf_infinity_small_width);
  tcase_add_test(tcase_core, Lf_infinity_neg_small_width);
  tcase_add_test(tcase_core, Lf_null_medium_width);
  tcase_add_test(tcase_core, Lf_null_neg_medium_width);
  tcase_add_test(tcase_core, Lf_fraction_short_medium_width);
  tcase_add_test(tcase_core, Lf_fraction_medium_medium_width);
  tcase_add_test(tcase_core, Lf_fraction_long_medium_width);
  tcase_add_test(tcase_core, Lf_general_short_medium_width);
  tcase_add_test(tcase_core, Lf_general_medium_medium_width);
  tcase_add_test(tcase_core, Lf_general_long_medium_width);
  tcase_add_test(tcase_core, Lf_infinity_medium_width);
  tcase_add_test(tcase_core, Lf_infinity_neg_medium_width);
  tcase_add_test(tcase_core, Lf_null_big_width);
  tcase_add_test(tcase_core, Lf_null_neg_big_width);
  tcase_add_test(tcase_core, Lf_fraction_short_big_width);
  tcase_add_test(tcase_core, Lf_fraction_medium_big_width);
  tcase_add_test(tcase_core, Lf_fraction_long_big_width);
  tcase_add_test(tcase_core, Lf_general_short_big_width);
  tcase_add_test(tcase_core, Lf_general_medium_big_width);
  tcase_add_test(tcase_core, Lf_general_long_big_width);
  tcase_add_test(tcase_core, Lf_infinity_big_width);
  tcase_add_test(tcase_core, Lf_infinity_neg_big_width);
  tcase_add_test(tcase_core, e_null_no_width);
  tcase_add_test(tcase_core, e_null_neg_no_width);
  tcase_add_test(tcase_core, e_fraction_short_no_width);
  tcase_add_test(tcase_core, e_fraction_medium_no_width);
  tcase_add_test(tcase_core, e_fraction_long_no_width);
  tcase_add_test(tcase_core, e_general_short_no_width);
  tcase_add_test(tcase_core, e_general_medium_no_width);
  tcase_add_test(tcase_core, e_general_long_no_width);
  tcase_add_test(tcase_core, e_infinity_no_width);
  tcase_add_test(tcase_core, e_infinity_neg_no_width);
  tcase_add_test(tcase_core, e_null_small_width);
  tcase_add_test(tcase_core, e_null_neg_small_width);
  tcase_add_test(tcase_core, e_fraction_short_small_width);
  tcase_add_test(tcase_core, e_fraction_medium_small_width);
  tcase_add_test(tcase_core, e_fraction_long_small_width);
  tcase_add_test(tcase_core, e_general_short_small_width);
  tcase_add_test(tcase_core, e_general_medium_small_width);
  tcase_add_test(tcase_core, e_general_long_small_width);
  tcase_add_test(tcase_core, e_infinity_small_width);
  tcase_add_test(tcase_core, e_infinity_neg_small_width);
  tcase_add_test(tcase_core, e_null_medium_width);
  tcase_add_test(tcase_core, e_null_neg_medium_width);
  tcase_add_test(tcase_core, e_fraction_short_medium_width);
  tcase_add_test(tcase_core, e_fraction_medium_medium_width);
  tcase_add_test(tcase_core, e_fraction_long_medium_width);
  tcase_add_test(tcase_core, e_general_short_medium_width);
  tcase_add_test(tcase_core, e_general_medium_medium_width);
  tcase_add_test(tcase_core, e_general_long_medium_width);
  tcase_add_test(tcase_core, e_infinity_medium_width);
  tcase_add_test(tcase_core, e_infinity_neg_medium_width);
  tcase_add_test(tcase_core, e_null_big_width);
  tcase_add_test(tcase_core, e_null_neg_big_width);
  tcase_add_test(tcase_core, e_fraction_short_big_width);
  tcase_add_test(tcase_core, e_fraction_medium_big_width);
  tcase_add_test(tcase_core, e_fraction_long_big_width);
  tcase_add_test(tcase_core, e_general_short_big_width);
  tcase_add_test(tcase_core, e_general_medium_big_width);
  tcase_add_test(tcase_core, e_general_long_big_width);
  tcase_add_test(tcase_core, e_infinity_big_width);
  tcase_add_test(tcase_core, e_infinity_neg_big_width);
  tcase_add_test(tcase_core, E_null_no_width);
  tcase_add_test(tcase_core, E_null_neg_no_width);
  tcase_add_test(tcase_core, E_fraction_short_no_width);
  tcase_add_test(tcase_core, E_fraction_medium_no_width);
  tcase_add_test(tcase_core, E_fraction_long_no_width);
  tcase_add_test(tcase_core, E_general_short_no_width);
  tcase_add_test(tcase_core, E_general_medium_no_width);
  tcase_add_test(tcase_core, E_general_long_no_width);
  tcase_add_test(tcase_core, E_infinity_no_width);
  tcase_add_test(tcase_core, E_infinity_neg_no_width);
  tcase_add_test(tcase_core, E_null_small_width);
  tcase_add_test(tcase_core, E_null_neg_small_width);
  tcase_add_test(tcase_core, E_fraction_short_small_width);
  tcase_add_test(tcase_core, E_fraction_medium_small_width);
  tcase_add_test(tcase_core, E_fraction_long_small_width);
  tcase_add_test(tcase_core, E_general_short_small_width);
  tcase_add_test(tcase_core, E_general_medium_small_width);
  tcase_add_test(tcase_core, E_general_long_small_width);
  tcase_add_test(tcase_core, E_infinity_small_width);
  tcase_add_test(tcase_core, E_infinity_neg_small_width);
  tcase_add_test(tcase_core, E_null_medium_width);
  tcase_add_test(tcase_core, E_null_neg_medium_width);
  tcase_add_test(tcase_core, E_fraction_short_medium_width);
  tcase_add_test(tcase_core, E_fraction_medium_medium_width);
  tcase_add_test(tcase_core, E_fraction_long_medium_width);
  tcase_add_test(tcase_core, E_general_short_medium_width);
  tcase_add_test(tcase_core, E_general_medium_medium_width);
  tcase_add_test(tcase_core, E_general_long_medium_width);
  tcase_add_test(tcase_core, E_infinity_medium_width);
  tcase_add_test(tcase_core, E_infinity_neg_medium_width);
  tcase_add_test(tcase_core, E_null_big_width);
  tcase_add_test(tcase_core, E_null_neg_big_width);
  tcase_add_test(tcase_core, E_fraction_short_big_width);
  tcase_add_test(tcase_core, E_fraction_medium_big_width);
  tcase_add_test(tcase_core, E_fraction_long_big_width);
  tcase_add_test(tcase_core, E_general_short_big_width);
  tcase_add_test(tcase_core, E_general_medium_big_width);
  tcase_add_test(tcase_core, E_general_long_big_width);
  tcase_add_test(tcase_core, E_infinity_big_width);
  tcase_add_test(tcase_core, E_infinity_neg_big_width);
  tcase_add_test(tcase_core, le_null_no_width);
  tcase_add_test(tcase_core, le_null_neg_no_width);
  tcase_add_test(tcase_core, le_fraction_short_no_width);
  tcase_add_test(tcase_core, le_fraction_medium_no_width);
  tcase_add_test(tcase_core, le_fraction_long_no_width);
  tcase_add_test(tcase_core, le_general_short_no_width);
  tcase_add_test(tcase_core, le_general_medium_no_width);
  tcase_add_test(tcase_core, le_general_long_no_width);
  tcase_add_test(tcase_core, le_infinity_no_width);
  tcase_add_test(tcase_core, le_infinity_neg_no_width);
  tcase_add_test(tcase_core, le_null_small_width);
  tcase_add_test(tcase_core, le_null_neg_small_width);
  tcase_add_test(tcase_core, le_fraction_short_small_width);
  tcase_add_test(tcase_core, le_fraction_medium_small_width);
  tcase_add_test(tcase_core, le_fraction_long_small_width);
  tcase_add_test(tcase_core, le_general_short_small_width);
  tcase_add_test(tcase_core, le_general_medium_small_width);
  tcase_add_test(tcase_core, le_general_long_small_width);
  tcase_add_test(tcase_core, le_infinity_small_width);
  tcase_add_test(tcase_core, le_infinity_neg_small_width);
  tcase_add_test(tcase_core, le_null_medium_width);
  tcase_add_test(tcase_core, le_null_neg_medium_width);
  tcase_add_test(tcase_core, le_fraction_short_medium_width);
  tcase_add_test(tcase_core, le_fraction_medium_medium_width);
  tcase_add_test(tcase_core, le_fraction_long_medium_width);
  tcase_add_test(tcase_core, le_general_short_medium_width);
  tcase_add_test(tcase_core, le_general_medium_medium_width);
  tcase_add_test(tcase_core, le_general_long_medium_width);
  tcase_add_test(tcase_core, le_infinity_medium_width);
  tcase_add_test(tcase_core, le_infinity_neg_medium_width);
  tcase_add_test(tcase_core, le_null_big_width);
  tcase_add_test(tcase_core, le_null_neg_big_width);
  tcase_add_test(tcase_core, le_fraction_short_big_width);
  tcase_add_test(tcase_core, le_fraction_medium_big_width);
  tcase_add_test(tcase_core, le_fraction_long_big_width);
  tcase_add_test(tcase_core, le_general_short_big_width);
  tcase_add_test(tcase_core, le_general_medium_big_width);
  tcase_add_test(tcase_core, le_general_long_big_width);
  tcase_add_test(tcase_core, le_infinity_big_width);
  tcase_add_test(tcase_core, le_infinity_neg_big_width);
  tcase_add_test(tcase_core, lE_null_no_width);
  tcase_add_test(tcase_core, lE_null_neg_no_width);
  tcase_add_test(tcase_core, lE_fraction_short_no_width);
  tcase_add_test(tcase_core, lE_fraction_medium_no_width);
  tcase_add_test(tcase_core, lE_fraction_long_no_width);
  tcase_add_test(tcase_core, lE_general_short_no_width);
  tcase_add_test(tcase_core, lE_general_medium_no_width);
  tcase_add_test(tcase_core, lE_general_long_no_width);
  tcase_add_test(tcase_core, lE_infinity_no_width);
  tcase_add_test(tcase_core, lE_infinity_neg_no_width);
  tcase_add_test(tcase_core, lE_null_small_width);
  tcase_add_test(tcase_core, lE_null_neg_small_width);
  tcase_add_test(tcase_core, lE_fraction_short_small_width);
  tcase_add_test(tcase_core, lE_fraction_medium_small_width);
  tcase_add_test(tcase_core, lE_fraction_long_small_width);
  tcase_add_test(tcase_core, lE_general_short_small_width);
  tcase_add_test(tcase_core, lE_general_medium_small_width);
  tcase_add_test(tcase_core, lE_general_long_small_width);
  tcase_add_test(tcase_core, lE_infinity_small_width);
  tcase_add_test(tcase_core, lE_infinity_neg_small_width);
  tcase_add_test(tcase_core, lE_null_medium_width);
  tcase_add_test(tcase_core, lE_null_neg_medium_width);
  tcase_add_test(tcase_core, lE_fraction_short_medium_width);
  tcase_add_test(tcase_core, lE_fraction_medium_medium_width);
  tcase_add_test(tcase_core, lE_fraction_long_medium_width);
  tcase_add_test(tcase_core, lE_general_short_medium_width);
  tcase_add_test(tcase_core, lE_general_medium_medium_width);
  tcase_add_test(tcase_core, lE_general_long_medium_width);
  tcase_add_test(tcase_core, lE_infinity_medium_width);
  tcase_add_test(tcase_core, lE_infinity_neg_medium_width);
  tcase_add_test(tcase_core, lE_null_big_width);
  tcase_add_test(tcase_core, lE_null_neg_big_width);
  tcase_add_test(tcase_core, lE_fraction_short_big_width);
  tcase_add_test(tcase_core, lE_fraction_medium_big_width);
  tcase_add_test(tcase_core, lE_fraction_long_big_width);
  tcase_add_test(tcase_core, lE_general_short_big_width);
  tcase_add_test(tcase_core, lE_general_medium_big_width);
  tcase_add_test(tcase_core, lE_general_long_big_width);
  tcase_add_test(tcase_core, lE_infinity_big_width);
  tcase_add_test(tcase_core, lE_infinity_neg_big_width);
  tcase_add_test(tcase_core, Le_null_no_width);
  tcase_add_test(tcase_core, Le_null_neg_no_width);
  tcase_add_test(tcase_core, Le_fraction_short_no_width);
  tcase_add_test(tcase_core, Le_fraction_medium_no_width);
  tcase_add_test(tcase_core, Le_fraction_long_no_width);
  tcase_add_test(tcase_core, Le_general_short_no_width);
  tcase_add_test(tcase_core, Le_general_medium_no_width);
  tcase_add_test(tcase_core, Le_general_long_no_width);
  tcase_add_test(tcase_core, Le_infinity_no_width);
  tcase_add_test(tcase_core, Le_infinity_neg_no_width);
  tcase_add_test(tcase_core, Le_null_small_width);
  tcase_add_test(tcase_core, Le_null_neg_small_width);
  tcase_add_test(tcase_core, Le_fraction_short_small_width);
  tcase_add_test(tcase_core, Le_fraction_medium_small_width);
  tcase_add_test(tcase_core, Le_fraction_long_small_width);
  tcase_add_test(tcase_core, Le_general_short_small_width);
  tcase_add_test(tcase_core, Le_general_medium_small_width);
  tcase_add_test(tcase_core, Le_general_long_small_width);
  tcase_add_test(tcase_core, Le_infinity_small_width);
  tcase_add_test(tcase_core, Le_infinity_neg_small_width);
  tcase_add_test(tcase_core, Le_null_medium_width);
  tcase_add_test(tcase_core, Le_null_neg_medium_width);
  tcase_add_test(tcase_core, Le_fraction_short_medium_width);
  tcase_add_test(tcase_core, Le_fraction_medium_medium_width);
  tcase_add_test(tcase_core, Le_fraction_long_medium_width);
  tcase_add_test(tcase_core, Le_general_short_medium_width);
  tcase_add_test(tcase_core, Le_general_medium_medium_width);
  tcase_add_test(tcase_core, Le_general_long_medium_width);
  tcase_add_test(tcase_core, Le_infinity_medium_width);
  tcase_add_test(tcase_core, Le_infinity_neg_medium_width);
  tcase_add_test(tcase_core, Le_null_big_width);
  tcase_add_test(tcase_core, Le_null_neg_big_width);
  tcase_add_test(tcase_core, Le_fraction_short_big_width);
  tcase_add_test(tcase_core, Le_fraction_medium_big_width);
  tcase_add_test(tcase_core, Le_fraction_long_big_width);
  tcase_add_test(tcase_core, Le_general_short_big_width);
  tcase_add_test(tcase_core, Le_general_medium_big_width);
  tcase_add_test(tcase_core, Le_general_long_big_width);
  tcase_add_test(tcase_core, Le_infinity_big_width);
  tcase_add_test(tcase_core, Le_infinity_neg_big_width);
  tcase_add_test(tcase_core, LE_null_no_width);
  tcase_add_test(tcase_core, LE_null_neg_no_width);
  tcase_add_test(tcase_core, LE_fraction_short_no_width);
  tcase_add_test(tcase_core, LE_fraction_medium_no_width);
  tcase_add_test(tcase_core, LE_fraction_long_no_width);
  tcase_add_test(tcase_core, LE_general_short_no_width);
  tcase_add_test(tcase_core, LE_general_medium_no_width);
  tcase_add_test(tcase_core, LE_general_long_no_width);
  tcase_add_test(tcase_core, LE_infinity_no_width);
  tcase_add_test(tcase_core, LE_infinity_neg_no_width);
  tcase_add_test(tcase_core, LE_null_small_width);
  tcase_add_test(tcase_core, LE_null_neg_small_width);
  tcase_add_test(tcase_core, LE_fraction_short_small_width);
  tcase_add_test(tcase_core, LE_fraction_medium_small_width);
  tcase_add_test(tcase_core, LE_fraction_long_small_width);
  tcase_add_test(tcase_core, LE_general_short_small_width);
  tcase_add_test(tcase_core, LE_general_medium_small_width);
  tcase_add_test(tcase_core, LE_general_long_small_width);
  tcase_add_test(tcase_core, LE_infinity_small_width);
  tcase_add_test(tcase_core, LE_infinity_neg_small_width);
  tcase_add_test(tcase_core, LE_null_medium_width);
  tcase_add_test(tcase_core, LE_null_neg_medium_width);
  tcase_add_test(tcase_core, LE_fraction_short_medium_width);
  tcase_add_test(tcase_core, LE_fraction_medium_medium_width);
  tcase_add_test(tcase_core, LE_fraction_long_medium_width);
  tcase_add_test(tcase_core, LE_general_short_medium_width);
  tcase_add_test(tcase_core, LE_general_medium_medium_width);
  tcase_add_test(tcase_core, LE_general_long_medium_width);
  tcase_add_test(tcase_core, LE_infinity_medium_width);
  tcase_add_test(tcase_core, LE_infinity_neg_medium_width);
  tcase_add_test(tcase_core, LE_null_big_width);
  tcase_add_test(tcase_core, LE_null_neg_big_width);
  tcase_add_test(tcase_core, LE_fraction_short_big_width);
  tcase_add_test(tcase_core, LE_fraction_medium_big_width);
  tcase_add_test(tcase_core, LE_fraction_long_big_width);
  tcase_add_test(tcase_core, LE_general_short_big_width);
  tcase_add_test(tcase_core, LE_general_medium_big_width);
  tcase_add_test(tcase_core, LE_general_long_big_width);
  tcase_add_test(tcase_core, LE_infinity_big_width);
  tcase_add_test(tcase_core, LE_infinity_neg_big_width);
  tcase_add_test(tcase_core, g_null_no_width);
  tcase_add_test(tcase_core, g_null_neg_no_width);
  tcase_add_test(tcase_core, g_fraction_short_no_width);
  tcase_add_test(tcase_core, g_fraction_medium_no_width);
  tcase_add_test(tcase_core, g_fraction_long_no_width);
  tcase_add_test(tcase_core, g_general_short_no_width);
  tcase_add_test(tcase_core, g_general_medium_no_width);
  tcase_add_test(tcase_core, g_general_long_no_width);
  tcase_add_test(tcase_core, g_infinity_no_width);
  tcase_add_test(tcase_core, g_infinity_neg_no_width);
  tcase_add_test(tcase_core, g_null_small_width);
  tcase_add_test(tcase_core, g_null_neg_small_width);
  tcase_add_test(tcase_core, g_fraction_short_small_width);
  tcase_add_test(tcase_core, g_fraction_medium_small_width);
  tcase_add_test(tcase_core, g_fraction_long_small_width);
  tcase_add_test(tcase_core, g_general_short_small_width);
  tcase_add_test(tcase_core, g_general_medium_small_width);
  tcase_add_test(tcase_core, g_general_long_small_width);
  tcase_add_test(tcase_core, g_infinity_small_width);
  tcase_add_test(tcase_core, g_infinity_neg_small_width);
  tcase_add_test(tcase_core, g_null_medium_width);
  tcase_add_test(tcase_core, g_null_neg_medium_width);
  tcase_add_test(tcase_core, g_fraction_short_medium_width);
  tcase_add_test(tcase_core, g_fraction_medium_medium_width);
  tcase_add_test(tcase_core, g_fraction_long_medium_width);
  tcase_add_test(tcase_core, g_general_short_medium_width);
  tcase_add_test(tcase_core, g_general_medium_medium_width);
  tcase_add_test(tcase_core, g_general_long_medium_width);
  tcase_add_test(tcase_core, g_infinity_medium_width);
  tcase_add_test(tcase_core, g_infinity_neg_medium_width);
  tcase_add_test(tcase_core, g_null_big_width);
  tcase_add_test(tcase_core, g_null_neg_big_width);
  tcase_add_test(tcase_core, g_fraction_short_big_width);
  tcase_add_test(tcase_core, g_fraction_medium_big_width);
  tcase_add_test(tcase_core, g_fraction_long_big_width);
  tcase_add_test(tcase_core, g_general_short_big_width);
  tcase_add_test(tcase_core, g_general_medium_big_width);
  tcase_add_test(tcase_core, g_general_long_big_width);
  tcase_add_test(tcase_core, g_infinity_big_width);
  tcase_add_test(tcase_core, g_infinity_neg_big_width);
  tcase_add_test(tcase_core, G_null_no_width);
  tcase_add_test(tcase_core, G_null_neg_no_width);
  tcase_add_test(tcase_core, G_fraction_short_no_width);
  tcase_add_test(tcase_core, G_fraction_medium_no_width);
  tcase_add_test(tcase_core, G_fraction_long_no_width);
  tcase_add_test(tcase_core, G_general_short_no_width);
  tcase_add_test(tcase_core, G_general_medium_no_width);
  tcase_add_test(tcase_core, G_general_long_no_width);
  tcase_add_test(tcase_core, G_infinity_no_width);
  tcase_add_test(tcase_core, G_infinity_neg_no_width);
  tcase_add_test(tcase_core, G_null_small_width);
  tcase_add_test(tcase_core, G_null_neg_small_width);
  tcase_add_test(tcase_core, G_fraction_short_small_width);
  tcase_add_test(tcase_core, G_fraction_medium_small_width);
  tcase_add_test(tcase_core, G_fraction_long_small_width);
  tcase_add_test(tcase_core, G_general_short_small_width);
  tcase_add_test(tcase_core, G_general_medium_small_width);
  tcase_add_test(tcase_core, G_general_long_small_width);
  tcase_add_test(tcase_core, G_infinity_small_width);
  tcase_add_test(tcase_core, G_infinity_neg_small_width);
  tcase_add_test(tcase_core, G_null_medium_width);
  tcase_add_test(tcase_core, G_null_neg_medium_width);
  tcase_add_test(tcase_core, G_fraction_short_medium_width);
  tcase_add_test(tcase_core, G_fraction_medium_medium_width);
  tcase_add_test(tcase_core, G_fraction_long_medium_width);
  tcase_add_test(tcase_core, G_general_short_medium_width);
  tcase_add_test(tcase_core, G_general_medium_medium_width);
  tcase_add_test(tcase_core, G_general_long_medium_width);
  tcase_add_test(tcase_core, G_infinity_medium_width);
  tcase_add_test(tcase_core, G_infinity_neg_medium_width);
  tcase_add_test(tcase_core, G_null_big_width);
  tcase_add_test(tcase_core, G_null_neg_big_width);
  tcase_add_test(tcase_core, G_fraction_short_big_width);
  tcase_add_test(tcase_core, G_fraction_medium_big_width);
  tcase_add_test(tcase_core, G_fraction_long_big_width);
  tcase_add_test(tcase_core, G_general_short_big_width);
  tcase_add_test(tcase_core, G_general_medium_big_width);
  tcase_add_test(tcase_core, G_general_long_big_width);
  tcase_add_test(tcase_core, G_infinity_big_width);
  tcase_add_test(tcase_core, G_infinity_neg_big_width);
  tcase_add_test(tcase_core, lg_null_no_width);
  tcase_add_test(tcase_core, lg_null_neg_no_width);
  tcase_add_test(tcase_core, lg_fraction_short_no_width);
  tcase_add_test(tcase_core, lg_fraction_medium_no_width);
  tcase_add_test(tcase_core, lg_fraction_long_no_width);
  tcase_add_test(tcase_core, lg_general_short_no_width);
  tcase_add_test(tcase_core, lg_general_medium_no_width);
  tcase_add_test(tcase_core, lg_general_long_no_width);
  tcase_add_test(tcase_core, lg_infinity_no_width);
  tcase_add_test(tcase_core, lg_infinity_neg_no_width);
  tcase_add_test(tcase_core, lg_null_small_width);
  tcase_add_test(tcase_core, lg_null_neg_small_width);
  tcase_add_test(tcase_core, lg_fraction_short_small_width);
  tcase_add_test(tcase_core, lg_fraction_medium_small_width);
  tcase_add_test(tcase_core, lg_fraction_long_small_width);
  tcase_add_test(tcase_core, lg_general_short_small_width);
  tcase_add_test(tcase_core, lg_general_medium_small_width);
  tcase_add_test(tcase_core, lg_general_long_small_width);
  tcase_add_test(tcase_core, lg_infinity_small_width);
  tcase_add_test(tcase_core, lg_infinity_neg_small_width);
  tcase_add_test(tcase_core, lg_null_medium_width);
  tcase_add_test(tcase_core, lg_null_neg_medium_width);
  tcase_add_test(tcase_core, lg_fraction_short_medium_width);
  tcase_add_test(tcase_core, lg_fraction_medium_medium_width);
  tcase_add_test(tcase_core, lg_fraction_long_medium_width);
  tcase_add_test(tcase_core, lg_general_short_medium_width);
  tcase_add_test(tcase_core, lg_general_medium_medium_width);
  tcase_add_test(tcase_core, lg_general_long_medium_width);
  tcase_add_test(tcase_core, lg_infinity_medium_width);
  tcase_add_test(tcase_core, lg_infinity_neg_medium_width);
  tcase_add_test(tcase_core, lg_null_big_width);
  tcase_add_test(tcase_core, lg_null_neg_big_width);
  tcase_add_test(tcase_core, lg_fraction_short_big_width);
  tcase_add_test(tcase_core, lg_fraction_medium_big_width);
  tcase_add_test(tcase_core, lg_fraction_long_big_width);
  tcase_add_test(tcase_core, lg_general_short_big_width);
  tcase_add_test(tcase_core, lg_general_medium_big_width);
  tcase_add_test(tcase_core, lg_general_long_big_width);
  tcase_add_test(tcase_core, lg_infinity_big_width);
  tcase_add_test(tcase_core, lg_infinity_neg_big_width);
  tcase_add_test(tcase_core, lG_null_no_width);
  tcase_add_test(tcase_core, lG_null_neg_no_width);
  tcase_add_test(tcase_core, lG_fraction_short_no_width);
  tcase_add_test(tcase_core, lG_fraction_medium_no_width);
  tcase_add_test(tcase_core, lG_fraction_long_no_width);
  tcase_add_test(tcase_core, lG_general_short_no_width);
  tcase_add_test(tcase_core, lG_general_medium_no_width);
  tcase_add_test(tcase_core, lG_general_long_no_width);
  tcase_add_test(tcase_core, lG_infinity_no_width);
  tcase_add_test(tcase_core, lG_infinity_neg_no_width);
  tcase_add_test(tcase_core, lG_null_small_width);
  tcase_add_test(tcase_core, lG_null_neg_small_width);
  tcase_add_test(tcase_core, lG_fraction_short_small_width);
  tcase_add_test(tcase_core, lG_fraction_medium_small_width);
  tcase_add_test(tcase_core, lG_fraction_long_small_width);
  tcase_add_test(tcase_core, lG_general_short_small_width);
  tcase_add_test(tcase_core, lG_general_medium_small_width);
  tcase_add_test(tcase_core, lG_general_long_small_width);
  tcase_add_test(tcase_core, lG_infinity_small_width);
  tcase_add_test(tcase_core, lG_infinity_neg_small_width);
  tcase_add_test(tcase_core, lG_null_medium_width);
  tcase_add_test(tcase_core, lG_null_neg_medium_width);
  tcase_add_test(tcase_core, lG_fraction_short_medium_width);
  tcase_add_test(tcase_core, lG_fraction_medium_medium_width);
  tcase_add_test(tcase_core, lG_fraction_long_medium_width);
  tcase_add_test(tcase_core, lG_general_short_medium_width);
  tcase_add_test(tcase_core, lG_general_medium_medium_width);
  tcase_add_test(tcase_core, lG_general_long_medium_width);
  tcase_add_test(tcase_core, lG_infinity_medium_width);
  tcase_add_test(tcase_core, lG_infinity_neg_medium_width);
  tcase_add_test(tcase_core, lG_null_big_width);
  tcase_add_test(tcase_core, lG_null_neg_big_width);
  tcase_add_test(tcase_core, lG_fraction_short_big_width);
  tcase_add_test(tcase_core, lG_fraction_medium_big_width);
  tcase_add_test(tcase_core, lG_fraction_long_big_width);
  tcase_add_test(tcase_core, lG_general_short_big_width);
  tcase_add_test(tcase_core, lG_general_medium_big_width);
  tcase_add_test(tcase_core, lG_general_long_big_width);
  tcase_add_test(tcase_core, lG_infinity_big_width);
  tcase_add_test(tcase_core, lG_infinity_neg_big_width);
  tcase_add_test(tcase_core, Lg_null_no_width);
  tcase_add_test(tcase_core, Lg_null_neg_no_width);
  tcase_add_test(tcase_core, Lg_fraction_short_no_width);
  tcase_add_test(tcase_core, Lg_fraction_medium_no_width);
  tcase_add_test(tcase_core, Lg_fraction_long_no_width);
  tcase_add_test(tcase_core, Lg_general_short_no_width);
  tcase_add_test(tcase_core, Lg_general_medium_no_width);
  tcase_add_test(tcase_core, Lg_general_long_no_width);
  tcase_add_test(tcase_core, Lg_infinity_no_width);
  tcase_add_test(tcase_core, Lg_infinity_neg_no_width);
  tcase_add_test(tcase_core, Lg_null_small_width);
  tcase_add_test(tcase_core, Lg_null_neg_small_width);
  tcase_add_test(tcase_core, Lg_fraction_short_small_width);
  tcase_add_test(tcase_core, Lg_fraction_medium_small_width);
  tcase_add_test(tcase_core, Lg_fraction_long_small_width);
  tcase_add_test(tcase_core, Lg_general_short_small_width);
  tcase_add_test(tcase_core, Lg_general_medium_small_width);
  tcase_add_test(tcase_core, Lg_general_long_small_width);
  tcase_add_test(tcase_core, Lg_infinity_small_width);
  tcase_add_test(tcase_core, Lg_infinity_neg_small_width);
  tcase_add_test(tcase_core, Lg_null_medium_width);
  tcase_add_test(tcase_core, Lg_null_neg_medium_width);
  tcase_add_test(tcase_core, Lg_fraction_short_medium_width);
  tcase_add_test(tcase_core, Lg_fraction_medium_medium_width);
  tcase_add_test(tcase_core, Lg_fraction_long_medium_width);
  tcase_add_test(tcase_core, Lg_general_short_medium_width);
  tcase_add_test(tcase_core, Lg_general_medium_medium_width);
  tcase_add_test(tcase_core, Lg_general_long_medium_width);
  tcase_add_test(tcase_core, Lg_infinity_medium_width);
  tcase_add_test(tcase_core, Lg_infinity_neg_medium_width);
  tcase_add_test(tcase_core, Lg_null_big_width);
  tcase_add_test(tcase_core, Lg_null_neg_big_width);
  tcase_add_test(tcase_core, Lg_fraction_short_big_width);
  tcase_add_test(tcase_core, Lg_fraction_medium_big_width);
  tcase_add_test(tcase_core, Lg_fraction_long_big_width);
  tcase_add_test(tcase_core, Lg_general_short_big_width);
  tcase_add_test(tcase_core, Lg_general_medium_big_width);
  tcase_add_test(tcase_core, Lg_general_long_big_width);
  tcase_add_test(tcase_core, Lg_infinity_big_width);
  tcase_add_test(tcase_core, Lg_infinity_neg_big_width);
  tcase_add_test(tcase_core, LG_null_no_width);
  tcase_add_test(tcase_core, LG_null_neg_no_width);
  tcase_add_test(tcase_core, LG_fraction_short_no_width);
  tcase_add_test(tcase_core, LG_fraction_medium_no_width);
  tcase_add_test(tcase_core, LG_fraction_long_no_width);
  tcase_add_test(tcase_core, LG_general_short_no_width);
  tcase_add_test(tcase_core, LG_general_medium_no_width);
  tcase_add_test(tcase_core, LG_general_long_no_width);
  tcase_add_test(tcase_core, LG_infinity_no_width);
  tcase_add_test(tcase_core, LG_infinity_neg_no_width);
  tcase_add_test(tcase_core, LG_null_small_width);
  tcase_add_test(tcase_core, LG_null_neg_small_width);
  tcase_add_test(tcase_core, LG_fraction_short_small_width);
  tcase_add_test(tcase_core, LG_fraction_medium_small_width);
  tcase_add_test(tcase_core, LG_fraction_long_small_width);
  tcase_add_test(tcase_core, LG_general_short_small_width);
  tcase_add_test(tcase_core, LG_general_medium_small_width);
  tcase_add_test(tcase_core, LG_general_long_small_width);
  tcase_add_test(tcase_core, LG_infinity_small_width);
  tcase_add_test(tcase_core, LG_infinity_neg_small_width);
  tcase_add_test(tcase_core, LG_null_medium_width);
  tcase_add_test(tcase_core, LG_null_neg_medium_width);
  tcase_add_test(tcase_core, LG_fraction_short_medium_width);
  tcase_add_test(tcase_core, LG_fraction_medium_medium_width);
  tcase_add_test(tcase_core, LG_fraction_long_medium_width);
  tcase_add_test(tcase_core, LG_general_short_medium_width);
  tcase_add_test(tcase_core, LG_general_medium_medium_width);
  tcase_add_test(tcase_core, LG_general_long_medium_width);
  tcase_add_test(tcase_core, LG_infinity_medium_width);
  tcase_add_test(tcase_core, LG_infinity_neg_medium_width);
  tcase_add_test(tcase_core, LG_null_big_width);
  tcase_add_test(tcase_core, LG_null_neg_big_width);
  tcase_add_test(tcase_core, LG_fraction_short_big_width);
  tcase_add_test(tcase_core, LG_fraction_medium_big_width);
  tcase_add_test(tcase_core, LG_fraction_long_big_width);
  tcase_add_test(tcase_core, LG_general_short_big_width);
  tcase_add_test(tcase_core, LG_general_medium_big_width);
  tcase_add_test(tcase_core, LG_general_long_big_width);
  tcase_add_test(tcase_core, LG_infinity_big_width);
  tcase_add_test(tcase_core, LG_infinity_neg_big_width);
  tcase_add_test(tcase_core, d_null_no_width);
  tcase_add_test(tcase_core, d_null_neg_no_width);
  tcase_add_test(tcase_core, d_int_short_no_width);
  tcase_add_test(tcase_core, d_int_short_neg_no_width);
  tcase_add_test(tcase_core, d_int_medium_no_width);
  tcase_add_test(tcase_core, d_int_medium_neg_no_width);
  tcase_add_test(tcase_core, d_int_long_no_width);
  tcase_add_test(tcase_core, d_int_long_neg_no_width);
  tcase_add_test(tcase_core, d_null_small_width);
  tcase_add_test(tcase_core, d_null_neg_small_width);
  tcase_add_test(tcase_core, d_int_short_small_width);
  tcase_add_test(tcase_core, d_int_short_neg_small_width);
  tcase_add_test(tcase_core, d_int_medium_small_width);
  tcase_add_test(tcase_core, d_int_medium_neg_small_width);
  tcase_add_test(tcase_core, d_int_long_small_width);
  tcase_add_test(tcase_core, d_int_long_neg_small_width);
  tcase_add_test(tcase_core, d_null_medium_width);
  tcase_add_test(tcase_core, d_null_neg_medium_width);
  tcase_add_test(tcase_core, d_int_short_medium_width);
  tcase_add_test(tcase_core, d_int_short_neg_medium_width);
  tcase_add_test(tcase_core, d_int_medium_medium_width);
  tcase_add_test(tcase_core, d_int_medium_neg_medium_width);
  tcase_add_test(tcase_core, d_int_long_medium_width);
  tcase_add_test(tcase_core, d_int_long_neg_medium_width);
  tcase_add_test(tcase_core, d_null_big_width);
  tcase_add_test(tcase_core, d_null_neg_big_width);
  tcase_add_test(tcase_core, d_int_short_big_width);
  tcase_add_test(tcase_core, d_int_short_neg_big_width);
  tcase_add_test(tcase_core, d_int_medium_big_width);
  tcase_add_test(tcase_core, d_int_medium_neg_big_width);
  tcase_add_test(tcase_core, d_int_long_big_width);
  tcase_add_test(tcase_core, d_int_long_neg_big_width);
  tcase_add_test(tcase_core, hd_null_no_width);
  tcase_add_test(tcase_core, hd_null_neg_no_width);
  tcase_add_test(tcase_core, hd_int_short_no_width);
  tcase_add_test(tcase_core, hd_int_short_neg_no_width);
  tcase_add_test(tcase_core, hd_int_medium_no_width);
  tcase_add_test(tcase_core, hd_int_medium_neg_no_width);
  tcase_add_test(tcase_core, hd_int_long_no_width);
  tcase_add_test(tcase_core, hd_int_long_neg_no_width);
  tcase_add_test(tcase_core, hd_null_small_width);
  tcase_add_test(tcase_core, hd_null_neg_small_width);
  tcase_add_test(tcase_core, hd_int_short_small_width);
  tcase_add_test(tcase_core, hd_int_short_neg_small_width);
  tcase_add_test(tcase_core, hd_int_medium_small_width);
  tcase_add_test(tcase_core, hd_int_medium_neg_small_width);
  tcase_add_test(tcase_core, hd_int_long_small_width);
  tcase_add_test(tcase_core, hd_int_long_neg_small_width);
  tcase_add_test(tcase_core, hd_null_medium_width);
  tcase_add_test(tcase_core, hd_null_neg_medium_width);
  tcase_add_test(tcase_core, hd_int_short_medium_width);
  tcase_add_test(tcase_core, hd_int_short_neg_medium_width);
  tcase_add_test(tcase_core, hd_int_medium_medium_width);
  tcase_add_test(tcase_core, hd_int_medium_neg_medium_width);
  tcase_add_test(tcase_core, hd_int_long_medium_width);
  tcase_add_test(tcase_core, hd_int_long_neg_medium_width);
  tcase_add_test(tcase_core, hd_null_big_width);
  tcase_add_test(tcase_core, hd_null_neg_big_width);
  tcase_add_test(tcase_core, hd_int_short_big_width);
  tcase_add_test(tcase_core, hd_int_short_neg_big_width);
  tcase_add_test(tcase_core, hd_int_medium_big_width);
  tcase_add_test(tcase_core, hd_int_medium_neg_big_width);
  tcase_add_test(tcase_core, hd_int_long_big_width);
  tcase_add_test(tcase_core, hd_int_long_neg_big_width);
  tcase_add_test(tcase_core, ld_null_no_width);
  tcase_add_test(tcase_core, ld_null_neg_no_width);
  tcase_add_test(tcase_core, ld_int_short_no_width);
  tcase_add_test(tcase_core, ld_int_short_neg_no_width);
  tcase_add_test(tcase_core, ld_int_medium_no_width);
  tcase_add_test(tcase_core, ld_int_medium_neg_no_width);
  tcase_add_test(tcase_core, ld_int_long_no_width);
  tcase_add_test(tcase_core, ld_int_long_neg_no_width);
  tcase_add_test(tcase_core, ld_null_small_width);
  tcase_add_test(tcase_core, ld_null_neg_small_width);
  tcase_add_test(tcase_core, ld_int_short_small_width);
  tcase_add_test(tcase_core, ld_int_short_neg_small_width);
  tcase_add_test(tcase_core, ld_int_medium_small_width);
  tcase_add_test(tcase_core, ld_int_medium_neg_small_width);
  tcase_add_test(tcase_core, ld_int_long_small_width);
  tcase_add_test(tcase_core, ld_int_long_neg_small_width);
  tcase_add_test(tcase_core, ld_null_medium_width);
  tcase_add_test(tcase_core, ld_null_neg_medium_width);
  tcase_add_test(tcase_core, ld_int_short_medium_width);
  tcase_add_test(tcase_core, ld_int_short_neg_medium_width);
  tcase_add_test(tcase_core, ld_int_medium_medium_width);
  tcase_add_test(tcase_core, ld_int_medium_neg_medium_width);
  tcase_add_test(tcase_core, ld_int_long_medium_width);
  tcase_add_test(tcase_core, ld_int_long_neg_medium_width);
  tcase_add_test(tcase_core, ld_null_big_width);
  tcase_add_test(tcase_core, ld_null_neg_big_width);
  tcase_add_test(tcase_core, ld_int_short_big_width);
  tcase_add_test(tcase_core, ld_int_short_neg_big_width);
  tcase_add_test(tcase_core, ld_int_medium_big_width);
  tcase_add_test(tcase_core, ld_int_medium_neg_big_width);
  tcase_add_test(tcase_core, ld_int_long_big_width);
  tcase_add_test(tcase_core, ld_int_long_neg_big_width);
  tcase_add_test(tcase_core, i_null_no_width);
  tcase_add_test(tcase_core, i_null_neg_no_width);
  tcase_add_test(tcase_core, i_int_short_no_width);
  tcase_add_test(tcase_core, i_int_short_neg_no_width);
  tcase_add_test(tcase_core, i_int_medium_no_width);
  tcase_add_test(tcase_core, i_int_medium_neg_no_width);
  tcase_add_test(tcase_core, i_int_long_no_width);
  tcase_add_test(tcase_core, i_int_long_neg_no_width);
  tcase_add_test(tcase_core, i_null_small_width);
  tcase_add_test(tcase_core, i_null_neg_small_width);
  tcase_add_test(tcase_core, i_int_short_small_width);
  tcase_add_test(tcase_core, i_int_short_neg_small_width);
  tcase_add_test(tcase_core, i_int_medium_small_width);
  tcase_add_test(tcase_core, i_int_medium_neg_small_width);
  tcase_add_test(tcase_core, i_int_long_small_width);
  tcase_add_test(tcase_core, i_int_long_neg_small_width);
  tcase_add_test(tcase_core, i_null_medium_width);
  tcase_add_test(tcase_core, i_null_neg_medium_width);
  tcase_add_test(tcase_core, i_int_short_medium_width);
  tcase_add_test(tcase_core, i_int_short_neg_medium_width);
  tcase_add_test(tcase_core, i_int_medium_medium_width);
  tcase_add_test(tcase_core, i_int_medium_neg_medium_width);
  tcase_add_test(tcase_core, i_int_long_medium_width);
  tcase_add_test(tcase_core, i_int_long_neg_medium_width);
  tcase_add_test(tcase_core, i_null_big_width);
  tcase_add_test(tcase_core, i_null_neg_big_width);
  tcase_add_test(tcase_core, i_int_short_big_width);
  tcase_add_test(tcase_core, i_int_short_neg_big_width);
  tcase_add_test(tcase_core, i_int_medium_big_width);
  tcase_add_test(tcase_core, i_int_medium_neg_big_width);
  tcase_add_test(tcase_core, i_int_long_big_width);
  tcase_add_test(tcase_core, i_int_long_neg_big_width);
  tcase_add_test(tcase_core, hi_null_no_width);
  tcase_add_test(tcase_core, hi_null_neg_no_width);
  tcase_add_test(tcase_core, hi_int_short_no_width);
  tcase_add_test(tcase_core, hi_int_short_neg_no_width);
  tcase_add_test(tcase_core, hi_int_medium_no_width);
  tcase_add_test(tcase_core, hi_int_medium_neg_no_width);
  tcase_add_test(tcase_core, hi_int_long_no_width);
  tcase_add_test(tcase_core, hi_int_long_neg_no_width);
  tcase_add_test(tcase_core, hi_null_small_width);
  tcase_add_test(tcase_core, hi_null_neg_small_width);
  tcase_add_test(tcase_core, hi_int_short_small_width);
  tcase_add_test(tcase_core, hi_int_short_neg_small_width);
  tcase_add_test(tcase_core, hi_int_medium_small_width);
  tcase_add_test(tcase_core, hi_int_medium_neg_small_width);
  tcase_add_test(tcase_core, hi_int_long_small_width);
  tcase_add_test(tcase_core, hi_int_long_neg_small_width);
  tcase_add_test(tcase_core, hi_null_medium_width);
  tcase_add_test(tcase_core, hi_null_neg_medium_width);
  tcase_add_test(tcase_core, hi_int_short_medium_width);
  tcase_add_test(tcase_core, hi_int_short_neg_medium_width);
  tcase_add_test(tcase_core, hi_int_medium_medium_width);
  tcase_add_test(tcase_core, hi_int_medium_neg_medium_width);
  tcase_add_test(tcase_core, hi_int_long_medium_width);
  tcase_add_test(tcase_core, hi_int_long_neg_medium_width);
  tcase_add_test(tcase_core, hi_null_big_width);
  tcase_add_test(tcase_core, hi_null_neg_big_width);
  tcase_add_test(tcase_core, hi_int_short_big_width);
  tcase_add_test(tcase_core, hi_int_short_neg_big_width);
  tcase_add_test(tcase_core, hi_int_medium_big_width);
  tcase_add_test(tcase_core, hi_int_medium_neg_big_width);
  tcase_add_test(tcase_core, hi_int_long_big_width);
  tcase_add_test(tcase_core, hi_int_long_neg_big_width);
  tcase_add_test(tcase_core, li_null_no_width);
  tcase_add_test(tcase_core, li_null_neg_no_width);
  tcase_add_test(tcase_core, li_int_short_no_width);
  tcase_add_test(tcase_core, li_int_short_neg_no_width);
  tcase_add_test(tcase_core, li_int_medium_no_width);
  tcase_add_test(tcase_core, li_int_medium_neg_no_width);
  tcase_add_test(tcase_core, li_int_long_no_width);
  tcase_add_test(tcase_core, li_int_long_neg_no_width);
  tcase_add_test(tcase_core, li_null_small_width);
  tcase_add_test(tcase_core, li_null_neg_small_width);
  tcase_add_test(tcase_core, li_int_short_small_width);
  tcase_add_test(tcase_core, li_int_short_neg_small_width);
  tcase_add_test(tcase_core, li_int_medium_small_width);
  tcase_add_test(tcase_core, li_int_medium_neg_small_width);
  tcase_add_test(tcase_core, li_int_long_small_width);
  tcase_add_test(tcase_core, li_int_long_neg_small_width);
  tcase_add_test(tcase_core, li_null_medium_width);
  tcase_add_test(tcase_core, li_null_neg_medium_width);
  tcase_add_test(tcase_core, li_int_short_medium_width);
  tcase_add_test(tcase_core, li_int_short_neg_medium_width);
  tcase_add_test(tcase_core, li_int_medium_medium_width);
  tcase_add_test(tcase_core, li_int_medium_neg_medium_width);
  tcase_add_test(tcase_core, li_int_long_medium_width);
  tcase_add_test(tcase_core, li_int_long_neg_medium_width);
  tcase_add_test(tcase_core, li_null_big_width);
  tcase_add_test(tcase_core, li_null_neg_big_width);
  tcase_add_test(tcase_core, li_int_short_big_width);
  tcase_add_test(tcase_core, li_int_short_neg_big_width);
  tcase_add_test(tcase_core, li_int_medium_big_width);
  tcase_add_test(tcase_core, li_int_medium_neg_big_width);
  tcase_add_test(tcase_core, li_int_long_big_width);
  tcase_add_test(tcase_core, li_int_long_neg_big_width);
  tcase_add_test(tcase_core, u_null_no_width);
  tcase_add_test(tcase_core, u_null_neg_no_width);
  tcase_add_test(tcase_core, u_int_short_no_width);
  tcase_add_test(tcase_core, u_int_short_neg_no_width);
  tcase_add_test(tcase_core, u_int_medium_no_width);
  tcase_add_test(tcase_core, u_int_medium_neg_no_width);
  tcase_add_test(tcase_core, u_int_long_no_width);
  tcase_add_test(tcase_core, u_int_long_neg_no_width);
  tcase_add_test(tcase_core, u_null_small_width);
  tcase_add_test(tcase_core, u_null_neg_small_width);
  tcase_add_test(tcase_core, u_int_short_small_width);
  tcase_add_test(tcase_core, u_int_short_neg_small_width);
  tcase_add_test(tcase_core, u_int_medium_small_width);
  tcase_add_test(tcase_core, u_int_medium_neg_small_width);
  tcase_add_test(tcase_core, u_int_long_small_width);
  tcase_add_test(tcase_core, u_int_long_neg_small_width);
  tcase_add_test(tcase_core, u_null_medium_width);
  tcase_add_test(tcase_core, u_null_neg_medium_width);
  tcase_add_test(tcase_core, u_int_short_medium_width);
  tcase_add_test(tcase_core, u_int_short_neg_medium_width);
  tcase_add_test(tcase_core, u_int_medium_medium_width);
  tcase_add_test(tcase_core, u_int_medium_neg_medium_width);
  tcase_add_test(tcase_core, u_int_long_medium_width);
  tcase_add_test(tcase_core, u_int_long_neg_medium_width);
  tcase_add_test(tcase_core, u_null_big_width);
  tcase_add_test(tcase_core, u_null_neg_big_width);
  tcase_add_test(tcase_core, u_int_short_big_width);
  tcase_add_test(tcase_core, u_int_short_neg_big_width);
  tcase_add_test(tcase_core, u_int_medium_big_width);
  tcase_add_test(tcase_core, u_int_medium_neg_big_width);
  tcase_add_test(tcase_core, u_int_long_big_width);
  tcase_add_test(tcase_core, u_int_long_neg_big_width);
  tcase_add_test(tcase_core, hu_null_no_width);
  tcase_add_test(tcase_core, hu_null_neg_no_width);
  tcase_add_test(tcase_core, hu_int_short_no_width);
  tcase_add_test(tcase_core, hu_int_short_neg_no_width);
  tcase_add_test(tcase_core, hu_int_medium_no_width);
  tcase_add_test(tcase_core, hu_int_medium_neg_no_width);
  tcase_add_test(tcase_core, hu_int_long_no_width);
  tcase_add_test(tcase_core, hu_int_long_neg_no_width);
  tcase_add_test(tcase_core, hu_null_small_width);
  tcase_add_test(tcase_core, hu_null_neg_small_width);
  tcase_add_test(tcase_core, hu_int_short_small_width);
  tcase_add_test(tcase_core, hu_int_short_neg_small_width);
  tcase_add_test(tcase_core, hu_int_medium_small_width);
  tcase_add_test(tcase_core, hu_int_medium_neg_small_width);
  tcase_add_test(tcase_core, hu_int_long_small_width);
  tcase_add_test(tcase_core, hu_int_long_neg_small_width);
  tcase_add_test(tcase_core, hu_null_medium_width);
  tcase_add_test(tcase_core, hu_null_neg_medium_width);
  tcase_add_test(tcase_core, hu_int_short_medium_width);
  tcase_add_test(tcase_core, hu_int_short_neg_medium_width);
  tcase_add_test(tcase_core, hu_int_medium_medium_width);
  tcase_add_test(tcase_core, hu_int_medium_neg_medium_width);
  tcase_add_test(tcase_core, hu_int_long_medium_width);
  tcase_add_test(tcase_core, hu_int_long_neg_medium_width);
  tcase_add_test(tcase_core, hu_null_big_width);
  tcase_add_test(tcase_core, hu_null_neg_big_width);
  tcase_add_test(tcase_core, hu_int_short_big_width);
  tcase_add_test(tcase_core, hu_int_short_neg_big_width);
  tcase_add_test(tcase_core, hu_int_medium_big_width);
  tcase_add_test(tcase_core, hu_int_medium_neg_big_width);
  tcase_add_test(tcase_core, hu_int_long_big_width);
  tcase_add_test(tcase_core, hu_int_long_neg_big_width);
  tcase_add_test(tcase_core, lu_null_no_width);
  tcase_add_test(tcase_core, lu_null_neg_no_width);
  tcase_add_test(tcase_core, lu_int_short_no_width);
  tcase_add_test(tcase_core, lu_int_short_neg_no_width);
  tcase_add_test(tcase_core, lu_int_medium_no_width);
  tcase_add_test(tcase_core, lu_int_medium_neg_no_width);
  tcase_add_test(tcase_core, lu_int_long_no_width);
  tcase_add_test(tcase_core, lu_int_long_neg_no_width);
  tcase_add_test(tcase_core, lu_null_small_width);
  tcase_add_test(tcase_core, lu_null_neg_small_width);
  tcase_add_test(tcase_core, lu_int_short_small_width);
  tcase_add_test(tcase_core, lu_int_short_neg_small_width);
  tcase_add_test(tcase_core, lu_int_medium_small_width);
  tcase_add_test(tcase_core, lu_int_medium_neg_small_width);
  tcase_add_test(tcase_core, lu_int_long_small_width);
  tcase_add_test(tcase_core, lu_int_long_neg_small_width);
  tcase_add_test(tcase_core, lu_null_medium_width);
  tcase_add_test(tcase_core, lu_null_neg_medium_width);
  tcase_add_test(tcase_core, lu_int_short_medium_width);
  tcase_add_test(tcase_core, lu_int_short_neg_medium_width);
  tcase_add_test(tcase_core, lu_int_medium_medium_width);
  tcase_add_test(tcase_core, lu_int_medium_neg_medium_width);
  tcase_add_test(tcase_core, lu_int_long_medium_width);
  tcase_add_test(tcase_core, lu_int_long_neg_medium_width);
  tcase_add_test(tcase_core, lu_null_big_width);
  tcase_add_test(tcase_core, lu_null_neg_big_width);
  tcase_add_test(tcase_core, lu_int_short_big_width);
  tcase_add_test(tcase_core, lu_int_short_neg_big_width);
  tcase_add_test(tcase_core, lu_int_medium_big_width);
  tcase_add_test(tcase_core, lu_int_medium_neg_big_width);
  tcase_add_test(tcase_core, lu_int_long_big_width);
  tcase_add_test(tcase_core, lu_int_long_neg_big_width);
  tcase_add_test(tcase_core, o_oct_null_no_width);
  tcase_add_test(tcase_core, o_oct_medium_no_width);
  tcase_add_test(tcase_core, o_oct_long_no_width);
  tcase_add_test(tcase_core, o_oct_null_small_width);
  tcase_add_test(tcase_core, o_oct_medium_small_width);
  tcase_add_test(tcase_core, o_oct_long_small_width);
  tcase_add_test(tcase_core, o_oct_null_medium_width);
  tcase_add_test(tcase_core, o_oct_medium_medium_width);
  tcase_add_test(tcase_core, o_oct_long_medium_width);
  tcase_add_test(tcase_core, o_oct_null_big_width);
  tcase_add_test(tcase_core, o_oct_medium_big_width);
  tcase_add_test(tcase_core, o_oct_long_big_width);
  tcase_add_test(tcase_core, ho_oct_null_no_width);
  tcase_add_test(tcase_core, ho_oct_medium_no_width);
  tcase_add_test(tcase_core, ho_oct_long_no_width);
  tcase_add_test(tcase_core, ho_oct_null_small_width);
  tcase_add_test(tcase_core, ho_oct_medium_small_width);
  tcase_add_test(tcase_core, ho_oct_long_small_width);
  tcase_add_test(tcase_core, ho_oct_null_medium_width);
  tcase_add_test(tcase_core, ho_oct_medium_medium_width);
  tcase_add_test(tcase_core, ho_oct_long_medium_width);
  tcase_add_test(tcase_core, ho_oct_null_big_width);
  tcase_add_test(tcase_core, ho_oct_medium_big_width);
  tcase_add_test(tcase_core, ho_oct_long_big_width);
  tcase_add_test(tcase_core, lo_oct_null_no_width);
  tcase_add_test(tcase_core, lo_oct_medium_no_width);
  tcase_add_test(tcase_core, lo_oct_long_no_width);
  tcase_add_test(tcase_core, lo_oct_null_small_width);
  tcase_add_test(tcase_core, lo_oct_medium_small_width);
  tcase_add_test(tcase_core, lo_oct_long_small_width);
  tcase_add_test(tcase_core, lo_oct_null_medium_width);
  tcase_add_test(tcase_core, lo_oct_medium_medium_width);
  tcase_add_test(tcase_core, lo_oct_long_medium_width);
  tcase_add_test(tcase_core, lo_oct_null_big_width);
  tcase_add_test(tcase_core, lo_oct_medium_big_width);
  tcase_add_test(tcase_core, lo_oct_long_big_width);
  tcase_add_test(tcase_core, x_hex_null_no_width);
  tcase_add_test(tcase_core, x_hex_short_no_width);
  tcase_add_test(tcase_core, x_hex_medium_no_width);
  tcase_add_test(tcase_core, x_hex_no_prefix_no_width);
  tcase_add_test(tcase_core, x_hex_long_no_width);
  tcase_add_test(tcase_core, x_hex_null_small_width);
  tcase_add_test(tcase_core, x_hex_short_small_width);
  tcase_add_test(tcase_core, x_hex_medium_small_width);
  tcase_add_test(tcase_core, x_hex_no_prefix_small_width);
  tcase_add_test(tcase_core, x_hex_long_small_width);
  tcase_add_test(tcase_core, x_hex_null_medium_width);
  tcase_add_test(tcase_core, x_hex_short_medium_width);
  tcase_add_test(tcase_core, x_hex_medium_medium_width);
  tcase_add_test(tcase_core, x_hex_no_prefix_medium_width);
  tcase_add_test(tcase_core, x_hex_long_medium_width);
  tcase_add_test(tcase_core, x_hex_null_big_width);
  tcase_add_test(tcase_core, x_hex_short_big_width);
  tcase_add_test(tcase_core, x_hex_medium_big_width);
  tcase_add_test(tcase_core, x_hex_no_prefix_big_width);
  tcase_add_test(tcase_core, x_hex_long_big_width);
  tcase_add_test(tcase_core, X_hex_null_no_width);
  tcase_add_test(tcase_core, X_hex_short_no_width);
  tcase_add_test(tcase_core, X_hex_medium_no_width);
  tcase_add_test(tcase_core, X_hex_no_prefix_no_width);
  tcase_add_test(tcase_core, X_hex_long_no_width);
  tcase_add_test(tcase_core, X_hex_null_small_width);
  tcase_add_test(tcase_core, X_hex_short_small_width);
  tcase_add_test(tcase_core, X_hex_medium_small_width);
  tcase_add_test(tcase_core, X_hex_no_prefix_small_width);
  tcase_add_test(tcase_core, X_hex_long_small_width);
  tcase_add_test(tcase_core, X_hex_null_medium_width);
  tcase_add_test(tcase_core, X_hex_short_medium_width);
  tcase_add_test(tcase_core, X_hex_medium_medium_width);
  tcase_add_test(tcase_core, X_hex_no_prefix_medium_width);
  tcase_add_test(tcase_core, X_hex_long_medium_width);
  tcase_add_test(tcase_core, X_hex_null_big_width);
  tcase_add_test(tcase_core, X_hex_short_big_width);
  tcase_add_test(tcase_core, X_hex_medium_big_width);
  tcase_add_test(tcase_core, X_hex_no_prefix_big_width);
  tcase_add_test(tcase_core, X_hex_long_big_width);
  tcase_add_test(tcase_core, hx_hex_null_no_width);
  tcase_add_test(tcase_core, hx_hex_short_no_width);
  tcase_add_test(tcase_core, hx_hex_medium_no_width);
  tcase_add_test(tcase_core, hx_hex_no_prefix_no_width);
  tcase_add_test(tcase_core, hx_hex_long_no_width);
  tcase_add_test(tcase_core, hx_hex_null_small_width);
  tcase_add_test(tcase_core, hx_hex_short_small_width);
  tcase_add_test(tcase_core, hx_hex_medium_small_width);
  tcase_add_test(tcase_core, hx_hex_no_prefix_small_width);
  tcase_add_test(tcase_core, hx_hex_long_small_width);
  tcase_add_test(tcase_core, hx_hex_null_medium_width);
  tcase_add_test(tcase_core, hx_hex_short_medium_width);
  tcase_add_test(tcase_core, hx_hex_medium_medium_width);
  tcase_add_test(tcase_core, hx_hex_no_prefix_medium_width);
  tcase_add_test(tcase_core, hx_hex_long_medium_width);
  tcase_add_test(tcase_core, hx_hex_null_big_width);
  tcase_add_test(tcase_core, hx_hex_short_big_width);
  tcase_add_test(tcase_core, hx_hex_medium_big_width);
  tcase_add_test(tcase_core, hx_hex_no_prefix_big_width);
  tcase_add_test(tcase_core, hx_hex_long_big_width);
  tcase_add_test(tcase_core, hX_hex_null_no_width);
  tcase_add_test(tcase_core, hX_hex_short_no_width);
  tcase_add_test(tcase_core, hX_hex_medium_no_width);
  tcase_add_test(tcase_core, hX_hex_no_prefix_no_width);
  tcase_add_test(tcase_core, hX_hex_long_no_width);
  tcase_add_test(tcase_core, hX_hex_null_small_width);
  tcase_add_test(tcase_core, hX_hex_short_small_width);
  tcase_add_test(tcase_core, hX_hex_medium_small_width);
  tcase_add_test(tcase_core, hX_hex_no_prefix_small_width);
  tcase_add_test(tcase_core, hX_hex_long_small_width);
  tcase_add_test(tcase_core, hX_hex_null_medium_width);
  tcase_add_test(tcase_core, hX_hex_short_medium_width);
  tcase_add_test(tcase_core, hX_hex_medium_medium_width);
  tcase_add_test(tcase_core, hX_hex_no_prefix_medium_width);
  tcase_add_test(tcase_core, hX_hex_long_medium_width);
  tcase_add_test(tcase_core, hX_hex_null_big_width);
  tcase_add_test(tcase_core, hX_hex_short_big_width);
  tcase_add_test(tcase_core, hX_hex_medium_big_width);
  tcase_add_test(tcase_core, hX_hex_no_prefix_big_width);
  tcase_add_test(tcase_core, hX_hex_long_big_width);
  tcase_add_test(tcase_core, lx_hex_null_no_width);
  tcase_add_test(tcase_core, lx_hex_short_no_width);
  tcase_add_test(tcase_core, lx_hex_medium_no_width);
  tcase_add_test(tcase_core, lx_hex_no_prefix_no_width);
  tcase_add_test(tcase_core, lx_hex_long_no_width);
  tcase_add_test(tcase_core, lx_hex_null_small_width);
  tcase_add_test(tcase_core, lx_hex_short_small_width);
  tcase_add_test(tcase_core, lx_hex_medium_small_width);
  tcase_add_test(tcase_core, lx_hex_no_prefix_small_width);
  tcase_add_test(tcase_core, lx_hex_long_small_width);
  tcase_add_test(tcase_core, lx_hex_null_medium_width);
  tcase_add_test(tcase_core, lx_hex_short_medium_width);
  tcase_add_test(tcase_core, lx_hex_medium_medium_width);
  tcase_add_test(tcase_core, lx_hex_no_prefix_medium_width);
  tcase_add_test(tcase_core, lx_hex_long_medium_width);
  tcase_add_test(tcase_core, lx_hex_null_big_width);
  tcase_add_test(tcase_core, lx_hex_short_big_width);
  tcase_add_test(tcase_core, lx_hex_medium_big_width);
  tcase_add_test(tcase_core, lx_hex_no_prefix_big_width);
  tcase_add_test(tcase_core, lx_hex_long_big_width);
  tcase_add_test(tcase_core, lX_hex_null_no_width);
  tcase_add_test(tcase_core, lX_hex_short_no_width);
  tcase_add_test(tcase_core, lX_hex_medium_no_width);
  tcase_add_test(tcase_core, lX_hex_no_prefix_no_width);
  tcase_add_test(tcase_core, lX_hex_long_no_width);
  tcase_add_test(tcase_core, lX_hex_null_small_width);
  tcase_add_test(tcase_core, lX_hex_short_small_width);
  tcase_add_test(tcase_core, lX_hex_medium_small_width);
  tcase_add_test(tcase_core, lX_hex_no_prefix_small_width);
  tcase_add_test(tcase_core, lX_hex_long_small_width);
  tcase_add_test(tcase_core, lX_hex_null_medium_width);
  tcase_add_test(tcase_core, lX_hex_short_medium_width);
  tcase_add_test(tcase_core, lX_hex_medium_medium_width);
  tcase_add_test(tcase_core, lX_hex_no_prefix_medium_width);
  tcase_add_test(tcase_core, lX_hex_long_medium_width);
  tcase_add_test(tcase_core, lX_hex_null_big_width);
  tcase_add_test(tcase_core, lX_hex_short_big_width);
  tcase_add_test(tcase_core, lX_hex_medium_big_width);
  tcase_add_test(tcase_core, lX_hex_no_prefix_big_width);
  tcase_add_test(tcase_core, lX_hex_long_big_width);
  tcase_add_test(tcase_core, p_zero_ptr_no_width);
  tcase_add_test(tcase_core, p_small_ptr_no_width);
  tcase_add_test(tcase_core, p_medium_ptr_no_width);
  tcase_add_test(tcase_core, p_large_ptr_no_width);
  tcase_add_test(tcase_core, p_zero_ptr_small_width);
  tcase_add_test(tcase_core, p_small_ptr_small_width);
  tcase_add_test(tcase_core, p_medium_ptr_small_width);
  tcase_add_test(tcase_core, p_large_ptr_small_width);
  tcase_add_test(tcase_core, p_zero_ptr_medium_width);
  tcase_add_test(tcase_core, p_small_ptr_medium_width);
  tcase_add_test(tcase_core, p_medium_ptr_medium_width);
  tcase_add_test(tcase_core, p_large_ptr_medium_width);
  tcase_add_test(tcase_core, p_zero_ptr_big_width);
  tcase_add_test(tcase_core, p_small_ptr_big_width);
  tcase_add_test(tcase_core, p_medium_ptr_big_width);
  tcase_add_test(tcase_core, p_large_ptr_big_width);
  tcase_add_test(tcase_core, c_lowercase_no_width);
  tcase_add_test(tcase_core, c_uppercase_no_width);
  tcase_add_test(tcase_core, c_digit_no_width);
  tcase_add_test(tcase_core, c_symbol_no_width);
  tcase_add_test(tcase_core, c_newline_no_width);
  tcase_add_test(tcase_core, c_tab_no_width);
  tcase_add_test(tcase_core, c_space_no_width);
  tcase_add_test(tcase_core, c_multiple_chars_no_width);
  tcase_add_test(tcase_core, s_basic_default_width);
  tcase_add_test(tcase_core, s_with_space_default_width);
  tcase_add_test(tcase_core, s_digits_default_width);
  tcase_add_test(tcase_core, s_multiple_spaces_default_width);
  tcase_add_test(tcase_core, s_leading_spaces_default_width);
  tcase_add_test(tcase_core, s_trailing_spaces_default_width);
  tcase_add_test(tcase_core, s_symbols_default_width);
  tcase_add_test(tcase_core, s_empty_string_default_width);
  tcase_add_test(tcase_core, s_very_long_default_width);
  tcase_add_test(tcase_core, s_only_spaces_default_width);
  tcase_add_test(tcase_core, s_basic_small_width);
  tcase_add_test(tcase_core, s_with_space_small_width);
  tcase_add_test(tcase_core, s_digits_small_width);
  tcase_add_test(tcase_core, s_multiple_spaces_small_width);
  tcase_add_test(tcase_core, s_leading_spaces_small_width);
  tcase_add_test(tcase_core, s_trailing_spaces_small_width);
  tcase_add_test(tcase_core, s_symbols_small_width);
  tcase_add_test(tcase_core, s_empty_string_small_width);
  tcase_add_test(tcase_core, s_very_long_small_width);
  tcase_add_test(tcase_core, s_only_spaces_small_width);
  tcase_add_test(tcase_core, s_basic_medium_width);
  tcase_add_test(tcase_core, s_with_space_medium_width);
  tcase_add_test(tcase_core, s_digits_medium_width);
  tcase_add_test(tcase_core, s_multiple_spaces_medium_width);
  tcase_add_test(tcase_core, s_leading_spaces_medium_width);
  tcase_add_test(tcase_core, s_trailing_spaces_medium_width);
  tcase_add_test(tcase_core, s_symbols_medium_width);
  tcase_add_test(tcase_core, s_empty_string_medium_width);
  tcase_add_test(tcase_core, s_very_long_medium_width);
  tcase_add_test(tcase_core, s_only_spaces_medium_width);
  tcase_add_test(tcase_core, s_basic_big_width);
  tcase_add_test(tcase_core, s_with_space_big_width);
  tcase_add_test(tcase_core, s_digits_big_width);
  tcase_add_test(tcase_core, s_multiple_spaces_big_width);
  tcase_add_test(tcase_core, s_leading_spaces_big_width);
  tcase_add_test(tcase_core, s_trailing_spaces_big_width);
  tcase_add_test(tcase_core, s_symbols_big_width);
  tcase_add_test(tcase_core, s_empty_string_big_width);
  tcase_add_test(tcase_core, s_very_long_big_width);
  tcase_add_test(tcase_core, s_only_spaces_big_width);
  tcase_add_test(tcase_core, ls_basic_default_width);
  tcase_add_test(tcase_core, ls_with_space_default_width);
  tcase_add_test(tcase_core, ls_digits_default_width);
  tcase_add_test(tcase_core, ls_multiple_spaces_default_width);
  tcase_add_test(tcase_core, ls_leading_spaces_default_width);
  tcase_add_test(tcase_core, ls_trailing_spaces_default_width);
  tcase_add_test(tcase_core, ls_symbols_default_width);
  tcase_add_test(tcase_core, ls_empty_string_default_width);
  tcase_add_test(tcase_core, ls_very_long_default_width);
  tcase_add_test(tcase_core, ls_only_spaces_default_width);
  tcase_add_test(tcase_core, ls_basic_small_width);
  tcase_add_test(tcase_core, ls_with_space_small_width);
  tcase_add_test(tcase_core, ls_digits_small_width);
  tcase_add_test(tcase_core, ls_multiple_spaces_small_width);
  tcase_add_test(tcase_core, ls_leading_spaces_small_width);
  tcase_add_test(tcase_core, ls_trailing_spaces_small_width);
  tcase_add_test(tcase_core, ls_symbols_small_width);
  tcase_add_test(tcase_core, ls_empty_string_small_width);
  tcase_add_test(tcase_core, ls_very_long_small_width);
  tcase_add_test(tcase_core, ls_only_spaces_small_width);
  tcase_add_test(tcase_core, ls_basic_medium_width);
  tcase_add_test(tcase_core, ls_with_space_medium_width);
  tcase_add_test(tcase_core, ls_digits_medium_width);
  tcase_add_test(tcase_core, ls_multiple_spaces_medium_width);
  tcase_add_test(tcase_core, ls_leading_spaces_medium_width);
  tcase_add_test(tcase_core, ls_trailing_spaces_medium_width);
  tcase_add_test(tcase_core, ls_symbols_medium_width);
  tcase_add_test(tcase_core, ls_empty_string_medium_width);
  tcase_add_test(tcase_core, ls_very_long_medium_width);
  tcase_add_test(tcase_core, ls_only_spaces_medium_width);
  tcase_add_test(tcase_core, ls_basic_big_width);
  tcase_add_test(tcase_core, ls_with_space_big_width);
  tcase_add_test(tcase_core, ls_digits_big_width);
  tcase_add_test(tcase_core, ls_multiple_spaces_big_width);
  tcase_add_test(tcase_core, ls_leading_spaces_big_width);
  tcase_add_test(tcase_core, ls_trailing_spaces_big_width);
  tcase_add_test(tcase_core, ls_symbols_big_width);
  tcase_add_test(tcase_core, ls_empty_string_big_width);
  tcase_add_test(tcase_core, ls_very_long_big_width);
  tcase_add_test(tcase_core, ls_only_spaces_big_width);
  tcase_add_test(tcase_core, number_in_the_start);
  tcase_add_test(tcase_core, number_in_the_middle);
  tcase_add_test(tcase_core, number_in_the_end);
  tcase_add_test(tcase_core, percent_in_the_middle);
  tcase_add_test(tcase_core, percent_scan);
  tcase_add_test(tcase_core, star);
  tcase_add_test(tcase_core, wrong_specif);
  tcase_add_test(tcase_core, sscanf_all_specifiers);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
