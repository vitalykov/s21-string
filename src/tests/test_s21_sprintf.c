#include <math.h>
#include <stdio.h>
#include <wctype.h>

#include "s21_string.h"
#include "tests/test.h"

#define RUN_TEST(fmt, ...)                                            \
  char got_str[1000];                                                 \
  char expected_str[1000];                                            \
  const char* format = fmt;                                           \
  int chars_count_s21 = s21_sprintf(got_str, format, ##__VA_ARGS__);  \
  int chars_count_std = sprintf(expected_str, format, ##__VA_ARGS__); \
  ck_assert_str_eq(got_str, expected_str);                            \
  ck_assert_int_eq(chars_count_s21, chars_count_std);

START_TEST(float_null_no_flags){RUN_TEST("%f", 0.0f)} END_TEST
    START_TEST(float_null_neg_no_flags){RUN_TEST("%f", -0.0f)} END_TEST
    START_TEST(float_fraction_short_no_flags){
        RUN_TEST("%f", 0.1234567f)} END_TEST
    START_TEST(float_general_short_no_flags){RUN_TEST("%f", 1234.567f)} END_TEST
    START_TEST(float_exp_null_no_flags){RUN_TEST("%e", 0.0f)} END_TEST
    START_TEST(float_exp_null_neg_no_flags){RUN_TEST("%e", -0.0f)} END_TEST
    START_TEST(float_exp_fraction_short_no_flags){
        RUN_TEST("%e", 0.1234567f)} END_TEST
    START_TEST(float_exp_general_short_no_flags){
        RUN_TEST("%e", 1234.567f)} END_TEST
    START_TEST(float_EXP_null_no_flags){RUN_TEST("%E", 0.0f)} END_TEST
    START_TEST(float_EXP_null_neg_no_flags){RUN_TEST("%E", -0.0f)} END_TEST
    START_TEST(float_EXP_fraction_short_no_flags){
        RUN_TEST("%E", 0.1234567f)} END_TEST
    START_TEST(float_EXP_general_short_no_flags){
        RUN_TEST("%E", 1234.567f)} END_TEST
    START_TEST(float_g_null_no_flags){RUN_TEST("%g", 0.0f)} END_TEST
    START_TEST(float_g_null_neg_no_flags){RUN_TEST("%g", -0.0f)} END_TEST
    START_TEST(float_g_fraction_short_no_flags){
        RUN_TEST("%g", 0.1234567f)} END_TEST
    START_TEST(float_g_general_short_no_flags){
        RUN_TEST("%g", 1234.567f)} END_TEST
    START_TEST(float_G_null_no_flags){RUN_TEST("%G", 0.0f)} END_TEST
    START_TEST(float_G_null_neg_no_flags){RUN_TEST("%G", -0.0f)} END_TEST
    START_TEST(float_G_fraction_short_no_flags){
        RUN_TEST("%G", 0.1234567f)} END_TEST
    START_TEST(float_G_general_short_no_flags){
        RUN_TEST("%G", 1234.567f)} END_TEST
    START_TEST(float_null_prefix_sign){RUN_TEST("%+f", 0.0f)} END_TEST
    START_TEST(float_null_neg_prefix_sign){RUN_TEST("%+f", -0.0f)} END_TEST
    START_TEST(float_fraction_short_prefix_sign){
        RUN_TEST("%+f", 0.1234567f)} END_TEST
    START_TEST(float_general_short_prefix_sign){
        RUN_TEST("%+f", 1234.567f)} END_TEST
    START_TEST(float_exp_null_prefix_sign){RUN_TEST("%+e", 0.0f)} END_TEST
    START_TEST(float_exp_null_neg_prefix_sign){RUN_TEST("%+e", -0.0f)} END_TEST
    START_TEST(float_exp_fraction_short_prefix_sign){
        RUN_TEST("%+e", 0.1234567f)} END_TEST
    START_TEST(float_exp_general_short_prefix_sign){
        RUN_TEST("%+e", 1234.567f)} END_TEST
    START_TEST(float_EXP_null_prefix_sign){RUN_TEST("%+E", 0.0f)} END_TEST
    START_TEST(float_EXP_null_neg_prefix_sign){RUN_TEST("%+E", -0.0f)} END_TEST
    START_TEST(float_EXP_fraction_short_prefix_sign){
        RUN_TEST("%+E", 0.1234567f)} END_TEST
    START_TEST(float_EXP_general_short_prefix_sign){
        RUN_TEST("%+E", 1234.567f)} END_TEST
    START_TEST(float_g_null_prefix_sign){RUN_TEST("%+g", 0.0f)} END_TEST
    START_TEST(float_g_null_neg_prefix_sign){RUN_TEST("%+g", -0.0f)} END_TEST
    START_TEST(float_g_fraction_short_prefix_sign){
        RUN_TEST("%+g", 0.1234567f)} END_TEST
    START_TEST(float_g_general_short_prefix_sign){
        RUN_TEST("%+g", 1234.567f)} END_TEST
    START_TEST(float_G_null_prefix_sign){RUN_TEST("%+G", 0.0f)} END_TEST
    START_TEST(float_G_null_neg_prefix_sign){RUN_TEST("%+G", -0.0f)} END_TEST
    START_TEST(float_G_fraction_short_prefix_sign){
        RUN_TEST("%+G", 0.1234567f)} END_TEST
    START_TEST(float_G_general_short_prefix_sign){
        RUN_TEST("%+G", 1234.567f)} END_TEST
    START_TEST(float_null_prefix_space){RUN_TEST("% f", 0.0f)} END_TEST
    START_TEST(float_null_neg_prefix_space){RUN_TEST("% f", -0.0f)} END_TEST
    START_TEST(float_fraction_short_prefix_space){
        RUN_TEST("% f", 0.1234567f)} END_TEST
    START_TEST(float_general_short_prefix_space){
        RUN_TEST("% f", 1234.567f)} END_TEST
    START_TEST(float_exp_null_prefix_space){RUN_TEST("% e", 0.0f)} END_TEST
    START_TEST(float_exp_null_neg_prefix_space){RUN_TEST("% e", -0.0f)} END_TEST
    START_TEST(float_exp_fraction_short_prefix_space){
        RUN_TEST("% e", 0.1234567f)} END_TEST
    START_TEST(float_exp_general_short_prefix_space){
        RUN_TEST("% e", 1234.567f)} END_TEST
    START_TEST(float_EXP_null_prefix_space){RUN_TEST("% E", 0.0f)} END_TEST
    START_TEST(float_EXP_null_neg_prefix_space){RUN_TEST("% E", -0.0f)} END_TEST
    START_TEST(float_EXP_fraction_short_prefix_space){
        RUN_TEST("% E", 0.1234567f)} END_TEST
    START_TEST(float_EXP_general_short_prefix_space){
        RUN_TEST("% E", 1234.567f)} END_TEST
    START_TEST(float_g_null_prefix_space){RUN_TEST("% g", 0.0f)} END_TEST
    START_TEST(float_g_null_neg_prefix_space){RUN_TEST("% g", -0.0f)} END_TEST
    START_TEST(float_g_fraction_short_prefix_space){
        RUN_TEST("% g", 0.1234567f)} END_TEST
    START_TEST(float_g_general_short_prefix_space){
        RUN_TEST("% g", 1234.567f)} END_TEST
    START_TEST(float_G_null_prefix_space){RUN_TEST("% G", 0.0f)} END_TEST
    START_TEST(float_G_null_neg_prefix_space){RUN_TEST("% G", -0.0f)} END_TEST
    START_TEST(float_G_fraction_short_prefix_space){
        RUN_TEST("% G", 0.1234567f)} END_TEST
    START_TEST(float_G_general_short_prefix_space){
        RUN_TEST("% G", 1234.567f)} END_TEST
    START_TEST(float_null_left_alignment){RUN_TEST("%-f", 0.0f)} END_TEST
    START_TEST(float_null_neg_left_alignment){RUN_TEST("%-f", -0.0f)} END_TEST
    START_TEST(float_fraction_short_left_alignment){
        RUN_TEST("%-f", 0.1234567f)} END_TEST
    START_TEST(float_general_short_left_alignment){
        RUN_TEST("%-f", 1234.567f)} END_TEST
    START_TEST(float_exp_null_left_alignment){RUN_TEST("%-e", 0.0f)} END_TEST
    START_TEST(float_exp_null_neg_left_alignment){
        RUN_TEST("%-e", -0.0f)} END_TEST
    START_TEST(float_exp_fraction_short_left_alignment){
        RUN_TEST("%-e", 0.1234567f)} END_TEST
    START_TEST(float_exp_general_short_left_alignment){
        RUN_TEST("%-e", 1234.567f)} END_TEST
    START_TEST(float_EXP_null_left_alignment){RUN_TEST("%-E", 0.0f)} END_TEST
    START_TEST(float_EXP_null_neg_left_alignment){
        RUN_TEST("%-E", -0.0f)} END_TEST
    START_TEST(float_EXP_fraction_short_left_alignment){
        RUN_TEST("%-E", 0.1234567f)} END_TEST
    START_TEST(float_EXP_general_short_left_alignment){
        RUN_TEST("%-E", 1234.567f)} END_TEST
    START_TEST(float_g_null_left_alignment){RUN_TEST("%-g", 0.0f)} END_TEST
    START_TEST(float_g_null_neg_left_alignment){RUN_TEST("%-g", -0.0f)} END_TEST
    START_TEST(float_g_fraction_short_left_alignment){
        RUN_TEST("%-g", 0.1234567f)} END_TEST
    START_TEST(float_g_general_short_left_alignment){
        RUN_TEST("%-g", 1234.567f)} END_TEST
    START_TEST(float_G_null_left_alignment){RUN_TEST("%-G", 0.0f)} END_TEST
    START_TEST(float_G_null_neg_left_alignment){RUN_TEST("%-G", -0.0f)} END_TEST
    START_TEST(float_G_fraction_short_left_alignment){
        RUN_TEST("%-G", 0.1234567f)} END_TEST
    START_TEST(float_G_general_short_left_alignment){
        RUN_TEST("%-G", 1234.567f)} END_TEST
    START_TEST(float_null_leading_zeroes){RUN_TEST("%0f", 0.0f)} END_TEST
    START_TEST(float_null_neg_leading_zeroes){RUN_TEST("%0f", -0.0f)} END_TEST
    START_TEST(float_fraction_short_leading_zeroes){
        RUN_TEST("%0f", 0.1234567f)} END_TEST
    START_TEST(float_general_short_leading_zeroes){
        RUN_TEST("%0f", 1234.567f)} END_TEST
    START_TEST(float_exp_null_leading_zeroes){RUN_TEST("%0e", 0.0f)} END_TEST
    START_TEST(float_exp_null_neg_leading_zeroes){
        RUN_TEST("%0e", -0.0f)} END_TEST
    START_TEST(float_exp_fraction_short_leading_zeroes){
        RUN_TEST("%0e", 0.1234567f)} END_TEST
    START_TEST(float_exp_general_short_leading_zeroes){
        RUN_TEST("%0e", 1234.567f)} END_TEST
    START_TEST(float_EXP_null_leading_zeroes){RUN_TEST("%0E", 0.0f)} END_TEST
    START_TEST(float_EXP_null_neg_leading_zeroes){
        RUN_TEST("%0E", -0.0f)} END_TEST
    START_TEST(float_EXP_fraction_short_leading_zeroes){
        RUN_TEST("%0E", 0.1234567f)} END_TEST
    START_TEST(float_EXP_general_short_leading_zeroes){
        RUN_TEST("%0E", 1234.567f)} END_TEST
    START_TEST(float_g_null_leading_zeroes){RUN_TEST("%0g", 0.0f)} END_TEST
    START_TEST(float_g_null_neg_leading_zeroes){RUN_TEST("%0g", -0.0f)} END_TEST
    START_TEST(float_g_fraction_short_leading_zeroes){
        RUN_TEST("%0g", 0.1234567f)} END_TEST
    START_TEST(float_g_general_short_leading_zeroes){
        RUN_TEST("%0g", 1234.567f)} END_TEST
    START_TEST(float_G_null_leading_zeroes){RUN_TEST("%0G", 0.0f)} END_TEST
    START_TEST(float_G_null_neg_leading_zeroes){RUN_TEST("%0G", -0.0f)} END_TEST
    START_TEST(float_G_fraction_short_leading_zeroes){
        RUN_TEST("%0G", 0.1234567f)} END_TEST
    START_TEST(float_G_general_short_leading_zeroes){
        RUN_TEST("%0G", 1234.567f)} END_TEST
    START_TEST(float_null_alt_format){RUN_TEST("%#f", 0.0f)} END_TEST
    START_TEST(float_null_neg_alt_format){RUN_TEST("%#f", -0.0f)} END_TEST
    START_TEST(float_fraction_short_alt_format){
        RUN_TEST("%#f", 0.1234567f)} END_TEST
    START_TEST(float_general_short_alt_format){
        RUN_TEST("%#f", 1234.567f)} END_TEST
    START_TEST(float_exp_null_alt_format){RUN_TEST("%#e", 0.0f)} END_TEST
    START_TEST(float_exp_null_neg_alt_format){RUN_TEST("%#e", -0.0f)} END_TEST
    START_TEST(float_exp_fraction_short_alt_format){
        RUN_TEST("%#e", 0.1234567f)} END_TEST
    START_TEST(float_exp_general_short_alt_format){
        RUN_TEST("%#e", 1234.567f)} END_TEST
    START_TEST(float_EXP_null_alt_format){RUN_TEST("%#E", 0.0f)} END_TEST
    START_TEST(float_EXP_null_neg_alt_format){RUN_TEST("%#E", -0.0f)} END_TEST
    START_TEST(float_EXP_fraction_short_alt_format){
        RUN_TEST("%#E", 0.1234567f)} END_TEST
    START_TEST(float_EXP_general_short_alt_format){
        RUN_TEST("%#E", 1234.567f)} END_TEST
    START_TEST(float_g_null_alt_format){RUN_TEST("%#g", 0.0f)} END_TEST
    START_TEST(float_g_null_neg_alt_format){RUN_TEST("%#g", -0.0f)} END_TEST
    START_TEST(float_g_fraction_short_alt_format){
        RUN_TEST("%#g", 0.1234567f)} END_TEST
    START_TEST(float_g_general_short_alt_format){
        RUN_TEST("%#g", 1234.567f)} END_TEST
    START_TEST(float_G_null_alt_format){RUN_TEST("%#G", 0.0f)} END_TEST
    START_TEST(float_G_null_neg_alt_format){RUN_TEST("%#G", -0.0f)} END_TEST
    START_TEST(float_G_fraction_short_alt_format){
        RUN_TEST("%#G", 0.1234567f)} END_TEST
    START_TEST(float_G_general_short_alt_format){
        RUN_TEST("%#G", 1234.567f)} END_TEST
    START_TEST(float_null_no_width_no_precision){RUN_TEST("%f", 0.0f)} END_TEST
    START_TEST(float_null_neg_no_width_no_precision){
        RUN_TEST("%f", -0.0f)} END_TEST
    START_TEST(float_fraction_short_no_width_no_precision){
        RUN_TEST("%f", 0.1234567f)} END_TEST
    START_TEST(float_general_short_no_width_no_precision){
        RUN_TEST("%f", 1234.567f)} END_TEST
    START_TEST(float_exp_null_no_width_no_precision){
        RUN_TEST("%e", 0.0f)} END_TEST
    START_TEST(float_exp_null_neg_no_width_no_precision){
        RUN_TEST("%e", -0.0f)} END_TEST
    START_TEST(float_exp_fraction_short_no_width_no_precision){
        RUN_TEST("%e", 0.1234567f)} END_TEST
    START_TEST(float_exp_general_short_no_width_no_precision){
        RUN_TEST("%e", 1234.567f)} END_TEST
    START_TEST(float_EXP_null_no_width_no_precision){
        RUN_TEST("%E", 0.0f)} END_TEST
    START_TEST(float_EXP_null_neg_no_width_no_precision){
        RUN_TEST("%E", -0.0f)} END_TEST
    START_TEST(float_EXP_fraction_short_no_width_no_precision){
        RUN_TEST("%E", 0.1234567f)} END_TEST
    START_TEST(float_EXP_general_short_no_width_no_precision){
        RUN_TEST("%E", 1234.567f)} END_TEST
    START_TEST(float_g_null_no_width_no_precision){
        RUN_TEST("%g", 0.0f)} END_TEST
    START_TEST(float_g_null_neg_no_width_no_precision){
        RUN_TEST("%g", -0.0f)} END_TEST
    START_TEST(float_g_fraction_short_no_width_no_precision){
        RUN_TEST("%g", 0.1234567f)} END_TEST
    START_TEST(float_g_general_short_no_width_no_precision){
        RUN_TEST("%g", 1234.567f)} END_TEST
    START_TEST(float_G_null_no_width_no_precision){
        RUN_TEST("%G", 0.0f)} END_TEST
    START_TEST(float_G_null_neg_no_width_no_precision){
        RUN_TEST("%G", -0.0f)} END_TEST
    START_TEST(float_G_fraction_short_no_width_no_precision){
        RUN_TEST("%G", 0.1234567f)} END_TEST
    START_TEST(float_G_general_short_no_width_no_precision){
        RUN_TEST("%G", 1234.567f)} END_TEST
    START_TEST(float_null_no_width_small_precision){
        RUN_TEST("%.3f", 0.0f)} END_TEST
    START_TEST(float_null_neg_no_width_small_precision){
        RUN_TEST("%.3f", -0.0f)} END_TEST
    START_TEST(float_fraction_short_no_width_small_precision){
        RUN_TEST("%.3f", 0.1234567f)} END_TEST
    START_TEST(float_general_short_no_width_small_precision){
        RUN_TEST("%.3f", 1234.567f)} END_TEST
    START_TEST(float_exp_null_no_width_small_precision){
        RUN_TEST("%.3e", 0.0f)} END_TEST
    START_TEST(float_exp_null_neg_no_width_small_precision){
        RUN_TEST("%.3e", -0.0f)} END_TEST
    START_TEST(float_exp_fraction_short_no_width_small_precision){
        RUN_TEST("%.3e", 0.1234567f)} END_TEST
    START_TEST(float_exp_general_short_no_width_small_precision){
        RUN_TEST("%.3e", 1234.567f)} END_TEST
    START_TEST(float_EXP_null_no_width_small_precision){
        RUN_TEST("%.3E", 0.0f)} END_TEST
    START_TEST(float_EXP_null_neg_no_width_small_precision){
        RUN_TEST("%.3E", -0.0f)} END_TEST
    START_TEST(float_EXP_fraction_short_no_width_small_precision){
        RUN_TEST("%.3E", 0.1234567f)} END_TEST
    START_TEST(float_EXP_general_short_no_width_small_precision){
        RUN_TEST("%.3E", 1234.567f)} END_TEST
    START_TEST(float_g_null_no_width_small_precision){
        RUN_TEST("%.3g", 0.0f)} END_TEST
    START_TEST(float_g_null_neg_no_width_small_precision){
        RUN_TEST("%.3g", -0.0f)} END_TEST
    START_TEST(float_g_fraction_short_no_width_small_precision){
        RUN_TEST("%.3g", 0.1234567f)} END_TEST
    START_TEST(float_g_general_short_no_width_small_precision){
        RUN_TEST("%.3g", 1234.567f)} END_TEST
    START_TEST(float_G_null_no_width_small_precision){
        RUN_TEST("%.3G", 0.0f)} END_TEST
    START_TEST(float_G_null_neg_no_width_small_precision){
        RUN_TEST("%.3G", -0.0f)} END_TEST
    START_TEST(float_G_fraction_short_no_width_small_precision){
        RUN_TEST("%.3G", 0.1234567f)} END_TEST
    START_TEST(float_G_general_short_no_width_small_precision){
        RUN_TEST("%.3G", 1234.567f)} END_TEST
    START_TEST(float_null_no_width_big_precision){
        RUN_TEST("%.14f", 0.0f)} END_TEST
    START_TEST(float_null_neg_no_width_big_precision){
        RUN_TEST("%.14f", -0.0f)} END_TEST
    START_TEST(float_fraction_short_no_width_big_precision){
        RUN_TEST("%.14f", 0.1234567f)} END_TEST
    START_TEST(float_general_short_no_width_big_precision){
        RUN_TEST("%.14f", 1234.567f)} END_TEST
    START_TEST(float_exp_null_no_width_big_precision){
        RUN_TEST("%.14e", 0.0f)} END_TEST
    START_TEST(float_exp_null_neg_no_width_big_precision){
        RUN_TEST("%.14e", -0.0f)} END_TEST
    START_TEST(float_exp_fraction_short_no_width_big_precision){
        RUN_TEST("%.14e", 0.1234567f)} END_TEST
    START_TEST(float_exp_general_short_no_width_big_precision){
        RUN_TEST("%.14e", 1234.567f)} END_TEST
    START_TEST(float_EXP_null_no_width_big_precision){
        RUN_TEST("%.14E", 0.0f)} END_TEST
    START_TEST(float_EXP_null_neg_no_width_big_precision){
        RUN_TEST("%.14E", -0.0f)} END_TEST
    START_TEST(float_EXP_fraction_short_no_width_big_precision){
        RUN_TEST("%.14E", 0.1234567f)} END_TEST
    START_TEST(float_EXP_general_short_no_width_big_precision){
        RUN_TEST("%.14E", 1234.567f)} END_TEST
    START_TEST(float_g_null_no_width_big_precision){
        RUN_TEST("%.14g", 0.0f)} END_TEST
    START_TEST(float_g_null_neg_no_width_big_precision){
        RUN_TEST("%.14g", -0.0f)} END_TEST
    START_TEST(float_g_fraction_short_no_width_big_precision){
        RUN_TEST("%.14g", 0.1234567f)} END_TEST
    START_TEST(float_g_general_short_no_width_big_precision){
        RUN_TEST("%.14g", 1234.567f)} END_TEST
    START_TEST(float_G_null_no_width_big_precision){
        RUN_TEST("%.14G", 0.0f)} END_TEST
    START_TEST(float_G_null_neg_no_width_big_precision){
        RUN_TEST("%.14G", -0.0f)} END_TEST
    START_TEST(float_G_fraction_short_no_width_big_precision){
        RUN_TEST("%.14G", 0.1234567f)} END_TEST
    START_TEST(float_G_general_short_no_width_big_precision){
        RUN_TEST("%.14G", 1234.567f)} END_TEST
    START_TEST(float_null_small_width_no_precision){
        RUN_TEST("%1f", 0.0f)} END_TEST
    START_TEST(float_null_neg_small_width_no_precision){
        RUN_TEST("%1f", -0.0f)} END_TEST
    START_TEST(float_fraction_short_small_width_no_precision){
        RUN_TEST("%1f", 0.1234567f)} END_TEST
    START_TEST(float_general_short_small_width_no_precision){
        RUN_TEST("%1f", 1234.567f)} END_TEST
    START_TEST(float_exp_null_small_width_no_precision){
        RUN_TEST("%1e", 0.0f)} END_TEST
    START_TEST(float_exp_null_neg_small_width_no_precision){
        RUN_TEST("%1e", -0.0f)} END_TEST
    START_TEST(float_exp_fraction_short_small_width_no_precision){
        RUN_TEST("%1e", 0.1234567f)} END_TEST
    START_TEST(float_exp_general_short_small_width_no_precision){
        RUN_TEST("%1e", 1234.567f)} END_TEST
    START_TEST(float_EXP_null_small_width_no_precision){
        RUN_TEST("%1E", 0.0f)} END_TEST
    START_TEST(float_EXP_null_neg_small_width_no_precision){
        RUN_TEST("%1E", -0.0f)} END_TEST
    START_TEST(float_EXP_fraction_short_small_width_no_precision){
        RUN_TEST("%1E", 0.1234567f)} END_TEST
    START_TEST(float_EXP_general_short_small_width_no_precision){
        RUN_TEST("%1E", 1234.567f)} END_TEST
    START_TEST(float_g_null_small_width_no_precision){
        RUN_TEST("%1g", 0.0f)} END_TEST
    START_TEST(float_g_null_neg_small_width_no_precision){
        RUN_TEST("%1g", -0.0f)} END_TEST
    START_TEST(float_g_fraction_short_small_width_no_precision){
        RUN_TEST("%1g", 0.1234567f)} END_TEST
    START_TEST(float_g_general_short_small_width_no_precision){
        RUN_TEST("%1g", 1234.567f)} END_TEST
    START_TEST(float_G_null_small_width_no_precision){
        RUN_TEST("%1G", 0.0f)} END_TEST
    START_TEST(float_G_null_neg_small_width_no_precision){
        RUN_TEST("%1G", -0.0f)} END_TEST
    START_TEST(float_G_fraction_short_small_width_no_precision){
        RUN_TEST("%1G", 0.1234567f)} END_TEST
    START_TEST(float_G_general_short_small_width_no_precision){
        RUN_TEST("%1G", 1234.567f)} END_TEST
    START_TEST(float_null_small_width_small_precision){
        RUN_TEST("%1.3f", 0.0f)} END_TEST
    START_TEST(float_null_neg_small_width_small_precision){
        RUN_TEST("%1.3f", -0.0f)} END_TEST
    START_TEST(float_fraction_short_small_width_small_precision){
        RUN_TEST("%1.3f", 0.1234567f)} END_TEST
    START_TEST(float_general_short_small_width_small_precision){
        RUN_TEST("%1.3f", 1234.567f)} END_TEST
    START_TEST(float_exp_null_small_width_small_precision){
        RUN_TEST("%1.3e", 0.0f)} END_TEST
    START_TEST(float_exp_null_neg_small_width_small_precision){
        RUN_TEST("%1.3e", -0.0f)} END_TEST
    START_TEST(float_exp_fraction_short_small_width_small_precision){
        RUN_TEST("%1.3e", 0.1234567f)} END_TEST
    START_TEST(float_exp_general_short_small_width_small_precision){
        RUN_TEST("%1.3e", 1234.567f)} END_TEST
    START_TEST(float_EXP_null_small_width_small_precision){
        RUN_TEST("%1.3E", 0.0f)} END_TEST
    START_TEST(float_EXP_null_neg_small_width_small_precision){
        RUN_TEST("%1.3E", -0.0f)} END_TEST
    START_TEST(float_EXP_fraction_short_small_width_small_precision){
        RUN_TEST("%1.3E", 0.1234567f)} END_TEST
    START_TEST(float_EXP_general_short_small_width_small_precision){
        RUN_TEST("%1.3E", 1234.567f)} END_TEST
    START_TEST(float_g_null_small_width_small_precision){
        RUN_TEST("%1.3g", 0.0f)} END_TEST
    START_TEST(float_g_null_neg_small_width_small_precision){
        RUN_TEST("%1.3g", -0.0f)} END_TEST
    START_TEST(float_g_fraction_short_small_width_small_precision){
        RUN_TEST("%1.3g", 0.1234567f)} END_TEST
    START_TEST(float_g_general_short_small_width_small_precision){
        RUN_TEST("%1.3g", 1234.567f)} END_TEST
    START_TEST(float_G_null_small_width_small_precision){
        RUN_TEST("%1.3G", 0.0f)} END_TEST
    START_TEST(float_G_null_neg_small_width_small_precision){
        RUN_TEST("%1.3G", -0.0f)} END_TEST
    START_TEST(float_G_fraction_short_small_width_small_precision){
        RUN_TEST("%1.3G", 0.1234567f)} END_TEST
    START_TEST(float_G_general_short_small_width_small_precision){
        RUN_TEST("%1.3G", 1234.567f)} END_TEST
    START_TEST(float_null_small_width_big_precision){
        RUN_TEST("%1.14f", 0.0f)} END_TEST
    START_TEST(float_null_neg_small_width_big_precision){
        RUN_TEST("%1.14f", -0.0f)} END_TEST
    START_TEST(float_fraction_short_small_width_big_precision){
        RUN_TEST("%1.14f", 0.1234567f)} END_TEST
    START_TEST(float_general_short_small_width_big_precision){
        RUN_TEST("%1.14f", 1234.567f)} END_TEST
    START_TEST(float_exp_null_small_width_big_precision){
        RUN_TEST("%1.14e", 0.0f)} END_TEST
    START_TEST(float_exp_null_neg_small_width_big_precision){
        RUN_TEST("%1.14e", -0.0f)} END_TEST
    START_TEST(float_exp_fraction_short_small_width_big_precision){
        RUN_TEST("%1.14e", 0.1234567f)} END_TEST
    START_TEST(float_exp_general_short_small_width_big_precision){
        RUN_TEST("%1.14e", 1234.567f)} END_TEST
    START_TEST(float_EXP_null_small_width_big_precision){
        RUN_TEST("%1.14E", 0.0f)} END_TEST
    START_TEST(float_EXP_null_neg_small_width_big_precision){
        RUN_TEST("%1.14E", -0.0f)} END_TEST
    START_TEST(float_EXP_fraction_short_small_width_big_precision){
        RUN_TEST("%1.14E", 0.1234567f)} END_TEST
    START_TEST(float_EXP_general_short_small_width_big_precision){
        RUN_TEST("%1.14E", 1234.567f)} END_TEST
    START_TEST(float_g_null_small_width_big_precision){
        RUN_TEST("%1.14g", 0.0f)} END_TEST
    START_TEST(float_g_null_neg_small_width_big_precision){
        RUN_TEST("%1.14g", -0.0f)} END_TEST
    START_TEST(float_g_fraction_short_small_width_big_precision){
        RUN_TEST("%1.14g", 0.1234567f)} END_TEST
    START_TEST(float_g_general_short_small_width_big_precision){
        RUN_TEST("%1.14g", 1234.567f)} END_TEST
    START_TEST(float_G_null_small_width_big_precision){
        RUN_TEST("%1.14G", 0.0f)} END_TEST
    START_TEST(float_G_null_neg_small_width_big_precision){
        RUN_TEST("%1.14G", -0.0f)} END_TEST
    START_TEST(float_G_fraction_short_small_width_big_precision){
        RUN_TEST("%1.14G", 0.1234567f)} END_TEST
    START_TEST(float_G_general_short_small_width_big_precision){
        RUN_TEST("%1.14G", 1234.567f)} END_TEST
    START_TEST(float_null_big_width_no_precision){
        RUN_TEST("%50f", 0.0f)} END_TEST
    START_TEST(float_null_neg_big_width_no_precision){
        RUN_TEST("%50f", -0.0f)} END_TEST
    START_TEST(float_fraction_short_big_width_no_precision){
        RUN_TEST("%50f", 0.1234567f)} END_TEST
    START_TEST(float_general_short_big_width_no_precision){
        RUN_TEST("%50f", 1234.567f)} END_TEST
    START_TEST(float_exp_null_big_width_no_precision){
        RUN_TEST("%50e", 0.0f)} END_TEST
    START_TEST(float_exp_null_neg_big_width_no_precision){
        RUN_TEST("%50e", -0.0f)} END_TEST
    START_TEST(float_exp_fraction_short_big_width_no_precision){
        RUN_TEST("%50e", 0.1234567f)} END_TEST
    START_TEST(float_exp_general_short_big_width_no_precision){
        RUN_TEST("%50e", 1234.567f)} END_TEST
    START_TEST(float_EXP_null_big_width_no_precision){
        RUN_TEST("%50E", 0.0f)} END_TEST
    START_TEST(float_EXP_null_neg_big_width_no_precision){
        RUN_TEST("%50E", -0.0f)} END_TEST
    START_TEST(float_EXP_fraction_short_big_width_no_precision){
        RUN_TEST("%50E", 0.1234567f)} END_TEST
    START_TEST(float_EXP_general_short_big_width_no_precision){
        RUN_TEST("%50E", 1234.567f)} END_TEST
    START_TEST(float_g_null_big_width_no_precision){
        RUN_TEST("%50g", 0.0f)} END_TEST
    START_TEST(float_g_null_neg_big_width_no_precision){
        RUN_TEST("%50g", -0.0f)} END_TEST
    START_TEST(float_g_fraction_short_big_width_no_precision){
        RUN_TEST("%50g", 0.1234567f)} END_TEST
    START_TEST(float_g_general_short_big_width_no_precision){
        RUN_TEST("%50g", 1234.567f)} END_TEST
    START_TEST(float_G_null_big_width_no_precision){
        RUN_TEST("%50G", 0.0f)} END_TEST
    START_TEST(float_G_null_neg_big_width_no_precision){
        RUN_TEST("%50G", -0.0f)} END_TEST
    START_TEST(float_G_fraction_short_big_width_no_precision){
        RUN_TEST("%50G", 0.1234567f)} END_TEST
    START_TEST(float_G_general_short_big_width_no_precision){
        RUN_TEST("%50G", 1234.567f)} END_TEST
    START_TEST(float_null_big_width_small_precision){
        RUN_TEST("%50.3f", 0.0f)} END_TEST
    START_TEST(float_null_neg_big_width_small_precision){
        RUN_TEST("%50.3f", -0.0f)} END_TEST
    START_TEST(float_fraction_short_big_width_small_precision){
        RUN_TEST("%50.3f", 0.1234567f)} END_TEST
    START_TEST(float_general_short_big_width_small_precision){
        RUN_TEST("%50.3f", 1234.567f)} END_TEST
    START_TEST(float_exp_null_big_width_small_precision){
        RUN_TEST("%50.3e", 0.0f)} END_TEST
    START_TEST(float_exp_null_neg_big_width_small_precision){
        RUN_TEST("%50.3e", -0.0f)} END_TEST
    START_TEST(float_exp_fraction_short_big_width_small_precision){
        RUN_TEST("%50.3e", 0.1234567f)} END_TEST
    START_TEST(float_exp_general_short_big_width_small_precision){
        RUN_TEST("%50.3e", 1234.567f)} END_TEST
    START_TEST(float_EXP_null_big_width_small_precision){
        RUN_TEST("%50.3E", 0.0f)} END_TEST
    START_TEST(float_EXP_null_neg_big_width_small_precision){
        RUN_TEST("%50.3E", -0.0f)} END_TEST
    START_TEST(float_EXP_fraction_short_big_width_small_precision){
        RUN_TEST("%50.3E", 0.1234567f)} END_TEST
    START_TEST(float_EXP_general_short_big_width_small_precision){
        RUN_TEST("%50.3E", 1234.567f)} END_TEST
    START_TEST(float_g_null_big_width_small_precision){
        RUN_TEST("%50.3g", 0.0f)} END_TEST
    START_TEST(float_g_null_neg_big_width_small_precision){
        RUN_TEST("%50.3g", -0.0f)} END_TEST
    START_TEST(float_g_fraction_short_big_width_small_precision){
        RUN_TEST("%50.3g", 0.1234567f)} END_TEST
    START_TEST(float_g_general_short_big_width_small_precision){
        RUN_TEST("%50.3g", 1234.567f)} END_TEST
    START_TEST(float_G_null_big_width_small_precision){
        RUN_TEST("%50.3G", 0.0f)} END_TEST
    START_TEST(float_G_null_neg_big_width_small_precision){
        RUN_TEST("%50.3G", -0.0f)} END_TEST
    START_TEST(float_G_fraction_short_big_width_small_precision){
        RUN_TEST("%50.3G", 0.1234567f)} END_TEST
    START_TEST(float_G_general_short_big_width_small_precision){
        RUN_TEST("%50.3G", 1234.567f)} END_TEST
    START_TEST(float_null_big_width_big_precision){
        RUN_TEST("%50.14f", 0.0f)} END_TEST
    START_TEST(float_null_neg_big_width_big_precision){
        RUN_TEST("%50.14f", -0.0f)} END_TEST
    START_TEST(float_fraction_short_big_width_big_precision){
        RUN_TEST("%50.14f", 0.1234567f)} END_TEST
    START_TEST(float_general_short_big_width_big_precision){
        RUN_TEST("%50.14f", 1234.567f)} END_TEST
    START_TEST(float_exp_null_big_width_big_precision){
        RUN_TEST("%50.14e", 0.0f)} END_TEST
    START_TEST(float_exp_null_neg_big_width_big_precision){
        RUN_TEST("%50.14e", -0.0f)} END_TEST
    START_TEST(float_exp_fraction_short_big_width_big_precision){
        RUN_TEST("%50.14e", 0.1234567f)} END_TEST
    START_TEST(float_exp_general_short_big_width_big_precision){
        RUN_TEST("%50.14e", 1234.567f)} END_TEST
    START_TEST(float_EXP_null_big_width_big_precision){
        RUN_TEST("%50.14E", 0.0f)} END_TEST
    START_TEST(float_EXP_null_neg_big_width_big_precision){
        RUN_TEST("%50.14E", -0.0f)} END_TEST
    START_TEST(float_EXP_fraction_short_big_width_big_precision){
        RUN_TEST("%50.14E", 0.1234567f)} END_TEST
    START_TEST(float_EXP_general_short_big_width_big_precision){
        RUN_TEST("%50.14E", 1234.567f)} END_TEST
    START_TEST(float_g_null_big_width_big_precision){
        RUN_TEST("%50.14g", 0.0f)} END_TEST
    START_TEST(float_g_null_neg_big_width_big_precision){
        RUN_TEST("%50.14g", -0.0f)} END_TEST
    START_TEST(float_g_fraction_short_big_width_big_precision){
        RUN_TEST("%50.14g", 0.1234567f)} END_TEST
    START_TEST(float_g_general_short_big_width_big_precision){
        RUN_TEST("%50.14g", 1234.567f)} END_TEST
    START_TEST(float_G_null_big_width_big_precision){
        RUN_TEST("%50.14G", 0.0f)} END_TEST
    START_TEST(float_G_null_neg_big_width_big_precision){
        RUN_TEST("%50.14G", -0.0f)} END_TEST
    START_TEST(float_G_fraction_short_big_width_big_precision){
        RUN_TEST("%50.14G", 0.1234567f)} END_TEST
    START_TEST(float_G_general_short_big_width_big_precision){
        RUN_TEST("%50.14G", 1234.567f)} END_TEST

    START_TEST(double_null_no_flags){RUN_TEST("%lf", 0.0)} END_TEST
    START_TEST(double_null_neg_no_flags){RUN_TEST("%lf", -0.0)} END_TEST
    START_TEST(double_fraction_medium_no_flags){
        RUN_TEST("%lf", 0.123456789101112)} END_TEST
    START_TEST(double_general_medium_no_flags){
        RUN_TEST("%lf", 1234.56789101112)} END_TEST
    START_TEST(double_exp_null_no_flags){RUN_TEST("%le", 0.0)} END_TEST
    START_TEST(double_exp_null_neg_no_flags){RUN_TEST("%le", -0.0)} END_TEST
    START_TEST(double_exp_fraction_medium_no_flags){
        RUN_TEST("%le", 0.123456789101112)} END_TEST
    START_TEST(double_exp_general_medium_no_flags){
        RUN_TEST("%le", 1234.56789101112)} END_TEST
    START_TEST(double_EXP_null_no_flags){RUN_TEST("%lE", 0.0)} END_TEST
    START_TEST(double_EXP_null_neg_no_flags){RUN_TEST("%lE", -0.0)} END_TEST
    START_TEST(double_EXP_fraction_medium_no_flags){
        RUN_TEST("%lE", 0.123456789101112)} END_TEST
    START_TEST(double_EXP_general_medium_no_flags){
        RUN_TEST("%lE", 1234.56789101112)} END_TEST
    START_TEST(double_g_null_no_flags){RUN_TEST("%lg", 0.0)} END_TEST
    START_TEST(double_g_null_neg_no_flags){RUN_TEST("%lg", -0.0)} END_TEST
    START_TEST(double_g_fraction_medium_no_flags){
        RUN_TEST("%lg", 0.123456789101112)} END_TEST
    START_TEST(double_g_general_medium_no_flags){
        RUN_TEST("%lg", 1234.56789101112)} END_TEST
    START_TEST(double_G_null_no_flags){RUN_TEST("%lG", 0.0)} END_TEST
    START_TEST(double_G_null_neg_no_flags){RUN_TEST("%lG", -0.0)} END_TEST
    START_TEST(double_G_fraction_medium_no_flags){
        RUN_TEST("%lG", 0.123456789101112)} END_TEST
    START_TEST(double_G_general_medium_no_flags){
        RUN_TEST("%lG", 1234.56789101112)} END_TEST
    START_TEST(double_null_prefix_sign){RUN_TEST("%+lf", 0.0)} END_TEST
    START_TEST(double_null_neg_prefix_sign){RUN_TEST("%+lf", -0.0)} END_TEST
    START_TEST(double_fraction_medium_prefix_sign){
        RUN_TEST("%+lf", 0.123456789101112)} END_TEST
    START_TEST(double_general_medium_prefix_sign){
        RUN_TEST("%+lf", 1234.56789101112)} END_TEST
    START_TEST(double_exp_null_prefix_sign){RUN_TEST("%+le", 0.0)} END_TEST
    START_TEST(double_exp_null_neg_prefix_sign){RUN_TEST("%+le", -0.0)} END_TEST
    START_TEST(double_exp_fraction_medium_prefix_sign){
        RUN_TEST("%+le", 0.123456789101112)} END_TEST
    START_TEST(double_exp_general_medium_prefix_sign){
        RUN_TEST("%+le", 1234.56789101112)} END_TEST
    START_TEST(double_EXP_null_prefix_sign){RUN_TEST("%+lE", 0.0)} END_TEST
    START_TEST(double_EXP_null_neg_prefix_sign){RUN_TEST("%+lE", -0.0)} END_TEST
    START_TEST(double_EXP_fraction_medium_prefix_sign){
        RUN_TEST("%+lE", 0.123456789101112)} END_TEST
    START_TEST(double_EXP_general_medium_prefix_sign){
        RUN_TEST("%+lE", 1234.56789101112)} END_TEST
    START_TEST(double_g_null_prefix_sign){RUN_TEST("%+lg", 0.0)} END_TEST
    START_TEST(double_g_null_neg_prefix_sign){RUN_TEST("%+lg", -0.0)} END_TEST
    START_TEST(double_g_fraction_medium_prefix_sign){
        RUN_TEST("%+lg", 0.123456789101112)} END_TEST
    START_TEST(double_g_general_medium_prefix_sign){
        RUN_TEST("%+lg", 1234.56789101112)} END_TEST
    START_TEST(double_G_null_prefix_sign){RUN_TEST("%+lG", 0.0)} END_TEST
    START_TEST(double_G_null_neg_prefix_sign){RUN_TEST("%+lG", -0.0)} END_TEST
    START_TEST(double_G_fraction_medium_prefix_sign){
        RUN_TEST("%+lG", 0.123456789101112)} END_TEST
    START_TEST(double_G_general_medium_prefix_sign){
        RUN_TEST("%+lG", 1234.56789101112)} END_TEST
    START_TEST(double_null_prefix_space){RUN_TEST("% lf", 0.0)} END_TEST
    START_TEST(double_null_neg_prefix_space){RUN_TEST("% lf", -0.0)} END_TEST
    START_TEST(double_fraction_medium_prefix_space){
        RUN_TEST("% lf", 0.123456789101112)} END_TEST
    START_TEST(double_general_medium_prefix_space){
        RUN_TEST("% lf", 1234.56789101112)} END_TEST
    START_TEST(double_exp_null_prefix_space){RUN_TEST("% le", 0.0)} END_TEST
    START_TEST(double_exp_null_neg_prefix_space){
        RUN_TEST("% le", -0.0)} END_TEST
    START_TEST(double_exp_fraction_medium_prefix_space){
        RUN_TEST("% le", 0.123456789101112)} END_TEST
    START_TEST(double_exp_general_medium_prefix_space){
        RUN_TEST("% le", 1234.56789101112)} END_TEST
    START_TEST(double_EXP_null_prefix_space){RUN_TEST("% lE", 0.0)} END_TEST
    START_TEST(double_EXP_null_neg_prefix_space){
        RUN_TEST("% lE", -0.0)} END_TEST
    START_TEST(double_EXP_fraction_medium_prefix_space){
        RUN_TEST("% lE", 0.123456789101112)} END_TEST
    START_TEST(double_EXP_general_medium_prefix_space){
        RUN_TEST("% lE", 1234.56789101112)} END_TEST
    START_TEST(double_g_null_prefix_space){RUN_TEST("% lg", 0.0)} END_TEST
    START_TEST(double_g_null_neg_prefix_space){RUN_TEST("% lg", -0.0)} END_TEST
    START_TEST(double_g_fraction_medium_prefix_space){
        RUN_TEST("% lg", 0.123456789101112)} END_TEST
    START_TEST(double_g_general_medium_prefix_space){
        RUN_TEST("% lg", 1234.56789101112)} END_TEST
    START_TEST(double_G_null_prefix_space){RUN_TEST("% lG", 0.0)} END_TEST
    START_TEST(double_G_null_neg_prefix_space){RUN_TEST("% lG", -0.0)} END_TEST
    START_TEST(double_G_fraction_medium_prefix_space){
        RUN_TEST("% lG", 0.123456789101112)} END_TEST
    START_TEST(double_G_general_medium_prefix_space){
        RUN_TEST("% lG", 1234.56789101112)} END_TEST
    START_TEST(double_null_left_alignment){RUN_TEST("%-lf", 0.0)} END_TEST
    START_TEST(double_null_neg_left_alignment){RUN_TEST("%-lf", -0.0)} END_TEST
    START_TEST(double_fraction_medium_left_alignment){
        RUN_TEST("%-lf", 0.123456789101112)} END_TEST
    START_TEST(double_general_medium_left_alignment){
        RUN_TEST("%-lf", 1234.56789101112)} END_TEST
    START_TEST(double_exp_null_left_alignment){RUN_TEST("%-le", 0.0)} END_TEST
    START_TEST(double_exp_null_neg_left_alignment){
        RUN_TEST("%-le", -0.0)} END_TEST
    START_TEST(double_exp_fraction_medium_left_alignment){
        RUN_TEST("%-le", 0.123456789101112)} END_TEST
    START_TEST(double_exp_general_medium_left_alignment){
        RUN_TEST("%-le", 1234.56789101112)} END_TEST
    START_TEST(double_EXP_null_left_alignment){RUN_TEST("%-lE", 0.0)} END_TEST
    START_TEST(double_EXP_null_neg_left_alignment){
        RUN_TEST("%-lE", -0.0)} END_TEST
    START_TEST(double_EXP_fraction_medium_left_alignment){
        RUN_TEST("%-lE", 0.123456789101112)} END_TEST
    START_TEST(double_EXP_general_medium_left_alignment){
        RUN_TEST("%-lE", 1234.56789101112)} END_TEST
    START_TEST(double_g_null_left_alignment){RUN_TEST("%-lg", 0.0)} END_TEST
    START_TEST(double_g_null_neg_left_alignment){
        RUN_TEST("%-lg", -0.0)} END_TEST
    START_TEST(double_g_fraction_medium_left_alignment){
        RUN_TEST("%-lg", 0.123456789101112)} END_TEST
    START_TEST(double_g_general_medium_left_alignment){
        RUN_TEST("%-lg", 1234.56789101112)} END_TEST
    START_TEST(double_G_null_left_alignment){RUN_TEST("%-lG", 0.0)} END_TEST
    START_TEST(double_G_null_neg_left_alignment){
        RUN_TEST("%-lG", -0.0)} END_TEST
    START_TEST(double_G_fraction_medium_left_alignment){
        RUN_TEST("%-lG", 0.123456789101112)} END_TEST
    START_TEST(double_G_general_medium_left_alignment){
        RUN_TEST("%-lG", 1234.56789101112)} END_TEST
    START_TEST(double_null_leading_zeroes){RUN_TEST("%0lf", 0.0)} END_TEST
    START_TEST(double_null_neg_leading_zeroes){RUN_TEST("%0lf", -0.0)} END_TEST
    START_TEST(double_fraction_medium_leading_zeroes){
        RUN_TEST("%0lf", 0.123456789101112)} END_TEST
    START_TEST(double_general_medium_leading_zeroes){
        RUN_TEST("%0lf", 1234.56789101112)} END_TEST
    START_TEST(double_exp_null_leading_zeroes){RUN_TEST("%0le", 0.0)} END_TEST
    START_TEST(double_exp_null_neg_leading_zeroes){
        RUN_TEST("%0le", -0.0)} END_TEST
    START_TEST(double_exp_fraction_medium_leading_zeroes){
        RUN_TEST("%0le", 0.123456789101112)} END_TEST
    START_TEST(double_exp_general_medium_leading_zeroes){
        RUN_TEST("%0le", 1234.56789101112)} END_TEST
    START_TEST(double_EXP_null_leading_zeroes){RUN_TEST("%0lE", 0.0)} END_TEST
    START_TEST(double_EXP_null_neg_leading_zeroes){
        RUN_TEST("%0lE", -0.0)} END_TEST
    START_TEST(double_EXP_fraction_medium_leading_zeroes){
        RUN_TEST("%0lE", 0.123456789101112)} END_TEST
    START_TEST(double_EXP_general_medium_leading_zeroes){
        RUN_TEST("%0lE", 1234.56789101112)} END_TEST
    START_TEST(double_g_null_leading_zeroes){RUN_TEST("%0lg", 0.0)} END_TEST
    START_TEST(double_g_null_neg_leading_zeroes){
        RUN_TEST("%0lg", -0.0)} END_TEST
    START_TEST(double_g_fraction_medium_leading_zeroes){
        RUN_TEST("%0lg", 0.123456789101112)} END_TEST
    START_TEST(double_g_general_medium_leading_zeroes){
        RUN_TEST("%0lg", 1234.56789101112)} END_TEST
    START_TEST(double_G_null_leading_zeroes){RUN_TEST("%0lG", 0.0)} END_TEST
    START_TEST(double_G_null_neg_leading_zeroes){
        RUN_TEST("%0lG", -0.0)} END_TEST
    START_TEST(double_G_fraction_medium_leading_zeroes){
        RUN_TEST("%0lG", 0.123456789101112)} END_TEST
    START_TEST(double_G_general_medium_leading_zeroes){
        RUN_TEST("%0lG", 1234.56789101112)} END_TEST
    START_TEST(double_null_alt_format){RUN_TEST("%#lf", 0.0)} END_TEST
    START_TEST(double_null_neg_alt_format){RUN_TEST("%#lf", -0.0)} END_TEST
    START_TEST(double_fraction_medium_alt_format){
        RUN_TEST("%#lf", 0.123456789101112)} END_TEST
    START_TEST(double_general_medium_alt_format){
        RUN_TEST("%#lf", 1234.56789101112)} END_TEST
    START_TEST(double_exp_null_alt_format){RUN_TEST("%#le", 0.0)} END_TEST
    START_TEST(double_exp_null_neg_alt_format){RUN_TEST("%#le", -0.0)} END_TEST
    START_TEST(double_exp_fraction_medium_alt_format){
        RUN_TEST("%#le", 0.123456789101112)} END_TEST
    START_TEST(double_exp_general_medium_alt_format){
        RUN_TEST("%#le", 1234.56789101112)} END_TEST
    START_TEST(double_EXP_null_alt_format){RUN_TEST("%#lE", 0.0)} END_TEST
    START_TEST(double_EXP_null_neg_alt_format){RUN_TEST("%#lE", -0.0)} END_TEST
    START_TEST(double_EXP_fraction_medium_alt_format){
        RUN_TEST("%#lE", 0.123456789101112)} END_TEST
    START_TEST(double_EXP_general_medium_alt_format){
        RUN_TEST("%#lE", 1234.56789101112)} END_TEST
    START_TEST(double_g_null_alt_format){RUN_TEST("%#lg", 0.0)} END_TEST
    START_TEST(double_g_null_neg_alt_format){RUN_TEST("%#lg", -0.0)} END_TEST
    START_TEST(double_g_fraction_medium_alt_format){
        RUN_TEST("%#lg", 0.123456789101112)} END_TEST
    START_TEST(double_g_general_medium_alt_format){
        RUN_TEST("%#lg", 1234.56789101112)} END_TEST
    START_TEST(double_G_null_alt_format){RUN_TEST("%#lG", 0.0)} END_TEST
    START_TEST(double_G_null_neg_alt_format){RUN_TEST("%#lG", -0.0)} END_TEST
    START_TEST(double_G_fraction_medium_alt_format){
        RUN_TEST("%#lG", 0.123456789101112)} END_TEST
    START_TEST(double_G_general_medium_alt_format){
        RUN_TEST("%#lG", 1234.56789101112)} END_TEST
    START_TEST(double_null_no_width_no_precision){RUN_TEST("%lf", 0.0)} END_TEST
    START_TEST(double_null_neg_no_width_no_precision){
        RUN_TEST("%lf", -0.0)} END_TEST
    START_TEST(double_fraction_medium_no_width_no_precision){
        RUN_TEST("%lf", 0.123456789101112)} END_TEST
    START_TEST(double_general_medium_no_width_no_precision){
        RUN_TEST("%lf", 1234.56789101112)} END_TEST
    START_TEST(double_exp_null_no_width_no_precision){
        RUN_TEST("%le", 0.0)} END_TEST
    START_TEST(double_exp_null_neg_no_width_no_precision){
        RUN_TEST("%le", -0.0)} END_TEST
    START_TEST(double_exp_fraction_medium_no_width_no_precision){
        RUN_TEST("%le", 0.123456789101112)} END_TEST
    START_TEST(double_exp_general_medium_no_width_no_precision){
        RUN_TEST("%le", 1234.56789101112)} END_TEST
    START_TEST(double_EXP_null_no_width_no_precision){
        RUN_TEST("%lE", 0.0)} END_TEST
    START_TEST(double_EXP_null_neg_no_width_no_precision){
        RUN_TEST("%lE", -0.0)} END_TEST
    START_TEST(double_EXP_fraction_medium_no_width_no_precision){
        RUN_TEST("%lE", 0.123456789101112)} END_TEST
    START_TEST(double_EXP_general_medium_no_width_no_precision){
        RUN_TEST("%lE", 1234.56789101112)} END_TEST
    START_TEST(double_g_null_no_width_no_precision){
        RUN_TEST("%lg", 0.0)} END_TEST
    START_TEST(double_g_null_neg_no_width_no_precision){
        RUN_TEST("%lg", -0.0)} END_TEST
    START_TEST(double_g_fraction_medium_no_width_no_precision){
        RUN_TEST("%lg", 0.123456789101112)} END_TEST
    START_TEST(double_g_general_medium_no_width_no_precision){
        RUN_TEST("%lg", 1234.56789101112)} END_TEST
    START_TEST(double_G_null_no_width_no_precision){
        RUN_TEST("%lG", 0.0)} END_TEST
    START_TEST(double_G_null_neg_no_width_no_precision){
        RUN_TEST("%lG", -0.0)} END_TEST
    START_TEST(double_G_fraction_medium_no_width_no_precision){
        RUN_TEST("%lG", 0.123456789101112)} END_TEST
    START_TEST(double_G_general_medium_no_width_no_precision){
        RUN_TEST("%lG", 1234.56789101112)} END_TEST
    START_TEST(double_null_no_width_small_precision){
        RUN_TEST("%.3lf", 0.0)} END_TEST
    START_TEST(double_null_neg_no_width_small_precision){
        RUN_TEST("%.3lf", -0.0)} END_TEST
    START_TEST(double_fraction_medium_no_width_small_precision){
        RUN_TEST("%.3lf", 0.123456789101112)} END_TEST
    START_TEST(double_general_medium_no_width_small_precision){
        RUN_TEST("%.3lf", 1234.56789101112)} END_TEST
    START_TEST(double_exp_null_no_width_small_precision){
        RUN_TEST("%.3le", 0.0)} END_TEST
    START_TEST(double_exp_null_neg_no_width_small_precision){
        RUN_TEST("%.3le", -0.0)} END_TEST
    START_TEST(double_exp_fraction_medium_no_width_small_precision){
        RUN_TEST("%.3le", 0.123456789101112)} END_TEST
    START_TEST(double_exp_general_medium_no_width_small_precision){
        RUN_TEST("%.3le", 1234.56789101112)} END_TEST
    START_TEST(double_EXP_null_no_width_small_precision){
        RUN_TEST("%.3lE", 0.0)} END_TEST
    START_TEST(double_EXP_null_neg_no_width_small_precision){
        RUN_TEST("%.3lE", -0.0)} END_TEST
    START_TEST(double_EXP_fraction_medium_no_width_small_precision){
        RUN_TEST("%.3lE", 0.123456789101112)} END_TEST
    START_TEST(double_EXP_general_medium_no_width_small_precision){
        RUN_TEST("%.3lE", 1234.56789101112)} END_TEST
    START_TEST(double_g_null_no_width_small_precision){
        RUN_TEST("%.3lg", 0.0)} END_TEST
    START_TEST(double_g_null_neg_no_width_small_precision){
        RUN_TEST("%.3lg", -0.0)} END_TEST
    START_TEST(double_g_fraction_medium_no_width_small_precision){
        RUN_TEST("%.3lg", 0.123456789101112)} END_TEST
    START_TEST(double_g_general_medium_no_width_small_precision){
        RUN_TEST("%.3lg", 1234.56789101112)} END_TEST
    START_TEST(double_G_null_no_width_small_precision){
        RUN_TEST("%.3lG", 0.0)} END_TEST
    START_TEST(double_G_null_neg_no_width_small_precision){
        RUN_TEST("%.3lG", -0.0)} END_TEST
    START_TEST(double_G_fraction_medium_no_width_small_precision){
        RUN_TEST("%.3lG", 0.123456789101112)} END_TEST
    START_TEST(double_G_general_medium_no_width_small_precision){
        RUN_TEST("%.3lG", 1234.56789101112)} END_TEST
    START_TEST(double_null_no_width_big_precision){
        RUN_TEST("%.14lf", 0.0)} END_TEST
    START_TEST(double_null_neg_no_width_big_precision){
        RUN_TEST("%.14lf", -0.0)} END_TEST
    START_TEST(double_fraction_medium_no_width_big_precision){
        RUN_TEST("%.14lf", 0.123456789101112)} END_TEST
    START_TEST(double_general_medium_no_width_big_precision){
        RUN_TEST("%.14lf", 1234.56789101112)} END_TEST
    START_TEST(double_exp_null_no_width_big_precision){
        RUN_TEST("%.14le", 0.0)} END_TEST
    START_TEST(double_exp_null_neg_no_width_big_precision){
        RUN_TEST("%.14le", -0.0)} END_TEST
    START_TEST(double_exp_fraction_medium_no_width_big_precision){
        RUN_TEST("%.14le", 0.123456789101112)} END_TEST
    START_TEST(double_exp_general_medium_no_width_big_precision){
        RUN_TEST("%.14le", 1234.56789101112)} END_TEST
    START_TEST(double_EXP_null_no_width_big_precision){
        RUN_TEST("%.14lE", 0.0)} END_TEST
    START_TEST(double_EXP_null_neg_no_width_big_precision){
        RUN_TEST("%.14lE", -0.0)} END_TEST
    START_TEST(double_EXP_fraction_medium_no_width_big_precision){
        RUN_TEST("%.14lE", 0.123456789101112)} END_TEST
    START_TEST(double_EXP_general_medium_no_width_big_precision){
        RUN_TEST("%.14lE", 1234.56789101112)} END_TEST
    START_TEST(double_g_null_no_width_big_precision){
        RUN_TEST("%.14lg", 0.0)} END_TEST
    START_TEST(double_g_null_neg_no_width_big_precision){
        RUN_TEST("%.14lg", -0.0)} END_TEST
    START_TEST(double_g_fraction_medium_no_width_big_precision){
        RUN_TEST("%.14lg", 0.123456789101112)} END_TEST
    START_TEST(double_g_general_medium_no_width_big_precision){
        RUN_TEST("%.14lg", 1234.56789101112)} END_TEST
    START_TEST(double_G_null_no_width_big_precision){
        RUN_TEST("%.14lG", 0.0)} END_TEST
    START_TEST(double_G_null_neg_no_width_big_precision){
        RUN_TEST("%.14lG", -0.0)} END_TEST
    START_TEST(double_G_fraction_medium_no_width_big_precision){
        RUN_TEST("%.14lG", 0.123456789101112)} END_TEST
    START_TEST(double_G_general_medium_no_width_big_precision){
        RUN_TEST("%.14lG", 1234.56789101112)} END_TEST
    START_TEST(double_null_small_width_no_precision){
        RUN_TEST("%1lf", 0.0)} END_TEST
    START_TEST(double_null_neg_small_width_no_precision){
        RUN_TEST("%1lf", -0.0)} END_TEST
    START_TEST(double_fraction_medium_small_width_no_precision){
        RUN_TEST("%1lf", 0.123456789101112)} END_TEST
    START_TEST(double_general_medium_small_width_no_precision){
        RUN_TEST("%1lf", 1234.56789101112)} END_TEST
    START_TEST(double_exp_null_small_width_no_precision){
        RUN_TEST("%1le", 0.0)} END_TEST
    START_TEST(double_exp_null_neg_small_width_no_precision){
        RUN_TEST("%1le", -0.0)} END_TEST
    START_TEST(double_exp_fraction_medium_small_width_no_precision){
        RUN_TEST("%1le", 0.123456789101112)} END_TEST
    START_TEST(double_exp_general_medium_small_width_no_precision){
        RUN_TEST("%1le", 1234.56789101112)} END_TEST
    START_TEST(double_EXP_null_small_width_no_precision){
        RUN_TEST("%1lE", 0.0)} END_TEST
    START_TEST(double_EXP_null_neg_small_width_no_precision){
        RUN_TEST("%1lE", -0.0)} END_TEST
    START_TEST(double_EXP_fraction_medium_small_width_no_precision){
        RUN_TEST("%1lE", 0.123456789101112)} END_TEST
    START_TEST(double_EXP_general_medium_small_width_no_precision){
        RUN_TEST("%1lE", 1234.56789101112)} END_TEST
    START_TEST(double_g_null_small_width_no_precision){
        RUN_TEST("%1lg", 0.0)} END_TEST
    START_TEST(double_g_null_neg_small_width_no_precision){
        RUN_TEST("%1lg", -0.0)} END_TEST
    START_TEST(double_g_fraction_medium_small_width_no_precision){
        RUN_TEST("%1lg", 0.123456789101112)} END_TEST
    START_TEST(double_g_general_medium_small_width_no_precision){
        RUN_TEST("%1lg", 1234.56789101112)} END_TEST
    START_TEST(double_G_null_small_width_no_precision){
        RUN_TEST("%1lG", 0.0)} END_TEST
    START_TEST(double_G_null_neg_small_width_no_precision){
        RUN_TEST("%1lG", -0.0)} END_TEST
    START_TEST(double_G_fraction_medium_small_width_no_precision){
        RUN_TEST("%1lG", 0.123456789101112)} END_TEST
    START_TEST(double_G_general_medium_small_width_no_precision){
        RUN_TEST("%1lG", 1234.56789101112)} END_TEST
    START_TEST(double_null_small_width_small_precision){
        RUN_TEST("%1.3lf", 0.0)} END_TEST
    START_TEST(double_null_neg_small_width_small_precision){
        RUN_TEST("%1.3lf", -0.0)} END_TEST
    START_TEST(double_fraction_medium_small_width_small_precision){
        RUN_TEST("%1.3lf", 0.123456789101112)} END_TEST
    START_TEST(double_general_medium_small_width_small_precision){
        RUN_TEST("%1.3lf", 1234.56789101112)} END_TEST
    START_TEST(double_exp_null_small_width_small_precision){
        RUN_TEST("%1.3le", 0.0)} END_TEST
    START_TEST(double_exp_null_neg_small_width_small_precision){
        RUN_TEST("%1.3le", -0.0)} END_TEST
    START_TEST(double_exp_fraction_medium_small_width_small_precision){
        RUN_TEST("%1.3le", 0.123456789101112)} END_TEST
    START_TEST(double_exp_general_medium_small_width_small_precision){
        RUN_TEST("%1.3le", 1234.56789101112)} END_TEST
    START_TEST(double_EXP_null_small_width_small_precision){
        RUN_TEST("%1.3lE", 0.0)} END_TEST
    START_TEST(double_EXP_null_neg_small_width_small_precision){
        RUN_TEST("%1.3lE", -0.0)} END_TEST
    START_TEST(double_EXP_fraction_medium_small_width_small_precision){
        RUN_TEST("%1.3lE", 0.123456789101112)} END_TEST
    START_TEST(double_EXP_general_medium_small_width_small_precision){
        RUN_TEST("%1.3lE", 1234.56789101112)} END_TEST
    START_TEST(double_g_null_small_width_small_precision){
        RUN_TEST("%1.3lg", 0.0)} END_TEST
    START_TEST(double_g_null_neg_small_width_small_precision){
        RUN_TEST("%1.3lg", -0.0)} END_TEST
    START_TEST(double_g_fraction_medium_small_width_small_precision){
        RUN_TEST("%1.3lg", 0.123456789101112)} END_TEST
    START_TEST(double_g_general_medium_small_width_small_precision){
        RUN_TEST("%1.3lg", 1234.56789101112)} END_TEST
    START_TEST(double_G_null_small_width_small_precision){
        RUN_TEST("%1.3lG", 0.0)} END_TEST
    START_TEST(double_G_null_neg_small_width_small_precision){
        RUN_TEST("%1.3lG", -0.0)} END_TEST
    START_TEST(double_G_fraction_medium_small_width_small_precision){
        RUN_TEST("%1.3lG", 0.123456789101112)} END_TEST
    START_TEST(double_G_general_medium_small_width_small_precision){
        RUN_TEST("%1.3lG", 1234.56789101112)} END_TEST
    START_TEST(double_null_small_width_big_precision){
        RUN_TEST("%1.14lf", 0.0)} END_TEST
    START_TEST(double_null_neg_small_width_big_precision){
        RUN_TEST("%1.14lf", -0.0)} END_TEST
    START_TEST(double_fraction_medium_small_width_big_precision){
        RUN_TEST("%1.14lf", 0.123456789101112)} END_TEST
    START_TEST(double_general_medium_small_width_big_precision){
        RUN_TEST("%1.14lf", 1234.56789101112)} END_TEST
    START_TEST(double_exp_null_small_width_big_precision){
        RUN_TEST("%1.14le", 0.0)} END_TEST
    START_TEST(double_exp_null_neg_small_width_big_precision){
        RUN_TEST("%1.14le", -0.0)} END_TEST
    START_TEST(double_exp_fraction_medium_small_width_big_precision){
        RUN_TEST("%1.14le", 0.123456789101112)} END_TEST
    START_TEST(double_exp_general_medium_small_width_big_precision){
        RUN_TEST("%1.14le", 1234.56789101112)} END_TEST
    START_TEST(double_EXP_null_small_width_big_precision){
        RUN_TEST("%1.14lE", 0.0)} END_TEST
    START_TEST(double_EXP_null_neg_small_width_big_precision){
        RUN_TEST("%1.14lE", -0.0)} END_TEST
    START_TEST(double_EXP_fraction_medium_small_width_big_precision){
        RUN_TEST("%1.14lE", 0.123456789101112)} END_TEST
    START_TEST(double_EXP_general_medium_small_width_big_precision){
        RUN_TEST("%1.14lE", 1234.56789101112)} END_TEST
    START_TEST(double_g_null_small_width_big_precision){
        RUN_TEST("%1.14lg", 0.0)} END_TEST
    START_TEST(double_g_null_neg_small_width_big_precision){
        RUN_TEST("%1.14lg", -0.0)} END_TEST
    START_TEST(double_g_fraction_medium_small_width_big_precision){
        RUN_TEST("%1.14lg", 0.123456789101112)} END_TEST
    START_TEST(double_g_general_medium_small_width_big_precision){
        RUN_TEST("%1.14lg", 1234.56789101112)} END_TEST
    START_TEST(double_G_null_small_width_big_precision){
        RUN_TEST("%1.14lG", 0.0)} END_TEST
    START_TEST(double_G_null_neg_small_width_big_precision){
        RUN_TEST("%1.14lG", -0.0)} END_TEST
    START_TEST(double_G_fraction_medium_small_width_big_precision){
        RUN_TEST("%1.14lG", 0.123456789101112)} END_TEST
    START_TEST(double_G_general_medium_small_width_big_precision){
        RUN_TEST("%1.14lG", 1234.56789101112)} END_TEST
    START_TEST(double_null_big_width_no_precision){
        RUN_TEST("%50lf", 0.0)} END_TEST
    START_TEST(double_null_neg_big_width_no_precision){
        RUN_TEST("%50lf", -0.0)} END_TEST
    START_TEST(double_fraction_medium_big_width_no_precision){
        RUN_TEST("%50lf", 0.123456789101112)} END_TEST
    START_TEST(double_general_medium_big_width_no_precision){
        RUN_TEST("%50lf", 1234.56789101112)} END_TEST
    START_TEST(double_exp_null_big_width_no_precision){
        RUN_TEST("%50le", 0.0)} END_TEST
    START_TEST(double_exp_null_neg_big_width_no_precision){
        RUN_TEST("%50le", -0.0)} END_TEST
    START_TEST(double_exp_fraction_medium_big_width_no_precision){
        RUN_TEST("%50le", 0.123456789101112)} END_TEST
    START_TEST(double_exp_general_medium_big_width_no_precision){
        RUN_TEST("%50le", 1234.56789101112)} END_TEST
    START_TEST(double_EXP_null_big_width_no_precision){
        RUN_TEST("%50lE", 0.0)} END_TEST
    START_TEST(double_EXP_null_neg_big_width_no_precision){
        RUN_TEST("%50lE", -0.0)} END_TEST
    START_TEST(double_EXP_fraction_medium_big_width_no_precision){
        RUN_TEST("%50lE", 0.123456789101112)} END_TEST
    START_TEST(double_EXP_general_medium_big_width_no_precision){
        RUN_TEST("%50lE", 1234.56789101112)} END_TEST
    START_TEST(double_g_null_big_width_no_precision){
        RUN_TEST("%50lg", 0.0)} END_TEST
    START_TEST(double_g_null_neg_big_width_no_precision){
        RUN_TEST("%50lg", -0.0)} END_TEST
    START_TEST(double_g_fraction_medium_big_width_no_precision){
        RUN_TEST("%50lg", 0.123456789101112)} END_TEST
    START_TEST(double_g_general_medium_big_width_no_precision){
        RUN_TEST("%50lg", 1234.56789101112)} END_TEST
    START_TEST(double_G_null_big_width_no_precision){
        RUN_TEST("%50lG", 0.0)} END_TEST
    START_TEST(double_G_null_neg_big_width_no_precision){
        RUN_TEST("%50lG", -0.0)} END_TEST
    START_TEST(double_G_fraction_medium_big_width_no_precision){
        RUN_TEST("%50lG", 0.123456789101112)} END_TEST
    START_TEST(double_G_general_medium_big_width_no_precision){
        RUN_TEST("%50lG", 1234.56789101112)} END_TEST
    START_TEST(double_null_big_width_small_precision){
        RUN_TEST("%50.3lf", 0.0)} END_TEST
    START_TEST(double_null_neg_big_width_small_precision){
        RUN_TEST("%50.3lf", -0.0)} END_TEST
    START_TEST(double_fraction_medium_big_width_small_precision){
        RUN_TEST("%50.3lf", 0.123456789101112)} END_TEST
    START_TEST(double_general_medium_big_width_small_precision){
        RUN_TEST("%50.3lf", 1234.56789101112)} END_TEST
    START_TEST(double_exp_null_big_width_small_precision){
        RUN_TEST("%50.3le", 0.0)} END_TEST
    START_TEST(double_exp_null_neg_big_width_small_precision){
        RUN_TEST("%50.3le", -0.0)} END_TEST
    START_TEST(double_exp_fraction_medium_big_width_small_precision){
        RUN_TEST("%50.3le", 0.123456789101112)} END_TEST
    START_TEST(double_exp_general_medium_big_width_small_precision){
        RUN_TEST("%50.3le", 1234.56789101112)} END_TEST
    START_TEST(double_EXP_null_big_width_small_precision){
        RUN_TEST("%50.3lE", 0.0)} END_TEST
    START_TEST(double_EXP_null_neg_big_width_small_precision){
        RUN_TEST("%50.3lE", -0.0)} END_TEST
    START_TEST(double_EXP_fraction_medium_big_width_small_precision){
        RUN_TEST("%50.3lE", 0.123456789101112)} END_TEST
    START_TEST(double_EXP_general_medium_big_width_small_precision){
        RUN_TEST("%50.3lE", 1234.56789101112)} END_TEST
    START_TEST(double_g_null_big_width_small_precision){
        RUN_TEST("%50.3lg", 0.0)} END_TEST
    START_TEST(double_g_null_neg_big_width_small_precision){
        RUN_TEST("%50.3lg", -0.0)} END_TEST
    START_TEST(double_g_fraction_medium_big_width_small_precision){
        RUN_TEST("%50.3lg", 0.123456789101112)} END_TEST
    START_TEST(double_g_general_medium_big_width_small_precision){
        RUN_TEST("%50.3lg", 1234.56789101112)} END_TEST
    START_TEST(double_G_null_big_width_small_precision){
        RUN_TEST("%50.3lG", 0.0)} END_TEST
    START_TEST(double_G_null_neg_big_width_small_precision){
        RUN_TEST("%50.3lG", -0.0)} END_TEST
    START_TEST(double_G_fraction_medium_big_width_small_precision){
        RUN_TEST("%50.3lG", 0.123456789101112)} END_TEST
    START_TEST(double_G_general_medium_big_width_small_precision){
        RUN_TEST("%50.3lG", 1234.56789101112)} END_TEST
    START_TEST(double_null_big_width_big_precision){
        RUN_TEST("%50.14lf", 0.0)} END_TEST
    START_TEST(double_null_neg_big_width_big_precision){
        RUN_TEST("%50.14lf", -0.0)} END_TEST
    START_TEST(double_fraction_medium_big_width_big_precision){
        RUN_TEST("%50.14lf", 0.123456789101112)} END_TEST
    START_TEST(double_general_medium_big_width_big_precision){
        RUN_TEST("%50.14lf", 1234.56789101112)} END_TEST
    START_TEST(double_exp_null_big_width_big_precision){
        RUN_TEST("%50.14le", 0.0)} END_TEST
    START_TEST(double_exp_null_neg_big_width_big_precision){
        RUN_TEST("%50.14le", -0.0)} END_TEST
    START_TEST(double_exp_fraction_medium_big_width_big_precision){
        RUN_TEST("%50.14le", 0.123456789101112)} END_TEST
    START_TEST(double_exp_general_medium_big_width_big_precision){
        RUN_TEST("%50.14le", 1234.56789101112)} END_TEST
    START_TEST(double_EXP_null_big_width_big_precision){
        RUN_TEST("%50.14lE", 0.0)} END_TEST
    START_TEST(double_EXP_null_neg_big_width_big_precision){
        RUN_TEST("%50.14lE", -0.0)} END_TEST
    START_TEST(double_EXP_fraction_medium_big_width_big_precision){
        RUN_TEST("%50.14lE", 0.123456789101112)} END_TEST
    START_TEST(double_EXP_general_medium_big_width_big_precision){
        RUN_TEST("%50.14lE", 1234.56789101112)} END_TEST
    START_TEST(double_g_null_big_width_big_precision){
        RUN_TEST("%50.14lg", 0.0)} END_TEST
    START_TEST(double_g_null_neg_big_width_big_precision){
        RUN_TEST("%50.14lg", -0.0)} END_TEST
    START_TEST(double_g_fraction_medium_big_width_big_precision){
        RUN_TEST("%50.14lg", 0.123456789101112)} END_TEST
    START_TEST(double_g_general_medium_big_width_big_precision){
        RUN_TEST("%50.14lg", 1234.56789101112)} END_TEST
    START_TEST(double_G_null_big_width_big_precision){
        RUN_TEST("%50.14lG", 0.0)} END_TEST
    START_TEST(double_G_null_neg_big_width_big_precision){
        RUN_TEST("%50.14lG", -0.0)} END_TEST
    START_TEST(double_G_fraction_medium_big_width_big_precision){
        RUN_TEST("%50.14lG", 0.123456789101112)} END_TEST
    START_TEST(double_G_general_medium_big_width_big_precision){
        RUN_TEST("%50.14lG", 1234.56789101112)} END_TEST

    START_TEST(long_double_null_no_flags){RUN_TEST("%Lf", 0.0L)} END_TEST
    START_TEST(long_double_null_neg_no_flags){RUN_TEST("%Lf", -0.0L)} END_TEST
    START_TEST(long_double_fraction_long_no_flags){
        RUN_TEST("%Lf", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_general_long_no_flags){
        RUN_TEST("%Lf", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_exp_null_no_flags){RUN_TEST("%Le", 0.0L)} END_TEST
    START_TEST(long_double_exp_null_neg_no_flags){
        RUN_TEST("%Le", -0.0L)} END_TEST
    START_TEST(long_double_exp_fraction_long_no_flags){
        RUN_TEST("%Le", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_exp_general_long_no_flags){
        RUN_TEST("%Le", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_EXP_null_no_flags){RUN_TEST("%LE", 0.0L)} END_TEST
    START_TEST(long_double_EXP_null_neg_no_flags){
        RUN_TEST("%LE", -0.0L)} END_TEST
    START_TEST(long_double_EXP_fraction_long_no_flags){
        RUN_TEST("%LE", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_EXP_general_long_no_flags){
        RUN_TEST("%LE", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_g_null_no_flags){RUN_TEST("%Lg", 0.0L)} END_TEST
    START_TEST(long_double_g_null_neg_no_flags){RUN_TEST("%Lg", -0.0L)} END_TEST
    START_TEST(long_double_g_fraction_long_no_flags){
        RUN_TEST("%Lg", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_g_general_long_no_flags){
        RUN_TEST("%Lg", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_G_null_no_flags){RUN_TEST("%LG", 0.0L)} END_TEST
    START_TEST(long_double_G_null_neg_no_flags){RUN_TEST("%LG", -0.0L)} END_TEST
    START_TEST(long_double_G_fraction_long_no_flags){
        RUN_TEST("%LG", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_G_general_long_no_flags){
        RUN_TEST("%LG", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_null_prefix_sign){RUN_TEST("%+Lf", 0.0L)} END_TEST
    START_TEST(long_double_null_neg_prefix_sign){
        RUN_TEST("%+Lf", -0.0L)} END_TEST
    START_TEST(long_double_fraction_long_prefix_sign){
        RUN_TEST("%+Lf", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_general_long_prefix_sign){
        RUN_TEST("%+Lf", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_exp_null_prefix_sign){
        RUN_TEST("%+Le", 0.0L)} END_TEST
    START_TEST(long_double_exp_null_neg_prefix_sign){
        RUN_TEST("%+Le", -0.0L)} END_TEST
    START_TEST(long_double_exp_fraction_long_prefix_sign){
        RUN_TEST("%+Le", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_exp_general_long_prefix_sign){
        RUN_TEST("%+Le", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_EXP_null_prefix_sign){
        RUN_TEST("%+LE", 0.0L)} END_TEST
    START_TEST(long_double_EXP_null_neg_prefix_sign){
        RUN_TEST("%+LE", -0.0L)} END_TEST
    START_TEST(long_double_EXP_fraction_long_prefix_sign){
        RUN_TEST("%+LE", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_EXP_general_long_prefix_sign){
        RUN_TEST("%+LE", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_g_null_prefix_sign){RUN_TEST("%+Lg", 0.0L)} END_TEST
    START_TEST(long_double_g_null_neg_prefix_sign){
        RUN_TEST("%+Lg", -0.0L)} END_TEST
    START_TEST(long_double_g_fraction_long_prefix_sign){
        RUN_TEST("%+Lg", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_g_general_long_prefix_sign){
        RUN_TEST("%+Lg", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_G_null_prefix_sign){RUN_TEST("%+LG", 0.0L)} END_TEST
    START_TEST(long_double_G_null_neg_prefix_sign){
        RUN_TEST("%+LG", -0.0L)} END_TEST
    START_TEST(long_double_G_fraction_long_prefix_sign){
        RUN_TEST("%+LG", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_G_general_long_prefix_sign){
        RUN_TEST("%+LG", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_null_prefix_space){RUN_TEST("% Lf", 0.0L)} END_TEST
    START_TEST(long_double_null_neg_prefix_space){
        RUN_TEST("% Lf", -0.0L)} END_TEST
    START_TEST(long_double_fraction_long_prefix_space){
        RUN_TEST("% Lf", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_general_long_prefix_space){
        RUN_TEST("% Lf", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_exp_null_prefix_space){
        RUN_TEST("% Le", 0.0L)} END_TEST
    START_TEST(long_double_exp_null_neg_prefix_space){
        RUN_TEST("% Le", -0.0L)} END_TEST
    START_TEST(long_double_exp_fraction_long_prefix_space){
        RUN_TEST("% Le", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_exp_general_long_prefix_space){
        RUN_TEST("% Le", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_EXP_null_prefix_space){
        RUN_TEST("% LE", 0.0L)} END_TEST
    START_TEST(long_double_EXP_null_neg_prefix_space){
        RUN_TEST("% LE", -0.0L)} END_TEST
    START_TEST(long_double_EXP_fraction_long_prefix_space){
        RUN_TEST("% LE", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_EXP_general_long_prefix_space){
        RUN_TEST("% LE", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_g_null_prefix_space){RUN_TEST("% Lg", 0.0L)} END_TEST
    START_TEST(long_double_g_null_neg_prefix_space){
        RUN_TEST("% Lg", -0.0L)} END_TEST
    START_TEST(long_double_g_fraction_long_prefix_space){
        RUN_TEST("% Lg", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_g_general_long_prefix_space){
        RUN_TEST("% Lg", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_G_null_prefix_space){RUN_TEST("% LG", 0.0L)} END_TEST
    START_TEST(long_double_G_null_neg_prefix_space){
        RUN_TEST("% LG", -0.0L)} END_TEST
    START_TEST(long_double_G_fraction_long_prefix_space){
        RUN_TEST("% LG", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_G_general_long_prefix_space){
        RUN_TEST("% LG", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_null_left_alignment){RUN_TEST("%-Lf", 0.0L)} END_TEST
    START_TEST(long_double_null_neg_left_alignment){
        RUN_TEST("%-Lf", -0.0L)} END_TEST
    START_TEST(long_double_fraction_long_left_alignment){
        RUN_TEST("%-Lf", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_general_long_left_alignment){
        RUN_TEST("%-Lf", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_exp_null_left_alignment){
        RUN_TEST("%-Le", 0.0L)} END_TEST
    START_TEST(long_double_exp_null_neg_left_alignment){
        RUN_TEST("%-Le", -0.0L)} END_TEST
    START_TEST(long_double_exp_fraction_long_left_alignment){
        RUN_TEST("%-Le", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_exp_general_long_left_alignment){
        RUN_TEST("%-Le", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_EXP_null_left_alignment){
        RUN_TEST("%-LE", 0.0L)} END_TEST
    START_TEST(long_double_EXP_null_neg_left_alignment){
        RUN_TEST("%-LE", -0.0L)} END_TEST
    START_TEST(long_double_EXP_fraction_long_left_alignment){
        RUN_TEST("%-LE", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_EXP_general_long_left_alignment){
        RUN_TEST("%-LE", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_g_null_left_alignment){
        RUN_TEST("%-Lg", 0.0L)} END_TEST
    START_TEST(long_double_g_null_neg_left_alignment){
        RUN_TEST("%-Lg", -0.0L)} END_TEST
    START_TEST(long_double_g_fraction_long_left_alignment){
        RUN_TEST("%-Lg", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_g_general_long_left_alignment){
        RUN_TEST("%-Lg", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_G_null_left_alignment){
        RUN_TEST("%-LG", 0.0L)} END_TEST
    START_TEST(long_double_G_null_neg_left_alignment){
        RUN_TEST("%-LG", -0.0L)} END_TEST
    START_TEST(long_double_G_fraction_long_left_alignment){
        RUN_TEST("%-LG", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_G_general_long_left_alignment){
        RUN_TEST("%-LG", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_null_leading_zeroes){RUN_TEST("%0Lf", 0.0L)} END_TEST
    START_TEST(long_double_null_neg_leading_zeroes){
        RUN_TEST("%0Lf", -0.0L)} END_TEST
    START_TEST(long_double_fraction_long_leading_zeroes){
        RUN_TEST("%0Lf", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_general_long_leading_zeroes){
        RUN_TEST("%0Lf", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_exp_null_leading_zeroes){
        RUN_TEST("%0Le", 0.0L)} END_TEST
    START_TEST(long_double_exp_null_neg_leading_zeroes){
        RUN_TEST("%0Le", -0.0L)} END_TEST
    START_TEST(long_double_exp_fraction_long_leading_zeroes){
        RUN_TEST("%0Le", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_exp_general_long_leading_zeroes){
        RUN_TEST("%0Le", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_EXP_null_leading_zeroes){
        RUN_TEST("%0LE", 0.0L)} END_TEST
    START_TEST(long_double_EXP_null_neg_leading_zeroes){
        RUN_TEST("%0LE", -0.0L)} END_TEST
    START_TEST(long_double_EXP_fraction_long_leading_zeroes){
        RUN_TEST("%0LE", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_EXP_general_long_leading_zeroes){
        RUN_TEST("%0LE", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_g_null_leading_zeroes){
        RUN_TEST("%0Lg", 0.0L)} END_TEST
    START_TEST(long_double_g_null_neg_leading_zeroes){
        RUN_TEST("%0Lg", -0.0L)} END_TEST
    START_TEST(long_double_g_fraction_long_leading_zeroes){
        RUN_TEST("%0Lg", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_g_general_long_leading_zeroes){
        RUN_TEST("%0Lg", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_G_null_leading_zeroes){
        RUN_TEST("%0LG", 0.0L)} END_TEST
    START_TEST(long_double_G_null_neg_leading_zeroes){
        RUN_TEST("%0LG", -0.0L)} END_TEST
    START_TEST(long_double_G_fraction_long_leading_zeroes){
        RUN_TEST("%0LG", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_G_general_long_leading_zeroes){
        RUN_TEST("%0LG", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_null_alt_format){RUN_TEST("%#Lf", 0.0L)} END_TEST
    START_TEST(long_double_null_neg_alt_format){
        RUN_TEST("%#Lf", -0.0L)} END_TEST
    START_TEST(long_double_fraction_long_alt_format){
        RUN_TEST("%#Lf", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_general_long_alt_format){
        RUN_TEST("%#Lf", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_exp_null_alt_format){RUN_TEST("%#Le", 0.0L)} END_TEST
    START_TEST(long_double_exp_null_neg_alt_format){
        RUN_TEST("%#Le", -0.0L)} END_TEST
    START_TEST(long_double_exp_fraction_long_alt_format){
        RUN_TEST("%#Le", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_exp_general_long_alt_format){
        RUN_TEST("%#Le", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_EXP_null_alt_format){RUN_TEST("%#LE", 0.0L)} END_TEST
    START_TEST(long_double_EXP_null_neg_alt_format){
        RUN_TEST("%#LE", -0.0L)} END_TEST
    START_TEST(long_double_EXP_fraction_long_alt_format){
        RUN_TEST("%#LE", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_EXP_general_long_alt_format){
        RUN_TEST("%#LE", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_g_null_alt_format){RUN_TEST("%#Lg", 0.0L)} END_TEST
    START_TEST(long_double_g_null_neg_alt_format){
        RUN_TEST("%#Lg", -0.0L)} END_TEST
    START_TEST(long_double_g_fraction_long_alt_format){
        RUN_TEST("%#Lg", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_g_general_long_alt_format){
        RUN_TEST("%#Lg", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_G_null_alt_format){RUN_TEST("%#LG", 0.0L)} END_TEST
    START_TEST(long_double_G_null_neg_alt_format){
        RUN_TEST("%#LG", -0.0L)} END_TEST
    START_TEST(long_double_G_fraction_long_alt_format){
        RUN_TEST("%#LG", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_G_general_long_alt_format){
        RUN_TEST("%#LG", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_null_no_width_no_precision){
        RUN_TEST("%Lf", 0.0L)} END_TEST
    START_TEST(long_double_null_neg_no_width_no_precision){
        RUN_TEST("%Lf", -0.0L)} END_TEST
    START_TEST(long_double_fraction_long_no_width_no_precision){
        RUN_TEST("%Lf", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_general_long_no_width_no_precision){
        RUN_TEST("%Lf", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_exp_null_no_width_no_precision){
        RUN_TEST("%Le", 0.0L)} END_TEST
    START_TEST(long_double_exp_null_neg_no_width_no_precision){
        RUN_TEST("%Le", -0.0L)} END_TEST
    START_TEST(long_double_exp_fraction_long_no_width_no_precision){
        RUN_TEST("%Le", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_exp_general_long_no_width_no_precision){
        RUN_TEST("%Le", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_EXP_null_no_width_no_precision){
        RUN_TEST("%LE", 0.0L)} END_TEST
    START_TEST(long_double_EXP_null_neg_no_width_no_precision){
        RUN_TEST("%LE", -0.0L)} END_TEST
    START_TEST(long_double_EXP_fraction_long_no_width_no_precision){
        RUN_TEST("%LE", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_EXP_general_long_no_width_no_precision){
        RUN_TEST("%LE", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_g_null_no_width_no_precision){
        RUN_TEST("%Lg", 0.0L)} END_TEST
    START_TEST(long_double_g_null_neg_no_width_no_precision){
        RUN_TEST("%Lg", -0.0L)} END_TEST
    START_TEST(long_double_g_fraction_long_no_width_no_precision){
        RUN_TEST("%Lg", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_g_general_long_no_width_no_precision){
        RUN_TEST("%Lg", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_G_null_no_width_no_precision){
        RUN_TEST("%LG", 0.0L)} END_TEST
    START_TEST(long_double_G_null_neg_no_width_no_precision){
        RUN_TEST("%LG", -0.0L)} END_TEST
    START_TEST(long_double_G_fraction_long_no_width_no_precision){
        RUN_TEST("%LG", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_G_general_long_no_width_no_precision){
        RUN_TEST("%LG", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_null_no_width_small_precision){
        RUN_TEST("%.3Lf", 0.0L)} END_TEST
    START_TEST(long_double_null_neg_no_width_small_precision){
        RUN_TEST("%.3Lf", -0.0L)} END_TEST
    START_TEST(long_double_fraction_long_no_width_small_precision){
        RUN_TEST("%.3Lf", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_general_long_no_width_small_precision){
        RUN_TEST("%.3Lf", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_exp_null_no_width_small_precision){
        RUN_TEST("%.3Le", 0.0L)} END_TEST
    START_TEST(long_double_exp_null_neg_no_width_small_precision){
        RUN_TEST("%.3Le", -0.0L)} END_TEST
    START_TEST(long_double_exp_fraction_long_no_width_small_precision){
        RUN_TEST("%.3Le", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_exp_general_long_no_width_small_precision){
        RUN_TEST("%.3Le", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_EXP_null_no_width_small_precision){
        RUN_TEST("%.3LE", 0.0L)} END_TEST
    START_TEST(long_double_EXP_null_neg_no_width_small_precision){
        RUN_TEST("%.3LE", -0.0L)} END_TEST
    START_TEST(long_double_EXP_fraction_long_no_width_small_precision){
        RUN_TEST("%.3LE", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_EXP_general_long_no_width_small_precision){
        RUN_TEST("%.3LE", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_g_null_no_width_small_precision){
        RUN_TEST("%.3Lg", 0.0L)} END_TEST
    START_TEST(long_double_g_null_neg_no_width_small_precision){
        RUN_TEST("%.3Lg", -0.0L)} END_TEST
    START_TEST(long_double_g_fraction_long_no_width_small_precision){
        RUN_TEST("%.3Lg", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_g_general_long_no_width_small_precision){
        RUN_TEST("%.3Lg", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_G_null_no_width_small_precision){
        RUN_TEST("%.3LG", 0.0L)} END_TEST
    START_TEST(long_double_G_null_neg_no_width_small_precision){
        RUN_TEST("%.3LG", -0.0L)} END_TEST
    START_TEST(long_double_G_fraction_long_no_width_small_precision){
        RUN_TEST("%.3LG", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_G_general_long_no_width_small_precision){
        RUN_TEST("%.3LG", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_null_no_width_big_precision){
        RUN_TEST("%.14Lf", 0.0L)} END_TEST
    START_TEST(long_double_null_neg_no_width_big_precision){
        RUN_TEST("%.14Lf", -0.0L)} END_TEST
    START_TEST(long_double_fraction_long_no_width_big_precision){
        RUN_TEST("%.14Lf", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_general_long_no_width_big_precision){
        RUN_TEST("%.14Lf", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_exp_null_no_width_big_precision){
        RUN_TEST("%.14Le", 0.0L)} END_TEST
    START_TEST(long_double_exp_null_neg_no_width_big_precision){
        RUN_TEST("%.14Le", -0.0L)} END_TEST
    START_TEST(long_double_exp_fraction_long_no_width_big_precision){
        RUN_TEST("%.14Le", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_exp_general_long_no_width_big_precision){
        RUN_TEST("%.14Le", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_EXP_null_no_width_big_precision){
        RUN_TEST("%.14LE", 0.0L)} END_TEST
    START_TEST(long_double_EXP_null_neg_no_width_big_precision){
        RUN_TEST("%.14LE", -0.0L)} END_TEST
    START_TEST(long_double_EXP_fraction_long_no_width_big_precision){
        RUN_TEST("%.14LE", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_EXP_general_long_no_width_big_precision){
        RUN_TEST("%.14LE", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_g_null_no_width_big_precision){
        RUN_TEST("%.14Lg", 0.0L)} END_TEST
    START_TEST(long_double_g_null_neg_no_width_big_precision){
        RUN_TEST("%.14Lg", -0.0L)} END_TEST
    START_TEST(long_double_g_fraction_long_no_width_big_precision){
        RUN_TEST("%.14Lg", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_g_general_long_no_width_big_precision){
        RUN_TEST("%.14Lg", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_G_null_no_width_big_precision){
        RUN_TEST("%.14LG", 0.0L)} END_TEST
    START_TEST(long_double_G_null_neg_no_width_big_precision){
        RUN_TEST("%.14LG", -0.0L)} END_TEST
    START_TEST(long_double_G_fraction_long_no_width_big_precision){
        RUN_TEST("%.14LG", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_G_general_long_no_width_big_precision){
        RUN_TEST("%.14LG", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_null_small_width_no_precision){
        RUN_TEST("%1Lf", 0.0L)} END_TEST
    START_TEST(long_double_null_neg_small_width_no_precision){
        RUN_TEST("%1Lf", -0.0L)} END_TEST
    START_TEST(long_double_fraction_long_small_width_no_precision){
        RUN_TEST("%1Lf", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_general_long_small_width_no_precision){
        RUN_TEST("%1Lf", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_exp_null_small_width_no_precision){
        RUN_TEST("%1Le", 0.0L)} END_TEST
    START_TEST(long_double_exp_null_neg_small_width_no_precision){
        RUN_TEST("%1Le", -0.0L)} END_TEST
    START_TEST(long_double_exp_fraction_long_small_width_no_precision){
        RUN_TEST("%1Le", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_exp_general_long_small_width_no_precision){
        RUN_TEST("%1Le", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_EXP_null_small_width_no_precision){
        RUN_TEST("%1LE", 0.0L)} END_TEST
    START_TEST(long_double_EXP_null_neg_small_width_no_precision){
        RUN_TEST("%1LE", -0.0L)} END_TEST
    START_TEST(long_double_EXP_fraction_long_small_width_no_precision){
        RUN_TEST("%1LE", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_EXP_general_long_small_width_no_precision){
        RUN_TEST("%1LE", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_g_null_small_width_no_precision){
        RUN_TEST("%1Lg", 0.0L)} END_TEST
    START_TEST(long_double_g_null_neg_small_width_no_precision){
        RUN_TEST("%1Lg", -0.0L)} END_TEST
    START_TEST(long_double_g_fraction_long_small_width_no_precision){
        RUN_TEST("%1Lg", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_g_general_long_small_width_no_precision){
        RUN_TEST("%1Lg", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_G_null_small_width_no_precision){
        RUN_TEST("%1LG", 0.0L)} END_TEST
    START_TEST(long_double_G_null_neg_small_width_no_precision){
        RUN_TEST("%1LG", -0.0L)} END_TEST
    START_TEST(long_double_G_fraction_long_small_width_no_precision){
        RUN_TEST("%1LG", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_G_general_long_small_width_no_precision){
        RUN_TEST("%1LG", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_null_small_width_small_precision){
        RUN_TEST("%1.3Lf", 0.0L)} END_TEST
    START_TEST(long_double_null_neg_small_width_small_precision){
        RUN_TEST("%1.3Lf", -0.0L)} END_TEST
    START_TEST(long_double_fraction_long_small_width_small_precision){
        RUN_TEST("%1.3Lf", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_general_long_small_width_small_precision){
        RUN_TEST("%1.3Lf", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_exp_null_small_width_small_precision){
        RUN_TEST("%1.3Le", 0.0L)} END_TEST
    START_TEST(long_double_exp_null_neg_small_width_small_precision){
        RUN_TEST("%1.3Le", -0.0L)} END_TEST
    START_TEST(long_double_exp_fraction_long_small_width_small_precision){
        RUN_TEST("%1.3Le", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_exp_general_long_small_width_small_precision){
        RUN_TEST("%1.3Le", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_EXP_null_small_width_small_precision){
        RUN_TEST("%1.3LE", 0.0L)} END_TEST
    START_TEST(long_double_EXP_null_neg_small_width_small_precision){
        RUN_TEST("%1.3LE", -0.0L)} END_TEST
    START_TEST(long_double_EXP_fraction_long_small_width_small_precision){
        RUN_TEST("%1.3LE", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_EXP_general_long_small_width_small_precision){
        RUN_TEST("%1.3LE", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_g_null_small_width_small_precision){
        RUN_TEST("%1.3Lg", 0.0L)} END_TEST
    START_TEST(long_double_g_null_neg_small_width_small_precision){
        RUN_TEST("%1.3Lg", -0.0L)} END_TEST
    START_TEST(long_double_g_fraction_long_small_width_small_precision){
        RUN_TEST("%1.3Lg", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_g_general_long_small_width_small_precision){
        RUN_TEST("%1.3Lg", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_G_null_small_width_small_precision){
        RUN_TEST("%1.3LG", 0.0L)} END_TEST
    START_TEST(long_double_G_null_neg_small_width_small_precision){
        RUN_TEST("%1.3LG", -0.0L)} END_TEST
    START_TEST(long_double_G_fraction_long_small_width_small_precision){
        RUN_TEST("%1.3LG", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_G_general_long_small_width_small_precision){
        RUN_TEST("%1.3LG", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_null_small_width_big_precision){
        RUN_TEST("%1.14Lf", 0.0L)} END_TEST
    START_TEST(long_double_null_neg_small_width_big_precision){
        RUN_TEST("%1.14Lf", -0.0L)} END_TEST
    START_TEST(long_double_fraction_long_small_width_big_precision){
        RUN_TEST("%1.14Lf", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_general_long_small_width_big_precision){
        RUN_TEST("%1.14Lf", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_exp_null_small_width_big_precision){
        RUN_TEST("%1.14Le", 0.0L)} END_TEST
    START_TEST(long_double_exp_null_neg_small_width_big_precision){
        RUN_TEST("%1.14Le", -0.0L)} END_TEST
    START_TEST(long_double_exp_fraction_long_small_width_big_precision){
        RUN_TEST("%1.14Le", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_exp_general_long_small_width_big_precision){
        RUN_TEST("%1.14Le", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_EXP_null_small_width_big_precision){
        RUN_TEST("%1.14LE", 0.0L)} END_TEST
    START_TEST(long_double_EXP_null_neg_small_width_big_precision){
        RUN_TEST("%1.14LE", -0.0L)} END_TEST
    START_TEST(long_double_EXP_fraction_long_small_width_big_precision){
        RUN_TEST("%1.14LE", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_EXP_general_long_small_width_big_precision){
        RUN_TEST("%1.14LE", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_g_null_small_width_big_precision){
        RUN_TEST("%1.14Lg", 0.0L)} END_TEST
    START_TEST(long_double_g_null_neg_small_width_big_precision){
        RUN_TEST("%1.14Lg", -0.0L)} END_TEST
    START_TEST(long_double_g_fraction_long_small_width_big_precision){
        RUN_TEST("%1.14Lg", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_g_general_long_small_width_big_precision){
        RUN_TEST("%1.14Lg", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_G_null_small_width_big_precision){
        RUN_TEST("%1.14LG", 0.0L)} END_TEST
    START_TEST(long_double_G_null_neg_small_width_big_precision){
        RUN_TEST("%1.14LG", -0.0L)} END_TEST
    START_TEST(long_double_G_fraction_long_small_width_big_precision){
        RUN_TEST("%1.14LG", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_G_general_long_small_width_big_precision){
        RUN_TEST("%1.14LG", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_null_big_width_no_precision){
        RUN_TEST("%50Lf", 0.0L)} END_TEST
    START_TEST(long_double_null_neg_big_width_no_precision){
        RUN_TEST("%50Lf", -0.0L)} END_TEST
    START_TEST(long_double_fraction_long_big_width_no_precision){
        RUN_TEST("%50Lf", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_general_long_big_width_no_precision){
        RUN_TEST("%50Lf", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_exp_null_big_width_no_precision){
        RUN_TEST("%50Le", 0.0L)} END_TEST
    START_TEST(long_double_exp_null_neg_big_width_no_precision){
        RUN_TEST("%50Le", -0.0L)} END_TEST
    START_TEST(long_double_exp_fraction_long_big_width_no_precision){
        RUN_TEST("%50Le", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_exp_general_long_big_width_no_precision){
        RUN_TEST("%50Le", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_EXP_null_big_width_no_precision){
        RUN_TEST("%50LE", 0.0L)} END_TEST
    START_TEST(long_double_EXP_null_neg_big_width_no_precision){
        RUN_TEST("%50LE", -0.0L)} END_TEST
    START_TEST(long_double_EXP_fraction_long_big_width_no_precision){
        RUN_TEST("%50LE", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_EXP_general_long_big_width_no_precision){
        RUN_TEST("%50LE", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_g_null_big_width_no_precision){
        RUN_TEST("%50Lg", 0.0L)} END_TEST
    START_TEST(long_double_g_null_neg_big_width_no_precision){
        RUN_TEST("%50Lg", -0.0L)} END_TEST
    START_TEST(long_double_g_fraction_long_big_width_no_precision){
        RUN_TEST("%50Lg", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_g_general_long_big_width_no_precision){
        RUN_TEST("%50Lg", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_G_null_big_width_no_precision){
        RUN_TEST("%50LG", 0.0L)} END_TEST
    START_TEST(long_double_G_null_neg_big_width_no_precision){
        RUN_TEST("%50LG", -0.0L)} END_TEST
    START_TEST(long_double_G_fraction_long_big_width_no_precision){
        RUN_TEST("%50LG", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_G_general_long_big_width_no_precision){
        RUN_TEST("%50LG", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_null_big_width_small_precision){
        RUN_TEST("%50.3Lf", 0.0L)} END_TEST
    START_TEST(long_double_null_neg_big_width_small_precision){
        RUN_TEST("%50.3Lf", -0.0L)} END_TEST
    START_TEST(long_double_fraction_long_big_width_small_precision){
        RUN_TEST("%50.3Lf", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_general_long_big_width_small_precision){
        RUN_TEST("%50.3Lf", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_exp_null_big_width_small_precision){
        RUN_TEST("%50.3Le", 0.0L)} END_TEST
    START_TEST(long_double_exp_null_neg_big_width_small_precision){
        RUN_TEST("%50.3Le", -0.0L)} END_TEST
    START_TEST(long_double_exp_fraction_long_big_width_small_precision){
        RUN_TEST("%50.3Le", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_exp_general_long_big_width_small_precision){
        RUN_TEST("%50.3Le", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_EXP_null_big_width_small_precision){
        RUN_TEST("%50.3LE", 0.0L)} END_TEST
    START_TEST(long_double_EXP_null_neg_big_width_small_precision){
        RUN_TEST("%50.3LE", -0.0L)} END_TEST
    START_TEST(long_double_EXP_fraction_long_big_width_small_precision){
        RUN_TEST("%50.3LE", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_EXP_general_long_big_width_small_precision){
        RUN_TEST("%50.3LE", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_g_null_big_width_small_precision){
        RUN_TEST("%50.3Lg", 0.0L)} END_TEST
    START_TEST(long_double_g_null_neg_big_width_small_precision){
        RUN_TEST("%50.3Lg", -0.0L)} END_TEST
    START_TEST(long_double_g_fraction_long_big_width_small_precision){
        RUN_TEST("%50.3Lg", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_g_general_long_big_width_small_precision){
        RUN_TEST("%50.3Lg", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_G_null_big_width_small_precision){
        RUN_TEST("%50.3LG", 0.0L)} END_TEST
    START_TEST(long_double_G_null_neg_big_width_small_precision){
        RUN_TEST("%50.3LG", -0.0L)} END_TEST
    START_TEST(long_double_G_fraction_long_big_width_small_precision){
        RUN_TEST("%50.3LG", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_G_general_long_big_width_small_precision){
        RUN_TEST("%50.3LG", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_null_big_width_big_precision){
        RUN_TEST("%50.14Lf", 0.0L)} END_TEST
    START_TEST(long_double_null_neg_big_width_big_precision){
        RUN_TEST("%50.14Lf", -0.0L)} END_TEST
    START_TEST(long_double_fraction_long_big_width_big_precision){
        RUN_TEST("%50.14Lf", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_general_long_big_width_big_precision){
        RUN_TEST("%50.14Lf", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_exp_null_big_width_big_precision){
        RUN_TEST("%50.14Le", 0.0L)} END_TEST
    START_TEST(long_double_exp_null_neg_big_width_big_precision){
        RUN_TEST("%50.14Le", -0.0L)} END_TEST
    START_TEST(long_double_exp_fraction_long_big_width_big_precision){
        RUN_TEST("%50.14Le", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_exp_general_long_big_width_big_precision){
        RUN_TEST("%50.14Le", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_EXP_null_big_width_big_precision){
        RUN_TEST("%50.14LE", 0.0L)} END_TEST
    START_TEST(long_double_EXP_null_neg_big_width_big_precision){
        RUN_TEST("%50.14LE", -0.0L)} END_TEST
    START_TEST(long_double_EXP_fraction_long_big_width_big_precision){
        RUN_TEST("%50.14LE", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_EXP_general_long_big_width_big_precision){
        RUN_TEST("%50.14LE", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_g_null_big_width_big_precision){
        RUN_TEST("%50.14Lg", 0.0L)} END_TEST
    START_TEST(long_double_g_null_neg_big_width_big_precision){
        RUN_TEST("%50.14Lg", -0.0L)} END_TEST
    START_TEST(long_double_g_fraction_long_big_width_big_precision){
        RUN_TEST("%50.14Lg", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_g_general_long_big_width_big_precision){
        RUN_TEST("%50.14Lg", 12345678.9101112131415L)} END_TEST
    START_TEST(long_double_G_null_big_width_big_precision){
        RUN_TEST("%50.14LG", 0.0L)} END_TEST
    START_TEST(long_double_G_null_neg_big_width_big_precision){
        RUN_TEST("%50.14LG", -0.0L)} END_TEST
    START_TEST(long_double_G_fraction_long_big_width_big_precision){
        RUN_TEST("%50.14LG", 0.12356789101112131415L)} END_TEST
    START_TEST(long_double_G_general_long_big_width_big_precision){
        RUN_TEST("%50.14LG", 12345678.9101112131415L)} END_TEST

    START_TEST(float_nan_no_flags){RUN_TEST("%f", NAN)} END_TEST
    START_TEST(float_nan_neg_no_flags){RUN_TEST("%f", -NAN)} END_TEST
    START_TEST(float_infinity_no_flags){RUN_TEST("%f", INFINITY)} END_TEST
    START_TEST(float_infinity_neg_no_flags){RUN_TEST("%f", -INFINITY)} END_TEST
    START_TEST(double_nan_no_flags){RUN_TEST("%lf", NAN)} END_TEST
    START_TEST(double_nan_neg_no_flags){RUN_TEST("%lf", -NAN)} END_TEST
    START_TEST(double_infinity_no_flags){RUN_TEST("%lf", INFINITY)} END_TEST
    START_TEST(double_infinity_neg_no_flags){
        RUN_TEST("%lf", -INFINITY)} END_TEST
    START_TEST(long_double_nan_no_flags){RUN_TEST("%Lf", NAN)} END_TEST
    START_TEST(long_double_nan_neg_no_flags){RUN_TEST("%Lf", -NAN)} END_TEST
    START_TEST(long_double_infinity_no_flags){
        RUN_TEST("%Lf", INFINITY)} END_TEST
    START_TEST(long_double_infinity_neg_no_flags){
        RUN_TEST("%Lf", -INFINITY)} END_TEST
    START_TEST(float_exp_nan_no_flags){RUN_TEST("%e", NAN)} END_TEST
    START_TEST(float_exp_nan_neg_no_flags){RUN_TEST("%e", -NAN)} END_TEST
    START_TEST(float_exp_infinity_no_flags){RUN_TEST("%e", INFINITY)} END_TEST
    START_TEST(float_exp_infinity_neg_no_flags){
        RUN_TEST("%e", -INFINITY)} END_TEST
    START_TEST(double_exp_nan_no_flags){RUN_TEST("%le", NAN)} END_TEST
    START_TEST(double_exp_nan_neg_no_flags){RUN_TEST("%le", -NAN)} END_TEST
    START_TEST(double_exp_infinity_no_flags){RUN_TEST("%le", INFINITY)} END_TEST
    START_TEST(double_exp_infinity_neg_no_flags){
        RUN_TEST("%le", -INFINITY)} END_TEST
    START_TEST(long_double_exp_nan_no_flags){RUN_TEST("%Le", NAN)} END_TEST
    START_TEST(long_double_exp_nan_neg_no_flags){RUN_TEST("%Le", -NAN)} END_TEST
    START_TEST(long_double_exp_infinity_no_flags){
        RUN_TEST("%Le", INFINITY)} END_TEST
    START_TEST(long_double_exp_infinity_neg_no_flags){
        RUN_TEST("%Le", -INFINITY)} END_TEST
    START_TEST(float_EXP_nan_no_flags){RUN_TEST("%E", NAN)} END_TEST
    START_TEST(float_EXP_nan_neg_no_flags){RUN_TEST("%E", -NAN)} END_TEST
    START_TEST(float_EXP_infinity_no_flags){RUN_TEST("%E", INFINITY)} END_TEST
    START_TEST(float_EXP_infinity_neg_no_flags){
        RUN_TEST("%E", -INFINITY)} END_TEST
    START_TEST(double_EXP_nan_no_flags){RUN_TEST("%lE", NAN)} END_TEST
    START_TEST(double_EXP_nan_neg_no_flags){RUN_TEST("%lE", -NAN)} END_TEST
    START_TEST(double_EXP_infinity_no_flags){RUN_TEST("%lE", INFINITY)} END_TEST
    START_TEST(double_EXP_infinity_neg_no_flags){
        RUN_TEST("%lE", -INFINITY)} END_TEST
    START_TEST(long_double_EXP_nan_no_flags){RUN_TEST("%LE", NAN)} END_TEST
    START_TEST(long_double_EXP_nan_neg_no_flags){RUN_TEST("%LE", -NAN)} END_TEST
    START_TEST(long_double_EXP_infinity_no_flags){
        RUN_TEST("%LE", INFINITY)} END_TEST
    START_TEST(long_double_EXP_infinity_neg_no_flags){
        RUN_TEST("%LE", -INFINITY)} END_TEST
    START_TEST(float_g_nan_no_flags){RUN_TEST("%g", NAN)} END_TEST
    START_TEST(float_g_nan_neg_no_flags){RUN_TEST("%g", -NAN)} END_TEST
    START_TEST(float_g_infinity_no_flags){RUN_TEST("%g", INFINITY)} END_TEST
    START_TEST(float_g_infinity_neg_no_flags){
        RUN_TEST("%g", -INFINITY)} END_TEST
    START_TEST(double_g_nan_no_flags){RUN_TEST("%lg", NAN)} END_TEST
    START_TEST(double_g_nan_neg_no_flags){RUN_TEST("%lg", -NAN)} END_TEST
    START_TEST(double_g_infinity_no_flags){RUN_TEST("%lg", INFINITY)} END_TEST
    START_TEST(double_g_infinity_neg_no_flags){
        RUN_TEST("%lg", -INFINITY)} END_TEST
    START_TEST(long_double_g_nan_no_flags){RUN_TEST("%Lg", NAN)} END_TEST
    START_TEST(long_double_g_nan_neg_no_flags){RUN_TEST("%Lg", -NAN)} END_TEST
    START_TEST(long_double_g_infinity_no_flags){
        RUN_TEST("%Lg", INFINITY)} END_TEST
    START_TEST(long_double_g_infinity_neg_no_flags){
        RUN_TEST("%Lg", -INFINITY)} END_TEST
    START_TEST(float_G_nan_no_flags){RUN_TEST("%G", NAN)} END_TEST
    START_TEST(float_G_nan_neg_no_flags){RUN_TEST("%G", -NAN)} END_TEST
    START_TEST(float_G_infinity_no_flags){RUN_TEST("%G", INFINITY)} END_TEST
    START_TEST(float_G_infinity_neg_no_flags){
        RUN_TEST("%G", -INFINITY)} END_TEST
    START_TEST(double_G_nan_no_flags){RUN_TEST("%lG", NAN)} END_TEST
    START_TEST(double_G_nan_neg_no_flags){RUN_TEST("%lG", -NAN)} END_TEST
    START_TEST(double_G_infinity_no_flags){RUN_TEST("%lG", INFINITY)} END_TEST
    START_TEST(double_G_infinity_neg_no_flags){
        RUN_TEST("%lG", -INFINITY)} END_TEST
    START_TEST(long_double_G_nan_no_flags){RUN_TEST("%LG", NAN)} END_TEST
    START_TEST(long_double_G_nan_neg_no_flags){RUN_TEST("%LG", -NAN)} END_TEST
    START_TEST(long_double_G_infinity_no_flags){
        RUN_TEST("%LG", INFINITY)} END_TEST
    START_TEST(long_double_G_infinity_neg_no_flags){
        RUN_TEST("%LG", -INFINITY)} END_TEST
    START_TEST(float_nan_prefix_sign){RUN_TEST("%+f", NAN)} END_TEST
    START_TEST(float_nan_neg_prefix_sign){RUN_TEST("%+f", -NAN)} END_TEST
    START_TEST(float_infinity_prefix_sign){RUN_TEST("%+f", INFINITY)} END_TEST
    START_TEST(float_infinity_neg_prefix_sign){
        RUN_TEST("%+f", -INFINITY)} END_TEST
    START_TEST(double_nan_prefix_sign){RUN_TEST("%+lf", NAN)} END_TEST
    START_TEST(double_nan_neg_prefix_sign){RUN_TEST("%+lf", -NAN)} END_TEST
    START_TEST(double_infinity_prefix_sign){RUN_TEST("%+lf", INFINITY)} END_TEST
    START_TEST(double_infinity_neg_prefix_sign){
        RUN_TEST("%+lf", -INFINITY)} END_TEST
    START_TEST(long_double_nan_prefix_sign){RUN_TEST("%+Lf", NAN)} END_TEST
    START_TEST(long_double_nan_neg_prefix_sign){RUN_TEST("%+Lf", -NAN)} END_TEST
    START_TEST(long_double_infinity_prefix_sign){
        RUN_TEST("%+Lf", INFINITY)} END_TEST
    START_TEST(long_double_infinity_neg_prefix_sign){
        RUN_TEST("%+Lf", -INFINITY)} END_TEST
    START_TEST(float_exp_nan_prefix_sign){RUN_TEST("%+e", NAN)} END_TEST
    START_TEST(float_exp_nan_neg_prefix_sign){RUN_TEST("%+e", -NAN)} END_TEST
    START_TEST(float_exp_infinity_prefix_sign){
        RUN_TEST("%+e", INFINITY)} END_TEST
    START_TEST(float_exp_infinity_neg_prefix_sign){
        RUN_TEST("%+e", -INFINITY)} END_TEST
    START_TEST(double_exp_nan_prefix_sign){RUN_TEST("%+le", NAN)} END_TEST
    START_TEST(double_exp_nan_neg_prefix_sign){RUN_TEST("%+le", -NAN)} END_TEST
    START_TEST(double_exp_infinity_prefix_sign){
        RUN_TEST("%+le", INFINITY)} END_TEST
    START_TEST(double_exp_infinity_neg_prefix_sign){
        RUN_TEST("%+le", -INFINITY)} END_TEST
    START_TEST(long_double_exp_nan_prefix_sign){RUN_TEST("%+Le", NAN)} END_TEST
    START_TEST(long_double_exp_nan_neg_prefix_sign){
        RUN_TEST("%+Le", -NAN)} END_TEST
    START_TEST(long_double_exp_infinity_prefix_sign){
        RUN_TEST("%+Le", INFINITY)} END_TEST
    START_TEST(long_double_exp_infinity_neg_prefix_sign){
        RUN_TEST("%+Le", -INFINITY)} END_TEST
    START_TEST(float_EXP_nan_prefix_sign){RUN_TEST("%+E", NAN)} END_TEST
    START_TEST(float_EXP_nan_neg_prefix_sign){RUN_TEST("%+E", -NAN)} END_TEST
    START_TEST(float_EXP_infinity_prefix_sign){
        RUN_TEST("%+E", INFINITY)} END_TEST
    START_TEST(float_EXP_infinity_neg_prefix_sign){
        RUN_TEST("%+E", -INFINITY)} END_TEST
    START_TEST(double_EXP_nan_prefix_sign){RUN_TEST("%+lE", NAN)} END_TEST
    START_TEST(double_EXP_nan_neg_prefix_sign){RUN_TEST("%+lE", -NAN)} END_TEST
    START_TEST(double_EXP_infinity_prefix_sign){
        RUN_TEST("%+lE", INFINITY)} END_TEST
    START_TEST(double_EXP_infinity_neg_prefix_sign){
        RUN_TEST("%+lE", -INFINITY)} END_TEST
    START_TEST(long_double_EXP_nan_prefix_sign){RUN_TEST("%+LE", NAN)} END_TEST
    START_TEST(long_double_EXP_nan_neg_prefix_sign){
        RUN_TEST("%+LE", -NAN)} END_TEST
    START_TEST(long_double_EXP_infinity_prefix_sign){
        RUN_TEST("%+LE", INFINITY)} END_TEST
    START_TEST(long_double_EXP_infinity_neg_prefix_sign){
        RUN_TEST("%+LE", -INFINITY)} END_TEST
    START_TEST(float_g_nan_prefix_sign){RUN_TEST("%+g", NAN)} END_TEST
    START_TEST(float_g_nan_neg_prefix_sign){RUN_TEST("%+g", -NAN)} END_TEST
    START_TEST(float_g_infinity_prefix_sign){RUN_TEST("%+g", INFINITY)} END_TEST
    START_TEST(float_g_infinity_neg_prefix_sign){
        RUN_TEST("%+g", -INFINITY)} END_TEST
    START_TEST(double_g_nan_prefix_sign){RUN_TEST("%+lg", NAN)} END_TEST
    START_TEST(double_g_nan_neg_prefix_sign){RUN_TEST("%+lg", -NAN)} END_TEST
    START_TEST(double_g_infinity_prefix_sign){
        RUN_TEST("%+lg", INFINITY)} END_TEST
    START_TEST(double_g_infinity_neg_prefix_sign){
        RUN_TEST("%+lg", -INFINITY)} END_TEST
    START_TEST(long_double_g_nan_prefix_sign){RUN_TEST("%+Lg", NAN)} END_TEST
    START_TEST(long_double_g_nan_neg_prefix_sign){
        RUN_TEST("%+Lg", -NAN)} END_TEST
    START_TEST(long_double_g_infinity_prefix_sign){
        RUN_TEST("%+Lg", INFINITY)} END_TEST
    START_TEST(long_double_g_infinity_neg_prefix_sign){
        RUN_TEST("%+Lg", -INFINITY)} END_TEST
    START_TEST(float_G_nan_prefix_sign){RUN_TEST("%+G", NAN)} END_TEST
    START_TEST(float_G_nan_neg_prefix_sign){RUN_TEST("%+G", -NAN)} END_TEST
    START_TEST(float_G_infinity_prefix_sign){RUN_TEST("%+G", INFINITY)} END_TEST
    START_TEST(float_G_infinity_neg_prefix_sign){
        RUN_TEST("%+G", -INFINITY)} END_TEST
    START_TEST(double_G_nan_prefix_sign){RUN_TEST("%+lG", NAN)} END_TEST
    START_TEST(double_G_nan_neg_prefix_sign){RUN_TEST("%+lG", -NAN)} END_TEST
    START_TEST(double_G_infinity_prefix_sign){
        RUN_TEST("%+lG", INFINITY)} END_TEST
    START_TEST(double_G_infinity_neg_prefix_sign){
        RUN_TEST("%+lG", -INFINITY)} END_TEST
    START_TEST(long_double_G_nan_prefix_sign){RUN_TEST("%+LG", NAN)} END_TEST
    START_TEST(long_double_G_nan_neg_prefix_sign){
        RUN_TEST("%+LG", -NAN)} END_TEST
    START_TEST(long_double_G_infinity_prefix_sign){
        RUN_TEST("%+LG", INFINITY)} END_TEST
    START_TEST(long_double_G_infinity_neg_prefix_sign){
        RUN_TEST("%+LG", -INFINITY)} END_TEST
    START_TEST(float_nan_prefix_space){RUN_TEST("% f", NAN)} END_TEST
    START_TEST(float_nan_neg_prefix_space){RUN_TEST("% f", -NAN)} END_TEST
    START_TEST(float_infinity_prefix_space){RUN_TEST("% f", INFINITY)} END_TEST
    START_TEST(float_infinity_neg_prefix_space){
        RUN_TEST("% f", -INFINITY)} END_TEST
    START_TEST(double_nan_prefix_space){RUN_TEST("% lf", NAN)} END_TEST
    START_TEST(double_nan_neg_prefix_space){RUN_TEST("% lf", -NAN)} END_TEST
    START_TEST(double_infinity_prefix_space){
        RUN_TEST("% lf", INFINITY)} END_TEST
    START_TEST(double_infinity_neg_prefix_space){
        RUN_TEST("% lf", -INFINITY)} END_TEST
    START_TEST(long_double_nan_prefix_space){RUN_TEST("% Lf", NAN)} END_TEST
    START_TEST(long_double_nan_neg_prefix_space){
        RUN_TEST("% Lf", -NAN)} END_TEST
    START_TEST(long_double_infinity_prefix_space){
        RUN_TEST("% Lf", INFINITY)} END_TEST
    START_TEST(long_double_infinity_neg_prefix_space){
        RUN_TEST("% Lf", -INFINITY)} END_TEST
    START_TEST(float_exp_nan_prefix_space){RUN_TEST("% e", NAN)} END_TEST
    START_TEST(float_exp_nan_neg_prefix_space){RUN_TEST("% e", -NAN)} END_TEST
    START_TEST(float_exp_infinity_prefix_space){
        RUN_TEST("% e", INFINITY)} END_TEST
    START_TEST(float_exp_infinity_neg_prefix_space){
        RUN_TEST("% e", -INFINITY)} END_TEST
    START_TEST(double_exp_nan_prefix_space){RUN_TEST("% le", NAN)} END_TEST
    START_TEST(double_exp_nan_neg_prefix_space){RUN_TEST("% le", -NAN)} END_TEST
    START_TEST(double_exp_infinity_prefix_space){
        RUN_TEST("% le", INFINITY)} END_TEST
    START_TEST(double_exp_infinity_neg_prefix_space){
        RUN_TEST("% le", -INFINITY)} END_TEST
    START_TEST(long_double_exp_nan_prefix_space){RUN_TEST("% Le", NAN)} END_TEST
    START_TEST(long_double_exp_nan_neg_prefix_space){
        RUN_TEST("% Le", -NAN)} END_TEST
    START_TEST(long_double_exp_infinity_prefix_space){
        RUN_TEST("% Le", INFINITY)} END_TEST
    START_TEST(long_double_exp_infinity_neg_prefix_space){
        RUN_TEST("% Le", -INFINITY)} END_TEST
    START_TEST(float_EXP_nan_prefix_space){RUN_TEST("% E", NAN)} END_TEST
    START_TEST(float_EXP_nan_neg_prefix_space){RUN_TEST("% E", -NAN)} END_TEST
    START_TEST(float_EXP_infinity_prefix_space){
        RUN_TEST("% E", INFINITY)} END_TEST
    START_TEST(float_EXP_infinity_neg_prefix_space){
        RUN_TEST("% E", -INFINITY)} END_TEST
    START_TEST(double_EXP_nan_prefix_space){RUN_TEST("% lE", NAN)} END_TEST
    START_TEST(double_EXP_nan_neg_prefix_space){RUN_TEST("% lE", -NAN)} END_TEST
    START_TEST(double_EXP_infinity_prefix_space){
        RUN_TEST("% lE", INFINITY)} END_TEST
    START_TEST(double_EXP_infinity_neg_prefix_space){
        RUN_TEST("% lE", -INFINITY)} END_TEST
    START_TEST(long_double_EXP_nan_prefix_space){RUN_TEST("% LE", NAN)} END_TEST
    START_TEST(long_double_EXP_nan_neg_prefix_space){
        RUN_TEST("% LE", -NAN)} END_TEST
    START_TEST(long_double_EXP_infinity_prefix_space){
        RUN_TEST("% LE", INFINITY)} END_TEST
    START_TEST(long_double_EXP_infinity_neg_prefix_space){
        RUN_TEST("% LE", -INFINITY)} END_TEST
    START_TEST(float_g_nan_prefix_space){RUN_TEST("% g", NAN)} END_TEST
    START_TEST(float_g_nan_neg_prefix_space){RUN_TEST("% g", -NAN)} END_TEST
    START_TEST(float_g_infinity_prefix_space){
        RUN_TEST("% g", INFINITY)} END_TEST
    START_TEST(float_g_infinity_neg_prefix_space){
        RUN_TEST("% g", -INFINITY)} END_TEST
    START_TEST(double_g_nan_prefix_space){RUN_TEST("% lg", NAN)} END_TEST
    START_TEST(double_g_nan_neg_prefix_space){RUN_TEST("% lg", -NAN)} END_TEST
    START_TEST(double_g_infinity_prefix_space){
        RUN_TEST("% lg", INFINITY)} END_TEST
    START_TEST(double_g_infinity_neg_prefix_space){
        RUN_TEST("% lg", -INFINITY)} END_TEST
    START_TEST(long_double_g_nan_prefix_space){RUN_TEST("% Lg", NAN)} END_TEST
    START_TEST(long_double_g_nan_neg_prefix_space){
        RUN_TEST("% Lg", -NAN)} END_TEST
    START_TEST(long_double_g_infinity_prefix_space){
        RUN_TEST("% Lg", INFINITY)} END_TEST
    START_TEST(long_double_g_infinity_neg_prefix_space){
        RUN_TEST("% Lg", -INFINITY)} END_TEST
    START_TEST(float_G_nan_prefix_space){RUN_TEST("% G", NAN)} END_TEST
    START_TEST(float_G_nan_neg_prefix_space){RUN_TEST("% G", -NAN)} END_TEST
    START_TEST(float_G_infinity_prefix_space){
        RUN_TEST("% G", INFINITY)} END_TEST
    START_TEST(float_G_infinity_neg_prefix_space){
        RUN_TEST("% G", -INFINITY)} END_TEST
    START_TEST(double_G_nan_prefix_space){RUN_TEST("% lG", NAN)} END_TEST
    START_TEST(double_G_nan_neg_prefix_space){RUN_TEST("% lG", -NAN)} END_TEST
    START_TEST(double_G_infinity_prefix_space){
        RUN_TEST("% lG", INFINITY)} END_TEST
    START_TEST(double_G_infinity_neg_prefix_space){
        RUN_TEST("% lG", -INFINITY)} END_TEST
    START_TEST(long_double_G_nan_prefix_space){RUN_TEST("% LG", NAN)} END_TEST
    START_TEST(long_double_G_nan_neg_prefix_space){
        RUN_TEST("% LG", -NAN)} END_TEST
    START_TEST(long_double_G_infinity_prefix_space){
        RUN_TEST("% LG", INFINITY)} END_TEST
    START_TEST(long_double_G_infinity_neg_prefix_space){
        RUN_TEST("% LG", -INFINITY)} END_TEST
    START_TEST(float_nan_left_alignment){RUN_TEST("%-f", NAN)} END_TEST
    START_TEST(float_nan_neg_left_alignment){RUN_TEST("%-f", -NAN)} END_TEST
    START_TEST(float_infinity_left_alignment){
        RUN_TEST("%-f", INFINITY)} END_TEST
    START_TEST(float_infinity_neg_left_alignment){
        RUN_TEST("%-f", -INFINITY)} END_TEST
    START_TEST(double_nan_left_alignment){RUN_TEST("%-lf", NAN)} END_TEST
    START_TEST(double_nan_neg_left_alignment){RUN_TEST("%-lf", -NAN)} END_TEST
    START_TEST(double_infinity_left_alignment){
        RUN_TEST("%-lf", INFINITY)} END_TEST
    START_TEST(double_infinity_neg_left_alignment){
        RUN_TEST("%-lf", -INFINITY)} END_TEST
    START_TEST(long_double_nan_left_alignment){RUN_TEST("%-Lf", NAN)} END_TEST
    START_TEST(long_double_nan_neg_left_alignment){
        RUN_TEST("%-Lf", -NAN)} END_TEST
    START_TEST(long_double_infinity_left_alignment){
        RUN_TEST("%-Lf", INFINITY)} END_TEST
    START_TEST(long_double_infinity_neg_left_alignment){
        RUN_TEST("%-Lf", -INFINITY)} END_TEST
    START_TEST(float_exp_nan_left_alignment){RUN_TEST("%-e", NAN)} END_TEST
    START_TEST(float_exp_nan_neg_left_alignment){RUN_TEST("%-e", -NAN)} END_TEST
    START_TEST(float_exp_infinity_left_alignment){
        RUN_TEST("%-e", INFINITY)} END_TEST
    START_TEST(float_exp_infinity_neg_left_alignment){
        RUN_TEST("%-e", -INFINITY)} END_TEST
    START_TEST(double_exp_nan_left_alignment){RUN_TEST("%-le", NAN)} END_TEST
    START_TEST(double_exp_nan_neg_left_alignment){
        RUN_TEST("%-le", -NAN)} END_TEST
    START_TEST(double_exp_infinity_left_alignment){
        RUN_TEST("%-le", INFINITY)} END_TEST
    START_TEST(double_exp_infinity_neg_left_alignment){
        RUN_TEST("%-le", -INFINITY)} END_TEST
    START_TEST(long_double_exp_nan_left_alignment){
        RUN_TEST("%-Le", NAN)} END_TEST
    START_TEST(long_double_exp_nan_neg_left_alignment){
        RUN_TEST("%-Le", -NAN)} END_TEST
    START_TEST(long_double_exp_infinity_left_alignment){
        RUN_TEST("%-Le", INFINITY)} END_TEST
    START_TEST(long_double_exp_infinity_neg_left_alignment){
        RUN_TEST("%-Le", -INFINITY)} END_TEST
    START_TEST(float_EXP_nan_left_alignment){RUN_TEST("%-E", NAN)} END_TEST
    START_TEST(float_EXP_nan_neg_left_alignment){RUN_TEST("%-E", -NAN)} END_TEST
    START_TEST(float_EXP_infinity_left_alignment){
        RUN_TEST("%-E", INFINITY)} END_TEST
    START_TEST(float_EXP_infinity_neg_left_alignment){
        RUN_TEST("%-E", -INFINITY)} END_TEST
    START_TEST(double_EXP_nan_left_alignment){RUN_TEST("%-lE", NAN)} END_TEST
    START_TEST(double_EXP_nan_neg_left_alignment){
        RUN_TEST("%-lE", -NAN)} END_TEST
    START_TEST(double_EXP_infinity_left_alignment){
        RUN_TEST("%-lE", INFINITY)} END_TEST
    START_TEST(double_EXP_infinity_neg_left_alignment){
        RUN_TEST("%-lE", -INFINITY)} END_TEST
    START_TEST(long_double_EXP_nan_left_alignment){
        RUN_TEST("%-LE", NAN)} END_TEST
    START_TEST(long_double_EXP_nan_neg_left_alignment){
        RUN_TEST("%-LE", -NAN)} END_TEST
    START_TEST(long_double_EXP_infinity_left_alignment){
        RUN_TEST("%-LE", INFINITY)} END_TEST
    START_TEST(long_double_EXP_infinity_neg_left_alignment){
        RUN_TEST("%-LE", -INFINITY)} END_TEST
    START_TEST(float_g_nan_left_alignment){RUN_TEST("%-g", NAN)} END_TEST
    START_TEST(float_g_nan_neg_left_alignment){RUN_TEST("%-g", -NAN)} END_TEST
    START_TEST(float_g_infinity_left_alignment){
        RUN_TEST("%-g", INFINITY)} END_TEST
    START_TEST(float_g_infinity_neg_left_alignment){
        RUN_TEST("%-g", -INFINITY)} END_TEST
    START_TEST(double_g_nan_left_alignment){RUN_TEST("%-lg", NAN)} END_TEST
    START_TEST(double_g_nan_neg_left_alignment){RUN_TEST("%-lg", -NAN)} END_TEST
    START_TEST(double_g_infinity_left_alignment){
        RUN_TEST("%-lg", INFINITY)} END_TEST
    START_TEST(double_g_infinity_neg_left_alignment){
        RUN_TEST("%-lg", -INFINITY)} END_TEST
    START_TEST(long_double_g_nan_left_alignment){RUN_TEST("%-Lg", NAN)} END_TEST
    START_TEST(long_double_g_nan_neg_left_alignment){
        RUN_TEST("%-Lg", -NAN)} END_TEST
    START_TEST(long_double_g_infinity_left_alignment){
        RUN_TEST("%-Lg", INFINITY)} END_TEST
    START_TEST(long_double_g_infinity_neg_left_alignment){
        RUN_TEST("%-Lg", -INFINITY)} END_TEST
    START_TEST(float_G_nan_left_alignment){RUN_TEST("%-G", NAN)} END_TEST
    START_TEST(float_G_nan_neg_left_alignment){RUN_TEST("%-G", -NAN)} END_TEST
    START_TEST(float_G_infinity_left_alignment){
        RUN_TEST("%-G", INFINITY)} END_TEST
    START_TEST(float_G_infinity_neg_left_alignment){
        RUN_TEST("%-G", -INFINITY)} END_TEST
    START_TEST(double_G_nan_left_alignment){RUN_TEST("%-lG", NAN)} END_TEST
    START_TEST(double_G_nan_neg_left_alignment){RUN_TEST("%-lG", -NAN)} END_TEST
    START_TEST(double_G_infinity_left_alignment){
        RUN_TEST("%-lG", INFINITY)} END_TEST
    START_TEST(double_G_infinity_neg_left_alignment){
        RUN_TEST("%-lG", -INFINITY)} END_TEST
    START_TEST(long_double_G_nan_left_alignment){RUN_TEST("%-LG", NAN)} END_TEST
    START_TEST(long_double_G_nan_neg_left_alignment){
        RUN_TEST("%-LG", -NAN)} END_TEST
    START_TEST(long_double_G_infinity_left_alignment){
        RUN_TEST("%-LG", INFINITY)} END_TEST
    START_TEST(long_double_G_infinity_neg_left_alignment){
        RUN_TEST("%-LG", -INFINITY)} END_TEST
    START_TEST(float_nan_leading_zeroes){RUN_TEST("%0f", NAN)} END_TEST
    START_TEST(float_nan_neg_leading_zeroes){RUN_TEST("%0f", -NAN)} END_TEST
    START_TEST(float_infinity_leading_zeroes){
        RUN_TEST("%0f", INFINITY)} END_TEST
    START_TEST(float_infinity_neg_leading_zeroes){
        RUN_TEST("%0f", -INFINITY)} END_TEST
    START_TEST(double_nan_leading_zeroes){RUN_TEST("%0lf", NAN)} END_TEST
    START_TEST(double_nan_neg_leading_zeroes){RUN_TEST("%0lf", -NAN)} END_TEST
    START_TEST(double_infinity_leading_zeroes){
        RUN_TEST("%0lf", INFINITY)} END_TEST
    START_TEST(double_infinity_neg_leading_zeroes){
        RUN_TEST("%0lf", -INFINITY)} END_TEST
    START_TEST(long_double_nan_leading_zeroes){RUN_TEST("%0Lf", NAN)} END_TEST
    START_TEST(long_double_nan_neg_leading_zeroes){
        RUN_TEST("%0Lf", -NAN)} END_TEST
    START_TEST(long_double_infinity_leading_zeroes){
        RUN_TEST("%0Lf", INFINITY)} END_TEST
    START_TEST(long_double_infinity_neg_leading_zeroes){
        RUN_TEST("%0Lf", -INFINITY)} END_TEST
    START_TEST(float_exp_nan_leading_zeroes){RUN_TEST("%0e", NAN)} END_TEST
    START_TEST(float_exp_nan_neg_leading_zeroes){RUN_TEST("%0e", -NAN)} END_TEST
    START_TEST(float_exp_infinity_leading_zeroes){
        RUN_TEST("%0e", INFINITY)} END_TEST
    START_TEST(float_exp_infinity_neg_leading_zeroes){
        RUN_TEST("%0e", -INFINITY)} END_TEST
    START_TEST(double_exp_nan_leading_zeroes){RUN_TEST("%0le", NAN)} END_TEST
    START_TEST(double_exp_nan_neg_leading_zeroes){
        RUN_TEST("%0le", -NAN)} END_TEST
    START_TEST(double_exp_infinity_leading_zeroes){
        RUN_TEST("%0le", INFINITY)} END_TEST
    START_TEST(double_exp_infinity_neg_leading_zeroes){
        RUN_TEST("%0le", -INFINITY)} END_TEST
    START_TEST(long_double_exp_nan_leading_zeroes){
        RUN_TEST("%0Le", NAN)} END_TEST
    START_TEST(long_double_exp_nan_neg_leading_zeroes){
        RUN_TEST("%0Le", -NAN)} END_TEST
    START_TEST(long_double_exp_infinity_leading_zeroes){
        RUN_TEST("%0Le", INFINITY)} END_TEST
    START_TEST(long_double_exp_infinity_neg_leading_zeroes){
        RUN_TEST("%0Le", -INFINITY)} END_TEST
    START_TEST(float_EXP_nan_leading_zeroes){RUN_TEST("%0E", NAN)} END_TEST
    START_TEST(float_EXP_nan_neg_leading_zeroes){RUN_TEST("%0E", -NAN)} END_TEST
    START_TEST(float_EXP_infinity_leading_zeroes){
        RUN_TEST("%0E", INFINITY)} END_TEST
    START_TEST(float_EXP_infinity_neg_leading_zeroes){
        RUN_TEST("%0E", -INFINITY)} END_TEST
    START_TEST(double_EXP_nan_leading_zeroes){RUN_TEST("%0lE", NAN)} END_TEST
    START_TEST(double_EXP_nan_neg_leading_zeroes){
        RUN_TEST("%0lE", -NAN)} END_TEST
    START_TEST(double_EXP_infinity_leading_zeroes){
        RUN_TEST("%0lE", INFINITY)} END_TEST
    START_TEST(double_EXP_infinity_neg_leading_zeroes){
        RUN_TEST("%0lE", -INFINITY)} END_TEST
    START_TEST(long_double_EXP_nan_leading_zeroes){
        RUN_TEST("%0LE", NAN)} END_TEST
    START_TEST(long_double_EXP_nan_neg_leading_zeroes){
        RUN_TEST("%0LE", -NAN)} END_TEST
    START_TEST(long_double_EXP_infinity_leading_zeroes){
        RUN_TEST("%0LE", INFINITY)} END_TEST
    START_TEST(long_double_EXP_infinity_neg_leading_zeroes){
        RUN_TEST("%0LE", -INFINITY)} END_TEST
    START_TEST(float_g_nan_leading_zeroes){RUN_TEST("%0g", NAN)} END_TEST
    START_TEST(float_g_nan_neg_leading_zeroes){RUN_TEST("%0g", -NAN)} END_TEST
    START_TEST(float_g_infinity_leading_zeroes){
        RUN_TEST("%0g", INFINITY)} END_TEST
    START_TEST(float_g_infinity_neg_leading_zeroes){
        RUN_TEST("%0g", -INFINITY)} END_TEST
    START_TEST(double_g_nan_leading_zeroes){RUN_TEST("%0lg", NAN)} END_TEST
    START_TEST(double_g_nan_neg_leading_zeroes){RUN_TEST("%0lg", -NAN)} END_TEST
    START_TEST(double_g_infinity_leading_zeroes){
        RUN_TEST("%0lg", INFINITY)} END_TEST
    START_TEST(double_g_infinity_neg_leading_zeroes){
        RUN_TEST("%0lg", -INFINITY)} END_TEST
    START_TEST(long_double_g_nan_leading_zeroes){RUN_TEST("%0Lg", NAN)} END_TEST
    START_TEST(long_double_g_nan_neg_leading_zeroes){
        RUN_TEST("%0Lg", -NAN)} END_TEST
    START_TEST(long_double_g_infinity_leading_zeroes){
        RUN_TEST("%0Lg", INFINITY)} END_TEST
    START_TEST(long_double_g_infinity_neg_leading_zeroes){
        RUN_TEST("%0Lg", -INFINITY)} END_TEST
    START_TEST(float_G_nan_leading_zeroes){RUN_TEST("%0G", NAN)} END_TEST
    START_TEST(float_G_nan_neg_leading_zeroes){RUN_TEST("%0G", -NAN)} END_TEST
    START_TEST(float_G_infinity_leading_zeroes){
        RUN_TEST("%0G", INFINITY)} END_TEST
    START_TEST(float_G_infinity_neg_leading_zeroes){
        RUN_TEST("%0G", -INFINITY)} END_TEST
    START_TEST(double_G_nan_leading_zeroes){RUN_TEST("%0lG", NAN)} END_TEST
    START_TEST(double_G_nan_neg_leading_zeroes){RUN_TEST("%0lG", -NAN)} END_TEST
    START_TEST(double_G_infinity_leading_zeroes){
        RUN_TEST("%0lG", INFINITY)} END_TEST
    START_TEST(double_G_infinity_neg_leading_zeroes){
        RUN_TEST("%0lG", -INFINITY)} END_TEST
    START_TEST(long_double_G_nan_leading_zeroes){RUN_TEST("%0LG", NAN)} END_TEST
    START_TEST(long_double_G_nan_neg_leading_zeroes){
        RUN_TEST("%0LG", -NAN)} END_TEST
    START_TEST(long_double_G_infinity_leading_zeroes){
        RUN_TEST("%0LG", INFINITY)} END_TEST
    START_TEST(long_double_G_infinity_neg_leading_zeroes){
        RUN_TEST("%0LG", -INFINITY)} END_TEST
    START_TEST(float_nan_alt_format){RUN_TEST("%#f", NAN)} END_TEST
    START_TEST(float_nan_neg_alt_format){RUN_TEST("%#f", -NAN)} END_TEST
    START_TEST(float_infinity_alt_format){RUN_TEST("%#f", INFINITY)} END_TEST
    START_TEST(float_infinity_neg_alt_format){
        RUN_TEST("%#f", -INFINITY)} END_TEST
    START_TEST(double_nan_alt_format){RUN_TEST("%#lf", NAN)} END_TEST
    START_TEST(double_nan_neg_alt_format){RUN_TEST("%#lf", -NAN)} END_TEST
    START_TEST(double_infinity_alt_format){RUN_TEST("%#lf", INFINITY)} END_TEST
    START_TEST(double_infinity_neg_alt_format){
        RUN_TEST("%#lf", -INFINITY)} END_TEST
    START_TEST(long_double_nan_alt_format){RUN_TEST("%#Lf", NAN)} END_TEST
    START_TEST(long_double_nan_neg_alt_format){RUN_TEST("%#Lf", -NAN)} END_TEST
    START_TEST(long_double_infinity_alt_format){
        RUN_TEST("%#Lf", INFINITY)} END_TEST
    START_TEST(long_double_infinity_neg_alt_format){
        RUN_TEST("%#Lf", -INFINITY)} END_TEST
    START_TEST(float_exp_nan_alt_format){RUN_TEST("%#e", NAN)} END_TEST
    START_TEST(float_exp_nan_neg_alt_format){RUN_TEST("%#e", -NAN)} END_TEST
    START_TEST(float_exp_infinity_alt_format){
        RUN_TEST("%#e", INFINITY)} END_TEST
    START_TEST(float_exp_infinity_neg_alt_format){
        RUN_TEST("%#e", -INFINITY)} END_TEST
    START_TEST(double_exp_nan_alt_format){RUN_TEST("%#le", NAN)} END_TEST
    START_TEST(double_exp_nan_neg_alt_format){RUN_TEST("%#le", -NAN)} END_TEST
    START_TEST(double_exp_infinity_alt_format){
        RUN_TEST("%#le", INFINITY)} END_TEST
    START_TEST(double_exp_infinity_neg_alt_format){
        RUN_TEST("%#le", -INFINITY)} END_TEST
    START_TEST(long_double_exp_nan_alt_format){RUN_TEST("%#Le", NAN)} END_TEST
    START_TEST(long_double_exp_nan_neg_alt_format){
        RUN_TEST("%#Le", -NAN)} END_TEST
    START_TEST(long_double_exp_infinity_alt_format){
        RUN_TEST("%#Le", INFINITY)} END_TEST
    START_TEST(long_double_exp_infinity_neg_alt_format){
        RUN_TEST("%#Le", -INFINITY)} END_TEST
    START_TEST(float_EXP_nan_alt_format){RUN_TEST("%#E", NAN)} END_TEST
    START_TEST(float_EXP_nan_neg_alt_format){RUN_TEST("%#E", -NAN)} END_TEST
    START_TEST(float_EXP_infinity_alt_format){
        RUN_TEST("%#E", INFINITY)} END_TEST
    START_TEST(float_EXP_infinity_neg_alt_format){
        RUN_TEST("%#E", -INFINITY)} END_TEST
    START_TEST(double_EXP_nan_alt_format){RUN_TEST("%#lE", NAN)} END_TEST
    START_TEST(double_EXP_nan_neg_alt_format){RUN_TEST("%#lE", -NAN)} END_TEST
    START_TEST(double_EXP_infinity_alt_format){
        RUN_TEST("%#lE", INFINITY)} END_TEST
    START_TEST(double_EXP_infinity_neg_alt_format){
        RUN_TEST("%#lE", -INFINITY)} END_TEST
    START_TEST(long_double_EXP_nan_alt_format){RUN_TEST("%#LE", NAN)} END_TEST
    START_TEST(long_double_EXP_nan_neg_alt_format){
        RUN_TEST("%#LE", -NAN)} END_TEST
    START_TEST(long_double_EXP_infinity_alt_format){
        RUN_TEST("%#LE", INFINITY)} END_TEST
    START_TEST(long_double_EXP_infinity_neg_alt_format){
        RUN_TEST("%#LE", -INFINITY)} END_TEST
    START_TEST(float_g_nan_alt_format){RUN_TEST("%#g", NAN)} END_TEST
    START_TEST(float_g_nan_neg_alt_format){RUN_TEST("%#g", -NAN)} END_TEST
    START_TEST(float_g_infinity_alt_format){RUN_TEST("%#g", INFINITY)} END_TEST
    START_TEST(float_g_infinity_neg_alt_format){
        RUN_TEST("%#g", -INFINITY)} END_TEST
    START_TEST(double_g_nan_alt_format){RUN_TEST("%#lg", NAN)} END_TEST
    START_TEST(double_g_nan_neg_alt_format){RUN_TEST("%#lg", -NAN)} END_TEST
    START_TEST(double_g_infinity_alt_format){
        RUN_TEST("%#lg", INFINITY)} END_TEST
    START_TEST(double_g_infinity_neg_alt_format){
        RUN_TEST("%#lg", -INFINITY)} END_TEST
    START_TEST(long_double_g_nan_alt_format){RUN_TEST("%#Lg", NAN)} END_TEST
    START_TEST(long_double_g_nan_neg_alt_format){
        RUN_TEST("%#Lg", -NAN)} END_TEST
    START_TEST(long_double_g_infinity_alt_format){
        RUN_TEST("%#Lg", INFINITY)} END_TEST
    START_TEST(long_double_g_infinity_neg_alt_format){
        RUN_TEST("%#Lg", -INFINITY)} END_TEST
    START_TEST(float_G_nan_alt_format){RUN_TEST("%#G", NAN)} END_TEST
    START_TEST(float_G_nan_neg_alt_format){RUN_TEST("%#G", -NAN)} END_TEST
    START_TEST(float_G_infinity_alt_format){RUN_TEST("%#G", INFINITY)} END_TEST
    START_TEST(float_G_infinity_neg_alt_format){
        RUN_TEST("%#G", -INFINITY)} END_TEST
    START_TEST(double_G_nan_alt_format){RUN_TEST("%#lG", NAN)} END_TEST
    START_TEST(double_G_nan_neg_alt_format){RUN_TEST("%#lG", -NAN)} END_TEST
    START_TEST(double_G_infinity_alt_format){
        RUN_TEST("%#lG", INFINITY)} END_TEST
    START_TEST(double_G_infinity_neg_alt_format){
        RUN_TEST("%#lG", -INFINITY)} END_TEST
    START_TEST(long_double_G_nan_alt_format){RUN_TEST("%#LG", NAN)} END_TEST
    START_TEST(long_double_G_nan_neg_alt_format){
        RUN_TEST("%#LG", -NAN)} END_TEST
    START_TEST(long_double_G_infinity_alt_format){
        RUN_TEST("%#LG", INFINITY)} END_TEST
    START_TEST(long_double_G_infinity_neg_alt_format){
        RUN_TEST("%#LG", -INFINITY)} END_TEST
    START_TEST(float_nan_no_width_no_precision){RUN_TEST("%f", NAN)} END_TEST
    START_TEST(float_nan_neg_no_width_no_precision){
        RUN_TEST("%f", -NAN)} END_TEST
    START_TEST(float_infinity_no_width_no_precision){
        RUN_TEST("%f", INFINITY)} END_TEST
    START_TEST(float_infinity_neg_no_width_no_precision){
        RUN_TEST("%f", -INFINITY)} END_TEST
    START_TEST(double_nan_no_width_no_precision){RUN_TEST("%lf", NAN)} END_TEST
    START_TEST(double_nan_neg_no_width_no_precision){
        RUN_TEST("%lf", -NAN)} END_TEST
    START_TEST(double_infinity_no_width_no_precision){
        RUN_TEST("%lf", INFINITY)} END_TEST
    START_TEST(double_infinity_neg_no_width_no_precision){
        RUN_TEST("%lf", -INFINITY)} END_TEST
    START_TEST(long_double_nan_no_width_no_precision){
        RUN_TEST("%Lf", NAN)} END_TEST
    START_TEST(long_double_nan_neg_no_width_no_precision){
        RUN_TEST("%Lf", -NAN)} END_TEST
    START_TEST(long_double_infinity_no_width_no_precision){
        RUN_TEST("%Lf", INFINITY)} END_TEST
    START_TEST(long_double_infinity_neg_no_width_no_precision){
        RUN_TEST("%Lf", -INFINITY)} END_TEST
    START_TEST(float_exp_nan_no_width_no_precision){
        RUN_TEST("%e", NAN)} END_TEST
    START_TEST(float_exp_nan_neg_no_width_no_precision){
        RUN_TEST("%e", -NAN)} END_TEST
    START_TEST(float_exp_infinity_no_width_no_precision){
        RUN_TEST("%e", INFINITY)} END_TEST
    START_TEST(float_exp_infinity_neg_no_width_no_precision){
        RUN_TEST("%e", -INFINITY)} END_TEST
    START_TEST(double_exp_nan_no_width_no_precision){
        RUN_TEST("%le", NAN)} END_TEST
    START_TEST(double_exp_nan_neg_no_width_no_precision){
        RUN_TEST("%le", -NAN)} END_TEST
    START_TEST(double_exp_infinity_no_width_no_precision){
        RUN_TEST("%le", INFINITY)} END_TEST
    START_TEST(double_exp_infinity_neg_no_width_no_precision){
        RUN_TEST("%le", -INFINITY)} END_TEST
    START_TEST(long_double_exp_nan_no_width_no_precision){
        RUN_TEST("%Le", NAN)} END_TEST
    START_TEST(long_double_exp_nan_neg_no_width_no_precision){
        RUN_TEST("%Le", -NAN)} END_TEST
    START_TEST(long_double_exp_infinity_no_width_no_precision){
        RUN_TEST("%Le", INFINITY)} END_TEST
    START_TEST(long_double_exp_infinity_neg_no_width_no_precision){
        RUN_TEST("%Le", -INFINITY)} END_TEST
    START_TEST(float_EXP_nan_no_width_no_precision){
        RUN_TEST("%E", NAN)} END_TEST
    START_TEST(float_EXP_nan_neg_no_width_no_precision){
        RUN_TEST("%E", -NAN)} END_TEST
    START_TEST(float_EXP_infinity_no_width_no_precision){
        RUN_TEST("%E", INFINITY)} END_TEST
    START_TEST(float_EXP_infinity_neg_no_width_no_precision){
        RUN_TEST("%E", -INFINITY)} END_TEST
    START_TEST(double_EXP_nan_no_width_no_precision){
        RUN_TEST("%lE", NAN)} END_TEST
    START_TEST(double_EXP_nan_neg_no_width_no_precision){
        RUN_TEST("%lE", -NAN)} END_TEST
    START_TEST(double_EXP_infinity_no_width_no_precision){
        RUN_TEST("%lE", INFINITY)} END_TEST
    START_TEST(double_EXP_infinity_neg_no_width_no_precision){
        RUN_TEST("%lE", -INFINITY)} END_TEST
    START_TEST(long_double_EXP_nan_no_width_no_precision){
        RUN_TEST("%LE", NAN)} END_TEST
    START_TEST(long_double_EXP_nan_neg_no_width_no_precision){
        RUN_TEST("%LE", -NAN)} END_TEST
    START_TEST(long_double_EXP_infinity_no_width_no_precision){
        RUN_TEST("%LE", INFINITY)} END_TEST
    START_TEST(long_double_EXP_infinity_neg_no_width_no_precision){
        RUN_TEST("%LE", -INFINITY)} END_TEST
    START_TEST(float_g_nan_no_width_no_precision){RUN_TEST("%g", NAN)} END_TEST
    START_TEST(float_g_nan_neg_no_width_no_precision){
        RUN_TEST("%g", -NAN)} END_TEST
    START_TEST(float_g_infinity_no_width_no_precision){
        RUN_TEST("%g", INFINITY)} END_TEST
    START_TEST(float_g_infinity_neg_no_width_no_precision){
        RUN_TEST("%g", -INFINITY)} END_TEST
    START_TEST(double_g_nan_no_width_no_precision){
        RUN_TEST("%lg", NAN)} END_TEST
    START_TEST(double_g_nan_neg_no_width_no_precision){
        RUN_TEST("%lg", -NAN)} END_TEST
    START_TEST(double_g_infinity_no_width_no_precision){
        RUN_TEST("%lg", INFINITY)} END_TEST
    START_TEST(double_g_infinity_neg_no_width_no_precision){
        RUN_TEST("%lg", -INFINITY)} END_TEST
    START_TEST(long_double_g_nan_no_width_no_precision){
        RUN_TEST("%Lg", NAN)} END_TEST
    START_TEST(long_double_g_nan_neg_no_width_no_precision){
        RUN_TEST("%Lg", -NAN)} END_TEST
    START_TEST(long_double_g_infinity_no_width_no_precision){
        RUN_TEST("%Lg", INFINITY)} END_TEST
    START_TEST(long_double_g_infinity_neg_no_width_no_precision){
        RUN_TEST("%Lg", -INFINITY)} END_TEST
    START_TEST(float_G_nan_no_width_no_precision){RUN_TEST("%G", NAN)} END_TEST
    START_TEST(float_G_nan_neg_no_width_no_precision){
        RUN_TEST("%G", -NAN)} END_TEST
    START_TEST(float_G_infinity_no_width_no_precision){
        RUN_TEST("%G", INFINITY)} END_TEST
    START_TEST(float_G_infinity_neg_no_width_no_precision){
        RUN_TEST("%G", -INFINITY)} END_TEST
    START_TEST(double_G_nan_no_width_no_precision){
        RUN_TEST("%lG", NAN)} END_TEST
    START_TEST(double_G_nan_neg_no_width_no_precision){
        RUN_TEST("%lG", -NAN)} END_TEST
    START_TEST(double_G_infinity_no_width_no_precision){
        RUN_TEST("%lG", INFINITY)} END_TEST
    START_TEST(double_G_infinity_neg_no_width_no_precision){
        RUN_TEST("%lG", -INFINITY)} END_TEST
    START_TEST(long_double_G_nan_no_width_no_precision){
        RUN_TEST("%LG", NAN)} END_TEST
    START_TEST(long_double_G_nan_neg_no_width_no_precision){
        RUN_TEST("%LG", -NAN)} END_TEST
    START_TEST(long_double_G_infinity_no_width_no_precision){
        RUN_TEST("%LG", INFINITY)} END_TEST
    START_TEST(long_double_G_infinity_neg_no_width_no_precision){
        RUN_TEST("%LG", -INFINITY)} END_TEST
    START_TEST(float_nan_no_width_small_precision){
        RUN_TEST("%.3f", NAN)} END_TEST
    START_TEST(float_nan_neg_no_width_small_precision){
        RUN_TEST("%.3f", -NAN)} END_TEST
    START_TEST(float_infinity_no_width_small_precision){
        RUN_TEST("%.3f", INFINITY)} END_TEST
    START_TEST(float_infinity_neg_no_width_small_precision){
        RUN_TEST("%.3f", -INFINITY)} END_TEST
    START_TEST(double_nan_no_width_small_precision){
        RUN_TEST("%.3lf", NAN)} END_TEST
    START_TEST(double_nan_neg_no_width_small_precision){
        RUN_TEST("%.3lf", -NAN)} END_TEST
    START_TEST(double_infinity_no_width_small_precision){
        RUN_TEST("%.3lf", INFINITY)} END_TEST
    START_TEST(double_infinity_neg_no_width_small_precision){
        RUN_TEST("%.3lf", -INFINITY)} END_TEST
    START_TEST(long_double_nan_no_width_small_precision){
        RUN_TEST("%.3Lf", NAN)} END_TEST
    START_TEST(long_double_nan_neg_no_width_small_precision){
        RUN_TEST("%.3Lf", -NAN)} END_TEST
    START_TEST(long_double_infinity_no_width_small_precision){
        RUN_TEST("%.3Lf", INFINITY)} END_TEST
    START_TEST(long_double_infinity_neg_no_width_small_precision){
        RUN_TEST("%.3Lf", -INFINITY)} END_TEST
    START_TEST(float_exp_nan_no_width_small_precision){
        RUN_TEST("%.3e", NAN)} END_TEST
    START_TEST(float_exp_nan_neg_no_width_small_precision){
        RUN_TEST("%.3e", -NAN)} END_TEST
    START_TEST(float_exp_infinity_no_width_small_precision){
        RUN_TEST("%.3e", INFINITY)} END_TEST
    START_TEST(float_exp_infinity_neg_no_width_small_precision){
        RUN_TEST("%.3e", -INFINITY)} END_TEST
    START_TEST(double_exp_nan_no_width_small_precision){
        RUN_TEST("%.3le", NAN)} END_TEST
    START_TEST(double_exp_nan_neg_no_width_small_precision){
        RUN_TEST("%.3le", -NAN)} END_TEST
    START_TEST(double_exp_infinity_no_width_small_precision){
        RUN_TEST("%.3le", INFINITY)} END_TEST
    START_TEST(double_exp_infinity_neg_no_width_small_precision){
        RUN_TEST("%.3le", -INFINITY)} END_TEST
    START_TEST(long_double_exp_nan_no_width_small_precision){
        RUN_TEST("%.3Le", NAN)} END_TEST
    START_TEST(long_double_exp_nan_neg_no_width_small_precision){
        RUN_TEST("%.3Le", -NAN)} END_TEST
    START_TEST(long_double_exp_infinity_no_width_small_precision){
        RUN_TEST("%.3Le", INFINITY)} END_TEST
    START_TEST(long_double_exp_infinity_neg_no_width_small_precision){
        RUN_TEST("%.3Le", -INFINITY)} END_TEST
    START_TEST(float_EXP_nan_no_width_small_precision){
        RUN_TEST("%.3E", NAN)} END_TEST
    START_TEST(float_EXP_nan_neg_no_width_small_precision){
        RUN_TEST("%.3E", -NAN)} END_TEST
    START_TEST(float_EXP_infinity_no_width_small_precision){
        RUN_TEST("%.3E", INFINITY)} END_TEST
    START_TEST(float_EXP_infinity_neg_no_width_small_precision){
        RUN_TEST("%.3E", -INFINITY)} END_TEST
    START_TEST(double_EXP_nan_no_width_small_precision){
        RUN_TEST("%.3lE", NAN)} END_TEST
    START_TEST(double_EXP_nan_neg_no_width_small_precision){
        RUN_TEST("%.3lE", -NAN)} END_TEST
    START_TEST(double_EXP_infinity_no_width_small_precision){
        RUN_TEST("%.3lE", INFINITY)} END_TEST
    START_TEST(double_EXP_infinity_neg_no_width_small_precision){
        RUN_TEST("%.3lE", -INFINITY)} END_TEST
    START_TEST(long_double_EXP_nan_no_width_small_precision){
        RUN_TEST("%.3LE", NAN)} END_TEST
    START_TEST(long_double_EXP_nan_neg_no_width_small_precision){
        RUN_TEST("%.3LE", -NAN)} END_TEST
    START_TEST(long_double_EXP_infinity_no_width_small_precision){
        RUN_TEST("%.3LE", INFINITY)} END_TEST
    START_TEST(long_double_EXP_infinity_neg_no_width_small_precision){
        RUN_TEST("%.3LE", -INFINITY)} END_TEST
    START_TEST(float_g_nan_no_width_small_precision){
        RUN_TEST("%.3g", NAN)} END_TEST
    START_TEST(float_g_nan_neg_no_width_small_precision){
        RUN_TEST("%.3g", -NAN)} END_TEST
    START_TEST(float_g_infinity_no_width_small_precision){
        RUN_TEST("%.3g", INFINITY)} END_TEST
    START_TEST(float_g_infinity_neg_no_width_small_precision){
        RUN_TEST("%.3g", -INFINITY)} END_TEST
    START_TEST(double_g_nan_no_width_small_precision){
        RUN_TEST("%.3lg", NAN)} END_TEST
    START_TEST(double_g_nan_neg_no_width_small_precision){
        RUN_TEST("%.3lg", -NAN)} END_TEST
    START_TEST(double_g_infinity_no_width_small_precision){
        RUN_TEST("%.3lg", INFINITY)} END_TEST
    START_TEST(double_g_infinity_neg_no_width_small_precision){
        RUN_TEST("%.3lg", -INFINITY)} END_TEST
    START_TEST(long_double_g_nan_no_width_small_precision){
        RUN_TEST("%.3Lg", NAN)} END_TEST
    START_TEST(long_double_g_nan_neg_no_width_small_precision){
        RUN_TEST("%.3Lg", -NAN)} END_TEST
    START_TEST(long_double_g_infinity_no_width_small_precision){
        RUN_TEST("%.3Lg", INFINITY)} END_TEST
    START_TEST(long_double_g_infinity_neg_no_width_small_precision){
        RUN_TEST("%.3Lg", -INFINITY)} END_TEST
    START_TEST(float_G_nan_no_width_small_precision){
        RUN_TEST("%.3G", NAN)} END_TEST
    START_TEST(float_G_nan_neg_no_width_small_precision){
        RUN_TEST("%.3G", -NAN)} END_TEST
    START_TEST(float_G_infinity_no_width_small_precision){
        RUN_TEST("%.3G", INFINITY)} END_TEST
    START_TEST(float_G_infinity_neg_no_width_small_precision){
        RUN_TEST("%.3G", -INFINITY)} END_TEST
    START_TEST(double_G_nan_no_width_small_precision){
        RUN_TEST("%.3lG", NAN)} END_TEST
    START_TEST(double_G_nan_neg_no_width_small_precision){
        RUN_TEST("%.3lG", -NAN)} END_TEST
    START_TEST(double_G_infinity_no_width_small_precision){
        RUN_TEST("%.3lG", INFINITY)} END_TEST
    START_TEST(double_G_infinity_neg_no_width_small_precision){
        RUN_TEST("%.3lG", -INFINITY)} END_TEST
    START_TEST(long_double_G_nan_no_width_small_precision){
        RUN_TEST("%.3LG", NAN)} END_TEST
    START_TEST(long_double_G_nan_neg_no_width_small_precision){
        RUN_TEST("%.3LG", -NAN)} END_TEST
    START_TEST(long_double_G_infinity_no_width_small_precision){
        RUN_TEST("%.3LG", INFINITY)} END_TEST
    START_TEST(long_double_G_infinity_neg_no_width_small_precision){
        RUN_TEST("%.3LG", -INFINITY)} END_TEST
    START_TEST(float_nan_no_width_big_precision){
        RUN_TEST("%.14f", NAN)} END_TEST
    START_TEST(float_nan_neg_no_width_big_precision){
        RUN_TEST("%.14f", -NAN)} END_TEST
    START_TEST(float_infinity_no_width_big_precision){
        RUN_TEST("%.14f", INFINITY)} END_TEST
    START_TEST(float_infinity_neg_no_width_big_precision){
        RUN_TEST("%.14f", -INFINITY)} END_TEST
    START_TEST(double_nan_no_width_big_precision){
        RUN_TEST("%.14lf", NAN)} END_TEST
    START_TEST(double_nan_neg_no_width_big_precision){
        RUN_TEST("%.14lf", -NAN)} END_TEST
    START_TEST(double_infinity_no_width_big_precision){
        RUN_TEST("%.14lf", INFINITY)} END_TEST
    START_TEST(double_infinity_neg_no_width_big_precision){
        RUN_TEST("%.14lf", -INFINITY)} END_TEST
    START_TEST(long_double_nan_no_width_big_precision){
        RUN_TEST("%.14Lf", NAN)} END_TEST
    START_TEST(long_double_nan_neg_no_width_big_precision){
        RUN_TEST("%.14Lf", -NAN)} END_TEST
    START_TEST(long_double_infinity_no_width_big_precision){
        RUN_TEST("%.14Lf", INFINITY)} END_TEST
    START_TEST(long_double_infinity_neg_no_width_big_precision){
        RUN_TEST("%.14Lf", -INFINITY)} END_TEST
    START_TEST(float_exp_nan_no_width_big_precision){
        RUN_TEST("%.14e", NAN)} END_TEST
    START_TEST(float_exp_nan_neg_no_width_big_precision){
        RUN_TEST("%.14e", -NAN)} END_TEST
    START_TEST(float_exp_infinity_no_width_big_precision){
        RUN_TEST("%.14e", INFINITY)} END_TEST
    START_TEST(float_exp_infinity_neg_no_width_big_precision){
        RUN_TEST("%.14e", -INFINITY)} END_TEST
    START_TEST(double_exp_nan_no_width_big_precision){
        RUN_TEST("%.14le", NAN)} END_TEST
    START_TEST(double_exp_nan_neg_no_width_big_precision){
        RUN_TEST("%.14le", -NAN)} END_TEST
    START_TEST(double_exp_infinity_no_width_big_precision){
        RUN_TEST("%.14le", INFINITY)} END_TEST
    START_TEST(double_exp_infinity_neg_no_width_big_precision){
        RUN_TEST("%.14le", -INFINITY)} END_TEST
    START_TEST(long_double_exp_nan_no_width_big_precision){
        RUN_TEST("%.14Le", NAN)} END_TEST
    START_TEST(long_double_exp_nan_neg_no_width_big_precision){
        RUN_TEST("%.14Le", -NAN)} END_TEST
    START_TEST(long_double_exp_infinity_no_width_big_precision){
        RUN_TEST("%.14Le", INFINITY)} END_TEST
    START_TEST(long_double_exp_infinity_neg_no_width_big_precision){
        RUN_TEST("%.14Le", -INFINITY)} END_TEST
    START_TEST(float_EXP_nan_no_width_big_precision){
        RUN_TEST("%.14E", NAN)} END_TEST
    START_TEST(float_EXP_nan_neg_no_width_big_precision){
        RUN_TEST("%.14E", -NAN)} END_TEST
    START_TEST(float_EXP_infinity_no_width_big_precision){
        RUN_TEST("%.14E", INFINITY)} END_TEST
    START_TEST(float_EXP_infinity_neg_no_width_big_precision){
        RUN_TEST("%.14E", -INFINITY)} END_TEST
    START_TEST(double_EXP_nan_no_width_big_precision){
        RUN_TEST("%.14lE", NAN)} END_TEST
    START_TEST(double_EXP_nan_neg_no_width_big_precision){
        RUN_TEST("%.14lE", -NAN)} END_TEST
    START_TEST(double_EXP_infinity_no_width_big_precision){
        RUN_TEST("%.14lE", INFINITY)} END_TEST
    START_TEST(double_EXP_infinity_neg_no_width_big_precision){
        RUN_TEST("%.14lE", -INFINITY)} END_TEST
    START_TEST(long_double_EXP_nan_no_width_big_precision){
        RUN_TEST("%.14LE", NAN)} END_TEST
    START_TEST(long_double_EXP_nan_neg_no_width_big_precision){
        RUN_TEST("%.14LE", -NAN)} END_TEST
    START_TEST(long_double_EXP_infinity_no_width_big_precision){
        RUN_TEST("%.14LE", INFINITY)} END_TEST
    START_TEST(long_double_EXP_infinity_neg_no_width_big_precision){
        RUN_TEST("%.14LE", -INFINITY)} END_TEST
    START_TEST(float_g_nan_no_width_big_precision){
        RUN_TEST("%.14g", NAN)} END_TEST
    START_TEST(float_g_nan_neg_no_width_big_precision){
        RUN_TEST("%.14g", -NAN)} END_TEST
    START_TEST(float_g_infinity_no_width_big_precision){
        RUN_TEST("%.14g", INFINITY)} END_TEST
    START_TEST(float_g_infinity_neg_no_width_big_precision){
        RUN_TEST("%.14g", -INFINITY)} END_TEST
    START_TEST(double_g_nan_no_width_big_precision){
        RUN_TEST("%.14lg", NAN)} END_TEST
    START_TEST(double_g_nan_neg_no_width_big_precision){
        RUN_TEST("%.14lg", -NAN)} END_TEST
    START_TEST(double_g_infinity_no_width_big_precision){
        RUN_TEST("%.14lg", INFINITY)} END_TEST
    START_TEST(double_g_infinity_neg_no_width_big_precision){
        RUN_TEST("%.14lg", -INFINITY)} END_TEST
    START_TEST(long_double_g_nan_no_width_big_precision){
        RUN_TEST("%.14Lg", NAN)} END_TEST
    START_TEST(long_double_g_nan_neg_no_width_big_precision){
        RUN_TEST("%.14Lg", -NAN)} END_TEST
    START_TEST(long_double_g_infinity_no_width_big_precision){
        RUN_TEST("%.14Lg", INFINITY)} END_TEST
    START_TEST(long_double_g_infinity_neg_no_width_big_precision){
        RUN_TEST("%.14Lg", -INFINITY)} END_TEST
    START_TEST(float_G_nan_no_width_big_precision){
        RUN_TEST("%.14G", NAN)} END_TEST
    START_TEST(float_G_nan_neg_no_width_big_precision){
        RUN_TEST("%.14G", -NAN)} END_TEST
    START_TEST(float_G_infinity_no_width_big_precision){
        RUN_TEST("%.14G", INFINITY)} END_TEST
    START_TEST(float_G_infinity_neg_no_width_big_precision){
        RUN_TEST("%.14G", -INFINITY)} END_TEST
    START_TEST(double_G_nan_no_width_big_precision){
        RUN_TEST("%.14lG", NAN)} END_TEST
    START_TEST(double_G_nan_neg_no_width_big_precision){
        RUN_TEST("%.14lG", -NAN)} END_TEST
    START_TEST(double_G_infinity_no_width_big_precision){
        RUN_TEST("%.14lG", INFINITY)} END_TEST
    START_TEST(double_G_infinity_neg_no_width_big_precision){
        RUN_TEST("%.14lG", -INFINITY)} END_TEST
    START_TEST(long_double_G_nan_no_width_big_precision){
        RUN_TEST("%.14LG", NAN)} END_TEST
    START_TEST(long_double_G_nan_neg_no_width_big_precision){
        RUN_TEST("%.14LG", -NAN)} END_TEST
    START_TEST(long_double_G_infinity_no_width_big_precision){
        RUN_TEST("%.14LG", INFINITY)} END_TEST
    START_TEST(long_double_G_infinity_neg_no_width_big_precision){
        RUN_TEST("%.14LG", -INFINITY)} END_TEST
    START_TEST(float_nan_small_width_no_precision){
        RUN_TEST("%1f", NAN)} END_TEST
    START_TEST(float_nan_neg_small_width_no_precision){
        RUN_TEST("%1f", -NAN)} END_TEST
    START_TEST(float_infinity_small_width_no_precision){
        RUN_TEST("%1f", INFINITY)} END_TEST
    START_TEST(float_infinity_neg_small_width_no_precision){
        RUN_TEST("%1f", -INFINITY)} END_TEST
    START_TEST(double_nan_small_width_no_precision){
        RUN_TEST("%1lf", NAN)} END_TEST
    START_TEST(double_nan_neg_small_width_no_precision){
        RUN_TEST("%1lf", -NAN)} END_TEST
    START_TEST(double_infinity_small_width_no_precision){
        RUN_TEST("%1lf", INFINITY)} END_TEST
    START_TEST(double_infinity_neg_small_width_no_precision){
        RUN_TEST("%1lf", -INFINITY)} END_TEST
    START_TEST(long_double_nan_small_width_no_precision){
        RUN_TEST("%1Lf", NAN)} END_TEST
    START_TEST(long_double_nan_neg_small_width_no_precision){
        RUN_TEST("%1Lf", -NAN)} END_TEST
    START_TEST(long_double_infinity_small_width_no_precision){
        RUN_TEST("%1Lf", INFINITY)} END_TEST
    START_TEST(long_double_infinity_neg_small_width_no_precision){
        RUN_TEST("%1Lf", -INFINITY)} END_TEST
    START_TEST(float_exp_nan_small_width_no_precision){
        RUN_TEST("%1e", NAN)} END_TEST
    START_TEST(float_exp_nan_neg_small_width_no_precision){
        RUN_TEST("%1e", -NAN)} END_TEST
    START_TEST(float_exp_infinity_small_width_no_precision){
        RUN_TEST("%1e", INFINITY)} END_TEST
    START_TEST(float_exp_infinity_neg_small_width_no_precision){
        RUN_TEST("%1e", -INFINITY)} END_TEST
    START_TEST(double_exp_nan_small_width_no_precision){
        RUN_TEST("%1le", NAN)} END_TEST
    START_TEST(double_exp_nan_neg_small_width_no_precision){
        RUN_TEST("%1le", -NAN)} END_TEST
    START_TEST(double_exp_infinity_small_width_no_precision){
        RUN_TEST("%1le", INFINITY)} END_TEST
    START_TEST(double_exp_infinity_neg_small_width_no_precision){
        RUN_TEST("%1le", -INFINITY)} END_TEST
    START_TEST(long_double_exp_nan_small_width_no_precision){
        RUN_TEST("%1Le", NAN)} END_TEST
    START_TEST(long_double_exp_nan_neg_small_width_no_precision){
        RUN_TEST("%1Le", -NAN)} END_TEST
    START_TEST(long_double_exp_infinity_small_width_no_precision){
        RUN_TEST("%1Le", INFINITY)} END_TEST
    START_TEST(long_double_exp_infinity_neg_small_width_no_precision){
        RUN_TEST("%1Le", -INFINITY)} END_TEST
    START_TEST(float_EXP_nan_small_width_no_precision){
        RUN_TEST("%1E", NAN)} END_TEST
    START_TEST(float_EXP_nan_neg_small_width_no_precision){
        RUN_TEST("%1E", -NAN)} END_TEST
    START_TEST(float_EXP_infinity_small_width_no_precision){
        RUN_TEST("%1E", INFINITY)} END_TEST
    START_TEST(float_EXP_infinity_neg_small_width_no_precision){
        RUN_TEST("%1E", -INFINITY)} END_TEST
    START_TEST(double_EXP_nan_small_width_no_precision){
        RUN_TEST("%1lE", NAN)} END_TEST
    START_TEST(double_EXP_nan_neg_small_width_no_precision){
        RUN_TEST("%1lE", -NAN)} END_TEST
    START_TEST(double_EXP_infinity_small_width_no_precision){
        RUN_TEST("%1lE", INFINITY)} END_TEST
    START_TEST(double_EXP_infinity_neg_small_width_no_precision){
        RUN_TEST("%1lE", -INFINITY)} END_TEST
    START_TEST(long_double_EXP_nan_small_width_no_precision){
        RUN_TEST("%1LE", NAN)} END_TEST
    START_TEST(long_double_EXP_nan_neg_small_width_no_precision){
        RUN_TEST("%1LE", -NAN)} END_TEST
    START_TEST(long_double_EXP_infinity_small_width_no_precision){
        RUN_TEST("%1LE", INFINITY)} END_TEST
    START_TEST(long_double_EXP_infinity_neg_small_width_no_precision){
        RUN_TEST("%1LE", -INFINITY)} END_TEST
    START_TEST(float_g_nan_small_width_no_precision){
        RUN_TEST("%1g", NAN)} END_TEST
    START_TEST(float_g_nan_neg_small_width_no_precision){
        RUN_TEST("%1g", -NAN)} END_TEST
    START_TEST(float_g_infinity_small_width_no_precision){
        RUN_TEST("%1g", INFINITY)} END_TEST
    START_TEST(float_g_infinity_neg_small_width_no_precision){
        RUN_TEST("%1g", -INFINITY)} END_TEST
    START_TEST(double_g_nan_small_width_no_precision){
        RUN_TEST("%1lg", NAN)} END_TEST
    START_TEST(double_g_nan_neg_small_width_no_precision){
        RUN_TEST("%1lg", -NAN)} END_TEST
    START_TEST(double_g_infinity_small_width_no_precision){
        RUN_TEST("%1lg", INFINITY)} END_TEST
    START_TEST(double_g_infinity_neg_small_width_no_precision){
        RUN_TEST("%1lg", -INFINITY)} END_TEST
    START_TEST(long_double_g_nan_small_width_no_precision){
        RUN_TEST("%1Lg", NAN)} END_TEST
    START_TEST(long_double_g_nan_neg_small_width_no_precision){
        RUN_TEST("%1Lg", -NAN)} END_TEST
    START_TEST(long_double_g_infinity_small_width_no_precision){
        RUN_TEST("%1Lg", INFINITY)} END_TEST
    START_TEST(long_double_g_infinity_neg_small_width_no_precision){
        RUN_TEST("%1Lg", -INFINITY)} END_TEST
    START_TEST(float_G_nan_small_width_no_precision){
        RUN_TEST("%1G", NAN)} END_TEST
    START_TEST(float_G_nan_neg_small_width_no_precision){
        RUN_TEST("%1G", -NAN)} END_TEST
    START_TEST(float_G_infinity_small_width_no_precision){
        RUN_TEST("%1G", INFINITY)} END_TEST
    START_TEST(float_G_infinity_neg_small_width_no_precision){
        RUN_TEST("%1G", -INFINITY)} END_TEST
    START_TEST(double_G_nan_small_width_no_precision){
        RUN_TEST("%1lG", NAN)} END_TEST
    START_TEST(double_G_nan_neg_small_width_no_precision){
        RUN_TEST("%1lG", -NAN)} END_TEST
    START_TEST(double_G_infinity_small_width_no_precision){
        RUN_TEST("%1lG", INFINITY)} END_TEST
    START_TEST(double_G_infinity_neg_small_width_no_precision){
        RUN_TEST("%1lG", -INFINITY)} END_TEST
    START_TEST(long_double_G_nan_small_width_no_precision){
        RUN_TEST("%1LG", NAN)} END_TEST
    START_TEST(long_double_G_nan_neg_small_width_no_precision){
        RUN_TEST("%1LG", -NAN)} END_TEST
    START_TEST(long_double_G_infinity_small_width_no_precision){
        RUN_TEST("%1LG", INFINITY)} END_TEST
    START_TEST(long_double_G_infinity_neg_small_width_no_precision){
        RUN_TEST("%1LG", -INFINITY)} END_TEST
    START_TEST(float_nan_small_width_small_precision){
        RUN_TEST("%1.3f", NAN)} END_TEST
    START_TEST(float_nan_neg_small_width_small_precision){
        RUN_TEST("%1.3f", -NAN)} END_TEST
    START_TEST(float_infinity_small_width_small_precision){
        RUN_TEST("%1.3f", INFINITY)} END_TEST
    START_TEST(float_infinity_neg_small_width_small_precision){
        RUN_TEST("%1.3f", -INFINITY)} END_TEST
    START_TEST(double_nan_small_width_small_precision){
        RUN_TEST("%1.3lf", NAN)} END_TEST
    START_TEST(double_nan_neg_small_width_small_precision){
        RUN_TEST("%1.3lf", -NAN)} END_TEST
    START_TEST(double_infinity_small_width_small_precision){
        RUN_TEST("%1.3lf", INFINITY)} END_TEST
    START_TEST(double_infinity_neg_small_width_small_precision){
        RUN_TEST("%1.3lf", -INFINITY)} END_TEST
    START_TEST(long_double_nan_small_width_small_precision){
        RUN_TEST("%1.3Lf", NAN)} END_TEST
    START_TEST(long_double_nan_neg_small_width_small_precision){
        RUN_TEST("%1.3Lf", -NAN)} END_TEST
    START_TEST(long_double_infinity_small_width_small_precision){
        RUN_TEST("%1.3Lf", INFINITY)} END_TEST
    START_TEST(long_double_infinity_neg_small_width_small_precision){
        RUN_TEST("%1.3Lf", -INFINITY)} END_TEST
    START_TEST(float_exp_nan_small_width_small_precision){
        RUN_TEST("%1.3e", NAN)} END_TEST
    START_TEST(float_exp_nan_neg_small_width_small_precision){
        RUN_TEST("%1.3e", -NAN)} END_TEST
    START_TEST(float_exp_infinity_small_width_small_precision){
        RUN_TEST("%1.3e", INFINITY)} END_TEST
    START_TEST(float_exp_infinity_neg_small_width_small_precision){
        RUN_TEST("%1.3e", -INFINITY)} END_TEST
    START_TEST(double_exp_nan_small_width_small_precision){
        RUN_TEST("%1.3le", NAN)} END_TEST
    START_TEST(double_exp_nan_neg_small_width_small_precision){
        RUN_TEST("%1.3le", -NAN)} END_TEST
    START_TEST(double_exp_infinity_small_width_small_precision){
        RUN_TEST("%1.3le", INFINITY)} END_TEST
    START_TEST(double_exp_infinity_neg_small_width_small_precision){
        RUN_TEST("%1.3le", -INFINITY)} END_TEST
    START_TEST(long_double_exp_nan_small_width_small_precision){
        RUN_TEST("%1.3Le", NAN)} END_TEST
    START_TEST(long_double_exp_nan_neg_small_width_small_precision){
        RUN_TEST("%1.3Le", -NAN)} END_TEST
    START_TEST(long_double_exp_infinity_small_width_small_precision){
        RUN_TEST("%1.3Le", INFINITY)} END_TEST
    START_TEST(long_double_exp_infinity_neg_small_width_small_precision){
        RUN_TEST("%1.3Le", -INFINITY)} END_TEST
    START_TEST(float_EXP_nan_small_width_small_precision){
        RUN_TEST("%1.3E", NAN)} END_TEST
    START_TEST(float_EXP_nan_neg_small_width_small_precision){
        RUN_TEST("%1.3E", -NAN)} END_TEST
    START_TEST(float_EXP_infinity_small_width_small_precision){
        RUN_TEST("%1.3E", INFINITY)} END_TEST
    START_TEST(float_EXP_infinity_neg_small_width_small_precision){
        RUN_TEST("%1.3E", -INFINITY)} END_TEST
    START_TEST(double_EXP_nan_small_width_small_precision){
        RUN_TEST("%1.3lE", NAN)} END_TEST
    START_TEST(double_EXP_nan_neg_small_width_small_precision){
        RUN_TEST("%1.3lE", -NAN)} END_TEST
    START_TEST(double_EXP_infinity_small_width_small_precision){
        RUN_TEST("%1.3lE", INFINITY)} END_TEST
    START_TEST(double_EXP_infinity_neg_small_width_small_precision){
        RUN_TEST("%1.3lE", -INFINITY)} END_TEST
    START_TEST(long_double_EXP_nan_small_width_small_precision){
        RUN_TEST("%1.3LE", NAN)} END_TEST
    START_TEST(long_double_EXP_nan_neg_small_width_small_precision){
        RUN_TEST("%1.3LE", -NAN)} END_TEST
    START_TEST(long_double_EXP_infinity_small_width_small_precision){
        RUN_TEST("%1.3LE", INFINITY)} END_TEST
    START_TEST(long_double_EXP_infinity_neg_small_width_small_precision){
        RUN_TEST("%1.3LE", -INFINITY)} END_TEST
    START_TEST(float_g_nan_small_width_small_precision){
        RUN_TEST("%1.3g", NAN)} END_TEST
    START_TEST(float_g_nan_neg_small_width_small_precision){
        RUN_TEST("%1.3g", -NAN)} END_TEST
    START_TEST(float_g_infinity_small_width_small_precision){
        RUN_TEST("%1.3g", INFINITY)} END_TEST
    START_TEST(float_g_infinity_neg_small_width_small_precision){
        RUN_TEST("%1.3g", -INFINITY)} END_TEST
    START_TEST(double_g_nan_small_width_small_precision){
        RUN_TEST("%1.3lg", NAN)} END_TEST
    START_TEST(double_g_nan_neg_small_width_small_precision){
        RUN_TEST("%1.3lg", -NAN)} END_TEST
    START_TEST(double_g_infinity_small_width_small_precision){
        RUN_TEST("%1.3lg", INFINITY)} END_TEST
    START_TEST(double_g_infinity_neg_small_width_small_precision){
        RUN_TEST("%1.3lg", -INFINITY)} END_TEST
    START_TEST(long_double_g_nan_small_width_small_precision){
        RUN_TEST("%1.3Lg", NAN)} END_TEST
    START_TEST(long_double_g_nan_neg_small_width_small_precision){
        RUN_TEST("%1.3Lg", -NAN)} END_TEST
    START_TEST(long_double_g_infinity_small_width_small_precision){
        RUN_TEST("%1.3Lg", INFINITY)} END_TEST
    START_TEST(long_double_g_infinity_neg_small_width_small_precision){
        RUN_TEST("%1.3Lg", -INFINITY)} END_TEST
    START_TEST(float_G_nan_small_width_small_precision){
        RUN_TEST("%1.3G", NAN)} END_TEST
    START_TEST(float_G_nan_neg_small_width_small_precision){
        RUN_TEST("%1.3G", -NAN)} END_TEST
    START_TEST(float_G_infinity_small_width_small_precision){
        RUN_TEST("%1.3G", INFINITY)} END_TEST
    START_TEST(float_G_infinity_neg_small_width_small_precision){
        RUN_TEST("%1.3G", -INFINITY)} END_TEST
    START_TEST(double_G_nan_small_width_small_precision){
        RUN_TEST("%1.3lG", NAN)} END_TEST
    START_TEST(double_G_nan_neg_small_width_small_precision){
        RUN_TEST("%1.3lG", -NAN)} END_TEST
    START_TEST(double_G_infinity_small_width_small_precision){
        RUN_TEST("%1.3lG", INFINITY)} END_TEST
    START_TEST(double_G_infinity_neg_small_width_small_precision){
        RUN_TEST("%1.3lG", -INFINITY)} END_TEST
    START_TEST(long_double_G_nan_small_width_small_precision){
        RUN_TEST("%1.3LG", NAN)} END_TEST
    START_TEST(long_double_G_nan_neg_small_width_small_precision){
        RUN_TEST("%1.3LG", -NAN)} END_TEST
    START_TEST(long_double_G_infinity_small_width_small_precision){
        RUN_TEST("%1.3LG", INFINITY)} END_TEST
    START_TEST(long_double_G_infinity_neg_small_width_small_precision){
        RUN_TEST("%1.3LG", -INFINITY)} END_TEST
    START_TEST(float_nan_small_width_big_precision){
        RUN_TEST("%1.14f", NAN)} END_TEST
    START_TEST(float_nan_neg_small_width_big_precision){
        RUN_TEST("%1.14f", -NAN)} END_TEST
    START_TEST(float_infinity_small_width_big_precision){
        RUN_TEST("%1.14f", INFINITY)} END_TEST
    START_TEST(float_infinity_neg_small_width_big_precision){
        RUN_TEST("%1.14f", -INFINITY)} END_TEST
    START_TEST(double_nan_small_width_big_precision){
        RUN_TEST("%1.14lf", NAN)} END_TEST
    START_TEST(double_nan_neg_small_width_big_precision){
        RUN_TEST("%1.14lf", -NAN)} END_TEST
    START_TEST(double_infinity_small_width_big_precision){
        RUN_TEST("%1.14lf", INFINITY)} END_TEST
    START_TEST(double_infinity_neg_small_width_big_precision){
        RUN_TEST("%1.14lf", -INFINITY)} END_TEST
    START_TEST(long_double_nan_small_width_big_precision){
        RUN_TEST("%1.14Lf", NAN)} END_TEST
    START_TEST(long_double_nan_neg_small_width_big_precision){
        RUN_TEST("%1.14Lf", -NAN)} END_TEST
    START_TEST(long_double_infinity_small_width_big_precision){
        RUN_TEST("%1.14Lf", INFINITY)} END_TEST
    START_TEST(long_double_infinity_neg_small_width_big_precision){
        RUN_TEST("%1.14Lf", -INFINITY)} END_TEST
    START_TEST(float_exp_nan_small_width_big_precision){
        RUN_TEST("%1.14e", NAN)} END_TEST
    START_TEST(float_exp_nan_neg_small_width_big_precision){
        RUN_TEST("%1.14e", -NAN)} END_TEST
    START_TEST(float_exp_infinity_small_width_big_precision){
        RUN_TEST("%1.14e", INFINITY)} END_TEST
    START_TEST(float_exp_infinity_neg_small_width_big_precision){
        RUN_TEST("%1.14e", -INFINITY)} END_TEST
    START_TEST(double_exp_nan_small_width_big_precision){
        RUN_TEST("%1.14le", NAN)} END_TEST
    START_TEST(double_exp_nan_neg_small_width_big_precision){
        RUN_TEST("%1.14le", -NAN)} END_TEST
    START_TEST(double_exp_infinity_small_width_big_precision){
        RUN_TEST("%1.14le", INFINITY)} END_TEST
    START_TEST(double_exp_infinity_neg_small_width_big_precision){
        RUN_TEST("%1.14le", -INFINITY)} END_TEST
    START_TEST(long_double_exp_nan_small_width_big_precision){
        RUN_TEST("%1.14Le", NAN)} END_TEST
    START_TEST(long_double_exp_nan_neg_small_width_big_precision){
        RUN_TEST("%1.14Le", -NAN)} END_TEST
    START_TEST(long_double_exp_infinity_small_width_big_precision){
        RUN_TEST("%1.14Le", INFINITY)} END_TEST
    START_TEST(long_double_exp_infinity_neg_small_width_big_precision){
        RUN_TEST("%1.14Le", -INFINITY)} END_TEST
    START_TEST(float_EXP_nan_small_width_big_precision){
        RUN_TEST("%1.14E", NAN)} END_TEST
    START_TEST(float_EXP_nan_neg_small_width_big_precision){
        RUN_TEST("%1.14E", -NAN)} END_TEST
    START_TEST(float_EXP_infinity_small_width_big_precision){
        RUN_TEST("%1.14E", INFINITY)} END_TEST
    START_TEST(float_EXP_infinity_neg_small_width_big_precision){
        RUN_TEST("%1.14E", -INFINITY)} END_TEST
    START_TEST(double_EXP_nan_small_width_big_precision){
        RUN_TEST("%1.14lE", NAN)} END_TEST
    START_TEST(double_EXP_nan_neg_small_width_big_precision){
        RUN_TEST("%1.14lE", -NAN)} END_TEST
    START_TEST(double_EXP_infinity_small_width_big_precision){
        RUN_TEST("%1.14lE", INFINITY)} END_TEST
    START_TEST(double_EXP_infinity_neg_small_width_big_precision){
        RUN_TEST("%1.14lE", -INFINITY)} END_TEST
    START_TEST(long_double_EXP_nan_small_width_big_precision){
        RUN_TEST("%1.14LE", NAN)} END_TEST
    START_TEST(long_double_EXP_nan_neg_small_width_big_precision){
        RUN_TEST("%1.14LE", -NAN)} END_TEST
    START_TEST(long_double_EXP_infinity_small_width_big_precision){
        RUN_TEST("%1.14LE", INFINITY)} END_TEST
    START_TEST(long_double_EXP_infinity_neg_small_width_big_precision){
        RUN_TEST("%1.14LE", -INFINITY)} END_TEST
    START_TEST(float_g_nan_small_width_big_precision){
        RUN_TEST("%1.14g", NAN)} END_TEST
    START_TEST(float_g_nan_neg_small_width_big_precision){
        RUN_TEST("%1.14g", -NAN)} END_TEST
    START_TEST(float_g_infinity_small_width_big_precision){
        RUN_TEST("%1.14g", INFINITY)} END_TEST
    START_TEST(float_g_infinity_neg_small_width_big_precision){
        RUN_TEST("%1.14g", -INFINITY)} END_TEST
    START_TEST(double_g_nan_small_width_big_precision){
        RUN_TEST("%1.14lg", NAN)} END_TEST
    START_TEST(double_g_nan_neg_small_width_big_precision){
        RUN_TEST("%1.14lg", -NAN)} END_TEST
    START_TEST(double_g_infinity_small_width_big_precision){
        RUN_TEST("%1.14lg", INFINITY)} END_TEST
    START_TEST(double_g_infinity_neg_small_width_big_precision){
        RUN_TEST("%1.14lg", -INFINITY)} END_TEST
    START_TEST(long_double_g_nan_small_width_big_precision){
        RUN_TEST("%1.14Lg", NAN)} END_TEST
    START_TEST(long_double_g_nan_neg_small_width_big_precision){
        RUN_TEST("%1.14Lg", -NAN)} END_TEST
    START_TEST(long_double_g_infinity_small_width_big_precision){
        RUN_TEST("%1.14Lg", INFINITY)} END_TEST
    START_TEST(long_double_g_infinity_neg_small_width_big_precision){
        RUN_TEST("%1.14Lg", -INFINITY)} END_TEST
    START_TEST(float_G_nan_small_width_big_precision){
        RUN_TEST("%1.14G", NAN)} END_TEST
    START_TEST(float_G_nan_neg_small_width_big_precision){
        RUN_TEST("%1.14G", -NAN)} END_TEST
    START_TEST(float_G_infinity_small_width_big_precision){
        RUN_TEST("%1.14G", INFINITY)} END_TEST
    START_TEST(float_G_infinity_neg_small_width_big_precision){
        RUN_TEST("%1.14G", -INFINITY)} END_TEST
    START_TEST(double_G_nan_small_width_big_precision){
        RUN_TEST("%1.14lG", NAN)} END_TEST
    START_TEST(double_G_nan_neg_small_width_big_precision){
        RUN_TEST("%1.14lG", -NAN)} END_TEST
    START_TEST(double_G_infinity_small_width_big_precision){
        RUN_TEST("%1.14lG", INFINITY)} END_TEST
    START_TEST(double_G_infinity_neg_small_width_big_precision){
        RUN_TEST("%1.14lG", -INFINITY)} END_TEST
    START_TEST(long_double_G_nan_small_width_big_precision){
        RUN_TEST("%1.14LG", NAN)} END_TEST
    START_TEST(long_double_G_nan_neg_small_width_big_precision){
        RUN_TEST("%1.14LG", -NAN)} END_TEST
    START_TEST(long_double_G_infinity_small_width_big_precision){
        RUN_TEST("%1.14LG", INFINITY)} END_TEST
    START_TEST(long_double_G_infinity_neg_small_width_big_precision){
        RUN_TEST("%1.14LG", -INFINITY)} END_TEST
    START_TEST(float_nan_big_width_no_precision){RUN_TEST("%50f", NAN)} END_TEST
    START_TEST(float_nan_neg_big_width_no_precision){
        RUN_TEST("%50f", -NAN)} END_TEST
    START_TEST(float_infinity_big_width_no_precision){
        RUN_TEST("%50f", INFINITY)} END_TEST
    START_TEST(float_infinity_neg_big_width_no_precision){
        RUN_TEST("%50f", -INFINITY)} END_TEST
    START_TEST(double_nan_big_width_no_precision){
        RUN_TEST("%50lf", NAN)} END_TEST
    START_TEST(double_nan_neg_big_width_no_precision){
        RUN_TEST("%50lf", -NAN)} END_TEST
    START_TEST(double_infinity_big_width_no_precision){
        RUN_TEST("%50lf", INFINITY)} END_TEST
    START_TEST(double_infinity_neg_big_width_no_precision){
        RUN_TEST("%50lf", -INFINITY)} END_TEST
    START_TEST(long_double_nan_big_width_no_precision){
        RUN_TEST("%50Lf", NAN)} END_TEST
    START_TEST(long_double_nan_neg_big_width_no_precision){
        RUN_TEST("%50Lf", -NAN)} END_TEST
    START_TEST(long_double_infinity_big_width_no_precision){
        RUN_TEST("%50Lf", INFINITY)} END_TEST
    START_TEST(long_double_infinity_neg_big_width_no_precision){
        RUN_TEST("%50Lf", -INFINITY)} END_TEST
    START_TEST(float_exp_nan_big_width_no_precision){
        RUN_TEST("%50e", NAN)} END_TEST
    START_TEST(float_exp_nan_neg_big_width_no_precision){
        RUN_TEST("%50e", -NAN)} END_TEST
    START_TEST(float_exp_infinity_big_width_no_precision){
        RUN_TEST("%50e", INFINITY)} END_TEST
    START_TEST(float_exp_infinity_neg_big_width_no_precision){
        RUN_TEST("%50e", -INFINITY)} END_TEST
    START_TEST(double_exp_nan_big_width_no_precision){
        RUN_TEST("%50le", NAN)} END_TEST
    START_TEST(double_exp_nan_neg_big_width_no_precision){
        RUN_TEST("%50le", -NAN)} END_TEST
    START_TEST(double_exp_infinity_big_width_no_precision){
        RUN_TEST("%50le", INFINITY)} END_TEST
    START_TEST(double_exp_infinity_neg_big_width_no_precision){
        RUN_TEST("%50le", -INFINITY)} END_TEST
    START_TEST(long_double_exp_nan_big_width_no_precision){
        RUN_TEST("%50Le", NAN)} END_TEST
    START_TEST(long_double_exp_nan_neg_big_width_no_precision){
        RUN_TEST("%50Le", -NAN)} END_TEST
    START_TEST(long_double_exp_infinity_big_width_no_precision){
        RUN_TEST("%50Le", INFINITY)} END_TEST
    START_TEST(long_double_exp_infinity_neg_big_width_no_precision){
        RUN_TEST("%50Le", -INFINITY)} END_TEST
    START_TEST(float_EXP_nan_big_width_no_precision){
        RUN_TEST("%50E", NAN)} END_TEST
    START_TEST(float_EXP_nan_neg_big_width_no_precision){
        RUN_TEST("%50E", -NAN)} END_TEST
    START_TEST(float_EXP_infinity_big_width_no_precision){
        RUN_TEST("%50E", INFINITY)} END_TEST
    START_TEST(float_EXP_infinity_neg_big_width_no_precision){
        RUN_TEST("%50E", -INFINITY)} END_TEST
    START_TEST(double_EXP_nan_big_width_no_precision){
        RUN_TEST("%50lE", NAN)} END_TEST
    START_TEST(double_EXP_nan_neg_big_width_no_precision){
        RUN_TEST("%50lE", -NAN)} END_TEST
    START_TEST(double_EXP_infinity_big_width_no_precision){
        RUN_TEST("%50lE", INFINITY)} END_TEST
    START_TEST(double_EXP_infinity_neg_big_width_no_precision){
        RUN_TEST("%50lE", -INFINITY)} END_TEST
    START_TEST(long_double_EXP_nan_big_width_no_precision){
        RUN_TEST("%50LE", NAN)} END_TEST
    START_TEST(long_double_EXP_nan_neg_big_width_no_precision){
        RUN_TEST("%50LE", -NAN)} END_TEST
    START_TEST(long_double_EXP_infinity_big_width_no_precision){
        RUN_TEST("%50LE", INFINITY)} END_TEST
    START_TEST(long_double_EXP_infinity_neg_big_width_no_precision){
        RUN_TEST("%50LE", -INFINITY)} END_TEST
    START_TEST(float_g_nan_big_width_no_precision){
        RUN_TEST("%50g", NAN)} END_TEST
    START_TEST(float_g_nan_neg_big_width_no_precision){
        RUN_TEST("%50g", -NAN)} END_TEST
    START_TEST(float_g_infinity_big_width_no_precision){
        RUN_TEST("%50g", INFINITY)} END_TEST
    START_TEST(float_g_infinity_neg_big_width_no_precision){
        RUN_TEST("%50g", -INFINITY)} END_TEST
    START_TEST(double_g_nan_big_width_no_precision){
        RUN_TEST("%50lg", NAN)} END_TEST
    START_TEST(double_g_nan_neg_big_width_no_precision){
        RUN_TEST("%50lg", -NAN)} END_TEST
    START_TEST(double_g_infinity_big_width_no_precision){
        RUN_TEST("%50lg", INFINITY)} END_TEST
    START_TEST(double_g_infinity_neg_big_width_no_precision){
        RUN_TEST("%50lg", -INFINITY)} END_TEST
    START_TEST(long_double_g_nan_big_width_no_precision){
        RUN_TEST("%50Lg", NAN)} END_TEST
    START_TEST(long_double_g_nan_neg_big_width_no_precision){
        RUN_TEST("%50Lg", -NAN)} END_TEST
    START_TEST(long_double_g_infinity_big_width_no_precision){
        RUN_TEST("%50Lg", INFINITY)} END_TEST
    START_TEST(long_double_g_infinity_neg_big_width_no_precision){
        RUN_TEST("%50Lg", -INFINITY)} END_TEST
    START_TEST(float_G_nan_big_width_no_precision){
        RUN_TEST("%50G", NAN)} END_TEST
    START_TEST(float_G_nan_neg_big_width_no_precision){
        RUN_TEST("%50G", -NAN)} END_TEST
    START_TEST(float_G_infinity_big_width_no_precision){
        RUN_TEST("%50G", INFINITY)} END_TEST
    START_TEST(float_G_infinity_neg_big_width_no_precision){
        RUN_TEST("%50G", -INFINITY)} END_TEST
    START_TEST(double_G_nan_big_width_no_precision){
        RUN_TEST("%50lG", NAN)} END_TEST
    START_TEST(double_G_nan_neg_big_width_no_precision){
        RUN_TEST("%50lG", -NAN)} END_TEST
    START_TEST(double_G_infinity_big_width_no_precision){
        RUN_TEST("%50lG", INFINITY)} END_TEST
    START_TEST(double_G_infinity_neg_big_width_no_precision){
        RUN_TEST("%50lG", -INFINITY)} END_TEST
    START_TEST(long_double_G_nan_big_width_no_precision){
        RUN_TEST("%50LG", NAN)} END_TEST
    START_TEST(long_double_G_nan_neg_big_width_no_precision){
        RUN_TEST("%50LG", -NAN)} END_TEST
    START_TEST(long_double_G_infinity_big_width_no_precision){
        RUN_TEST("%50LG", INFINITY)} END_TEST
    START_TEST(long_double_G_infinity_neg_big_width_no_precision){
        RUN_TEST("%50LG", -INFINITY)} END_TEST
    START_TEST(float_nan_big_width_small_precision){
        RUN_TEST("%50.3f", NAN)} END_TEST
    START_TEST(float_nan_neg_big_width_small_precision){
        RUN_TEST("%50.3f", -NAN)} END_TEST
    START_TEST(float_infinity_big_width_small_precision){
        RUN_TEST("%50.3f", INFINITY)} END_TEST
    START_TEST(float_infinity_neg_big_width_small_precision){
        RUN_TEST("%50.3f", -INFINITY)} END_TEST
    START_TEST(double_nan_big_width_small_precision){
        RUN_TEST("%50.3lf", NAN)} END_TEST
    START_TEST(double_nan_neg_big_width_small_precision){
        RUN_TEST("%50.3lf", -NAN)} END_TEST
    START_TEST(double_infinity_big_width_small_precision){
        RUN_TEST("%50.3lf", INFINITY)} END_TEST
    START_TEST(double_infinity_neg_big_width_small_precision){
        RUN_TEST("%50.3lf", -INFINITY)} END_TEST
    START_TEST(long_double_nan_big_width_small_precision){
        RUN_TEST("%50.3Lf", NAN)} END_TEST
    START_TEST(long_double_nan_neg_big_width_small_precision){
        RUN_TEST("%50.3Lf", -NAN)} END_TEST
    START_TEST(long_double_infinity_big_width_small_precision){
        RUN_TEST("%50.3Lf", INFINITY)} END_TEST
    START_TEST(long_double_infinity_neg_big_width_small_precision){
        RUN_TEST("%50.3Lf", -INFINITY)} END_TEST
    START_TEST(float_exp_nan_big_width_small_precision){
        RUN_TEST("%50.3e", NAN)} END_TEST
    START_TEST(float_exp_nan_neg_big_width_small_precision){
        RUN_TEST("%50.3e", -NAN)} END_TEST
    START_TEST(float_exp_infinity_big_width_small_precision){
        RUN_TEST("%50.3e", INFINITY)} END_TEST
    START_TEST(float_exp_infinity_neg_big_width_small_precision){
        RUN_TEST("%50.3e", -INFINITY)} END_TEST
    START_TEST(double_exp_nan_big_width_small_precision){
        RUN_TEST("%50.3le", NAN)} END_TEST
    START_TEST(double_exp_nan_neg_big_width_small_precision){
        RUN_TEST("%50.3le", -NAN)} END_TEST
    START_TEST(double_exp_infinity_big_width_small_precision){
        RUN_TEST("%50.3le", INFINITY)} END_TEST
    START_TEST(double_exp_infinity_neg_big_width_small_precision){
        RUN_TEST("%50.3le", -INFINITY)} END_TEST
    START_TEST(long_double_exp_nan_big_width_small_precision){
        RUN_TEST("%50.3Le", NAN)} END_TEST
    START_TEST(long_double_exp_nan_neg_big_width_small_precision){
        RUN_TEST("%50.3Le", -NAN)} END_TEST
    START_TEST(long_double_exp_infinity_big_width_small_precision){
        RUN_TEST("%50.3Le", INFINITY)} END_TEST
    START_TEST(long_double_exp_infinity_neg_big_width_small_precision){
        RUN_TEST("%50.3Le", -INFINITY)} END_TEST
    START_TEST(float_EXP_nan_big_width_small_precision){
        RUN_TEST("%50.3E", NAN)} END_TEST
    START_TEST(float_EXP_nan_neg_big_width_small_precision){
        RUN_TEST("%50.3E", -NAN)} END_TEST
    START_TEST(float_EXP_infinity_big_width_small_precision){
        RUN_TEST("%50.3E", INFINITY)} END_TEST
    START_TEST(float_EXP_infinity_neg_big_width_small_precision){
        RUN_TEST("%50.3E", -INFINITY)} END_TEST
    START_TEST(double_EXP_nan_big_width_small_precision){
        RUN_TEST("%50.3lE", NAN)} END_TEST
    START_TEST(double_EXP_nan_neg_big_width_small_precision){
        RUN_TEST("%50.3lE", -NAN)} END_TEST
    START_TEST(double_EXP_infinity_big_width_small_precision){
        RUN_TEST("%50.3lE", INFINITY)} END_TEST
    START_TEST(double_EXP_infinity_neg_big_width_small_precision){
        RUN_TEST("%50.3lE", -INFINITY)} END_TEST
    START_TEST(long_double_EXP_nan_big_width_small_precision){
        RUN_TEST("%50.3LE", NAN)} END_TEST
    START_TEST(long_double_EXP_nan_neg_big_width_small_precision){
        RUN_TEST("%50.3LE", -NAN)} END_TEST
    START_TEST(long_double_EXP_infinity_big_width_small_precision){
        RUN_TEST("%50.3LE", INFINITY)} END_TEST
    START_TEST(long_double_EXP_infinity_neg_big_width_small_precision){
        RUN_TEST("%50.3LE", -INFINITY)} END_TEST
    START_TEST(float_g_nan_big_width_small_precision){
        RUN_TEST("%50.3g", NAN)} END_TEST
    START_TEST(float_g_nan_neg_big_width_small_precision){
        RUN_TEST("%50.3g", -NAN)} END_TEST
    START_TEST(float_g_infinity_big_width_small_precision){
        RUN_TEST("%50.3g", INFINITY)} END_TEST
    START_TEST(float_g_infinity_neg_big_width_small_precision){
        RUN_TEST("%50.3g", -INFINITY)} END_TEST
    START_TEST(double_g_nan_big_width_small_precision){
        RUN_TEST("%50.3lg", NAN)} END_TEST
    START_TEST(double_g_nan_neg_big_width_small_precision){
        RUN_TEST("%50.3lg", -NAN)} END_TEST
    START_TEST(double_g_infinity_big_width_small_precision){
        RUN_TEST("%50.3lg", INFINITY)} END_TEST
    START_TEST(double_g_infinity_neg_big_width_small_precision){
        RUN_TEST("%50.3lg", -INFINITY)} END_TEST
    START_TEST(long_double_g_nan_big_width_small_precision){
        RUN_TEST("%50.3Lg", NAN)} END_TEST
    START_TEST(long_double_g_nan_neg_big_width_small_precision){
        RUN_TEST("%50.3Lg", -NAN)} END_TEST
    START_TEST(long_double_g_infinity_big_width_small_precision){
        RUN_TEST("%50.3Lg", INFINITY)} END_TEST
    START_TEST(long_double_g_infinity_neg_big_width_small_precision){
        RUN_TEST("%50.3Lg", -INFINITY)} END_TEST
    START_TEST(float_G_nan_big_width_small_precision){
        RUN_TEST("%50.3G", NAN)} END_TEST
    START_TEST(float_G_nan_neg_big_width_small_precision){
        RUN_TEST("%50.3G", -NAN)} END_TEST
    START_TEST(float_G_infinity_big_width_small_precision){
        RUN_TEST("%50.3G", INFINITY)} END_TEST
    START_TEST(float_G_infinity_neg_big_width_small_precision){
        RUN_TEST("%50.3G", -INFINITY)} END_TEST
    START_TEST(double_G_nan_big_width_small_precision){
        RUN_TEST("%50.3lG", NAN)} END_TEST
    START_TEST(double_G_nan_neg_big_width_small_precision){
        RUN_TEST("%50.3lG", -NAN)} END_TEST
    START_TEST(double_G_infinity_big_width_small_precision){
        RUN_TEST("%50.3lG", INFINITY)} END_TEST
    START_TEST(double_G_infinity_neg_big_width_small_precision){
        RUN_TEST("%50.3lG", -INFINITY)} END_TEST
    START_TEST(long_double_G_nan_big_width_small_precision){
        RUN_TEST("%50.3LG", NAN)} END_TEST
    START_TEST(long_double_G_nan_neg_big_width_small_precision){
        RUN_TEST("%50.3LG", -NAN)} END_TEST
    START_TEST(long_double_G_infinity_big_width_small_precision){
        RUN_TEST("%50.3LG", INFINITY)} END_TEST
    START_TEST(long_double_G_infinity_neg_big_width_small_precision){
        RUN_TEST("%50.3LG", -INFINITY)} END_TEST
    START_TEST(float_nan_big_width_big_precision){
        RUN_TEST("%50.14f", NAN)} END_TEST
    START_TEST(float_nan_neg_big_width_big_precision){
        RUN_TEST("%50.14f", -NAN)} END_TEST
    START_TEST(float_infinity_big_width_big_precision){
        RUN_TEST("%50.14f", INFINITY)} END_TEST
    START_TEST(float_infinity_neg_big_width_big_precision){
        RUN_TEST("%50.14f", -INFINITY)} END_TEST
    START_TEST(double_nan_big_width_big_precision){
        RUN_TEST("%50.14lf", NAN)} END_TEST
    START_TEST(double_nan_neg_big_width_big_precision){
        RUN_TEST("%50.14lf", -NAN)} END_TEST
    START_TEST(double_infinity_big_width_big_precision){
        RUN_TEST("%50.14lf", INFINITY)} END_TEST
    START_TEST(double_infinity_neg_big_width_big_precision){
        RUN_TEST("%50.14lf", -INFINITY)} END_TEST
    START_TEST(long_double_nan_big_width_big_precision){
        RUN_TEST("%50.14Lf", NAN)} END_TEST
    START_TEST(long_double_nan_neg_big_width_big_precision){
        RUN_TEST("%50.14Lf", -NAN)} END_TEST
    START_TEST(long_double_infinity_big_width_big_precision){
        RUN_TEST("%50.14Lf", INFINITY)} END_TEST
    START_TEST(long_double_infinity_neg_big_width_big_precision){
        RUN_TEST("%50.14Lf", -INFINITY)} END_TEST
    START_TEST(float_exp_nan_big_width_big_precision){
        RUN_TEST("%50.14e", NAN)} END_TEST
    START_TEST(float_exp_nan_neg_big_width_big_precision){
        RUN_TEST("%50.14e", -NAN)} END_TEST
    START_TEST(float_exp_infinity_big_width_big_precision){
        RUN_TEST("%50.14e", INFINITY)} END_TEST
    START_TEST(float_exp_infinity_neg_big_width_big_precision){
        RUN_TEST("%50.14e", -INFINITY)} END_TEST
    START_TEST(double_exp_nan_big_width_big_precision){
        RUN_TEST("%50.14le", NAN)} END_TEST
    START_TEST(double_exp_nan_neg_big_width_big_precision){
        RUN_TEST("%50.14le", -NAN)} END_TEST
    START_TEST(double_exp_infinity_big_width_big_precision){
        RUN_TEST("%50.14le", INFINITY)} END_TEST
    START_TEST(double_exp_infinity_neg_big_width_big_precision){
        RUN_TEST("%50.14le", -INFINITY)} END_TEST
    START_TEST(long_double_exp_nan_big_width_big_precision){
        RUN_TEST("%50.14Le", NAN)} END_TEST
    START_TEST(long_double_exp_nan_neg_big_width_big_precision){
        RUN_TEST("%50.14Le", -NAN)} END_TEST
    START_TEST(long_double_exp_infinity_big_width_big_precision){
        RUN_TEST("%50.14Le", INFINITY)} END_TEST
    START_TEST(long_double_exp_infinity_neg_big_width_big_precision){
        RUN_TEST("%50.14Le", -INFINITY)} END_TEST
    START_TEST(float_EXP_nan_big_width_big_precision){
        RUN_TEST("%50.14E", NAN)} END_TEST
    START_TEST(float_EXP_nan_neg_big_width_big_precision){
        RUN_TEST("%50.14E", -NAN)} END_TEST
    START_TEST(float_EXP_infinity_big_width_big_precision){
        RUN_TEST("%50.14E", INFINITY)} END_TEST
    START_TEST(float_EXP_infinity_neg_big_width_big_precision){
        RUN_TEST("%50.14E", -INFINITY)} END_TEST
    START_TEST(double_EXP_nan_big_width_big_precision){
        RUN_TEST("%50.14lE", NAN)} END_TEST
    START_TEST(double_EXP_nan_neg_big_width_big_precision){
        RUN_TEST("%50.14lE", -NAN)} END_TEST
    START_TEST(double_EXP_infinity_big_width_big_precision){
        RUN_TEST("%50.14lE", INFINITY)} END_TEST
    START_TEST(double_EXP_infinity_neg_big_width_big_precision){
        RUN_TEST("%50.14lE", -INFINITY)} END_TEST
    START_TEST(long_double_EXP_nan_big_width_big_precision){
        RUN_TEST("%50.14LE", NAN)} END_TEST
    START_TEST(long_double_EXP_nan_neg_big_width_big_precision){
        RUN_TEST("%50.14LE", -NAN)} END_TEST
    START_TEST(long_double_EXP_infinity_big_width_big_precision){
        RUN_TEST("%50.14LE", INFINITY)} END_TEST
    START_TEST(long_double_EXP_infinity_neg_big_width_big_precision){
        RUN_TEST("%50.14LE", -INFINITY)} END_TEST
    START_TEST(float_g_nan_big_width_big_precision){
        RUN_TEST("%50.14g", NAN)} END_TEST
    START_TEST(float_g_nan_neg_big_width_big_precision){
        RUN_TEST("%50.14g", -NAN)} END_TEST
    START_TEST(float_g_infinity_big_width_big_precision){
        RUN_TEST("%50.14g", INFINITY)} END_TEST
    START_TEST(float_g_infinity_neg_big_width_big_precision){
        RUN_TEST("%50.14g", -INFINITY)} END_TEST
    START_TEST(double_g_nan_big_width_big_precision){
        RUN_TEST("%50.14lg", NAN)} END_TEST
    START_TEST(double_g_nan_neg_big_width_big_precision){
        RUN_TEST("%50.14lg", -NAN)} END_TEST
    START_TEST(double_g_infinity_big_width_big_precision){
        RUN_TEST("%50.14lg", INFINITY)} END_TEST
    START_TEST(double_g_infinity_neg_big_width_big_precision){
        RUN_TEST("%50.14lg", -INFINITY)} END_TEST
    START_TEST(long_double_g_nan_big_width_big_precision){
        RUN_TEST("%50.14Lg", NAN)} END_TEST
    START_TEST(long_double_g_nan_neg_big_width_big_precision){
        RUN_TEST("%50.14Lg", -NAN)} END_TEST
    START_TEST(long_double_g_infinity_big_width_big_precision){
        RUN_TEST("%50.14Lg", INFINITY)} END_TEST
    START_TEST(long_double_g_infinity_neg_big_width_big_precision){
        RUN_TEST("%50.14Lg", -INFINITY)} END_TEST
    START_TEST(float_G_nan_big_width_big_precision){
        RUN_TEST("%50.14G", NAN)} END_TEST
    START_TEST(float_G_nan_neg_big_width_big_precision){
        RUN_TEST("%50.14G", -NAN)} END_TEST
    START_TEST(float_G_infinity_big_width_big_precision){
        RUN_TEST("%50.14G", INFINITY)} END_TEST
    START_TEST(float_G_infinity_neg_big_width_big_precision){
        RUN_TEST("%50.14G", -INFINITY)} END_TEST
    START_TEST(double_G_nan_big_width_big_precision){
        RUN_TEST("%50.14lG", NAN)} END_TEST
    START_TEST(double_G_nan_neg_big_width_big_precision){
        RUN_TEST("%50.14lG", -NAN)} END_TEST
    START_TEST(double_G_infinity_big_width_big_precision){
        RUN_TEST("%50.14lG", INFINITY)} END_TEST
    START_TEST(double_G_infinity_neg_big_width_big_precision){
        RUN_TEST("%50.14lG", -INFINITY)} END_TEST
    START_TEST(long_double_G_nan_big_width_big_precision){
        RUN_TEST("%50.14LG", NAN)} END_TEST
    START_TEST(long_double_G_nan_neg_big_width_big_precision){
        RUN_TEST("%50.14LG", -NAN)} END_TEST
    START_TEST(long_double_G_infinity_big_width_big_precision){
        RUN_TEST("%50.14LG", INFINITY)} END_TEST
    START_TEST(long_double_G_infinity_neg_big_width_big_precision){
        RUN_TEST("%50.14LG", -INFINITY)} END_TEST

    START_TEST(short_null_no_flags){RUN_TEST("%hd", (short)0)} END_TEST
    START_TEST(short_general_short_no_flags){
        RUN_TEST("%hd", (short)8192)} END_TEST
    START_TEST(short_general_short_neg_no_flags){
        RUN_TEST("%hd", (short)-8192)} END_TEST
    START_TEST(short_general_medium_no_flags){
        RUN_TEST("%hd", (short)2000000001)} END_TEST
    START_TEST(short_general_medium_neg_no_flags){
        RUN_TEST("%hd", (short)-2000000001)} END_TEST
    START_TEST(short_null_prefix_sign){RUN_TEST("%+hd", (short)0)} END_TEST
    START_TEST(short_general_short_prefix_sign){
        RUN_TEST("%+hd", (short)8192)} END_TEST
    START_TEST(short_general_short_neg_prefix_sign){
        RUN_TEST("%+hd", (short)-8192)} END_TEST
    START_TEST(short_general_medium_prefix_sign){
        RUN_TEST("%+hd", (short)2000000001)} END_TEST
    START_TEST(short_general_medium_neg_prefix_sign){
        RUN_TEST("%+hd", (short)-2000000001)} END_TEST
    START_TEST(short_null_prefix_space){RUN_TEST("% hd", (short)0)} END_TEST
    START_TEST(short_general_short_prefix_space){
        RUN_TEST("% hd", (short)8192)} END_TEST
    START_TEST(short_general_short_neg_prefix_space){
        RUN_TEST("% hd", (short)-8192)} END_TEST
    START_TEST(short_general_medium_prefix_space){
        RUN_TEST("% hd", (short)2000000001)} END_TEST
    START_TEST(short_general_medium_neg_prefix_space){
        RUN_TEST("% hd", (short)-2000000001)} END_TEST
    START_TEST(short_null_left_alignment){RUN_TEST("%-hd", (short)0)} END_TEST
    START_TEST(short_general_short_left_alignment){
        RUN_TEST("%-hd", (short)8192)} END_TEST
    START_TEST(short_general_short_neg_left_alignment){
        RUN_TEST("%-hd", (short)-8192)} END_TEST
    START_TEST(short_general_medium_left_alignment){
        RUN_TEST("%-hd", (short)2000000001)} END_TEST
    START_TEST(short_general_medium_neg_left_alignment){
        RUN_TEST("%-hd", (short)-2000000001)} END_TEST
    START_TEST(short_null_leading_zeroes){RUN_TEST("%0hd", (short)0)} END_TEST
    START_TEST(short_general_short_leading_zeroes){
        RUN_TEST("%0hd", (short)8192)} END_TEST
    START_TEST(short_general_short_neg_leading_zeroes){
        RUN_TEST("%0hd", (short)-8192)} END_TEST
    START_TEST(short_general_medium_leading_zeroes){
        RUN_TEST("%0hd", (short)2000000001)} END_TEST
    START_TEST(short_general_medium_neg_leading_zeroes){
        RUN_TEST("%0hd", (short)-2000000001)} END_TEST
    START_TEST(short_null_alt_format){RUN_TEST("%#hd", (short)0)} END_TEST
    START_TEST(short_general_short_alt_format){
        RUN_TEST("%#hd", (short)8192)} END_TEST
    START_TEST(short_general_short_neg_alt_format){
        RUN_TEST("%#hd", (short)-8192)} END_TEST
    START_TEST(short_general_medium_alt_format){
        RUN_TEST("%#hd", (short)2000000001)} END_TEST
    START_TEST(short_general_medium_neg_alt_format){
        RUN_TEST("%#hd", (short)-2000000001)} END_TEST
    START_TEST(short_null_no_width_no_precision){
        RUN_TEST("%hd", (short)0)} END_TEST
    START_TEST(short_general_short_no_width_no_precision){
        RUN_TEST("%hd", (short)8192)} END_TEST
    START_TEST(short_general_short_neg_no_width_no_precision){
        RUN_TEST("%hd", (short)-8192)} END_TEST
    START_TEST(short_general_medium_no_width_no_precision){
        RUN_TEST("%hd", (short)2000000001)} END_TEST
    START_TEST(short_general_medium_neg_no_width_no_precision){
        RUN_TEST("%hd", (short)-2000000001)} END_TEST
    START_TEST(short_null_no_width_small_precision){
        RUN_TEST("%.3hd", (short)0)} END_TEST
    START_TEST(short_general_short_no_width_small_precision){
        RUN_TEST("%.3hd", (short)8192)} END_TEST
    START_TEST(short_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3hd", (short)-8192)} END_TEST
    START_TEST(short_general_medium_no_width_small_precision){
        RUN_TEST("%.3hd", (short)2000000001)} END_TEST
    START_TEST(short_general_medium_neg_no_width_small_precision){
        RUN_TEST("%.3hd", (short)-2000000001)} END_TEST
    START_TEST(short_null_no_width_big_precision){
        RUN_TEST("%.14hd", (short)0)} END_TEST
    START_TEST(short_general_short_no_width_big_precision){
        RUN_TEST("%.14hd", (short)8192)} END_TEST
    START_TEST(short_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14hd", (short)-8192)} END_TEST
    START_TEST(short_general_medium_no_width_big_precision){
        RUN_TEST("%.14hd", (short)2000000001)} END_TEST
    START_TEST(short_general_medium_neg_no_width_big_precision){
        RUN_TEST("%.14hd", (short)-2000000001)} END_TEST
    START_TEST(short_null_small_width_no_precision){
        RUN_TEST("%1hd", (short)0)} END_TEST
    START_TEST(short_general_short_small_width_no_precision){
        RUN_TEST("%1hd", (short)8192)} END_TEST
    START_TEST(short_general_short_neg_small_width_no_precision){
        RUN_TEST("%1hd", (short)-8192)} END_TEST
    START_TEST(short_general_medium_small_width_no_precision){
        RUN_TEST("%1hd", (short)2000000001)} END_TEST
    START_TEST(short_general_medium_neg_small_width_no_precision){
        RUN_TEST("%1hd", (short)-2000000001)} END_TEST
    START_TEST(short_null_small_width_small_precision){
        RUN_TEST("%1.3hd", (short)0)} END_TEST
    START_TEST(short_general_short_small_width_small_precision){
        RUN_TEST("%1.3hd", (short)8192)} END_TEST
    START_TEST(short_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3hd", (short)-8192)} END_TEST
    START_TEST(short_general_medium_small_width_small_precision){
        RUN_TEST("%1.3hd", (short)2000000001)} END_TEST
    START_TEST(short_general_medium_neg_small_width_small_precision){
        RUN_TEST("%1.3hd", (short)-2000000001)} END_TEST
    START_TEST(short_null_small_width_big_precision){
        RUN_TEST("%1.14hd", (short)0)} END_TEST
    START_TEST(short_general_short_small_width_big_precision){
        RUN_TEST("%1.14hd", (short)8192)} END_TEST
    START_TEST(short_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14hd", (short)-8192)} END_TEST
    START_TEST(short_general_medium_small_width_big_precision){
        RUN_TEST("%1.14hd", (short)2000000001)} END_TEST
    START_TEST(short_general_medium_neg_small_width_big_precision){
        RUN_TEST("%1.14hd", (short)-2000000001)} END_TEST
    START_TEST(short_null_big_width_no_precision){
        RUN_TEST("%50hd", (short)0)} END_TEST
    START_TEST(short_general_short_big_width_no_precision){
        RUN_TEST("%50hd", (short)8192)} END_TEST
    START_TEST(short_general_short_neg_big_width_no_precision){
        RUN_TEST("%50hd", (short)-8192)} END_TEST
    START_TEST(short_general_medium_big_width_no_precision){
        RUN_TEST("%50hd", (short)2000000001)} END_TEST
    START_TEST(short_general_medium_neg_big_width_no_precision){
        RUN_TEST("%50hd", (short)-2000000001)} END_TEST
    START_TEST(short_null_big_width_small_precision){
        RUN_TEST("%50.3hd", (short)0)} END_TEST
    START_TEST(short_general_short_big_width_small_precision){
        RUN_TEST("%50.3hd", (short)8192)} END_TEST
    START_TEST(short_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3hd", (short)-8192)} END_TEST
    START_TEST(short_general_medium_big_width_small_precision){
        RUN_TEST("%50.3hd", (short)2000000001)} END_TEST
    START_TEST(short_general_medium_neg_big_width_small_precision){
        RUN_TEST("%50.3hd", (short)-2000000001)} END_TEST
    START_TEST(short_null_big_width_big_precision){
        RUN_TEST("%50.14hd", (short)0)} END_TEST
    START_TEST(short_general_short_big_width_big_precision){
        RUN_TEST("%50.14hd", (short)8192)} END_TEST
    START_TEST(short_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14hd", (short)-8192)} END_TEST
    START_TEST(short_general_medium_big_width_big_precision){
        RUN_TEST("%50.14hd", (short)2000000001)} END_TEST
    START_TEST(short_general_medium_neg_big_width_big_precision){
        RUN_TEST("%50.14hd", (short)-2000000001)} END_TEST

    START_TEST(unsigned_short_null_no_flags){
        RUN_TEST("%hu", (unsigned short)0u)} END_TEST
    START_TEST(unsigned_short_general_short_no_flags){
        RUN_TEST("%hu", (unsigned short)8192u)} END_TEST
    START_TEST(unsigned_short_general_short_neg_no_flags){
        RUN_TEST("%hu", (unsigned short)-8192u)} END_TEST
    START_TEST(unsigned_short_general_medium_no_flags){
        RUN_TEST("%hu", (unsigned short)2000000001u)} END_TEST
    START_TEST(unsigned_short_general_medium_neg_no_flags){
        RUN_TEST("%hu", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_hex_null_no_flags){
        RUN_TEST("%hx", (unsigned short)0u)} END_TEST
    START_TEST(short_hex_general_short_no_flags){
        RUN_TEST("%hx", (unsigned short)8192u)} END_TEST
    START_TEST(short_hex_general_short_neg_no_flags){
        RUN_TEST("%hx", (unsigned short)-8192u)} END_TEST
    START_TEST(short_hex_general_medium_no_flags){
        RUN_TEST("%hx", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_hex_general_medium_neg_no_flags){
        RUN_TEST("%hx", (unsigned short)-2000000001u)} END_TEST
    START_TEST(SHORT_HEX_null_no_flags){
        RUN_TEST("%hX", (unsigned short)0u)} END_TEST
    START_TEST(SHORT_HEX_general_short_no_flags){
        RUN_TEST("%hX", (unsigned short)8192u)} END_TEST
    START_TEST(SHORT_HEX_general_short_neg_no_flags){
        RUN_TEST("%hX", (unsigned short)-8192u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_no_flags){
        RUN_TEST("%hX", (unsigned short)2000000001u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_neg_no_flags){
        RUN_TEST("%hX", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_oct_null_no_flags){
        RUN_TEST("%ho", (unsigned short)0u)} END_TEST
    START_TEST(short_oct_general_short_no_flags){
        RUN_TEST("%ho", (unsigned short)8192u)} END_TEST
    START_TEST(short_oct_general_short_neg_no_flags){
        RUN_TEST("%ho", (unsigned short)-8192u)} END_TEST
    START_TEST(short_oct_general_medium_no_flags){
        RUN_TEST("%ho", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_oct_general_medium_neg_no_flags){
        RUN_TEST("%ho", (unsigned short)-2000000001u)} END_TEST
    START_TEST(unsigned_short_null_prefix_sign){
        RUN_TEST("%+hu", (unsigned short)0u)} END_TEST
    START_TEST(unsigned_short_general_short_prefix_sign){
        RUN_TEST("%+hu", (unsigned short)8192u)} END_TEST
    START_TEST(unsigned_short_general_short_neg_prefix_sign){
        RUN_TEST("%+hu", (unsigned short)-8192u)} END_TEST
    START_TEST(unsigned_short_general_medium_prefix_sign){
        RUN_TEST("%+hu", (unsigned short)2000000001u)} END_TEST
    START_TEST(unsigned_short_general_medium_neg_prefix_sign){
        RUN_TEST("%+hu", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_hex_null_prefix_sign){
        RUN_TEST("%+hx", (unsigned short)0u)} END_TEST
    START_TEST(short_hex_general_short_prefix_sign){
        RUN_TEST("%+hx", (unsigned short)8192u)} END_TEST
    START_TEST(short_hex_general_short_neg_prefix_sign){
        RUN_TEST("%+hx", (unsigned short)-8192u)} END_TEST
    START_TEST(short_hex_general_medium_prefix_sign){
        RUN_TEST("%+hx", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_hex_general_medium_neg_prefix_sign){
        RUN_TEST("%+hx", (unsigned short)-2000000001u)} END_TEST
    START_TEST(SHORT_HEX_null_prefix_sign){
        RUN_TEST("%+hX", (unsigned short)0u)} END_TEST
    START_TEST(SHORT_HEX_general_short_prefix_sign){
        RUN_TEST("%+hX", (unsigned short)8192u)} END_TEST
    START_TEST(SHORT_HEX_general_short_neg_prefix_sign){
        RUN_TEST("%+hX", (unsigned short)-8192u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_prefix_sign){
        RUN_TEST("%+hX", (unsigned short)2000000001u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_neg_prefix_sign){
        RUN_TEST("%+hX", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_oct_null_prefix_sign){
        RUN_TEST("%+ho", (unsigned short)0u)} END_TEST
    START_TEST(short_oct_general_short_prefix_sign){
        RUN_TEST("%+ho", (unsigned short)8192u)} END_TEST
    START_TEST(short_oct_general_short_neg_prefix_sign){
        RUN_TEST("%+ho", (unsigned short)-8192u)} END_TEST
    START_TEST(short_oct_general_medium_prefix_sign){
        RUN_TEST("%+ho", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_oct_general_medium_neg_prefix_sign){
        RUN_TEST("%+ho", (unsigned short)-2000000001u)} END_TEST
    START_TEST(unsigned_short_null_prefix_space){
        RUN_TEST("% hu", (unsigned short)0u)} END_TEST
    START_TEST(unsigned_short_general_short_prefix_space){
        RUN_TEST("% hu", (unsigned short)8192u)} END_TEST
    START_TEST(unsigned_short_general_short_neg_prefix_space){
        RUN_TEST("% hu", (unsigned short)-8192u)} END_TEST
    START_TEST(unsigned_short_general_medium_prefix_space){
        RUN_TEST("% hu", (unsigned short)2000000001u)} END_TEST
    START_TEST(unsigned_short_general_medium_neg_prefix_space){
        RUN_TEST("% hu", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_hex_null_prefix_space){
        RUN_TEST("% hx", (unsigned short)0u)} END_TEST
    START_TEST(short_hex_general_short_prefix_space){
        RUN_TEST("% hx", (unsigned short)8192u)} END_TEST
    START_TEST(short_hex_general_short_neg_prefix_space){
        RUN_TEST("% hx", (unsigned short)-8192u)} END_TEST
    START_TEST(short_hex_general_medium_prefix_space){
        RUN_TEST("% hx", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_hex_general_medium_neg_prefix_space){
        RUN_TEST("% hx", (unsigned short)-2000000001u)} END_TEST
    START_TEST(SHORT_HEX_null_prefix_space){
        RUN_TEST("% hX", (unsigned short)0u)} END_TEST
    START_TEST(SHORT_HEX_general_short_prefix_space){
        RUN_TEST("% hX", (unsigned short)8192u)} END_TEST
    START_TEST(SHORT_HEX_general_short_neg_prefix_space){
        RUN_TEST("% hX", (unsigned short)-8192u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_prefix_space){
        RUN_TEST("% hX", (unsigned short)2000000001u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_neg_prefix_space){
        RUN_TEST("% hX", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_oct_null_prefix_space){
        RUN_TEST("% ho", (unsigned short)0u)} END_TEST
    START_TEST(short_oct_general_short_prefix_space){
        RUN_TEST("% ho", (unsigned short)8192u)} END_TEST
    START_TEST(short_oct_general_short_neg_prefix_space){
        RUN_TEST("% ho", (unsigned short)-8192u)} END_TEST
    START_TEST(short_oct_general_medium_prefix_space){
        RUN_TEST("% ho", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_oct_general_medium_neg_prefix_space){
        RUN_TEST("% ho", (unsigned short)-2000000001u)} END_TEST
    START_TEST(unsigned_short_null_left_alignment){
        RUN_TEST("%-hu", (unsigned short)0u)} END_TEST
    START_TEST(unsigned_short_general_short_left_alignment){
        RUN_TEST("%-hu", (unsigned short)8192u)} END_TEST
    START_TEST(unsigned_short_general_short_neg_left_alignment){
        RUN_TEST("%-hu", (unsigned short)-8192u)} END_TEST
    START_TEST(unsigned_short_general_medium_left_alignment){
        RUN_TEST("%-hu", (unsigned short)2000000001u)} END_TEST
    START_TEST(unsigned_short_general_medium_neg_left_alignment){
        RUN_TEST("%-hu", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_hex_null_left_alignment){
        RUN_TEST("%-hx", (unsigned short)0u)} END_TEST
    START_TEST(short_hex_general_short_left_alignment){
        RUN_TEST("%-hx", (unsigned short)8192u)} END_TEST
    START_TEST(short_hex_general_short_neg_left_alignment){
        RUN_TEST("%-hx", (unsigned short)-8192u)} END_TEST
    START_TEST(short_hex_general_medium_left_alignment){
        RUN_TEST("%-hx", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_hex_general_medium_neg_left_alignment){
        RUN_TEST("%-hx", (unsigned short)-2000000001u)} END_TEST
    START_TEST(SHORT_HEX_null_left_alignment){
        RUN_TEST("%-hX", (unsigned short)0u)} END_TEST
    START_TEST(SHORT_HEX_general_short_left_alignment){
        RUN_TEST("%-hX", (unsigned short)8192u)} END_TEST
    START_TEST(SHORT_HEX_general_short_neg_left_alignment){
        RUN_TEST("%-hX", (unsigned short)-8192u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_left_alignment){
        RUN_TEST("%-hX", (unsigned short)2000000001u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_neg_left_alignment){
        RUN_TEST("%-hX", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_oct_null_left_alignment){
        RUN_TEST("%-ho", (unsigned short)0u)} END_TEST
    START_TEST(short_oct_general_short_left_alignment){
        RUN_TEST("%-ho", (unsigned short)8192u)} END_TEST
    START_TEST(short_oct_general_short_neg_left_alignment){
        RUN_TEST("%-ho", (unsigned short)-8192u)} END_TEST
    START_TEST(short_oct_general_medium_left_alignment){
        RUN_TEST("%-ho", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_oct_general_medium_neg_left_alignment){
        RUN_TEST("%-ho", (unsigned short)-2000000001u)} END_TEST
    START_TEST(unsigned_short_null_leading_zeroes){
        RUN_TEST("%0hu", (unsigned short)0u)} END_TEST
    START_TEST(unsigned_short_general_short_leading_zeroes){
        RUN_TEST("%0hu", (unsigned short)8192u)} END_TEST
    START_TEST(unsigned_short_general_short_neg_leading_zeroes){
        RUN_TEST("%0hu", (unsigned short)-8192u)} END_TEST
    START_TEST(unsigned_short_general_medium_leading_zeroes){
        RUN_TEST("%0hu", (unsigned short)2000000001u)} END_TEST
    START_TEST(unsigned_short_general_medium_neg_leading_zeroes){
        RUN_TEST("%0hu", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_hex_null_leading_zeroes){
        RUN_TEST("%0hx", (unsigned short)0u)} END_TEST
    START_TEST(short_hex_general_short_leading_zeroes){
        RUN_TEST("%0hx", (unsigned short)8192u)} END_TEST
    START_TEST(short_hex_general_short_neg_leading_zeroes){
        RUN_TEST("%0hx", (unsigned short)-8192u)} END_TEST
    START_TEST(short_hex_general_medium_leading_zeroes){
        RUN_TEST("%0hx", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_hex_general_medium_neg_leading_zeroes){
        RUN_TEST("%0hx", (unsigned short)-2000000001u)} END_TEST
    START_TEST(SHORT_HEX_null_leading_zeroes){
        RUN_TEST("%0hX", (unsigned short)0u)} END_TEST
    START_TEST(SHORT_HEX_general_short_leading_zeroes){
        RUN_TEST("%0hX", (unsigned short)8192u)} END_TEST
    START_TEST(SHORT_HEX_general_short_neg_leading_zeroes){
        RUN_TEST("%0hX", (unsigned short)-8192u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_leading_zeroes){
        RUN_TEST("%0hX", (unsigned short)2000000001u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_neg_leading_zeroes){
        RUN_TEST("%0hX", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_oct_null_leading_zeroes){
        RUN_TEST("%0ho", (unsigned short)0u)} END_TEST
    START_TEST(short_oct_general_short_leading_zeroes){
        RUN_TEST("%0ho", (unsigned short)8192u)} END_TEST
    START_TEST(short_oct_general_short_neg_leading_zeroes){
        RUN_TEST("%0ho", (unsigned short)-8192u)} END_TEST
    START_TEST(short_oct_general_medium_leading_zeroes){
        RUN_TEST("%0ho", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_oct_general_medium_neg_leading_zeroes){
        RUN_TEST("%0ho", (unsigned short)-2000000001u)} END_TEST
    START_TEST(unsigned_short_null_alt_format){
        RUN_TEST("%#hu", (unsigned short)0u)} END_TEST
    START_TEST(unsigned_short_general_short_alt_format){
        RUN_TEST("%#hu", (unsigned short)8192u)} END_TEST
    START_TEST(unsigned_short_general_short_neg_alt_format){
        RUN_TEST("%#hu", (unsigned short)-8192u)} END_TEST
    START_TEST(unsigned_short_general_medium_alt_format){
        RUN_TEST("%#hu", (unsigned short)2000000001u)} END_TEST
    START_TEST(unsigned_short_general_medium_neg_alt_format){
        RUN_TEST("%#hu", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_hex_null_alt_format){
        RUN_TEST("%#hx", (unsigned short)0u)} END_TEST
    START_TEST(short_hex_general_short_alt_format){
        RUN_TEST("%#hx", (unsigned short)8192u)} END_TEST
    START_TEST(short_hex_general_short_neg_alt_format){
        RUN_TEST("%#hx", (unsigned short)-8192u)} END_TEST
    START_TEST(short_hex_general_medium_alt_format){
        RUN_TEST("%#hx", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_hex_general_medium_neg_alt_format){
        RUN_TEST("%#hx", (unsigned short)-2000000001u)} END_TEST
    START_TEST(SHORT_HEX_null_alt_format){
        RUN_TEST("%#hX", (unsigned short)0u)} END_TEST
    START_TEST(SHORT_HEX_general_short_alt_format){
        RUN_TEST("%#hX", (unsigned short)8192u)} END_TEST
    START_TEST(SHORT_HEX_general_short_neg_alt_format){
        RUN_TEST("%#hX", (unsigned short)-8192u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_alt_format){
        RUN_TEST("%#hX", (unsigned short)2000000001u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_neg_alt_format){
        RUN_TEST("%#hX", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_oct_null_alt_format){
        RUN_TEST("%#ho", (unsigned short)0u)} END_TEST
    START_TEST(short_oct_general_short_alt_format){
        RUN_TEST("%#ho", (unsigned short)8192u)} END_TEST
    START_TEST(short_oct_general_short_neg_alt_format){
        RUN_TEST("%#ho", (unsigned short)-8192u)} END_TEST
    START_TEST(short_oct_general_medium_alt_format){
        RUN_TEST("%#ho", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_oct_general_medium_neg_alt_format){
        RUN_TEST("%#ho", (unsigned short)-2000000001u)} END_TEST
    START_TEST(unsigned_short_null_no_width_no_precision){
        RUN_TEST("%hu", (unsigned short)0u)} END_TEST
    START_TEST(unsigned_short_general_short_no_width_no_precision){
        RUN_TEST("%hu", (unsigned short)8192u)} END_TEST
    START_TEST(unsigned_short_general_short_neg_no_width_no_precision){
        RUN_TEST("%hu", (unsigned short)-8192u)} END_TEST
    START_TEST(unsigned_short_general_medium_no_width_no_precision){
        RUN_TEST("%hu", (unsigned short)2000000001u)} END_TEST
    START_TEST(unsigned_short_general_medium_neg_no_width_no_precision){
        RUN_TEST("%hu", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_hex_null_no_width_no_precision){
        RUN_TEST("%hx", (unsigned short)0u)} END_TEST
    START_TEST(short_hex_general_short_no_width_no_precision){
        RUN_TEST("%hx", (unsigned short)8192u)} END_TEST
    START_TEST(short_hex_general_short_neg_no_width_no_precision){
        RUN_TEST("%hx", (unsigned short)-8192u)} END_TEST
    START_TEST(short_hex_general_medium_no_width_no_precision){
        RUN_TEST("%hx", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_hex_general_medium_neg_no_width_no_precision){
        RUN_TEST("%hx", (unsigned short)-2000000001u)} END_TEST
    START_TEST(SHORT_HEX_null_no_width_no_precision){
        RUN_TEST("%hX", (unsigned short)0u)} END_TEST
    START_TEST(SHORT_HEX_general_short_no_width_no_precision){
        RUN_TEST("%hX", (unsigned short)8192u)} END_TEST
    START_TEST(SHORT_HEX_general_short_neg_no_width_no_precision){
        RUN_TEST("%hX", (unsigned short)-8192u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_no_width_no_precision){
        RUN_TEST("%hX", (unsigned short)2000000001u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_neg_no_width_no_precision){
        RUN_TEST("%hX", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_oct_null_no_width_no_precision){
        RUN_TEST("%ho", (unsigned short)0u)} END_TEST
    START_TEST(short_oct_general_short_no_width_no_precision){
        RUN_TEST("%ho", (unsigned short)8192u)} END_TEST
    START_TEST(short_oct_general_short_neg_no_width_no_precision){
        RUN_TEST("%ho", (unsigned short)-8192u)} END_TEST
    START_TEST(short_oct_general_medium_no_width_no_precision){
        RUN_TEST("%ho", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_oct_general_medium_neg_no_width_no_precision){
        RUN_TEST("%ho", (unsigned short)-2000000001u)} END_TEST
    START_TEST(unsigned_short_null_no_width_small_precision){
        RUN_TEST("%.3hu", (unsigned short)0u)} END_TEST
    START_TEST(unsigned_short_general_short_no_width_small_precision){
        RUN_TEST("%.3hu", (unsigned short)8192u)} END_TEST
    START_TEST(unsigned_short_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3hu", (unsigned short)-8192u)} END_TEST
    START_TEST(unsigned_short_general_medium_no_width_small_precision){
        RUN_TEST("%.3hu", (unsigned short)2000000001u)} END_TEST
    START_TEST(unsigned_short_general_medium_neg_no_width_small_precision){
        RUN_TEST("%.3hu", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_hex_null_no_width_small_precision){
        RUN_TEST("%.3hx", (unsigned short)0u)} END_TEST
    START_TEST(short_hex_general_short_no_width_small_precision){
        RUN_TEST("%.3hx", (unsigned short)8192u)} END_TEST
    START_TEST(short_hex_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3hx", (unsigned short)-8192u)} END_TEST
    START_TEST(short_hex_general_medium_no_width_small_precision){
        RUN_TEST("%.3hx", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_hex_general_medium_neg_no_width_small_precision){
        RUN_TEST("%.3hx", (unsigned short)-2000000001u)} END_TEST
    START_TEST(SHORT_HEX_null_no_width_small_precision){
        RUN_TEST("%.3hX", (unsigned short)0u)} END_TEST
    START_TEST(SHORT_HEX_general_short_no_width_small_precision){
        RUN_TEST("%.3hX", (unsigned short)8192u)} END_TEST
    START_TEST(SHORT_HEX_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3hX", (unsigned short)-8192u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_no_width_small_precision){
        RUN_TEST("%.3hX", (unsigned short)2000000001u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_neg_no_width_small_precision){
        RUN_TEST("%.3hX", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_oct_null_no_width_small_precision){
        RUN_TEST("%.3ho", (unsigned short)0u)} END_TEST
    START_TEST(short_oct_general_short_no_width_small_precision){
        RUN_TEST("%.3ho", (unsigned short)8192u)} END_TEST
    START_TEST(short_oct_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3ho", (unsigned short)-8192u)} END_TEST
    START_TEST(short_oct_general_medium_no_width_small_precision){
        RUN_TEST("%.3ho", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_oct_general_medium_neg_no_width_small_precision){
        RUN_TEST("%.3ho", (unsigned short)-2000000001u)} END_TEST
    START_TEST(unsigned_short_null_no_width_big_precision){
        RUN_TEST("%.14hu", (unsigned short)0u)} END_TEST
    START_TEST(unsigned_short_general_short_no_width_big_precision){
        RUN_TEST("%.14hu", (unsigned short)8192u)} END_TEST
    START_TEST(unsigned_short_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14hu", (unsigned short)-8192u)} END_TEST
    START_TEST(unsigned_short_general_medium_no_width_big_precision){
        RUN_TEST("%.14hu", (unsigned short)2000000001u)} END_TEST
    START_TEST(unsigned_short_general_medium_neg_no_width_big_precision){
        RUN_TEST("%.14hu", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_hex_null_no_width_big_precision){
        RUN_TEST("%.14hx", (unsigned short)0u)} END_TEST
    START_TEST(short_hex_general_short_no_width_big_precision){
        RUN_TEST("%.14hx", (unsigned short)8192u)} END_TEST
    START_TEST(short_hex_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14hx", (unsigned short)-8192u)} END_TEST
    START_TEST(short_hex_general_medium_no_width_big_precision){
        RUN_TEST("%.14hx", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_hex_general_medium_neg_no_width_big_precision){
        RUN_TEST("%.14hx", (unsigned short)-2000000001u)} END_TEST
    START_TEST(SHORT_HEX_null_no_width_big_precision){
        RUN_TEST("%.14hX", (unsigned short)0u)} END_TEST
    START_TEST(SHORT_HEX_general_short_no_width_big_precision){
        RUN_TEST("%.14hX", (unsigned short)8192u)} END_TEST
    START_TEST(SHORT_HEX_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14hX", (unsigned short)-8192u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_no_width_big_precision){
        RUN_TEST("%.14hX", (unsigned short)2000000001u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_neg_no_width_big_precision){
        RUN_TEST("%.14hX", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_oct_null_no_width_big_precision){
        RUN_TEST("%.14ho", (unsigned short)0u)} END_TEST
    START_TEST(short_oct_general_short_no_width_big_precision){
        RUN_TEST("%.14ho", (unsigned short)8192u)} END_TEST
    START_TEST(short_oct_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14ho", (unsigned short)-8192u)} END_TEST
    START_TEST(short_oct_general_medium_no_width_big_precision){
        RUN_TEST("%.14ho", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_oct_general_medium_neg_no_width_big_precision){
        RUN_TEST("%.14ho", (unsigned short)-2000000001u)} END_TEST
    START_TEST(unsigned_short_null_small_width_no_precision){
        RUN_TEST("%1hu", (unsigned short)0u)} END_TEST
    START_TEST(unsigned_short_general_short_small_width_no_precision){
        RUN_TEST("%1hu", (unsigned short)8192u)} END_TEST
    START_TEST(unsigned_short_general_short_neg_small_width_no_precision){
        RUN_TEST("%1hu", (unsigned short)-8192u)} END_TEST
    START_TEST(unsigned_short_general_medium_small_width_no_precision){
        RUN_TEST("%1hu", (unsigned short)2000000001u)} END_TEST
    START_TEST(unsigned_short_general_medium_neg_small_width_no_precision){
        RUN_TEST("%1hu", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_hex_null_small_width_no_precision){
        RUN_TEST("%1hx", (unsigned short)0u)} END_TEST
    START_TEST(short_hex_general_short_small_width_no_precision){
        RUN_TEST("%1hx", (unsigned short)8192u)} END_TEST
    START_TEST(short_hex_general_short_neg_small_width_no_precision){
        RUN_TEST("%1hx", (unsigned short)-8192u)} END_TEST
    START_TEST(short_hex_general_medium_small_width_no_precision){
        RUN_TEST("%1hx", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_hex_general_medium_neg_small_width_no_precision){
        RUN_TEST("%1hx", (unsigned short)-2000000001u)} END_TEST
    START_TEST(SHORT_HEX_null_small_width_no_precision){
        RUN_TEST("%1hX", (unsigned short)0u)} END_TEST
    START_TEST(SHORT_HEX_general_short_small_width_no_precision){
        RUN_TEST("%1hX", (unsigned short)8192u)} END_TEST
    START_TEST(SHORT_HEX_general_short_neg_small_width_no_precision){
        RUN_TEST("%1hX", (unsigned short)-8192u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_small_width_no_precision){
        RUN_TEST("%1hX", (unsigned short)2000000001u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_neg_small_width_no_precision){
        RUN_TEST("%1hX", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_oct_null_small_width_no_precision){
        RUN_TEST("%1ho", (unsigned short)0u)} END_TEST
    START_TEST(short_oct_general_short_small_width_no_precision){
        RUN_TEST("%1ho", (unsigned short)8192u)} END_TEST
    START_TEST(short_oct_general_short_neg_small_width_no_precision){
        RUN_TEST("%1ho", (unsigned short)-8192u)} END_TEST
    START_TEST(short_oct_general_medium_small_width_no_precision){
        RUN_TEST("%1ho", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_oct_general_medium_neg_small_width_no_precision){
        RUN_TEST("%1ho", (unsigned short)-2000000001u)} END_TEST
    START_TEST(unsigned_short_null_small_width_small_precision){
        RUN_TEST("%1.3hu", (unsigned short)0u)} END_TEST
    START_TEST(unsigned_short_general_short_small_width_small_precision){
        RUN_TEST("%1.3hu", (unsigned short)8192u)} END_TEST
    START_TEST(unsigned_short_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3hu", (unsigned short)-8192u)} END_TEST
    START_TEST(unsigned_short_general_medium_small_width_small_precision){
        RUN_TEST("%1.3hu", (unsigned short)2000000001u)} END_TEST
    START_TEST(unsigned_short_general_medium_neg_small_width_small_precision){
        RUN_TEST("%1.3hu", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_hex_null_small_width_small_precision){
        RUN_TEST("%1.3hx", (unsigned short)0u)} END_TEST
    START_TEST(short_hex_general_short_small_width_small_precision){
        RUN_TEST("%1.3hx", (unsigned short)8192u)} END_TEST
    START_TEST(short_hex_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3hx", (unsigned short)-8192u)} END_TEST
    START_TEST(short_hex_general_medium_small_width_small_precision){
        RUN_TEST("%1.3hx", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_hex_general_medium_neg_small_width_small_precision){
        RUN_TEST("%1.3hx", (unsigned short)-2000000001u)} END_TEST
    START_TEST(SHORT_HEX_null_small_width_small_precision){
        RUN_TEST("%1.3hX", (unsigned short)0u)} END_TEST
    START_TEST(SHORT_HEX_general_short_small_width_small_precision){
        RUN_TEST("%1.3hX", (unsigned short)8192u)} END_TEST
    START_TEST(SHORT_HEX_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3hX", (unsigned short)-8192u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_small_width_small_precision){
        RUN_TEST("%1.3hX", (unsigned short)2000000001u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_neg_small_width_small_precision){
        RUN_TEST("%1.3hX", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_oct_null_small_width_small_precision){
        RUN_TEST("%1.3ho", (unsigned short)0u)} END_TEST
    START_TEST(short_oct_general_short_small_width_small_precision){
        RUN_TEST("%1.3ho", (unsigned short)8192u)} END_TEST
    START_TEST(short_oct_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3ho", (unsigned short)-8192u)} END_TEST
    START_TEST(short_oct_general_medium_small_width_small_precision){
        RUN_TEST("%1.3ho", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_oct_general_medium_neg_small_width_small_precision){
        RUN_TEST("%1.3ho", (unsigned short)-2000000001u)} END_TEST
    START_TEST(unsigned_short_null_small_width_big_precision){
        RUN_TEST("%1.14hu", (unsigned short)0u)} END_TEST
    START_TEST(unsigned_short_general_short_small_width_big_precision){
        RUN_TEST("%1.14hu", (unsigned short)8192u)} END_TEST
    START_TEST(unsigned_short_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14hu", (unsigned short)-8192u)} END_TEST
    START_TEST(unsigned_short_general_medium_small_width_big_precision){
        RUN_TEST("%1.14hu", (unsigned short)2000000001u)} END_TEST
    START_TEST(unsigned_short_general_medium_neg_small_width_big_precision){
        RUN_TEST("%1.14hu", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_hex_null_small_width_big_precision){
        RUN_TEST("%1.14hx", (unsigned short)0u)} END_TEST
    START_TEST(short_hex_general_short_small_width_big_precision){
        RUN_TEST("%1.14hx", (unsigned short)8192u)} END_TEST
    START_TEST(short_hex_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14hx", (unsigned short)-8192u)} END_TEST
    START_TEST(short_hex_general_medium_small_width_big_precision){
        RUN_TEST("%1.14hx", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_hex_general_medium_neg_small_width_big_precision){
        RUN_TEST("%1.14hx", (unsigned short)-2000000001u)} END_TEST
    START_TEST(SHORT_HEX_null_small_width_big_precision){
        RUN_TEST("%1.14hX", (unsigned short)0u)} END_TEST
    START_TEST(SHORT_HEX_general_short_small_width_big_precision){
        RUN_TEST("%1.14hX", (unsigned short)8192u)} END_TEST
    START_TEST(SHORT_HEX_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14hX", (unsigned short)-8192u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_small_width_big_precision){
        RUN_TEST("%1.14hX", (unsigned short)2000000001u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_neg_small_width_big_precision){
        RUN_TEST("%1.14hX", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_oct_null_small_width_big_precision){
        RUN_TEST("%1.14ho", (unsigned short)0u)} END_TEST
    START_TEST(short_oct_general_short_small_width_big_precision){
        RUN_TEST("%1.14ho", (unsigned short)8192u)} END_TEST
    START_TEST(short_oct_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14ho", (unsigned short)-8192u)} END_TEST
    START_TEST(short_oct_general_medium_small_width_big_precision){
        RUN_TEST("%1.14ho", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_oct_general_medium_neg_small_width_big_precision){
        RUN_TEST("%1.14ho", (unsigned short)-2000000001u)} END_TEST
    START_TEST(unsigned_short_null_big_width_no_precision){
        RUN_TEST("%50hu", (unsigned short)0u)} END_TEST
    START_TEST(unsigned_short_general_short_big_width_no_precision){
        RUN_TEST("%50hu", (unsigned short)8192u)} END_TEST
    START_TEST(unsigned_short_general_short_neg_big_width_no_precision){
        RUN_TEST("%50hu", (unsigned short)-8192u)} END_TEST
    START_TEST(unsigned_short_general_medium_big_width_no_precision){
        RUN_TEST("%50hu", (unsigned short)2000000001u)} END_TEST
    START_TEST(unsigned_short_general_medium_neg_big_width_no_precision){
        RUN_TEST("%50hu", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_hex_null_big_width_no_precision){
        RUN_TEST("%50hx", (unsigned short)0u)} END_TEST
    START_TEST(short_hex_general_short_big_width_no_precision){
        RUN_TEST("%50hx", (unsigned short)8192u)} END_TEST
    START_TEST(short_hex_general_short_neg_big_width_no_precision){
        RUN_TEST("%50hx", (unsigned short)-8192u)} END_TEST
    START_TEST(short_hex_general_medium_big_width_no_precision){
        RUN_TEST("%50hx", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_hex_general_medium_neg_big_width_no_precision){
        RUN_TEST("%50hx", (unsigned short)-2000000001u)} END_TEST
    START_TEST(SHORT_HEX_null_big_width_no_precision){
        RUN_TEST("%50hX", (unsigned short)0u)} END_TEST
    START_TEST(SHORT_HEX_general_short_big_width_no_precision){
        RUN_TEST("%50hX", (unsigned short)8192u)} END_TEST
    START_TEST(SHORT_HEX_general_short_neg_big_width_no_precision){
        RUN_TEST("%50hX", (unsigned short)-8192u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_big_width_no_precision){
        RUN_TEST("%50hX", (unsigned short)2000000001u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_neg_big_width_no_precision){
        RUN_TEST("%50hX", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_oct_null_big_width_no_precision){
        RUN_TEST("%50ho", (unsigned short)0u)} END_TEST
    START_TEST(short_oct_general_short_big_width_no_precision){
        RUN_TEST("%50ho", (unsigned short)8192u)} END_TEST
    START_TEST(short_oct_general_short_neg_big_width_no_precision){
        RUN_TEST("%50ho", (unsigned short)-8192u)} END_TEST
    START_TEST(short_oct_general_medium_big_width_no_precision){
        RUN_TEST("%50ho", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_oct_general_medium_neg_big_width_no_precision){
        RUN_TEST("%50ho", (unsigned short)-2000000001u)} END_TEST
    START_TEST(unsigned_short_null_big_width_small_precision){
        RUN_TEST("%50.3hu", (unsigned short)0u)} END_TEST
    START_TEST(unsigned_short_general_short_big_width_small_precision){
        RUN_TEST("%50.3hu", (unsigned short)8192u)} END_TEST
    START_TEST(unsigned_short_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3hu", (unsigned short)-8192u)} END_TEST
    START_TEST(unsigned_short_general_medium_big_width_small_precision){
        RUN_TEST("%50.3hu", (unsigned short)2000000001u)} END_TEST
    START_TEST(unsigned_short_general_medium_neg_big_width_small_precision){
        RUN_TEST("%50.3hu", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_hex_null_big_width_small_precision){
        RUN_TEST("%50.3hx", (unsigned short)0u)} END_TEST
    START_TEST(short_hex_general_short_big_width_small_precision){
        RUN_TEST("%50.3hx", (unsigned short)8192u)} END_TEST
    START_TEST(short_hex_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3hx", (unsigned short)-8192u)} END_TEST
    START_TEST(short_hex_general_medium_big_width_small_precision){
        RUN_TEST("%50.3hx", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_hex_general_medium_neg_big_width_small_precision){
        RUN_TEST("%50.3hx", (unsigned short)-2000000001u)} END_TEST
    START_TEST(SHORT_HEX_null_big_width_small_precision){
        RUN_TEST("%50.3hX", (unsigned short)0u)} END_TEST
    START_TEST(SHORT_HEX_general_short_big_width_small_precision){
        RUN_TEST("%50.3hX", (unsigned short)8192u)} END_TEST
    START_TEST(SHORT_HEX_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3hX", (unsigned short)-8192u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_big_width_small_precision){
        RUN_TEST("%50.3hX", (unsigned short)2000000001u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_neg_big_width_small_precision){
        RUN_TEST("%50.3hX", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_oct_null_big_width_small_precision){
        RUN_TEST("%50.3ho", (unsigned short)0u)} END_TEST
    START_TEST(short_oct_general_short_big_width_small_precision){
        RUN_TEST("%50.3ho", (unsigned short)8192u)} END_TEST
    START_TEST(short_oct_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3ho", (unsigned short)-8192u)} END_TEST
    START_TEST(short_oct_general_medium_big_width_small_precision){
        RUN_TEST("%50.3ho", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_oct_general_medium_neg_big_width_small_precision){
        RUN_TEST("%50.3ho", (unsigned short)-2000000001u)} END_TEST
    START_TEST(unsigned_short_null_big_width_big_precision){
        RUN_TEST("%50.14hu", (unsigned short)0u)} END_TEST
    START_TEST(unsigned_short_general_short_big_width_big_precision){
        RUN_TEST("%50.14hu", (unsigned short)8192u)} END_TEST
    START_TEST(unsigned_short_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14hu", (unsigned short)-8192u)} END_TEST
    START_TEST(unsigned_short_general_medium_big_width_big_precision){
        RUN_TEST("%50.14hu", (unsigned short)2000000001u)} END_TEST
    START_TEST(unsigned_short_general_medium_neg_big_width_big_precision){
        RUN_TEST("%50.14hu", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_hex_null_big_width_big_precision){
        RUN_TEST("%50.14hx", (unsigned short)0u)} END_TEST
    START_TEST(short_hex_general_short_big_width_big_precision){
        RUN_TEST("%50.14hx", (unsigned short)8192u)} END_TEST
    START_TEST(short_hex_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14hx", (unsigned short)-8192u)} END_TEST
    START_TEST(short_hex_general_medium_big_width_big_precision){
        RUN_TEST("%50.14hx", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_hex_general_medium_neg_big_width_big_precision){
        RUN_TEST("%50.14hx", (unsigned short)-2000000001u)} END_TEST
    START_TEST(SHORT_HEX_null_big_width_big_precision){
        RUN_TEST("%50.14hX", (unsigned short)0u)} END_TEST
    START_TEST(SHORT_HEX_general_short_big_width_big_precision){
        RUN_TEST("%50.14hX", (unsigned short)8192u)} END_TEST
    START_TEST(SHORT_HEX_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14hX", (unsigned short)-8192u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_big_width_big_precision){
        RUN_TEST("%50.14hX", (unsigned short)2000000001u)} END_TEST
    START_TEST(SHORT_HEX_general_medium_neg_big_width_big_precision){
        RUN_TEST("%50.14hX", (unsigned short)-2000000001u)} END_TEST
    START_TEST(short_oct_null_big_width_big_precision){
        RUN_TEST("%50.14ho", (unsigned short)0u)} END_TEST
    START_TEST(short_oct_general_short_big_width_big_precision){
        RUN_TEST("%50.14ho", (unsigned short)8192u)} END_TEST
    START_TEST(short_oct_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14ho", (unsigned short)-8192u)} END_TEST
    START_TEST(short_oct_general_medium_big_width_big_precision){
        RUN_TEST("%50.14ho", (unsigned short)2000000001u)} END_TEST
    START_TEST(short_oct_general_medium_neg_big_width_big_precision){
        RUN_TEST("%50.14ho", (unsigned short)-2000000001u)} END_TEST

    START_TEST(int_null_no_flags){RUN_TEST("%d", 0)} END_TEST
    START_TEST(int_general_short_no_flags){RUN_TEST("%d", 8192)} END_TEST
    START_TEST(int_general_short_neg_no_flags){RUN_TEST("%d", -8192)} END_TEST
    START_TEST(int_general_medium_no_flags){RUN_TEST("%d", 2000000001)} END_TEST
    START_TEST(int_general_medium_neg_no_flags){
        RUN_TEST("%d", -2000000001)} END_TEST
    START_TEST(alt_int_null_no_flags){RUN_TEST("%i", 0)} END_TEST
    START_TEST(alt_int_general_short_no_flags){RUN_TEST("%i", 8192)} END_TEST
    START_TEST(alt_int_general_short_neg_no_flags){
        RUN_TEST("%i", -8192)} END_TEST
    START_TEST(alt_int_general_medium_no_flags){
        RUN_TEST("%i", 2000000001)} END_TEST
    START_TEST(alt_int_general_medium_neg_no_flags){
        RUN_TEST("%i", -2000000001)} END_TEST
    START_TEST(unsigned_null_no_flags){RUN_TEST("%u", 0u)} END_TEST
    START_TEST(unsigned_general_short_no_flags){RUN_TEST("%u", 8192u)} END_TEST
    START_TEST(unsigned_general_short_neg_no_flags){
        RUN_TEST("%u", -8192u)} END_TEST
    START_TEST(unsigned_general_medium_no_flags){
        RUN_TEST("%u", 2000000001u)} END_TEST
    START_TEST(unsigned_general_medium_neg_no_flags){
        RUN_TEST("%u", -2000000001u)} END_TEST
    START_TEST(hex_null_no_flags){RUN_TEST("%x", 0u)} END_TEST
    START_TEST(hex_general_short_no_flags){RUN_TEST("%x", 8192u)} END_TEST
    START_TEST(hex_general_short_neg_no_flags){RUN_TEST("%x", -8192u)} END_TEST
    START_TEST(hex_general_medium_no_flags){
        RUN_TEST("%x", 2000000001u)} END_TEST
    START_TEST(hex_general_medium_neg_no_flags){
        RUN_TEST("%x", -2000000001u)} END_TEST
    START_TEST(HEX_null_no_flags){RUN_TEST("%X", 0u)} END_TEST
    START_TEST(HEX_general_short_no_flags){RUN_TEST("%X", 8192u)} END_TEST
    START_TEST(HEX_general_short_neg_no_flags){RUN_TEST("%X", -8192u)} END_TEST
    START_TEST(HEX_general_medium_no_flags){
        RUN_TEST("%X", 2000000001u)} END_TEST
    START_TEST(HEX_general_medium_neg_no_flags){
        RUN_TEST("%X", -2000000001u)} END_TEST
    START_TEST(oct_null_no_flags){RUN_TEST("%o", 0u)} END_TEST
    START_TEST(oct_general_short_no_flags){RUN_TEST("%o", 8192u)} END_TEST
    START_TEST(oct_general_short_neg_no_flags){RUN_TEST("%o", -8192u)} END_TEST
    START_TEST(oct_general_medium_no_flags){
        RUN_TEST("%o", 2000000001u)} END_TEST
    START_TEST(oct_general_medium_neg_no_flags){
        RUN_TEST("%o", -2000000001u)} END_TEST
    START_TEST(int_null_prefix_sign){RUN_TEST("%+d", 0)} END_TEST
    START_TEST(int_general_short_prefix_sign){RUN_TEST("%+d", 8192)} END_TEST
    START_TEST(int_general_short_neg_prefix_sign){
        RUN_TEST("%+d", -8192)} END_TEST
    START_TEST(int_general_medium_prefix_sign){
        RUN_TEST("%+d", 2000000001)} END_TEST
    START_TEST(int_general_medium_neg_prefix_sign){
        RUN_TEST("%+d", -2000000001)} END_TEST
    START_TEST(alt_int_null_prefix_sign){RUN_TEST("%+i", 0)} END_TEST
    START_TEST(alt_int_general_short_prefix_sign){
        RUN_TEST("%+i", 8192)} END_TEST
    START_TEST(alt_int_general_short_neg_prefix_sign){
        RUN_TEST("%+i", -8192)} END_TEST
    START_TEST(alt_int_general_medium_prefix_sign){
        RUN_TEST("%+i", 2000000001)} END_TEST
    START_TEST(alt_int_general_medium_neg_prefix_sign){
        RUN_TEST("%+i", -2000000001)} END_TEST
    START_TEST(unsigned_null_prefix_sign){RUN_TEST("%+u", 0u)} END_TEST
    START_TEST(unsigned_general_short_prefix_sign){
        RUN_TEST("%+u", 8192u)} END_TEST
    START_TEST(unsigned_general_short_neg_prefix_sign){
        RUN_TEST("%+u", -8192u)} END_TEST
    START_TEST(unsigned_general_medium_prefix_sign){
        RUN_TEST("%+u", 2000000001u)} END_TEST
    START_TEST(unsigned_general_medium_neg_prefix_sign){
        RUN_TEST("%+u", -2000000001u)} END_TEST
    START_TEST(hex_null_prefix_sign){RUN_TEST("%+x", 0u)} END_TEST
    START_TEST(hex_general_short_prefix_sign){RUN_TEST("%+x", 8192u)} END_TEST
    START_TEST(hex_general_short_neg_prefix_sign){
        RUN_TEST("%+x", -8192u)} END_TEST
    START_TEST(hex_general_medium_prefix_sign){
        RUN_TEST("%+x", 2000000001u)} END_TEST
    START_TEST(hex_general_medium_neg_prefix_sign){
        RUN_TEST("%+x", -2000000001u)} END_TEST
    START_TEST(HEX_null_prefix_sign){RUN_TEST("%+X", 0u)} END_TEST
    START_TEST(HEX_general_short_prefix_sign){RUN_TEST("%+X", 8192u)} END_TEST
    START_TEST(HEX_general_short_neg_prefix_sign){
        RUN_TEST("%+X", -8192u)} END_TEST
    START_TEST(HEX_general_medium_prefix_sign){
        RUN_TEST("%+X", 2000000001u)} END_TEST
    START_TEST(HEX_general_medium_neg_prefix_sign){
        RUN_TEST("%+X", -2000000001u)} END_TEST
    START_TEST(oct_null_prefix_sign){RUN_TEST("%+o", 0u)} END_TEST
    START_TEST(oct_general_short_prefix_sign){RUN_TEST("%+o", 8192u)} END_TEST
    START_TEST(oct_general_short_neg_prefix_sign){
        RUN_TEST("%+o", -8192u)} END_TEST
    START_TEST(oct_general_medium_prefix_sign){
        RUN_TEST("%+o", 2000000001u)} END_TEST
    START_TEST(oct_general_medium_neg_prefix_sign){
        RUN_TEST("%+o", -2000000001u)} END_TEST
    START_TEST(int_null_prefix_space){RUN_TEST("% d", 0)} END_TEST
    START_TEST(int_general_short_prefix_space){RUN_TEST("% d", 8192)} END_TEST
    START_TEST(int_general_short_neg_prefix_space){
        RUN_TEST("% d", -8192)} END_TEST
    START_TEST(int_general_medium_prefix_space){
        RUN_TEST("% d", 2000000001)} END_TEST
    START_TEST(int_general_medium_neg_prefix_space){
        RUN_TEST("% d", -2000000001)} END_TEST
    START_TEST(alt_int_null_prefix_space){RUN_TEST("% i", 0)} END_TEST
    START_TEST(alt_int_general_short_prefix_space){
        RUN_TEST("% i", 8192)} END_TEST
    START_TEST(alt_int_general_short_neg_prefix_space){
        RUN_TEST("% i", -8192)} END_TEST
    START_TEST(alt_int_general_medium_prefix_space){
        RUN_TEST("% i", 2000000001)} END_TEST
    START_TEST(alt_int_general_medium_neg_prefix_space){
        RUN_TEST("% i", -2000000001)} END_TEST
    START_TEST(unsigned_null_prefix_space){RUN_TEST("% u", 0u)} END_TEST
    START_TEST(unsigned_general_short_prefix_space){
        RUN_TEST("% u", 8192u)} END_TEST
    START_TEST(unsigned_general_short_neg_prefix_space){
        RUN_TEST("% u", -8192u)} END_TEST
    START_TEST(unsigned_general_medium_prefix_space){
        RUN_TEST("% u", 2000000001u)} END_TEST
    START_TEST(unsigned_general_medium_neg_prefix_space){
        RUN_TEST("% u", -2000000001u)} END_TEST
    START_TEST(hex_null_prefix_space){RUN_TEST("% x", 0u)} END_TEST
    START_TEST(hex_general_short_prefix_space){RUN_TEST("% x", 8192u)} END_TEST
    START_TEST(hex_general_short_neg_prefix_space){
        RUN_TEST("% x", -8192u)} END_TEST
    START_TEST(hex_general_medium_prefix_space){
        RUN_TEST("% x", 2000000001u)} END_TEST
    START_TEST(hex_general_medium_neg_prefix_space){
        RUN_TEST("% x", -2000000001u)} END_TEST
    START_TEST(HEX_null_prefix_space){RUN_TEST("% X", 0u)} END_TEST
    START_TEST(HEX_general_short_prefix_space){RUN_TEST("% X", 8192u)} END_TEST
    START_TEST(HEX_general_short_neg_prefix_space){
        RUN_TEST("% X", -8192u)} END_TEST
    START_TEST(HEX_general_medium_prefix_space){
        RUN_TEST("% X", 2000000001u)} END_TEST
    START_TEST(HEX_general_medium_neg_prefix_space){
        RUN_TEST("% X", -2000000001u)} END_TEST
    START_TEST(oct_null_prefix_space){RUN_TEST("% o", 0u)} END_TEST
    START_TEST(oct_general_short_prefix_space){RUN_TEST("% o", 8192u)} END_TEST
    START_TEST(oct_general_short_neg_prefix_space){
        RUN_TEST("% o", -8192u)} END_TEST
    START_TEST(oct_general_medium_prefix_space){
        RUN_TEST("% o", 2000000001u)} END_TEST
    START_TEST(oct_general_medium_neg_prefix_space){
        RUN_TEST("% o", -2000000001u)} END_TEST
    START_TEST(int_null_left_alignment){RUN_TEST("%-d", 0)} END_TEST
    START_TEST(int_general_short_left_alignment){RUN_TEST("%-d", 8192)} END_TEST
    START_TEST(int_general_short_neg_left_alignment){
        RUN_TEST("%-d", -8192)} END_TEST
    START_TEST(int_general_medium_left_alignment){
        RUN_TEST("%-d", 2000000001)} END_TEST
    START_TEST(int_general_medium_neg_left_alignment){
        RUN_TEST("%-d", -2000000001)} END_TEST
    START_TEST(alt_int_null_left_alignment){RUN_TEST("%-i", 0)} END_TEST
    START_TEST(alt_int_general_short_left_alignment){
        RUN_TEST("%-i", 8192)} END_TEST
    START_TEST(alt_int_general_short_neg_left_alignment){
        RUN_TEST("%-i", -8192)} END_TEST
    START_TEST(alt_int_general_medium_left_alignment){
        RUN_TEST("%-i", 2000000001)} END_TEST
    START_TEST(alt_int_general_medium_neg_left_alignment){
        RUN_TEST("%-i", -2000000001)} END_TEST
    START_TEST(unsigned_null_left_alignment){RUN_TEST("%-u", 0u)} END_TEST
    START_TEST(unsigned_general_short_left_alignment){
        RUN_TEST("%-u", 8192u)} END_TEST
    START_TEST(unsigned_general_short_neg_left_alignment){
        RUN_TEST("%-u", -8192u)} END_TEST
    START_TEST(unsigned_general_medium_left_alignment){
        RUN_TEST("%-u", 2000000001u)} END_TEST
    START_TEST(unsigned_general_medium_neg_left_alignment){
        RUN_TEST("%-u", -2000000001u)} END_TEST
    START_TEST(hex_null_left_alignment){RUN_TEST("%-x", 0u)} END_TEST
    START_TEST(hex_general_short_left_alignment){
        RUN_TEST("%-x", 8192u)} END_TEST
    START_TEST(hex_general_short_neg_left_alignment){
        RUN_TEST("%-x", -8192u)} END_TEST
    START_TEST(hex_general_medium_left_alignment){
        RUN_TEST("%-x", 2000000001u)} END_TEST
    START_TEST(hex_general_medium_neg_left_alignment){
        RUN_TEST("%-x", -2000000001u)} END_TEST
    START_TEST(HEX_null_left_alignment){RUN_TEST("%-X", 0u)} END_TEST
    START_TEST(HEX_general_short_left_alignment){
        RUN_TEST("%-X", 8192u)} END_TEST
    START_TEST(HEX_general_short_neg_left_alignment){
        RUN_TEST("%-X", -8192u)} END_TEST
    START_TEST(HEX_general_medium_left_alignment){
        RUN_TEST("%-X", 2000000001u)} END_TEST
    START_TEST(HEX_general_medium_neg_left_alignment){
        RUN_TEST("%-X", -2000000001u)} END_TEST
    START_TEST(oct_null_left_alignment){RUN_TEST("%-o", 0u)} END_TEST
    START_TEST(oct_general_short_left_alignment){
        RUN_TEST("%-o", 8192u)} END_TEST
    START_TEST(oct_general_short_neg_left_alignment){
        RUN_TEST("%-o", -8192u)} END_TEST
    START_TEST(oct_general_medium_left_alignment){
        RUN_TEST("%-o", 2000000001u)} END_TEST
    START_TEST(oct_general_medium_neg_left_alignment){
        RUN_TEST("%-o", -2000000001u)} END_TEST
    START_TEST(int_null_leading_zeroes){RUN_TEST("%0d", 0)} END_TEST
    START_TEST(int_general_short_leading_zeroes){RUN_TEST("%0d", 8192)} END_TEST
    START_TEST(int_general_short_neg_leading_zeroes){
        RUN_TEST("%0d", -8192)} END_TEST
    START_TEST(int_general_medium_leading_zeroes){
        RUN_TEST("%0d", 2000000001)} END_TEST
    START_TEST(int_general_medium_neg_leading_zeroes){
        RUN_TEST("%0d", -2000000001)} END_TEST
    START_TEST(alt_int_null_leading_zeroes){RUN_TEST("%0i", 0)} END_TEST
    START_TEST(alt_int_general_short_leading_zeroes){
        RUN_TEST("%0i", 8192)} END_TEST
    START_TEST(alt_int_general_short_neg_leading_zeroes){
        RUN_TEST("%0i", -8192)} END_TEST
    START_TEST(alt_int_general_medium_leading_zeroes){
        RUN_TEST("%0i", 2000000001)} END_TEST
    START_TEST(alt_int_general_medium_neg_leading_zeroes){
        RUN_TEST("%0i", -2000000001)} END_TEST
    START_TEST(unsigned_null_leading_zeroes){RUN_TEST("%0u", 0u)} END_TEST
    START_TEST(unsigned_general_short_leading_zeroes){
        RUN_TEST("%0u", 8192u)} END_TEST
    START_TEST(unsigned_general_short_neg_leading_zeroes){
        RUN_TEST("%0u", -8192u)} END_TEST
    START_TEST(unsigned_general_medium_leading_zeroes){
        RUN_TEST("%0u", 2000000001u)} END_TEST
    START_TEST(unsigned_general_medium_neg_leading_zeroes){
        RUN_TEST("%0u", -2000000001u)} END_TEST
    START_TEST(hex_null_leading_zeroes){RUN_TEST("%0x", 0u)} END_TEST
    START_TEST(hex_general_short_leading_zeroes){
        RUN_TEST("%0x", 8192u)} END_TEST
    START_TEST(hex_general_short_neg_leading_zeroes){
        RUN_TEST("%0x", -8192u)} END_TEST
    START_TEST(hex_general_medium_leading_zeroes){
        RUN_TEST("%0x", 2000000001u)} END_TEST
    START_TEST(hex_general_medium_neg_leading_zeroes){
        RUN_TEST("%0x", -2000000001u)} END_TEST
    START_TEST(HEX_null_leading_zeroes){RUN_TEST("%0X", 0u)} END_TEST
    START_TEST(HEX_general_short_leading_zeroes){
        RUN_TEST("%0X", 8192u)} END_TEST
    START_TEST(HEX_general_short_neg_leading_zeroes){
        RUN_TEST("%0X", -8192u)} END_TEST
    START_TEST(HEX_general_medium_leading_zeroes){
        RUN_TEST("%0X", 2000000001u)} END_TEST
    START_TEST(HEX_general_medium_neg_leading_zeroes){
        RUN_TEST("%0X", -2000000001u)} END_TEST
    START_TEST(oct_null_leading_zeroes){RUN_TEST("%0o", 0u)} END_TEST
    START_TEST(oct_general_short_leading_zeroes){
        RUN_TEST("%0o", 8192u)} END_TEST
    START_TEST(oct_general_short_neg_leading_zeroes){
        RUN_TEST("%0o", -8192u)} END_TEST
    START_TEST(oct_general_medium_leading_zeroes){
        RUN_TEST("%0o", 2000000001u)} END_TEST
    START_TEST(oct_general_medium_neg_leading_zeroes){
        RUN_TEST("%0o", -2000000001u)} END_TEST
    START_TEST(int_null_alt_format){RUN_TEST("%#d", 0)} END_TEST
    START_TEST(int_general_short_alt_format){RUN_TEST("%#d", 8192)} END_TEST
    START_TEST(int_general_short_neg_alt_format){
        RUN_TEST("%#d", -8192)} END_TEST
    START_TEST(int_general_medium_alt_format){
        RUN_TEST("%#d", 2000000001)} END_TEST
    START_TEST(int_general_medium_neg_alt_format){
        RUN_TEST("%#d", -2000000001)} END_TEST
    START_TEST(alt_int_null_alt_format){RUN_TEST("%#i", 0)} END_TEST
    START_TEST(alt_int_general_short_alt_format){RUN_TEST("%#i", 8192)} END_TEST
    START_TEST(alt_int_general_short_neg_alt_format){
        RUN_TEST("%#i", -8192)} END_TEST
    START_TEST(alt_int_general_medium_alt_format){
        RUN_TEST("%#i", 2000000001)} END_TEST
    START_TEST(alt_int_general_medium_neg_alt_format){
        RUN_TEST("%#i", -2000000001)} END_TEST
    START_TEST(unsigned_null_alt_format){RUN_TEST("%#u", 0u)} END_TEST
    START_TEST(unsigned_general_short_alt_format){
        RUN_TEST("%#u", 8192u)} END_TEST
    START_TEST(unsigned_general_short_neg_alt_format){
        RUN_TEST("%#u", -8192u)} END_TEST
    START_TEST(unsigned_general_medium_alt_format){
        RUN_TEST("%#u", 2000000001u)} END_TEST
    START_TEST(unsigned_general_medium_neg_alt_format){
        RUN_TEST("%#u", -2000000001u)} END_TEST
    START_TEST(hex_null_alt_format){RUN_TEST("%#x", 0u)} END_TEST
    START_TEST(hex_general_short_alt_format){RUN_TEST("%#x", 8192u)} END_TEST
    START_TEST(hex_general_short_neg_alt_format){
        RUN_TEST("%#x", -8192u)} END_TEST
    START_TEST(hex_general_medium_alt_format){
        RUN_TEST("%#x", 2000000001u)} END_TEST
    START_TEST(hex_general_medium_neg_alt_format){
        RUN_TEST("%#x", -2000000001u)} END_TEST
    START_TEST(HEX_null_alt_format){RUN_TEST("%#X", 0u)} END_TEST
    START_TEST(HEX_general_short_alt_format){RUN_TEST("%#X", 8192u)} END_TEST
    START_TEST(HEX_general_short_neg_alt_format){
        RUN_TEST("%#X", -8192u)} END_TEST
    START_TEST(HEX_general_medium_alt_format){
        RUN_TEST("%#X", 2000000001u)} END_TEST
    START_TEST(HEX_general_medium_neg_alt_format){
        RUN_TEST("%#X", -2000000001u)} END_TEST
    START_TEST(oct_null_alt_format){RUN_TEST("%#o", 0u)} END_TEST
    START_TEST(oct_general_short_alt_format){RUN_TEST("%#o", 8192u)} END_TEST
    START_TEST(oct_general_short_neg_alt_format){
        RUN_TEST("%#o", -8192u)} END_TEST
    START_TEST(oct_general_medium_alt_format){
        RUN_TEST("%#o", 2000000001u)} END_TEST
    START_TEST(oct_general_medium_neg_alt_format){
        RUN_TEST("%#o", -2000000001u)} END_TEST
    START_TEST(int_null_no_width_no_precision){RUN_TEST("%d", 0)} END_TEST
    START_TEST(int_general_short_no_width_no_precision){
        RUN_TEST("%d", 8192)} END_TEST
    START_TEST(int_general_short_neg_no_width_no_precision){
        RUN_TEST("%d", -8192)} END_TEST
    START_TEST(int_general_medium_no_width_no_precision){
        RUN_TEST("%d", 2000000001)} END_TEST
    START_TEST(int_general_medium_neg_no_width_no_precision){
        RUN_TEST("%d", -2000000001)} END_TEST
    START_TEST(alt_int_null_no_width_no_precision){RUN_TEST("%i", 0)} END_TEST
    START_TEST(alt_int_general_short_no_width_no_precision){
        RUN_TEST("%i", 8192)} END_TEST
    START_TEST(alt_int_general_short_neg_no_width_no_precision){
        RUN_TEST("%i", -8192)} END_TEST
    START_TEST(alt_int_general_medium_no_width_no_precision){
        RUN_TEST("%i", 2000000001)} END_TEST
    START_TEST(alt_int_general_medium_neg_no_width_no_precision){
        RUN_TEST("%i", -2000000001)} END_TEST
    START_TEST(unsigned_null_no_width_no_precision){RUN_TEST("%u", 0u)} END_TEST
    START_TEST(unsigned_general_short_no_width_no_precision){
        RUN_TEST("%u", 8192u)} END_TEST
    START_TEST(unsigned_general_short_neg_no_width_no_precision){
        RUN_TEST("%u", -8192u)} END_TEST
    START_TEST(unsigned_general_medium_no_width_no_precision){
        RUN_TEST("%u", 2000000001u)} END_TEST
    START_TEST(unsigned_general_medium_neg_no_width_no_precision){
        RUN_TEST("%u", -2000000001u)} END_TEST
    START_TEST(hex_null_no_width_no_precision){RUN_TEST("%x", 0u)} END_TEST
    START_TEST(hex_general_short_no_width_no_precision){
        RUN_TEST("%x", 8192u)} END_TEST
    START_TEST(hex_general_short_neg_no_width_no_precision){
        RUN_TEST("%x", -8192u)} END_TEST
    START_TEST(hex_general_medium_no_width_no_precision){
        RUN_TEST("%x", 2000000001u)} END_TEST
    START_TEST(hex_general_medium_neg_no_width_no_precision){
        RUN_TEST("%x", -2000000001u)} END_TEST
    START_TEST(HEX_null_no_width_no_precision){RUN_TEST("%X", 0u)} END_TEST
    START_TEST(HEX_general_short_no_width_no_precision){
        RUN_TEST("%X", 8192u)} END_TEST
    START_TEST(HEX_general_short_neg_no_width_no_precision){
        RUN_TEST("%X", -8192u)} END_TEST
    START_TEST(HEX_general_medium_no_width_no_precision){
        RUN_TEST("%X", 2000000001u)} END_TEST
    START_TEST(HEX_general_medium_neg_no_width_no_precision){
        RUN_TEST("%X", -2000000001u)} END_TEST
    START_TEST(oct_null_no_width_no_precision){RUN_TEST("%o", 0u)} END_TEST
    START_TEST(oct_general_short_no_width_no_precision){
        RUN_TEST("%o", 8192u)} END_TEST
    START_TEST(oct_general_short_neg_no_width_no_precision){
        RUN_TEST("%o", -8192u)} END_TEST
    START_TEST(oct_general_medium_no_width_no_precision){
        RUN_TEST("%o", 2000000001u)} END_TEST
    START_TEST(oct_general_medium_neg_no_width_no_precision){
        RUN_TEST("%o", -2000000001u)} END_TEST
    START_TEST(int_null_no_width_small_precision){RUN_TEST("%.3d", 0)} END_TEST
    START_TEST(int_general_short_no_width_small_precision){
        RUN_TEST("%.3d", 8192)} END_TEST
    START_TEST(int_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3d", -8192)} END_TEST
    START_TEST(int_general_medium_no_width_small_precision){
        RUN_TEST("%.3d", 2000000001)} END_TEST
    START_TEST(int_general_medium_neg_no_width_small_precision){
        RUN_TEST("%.3d", -2000000001)} END_TEST
    START_TEST(alt_int_null_no_width_small_precision){
        RUN_TEST("%.3i", 0)} END_TEST
    START_TEST(alt_int_general_short_no_width_small_precision){
        RUN_TEST("%.3i", 8192)} END_TEST
    START_TEST(alt_int_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3i", -8192)} END_TEST
    START_TEST(alt_int_general_medium_no_width_small_precision){
        RUN_TEST("%.3i", 2000000001)} END_TEST
    START_TEST(alt_int_general_medium_neg_no_width_small_precision){
        RUN_TEST("%.3i", -2000000001)} END_TEST
    START_TEST(unsigned_null_no_width_small_precision){
        RUN_TEST("%.3u", 0u)} END_TEST
    START_TEST(unsigned_general_short_no_width_small_precision){
        RUN_TEST("%.3u", 8192u)} END_TEST
    START_TEST(unsigned_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3u", -8192u)} END_TEST
    START_TEST(unsigned_general_medium_no_width_small_precision){
        RUN_TEST("%.3u", 2000000001u)} END_TEST
    START_TEST(unsigned_general_medium_neg_no_width_small_precision){
        RUN_TEST("%.3u", -2000000001u)} END_TEST
    START_TEST(hex_null_no_width_small_precision){RUN_TEST("%.3x", 0u)} END_TEST
    START_TEST(hex_general_short_no_width_small_precision){
        RUN_TEST("%.3x", 8192u)} END_TEST
    START_TEST(hex_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3x", -8192u)} END_TEST
    START_TEST(hex_general_medium_no_width_small_precision){
        RUN_TEST("%.3x", 2000000001u)} END_TEST
    START_TEST(hex_general_medium_neg_no_width_small_precision){
        RUN_TEST("%.3x", -2000000001u)} END_TEST
    START_TEST(HEX_null_no_width_small_precision){RUN_TEST("%.3X", 0u)} END_TEST
    START_TEST(HEX_general_short_no_width_small_precision){
        RUN_TEST("%.3X", 8192u)} END_TEST
    START_TEST(HEX_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3X", -8192u)} END_TEST
    START_TEST(HEX_general_medium_no_width_small_precision){
        RUN_TEST("%.3X", 2000000001u)} END_TEST
    START_TEST(HEX_general_medium_neg_no_width_small_precision){
        RUN_TEST("%.3X", -2000000001u)} END_TEST
    START_TEST(oct_null_no_width_small_precision){RUN_TEST("%.3o", 0u)} END_TEST
    START_TEST(oct_general_short_no_width_small_precision){
        RUN_TEST("%.3o", 8192u)} END_TEST
    START_TEST(oct_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3o", -8192u)} END_TEST
    START_TEST(oct_general_medium_no_width_small_precision){
        RUN_TEST("%.3o", 2000000001u)} END_TEST
    START_TEST(oct_general_medium_neg_no_width_small_precision){
        RUN_TEST("%.3o", -2000000001u)} END_TEST
    START_TEST(int_null_no_width_big_precision){RUN_TEST("%.14d", 0)} END_TEST
    START_TEST(int_general_short_no_width_big_precision){
        RUN_TEST("%.14d", 8192)} END_TEST
    START_TEST(int_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14d", -8192)} END_TEST
    START_TEST(int_general_medium_no_width_big_precision){
        RUN_TEST("%.14d", 2000000001)} END_TEST
    START_TEST(int_general_medium_neg_no_width_big_precision){
        RUN_TEST("%.14d", -2000000001)} END_TEST
    START_TEST(alt_int_null_no_width_big_precision){
        RUN_TEST("%.14i", 0)} END_TEST
    START_TEST(alt_int_general_short_no_width_big_precision){
        RUN_TEST("%.14i", 8192)} END_TEST
    START_TEST(alt_int_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14i", -8192)} END_TEST
    START_TEST(alt_int_general_medium_no_width_big_precision){
        RUN_TEST("%.14i", 2000000001)} END_TEST
    START_TEST(alt_int_general_medium_neg_no_width_big_precision){
        RUN_TEST("%.14i", -2000000001)} END_TEST
    START_TEST(unsigned_null_no_width_big_precision){
        RUN_TEST("%.14u", 0u)} END_TEST
    START_TEST(unsigned_general_short_no_width_big_precision){
        RUN_TEST("%.14u", 8192u)} END_TEST
    START_TEST(unsigned_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14u", -8192u)} END_TEST
    START_TEST(unsigned_general_medium_no_width_big_precision){
        RUN_TEST("%.14u", 2000000001u)} END_TEST
    START_TEST(unsigned_general_medium_neg_no_width_big_precision){
        RUN_TEST("%.14u", -2000000001u)} END_TEST
    START_TEST(hex_null_no_width_big_precision){RUN_TEST("%.14x", 0u)} END_TEST
    START_TEST(hex_general_short_no_width_big_precision){
        RUN_TEST("%.14x", 8192u)} END_TEST
    START_TEST(hex_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14x", -8192u)} END_TEST
    START_TEST(hex_general_medium_no_width_big_precision){
        RUN_TEST("%.14x", 2000000001u)} END_TEST
    START_TEST(hex_general_medium_neg_no_width_big_precision){
        RUN_TEST("%.14x", -2000000001u)} END_TEST
    START_TEST(HEX_null_no_width_big_precision){RUN_TEST("%.14X", 0u)} END_TEST
    START_TEST(HEX_general_short_no_width_big_precision){
        RUN_TEST("%.14X", 8192u)} END_TEST
    START_TEST(HEX_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14X", -8192u)} END_TEST
    START_TEST(HEX_general_medium_no_width_big_precision){
        RUN_TEST("%.14X", 2000000001u)} END_TEST
    START_TEST(HEX_general_medium_neg_no_width_big_precision){
        RUN_TEST("%.14X", -2000000001u)} END_TEST
    START_TEST(oct_null_no_width_big_precision){RUN_TEST("%.14o", 0u)} END_TEST
    START_TEST(oct_general_short_no_width_big_precision){
        RUN_TEST("%.14o", 8192u)} END_TEST
    START_TEST(oct_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14o", -8192u)} END_TEST
    START_TEST(oct_general_medium_no_width_big_precision){
        RUN_TEST("%.14o", 2000000001u)} END_TEST
    START_TEST(oct_general_medium_neg_no_width_big_precision){
        RUN_TEST("%.14o", -2000000001u)} END_TEST
    START_TEST(int_null_small_width_no_precision){RUN_TEST("%1d", 0)} END_TEST
    START_TEST(int_general_short_small_width_no_precision){
        RUN_TEST("%1d", 8192)} END_TEST
    START_TEST(int_general_short_neg_small_width_no_precision){
        RUN_TEST("%1d", -8192)} END_TEST
    START_TEST(int_general_medium_small_width_no_precision){
        RUN_TEST("%1d", 2000000001)} END_TEST
    START_TEST(int_general_medium_neg_small_width_no_precision){
        RUN_TEST("%1d", -2000000001)} END_TEST
    START_TEST(alt_int_null_small_width_no_precision){
        RUN_TEST("%1i", 0)} END_TEST
    START_TEST(alt_int_general_short_small_width_no_precision){
        RUN_TEST("%1i", 8192)} END_TEST
    START_TEST(alt_int_general_short_neg_small_width_no_precision){
        RUN_TEST("%1i", -8192)} END_TEST
    START_TEST(alt_int_general_medium_small_width_no_precision){
        RUN_TEST("%1i", 2000000001)} END_TEST
    START_TEST(alt_int_general_medium_neg_small_width_no_precision){
        RUN_TEST("%1i", -2000000001)} END_TEST
    START_TEST(unsigned_null_small_width_no_precision){
        RUN_TEST("%1u", 0u)} END_TEST
    START_TEST(unsigned_general_short_small_width_no_precision){
        RUN_TEST("%1u", 8192u)} END_TEST
    START_TEST(unsigned_general_short_neg_small_width_no_precision){
        RUN_TEST("%1u", -8192u)} END_TEST
    START_TEST(unsigned_general_medium_small_width_no_precision){
        RUN_TEST("%1u", 2000000001u)} END_TEST
    START_TEST(unsigned_general_medium_neg_small_width_no_precision){
        RUN_TEST("%1u", -2000000001u)} END_TEST
    START_TEST(hex_null_small_width_no_precision){RUN_TEST("%1x", 0u)} END_TEST
    START_TEST(hex_general_short_small_width_no_precision){
        RUN_TEST("%1x", 8192u)} END_TEST
    START_TEST(hex_general_short_neg_small_width_no_precision){
        RUN_TEST("%1x", -8192u)} END_TEST
    START_TEST(hex_general_medium_small_width_no_precision){
        RUN_TEST("%1x", 2000000001u)} END_TEST
    START_TEST(hex_general_medium_neg_small_width_no_precision){
        RUN_TEST("%1x", -2000000001u)} END_TEST
    START_TEST(HEX_null_small_width_no_precision){RUN_TEST("%1X", 0u)} END_TEST
    START_TEST(HEX_general_short_small_width_no_precision){
        RUN_TEST("%1X", 8192u)} END_TEST
    START_TEST(HEX_general_short_neg_small_width_no_precision){
        RUN_TEST("%1X", -8192u)} END_TEST
    START_TEST(HEX_general_medium_small_width_no_precision){
        RUN_TEST("%1X", 2000000001u)} END_TEST
    START_TEST(HEX_general_medium_neg_small_width_no_precision){
        RUN_TEST("%1X", -2000000001u)} END_TEST
    START_TEST(oct_null_small_width_no_precision){RUN_TEST("%1o", 0u)} END_TEST
    START_TEST(oct_general_short_small_width_no_precision){
        RUN_TEST("%1o", 8192u)} END_TEST
    START_TEST(oct_general_short_neg_small_width_no_precision){
        RUN_TEST("%1o", -8192u)} END_TEST
    START_TEST(oct_general_medium_small_width_no_precision){
        RUN_TEST("%1o", 2000000001u)} END_TEST
    START_TEST(oct_general_medium_neg_small_width_no_precision){
        RUN_TEST("%1o", -2000000001u)} END_TEST
    START_TEST(int_null_small_width_small_precision){
        RUN_TEST("%1.3d", 0)} END_TEST
    START_TEST(int_general_short_small_width_small_precision){
        RUN_TEST("%1.3d", 8192)} END_TEST
    START_TEST(int_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3d", -8192)} END_TEST
    START_TEST(int_general_medium_small_width_small_precision){
        RUN_TEST("%1.3d", 2000000001)} END_TEST
    START_TEST(int_general_medium_neg_small_width_small_precision){
        RUN_TEST("%1.3d", -2000000001)} END_TEST
    START_TEST(alt_int_null_small_width_small_precision){
        RUN_TEST("%1.3i", 0)} END_TEST
    START_TEST(alt_int_general_short_small_width_small_precision){
        RUN_TEST("%1.3i", 8192)} END_TEST
    START_TEST(alt_int_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3i", -8192)} END_TEST
    START_TEST(alt_int_general_medium_small_width_small_precision){
        RUN_TEST("%1.3i", 2000000001)} END_TEST
    START_TEST(alt_int_general_medium_neg_small_width_small_precision){
        RUN_TEST("%1.3i", -2000000001)} END_TEST
    START_TEST(unsigned_null_small_width_small_precision){
        RUN_TEST("%1.3u", 0u)} END_TEST
    START_TEST(unsigned_general_short_small_width_small_precision){
        RUN_TEST("%1.3u", 8192u)} END_TEST
    START_TEST(unsigned_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3u", -8192u)} END_TEST
    START_TEST(unsigned_general_medium_small_width_small_precision){
        RUN_TEST("%1.3u", 2000000001u)} END_TEST
    START_TEST(unsigned_general_medium_neg_small_width_small_precision){
        RUN_TEST("%1.3u", -2000000001u)} END_TEST
    START_TEST(hex_null_small_width_small_precision){
        RUN_TEST("%1.3x", 0u)} END_TEST
    START_TEST(hex_general_short_small_width_small_precision){
        RUN_TEST("%1.3x", 8192u)} END_TEST
    START_TEST(hex_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3x", -8192u)} END_TEST
    START_TEST(hex_general_medium_small_width_small_precision){
        RUN_TEST("%1.3x", 2000000001u)} END_TEST
    START_TEST(hex_general_medium_neg_small_width_small_precision){
        RUN_TEST("%1.3x", -2000000001u)} END_TEST
    START_TEST(HEX_null_small_width_small_precision){
        RUN_TEST("%1.3X", 0u)} END_TEST
    START_TEST(HEX_general_short_small_width_small_precision){
        RUN_TEST("%1.3X", 8192u)} END_TEST
    START_TEST(HEX_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3X", -8192u)} END_TEST
    START_TEST(HEX_general_medium_small_width_small_precision){
        RUN_TEST("%1.3X", 2000000001u)} END_TEST
    START_TEST(HEX_general_medium_neg_small_width_small_precision){
        RUN_TEST("%1.3X", -2000000001u)} END_TEST
    START_TEST(oct_null_small_width_small_precision){
        RUN_TEST("%1.3o", 0u)} END_TEST
    START_TEST(oct_general_short_small_width_small_precision){
        RUN_TEST("%1.3o", 8192u)} END_TEST
    START_TEST(oct_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3o", -8192u)} END_TEST
    START_TEST(oct_general_medium_small_width_small_precision){
        RUN_TEST("%1.3o", 2000000001u)} END_TEST
    START_TEST(oct_general_medium_neg_small_width_small_precision){
        RUN_TEST("%1.3o", -2000000001u)} END_TEST
    START_TEST(int_null_small_width_big_precision){
        RUN_TEST("%1.14d", 0)} END_TEST
    START_TEST(int_general_short_small_width_big_precision){
        RUN_TEST("%1.14d", 8192)} END_TEST
    START_TEST(int_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14d", -8192)} END_TEST
    START_TEST(int_general_medium_small_width_big_precision){
        RUN_TEST("%1.14d", 2000000001)} END_TEST
    START_TEST(int_general_medium_neg_small_width_big_precision){
        RUN_TEST("%1.14d", -2000000001)} END_TEST
    START_TEST(alt_int_null_small_width_big_precision){
        RUN_TEST("%1.14i", 0)} END_TEST
    START_TEST(alt_int_general_short_small_width_big_precision){
        RUN_TEST("%1.14i", 8192)} END_TEST
    START_TEST(alt_int_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14i", -8192)} END_TEST
    START_TEST(alt_int_general_medium_small_width_big_precision){
        RUN_TEST("%1.14i", 2000000001)} END_TEST
    START_TEST(alt_int_general_medium_neg_small_width_big_precision){
        RUN_TEST("%1.14i", -2000000001)} END_TEST
    START_TEST(unsigned_null_small_width_big_precision){
        RUN_TEST("%1.14u", 0u)} END_TEST
    START_TEST(unsigned_general_short_small_width_big_precision){
        RUN_TEST("%1.14u", 8192u)} END_TEST
    START_TEST(unsigned_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14u", -8192u)} END_TEST
    START_TEST(unsigned_general_medium_small_width_big_precision){
        RUN_TEST("%1.14u", 2000000001u)} END_TEST
    START_TEST(unsigned_general_medium_neg_small_width_big_precision){
        RUN_TEST("%1.14u", -2000000001u)} END_TEST
    START_TEST(hex_null_small_width_big_precision){
        RUN_TEST("%1.14x", 0u)} END_TEST
    START_TEST(hex_general_short_small_width_big_precision){
        RUN_TEST("%1.14x", 8192u)} END_TEST
    START_TEST(hex_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14x", -8192u)} END_TEST
    START_TEST(hex_general_medium_small_width_big_precision){
        RUN_TEST("%1.14x", 2000000001u)} END_TEST
    START_TEST(hex_general_medium_neg_small_width_big_precision){
        RUN_TEST("%1.14x", -2000000001u)} END_TEST
    START_TEST(HEX_null_small_width_big_precision){
        RUN_TEST("%1.14X", 0u)} END_TEST
    START_TEST(HEX_general_short_small_width_big_precision){
        RUN_TEST("%1.14X", 8192u)} END_TEST
    START_TEST(HEX_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14X", -8192u)} END_TEST
    START_TEST(HEX_general_medium_small_width_big_precision){
        RUN_TEST("%1.14X", 2000000001u)} END_TEST
    START_TEST(HEX_general_medium_neg_small_width_big_precision){
        RUN_TEST("%1.14X", -2000000001u)} END_TEST
    START_TEST(oct_null_small_width_big_precision){
        RUN_TEST("%1.14o", 0u)} END_TEST
    START_TEST(oct_general_short_small_width_big_precision){
        RUN_TEST("%1.14o", 8192u)} END_TEST
    START_TEST(oct_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14o", -8192u)} END_TEST
    START_TEST(oct_general_medium_small_width_big_precision){
        RUN_TEST("%1.14o", 2000000001u)} END_TEST
    START_TEST(oct_general_medium_neg_small_width_big_precision){
        RUN_TEST("%1.14o", -2000000001u)} END_TEST
    START_TEST(int_null_big_width_no_precision){RUN_TEST("%50d", 0)} END_TEST
    START_TEST(int_general_short_big_width_no_precision){
        RUN_TEST("%50d", 8192)} END_TEST
    START_TEST(int_general_short_neg_big_width_no_precision){
        RUN_TEST("%50d", -8192)} END_TEST
    START_TEST(int_general_medium_big_width_no_precision){
        RUN_TEST("%50d", 2000000001)} END_TEST
    START_TEST(int_general_medium_neg_big_width_no_precision){
        RUN_TEST("%50d", -2000000001)} END_TEST
    START_TEST(alt_int_null_big_width_no_precision){
        RUN_TEST("%50i", 0)} END_TEST
    START_TEST(alt_int_general_short_big_width_no_precision){
        RUN_TEST("%50i", 8192)} END_TEST
    START_TEST(alt_int_general_short_neg_big_width_no_precision){
        RUN_TEST("%50i", -8192)} END_TEST
    START_TEST(alt_int_general_medium_big_width_no_precision){
        RUN_TEST("%50i", 2000000001)} END_TEST
    START_TEST(alt_int_general_medium_neg_big_width_no_precision){
        RUN_TEST("%50i", -2000000001)} END_TEST
    START_TEST(unsigned_null_big_width_no_precision){
        RUN_TEST("%50u", 0u)} END_TEST
    START_TEST(unsigned_general_short_big_width_no_precision){
        RUN_TEST("%50u", 8192u)} END_TEST
    START_TEST(unsigned_general_short_neg_big_width_no_precision){
        RUN_TEST("%50u", -8192u)} END_TEST
    START_TEST(unsigned_general_medium_big_width_no_precision){
        RUN_TEST("%50u", 2000000001u)} END_TEST
    START_TEST(unsigned_general_medium_neg_big_width_no_precision){
        RUN_TEST("%50u", -2000000001u)} END_TEST
    START_TEST(hex_null_big_width_no_precision){RUN_TEST("%50x", 0u)} END_TEST
    START_TEST(hex_general_short_big_width_no_precision){
        RUN_TEST("%50x", 8192u)} END_TEST
    START_TEST(hex_general_short_neg_big_width_no_precision){
        RUN_TEST("%50x", -8192u)} END_TEST
    START_TEST(hex_general_medium_big_width_no_precision){
        RUN_TEST("%50x", 2000000001u)} END_TEST
    START_TEST(hex_general_medium_neg_big_width_no_precision){
        RUN_TEST("%50x", -2000000001u)} END_TEST
    START_TEST(HEX_null_big_width_no_precision){RUN_TEST("%50X", 0u)} END_TEST
    START_TEST(HEX_general_short_big_width_no_precision){
        RUN_TEST("%50X", 8192u)} END_TEST
    START_TEST(HEX_general_short_neg_big_width_no_precision){
        RUN_TEST("%50X", -8192u)} END_TEST
    START_TEST(HEX_general_medium_big_width_no_precision){
        RUN_TEST("%50X", 2000000001u)} END_TEST
    START_TEST(HEX_general_medium_neg_big_width_no_precision){
        RUN_TEST("%50X", -2000000001u)} END_TEST
    START_TEST(oct_null_big_width_no_precision){RUN_TEST("%50o", 0u)} END_TEST
    START_TEST(oct_general_short_big_width_no_precision){
        RUN_TEST("%50o", 8192u)} END_TEST
    START_TEST(oct_general_short_neg_big_width_no_precision){
        RUN_TEST("%50o", -8192u)} END_TEST
    START_TEST(oct_general_medium_big_width_no_precision){
        RUN_TEST("%50o", 2000000001u)} END_TEST
    START_TEST(oct_general_medium_neg_big_width_no_precision){
        RUN_TEST("%50o", -2000000001u)} END_TEST
    START_TEST(int_null_big_width_small_precision){
        RUN_TEST("%50.3d", 0)} END_TEST
    START_TEST(int_general_short_big_width_small_precision){
        RUN_TEST("%50.3d", 8192)} END_TEST
    START_TEST(int_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3d", -8192)} END_TEST
    START_TEST(int_general_medium_big_width_small_precision){
        RUN_TEST("%50.3d", 2000000001)} END_TEST
    START_TEST(int_general_medium_neg_big_width_small_precision){
        RUN_TEST("%50.3d", -2000000001)} END_TEST
    START_TEST(alt_int_null_big_width_small_precision){
        RUN_TEST("%50.3i", 0)} END_TEST
    START_TEST(alt_int_general_short_big_width_small_precision){
        RUN_TEST("%50.3i", 8192)} END_TEST
    START_TEST(alt_int_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3i", -8192)} END_TEST
    START_TEST(alt_int_general_medium_big_width_small_precision){
        RUN_TEST("%50.3i", 2000000001)} END_TEST
    START_TEST(alt_int_general_medium_neg_big_width_small_precision){
        RUN_TEST("%50.3i", -2000000001)} END_TEST
    START_TEST(unsigned_null_big_width_small_precision){
        RUN_TEST("%50.3u", 0u)} END_TEST
    START_TEST(unsigned_general_short_big_width_small_precision){
        RUN_TEST("%50.3u", 8192u)} END_TEST
    START_TEST(unsigned_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3u", -8192u)} END_TEST
    START_TEST(unsigned_general_medium_big_width_small_precision){
        RUN_TEST("%50.3u", 2000000001u)} END_TEST
    START_TEST(unsigned_general_medium_neg_big_width_small_precision){
        RUN_TEST("%50.3u", -2000000001u)} END_TEST
    START_TEST(hex_null_big_width_small_precision){
        RUN_TEST("%50.3x", 0u)} END_TEST
    START_TEST(hex_general_short_big_width_small_precision){
        RUN_TEST("%50.3x", 8192u)} END_TEST
    START_TEST(hex_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3x", -8192u)} END_TEST
    START_TEST(hex_general_medium_big_width_small_precision){
        RUN_TEST("%50.3x", 2000000001u)} END_TEST
    START_TEST(hex_general_medium_neg_big_width_small_precision){
        RUN_TEST("%50.3x", -2000000001u)} END_TEST
    START_TEST(HEX_null_big_width_small_precision){
        RUN_TEST("%50.3X", 0u)} END_TEST
    START_TEST(HEX_general_short_big_width_small_precision){
        RUN_TEST("%50.3X", 8192u)} END_TEST
    START_TEST(HEX_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3X", -8192u)} END_TEST
    START_TEST(HEX_general_medium_big_width_small_precision){
        RUN_TEST("%50.3X", 2000000001u)} END_TEST
    START_TEST(HEX_general_medium_neg_big_width_small_precision){
        RUN_TEST("%50.3X", -2000000001u)} END_TEST
    START_TEST(oct_null_big_width_small_precision){
        RUN_TEST("%50.3o", 0u)} END_TEST
    START_TEST(oct_general_short_big_width_small_precision){
        RUN_TEST("%50.3o", 8192u)} END_TEST
    START_TEST(oct_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3o", -8192u)} END_TEST
    START_TEST(oct_general_medium_big_width_small_precision){
        RUN_TEST("%50.3o", 2000000001u)} END_TEST
    START_TEST(oct_general_medium_neg_big_width_small_precision){
        RUN_TEST("%50.3o", -2000000001u)} END_TEST
    START_TEST(int_null_big_width_big_precision){
        RUN_TEST("%50.14d", 0)} END_TEST
    START_TEST(int_general_short_big_width_big_precision){
        RUN_TEST("%50.14d", 8192)} END_TEST
    START_TEST(int_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14d", -8192)} END_TEST
    START_TEST(int_general_medium_big_width_big_precision){
        RUN_TEST("%50.14d", 2000000001)} END_TEST
    START_TEST(int_general_medium_neg_big_width_big_precision){
        RUN_TEST("%50.14d", -2000000001)} END_TEST
    START_TEST(alt_int_null_big_width_big_precision){
        RUN_TEST("%50.14i", 0)} END_TEST
    START_TEST(alt_int_general_short_big_width_big_precision){
        RUN_TEST("%50.14i", 8192)} END_TEST
    START_TEST(alt_int_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14i", -8192)} END_TEST
    START_TEST(alt_int_general_medium_big_width_big_precision){
        RUN_TEST("%50.14i", 2000000001)} END_TEST
    START_TEST(alt_int_general_medium_neg_big_width_big_precision){
        RUN_TEST("%50.14i", -2000000001)} END_TEST
    START_TEST(unsigned_null_big_width_big_precision){
        RUN_TEST("%50.14u", 0u)} END_TEST
    START_TEST(unsigned_general_short_big_width_big_precision){
        RUN_TEST("%50.14u", 8192u)} END_TEST
    START_TEST(unsigned_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14u", -8192u)} END_TEST
    START_TEST(unsigned_general_medium_big_width_big_precision){
        RUN_TEST("%50.14u", 2000000001u)} END_TEST
    START_TEST(unsigned_general_medium_neg_big_width_big_precision){
        RUN_TEST("%50.14u", -2000000001u)} END_TEST
    START_TEST(hex_null_big_width_big_precision){
        RUN_TEST("%50.14x", 0u)} END_TEST
    START_TEST(hex_general_short_big_width_big_precision){
        RUN_TEST("%50.14x", 8192u)} END_TEST
    START_TEST(hex_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14x", -8192u)} END_TEST
    START_TEST(hex_general_medium_big_width_big_precision){
        RUN_TEST("%50.14x", 2000000001u)} END_TEST
    START_TEST(hex_general_medium_neg_big_width_big_precision){
        RUN_TEST("%50.14x", -2000000001u)} END_TEST
    START_TEST(HEX_null_big_width_big_precision){
        RUN_TEST("%50.14X", 0u)} END_TEST
    START_TEST(HEX_general_short_big_width_big_precision){
        RUN_TEST("%50.14X", 8192u)} END_TEST
    START_TEST(HEX_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14X", -8192u)} END_TEST
    START_TEST(HEX_general_medium_big_width_big_precision){
        RUN_TEST("%50.14X", 2000000001u)} END_TEST
    START_TEST(HEX_general_medium_neg_big_width_big_precision){
        RUN_TEST("%50.14X", -2000000001u)} END_TEST
    START_TEST(oct_null_big_width_big_precision){
        RUN_TEST("%50.14o", 0u)} END_TEST
    START_TEST(oct_general_short_big_width_big_precision){
        RUN_TEST("%50.14o", 8192u)} END_TEST
    START_TEST(oct_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14o", -8192u)} END_TEST
    START_TEST(oct_general_medium_big_width_big_precision){
        RUN_TEST("%50.14o", 2000000001u)} END_TEST
    START_TEST(oct_general_medium_neg_big_width_big_precision){
        RUN_TEST("%50.14o", -2000000001u)} END_TEST

    START_TEST(long_null_no_flags){RUN_TEST("%ld", 0l)} END_TEST
    START_TEST(long_general_short_no_flags){RUN_TEST("%ld", 8192l)} END_TEST
    START_TEST(long_general_short_neg_no_flags){
        RUN_TEST("%ld", -8192l)} END_TEST
    START_TEST(long_general_long_no_flags){
        RUN_TEST("%ld", 9223372036854775000l)} END_TEST
    START_TEST(long_general_long_neg_no_flags){
        RUN_TEST("%ld", -9223372036854775000l)} END_TEST
    START_TEST(unsigned_long_null_no_flags){RUN_TEST("%lu", 0lu)} END_TEST
    START_TEST(unsigned_long_general_short_no_flags){
        RUN_TEST("%lu", 8192lu)} END_TEST
    START_TEST(unsigned_long_general_short_neg_no_flags){
        RUN_TEST("%lu", -8192lu)} END_TEST
    START_TEST(unsigned_long_general_long_no_flags){
        RUN_TEST("%lu", 9223372036854775000lu)} END_TEST
    START_TEST(unsigned_long_general_long_neg_no_flags){
        RUN_TEST("%lu", -9223372036854775000lu)} END_TEST
    START_TEST(long_hex_null_no_flags){RUN_TEST("%lx", 0l)} END_TEST
    START_TEST(long_hex_general_short_no_flags){RUN_TEST("%lx", 8192l)} END_TEST
    START_TEST(long_hex_general_short_neg_no_flags){
        RUN_TEST("%lx", -8192l)} END_TEST
    START_TEST(long_hex_general_long_no_flags){
        RUN_TEST("%lx", 9223372036854775000l)} END_TEST
    START_TEST(long_hex_general_long_neg_no_flags){
        RUN_TEST("%lx", -9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_null_no_flags){RUN_TEST("%lX", 0l)} END_TEST
    START_TEST(LONG_HEX_general_short_no_flags){RUN_TEST("%lX", 8192l)} END_TEST
    START_TEST(LONG_HEX_general_short_neg_no_flags){
        RUN_TEST("%lX", -8192l)} END_TEST
    START_TEST(LONG_HEX_general_long_no_flags){
        RUN_TEST("%lX", 9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_general_long_neg_no_flags){
        RUN_TEST("%lX", -9223372036854775000l)} END_TEST
    START_TEST(long_oct_null_no_flags){RUN_TEST("%lo", 0l)} END_TEST
    START_TEST(long_oct_general_short_no_flags){RUN_TEST("%lo", 8192l)} END_TEST
    START_TEST(long_oct_general_short_neg_no_flags){
        RUN_TEST("%lo", -8192l)} END_TEST
    START_TEST(long_oct_general_long_no_flags){
        RUN_TEST("%lo", 9223372036854775000l)} END_TEST
    START_TEST(long_oct_general_long_neg_no_flags){
        RUN_TEST("%lo", -9223372036854775000l)} END_TEST
    START_TEST(long_null_prefix_sign){RUN_TEST("%+ld", 0l)} END_TEST
    START_TEST(long_general_short_prefix_sign){RUN_TEST("%+ld", 8192l)} END_TEST
    START_TEST(long_general_short_neg_prefix_sign){
        RUN_TEST("%+ld", -8192l)} END_TEST
    START_TEST(long_general_long_prefix_sign){
        RUN_TEST("%+ld", 9223372036854775000l)} END_TEST
    START_TEST(long_general_long_neg_prefix_sign){
        RUN_TEST("%+ld", -9223372036854775000l)} END_TEST
    START_TEST(unsigned_long_null_prefix_sign){RUN_TEST("%+lu", 0lu)} END_TEST
    START_TEST(unsigned_long_general_short_prefix_sign){
        RUN_TEST("%+lu", 8192lu)} END_TEST
    START_TEST(unsigned_long_general_short_neg_prefix_sign){
        RUN_TEST("%+lu", -8192lu)} END_TEST
    START_TEST(unsigned_long_general_long_prefix_sign){
        RUN_TEST("%+lu", 9223372036854775000lu)} END_TEST
    START_TEST(unsigned_long_general_long_neg_prefix_sign){
        RUN_TEST("%+lu", -9223372036854775000lu)} END_TEST
    START_TEST(long_hex_null_prefix_sign){RUN_TEST("%+lx", 0l)} END_TEST
    START_TEST(long_hex_general_short_prefix_sign){
        RUN_TEST("%+lx", 8192l)} END_TEST
    START_TEST(long_hex_general_short_neg_prefix_sign){
        RUN_TEST("%+lx", -8192l)} END_TEST
    START_TEST(long_hex_general_long_prefix_sign){
        RUN_TEST("%+lx", 9223372036854775000l)} END_TEST
    START_TEST(long_hex_general_long_neg_prefix_sign){
        RUN_TEST("%+lx", -9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_null_prefix_sign){RUN_TEST("%+lX", 0l)} END_TEST
    START_TEST(LONG_HEX_general_short_prefix_sign){
        RUN_TEST("%+lX", 8192l)} END_TEST
    START_TEST(LONG_HEX_general_short_neg_prefix_sign){
        RUN_TEST("%+lX", -8192l)} END_TEST
    START_TEST(LONG_HEX_general_long_prefix_sign){
        RUN_TEST("%+lX", 9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_general_long_neg_prefix_sign){
        RUN_TEST("%+lX", -9223372036854775000l)} END_TEST
    START_TEST(long_oct_null_prefix_sign){RUN_TEST("%+lo", 0l)} END_TEST
    START_TEST(long_oct_general_short_prefix_sign){
        RUN_TEST("%+lo", 8192l)} END_TEST
    START_TEST(long_oct_general_short_neg_prefix_sign){
        RUN_TEST("%+lo", -8192l)} END_TEST
    START_TEST(long_oct_general_long_prefix_sign){
        RUN_TEST("%+lo", 9223372036854775000l)} END_TEST
    START_TEST(long_oct_general_long_neg_prefix_sign){
        RUN_TEST("%+lo", -9223372036854775000l)} END_TEST
    START_TEST(long_null_prefix_space){RUN_TEST("% ld", 0l)} END_TEST
    START_TEST(long_general_short_prefix_space){
        RUN_TEST("% ld", 8192l)} END_TEST
    START_TEST(long_general_short_neg_prefix_space){
        RUN_TEST("% ld", -8192l)} END_TEST
    START_TEST(long_general_long_prefix_space){
        RUN_TEST("% ld", 9223372036854775000l)} END_TEST
    START_TEST(long_general_long_neg_prefix_space){
        RUN_TEST("% ld", -9223372036854775000l)} END_TEST
    START_TEST(unsigned_long_null_prefix_space){RUN_TEST("% lu", 0lu)} END_TEST
    START_TEST(unsigned_long_general_short_prefix_space){
        RUN_TEST("% lu", 8192lu)} END_TEST
    START_TEST(unsigned_long_general_short_neg_prefix_space){
        RUN_TEST("% lu", -8192lu)} END_TEST
    START_TEST(unsigned_long_general_long_prefix_space){
        RUN_TEST("% lu", 9223372036854775000lu)} END_TEST
    START_TEST(unsigned_long_general_long_neg_prefix_space){
        RUN_TEST("% lu", -9223372036854775000lu)} END_TEST
    START_TEST(long_hex_null_prefix_space){RUN_TEST("% lx", 0l)} END_TEST
    START_TEST(long_hex_general_short_prefix_space){
        RUN_TEST("% lx", 8192l)} END_TEST
    START_TEST(long_hex_general_short_neg_prefix_space){
        RUN_TEST("% lx", -8192l)} END_TEST
    START_TEST(long_hex_general_long_prefix_space){
        RUN_TEST("% lx", 9223372036854775000l)} END_TEST
    START_TEST(long_hex_general_long_neg_prefix_space){
        RUN_TEST("% lx", -9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_null_prefix_space){RUN_TEST("% lX", 0l)} END_TEST
    START_TEST(LONG_HEX_general_short_prefix_space){
        RUN_TEST("% lX", 8192l)} END_TEST
    START_TEST(LONG_HEX_general_short_neg_prefix_space){
        RUN_TEST("% lX", -8192l)} END_TEST
    START_TEST(LONG_HEX_general_long_prefix_space){
        RUN_TEST("% lX", 9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_general_long_neg_prefix_space){
        RUN_TEST("% lX", -9223372036854775000l)} END_TEST
    START_TEST(long_oct_null_prefix_space){RUN_TEST("% lo", 0l)} END_TEST
    START_TEST(long_oct_general_short_prefix_space){
        RUN_TEST("% lo", 8192l)} END_TEST
    START_TEST(long_oct_general_short_neg_prefix_space){
        RUN_TEST("% lo", -8192l)} END_TEST
    START_TEST(long_oct_general_long_prefix_space){
        RUN_TEST("% lo", 9223372036854775000l)} END_TEST
    START_TEST(long_oct_general_long_neg_prefix_space){
        RUN_TEST("% lo", -9223372036854775000l)} END_TEST
    START_TEST(long_null_left_alignment){RUN_TEST("%-ld", 0l)} END_TEST
    START_TEST(long_general_short_left_alignment){
        RUN_TEST("%-ld", 8192l)} END_TEST
    START_TEST(long_general_short_neg_left_alignment){
        RUN_TEST("%-ld", -8192l)} END_TEST
    START_TEST(long_general_long_left_alignment){
        RUN_TEST("%-ld", 9223372036854775000l)} END_TEST
    START_TEST(long_general_long_neg_left_alignment){
        RUN_TEST("%-ld", -9223372036854775000l)} END_TEST
    START_TEST(unsigned_long_null_left_alignment){
        RUN_TEST("%-lu", 0lu)} END_TEST
    START_TEST(unsigned_long_general_short_left_alignment){
        RUN_TEST("%-lu", 8192lu)} END_TEST
    START_TEST(unsigned_long_general_short_neg_left_alignment){
        RUN_TEST("%-lu", -8192lu)} END_TEST
    START_TEST(unsigned_long_general_long_left_alignment){
        RUN_TEST("%-lu", 9223372036854775000lu)} END_TEST
    START_TEST(unsigned_long_general_long_neg_left_alignment){
        RUN_TEST("%-lu", -9223372036854775000lu)} END_TEST
    START_TEST(long_hex_null_left_alignment){RUN_TEST("%-lx", 0l)} END_TEST
    START_TEST(long_hex_general_short_left_alignment){
        RUN_TEST("%-lx", 8192l)} END_TEST
    START_TEST(long_hex_general_short_neg_left_alignment){
        RUN_TEST("%-lx", -8192l)} END_TEST
    START_TEST(long_hex_general_long_left_alignment){
        RUN_TEST("%-lx", 9223372036854775000l)} END_TEST
    START_TEST(long_hex_general_long_neg_left_alignment){
        RUN_TEST("%-lx", -9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_null_left_alignment){RUN_TEST("%-lX", 0l)} END_TEST
    START_TEST(LONG_HEX_general_short_left_alignment){
        RUN_TEST("%-lX", 8192l)} END_TEST
    START_TEST(LONG_HEX_general_short_neg_left_alignment){
        RUN_TEST("%-lX", -8192l)} END_TEST
    START_TEST(LONG_HEX_general_long_left_alignment){
        RUN_TEST("%-lX", 9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_general_long_neg_left_alignment){
        RUN_TEST("%-lX", -9223372036854775000l)} END_TEST
    START_TEST(long_oct_null_left_alignment){RUN_TEST("%-lo", 0l)} END_TEST
    START_TEST(long_oct_general_short_left_alignment){
        RUN_TEST("%-lo", 8192l)} END_TEST
    START_TEST(long_oct_general_short_neg_left_alignment){
        RUN_TEST("%-lo", -8192l)} END_TEST
    START_TEST(long_oct_general_long_left_alignment){
        RUN_TEST("%-lo", 9223372036854775000l)} END_TEST
    START_TEST(long_oct_general_long_neg_left_alignment){
        RUN_TEST("%-lo", -9223372036854775000l)} END_TEST
    START_TEST(long_null_leading_zeroes){RUN_TEST("%0ld", 0l)} END_TEST
    START_TEST(long_general_short_leading_zeroes){
        RUN_TEST("%0ld", 8192l)} END_TEST
    START_TEST(long_general_short_neg_leading_zeroes){
        RUN_TEST("%0ld", -8192l)} END_TEST
    START_TEST(long_general_long_leading_zeroes){
        RUN_TEST("%0ld", 9223372036854775000l)} END_TEST
    START_TEST(long_general_long_neg_leading_zeroes){
        RUN_TEST("%0ld", -9223372036854775000l)} END_TEST
    START_TEST(unsigned_long_null_leading_zeroes){
        RUN_TEST("%0lu", 0lu)} END_TEST
    START_TEST(unsigned_long_general_short_leading_zeroes){
        RUN_TEST("%0lu", 8192lu)} END_TEST
    START_TEST(unsigned_long_general_short_neg_leading_zeroes){
        RUN_TEST("%0lu", -8192lu)} END_TEST
    START_TEST(unsigned_long_general_long_leading_zeroes){
        RUN_TEST("%0lu", 9223372036854775000lu)} END_TEST
    START_TEST(unsigned_long_general_long_neg_leading_zeroes){
        RUN_TEST("%0lu", -9223372036854775000lu)} END_TEST
    START_TEST(long_hex_null_leading_zeroes){RUN_TEST("%0lx", 0l)} END_TEST
    START_TEST(long_hex_general_short_leading_zeroes){
        RUN_TEST("%0lx", 8192l)} END_TEST
    START_TEST(long_hex_general_short_neg_leading_zeroes){
        RUN_TEST("%0lx", -8192l)} END_TEST
    START_TEST(long_hex_general_long_leading_zeroes){
        RUN_TEST("%0lx", 9223372036854775000l)} END_TEST
    START_TEST(long_hex_general_long_neg_leading_zeroes){
        RUN_TEST("%0lx", -9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_null_leading_zeroes){RUN_TEST("%0lX", 0l)} END_TEST
    START_TEST(LONG_HEX_general_short_leading_zeroes){
        RUN_TEST("%0lX", 8192l)} END_TEST
    START_TEST(LONG_HEX_general_short_neg_leading_zeroes){
        RUN_TEST("%0lX", -8192l)} END_TEST
    START_TEST(LONG_HEX_general_long_leading_zeroes){
        RUN_TEST("%0lX", 9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_general_long_neg_leading_zeroes){
        RUN_TEST("%0lX", -9223372036854775000l)} END_TEST
    START_TEST(long_oct_null_leading_zeroes){RUN_TEST("%0lo", 0l)} END_TEST
    START_TEST(long_oct_general_short_leading_zeroes){
        RUN_TEST("%0lo", 8192l)} END_TEST
    START_TEST(long_oct_general_short_neg_leading_zeroes){
        RUN_TEST("%0lo", -8192l)} END_TEST
    START_TEST(long_oct_general_long_leading_zeroes){
        RUN_TEST("%0lo", 9223372036854775000l)} END_TEST
    START_TEST(long_oct_general_long_neg_leading_zeroes){
        RUN_TEST("%0lo", -9223372036854775000l)} END_TEST
    START_TEST(long_null_alt_format){RUN_TEST("%#ld", 0l)} END_TEST
    START_TEST(long_general_short_alt_format){RUN_TEST("%#ld", 8192l)} END_TEST
    START_TEST(long_general_short_neg_alt_format){
        RUN_TEST("%#ld", -8192l)} END_TEST
    START_TEST(long_general_long_alt_format){
        RUN_TEST("%#ld", 9223372036854775000l)} END_TEST
    START_TEST(long_general_long_neg_alt_format){
        RUN_TEST("%#ld", -9223372036854775000l)} END_TEST
    START_TEST(unsigned_long_null_alt_format){RUN_TEST("%#lu", 0lu)} END_TEST
    START_TEST(unsigned_long_general_short_alt_format){
        RUN_TEST("%#lu", 8192lu)} END_TEST
    START_TEST(unsigned_long_general_short_neg_alt_format){
        RUN_TEST("%#lu", -8192lu)} END_TEST
    START_TEST(unsigned_long_general_long_alt_format){
        RUN_TEST("%#lu", 9223372036854775000lu)} END_TEST
    START_TEST(unsigned_long_general_long_neg_alt_format){
        RUN_TEST("%#lu", -9223372036854775000lu)} END_TEST
    START_TEST(long_hex_null_alt_format){RUN_TEST("%#lx", 0l)} END_TEST
    START_TEST(long_hex_general_short_alt_format){
        RUN_TEST("%#lx", 8192l)} END_TEST
    START_TEST(long_hex_general_short_neg_alt_format){
        RUN_TEST("%#lx", -8192l)} END_TEST
    START_TEST(long_hex_general_long_alt_format){
        RUN_TEST("%#lx", 9223372036854775000l)} END_TEST
    START_TEST(long_hex_general_long_neg_alt_format){
        RUN_TEST("%#lx", -9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_null_alt_format){RUN_TEST("%#lX", 0l)} END_TEST
    START_TEST(LONG_HEX_general_short_alt_format){
        RUN_TEST("%#lX", 8192l)} END_TEST
    START_TEST(LONG_HEX_general_short_neg_alt_format){
        RUN_TEST("%#lX", -8192l)} END_TEST
    START_TEST(LONG_HEX_general_long_alt_format){
        RUN_TEST("%#lX", 9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_general_long_neg_alt_format){
        RUN_TEST("%#lX", -9223372036854775000l)} END_TEST
    START_TEST(long_oct_null_alt_format){RUN_TEST("%#lo", 0l)} END_TEST
    START_TEST(long_oct_general_short_alt_format){
        RUN_TEST("%#lo", 8192l)} END_TEST
    START_TEST(long_oct_general_short_neg_alt_format){
        RUN_TEST("%#lo", -8192l)} END_TEST
    START_TEST(long_oct_general_long_alt_format){
        RUN_TEST("%#lo", 9223372036854775000l)} END_TEST
    START_TEST(long_oct_general_long_neg_alt_format){
        RUN_TEST("%#lo", -9223372036854775000l)} END_TEST
    START_TEST(long_null_no_width_no_precision){RUN_TEST("%ld", 0l)} END_TEST
    START_TEST(long_general_short_no_width_no_precision){
        RUN_TEST("%ld", 8192l)} END_TEST
    START_TEST(long_general_short_neg_no_width_no_precision){
        RUN_TEST("%ld", -8192l)} END_TEST
    START_TEST(long_general_long_no_width_no_precision){
        RUN_TEST("%ld", 9223372036854775000l)} END_TEST
    START_TEST(long_general_long_neg_no_width_no_precision){
        RUN_TEST("%ld", -9223372036854775000l)} END_TEST
    START_TEST(unsigned_long_null_no_width_no_precision){
        RUN_TEST("%lu", 0lu)} END_TEST
    START_TEST(unsigned_long_general_short_no_width_no_precision){
        RUN_TEST("%lu", 8192lu)} END_TEST
    START_TEST(unsigned_long_general_short_neg_no_width_no_precision){
        RUN_TEST("%lu", -8192lu)} END_TEST
    START_TEST(unsigned_long_general_long_no_width_no_precision){
        RUN_TEST("%lu", 9223372036854775000lu)} END_TEST
    START_TEST(unsigned_long_general_long_neg_no_width_no_precision){
        RUN_TEST("%lu", -9223372036854775000lu)} END_TEST
    START_TEST(long_hex_null_no_width_no_precision){
        RUN_TEST("%lx", 0l)} END_TEST
    START_TEST(long_hex_general_short_no_width_no_precision){
        RUN_TEST("%lx", 8192l)} END_TEST
    START_TEST(long_hex_general_short_neg_no_width_no_precision){
        RUN_TEST("%lx", -8192l)} END_TEST
    START_TEST(long_hex_general_long_no_width_no_precision){
        RUN_TEST("%lx", 9223372036854775000l)} END_TEST
    START_TEST(long_hex_general_long_neg_no_width_no_precision){
        RUN_TEST("%lx", -9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_null_no_width_no_precision){
        RUN_TEST("%lX", 0l)} END_TEST
    START_TEST(LONG_HEX_general_short_no_width_no_precision){
        RUN_TEST("%lX", 8192l)} END_TEST
    START_TEST(LONG_HEX_general_short_neg_no_width_no_precision){
        RUN_TEST("%lX", -8192l)} END_TEST
    START_TEST(LONG_HEX_general_long_no_width_no_precision){
        RUN_TEST("%lX", 9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_general_long_neg_no_width_no_precision){
        RUN_TEST("%lX", -9223372036854775000l)} END_TEST
    START_TEST(long_oct_null_no_width_no_precision){
        RUN_TEST("%lo", 0l)} END_TEST
    START_TEST(long_oct_general_short_no_width_no_precision){
        RUN_TEST("%lo", 8192l)} END_TEST
    START_TEST(long_oct_general_short_neg_no_width_no_precision){
        RUN_TEST("%lo", -8192l)} END_TEST
    START_TEST(long_oct_general_long_no_width_no_precision){
        RUN_TEST("%lo", 9223372036854775000l)} END_TEST
    START_TEST(long_oct_general_long_neg_no_width_no_precision){
        RUN_TEST("%lo", -9223372036854775000l)} END_TEST
    START_TEST(long_null_no_width_small_precision){
        RUN_TEST("%.3ld", 0l)} END_TEST
    START_TEST(long_general_short_no_width_small_precision){
        RUN_TEST("%.3ld", 8192l)} END_TEST
    START_TEST(long_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3ld", -8192l)} END_TEST
    START_TEST(long_general_long_no_width_small_precision){
        RUN_TEST("%.3ld", 9223372036854775000l)} END_TEST
    START_TEST(long_general_long_neg_no_width_small_precision){
        RUN_TEST("%.3ld", -9223372036854775000l)} END_TEST
    START_TEST(unsigned_long_null_no_width_small_precision){
        RUN_TEST("%.3lu", 0lu)} END_TEST
    START_TEST(unsigned_long_general_short_no_width_small_precision){
        RUN_TEST("%.3lu", 8192lu)} END_TEST
    START_TEST(unsigned_long_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3lu", -8192lu)} END_TEST
    START_TEST(unsigned_long_general_long_no_width_small_precision){
        RUN_TEST("%.3lu", 9223372036854775000lu)} END_TEST
    START_TEST(unsigned_long_general_long_neg_no_width_small_precision){
        RUN_TEST("%.3lu", -9223372036854775000lu)} END_TEST
    START_TEST(long_hex_null_no_width_small_precision){
        RUN_TEST("%.3lx", 0l)} END_TEST
    START_TEST(long_hex_general_short_no_width_small_precision){
        RUN_TEST("%.3lx", 8192l)} END_TEST
    START_TEST(long_hex_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3lx", -8192l)} END_TEST
    START_TEST(long_hex_general_long_no_width_small_precision){
        RUN_TEST("%.3lx", 9223372036854775000l)} END_TEST
    START_TEST(long_hex_general_long_neg_no_width_small_precision){
        RUN_TEST("%.3lx", -9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_null_no_width_small_precision){
        RUN_TEST("%.3lX", 0l)} END_TEST
    START_TEST(LONG_HEX_general_short_no_width_small_precision){
        RUN_TEST("%.3lX", 8192l)} END_TEST
    START_TEST(LONG_HEX_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3lX", -8192l)} END_TEST
    START_TEST(LONG_HEX_general_long_no_width_small_precision){
        RUN_TEST("%.3lX", 9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_general_long_neg_no_width_small_precision){
        RUN_TEST("%.3lX", -9223372036854775000l)} END_TEST
    START_TEST(long_oct_null_no_width_small_precision){
        RUN_TEST("%.3lo", 0l)} END_TEST
    START_TEST(long_oct_general_short_no_width_small_precision){
        RUN_TEST("%.3lo", 8192l)} END_TEST
    START_TEST(long_oct_general_short_neg_no_width_small_precision){
        RUN_TEST("%.3lo", -8192l)} END_TEST
    START_TEST(long_oct_general_long_no_width_small_precision){
        RUN_TEST("%.3lo", 9223372036854775000l)} END_TEST
    START_TEST(long_oct_general_long_neg_no_width_small_precision){
        RUN_TEST("%.3lo", -9223372036854775000l)} END_TEST
    START_TEST(long_null_no_width_big_precision){
        RUN_TEST("%.14ld", 0l)} END_TEST
    START_TEST(long_general_short_no_width_big_precision){
        RUN_TEST("%.14ld", 8192l)} END_TEST
    START_TEST(long_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14ld", -8192l)} END_TEST
    START_TEST(long_general_long_no_width_big_precision){
        RUN_TEST("%.14ld", 9223372036854775000l)} END_TEST
    START_TEST(long_general_long_neg_no_width_big_precision){
        RUN_TEST("%.14ld", -9223372036854775000l)} END_TEST
    START_TEST(unsigned_long_null_no_width_big_precision){
        RUN_TEST("%.14lu", 0lu)} END_TEST
    START_TEST(unsigned_long_general_short_no_width_big_precision){
        RUN_TEST("%.14lu", 8192lu)} END_TEST
    START_TEST(unsigned_long_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14lu", -8192lu)} END_TEST
    START_TEST(unsigned_long_general_long_no_width_big_precision){
        RUN_TEST("%.14lu", 9223372036854775000lu)} END_TEST
    START_TEST(unsigned_long_general_long_neg_no_width_big_precision){
        RUN_TEST("%.14lu", -9223372036854775000lu)} END_TEST
    START_TEST(long_hex_null_no_width_big_precision){
        RUN_TEST("%.14lx", 0l)} END_TEST
    START_TEST(long_hex_general_short_no_width_big_precision){
        RUN_TEST("%.14lx", 8192l)} END_TEST
    START_TEST(long_hex_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14lx", -8192l)} END_TEST
    START_TEST(long_hex_general_long_no_width_big_precision){
        RUN_TEST("%.14lx", 9223372036854775000l)} END_TEST
    START_TEST(long_hex_general_long_neg_no_width_big_precision){
        RUN_TEST("%.14lx", -9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_null_no_width_big_precision){
        RUN_TEST("%.14lX", 0l)} END_TEST
    START_TEST(LONG_HEX_general_short_no_width_big_precision){
        RUN_TEST("%.14lX", 8192l)} END_TEST
    START_TEST(LONG_HEX_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14lX", -8192l)} END_TEST
    START_TEST(LONG_HEX_general_long_no_width_big_precision){
        RUN_TEST("%.14lX", 9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_general_long_neg_no_width_big_precision){
        RUN_TEST("%.14lX", -9223372036854775000l)} END_TEST
    START_TEST(long_oct_null_no_width_big_precision){
        RUN_TEST("%.14lo", 0l)} END_TEST
    START_TEST(long_oct_general_short_no_width_big_precision){
        RUN_TEST("%.14lo", 8192l)} END_TEST
    START_TEST(long_oct_general_short_neg_no_width_big_precision){
        RUN_TEST("%.14lo", -8192l)} END_TEST
    START_TEST(long_oct_general_long_no_width_big_precision){
        RUN_TEST("%.14lo", 9223372036854775000l)} END_TEST
    START_TEST(long_oct_general_long_neg_no_width_big_precision){
        RUN_TEST("%.14lo", -9223372036854775000l)} END_TEST
    START_TEST(long_null_small_width_no_precision){
        RUN_TEST("%1ld", 0l)} END_TEST
    START_TEST(long_general_short_small_width_no_precision){
        RUN_TEST("%1ld", 8192l)} END_TEST
    START_TEST(long_general_short_neg_small_width_no_precision){
        RUN_TEST("%1ld", -8192l)} END_TEST
    START_TEST(long_general_long_small_width_no_precision){
        RUN_TEST("%1ld", 9223372036854775000l)} END_TEST
    START_TEST(long_general_long_neg_small_width_no_precision){
        RUN_TEST("%1ld", -9223372036854775000l)} END_TEST
    START_TEST(unsigned_long_null_small_width_no_precision){
        RUN_TEST("%1lu", 0lu)} END_TEST
    START_TEST(unsigned_long_general_short_small_width_no_precision){
        RUN_TEST("%1lu", 8192lu)} END_TEST
    START_TEST(unsigned_long_general_short_neg_small_width_no_precision){
        RUN_TEST("%1lu", -8192lu)} END_TEST
    START_TEST(unsigned_long_general_long_small_width_no_precision){
        RUN_TEST("%1lu", 9223372036854775000lu)} END_TEST
    START_TEST(unsigned_long_general_long_neg_small_width_no_precision){
        RUN_TEST("%1lu", -9223372036854775000lu)} END_TEST
    START_TEST(long_hex_null_small_width_no_precision){
        RUN_TEST("%1lx", 0l)} END_TEST
    START_TEST(long_hex_general_short_small_width_no_precision){
        RUN_TEST("%1lx", 8192l)} END_TEST
    START_TEST(long_hex_general_short_neg_small_width_no_precision){
        RUN_TEST("%1lx", -8192l)} END_TEST
    START_TEST(long_hex_general_long_small_width_no_precision){
        RUN_TEST("%1lx", 9223372036854775000l)} END_TEST
    START_TEST(long_hex_general_long_neg_small_width_no_precision){
        RUN_TEST("%1lx", -9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_null_small_width_no_precision){
        RUN_TEST("%1lX", 0l)} END_TEST
    START_TEST(LONG_HEX_general_short_small_width_no_precision){
        RUN_TEST("%1lX", 8192l)} END_TEST
    START_TEST(LONG_HEX_general_short_neg_small_width_no_precision){
        RUN_TEST("%1lX", -8192l)} END_TEST
    START_TEST(LONG_HEX_general_long_small_width_no_precision){
        RUN_TEST("%1lX", 9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_general_long_neg_small_width_no_precision){
        RUN_TEST("%1lX", -9223372036854775000l)} END_TEST
    START_TEST(long_oct_null_small_width_no_precision){
        RUN_TEST("%1lo", 0l)} END_TEST
    START_TEST(long_oct_general_short_small_width_no_precision){
        RUN_TEST("%1lo", 8192l)} END_TEST
    START_TEST(long_oct_general_short_neg_small_width_no_precision){
        RUN_TEST("%1lo", -8192l)} END_TEST
    START_TEST(long_oct_general_long_small_width_no_precision){
        RUN_TEST("%1lo", 9223372036854775000l)} END_TEST
    START_TEST(long_oct_general_long_neg_small_width_no_precision){
        RUN_TEST("%1lo", -9223372036854775000l)} END_TEST
    START_TEST(long_null_small_width_small_precision){
        RUN_TEST("%1.3ld", 0l)} END_TEST
    START_TEST(long_general_short_small_width_small_precision){
        RUN_TEST("%1.3ld", 8192l)} END_TEST
    START_TEST(long_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3ld", -8192l)} END_TEST
    START_TEST(long_general_long_small_width_small_precision){
        RUN_TEST("%1.3ld", 9223372036854775000l)} END_TEST
    START_TEST(long_general_long_neg_small_width_small_precision){
        RUN_TEST("%1.3ld", -9223372036854775000l)} END_TEST
    START_TEST(unsigned_long_null_small_width_small_precision){
        RUN_TEST("%1.3lu", 0lu)} END_TEST
    START_TEST(unsigned_long_general_short_small_width_small_precision){
        RUN_TEST("%1.3lu", 8192lu)} END_TEST
    START_TEST(unsigned_long_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3lu", -8192lu)} END_TEST
    START_TEST(unsigned_long_general_long_small_width_small_precision){
        RUN_TEST("%1.3lu", 9223372036854775000lu)} END_TEST
    START_TEST(unsigned_long_general_long_neg_small_width_small_precision){
        RUN_TEST("%1.3lu", -9223372036854775000lu)} END_TEST
    START_TEST(long_hex_null_small_width_small_precision){
        RUN_TEST("%1.3lx", 0l)} END_TEST
    START_TEST(long_hex_general_short_small_width_small_precision){
        RUN_TEST("%1.3lx", 8192l)} END_TEST
    START_TEST(long_hex_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3lx", -8192l)} END_TEST
    START_TEST(long_hex_general_long_small_width_small_precision){
        RUN_TEST("%1.3lx", 9223372036854775000l)} END_TEST
    START_TEST(long_hex_general_long_neg_small_width_small_precision){
        RUN_TEST("%1.3lx", -9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_null_small_width_small_precision){
        RUN_TEST("%1.3lX", 0l)} END_TEST
    START_TEST(LONG_HEX_general_short_small_width_small_precision){
        RUN_TEST("%1.3lX", 8192l)} END_TEST
    START_TEST(LONG_HEX_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3lX", -8192l)} END_TEST
    START_TEST(LONG_HEX_general_long_small_width_small_precision){
        RUN_TEST("%1.3lX", 9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_general_long_neg_small_width_small_precision){
        RUN_TEST("%1.3lX", -9223372036854775000l)} END_TEST
    START_TEST(long_oct_null_small_width_small_precision){
        RUN_TEST("%1.3lo", 0l)} END_TEST
    START_TEST(long_oct_general_short_small_width_small_precision){
        RUN_TEST("%1.3lo", 8192l)} END_TEST
    START_TEST(long_oct_general_short_neg_small_width_small_precision){
        RUN_TEST("%1.3lo", -8192l)} END_TEST
    START_TEST(long_oct_general_long_small_width_small_precision){
        RUN_TEST("%1.3lo", 9223372036854775000l)} END_TEST
    START_TEST(long_oct_general_long_neg_small_width_small_precision){
        RUN_TEST("%1.3lo", -9223372036854775000l)} END_TEST
    START_TEST(long_null_small_width_big_precision){
        RUN_TEST("%1.14ld", 0l)} END_TEST
    START_TEST(long_general_short_small_width_big_precision){
        RUN_TEST("%1.14ld", 8192l)} END_TEST
    START_TEST(long_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14ld", -8192l)} END_TEST
    START_TEST(long_general_long_small_width_big_precision){
        RUN_TEST("%1.14ld", 9223372036854775000l)} END_TEST
    START_TEST(long_general_long_neg_small_width_big_precision){
        RUN_TEST("%1.14ld", -9223372036854775000l)} END_TEST
    START_TEST(unsigned_long_null_small_width_big_precision){
        RUN_TEST("%1.14lu", 0lu)} END_TEST
    START_TEST(unsigned_long_general_short_small_width_big_precision){
        RUN_TEST("%1.14lu", 8192lu)} END_TEST
    START_TEST(unsigned_long_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14lu", -8192lu)} END_TEST
    START_TEST(unsigned_long_general_long_small_width_big_precision){
        RUN_TEST("%1.14lu", 9223372036854775000lu)} END_TEST
    START_TEST(unsigned_long_general_long_neg_small_width_big_precision){
        RUN_TEST("%1.14lu", -9223372036854775000lu)} END_TEST
    START_TEST(long_hex_null_small_width_big_precision){
        RUN_TEST("%1.14lx", 0l)} END_TEST
    START_TEST(long_hex_general_short_small_width_big_precision){
        RUN_TEST("%1.14lx", 8192l)} END_TEST
    START_TEST(long_hex_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14lx", -8192l)} END_TEST
    START_TEST(long_hex_general_long_small_width_big_precision){
        RUN_TEST("%1.14lx", 9223372036854775000l)} END_TEST
    START_TEST(long_hex_general_long_neg_small_width_big_precision){
        RUN_TEST("%1.14lx", -9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_null_small_width_big_precision){
        RUN_TEST("%1.14lX", 0l)} END_TEST
    START_TEST(LONG_HEX_general_short_small_width_big_precision){
        RUN_TEST("%1.14lX", 8192l)} END_TEST
    START_TEST(LONG_HEX_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14lX", -8192l)} END_TEST
    START_TEST(LONG_HEX_general_long_small_width_big_precision){
        RUN_TEST("%1.14lX", 9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_general_long_neg_small_width_big_precision){
        RUN_TEST("%1.14lX", -9223372036854775000l)} END_TEST
    START_TEST(long_oct_null_small_width_big_precision){
        RUN_TEST("%1.14lo", 0l)} END_TEST
    START_TEST(long_oct_general_short_small_width_big_precision){
        RUN_TEST("%1.14lo", 8192l)} END_TEST
    START_TEST(long_oct_general_short_neg_small_width_big_precision){
        RUN_TEST("%1.14lo", -8192l)} END_TEST
    START_TEST(long_oct_general_long_small_width_big_precision){
        RUN_TEST("%1.14lo", 9223372036854775000l)} END_TEST
    START_TEST(long_oct_general_long_neg_small_width_big_precision){
        RUN_TEST("%1.14lo", -9223372036854775000l)} END_TEST
    START_TEST(long_null_big_width_no_precision){RUN_TEST("%50ld", 0l)} END_TEST
    START_TEST(long_general_short_big_width_no_precision){
        RUN_TEST("%50ld", 8192l)} END_TEST
    START_TEST(long_general_short_neg_big_width_no_precision){
        RUN_TEST("%50ld", -8192l)} END_TEST
    START_TEST(long_general_long_big_width_no_precision){
        RUN_TEST("%50ld", 9223372036854775000l)} END_TEST
    START_TEST(long_general_long_neg_big_width_no_precision){
        RUN_TEST("%50ld", -9223372036854775000l)} END_TEST
    START_TEST(unsigned_long_null_big_width_no_precision){
        RUN_TEST("%50lu", 0lu)} END_TEST
    START_TEST(unsigned_long_general_short_big_width_no_precision){
        RUN_TEST("%50lu", 8192lu)} END_TEST
    START_TEST(unsigned_long_general_short_neg_big_width_no_precision){
        RUN_TEST("%50lu", -8192lu)} END_TEST
    START_TEST(unsigned_long_general_long_big_width_no_precision){
        RUN_TEST("%50lu", 9223372036854775000lu)} END_TEST
    START_TEST(unsigned_long_general_long_neg_big_width_no_precision){
        RUN_TEST("%50lu", -9223372036854775000lu)} END_TEST
    START_TEST(long_hex_null_big_width_no_precision){
        RUN_TEST("%50lx", 0l)} END_TEST
    START_TEST(long_hex_general_short_big_width_no_precision){
        RUN_TEST("%50lx", 8192l)} END_TEST
    START_TEST(long_hex_general_short_neg_big_width_no_precision){
        RUN_TEST("%50lx", -8192l)} END_TEST
    START_TEST(long_hex_general_long_big_width_no_precision){
        RUN_TEST("%50lx", 9223372036854775000l)} END_TEST
    START_TEST(long_hex_general_long_neg_big_width_no_precision){
        RUN_TEST("%50lx", -9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_null_big_width_no_precision){
        RUN_TEST("%50lX", 0l)} END_TEST
    START_TEST(LONG_HEX_general_short_big_width_no_precision){
        RUN_TEST("%50lX", 8192l)} END_TEST
    START_TEST(LONG_HEX_general_short_neg_big_width_no_precision){
        RUN_TEST("%50lX", -8192l)} END_TEST
    START_TEST(LONG_HEX_general_long_big_width_no_precision){
        RUN_TEST("%50lX", 9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_general_long_neg_big_width_no_precision){
        RUN_TEST("%50lX", -9223372036854775000l)} END_TEST
    START_TEST(long_oct_null_big_width_no_precision){
        RUN_TEST("%50lo", 0l)} END_TEST
    START_TEST(long_oct_general_short_big_width_no_precision){
        RUN_TEST("%50lo", 8192l)} END_TEST
    START_TEST(long_oct_general_short_neg_big_width_no_precision){
        RUN_TEST("%50lo", -8192l)} END_TEST
    START_TEST(long_oct_general_long_big_width_no_precision){
        RUN_TEST("%50lo", 9223372036854775000l)} END_TEST
    START_TEST(long_oct_general_long_neg_big_width_no_precision){
        RUN_TEST("%50lo", -9223372036854775000l)} END_TEST
    START_TEST(long_null_big_width_small_precision){
        RUN_TEST("%50.3ld", 0l)} END_TEST
    START_TEST(long_general_short_big_width_small_precision){
        RUN_TEST("%50.3ld", 8192l)} END_TEST
    START_TEST(long_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3ld", -8192l)} END_TEST
    START_TEST(long_general_long_big_width_small_precision){
        RUN_TEST("%50.3ld", 9223372036854775000l)} END_TEST
    START_TEST(long_general_long_neg_big_width_small_precision){
        RUN_TEST("%50.3ld", -9223372036854775000l)} END_TEST
    START_TEST(unsigned_long_null_big_width_small_precision){
        RUN_TEST("%50.3lu", 0lu)} END_TEST
    START_TEST(unsigned_long_general_short_big_width_small_precision){
        RUN_TEST("%50.3lu", 8192lu)} END_TEST
    START_TEST(unsigned_long_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3lu", -8192lu)} END_TEST
    START_TEST(unsigned_long_general_long_big_width_small_precision){
        RUN_TEST("%50.3lu", 9223372036854775000lu)} END_TEST
    START_TEST(unsigned_long_general_long_neg_big_width_small_precision){
        RUN_TEST("%50.3lu", -9223372036854775000lu)} END_TEST
    START_TEST(long_hex_null_big_width_small_precision){
        RUN_TEST("%50.3lx", 0l)} END_TEST
    START_TEST(long_hex_general_short_big_width_small_precision){
        RUN_TEST("%50.3lx", 8192l)} END_TEST
    START_TEST(long_hex_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3lx", -8192l)} END_TEST
    START_TEST(long_hex_general_long_big_width_small_precision){
        RUN_TEST("%50.3lx", 9223372036854775000l)} END_TEST
    START_TEST(long_hex_general_long_neg_big_width_small_precision){
        RUN_TEST("%50.3lx", -9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_null_big_width_small_precision){
        RUN_TEST("%50.3lX", 0l)} END_TEST
    START_TEST(LONG_HEX_general_short_big_width_small_precision){
        RUN_TEST("%50.3lX", 8192l)} END_TEST
    START_TEST(LONG_HEX_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3lX", -8192l)} END_TEST
    START_TEST(LONG_HEX_general_long_big_width_small_precision){
        RUN_TEST("%50.3lX", 9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_general_long_neg_big_width_small_precision){
        RUN_TEST("%50.3lX", -9223372036854775000l)} END_TEST
    START_TEST(long_oct_null_big_width_small_precision){
        RUN_TEST("%50.3lo", 0l)} END_TEST
    START_TEST(long_oct_general_short_big_width_small_precision){
        RUN_TEST("%50.3lo", 8192l)} END_TEST
    START_TEST(long_oct_general_short_neg_big_width_small_precision){
        RUN_TEST("%50.3lo", -8192l)} END_TEST
    START_TEST(long_oct_general_long_big_width_small_precision){
        RUN_TEST("%50.3lo", 9223372036854775000l)} END_TEST
    START_TEST(long_oct_general_long_neg_big_width_small_precision){
        RUN_TEST("%50.3lo", -9223372036854775000l)} END_TEST
    START_TEST(long_null_big_width_big_precision){
        RUN_TEST("%50.14ld", 0l)} END_TEST
    START_TEST(long_general_short_big_width_big_precision){
        RUN_TEST("%50.14ld", 8192l)} END_TEST
    START_TEST(long_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14ld", -8192l)} END_TEST
    START_TEST(long_general_long_big_width_big_precision){
        RUN_TEST("%50.14ld", 9223372036854775000l)} END_TEST
    START_TEST(long_general_long_neg_big_width_big_precision){
        RUN_TEST("%50.14ld", -9223372036854775000l)} END_TEST
    START_TEST(unsigned_long_null_big_width_big_precision){
        RUN_TEST("%50.14lu", 0lu)} END_TEST
    START_TEST(unsigned_long_general_short_big_width_big_precision){
        RUN_TEST("%50.14lu", 8192lu)} END_TEST
    START_TEST(unsigned_long_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14lu", -8192lu)} END_TEST
    START_TEST(unsigned_long_general_long_big_width_big_precision){
        RUN_TEST("%50.14lu", 9223372036854775000lu)} END_TEST
    START_TEST(unsigned_long_general_long_neg_big_width_big_precision){
        RUN_TEST("%50.14lu", -9223372036854775000lu)} END_TEST
    START_TEST(long_hex_null_big_width_big_precision){
        RUN_TEST("%50.14lx", 0l)} END_TEST
    START_TEST(long_hex_general_short_big_width_big_precision){
        RUN_TEST("%50.14lx", 8192l)} END_TEST
    START_TEST(long_hex_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14lx", -8192l)} END_TEST
    START_TEST(long_hex_general_long_big_width_big_precision){
        RUN_TEST("%50.14lx", 9223372036854775000l)} END_TEST
    START_TEST(long_hex_general_long_neg_big_width_big_precision){
        RUN_TEST("%50.14lx", -9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_null_big_width_big_precision){
        RUN_TEST("%50.14lX", 0l)} END_TEST
    START_TEST(LONG_HEX_general_short_big_width_big_precision){
        RUN_TEST("%50.14lX", 8192l)} END_TEST
    START_TEST(LONG_HEX_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14lX", -8192l)} END_TEST
    START_TEST(LONG_HEX_general_long_big_width_big_precision){
        RUN_TEST("%50.14lX", 9223372036854775000l)} END_TEST
    START_TEST(LONG_HEX_general_long_neg_big_width_big_precision){
        RUN_TEST("%50.14lX", -9223372036854775000l)} END_TEST
    START_TEST(long_oct_null_big_width_big_precision){
        RUN_TEST("%50.14lo", 0l)} END_TEST
    START_TEST(long_oct_general_short_big_width_big_precision){
        RUN_TEST("%50.14lo", 8192l)} END_TEST
    START_TEST(long_oct_general_short_neg_big_width_big_precision){
        RUN_TEST("%50.14lo", -8192l)} END_TEST
    START_TEST(long_oct_general_long_big_width_big_precision){
        RUN_TEST("%50.14lo", 9223372036854775000l)} END_TEST
    START_TEST(long_oct_general_long_neg_big_width_big_precision){
        RUN_TEST("%50.14lo", -9223372036854775000l)} END_TEST

    START_TEST(pointer_null_no_flags){RUN_TEST("%p", S21_NULL)} END_TEST
    START_TEST(pointer_format_ptr_no_flags){RUN_TEST("%p", format)} END_TEST
    START_TEST(pointer_null_prefix_sign){RUN_TEST("%+p", S21_NULL)} END_TEST
    START_TEST(pointer_format_ptr_prefix_sign){RUN_TEST("%+p", format)} END_TEST
    START_TEST(pointer_null_prefix_space){RUN_TEST("% p", S21_NULL)} END_TEST
    START_TEST(pointer_format_ptr_prefix_space){
        RUN_TEST("% p", format)} END_TEST
    START_TEST(pointer_null_left_alignment){RUN_TEST("%-p", S21_NULL)} END_TEST
    START_TEST(pointer_format_ptr_left_alignment){
        RUN_TEST("%-p", format)} END_TEST
    START_TEST(pointer_null_leading_zeroes){RUN_TEST("%0p", S21_NULL)} END_TEST
    START_TEST(pointer_format_ptr_leading_zeroes){
        RUN_TEST("%0p", format)} END_TEST
    START_TEST(pointer_null_alt_format){RUN_TEST("%#p", S21_NULL)} END_TEST
    START_TEST(pointer_format_ptr_alt_format){RUN_TEST("%#p", format)} END_TEST
    START_TEST(pointer_null_no_width_no_precision){
        RUN_TEST("%p", S21_NULL)} END_TEST
    START_TEST(pointer_format_ptr_no_width_no_precision){
        RUN_TEST("%p", format)} END_TEST
    START_TEST(pointer_null_no_width_small_precision){
        RUN_TEST("%.3p", S21_NULL)} END_TEST
    START_TEST(pointer_format_ptr_no_width_small_precision){
        RUN_TEST("%.3p", format)} END_TEST
    START_TEST(pointer_null_no_width_big_precision){
        RUN_TEST("%.14p", S21_NULL)} END_TEST
    START_TEST(pointer_format_ptr_no_width_big_precision){
        RUN_TEST("%.14p", format)} END_TEST
    START_TEST(pointer_null_small_width_no_precision){
        RUN_TEST("%1p", S21_NULL)} END_TEST
    START_TEST(pointer_format_ptr_small_width_no_precision){
        RUN_TEST("%1p", format)} END_TEST
    START_TEST(pointer_null_small_width_small_precision){
        RUN_TEST("%1.3p", S21_NULL)} END_TEST
    START_TEST(pointer_format_ptr_small_width_small_precision){
        RUN_TEST("%1.3p", format)} END_TEST
    START_TEST(pointer_null_small_width_big_precision){
        RUN_TEST("%1.14p", S21_NULL)} END_TEST
    START_TEST(pointer_format_ptr_small_width_big_precision){
        RUN_TEST("%1.14p", format)} END_TEST
    START_TEST(pointer_null_big_width_no_precision){
        RUN_TEST("%50p", S21_NULL)} END_TEST
    START_TEST(pointer_format_ptr_big_width_no_precision){
        RUN_TEST("%50p", format)} END_TEST
    START_TEST(pointer_null_big_width_small_precision){
        RUN_TEST("%50.3p", S21_NULL)} END_TEST
    START_TEST(pointer_format_ptr_big_width_small_precision){
        RUN_TEST("%50.3p", format)} END_TEST
    START_TEST(pointer_null_big_width_big_precision){
        RUN_TEST("%50.14p", S21_NULL)} END_TEST
    START_TEST(pointer_format_ptr_big_width_big_precision){
        RUN_TEST("%50.14p", format)} END_TEST

    START_TEST(char_null_no_flags){RUN_TEST("%c", '\0')} END_TEST
    START_TEST(char_general_no_flags){RUN_TEST("%c", 'a')} END_TEST
    START_TEST(char_out_of_bounds_no_flags){RUN_TEST("%c", '\250')} END_TEST
    START_TEST(char_null_prefix_sign){RUN_TEST("%+c", '\0')} END_TEST
    START_TEST(char_general_prefix_sign){RUN_TEST("%+c", 'a')} END_TEST
    START_TEST(char_out_of_bounds_prefix_sign){RUN_TEST("%+c", '\250')} END_TEST
    START_TEST(char_null_prefix_space){RUN_TEST("% c", '\0')} END_TEST
    START_TEST(char_general_prefix_space){RUN_TEST("% c", 'a')} END_TEST
    START_TEST(char_out_of_bounds_prefix_space){
        RUN_TEST("% c", '\250')} END_TEST
    START_TEST(char_null_left_alignment){RUN_TEST("%-c", '\0')} END_TEST
    START_TEST(char_general_left_alignment){RUN_TEST("%-c", 'a')} END_TEST
    START_TEST(char_out_of_bounds_left_alignment){
        RUN_TEST("%-c", '\250')} END_TEST
    START_TEST(char_null_leading_zeroes){RUN_TEST("%0c", '\0')} END_TEST
    START_TEST(char_general_leading_zeroes){RUN_TEST("%0c", 'a')} END_TEST
    START_TEST(char_out_of_bounds_leading_zeroes){
        RUN_TEST("%0c", '\250')} END_TEST
    START_TEST(char_null_alt_format){RUN_TEST("%#c", '\0')} END_TEST
    START_TEST(char_general_alt_format){RUN_TEST("%#c", 'a')} END_TEST
    START_TEST(char_out_of_bounds_alt_format){RUN_TEST("%#c", '\250')} END_TEST
    START_TEST(char_null_no_width_no_precision){RUN_TEST("%c", '\0')} END_TEST
    START_TEST(char_general_no_width_no_precision){RUN_TEST("%c", 'a')} END_TEST
    START_TEST(char_out_of_bounds_no_width_no_precision){
        RUN_TEST("%c", '\250')} END_TEST
    START_TEST(char_null_no_width_small_precision){
        RUN_TEST("%.3c", '\0')} END_TEST
    START_TEST(char_general_no_width_small_precision){
        RUN_TEST("%.3c", 'a')} END_TEST
    START_TEST(char_out_of_bounds_no_width_small_precision){
        RUN_TEST("%.3c", '\250')} END_TEST
    START_TEST(char_null_no_width_big_precision){
        RUN_TEST("%.14c", '\0')} END_TEST
    START_TEST(char_general_no_width_big_precision){
        RUN_TEST("%.14c", 'a')} END_TEST
    START_TEST(char_out_of_bounds_no_width_big_precision){
        RUN_TEST("%.14c", '\250')} END_TEST
    START_TEST(char_null_small_width_no_precision){
        RUN_TEST("%1c", '\0')} END_TEST
    START_TEST(char_general_small_width_no_precision){
        RUN_TEST("%1c", 'a')} END_TEST
    START_TEST(char_out_of_bounds_small_width_no_precision){
        RUN_TEST("%1c", '\250')} END_TEST
    START_TEST(char_null_small_width_small_precision){
        RUN_TEST("%1.3c", '\0')} END_TEST
    START_TEST(char_general_small_width_small_precision){
        RUN_TEST("%1.3c", 'a')} END_TEST
    START_TEST(char_out_of_bounds_small_width_small_precision){
        RUN_TEST("%1.3c", '\250')} END_TEST
    START_TEST(char_null_small_width_big_precision){
        RUN_TEST("%1.14c", '\0')} END_TEST
    START_TEST(char_general_small_width_big_precision){
        RUN_TEST("%1.14c", 'a')} END_TEST
    START_TEST(char_out_of_bounds_small_width_big_precision){
        RUN_TEST("%1.14c", '\250')} END_TEST
    START_TEST(char_null_big_width_no_precision){
        RUN_TEST("%50c", '\0')} END_TEST
    START_TEST(char_general_big_width_no_precision){
        RUN_TEST("%50c", 'a')} END_TEST
    START_TEST(char_out_of_bounds_big_width_no_precision){
        RUN_TEST("%50c", '\250')} END_TEST
    START_TEST(char_null_big_width_small_precision){
        RUN_TEST("%50.3c", '\0')} END_TEST
    START_TEST(char_general_big_width_small_precision){
        RUN_TEST("%50.3c", 'a')} END_TEST
    START_TEST(char_out_of_bounds_big_width_small_precision){
        RUN_TEST("%50.3c", '\250')} END_TEST
    START_TEST(char_null_big_width_big_precision){
        RUN_TEST("%50.14c", '\0')} END_TEST
    START_TEST(char_general_big_width_big_precision){
        RUN_TEST("%50.14c", 'a')} END_TEST
    START_TEST(char_out_of_bounds_big_width_big_precision){
        RUN_TEST("%50.14c", '\250')} END_TEST

    START_TEST(long_char_null_no_flags){RUN_TEST("%lc", (wint_t)'\0')} END_TEST
    START_TEST(long_char_general_no_flags){
        RUN_TEST("%lc", (wint_t)'a')} END_TEST
    START_TEST(long_char_null_prefix_sign){
        RUN_TEST("%+lc", (wint_t)'\0')} END_TEST
    START_TEST(long_char_general_prefix_sign){
        RUN_TEST("%+lc", (wint_t)'a')} END_TEST
    START_TEST(long_char_null_prefix_space){
        RUN_TEST("% lc", (wint_t)'\0')} END_TEST
    START_TEST(long_char_general_prefix_space){
        RUN_TEST("% lc", (wint_t)'a')} END_TEST
    START_TEST(long_char_null_left_alignment){
        RUN_TEST("%-lc", (wint_t)'\0')} END_TEST
    START_TEST(long_char_general_left_alignment){
        RUN_TEST("%-lc", (wint_t)'a')} END_TEST
    START_TEST(long_char_null_leading_zeroes){
        RUN_TEST("%0lc", (wint_t)'\0')} END_TEST
    START_TEST(long_char_general_leading_zeroes){
        RUN_TEST("%0lc", (wint_t)'a')} END_TEST
    START_TEST(long_char_null_alt_format){
        RUN_TEST("%#lc", (wint_t)'\0')} END_TEST
    START_TEST(long_char_general_alt_format){
        RUN_TEST("%#lc", (wint_t)'a')} END_TEST
    START_TEST(long_char_null_no_width_no_precision){
        RUN_TEST("%lc", (wint_t)'\0')} END_TEST
    START_TEST(long_char_general_no_width_no_precision){
        RUN_TEST("%lc", (wint_t)'a')} END_TEST
    START_TEST(long_char_null_no_width_small_precision){
        RUN_TEST("%.3lc", (wint_t)'\0')} END_TEST
    START_TEST(long_char_general_no_width_small_precision){
        RUN_TEST("%.3lc", (wint_t)'a')} END_TEST
    START_TEST(long_char_null_no_width_big_precision){
        RUN_TEST("%.14lc", (wint_t)'\0')} END_TEST
    START_TEST(long_char_general_no_width_big_precision){
        RUN_TEST("%.14lc", (wint_t)'a')} END_TEST
    START_TEST(long_char_null_small_width_no_precision){
        RUN_TEST("%1lc", (wint_t)'\0')} END_TEST
    START_TEST(long_char_general_small_width_no_precision){
        RUN_TEST("%1lc", (wint_t)'a')} END_TEST
    START_TEST(long_char_null_small_width_small_precision){
        RUN_TEST("%1.3lc", (wint_t)'\0')} END_TEST
    START_TEST(long_char_general_small_width_small_precision){
        RUN_TEST("%1.3lc", (wint_t)'a')} END_TEST
    START_TEST(long_char_null_small_width_big_precision){
        RUN_TEST("%1.14lc", (wint_t)'\0')} END_TEST
    START_TEST(long_char_general_small_width_big_precision){
        RUN_TEST("%1.14lc", (wint_t)'a')} END_TEST
    START_TEST(long_char_null_big_width_no_precision){
        RUN_TEST("%50lc", (wint_t)'\0')} END_TEST
    START_TEST(long_char_general_big_width_no_precision){
        RUN_TEST("%50lc", (wint_t)'a')} END_TEST
    START_TEST(long_char_null_big_width_small_precision){
        RUN_TEST("%50.3lc", (wint_t)'\0')} END_TEST
    START_TEST(long_char_general_big_width_small_precision){
        RUN_TEST("%50.3lc", (wint_t)'a')} END_TEST
    START_TEST(long_char_null_big_width_big_precision){
        RUN_TEST("%50.14lc", (wint_t)'\0')} END_TEST
    START_TEST(long_char_general_big_width_big_precision){
        RUN_TEST("%50.14lc", (wint_t)'a')} END_TEST

    START_TEST(string_empty_no_flags){RUN_TEST("%s", "")} END_TEST
    START_TEST(string_len_one_no_flags){RUN_TEST("%s", "a")} END_TEST
    START_TEST(string_general_no_flags){RUN_TEST("%s", "hello")} END_TEST
    START_TEST(string_empty_prefix_sign){RUN_TEST("%+s", "")} END_TEST
    START_TEST(string_len_one_prefix_sign){RUN_TEST("%+s", "a")} END_TEST
    START_TEST(string_general_prefix_sign){RUN_TEST("%+s", "hello")} END_TEST
    START_TEST(string_empty_prefix_space){RUN_TEST("% s", "")} END_TEST
    START_TEST(string_len_one_prefix_space){RUN_TEST("% s", "a")} END_TEST
    START_TEST(string_general_prefix_space){RUN_TEST("% s", "hello")} END_TEST
    START_TEST(string_empty_left_alignment){RUN_TEST("%-s", "")} END_TEST
    START_TEST(string_len_one_left_alignment){RUN_TEST("%-s", "a")} END_TEST
    START_TEST(string_general_left_alignment){RUN_TEST("%-s", "hello")} END_TEST
    START_TEST(string_empty_leading_zeroes){RUN_TEST("%0s", "")} END_TEST
    START_TEST(string_len_one_leading_zeroes){RUN_TEST("%0s", "a")} END_TEST
    START_TEST(string_general_leading_zeroes){RUN_TEST("%0s", "hello")} END_TEST
    START_TEST(string_empty_alt_format){RUN_TEST("%#s", "")} END_TEST
    START_TEST(string_len_one_alt_format){RUN_TEST("%#s", "a")} END_TEST
    START_TEST(string_general_alt_format){RUN_TEST("%#s", "hello")} END_TEST
    START_TEST(string_empty_no_width_no_precision){RUN_TEST("%s", "")} END_TEST
    START_TEST(string_len_one_no_width_no_precision){
        RUN_TEST("%s", "a")} END_TEST
    START_TEST(string_general_no_width_no_precision){
        RUN_TEST("%s", "hello")} END_TEST
    START_TEST(string_empty_no_width_small_precision){
        RUN_TEST("%.3s", "")} END_TEST
    START_TEST(string_len_one_no_width_small_precision){
        RUN_TEST("%.3s", "a")} END_TEST
    START_TEST(string_general_no_width_small_precision){
        RUN_TEST("%.3s", "hello")} END_TEST
    START_TEST(string_empty_no_width_big_precision){
        RUN_TEST("%.14s", "")} END_TEST
    START_TEST(string_len_one_no_width_big_precision){
        RUN_TEST("%.14s", "a")} END_TEST
    START_TEST(string_general_no_width_big_precision){
        RUN_TEST("%.14s", "hello")} END_TEST
    START_TEST(string_empty_small_width_no_precision){
        RUN_TEST("%1s", "")} END_TEST
    START_TEST(string_len_one_small_width_no_precision){
        RUN_TEST("%1s", "a")} END_TEST
    START_TEST(string_general_small_width_no_precision){
        RUN_TEST("%1s", "hello")} END_TEST
    START_TEST(string_empty_small_width_small_precision){
        RUN_TEST("%1.3s", "")} END_TEST
    START_TEST(string_len_one_small_width_small_precision){
        RUN_TEST("%1.3s", "a")} END_TEST
    START_TEST(string_general_small_width_small_precision){
        RUN_TEST("%1.3s", "hello")} END_TEST
    START_TEST(string_empty_small_width_big_precision){
        RUN_TEST("%1.14s", "")} END_TEST
    START_TEST(string_len_one_small_width_big_precision){
        RUN_TEST("%1.14s", "a")} END_TEST
    START_TEST(string_general_small_width_big_precision){
        RUN_TEST("%1.14s", "hello")} END_TEST
    START_TEST(string_empty_big_width_no_precision){
        RUN_TEST("%50s", "")} END_TEST
    START_TEST(string_len_one_big_width_no_precision){
        RUN_TEST("%50s", "a")} END_TEST
    START_TEST(string_general_big_width_no_precision){
        RUN_TEST("%50s", "hello")} END_TEST
    START_TEST(string_empty_big_width_small_precision){
        RUN_TEST("%50.3s", "")} END_TEST
    START_TEST(string_len_one_big_width_small_precision){
        RUN_TEST("%50.3s", "a")} END_TEST
    START_TEST(string_general_big_width_small_precision){
        RUN_TEST("%50.3s", "hello")} END_TEST
    START_TEST(string_empty_big_width_big_precision){
        RUN_TEST("%50.14s", "")} END_TEST
    START_TEST(string_len_one_big_width_big_precision){
        RUN_TEST("%50.14s", "a")} END_TEST
    START_TEST(string_general_big_width_big_precision){
        RUN_TEST("%50.14s", "hello")} END_TEST

    START_TEST(long_string_empty_no_flags){RUN_TEST("%ls", L"")} END_TEST
    START_TEST(long_string_len_one_no_flags){RUN_TEST("%ls", L"a")} END_TEST
    START_TEST(long_string_general_no_flags){RUN_TEST("%ls", L"hello")} END_TEST
    START_TEST(long_string_empty_prefix_sign){RUN_TEST("%+ls", L"")} END_TEST
    START_TEST(long_string_len_one_prefix_sign){RUN_TEST("%+ls", L"a")} END_TEST
    START_TEST(long_string_general_prefix_sign){
        RUN_TEST("%+ls", L"hello")} END_TEST
    START_TEST(long_string_empty_prefix_space){RUN_TEST("% ls", L"")} END_TEST
    START_TEST(long_string_len_one_prefix_space){
        RUN_TEST("% ls", L"a")} END_TEST
    START_TEST(long_string_general_prefix_space){
        RUN_TEST("% ls", L"hello")} END_TEST
    START_TEST(long_string_empty_left_alignment){RUN_TEST("%-ls", L"")} END_TEST
    START_TEST(long_string_len_one_left_alignment){
        RUN_TEST("%-ls", L"a")} END_TEST
    START_TEST(long_string_general_left_alignment){
        RUN_TEST("%-ls", L"hello")} END_TEST
    START_TEST(long_string_empty_leading_zeroes){RUN_TEST("%0ls", L"")} END_TEST
    START_TEST(long_string_len_one_leading_zeroes){
        RUN_TEST("%0ls", L"a")} END_TEST
    START_TEST(long_string_general_leading_zeroes){
        RUN_TEST("%0ls", L"hello")} END_TEST
    START_TEST(long_string_empty_alt_format){RUN_TEST("%#ls", L"")} END_TEST
    START_TEST(long_string_len_one_alt_format){RUN_TEST("%#ls", L"a")} END_TEST
    START_TEST(long_string_general_alt_format){
        RUN_TEST("%#ls", L"hello")} END_TEST
    START_TEST(long_string_empty_no_width_no_precision){
        RUN_TEST("%ls", L"")} END_TEST
    START_TEST(long_string_len_one_no_width_no_precision){
        RUN_TEST("%ls", L"a")} END_TEST
    START_TEST(long_string_general_no_width_no_precision){
        RUN_TEST("%ls", L"hello")} END_TEST
    START_TEST(long_string_empty_no_width_small_precision){
        RUN_TEST("%.3ls", L"")} END_TEST
    START_TEST(long_string_len_one_no_width_small_precision){
        RUN_TEST("%.3ls", L"a")} END_TEST
    START_TEST(long_string_general_no_width_small_precision){
        RUN_TEST("%.3ls", L"hello")} END_TEST
    START_TEST(long_string_empty_no_width_big_precision){
        RUN_TEST("%.14ls", L"")} END_TEST
    START_TEST(long_string_len_one_no_width_big_precision){
        RUN_TEST("%.14ls", L"a")} END_TEST
    START_TEST(long_string_general_no_width_big_precision){
        RUN_TEST("%.14ls", L"hello")} END_TEST
    START_TEST(long_string_empty_small_width_no_precision){
        RUN_TEST("%1ls", L"")} END_TEST
    START_TEST(long_string_len_one_small_width_no_precision){
        RUN_TEST("%1ls", L"a")} END_TEST
    START_TEST(long_string_general_small_width_no_precision){
        RUN_TEST("%1ls", L"hello")} END_TEST
    START_TEST(long_string_empty_small_width_small_precision){
        RUN_TEST("%1.3ls", L"")} END_TEST
    START_TEST(long_string_len_one_small_width_small_precision){
        RUN_TEST("%1.3ls", L"a")} END_TEST
    START_TEST(long_string_general_small_width_small_precision){
        RUN_TEST("%1.3ls", L"hello")} END_TEST
    START_TEST(long_string_empty_small_width_big_precision){
        RUN_TEST("%1.14ls", L"")} END_TEST
    START_TEST(long_string_len_one_small_width_big_precision){
        RUN_TEST("%1.14ls", L"a")} END_TEST
    START_TEST(long_string_general_small_width_big_precision){
        RUN_TEST("%1.14ls", L"hello")} END_TEST
    START_TEST(long_string_empty_big_width_no_precision){
        RUN_TEST("%50ls", L"")} END_TEST
    START_TEST(long_string_len_one_big_width_no_precision){
        RUN_TEST("%50ls", L"a")} END_TEST
    START_TEST(long_string_general_big_width_no_precision){
        RUN_TEST("%50ls", L"hello")} END_TEST
    START_TEST(long_string_empty_big_width_small_precision){
        RUN_TEST("%50.3ls", L"")} END_TEST
    START_TEST(long_string_len_one_big_width_small_precision){
        RUN_TEST("%50.3ls", L"a")} END_TEST
    START_TEST(long_string_general_big_width_small_precision){
        RUN_TEST("%50.3ls", L"hello")} END_TEST
    START_TEST(long_string_empty_big_width_big_precision){
        RUN_TEST("%50.14ls", L"")} END_TEST
    START_TEST(long_string_len_one_big_width_big_precision){
        RUN_TEST("%50.14ls", L"a")} END_TEST
    START_TEST(long_string_general_big_width_big_precision){
        RUN_TEST("%50.14ls", L"hello")} END_TEST

    START_TEST(arbitrary_no_width_no_precision){
        RUN_TEST("%lf", 20.123124432423)} END_TEST
    START_TEST(arbitrary_no_width_small_precision){
        RUN_TEST("%.*lf", 2, 20.123124432423)} END_TEST
    START_TEST(arbitrary_no_width_big_precision){
        RUN_TEST("%.*lf", 14, 20.123124432423)} END_TEST
    START_TEST(arbitrary_small_width_no_precision){
        RUN_TEST("%*lf", 1, 20.123124432423)} END_TEST
    START_TEST(arbitrary_small_width_small_precision){
        RUN_TEST("%*.*lf", 1, 2, 20.123124432423)} END_TEST
    START_TEST(arbitrary_small_width_big_precision){
        RUN_TEST("%*.*lf", 1, 14, 20.123124432423)} END_TEST
    START_TEST(arbitrary_big_width_no_precision){
        RUN_TEST("%*lf", 20, 20.123124432423)} END_TEST
    START_TEST(arbitrary_big_width_small_precision){
        RUN_TEST("%*.*lf", 20, 2, 20.123124432423)} END_TEST
    START_TEST(arbitrary_big_width_big_precision){
        RUN_TEST("%*.*lf", 20, 14, 20.123124432423)} END_TEST
    START_TEST(multiple_formats){
        RUN_TEST("|%+15ld|%0.5u|%10.20lx|%-020lX|%#20o|%25p|%f|%+20.5Le|%+015."
                 "10lE|%#-10.0lg|%G|%c|%.3s|%%|",
                 96485L, 3243U, -12312312L, 0L, 256, S21_NULL, 3.1415,
                 6.02214076E23L, 6.62607015e-34, 1048576.0, 0.001, 'M',
                 L"Good")} END_TEST START_TEST(empty_format) {
  char str[100];
  ck_assert_int_eq(s21_sprintf(str, "%", 123), -1);
}
END_TEST
START_TEST(no_specifier_short) {
  char str[100];
  ck_assert_int_eq(s21_sprintf(str, "%l", 123), -1);
}
END_TEST
START_TEST(no_specifier_long) {
  char str[100];
  ck_assert_int_eq(s21_sprintf(str, "%+-#20.5h", 123), -1);
}
END_TEST
START_TEST(invalid_specifier_short) {
  char str[100];
  ck_assert_int_eq(s21_sprintf(str, "%lr", 123), -1);
}
END_TEST
START_TEST(invalid_specifier_long) {
  char str[100];
  ck_assert_int_eq(s21_sprintf(str, "%+-#20.5lr", 123), -1);
}
END_TEST
Suite* suite_s21_sprintf(void) {
  Suite* suite = suite_create("s21_sprintf");
  TCase* tcase_core = tcase_create("core");

  tcase_add_test(tcase_core, float_null_no_flags);
  tcase_add_test(tcase_core, float_null_neg_no_flags);
  tcase_add_test(tcase_core, float_fraction_short_no_flags);
  tcase_add_test(tcase_core, float_general_short_no_flags);
  tcase_add_test(tcase_core, float_exp_null_no_flags);
  tcase_add_test(tcase_core, float_exp_null_neg_no_flags);
  tcase_add_test(tcase_core, float_exp_fraction_short_no_flags);
  tcase_add_test(tcase_core, float_exp_general_short_no_flags);
  tcase_add_test(tcase_core, float_EXP_null_no_flags);
  tcase_add_test(tcase_core, float_EXP_null_neg_no_flags);
  tcase_add_test(tcase_core, float_EXP_fraction_short_no_flags);
  tcase_add_test(tcase_core, float_EXP_general_short_no_flags);
  tcase_add_test(tcase_core, float_g_null_no_flags);
  tcase_add_test(tcase_core, float_g_null_neg_no_flags);
  tcase_add_test(tcase_core, float_g_fraction_short_no_flags);
  tcase_add_test(tcase_core, float_g_general_short_no_flags);
  tcase_add_test(tcase_core, float_G_null_no_flags);
  tcase_add_test(tcase_core, float_G_null_neg_no_flags);
  tcase_add_test(tcase_core, float_G_fraction_short_no_flags);
  tcase_add_test(tcase_core, float_G_general_short_no_flags);
  tcase_add_test(tcase_core, float_null_prefix_sign);
  tcase_add_test(tcase_core, float_null_neg_prefix_sign);
  tcase_add_test(tcase_core, float_fraction_short_prefix_sign);
  tcase_add_test(tcase_core, float_general_short_prefix_sign);
  tcase_add_test(tcase_core, float_exp_null_prefix_sign);
  tcase_add_test(tcase_core, float_exp_null_neg_prefix_sign);
  tcase_add_test(tcase_core, float_exp_fraction_short_prefix_sign);
  tcase_add_test(tcase_core, float_exp_general_short_prefix_sign);
  tcase_add_test(tcase_core, float_EXP_null_prefix_sign);
  tcase_add_test(tcase_core, float_EXP_null_neg_prefix_sign);
  tcase_add_test(tcase_core, float_EXP_fraction_short_prefix_sign);
  tcase_add_test(tcase_core, float_EXP_general_short_prefix_sign);
  tcase_add_test(tcase_core, float_g_null_prefix_sign);
  tcase_add_test(tcase_core, float_g_null_neg_prefix_sign);
  tcase_add_test(tcase_core, float_g_fraction_short_prefix_sign);
  tcase_add_test(tcase_core, float_g_general_short_prefix_sign);
  tcase_add_test(tcase_core, float_G_null_prefix_sign);
  tcase_add_test(tcase_core, float_G_null_neg_prefix_sign);
  tcase_add_test(tcase_core, float_G_fraction_short_prefix_sign);
  tcase_add_test(tcase_core, float_G_general_short_prefix_sign);
  tcase_add_test(tcase_core, float_null_prefix_space);
  tcase_add_test(tcase_core, float_null_neg_prefix_space);
  tcase_add_test(tcase_core, float_fraction_short_prefix_space);
  tcase_add_test(tcase_core, float_general_short_prefix_space);
  tcase_add_test(tcase_core, float_exp_null_prefix_space);
  tcase_add_test(tcase_core, float_exp_null_neg_prefix_space);
  tcase_add_test(tcase_core, float_exp_fraction_short_prefix_space);
  tcase_add_test(tcase_core, float_exp_general_short_prefix_space);
  tcase_add_test(tcase_core, float_EXP_null_prefix_space);
  tcase_add_test(tcase_core, float_EXP_null_neg_prefix_space);
  tcase_add_test(tcase_core, float_EXP_fraction_short_prefix_space);
  tcase_add_test(tcase_core, float_EXP_general_short_prefix_space);
  tcase_add_test(tcase_core, float_g_null_prefix_space);
  tcase_add_test(tcase_core, float_g_null_neg_prefix_space);
  tcase_add_test(tcase_core, float_g_fraction_short_prefix_space);
  tcase_add_test(tcase_core, float_g_general_short_prefix_space);
  tcase_add_test(tcase_core, float_G_null_prefix_space);
  tcase_add_test(tcase_core, float_G_null_neg_prefix_space);
  tcase_add_test(tcase_core, float_G_fraction_short_prefix_space);
  tcase_add_test(tcase_core, float_G_general_short_prefix_space);
  tcase_add_test(tcase_core, float_null_left_alignment);
  tcase_add_test(tcase_core, float_null_neg_left_alignment);
  tcase_add_test(tcase_core, float_fraction_short_left_alignment);
  tcase_add_test(tcase_core, float_general_short_left_alignment);
  tcase_add_test(tcase_core, float_exp_null_left_alignment);
  tcase_add_test(tcase_core, float_exp_null_neg_left_alignment);
  tcase_add_test(tcase_core, float_exp_fraction_short_left_alignment);
  tcase_add_test(tcase_core, float_exp_general_short_left_alignment);
  tcase_add_test(tcase_core, float_EXP_null_left_alignment);
  tcase_add_test(tcase_core, float_EXP_null_neg_left_alignment);
  tcase_add_test(tcase_core, float_EXP_fraction_short_left_alignment);
  tcase_add_test(tcase_core, float_EXP_general_short_left_alignment);
  tcase_add_test(tcase_core, float_g_null_left_alignment);
  tcase_add_test(tcase_core, float_g_null_neg_left_alignment);
  tcase_add_test(tcase_core, float_g_fraction_short_left_alignment);
  tcase_add_test(tcase_core, float_g_general_short_left_alignment);
  tcase_add_test(tcase_core, float_G_null_left_alignment);
  tcase_add_test(tcase_core, float_G_null_neg_left_alignment);
  tcase_add_test(tcase_core, float_G_fraction_short_left_alignment);
  tcase_add_test(tcase_core, float_G_general_short_left_alignment);
  tcase_add_test(tcase_core, float_null_leading_zeroes);
  tcase_add_test(tcase_core, float_null_neg_leading_zeroes);
  tcase_add_test(tcase_core, float_fraction_short_leading_zeroes);
  tcase_add_test(tcase_core, float_general_short_leading_zeroes);
  tcase_add_test(tcase_core, float_exp_null_leading_zeroes);
  tcase_add_test(tcase_core, float_exp_null_neg_leading_zeroes);
  tcase_add_test(tcase_core, float_exp_fraction_short_leading_zeroes);
  tcase_add_test(tcase_core, float_exp_general_short_leading_zeroes);
  tcase_add_test(tcase_core, float_EXP_null_leading_zeroes);
  tcase_add_test(tcase_core, float_EXP_null_neg_leading_zeroes);
  tcase_add_test(tcase_core, float_EXP_fraction_short_leading_zeroes);
  tcase_add_test(tcase_core, float_EXP_general_short_leading_zeroes);
  tcase_add_test(tcase_core, float_g_null_leading_zeroes);
  tcase_add_test(tcase_core, float_g_null_neg_leading_zeroes);
  tcase_add_test(tcase_core, float_g_fraction_short_leading_zeroes);
  tcase_add_test(tcase_core, float_g_general_short_leading_zeroes);
  tcase_add_test(tcase_core, float_G_null_leading_zeroes);
  tcase_add_test(tcase_core, float_G_null_neg_leading_zeroes);
  tcase_add_test(tcase_core, float_G_fraction_short_leading_zeroes);
  tcase_add_test(tcase_core, float_G_general_short_leading_zeroes);
  tcase_add_test(tcase_core, float_null_alt_format);
  tcase_add_test(tcase_core, float_null_neg_alt_format);
  tcase_add_test(tcase_core, float_fraction_short_alt_format);
  tcase_add_test(tcase_core, float_general_short_alt_format);
  tcase_add_test(tcase_core, float_exp_null_alt_format);
  tcase_add_test(tcase_core, float_exp_null_neg_alt_format);
  tcase_add_test(tcase_core, float_exp_fraction_short_alt_format);
  tcase_add_test(tcase_core, float_exp_general_short_alt_format);
  tcase_add_test(tcase_core, float_EXP_null_alt_format);
  tcase_add_test(tcase_core, float_EXP_null_neg_alt_format);
  tcase_add_test(tcase_core, float_EXP_fraction_short_alt_format);
  tcase_add_test(tcase_core, float_EXP_general_short_alt_format);
  tcase_add_test(tcase_core, float_g_null_alt_format);
  tcase_add_test(tcase_core, float_g_null_neg_alt_format);
  tcase_add_test(tcase_core, float_g_fraction_short_alt_format);
  tcase_add_test(tcase_core, float_g_general_short_alt_format);
  tcase_add_test(tcase_core, float_G_null_alt_format);
  tcase_add_test(tcase_core, float_G_null_neg_alt_format);
  tcase_add_test(tcase_core, float_G_fraction_short_alt_format);
  tcase_add_test(tcase_core, float_G_general_short_alt_format);
  tcase_add_test(tcase_core, float_null_no_width_no_precision);
  tcase_add_test(tcase_core, float_null_neg_no_width_no_precision);
  tcase_add_test(tcase_core, float_fraction_short_no_width_no_precision);
  tcase_add_test(tcase_core, float_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, float_exp_null_no_width_no_precision);
  tcase_add_test(tcase_core, float_exp_null_neg_no_width_no_precision);
  tcase_add_test(tcase_core, float_exp_fraction_short_no_width_no_precision);
  tcase_add_test(tcase_core, float_exp_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_null_no_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_null_neg_no_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_fraction_short_no_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, float_g_null_no_width_no_precision);
  tcase_add_test(tcase_core, float_g_null_neg_no_width_no_precision);
  tcase_add_test(tcase_core, float_g_fraction_short_no_width_no_precision);
  tcase_add_test(tcase_core, float_g_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, float_G_null_no_width_no_precision);
  tcase_add_test(tcase_core, float_G_null_neg_no_width_no_precision);
  tcase_add_test(tcase_core, float_G_fraction_short_no_width_no_precision);
  tcase_add_test(tcase_core, float_G_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, float_null_no_width_small_precision);
  tcase_add_test(tcase_core, float_null_neg_no_width_small_precision);
  tcase_add_test(tcase_core, float_fraction_short_no_width_small_precision);
  tcase_add_test(tcase_core, float_general_short_no_width_small_precision);
  tcase_add_test(tcase_core, float_exp_null_no_width_small_precision);
  tcase_add_test(tcase_core, float_exp_null_neg_no_width_small_precision);
  tcase_add_test(tcase_core, float_exp_fraction_short_no_width_small_precision);
  tcase_add_test(tcase_core, float_exp_general_short_no_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_null_no_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_null_neg_no_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_fraction_short_no_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_general_short_no_width_small_precision);
  tcase_add_test(tcase_core, float_g_null_no_width_small_precision);
  tcase_add_test(tcase_core, float_g_null_neg_no_width_small_precision);
  tcase_add_test(tcase_core, float_g_fraction_short_no_width_small_precision);
  tcase_add_test(tcase_core, float_g_general_short_no_width_small_precision);
  tcase_add_test(tcase_core, float_G_null_no_width_small_precision);
  tcase_add_test(tcase_core, float_G_null_neg_no_width_small_precision);
  tcase_add_test(tcase_core, float_G_fraction_short_no_width_small_precision);
  tcase_add_test(tcase_core, float_G_general_short_no_width_small_precision);
  tcase_add_test(tcase_core, float_null_no_width_big_precision);
  tcase_add_test(tcase_core, float_null_neg_no_width_big_precision);
  tcase_add_test(tcase_core, float_fraction_short_no_width_big_precision);
  tcase_add_test(tcase_core, float_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, float_exp_null_no_width_big_precision);
  tcase_add_test(tcase_core, float_exp_null_neg_no_width_big_precision);
  tcase_add_test(tcase_core, float_exp_fraction_short_no_width_big_precision);
  tcase_add_test(tcase_core, float_exp_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_null_no_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_null_neg_no_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_fraction_short_no_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, float_g_null_no_width_big_precision);
  tcase_add_test(tcase_core, float_g_null_neg_no_width_big_precision);
  tcase_add_test(tcase_core, float_g_fraction_short_no_width_big_precision);
  tcase_add_test(tcase_core, float_g_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, float_G_null_no_width_big_precision);
  tcase_add_test(tcase_core, float_G_null_neg_no_width_big_precision);
  tcase_add_test(tcase_core, float_G_fraction_short_no_width_big_precision);
  tcase_add_test(tcase_core, float_G_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, float_null_small_width_no_precision);
  tcase_add_test(tcase_core, float_null_neg_small_width_no_precision);
  tcase_add_test(tcase_core, float_fraction_short_small_width_no_precision);
  tcase_add_test(tcase_core, float_general_short_small_width_no_precision);
  tcase_add_test(tcase_core, float_exp_null_small_width_no_precision);
  tcase_add_test(tcase_core, float_exp_null_neg_small_width_no_precision);
  tcase_add_test(tcase_core, float_exp_fraction_short_small_width_no_precision);
  tcase_add_test(tcase_core, float_exp_general_short_small_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_null_small_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_null_neg_small_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_fraction_short_small_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_general_short_small_width_no_precision);
  tcase_add_test(tcase_core, float_g_null_small_width_no_precision);
  tcase_add_test(tcase_core, float_g_null_neg_small_width_no_precision);
  tcase_add_test(tcase_core, float_g_fraction_short_small_width_no_precision);
  tcase_add_test(tcase_core, float_g_general_short_small_width_no_precision);
  tcase_add_test(tcase_core, float_G_null_small_width_no_precision);
  tcase_add_test(tcase_core, float_G_null_neg_small_width_no_precision);
  tcase_add_test(tcase_core, float_G_fraction_short_small_width_no_precision);
  tcase_add_test(tcase_core, float_G_general_short_small_width_no_precision);
  tcase_add_test(tcase_core, float_null_small_width_small_precision);
  tcase_add_test(tcase_core, float_null_neg_small_width_small_precision);
  tcase_add_test(tcase_core, float_fraction_short_small_width_small_precision);
  tcase_add_test(tcase_core, float_general_short_small_width_small_precision);
  tcase_add_test(tcase_core, float_exp_null_small_width_small_precision);
  tcase_add_test(tcase_core, float_exp_null_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 float_exp_fraction_short_small_width_small_precision);
  tcase_add_test(tcase_core,
                 float_exp_general_short_small_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_null_small_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_null_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 float_EXP_fraction_short_small_width_small_precision);
  tcase_add_test(tcase_core,
                 float_EXP_general_short_small_width_small_precision);
  tcase_add_test(tcase_core, float_g_null_small_width_small_precision);
  tcase_add_test(tcase_core, float_g_null_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 float_g_fraction_short_small_width_small_precision);
  tcase_add_test(tcase_core, float_g_general_short_small_width_small_precision);
  tcase_add_test(tcase_core, float_G_null_small_width_small_precision);
  tcase_add_test(tcase_core, float_G_null_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 float_G_fraction_short_small_width_small_precision);
  tcase_add_test(tcase_core, float_G_general_short_small_width_small_precision);
  tcase_add_test(tcase_core, float_null_small_width_big_precision);
  tcase_add_test(tcase_core, float_null_neg_small_width_big_precision);
  tcase_add_test(tcase_core, float_fraction_short_small_width_big_precision);
  tcase_add_test(tcase_core, float_general_short_small_width_big_precision);
  tcase_add_test(tcase_core, float_exp_null_small_width_big_precision);
  tcase_add_test(tcase_core, float_exp_null_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 float_exp_fraction_short_small_width_big_precision);
  tcase_add_test(tcase_core, float_exp_general_short_small_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_null_small_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_null_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 float_EXP_fraction_short_small_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_general_short_small_width_big_precision);
  tcase_add_test(tcase_core, float_g_null_small_width_big_precision);
  tcase_add_test(tcase_core, float_g_null_neg_small_width_big_precision);
  tcase_add_test(tcase_core, float_g_fraction_short_small_width_big_precision);
  tcase_add_test(tcase_core, float_g_general_short_small_width_big_precision);
  tcase_add_test(tcase_core, float_G_null_small_width_big_precision);
  tcase_add_test(tcase_core, float_G_null_neg_small_width_big_precision);
  tcase_add_test(tcase_core, float_G_fraction_short_small_width_big_precision);
  tcase_add_test(tcase_core, float_G_general_short_small_width_big_precision);
  tcase_add_test(tcase_core, float_null_big_width_no_precision);
  tcase_add_test(tcase_core, float_null_neg_big_width_no_precision);
  tcase_add_test(tcase_core, float_fraction_short_big_width_no_precision);
  tcase_add_test(tcase_core, float_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, float_exp_null_big_width_no_precision);
  tcase_add_test(tcase_core, float_exp_null_neg_big_width_no_precision);
  tcase_add_test(tcase_core, float_exp_fraction_short_big_width_no_precision);
  tcase_add_test(tcase_core, float_exp_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_null_big_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_null_neg_big_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_fraction_short_big_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, float_g_null_big_width_no_precision);
  tcase_add_test(tcase_core, float_g_null_neg_big_width_no_precision);
  tcase_add_test(tcase_core, float_g_fraction_short_big_width_no_precision);
  tcase_add_test(tcase_core, float_g_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, float_G_null_big_width_no_precision);
  tcase_add_test(tcase_core, float_G_null_neg_big_width_no_precision);
  tcase_add_test(tcase_core, float_G_fraction_short_big_width_no_precision);
  tcase_add_test(tcase_core, float_G_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, float_null_big_width_small_precision);
  tcase_add_test(tcase_core, float_null_neg_big_width_small_precision);
  tcase_add_test(tcase_core, float_fraction_short_big_width_small_precision);
  tcase_add_test(tcase_core, float_general_short_big_width_small_precision);
  tcase_add_test(tcase_core, float_exp_null_big_width_small_precision);
  tcase_add_test(tcase_core, float_exp_null_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 float_exp_fraction_short_big_width_small_precision);
  tcase_add_test(tcase_core, float_exp_general_short_big_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_null_big_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_null_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 float_EXP_fraction_short_big_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_general_short_big_width_small_precision);
  tcase_add_test(tcase_core, float_g_null_big_width_small_precision);
  tcase_add_test(tcase_core, float_g_null_neg_big_width_small_precision);
  tcase_add_test(tcase_core, float_g_fraction_short_big_width_small_precision);
  tcase_add_test(tcase_core, float_g_general_short_big_width_small_precision);
  tcase_add_test(tcase_core, float_G_null_big_width_small_precision);
  tcase_add_test(tcase_core, float_G_null_neg_big_width_small_precision);
  tcase_add_test(tcase_core, float_G_fraction_short_big_width_small_precision);
  tcase_add_test(tcase_core, float_G_general_short_big_width_small_precision);
  tcase_add_test(tcase_core, float_null_big_width_big_precision);
  tcase_add_test(tcase_core, float_null_neg_big_width_big_precision);
  tcase_add_test(tcase_core, float_fraction_short_big_width_big_precision);
  tcase_add_test(tcase_core, float_general_short_big_width_big_precision);
  tcase_add_test(tcase_core, float_exp_null_big_width_big_precision);
  tcase_add_test(tcase_core, float_exp_null_neg_big_width_big_precision);
  tcase_add_test(tcase_core, float_exp_fraction_short_big_width_big_precision);
  tcase_add_test(tcase_core, float_exp_general_short_big_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_null_big_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_null_neg_big_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_fraction_short_big_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_general_short_big_width_big_precision);
  tcase_add_test(tcase_core, float_g_null_big_width_big_precision);
  tcase_add_test(tcase_core, float_g_null_neg_big_width_big_precision);
  tcase_add_test(tcase_core, float_g_fraction_short_big_width_big_precision);
  tcase_add_test(tcase_core, float_g_general_short_big_width_big_precision);
  tcase_add_test(tcase_core, float_G_null_big_width_big_precision);
  tcase_add_test(tcase_core, float_G_null_neg_big_width_big_precision);
  tcase_add_test(tcase_core, float_G_fraction_short_big_width_big_precision);
  tcase_add_test(tcase_core, float_G_general_short_big_width_big_precision);
  tcase_add_test(tcase_core, double_null_no_flags);
  tcase_add_test(tcase_core, double_null_neg_no_flags);
  tcase_add_test(tcase_core, double_fraction_medium_no_flags);
  tcase_add_test(tcase_core, double_general_medium_no_flags);
  tcase_add_test(tcase_core, double_exp_null_no_flags);
  tcase_add_test(tcase_core, double_exp_null_neg_no_flags);
  tcase_add_test(tcase_core, double_exp_fraction_medium_no_flags);
  tcase_add_test(tcase_core, double_exp_general_medium_no_flags);
  tcase_add_test(tcase_core, double_EXP_null_no_flags);
  tcase_add_test(tcase_core, double_EXP_null_neg_no_flags);
  tcase_add_test(tcase_core, double_EXP_fraction_medium_no_flags);
  tcase_add_test(tcase_core, double_EXP_general_medium_no_flags);
  tcase_add_test(tcase_core, double_g_null_no_flags);
  tcase_add_test(tcase_core, double_g_null_neg_no_flags);
  tcase_add_test(tcase_core, double_g_fraction_medium_no_flags);
  tcase_add_test(tcase_core, double_g_general_medium_no_flags);
  tcase_add_test(tcase_core, double_G_null_no_flags);
  tcase_add_test(tcase_core, double_G_null_neg_no_flags);
  tcase_add_test(tcase_core, double_G_fraction_medium_no_flags);
  tcase_add_test(tcase_core, double_G_general_medium_no_flags);
  tcase_add_test(tcase_core, double_null_prefix_sign);
  tcase_add_test(tcase_core, double_null_neg_prefix_sign);
  tcase_add_test(tcase_core, double_fraction_medium_prefix_sign);
  tcase_add_test(tcase_core, double_general_medium_prefix_sign);
  tcase_add_test(tcase_core, double_exp_null_prefix_sign);
  tcase_add_test(tcase_core, double_exp_null_neg_prefix_sign);
  tcase_add_test(tcase_core, double_exp_fraction_medium_prefix_sign);
  tcase_add_test(tcase_core, double_exp_general_medium_prefix_sign);
  tcase_add_test(tcase_core, double_EXP_null_prefix_sign);
  tcase_add_test(tcase_core, double_EXP_null_neg_prefix_sign);
  tcase_add_test(tcase_core, double_EXP_fraction_medium_prefix_sign);
  tcase_add_test(tcase_core, double_EXP_general_medium_prefix_sign);
  tcase_add_test(tcase_core, double_g_null_prefix_sign);
  tcase_add_test(tcase_core, double_g_null_neg_prefix_sign);
  tcase_add_test(tcase_core, double_g_fraction_medium_prefix_sign);
  tcase_add_test(tcase_core, double_g_general_medium_prefix_sign);
  tcase_add_test(tcase_core, double_G_null_prefix_sign);
  tcase_add_test(tcase_core, double_G_null_neg_prefix_sign);
  tcase_add_test(tcase_core, double_G_fraction_medium_prefix_sign);
  tcase_add_test(tcase_core, double_G_general_medium_prefix_sign);
  tcase_add_test(tcase_core, double_null_prefix_space);
  tcase_add_test(tcase_core, double_null_neg_prefix_space);
  tcase_add_test(tcase_core, double_fraction_medium_prefix_space);
  tcase_add_test(tcase_core, double_general_medium_prefix_space);
  tcase_add_test(tcase_core, double_exp_null_prefix_space);
  tcase_add_test(tcase_core, double_exp_null_neg_prefix_space);
  tcase_add_test(tcase_core, double_exp_fraction_medium_prefix_space);
  tcase_add_test(tcase_core, double_exp_general_medium_prefix_space);
  tcase_add_test(tcase_core, double_EXP_null_prefix_space);
  tcase_add_test(tcase_core, double_EXP_null_neg_prefix_space);
  tcase_add_test(tcase_core, double_EXP_fraction_medium_prefix_space);
  tcase_add_test(tcase_core, double_EXP_general_medium_prefix_space);
  tcase_add_test(tcase_core, double_g_null_prefix_space);
  tcase_add_test(tcase_core, double_g_null_neg_prefix_space);
  tcase_add_test(tcase_core, double_g_fraction_medium_prefix_space);
  tcase_add_test(tcase_core, double_g_general_medium_prefix_space);
  tcase_add_test(tcase_core, double_G_null_prefix_space);
  tcase_add_test(tcase_core, double_G_null_neg_prefix_space);
  tcase_add_test(tcase_core, double_G_fraction_medium_prefix_space);
  tcase_add_test(tcase_core, double_G_general_medium_prefix_space);
  tcase_add_test(tcase_core, double_null_left_alignment);
  tcase_add_test(tcase_core, double_null_neg_left_alignment);
  tcase_add_test(tcase_core, double_fraction_medium_left_alignment);
  tcase_add_test(tcase_core, double_general_medium_left_alignment);
  tcase_add_test(tcase_core, double_exp_null_left_alignment);
  tcase_add_test(tcase_core, double_exp_null_neg_left_alignment);
  tcase_add_test(tcase_core, double_exp_fraction_medium_left_alignment);
  tcase_add_test(tcase_core, double_exp_general_medium_left_alignment);
  tcase_add_test(tcase_core, double_EXP_null_left_alignment);
  tcase_add_test(tcase_core, double_EXP_null_neg_left_alignment);
  tcase_add_test(tcase_core, double_EXP_fraction_medium_left_alignment);
  tcase_add_test(tcase_core, double_EXP_general_medium_left_alignment);
  tcase_add_test(tcase_core, double_g_null_left_alignment);
  tcase_add_test(tcase_core, double_g_null_neg_left_alignment);
  tcase_add_test(tcase_core, double_g_fraction_medium_left_alignment);
  tcase_add_test(tcase_core, double_g_general_medium_left_alignment);
  tcase_add_test(tcase_core, double_G_null_left_alignment);
  tcase_add_test(tcase_core, double_G_null_neg_left_alignment);
  tcase_add_test(tcase_core, double_G_fraction_medium_left_alignment);
  tcase_add_test(tcase_core, double_G_general_medium_left_alignment);
  tcase_add_test(tcase_core, double_null_leading_zeroes);
  tcase_add_test(tcase_core, double_null_neg_leading_zeroes);
  tcase_add_test(tcase_core, double_fraction_medium_leading_zeroes);
  tcase_add_test(tcase_core, double_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, double_exp_null_leading_zeroes);
  tcase_add_test(tcase_core, double_exp_null_neg_leading_zeroes);
  tcase_add_test(tcase_core, double_exp_fraction_medium_leading_zeroes);
  tcase_add_test(tcase_core, double_exp_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, double_EXP_null_leading_zeroes);
  tcase_add_test(tcase_core, double_EXP_null_neg_leading_zeroes);
  tcase_add_test(tcase_core, double_EXP_fraction_medium_leading_zeroes);
  tcase_add_test(tcase_core, double_EXP_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, double_g_null_leading_zeroes);
  tcase_add_test(tcase_core, double_g_null_neg_leading_zeroes);
  tcase_add_test(tcase_core, double_g_fraction_medium_leading_zeroes);
  tcase_add_test(tcase_core, double_g_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, double_G_null_leading_zeroes);
  tcase_add_test(tcase_core, double_G_null_neg_leading_zeroes);
  tcase_add_test(tcase_core, double_G_fraction_medium_leading_zeroes);
  tcase_add_test(tcase_core, double_G_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, double_null_alt_format);
  tcase_add_test(tcase_core, double_null_neg_alt_format);
  tcase_add_test(tcase_core, double_fraction_medium_alt_format);
  tcase_add_test(tcase_core, double_general_medium_alt_format);
  tcase_add_test(tcase_core, double_exp_null_alt_format);
  tcase_add_test(tcase_core, double_exp_null_neg_alt_format);
  tcase_add_test(tcase_core, double_exp_fraction_medium_alt_format);
  tcase_add_test(tcase_core, double_exp_general_medium_alt_format);
  tcase_add_test(tcase_core, double_EXP_null_alt_format);
  tcase_add_test(tcase_core, double_EXP_null_neg_alt_format);
  tcase_add_test(tcase_core, double_EXP_fraction_medium_alt_format);
  tcase_add_test(tcase_core, double_EXP_general_medium_alt_format);
  tcase_add_test(tcase_core, double_g_null_alt_format);
  tcase_add_test(tcase_core, double_g_null_neg_alt_format);
  tcase_add_test(tcase_core, double_g_fraction_medium_alt_format);
  tcase_add_test(tcase_core, double_g_general_medium_alt_format);
  tcase_add_test(tcase_core, double_G_null_alt_format);
  tcase_add_test(tcase_core, double_G_null_neg_alt_format);
  tcase_add_test(tcase_core, double_G_fraction_medium_alt_format);
  tcase_add_test(tcase_core, double_G_general_medium_alt_format);
  tcase_add_test(tcase_core, double_null_no_width_no_precision);
  tcase_add_test(tcase_core, double_null_neg_no_width_no_precision);
  tcase_add_test(tcase_core, double_fraction_medium_no_width_no_precision);
  tcase_add_test(tcase_core, double_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core, double_exp_null_no_width_no_precision);
  tcase_add_test(tcase_core, double_exp_null_neg_no_width_no_precision);
  tcase_add_test(tcase_core, double_exp_fraction_medium_no_width_no_precision);
  tcase_add_test(tcase_core, double_exp_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_null_no_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_null_neg_no_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_fraction_medium_no_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core, double_g_null_no_width_no_precision);
  tcase_add_test(tcase_core, double_g_null_neg_no_width_no_precision);
  tcase_add_test(tcase_core, double_g_fraction_medium_no_width_no_precision);
  tcase_add_test(tcase_core, double_g_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core, double_G_null_no_width_no_precision);
  tcase_add_test(tcase_core, double_G_null_neg_no_width_no_precision);
  tcase_add_test(tcase_core, double_G_fraction_medium_no_width_no_precision);
  tcase_add_test(tcase_core, double_G_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core, double_null_no_width_small_precision);
  tcase_add_test(tcase_core, double_null_neg_no_width_small_precision);
  tcase_add_test(tcase_core, double_fraction_medium_no_width_small_precision);
  tcase_add_test(tcase_core, double_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core, double_exp_null_no_width_small_precision);
  tcase_add_test(tcase_core, double_exp_null_neg_no_width_small_precision);
  tcase_add_test(tcase_core,
                 double_exp_fraction_medium_no_width_small_precision);
  tcase_add_test(tcase_core,
                 double_exp_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_null_no_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_null_neg_no_width_small_precision);
  tcase_add_test(tcase_core,
                 double_EXP_fraction_medium_no_width_small_precision);
  tcase_add_test(tcase_core,
                 double_EXP_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core, double_g_null_no_width_small_precision);
  tcase_add_test(tcase_core, double_g_null_neg_no_width_small_precision);
  tcase_add_test(tcase_core, double_g_fraction_medium_no_width_small_precision);
  tcase_add_test(tcase_core, double_g_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core, double_G_null_no_width_small_precision);
  tcase_add_test(tcase_core, double_G_null_neg_no_width_small_precision);
  tcase_add_test(tcase_core, double_G_fraction_medium_no_width_small_precision);
  tcase_add_test(tcase_core, double_G_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core, double_null_no_width_big_precision);
  tcase_add_test(tcase_core, double_null_neg_no_width_big_precision);
  tcase_add_test(tcase_core, double_fraction_medium_no_width_big_precision);
  tcase_add_test(tcase_core, double_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core, double_exp_null_no_width_big_precision);
  tcase_add_test(tcase_core, double_exp_null_neg_no_width_big_precision);
  tcase_add_test(tcase_core, double_exp_fraction_medium_no_width_big_precision);
  tcase_add_test(tcase_core, double_exp_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_null_no_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_null_neg_no_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_fraction_medium_no_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core, double_g_null_no_width_big_precision);
  tcase_add_test(tcase_core, double_g_null_neg_no_width_big_precision);
  tcase_add_test(tcase_core, double_g_fraction_medium_no_width_big_precision);
  tcase_add_test(tcase_core, double_g_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core, double_G_null_no_width_big_precision);
  tcase_add_test(tcase_core, double_G_null_neg_no_width_big_precision);
  tcase_add_test(tcase_core, double_G_fraction_medium_no_width_big_precision);
  tcase_add_test(tcase_core, double_G_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core, double_null_small_width_no_precision);
  tcase_add_test(tcase_core, double_null_neg_small_width_no_precision);
  tcase_add_test(tcase_core, double_fraction_medium_small_width_no_precision);
  tcase_add_test(tcase_core, double_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core, double_exp_null_small_width_no_precision);
  tcase_add_test(tcase_core, double_exp_null_neg_small_width_no_precision);
  tcase_add_test(tcase_core,
                 double_exp_fraction_medium_small_width_no_precision);
  tcase_add_test(tcase_core,
                 double_exp_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_null_small_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_null_neg_small_width_no_precision);
  tcase_add_test(tcase_core,
                 double_EXP_fraction_medium_small_width_no_precision);
  tcase_add_test(tcase_core,
                 double_EXP_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core, double_g_null_small_width_no_precision);
  tcase_add_test(tcase_core, double_g_null_neg_small_width_no_precision);
  tcase_add_test(tcase_core, double_g_fraction_medium_small_width_no_precision);
  tcase_add_test(tcase_core, double_g_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core, double_G_null_small_width_no_precision);
  tcase_add_test(tcase_core, double_G_null_neg_small_width_no_precision);
  tcase_add_test(tcase_core, double_G_fraction_medium_small_width_no_precision);
  tcase_add_test(tcase_core, double_G_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core, double_null_small_width_small_precision);
  tcase_add_test(tcase_core, double_null_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 double_fraction_medium_small_width_small_precision);
  tcase_add_test(tcase_core, double_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core, double_exp_null_small_width_small_precision);
  tcase_add_test(tcase_core, double_exp_null_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 double_exp_fraction_medium_small_width_small_precision);
  tcase_add_test(tcase_core,
                 double_exp_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_null_small_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_null_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 double_EXP_fraction_medium_small_width_small_precision);
  tcase_add_test(tcase_core,
                 double_EXP_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core, double_g_null_small_width_small_precision);
  tcase_add_test(tcase_core, double_g_null_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 double_g_fraction_medium_small_width_small_precision);
  tcase_add_test(tcase_core,
                 double_g_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core, double_G_null_small_width_small_precision);
  tcase_add_test(tcase_core, double_G_null_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 double_G_fraction_medium_small_width_small_precision);
  tcase_add_test(tcase_core,
                 double_G_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core, double_null_small_width_big_precision);
  tcase_add_test(tcase_core, double_null_neg_small_width_big_precision);
  tcase_add_test(tcase_core, double_fraction_medium_small_width_big_precision);
  tcase_add_test(tcase_core, double_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core, double_exp_null_small_width_big_precision);
  tcase_add_test(tcase_core, double_exp_null_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 double_exp_fraction_medium_small_width_big_precision);
  tcase_add_test(tcase_core,
                 double_exp_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_null_small_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_null_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 double_EXP_fraction_medium_small_width_big_precision);
  tcase_add_test(tcase_core,
                 double_EXP_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core, double_g_null_small_width_big_precision);
  tcase_add_test(tcase_core, double_g_null_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 double_g_fraction_medium_small_width_big_precision);
  tcase_add_test(tcase_core, double_g_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core, double_G_null_small_width_big_precision);
  tcase_add_test(tcase_core, double_G_null_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 double_G_fraction_medium_small_width_big_precision);
  tcase_add_test(tcase_core, double_G_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core, double_null_big_width_no_precision);
  tcase_add_test(tcase_core, double_null_neg_big_width_no_precision);
  tcase_add_test(tcase_core, double_fraction_medium_big_width_no_precision);
  tcase_add_test(tcase_core, double_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core, double_exp_null_big_width_no_precision);
  tcase_add_test(tcase_core, double_exp_null_neg_big_width_no_precision);
  tcase_add_test(tcase_core, double_exp_fraction_medium_big_width_no_precision);
  tcase_add_test(tcase_core, double_exp_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_null_big_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_null_neg_big_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_fraction_medium_big_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core, double_g_null_big_width_no_precision);
  tcase_add_test(tcase_core, double_g_null_neg_big_width_no_precision);
  tcase_add_test(tcase_core, double_g_fraction_medium_big_width_no_precision);
  tcase_add_test(tcase_core, double_g_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core, double_G_null_big_width_no_precision);
  tcase_add_test(tcase_core, double_G_null_neg_big_width_no_precision);
  tcase_add_test(tcase_core, double_G_fraction_medium_big_width_no_precision);
  tcase_add_test(tcase_core, double_G_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core, double_null_big_width_small_precision);
  tcase_add_test(tcase_core, double_null_neg_big_width_small_precision);
  tcase_add_test(tcase_core, double_fraction_medium_big_width_small_precision);
  tcase_add_test(tcase_core, double_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core, double_exp_null_big_width_small_precision);
  tcase_add_test(tcase_core, double_exp_null_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 double_exp_fraction_medium_big_width_small_precision);
  tcase_add_test(tcase_core,
                 double_exp_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_null_big_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_null_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 double_EXP_fraction_medium_big_width_small_precision);
  tcase_add_test(tcase_core,
                 double_EXP_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core, double_g_null_big_width_small_precision);
  tcase_add_test(tcase_core, double_g_null_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 double_g_fraction_medium_big_width_small_precision);
  tcase_add_test(tcase_core, double_g_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core, double_G_null_big_width_small_precision);
  tcase_add_test(tcase_core, double_G_null_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 double_G_fraction_medium_big_width_small_precision);
  tcase_add_test(tcase_core, double_G_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core, double_null_big_width_big_precision);
  tcase_add_test(tcase_core, double_null_neg_big_width_big_precision);
  tcase_add_test(tcase_core, double_fraction_medium_big_width_big_precision);
  tcase_add_test(tcase_core, double_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core, double_exp_null_big_width_big_precision);
  tcase_add_test(tcase_core, double_exp_null_neg_big_width_big_precision);
  tcase_add_test(tcase_core,
                 double_exp_fraction_medium_big_width_big_precision);
  tcase_add_test(tcase_core, double_exp_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_null_big_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_null_neg_big_width_big_precision);
  tcase_add_test(tcase_core,
                 double_EXP_fraction_medium_big_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core, double_g_null_big_width_big_precision);
  tcase_add_test(tcase_core, double_g_null_neg_big_width_big_precision);
  tcase_add_test(tcase_core, double_g_fraction_medium_big_width_big_precision);
  tcase_add_test(tcase_core, double_g_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core, double_G_null_big_width_big_precision);
  tcase_add_test(tcase_core, double_G_null_neg_big_width_big_precision);
  tcase_add_test(tcase_core, double_G_fraction_medium_big_width_big_precision);
  tcase_add_test(tcase_core, double_G_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_null_no_flags);
  tcase_add_test(tcase_core, long_double_null_neg_no_flags);
  tcase_add_test(tcase_core, long_double_fraction_long_no_flags);
  tcase_add_test(tcase_core, long_double_general_long_no_flags);
  tcase_add_test(tcase_core, long_double_exp_null_no_flags);
  tcase_add_test(tcase_core, long_double_exp_null_neg_no_flags);
  tcase_add_test(tcase_core, long_double_exp_fraction_long_no_flags);
  tcase_add_test(tcase_core, long_double_exp_general_long_no_flags);
  tcase_add_test(tcase_core, long_double_EXP_null_no_flags);
  tcase_add_test(tcase_core, long_double_EXP_null_neg_no_flags);
  tcase_add_test(tcase_core, long_double_EXP_fraction_long_no_flags);
  tcase_add_test(tcase_core, long_double_EXP_general_long_no_flags);
  tcase_add_test(tcase_core, long_double_g_null_no_flags);
  tcase_add_test(tcase_core, long_double_g_null_neg_no_flags);
  tcase_add_test(tcase_core, long_double_g_fraction_long_no_flags);
  tcase_add_test(tcase_core, long_double_g_general_long_no_flags);
  tcase_add_test(tcase_core, long_double_G_null_no_flags);
  tcase_add_test(tcase_core, long_double_G_null_neg_no_flags);
  tcase_add_test(tcase_core, long_double_G_fraction_long_no_flags);
  tcase_add_test(tcase_core, long_double_G_general_long_no_flags);
  tcase_add_test(tcase_core, long_double_null_prefix_sign);
  tcase_add_test(tcase_core, long_double_null_neg_prefix_sign);
  tcase_add_test(tcase_core, long_double_fraction_long_prefix_sign);
  tcase_add_test(tcase_core, long_double_general_long_prefix_sign);
  tcase_add_test(tcase_core, long_double_exp_null_prefix_sign);
  tcase_add_test(tcase_core, long_double_exp_null_neg_prefix_sign);
  tcase_add_test(tcase_core, long_double_exp_fraction_long_prefix_sign);
  tcase_add_test(tcase_core, long_double_exp_general_long_prefix_sign);
  tcase_add_test(tcase_core, long_double_EXP_null_prefix_sign);
  tcase_add_test(tcase_core, long_double_EXP_null_neg_prefix_sign);
  tcase_add_test(tcase_core, long_double_EXP_fraction_long_prefix_sign);
  tcase_add_test(tcase_core, long_double_EXP_general_long_prefix_sign);
  tcase_add_test(tcase_core, long_double_g_null_prefix_sign);
  tcase_add_test(tcase_core, long_double_g_null_neg_prefix_sign);
  tcase_add_test(tcase_core, long_double_g_fraction_long_prefix_sign);
  tcase_add_test(tcase_core, long_double_g_general_long_prefix_sign);
  tcase_add_test(tcase_core, long_double_G_null_prefix_sign);
  tcase_add_test(tcase_core, long_double_G_null_neg_prefix_sign);
  tcase_add_test(tcase_core, long_double_G_fraction_long_prefix_sign);
  tcase_add_test(tcase_core, long_double_G_general_long_prefix_sign);
  tcase_add_test(tcase_core, long_double_null_prefix_space);
  tcase_add_test(tcase_core, long_double_null_neg_prefix_space);
  tcase_add_test(tcase_core, long_double_fraction_long_prefix_space);
  tcase_add_test(tcase_core, long_double_general_long_prefix_space);
  tcase_add_test(tcase_core, long_double_exp_null_prefix_space);
  tcase_add_test(tcase_core, long_double_exp_null_neg_prefix_space);
  tcase_add_test(tcase_core, long_double_exp_fraction_long_prefix_space);
  tcase_add_test(tcase_core, long_double_exp_general_long_prefix_space);
  tcase_add_test(tcase_core, long_double_EXP_null_prefix_space);
  tcase_add_test(tcase_core, long_double_EXP_null_neg_prefix_space);
  tcase_add_test(tcase_core, long_double_EXP_fraction_long_prefix_space);
  tcase_add_test(tcase_core, long_double_EXP_general_long_prefix_space);
  tcase_add_test(tcase_core, long_double_g_null_prefix_space);
  tcase_add_test(tcase_core, long_double_g_null_neg_prefix_space);
  tcase_add_test(tcase_core, long_double_g_fraction_long_prefix_space);
  tcase_add_test(tcase_core, long_double_g_general_long_prefix_space);
  tcase_add_test(tcase_core, long_double_G_null_prefix_space);
  tcase_add_test(tcase_core, long_double_G_null_neg_prefix_space);
  tcase_add_test(tcase_core, long_double_G_fraction_long_prefix_space);
  tcase_add_test(tcase_core, long_double_G_general_long_prefix_space);
  tcase_add_test(tcase_core, long_double_null_left_alignment);
  tcase_add_test(tcase_core, long_double_null_neg_left_alignment);
  tcase_add_test(tcase_core, long_double_fraction_long_left_alignment);
  tcase_add_test(tcase_core, long_double_general_long_left_alignment);
  tcase_add_test(tcase_core, long_double_exp_null_left_alignment);
  tcase_add_test(tcase_core, long_double_exp_null_neg_left_alignment);
  tcase_add_test(tcase_core, long_double_exp_fraction_long_left_alignment);
  tcase_add_test(tcase_core, long_double_exp_general_long_left_alignment);
  tcase_add_test(tcase_core, long_double_EXP_null_left_alignment);
  tcase_add_test(tcase_core, long_double_EXP_null_neg_left_alignment);
  tcase_add_test(tcase_core, long_double_EXP_fraction_long_left_alignment);
  tcase_add_test(tcase_core, long_double_EXP_general_long_left_alignment);
  tcase_add_test(tcase_core, long_double_g_null_left_alignment);
  tcase_add_test(tcase_core, long_double_g_null_neg_left_alignment);
  tcase_add_test(tcase_core, long_double_g_fraction_long_left_alignment);
  tcase_add_test(tcase_core, long_double_g_general_long_left_alignment);
  tcase_add_test(tcase_core, long_double_G_null_left_alignment);
  tcase_add_test(tcase_core, long_double_G_null_neg_left_alignment);
  tcase_add_test(tcase_core, long_double_G_fraction_long_left_alignment);
  tcase_add_test(tcase_core, long_double_G_general_long_left_alignment);
  tcase_add_test(tcase_core, long_double_null_leading_zeroes);
  tcase_add_test(tcase_core, long_double_null_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_double_fraction_long_leading_zeroes);
  tcase_add_test(tcase_core, long_double_general_long_leading_zeroes);
  tcase_add_test(tcase_core, long_double_exp_null_leading_zeroes);
  tcase_add_test(tcase_core, long_double_exp_null_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_double_exp_fraction_long_leading_zeroes);
  tcase_add_test(tcase_core, long_double_exp_general_long_leading_zeroes);
  tcase_add_test(tcase_core, long_double_EXP_null_leading_zeroes);
  tcase_add_test(tcase_core, long_double_EXP_null_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_double_EXP_fraction_long_leading_zeroes);
  tcase_add_test(tcase_core, long_double_EXP_general_long_leading_zeroes);
  tcase_add_test(tcase_core, long_double_g_null_leading_zeroes);
  tcase_add_test(tcase_core, long_double_g_null_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_double_g_fraction_long_leading_zeroes);
  tcase_add_test(tcase_core, long_double_g_general_long_leading_zeroes);
  tcase_add_test(tcase_core, long_double_G_null_leading_zeroes);
  tcase_add_test(tcase_core, long_double_G_null_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_double_G_fraction_long_leading_zeroes);
  tcase_add_test(tcase_core, long_double_G_general_long_leading_zeroes);
  tcase_add_test(tcase_core, long_double_null_alt_format);
  tcase_add_test(tcase_core, long_double_null_neg_alt_format);
  tcase_add_test(tcase_core, long_double_fraction_long_alt_format);
  tcase_add_test(tcase_core, long_double_general_long_alt_format);
  tcase_add_test(tcase_core, long_double_exp_null_alt_format);
  tcase_add_test(tcase_core, long_double_exp_null_neg_alt_format);
  tcase_add_test(tcase_core, long_double_exp_fraction_long_alt_format);
  tcase_add_test(tcase_core, long_double_exp_general_long_alt_format);
  tcase_add_test(tcase_core, long_double_EXP_null_alt_format);
  tcase_add_test(tcase_core, long_double_EXP_null_neg_alt_format);
  tcase_add_test(tcase_core, long_double_EXP_fraction_long_alt_format);
  tcase_add_test(tcase_core, long_double_EXP_general_long_alt_format);
  tcase_add_test(tcase_core, long_double_g_null_alt_format);
  tcase_add_test(tcase_core, long_double_g_null_neg_alt_format);
  tcase_add_test(tcase_core, long_double_g_fraction_long_alt_format);
  tcase_add_test(tcase_core, long_double_g_general_long_alt_format);
  tcase_add_test(tcase_core, long_double_G_null_alt_format);
  tcase_add_test(tcase_core, long_double_G_null_neg_alt_format);
  tcase_add_test(tcase_core, long_double_G_fraction_long_alt_format);
  tcase_add_test(tcase_core, long_double_G_general_long_alt_format);
  tcase_add_test(tcase_core, long_double_null_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_null_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_fraction_long_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_general_long_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_exp_null_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_exp_null_neg_no_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_fraction_long_no_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_general_long_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_EXP_null_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_EXP_null_neg_no_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_fraction_long_no_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_general_long_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_null_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_null_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_fraction_long_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_general_long_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_null_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_null_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_fraction_long_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_general_long_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_null_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_null_neg_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_fraction_long_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_general_long_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_exp_null_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_exp_null_neg_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_fraction_long_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_general_long_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_EXP_null_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_EXP_null_neg_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_fraction_long_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_general_long_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_g_null_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_g_null_neg_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_g_fraction_long_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_g_general_long_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_G_null_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_G_null_neg_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_G_fraction_long_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_G_general_long_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_null_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_null_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_fraction_long_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_general_long_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_exp_null_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_exp_null_neg_no_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_fraction_long_no_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_general_long_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_EXP_null_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_EXP_null_neg_no_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_fraction_long_no_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_general_long_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_null_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_null_neg_no_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_g_fraction_long_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_general_long_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_null_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_null_neg_no_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_G_fraction_long_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_general_long_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_null_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_null_neg_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_fraction_long_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_general_long_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_exp_null_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_exp_null_neg_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_fraction_long_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_general_long_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_EXP_null_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_EXP_null_neg_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_fraction_long_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_general_long_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_null_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_null_neg_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_g_fraction_long_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_g_general_long_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_null_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_null_neg_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_G_fraction_long_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_G_general_long_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_null_small_width_small_precision);
  tcase_add_test(tcase_core, long_double_null_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_fraction_long_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_general_long_small_width_small_precision);
  tcase_add_test(tcase_core, long_double_exp_null_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_null_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_fraction_long_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_general_long_small_width_small_precision);
  tcase_add_test(tcase_core, long_double_EXP_null_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_null_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_fraction_long_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_general_long_small_width_small_precision);
  tcase_add_test(tcase_core, long_double_g_null_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_g_null_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_g_fraction_long_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_g_general_long_small_width_small_precision);
  tcase_add_test(tcase_core, long_double_G_null_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_G_null_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_G_fraction_long_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_G_general_long_small_width_small_precision);
  tcase_add_test(tcase_core, long_double_null_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_null_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_fraction_long_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_general_long_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_exp_null_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_null_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_fraction_long_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_general_long_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_EXP_null_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_null_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_fraction_long_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_general_long_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_null_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_null_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_g_fraction_long_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_g_general_long_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_null_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_null_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_G_fraction_long_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_G_general_long_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_null_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_null_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_fraction_long_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_general_long_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_exp_null_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_exp_null_neg_big_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_fraction_long_big_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_general_long_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_EXP_null_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_EXP_null_neg_big_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_fraction_long_big_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_general_long_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_null_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_null_neg_big_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_g_fraction_long_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_general_long_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_null_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_null_neg_big_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_G_fraction_long_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_general_long_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_null_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_null_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_fraction_long_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_general_long_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_exp_null_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_null_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_fraction_long_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_general_long_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_EXP_null_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_null_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_fraction_long_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_general_long_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_g_null_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_g_null_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_g_fraction_long_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_g_general_long_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_G_null_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_G_null_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_G_fraction_long_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_G_general_long_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_null_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_null_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_fraction_long_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_general_long_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_exp_null_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_exp_null_neg_big_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_fraction_long_big_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_general_long_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_EXP_null_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_EXP_null_neg_big_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_fraction_long_big_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_general_long_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_null_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_null_neg_big_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_g_fraction_long_big_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_g_general_long_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_null_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_null_neg_big_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_G_fraction_long_big_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_G_general_long_big_width_big_precision);
  tcase_add_test(tcase_core, float_nan_no_flags);
  tcase_add_test(tcase_core, float_nan_neg_no_flags);
  tcase_add_test(tcase_core, float_infinity_no_flags);
  tcase_add_test(tcase_core, float_infinity_neg_no_flags);
  tcase_add_test(tcase_core, double_nan_no_flags);
  tcase_add_test(tcase_core, double_nan_neg_no_flags);
  tcase_add_test(tcase_core, double_infinity_no_flags);
  tcase_add_test(tcase_core, double_infinity_neg_no_flags);
  tcase_add_test(tcase_core, long_double_nan_no_flags);
  tcase_add_test(tcase_core, long_double_nan_neg_no_flags);
  tcase_add_test(tcase_core, long_double_infinity_no_flags);
  tcase_add_test(tcase_core, long_double_infinity_neg_no_flags);
  tcase_add_test(tcase_core, float_exp_nan_no_flags);
  tcase_add_test(tcase_core, float_exp_nan_neg_no_flags);
  tcase_add_test(tcase_core, float_exp_infinity_no_flags);
  tcase_add_test(tcase_core, float_exp_infinity_neg_no_flags);
  tcase_add_test(tcase_core, double_exp_nan_no_flags);
  tcase_add_test(tcase_core, double_exp_nan_neg_no_flags);
  tcase_add_test(tcase_core, double_exp_infinity_no_flags);
  tcase_add_test(tcase_core, double_exp_infinity_neg_no_flags);
  tcase_add_test(tcase_core, long_double_exp_nan_no_flags);
  tcase_add_test(tcase_core, long_double_exp_nan_neg_no_flags);
  tcase_add_test(tcase_core, long_double_exp_infinity_no_flags);
  tcase_add_test(tcase_core, long_double_exp_infinity_neg_no_flags);
  tcase_add_test(tcase_core, float_EXP_nan_no_flags);
  tcase_add_test(tcase_core, float_EXP_nan_neg_no_flags);
  tcase_add_test(tcase_core, float_EXP_infinity_no_flags);
  tcase_add_test(tcase_core, float_EXP_infinity_neg_no_flags);
  tcase_add_test(tcase_core, double_EXP_nan_no_flags);
  tcase_add_test(tcase_core, double_EXP_nan_neg_no_flags);
  tcase_add_test(tcase_core, double_EXP_infinity_no_flags);
  tcase_add_test(tcase_core, double_EXP_infinity_neg_no_flags);
  tcase_add_test(tcase_core, long_double_EXP_nan_no_flags);
  tcase_add_test(tcase_core, long_double_EXP_nan_neg_no_flags);
  tcase_add_test(tcase_core, long_double_EXP_infinity_no_flags);
  tcase_add_test(tcase_core, long_double_EXP_infinity_neg_no_flags);
  tcase_add_test(tcase_core, float_g_nan_no_flags);
  tcase_add_test(tcase_core, float_g_nan_neg_no_flags);
  tcase_add_test(tcase_core, float_g_infinity_no_flags);
  tcase_add_test(tcase_core, float_g_infinity_neg_no_flags);
  tcase_add_test(tcase_core, double_g_nan_no_flags);
  tcase_add_test(tcase_core, double_g_nan_neg_no_flags);
  tcase_add_test(tcase_core, double_g_infinity_no_flags);
  tcase_add_test(tcase_core, double_g_infinity_neg_no_flags);
  tcase_add_test(tcase_core, long_double_g_nan_no_flags);
  tcase_add_test(tcase_core, long_double_g_nan_neg_no_flags);
  tcase_add_test(tcase_core, long_double_g_infinity_no_flags);
  tcase_add_test(tcase_core, long_double_g_infinity_neg_no_flags);
  tcase_add_test(tcase_core, float_G_nan_no_flags);
  tcase_add_test(tcase_core, float_G_nan_neg_no_flags);
  tcase_add_test(tcase_core, float_G_infinity_no_flags);
  tcase_add_test(tcase_core, float_G_infinity_neg_no_flags);
  tcase_add_test(tcase_core, double_G_nan_no_flags);
  tcase_add_test(tcase_core, double_G_nan_neg_no_flags);
  tcase_add_test(tcase_core, double_G_infinity_no_flags);
  tcase_add_test(tcase_core, double_G_infinity_neg_no_flags);
  tcase_add_test(tcase_core, long_double_G_nan_no_flags);
  tcase_add_test(tcase_core, long_double_G_nan_neg_no_flags);
  tcase_add_test(tcase_core, long_double_G_infinity_no_flags);
  tcase_add_test(tcase_core, long_double_G_infinity_neg_no_flags);
  tcase_add_test(tcase_core, float_nan_prefix_sign);
  tcase_add_test(tcase_core, float_nan_neg_prefix_sign);
  tcase_add_test(tcase_core, float_infinity_prefix_sign);
  tcase_add_test(tcase_core, float_infinity_neg_prefix_sign);
  tcase_add_test(tcase_core, double_nan_prefix_sign);
  tcase_add_test(tcase_core, double_nan_neg_prefix_sign);
  tcase_add_test(tcase_core, double_infinity_prefix_sign);
  tcase_add_test(tcase_core, double_infinity_neg_prefix_sign);
  tcase_add_test(tcase_core, long_double_nan_prefix_sign);
  tcase_add_test(tcase_core, long_double_nan_neg_prefix_sign);
  tcase_add_test(tcase_core, long_double_infinity_prefix_sign);
  tcase_add_test(tcase_core, long_double_infinity_neg_prefix_sign);
  tcase_add_test(tcase_core, float_exp_nan_prefix_sign);
  tcase_add_test(tcase_core, float_exp_nan_neg_prefix_sign);
  tcase_add_test(tcase_core, float_exp_infinity_prefix_sign);
  tcase_add_test(tcase_core, float_exp_infinity_neg_prefix_sign);
  tcase_add_test(tcase_core, double_exp_nan_prefix_sign);
  tcase_add_test(tcase_core, double_exp_nan_neg_prefix_sign);
  tcase_add_test(tcase_core, double_exp_infinity_prefix_sign);
  tcase_add_test(tcase_core, double_exp_infinity_neg_prefix_sign);
  tcase_add_test(tcase_core, long_double_exp_nan_prefix_sign);
  tcase_add_test(tcase_core, long_double_exp_nan_neg_prefix_sign);
  tcase_add_test(tcase_core, long_double_exp_infinity_prefix_sign);
  tcase_add_test(tcase_core, long_double_exp_infinity_neg_prefix_sign);
  tcase_add_test(tcase_core, float_EXP_nan_prefix_sign);
  tcase_add_test(tcase_core, float_EXP_nan_neg_prefix_sign);
  tcase_add_test(tcase_core, float_EXP_infinity_prefix_sign);
  tcase_add_test(tcase_core, float_EXP_infinity_neg_prefix_sign);
  tcase_add_test(tcase_core, double_EXP_nan_prefix_sign);
  tcase_add_test(tcase_core, double_EXP_nan_neg_prefix_sign);
  tcase_add_test(tcase_core, double_EXP_infinity_prefix_sign);
  tcase_add_test(tcase_core, double_EXP_infinity_neg_prefix_sign);
  tcase_add_test(tcase_core, long_double_EXP_nan_prefix_sign);
  tcase_add_test(tcase_core, long_double_EXP_nan_neg_prefix_sign);
  tcase_add_test(tcase_core, long_double_EXP_infinity_prefix_sign);
  tcase_add_test(tcase_core, long_double_EXP_infinity_neg_prefix_sign);
  tcase_add_test(tcase_core, float_g_nan_prefix_sign);
  tcase_add_test(tcase_core, float_g_nan_neg_prefix_sign);
  tcase_add_test(tcase_core, float_g_infinity_prefix_sign);
  tcase_add_test(tcase_core, float_g_infinity_neg_prefix_sign);
  tcase_add_test(tcase_core, double_g_nan_prefix_sign);
  tcase_add_test(tcase_core, double_g_nan_neg_prefix_sign);
  tcase_add_test(tcase_core, double_g_infinity_prefix_sign);
  tcase_add_test(tcase_core, double_g_infinity_neg_prefix_sign);
  tcase_add_test(tcase_core, long_double_g_nan_prefix_sign);
  tcase_add_test(tcase_core, long_double_g_nan_neg_prefix_sign);
  tcase_add_test(tcase_core, long_double_g_infinity_prefix_sign);
  tcase_add_test(tcase_core, long_double_g_infinity_neg_prefix_sign);
  tcase_add_test(tcase_core, float_G_nan_prefix_sign);
  tcase_add_test(tcase_core, float_G_nan_neg_prefix_sign);
  tcase_add_test(tcase_core, float_G_infinity_prefix_sign);
  tcase_add_test(tcase_core, float_G_infinity_neg_prefix_sign);
  tcase_add_test(tcase_core, double_G_nan_prefix_sign);
  tcase_add_test(tcase_core, double_G_nan_neg_prefix_sign);
  tcase_add_test(tcase_core, double_G_infinity_prefix_sign);
  tcase_add_test(tcase_core, double_G_infinity_neg_prefix_sign);
  tcase_add_test(tcase_core, long_double_G_nan_prefix_sign);
  tcase_add_test(tcase_core, long_double_G_nan_neg_prefix_sign);
  tcase_add_test(tcase_core, long_double_G_infinity_prefix_sign);
  tcase_add_test(tcase_core, long_double_G_infinity_neg_prefix_sign);
  tcase_add_test(tcase_core, float_nan_prefix_space);
  tcase_add_test(tcase_core, float_nan_neg_prefix_space);
  tcase_add_test(tcase_core, float_infinity_prefix_space);
  tcase_add_test(tcase_core, float_infinity_neg_prefix_space);
  tcase_add_test(tcase_core, double_nan_prefix_space);
  tcase_add_test(tcase_core, double_nan_neg_prefix_space);
  tcase_add_test(tcase_core, double_infinity_prefix_space);
  tcase_add_test(tcase_core, double_infinity_neg_prefix_space);
  tcase_add_test(tcase_core, long_double_nan_prefix_space);
  tcase_add_test(tcase_core, long_double_nan_neg_prefix_space);
  tcase_add_test(tcase_core, long_double_infinity_prefix_space);
  tcase_add_test(tcase_core, long_double_infinity_neg_prefix_space);
  tcase_add_test(tcase_core, float_exp_nan_prefix_space);
  tcase_add_test(tcase_core, float_exp_nan_neg_prefix_space);
  tcase_add_test(tcase_core, float_exp_infinity_prefix_space);
  tcase_add_test(tcase_core, float_exp_infinity_neg_prefix_space);
  tcase_add_test(tcase_core, double_exp_nan_prefix_space);
  tcase_add_test(tcase_core, double_exp_nan_neg_prefix_space);
  tcase_add_test(tcase_core, double_exp_infinity_prefix_space);
  tcase_add_test(tcase_core, double_exp_infinity_neg_prefix_space);
  tcase_add_test(tcase_core, long_double_exp_nan_prefix_space);
  tcase_add_test(tcase_core, long_double_exp_nan_neg_prefix_space);
  tcase_add_test(tcase_core, long_double_exp_infinity_prefix_space);
  tcase_add_test(tcase_core, long_double_exp_infinity_neg_prefix_space);
  tcase_add_test(tcase_core, float_EXP_nan_prefix_space);
  tcase_add_test(tcase_core, float_EXP_nan_neg_prefix_space);
  tcase_add_test(tcase_core, float_EXP_infinity_prefix_space);
  tcase_add_test(tcase_core, float_EXP_infinity_neg_prefix_space);
  tcase_add_test(tcase_core, double_EXP_nan_prefix_space);
  tcase_add_test(tcase_core, double_EXP_nan_neg_prefix_space);
  tcase_add_test(tcase_core, double_EXP_infinity_prefix_space);
  tcase_add_test(tcase_core, double_EXP_infinity_neg_prefix_space);
  tcase_add_test(tcase_core, long_double_EXP_nan_prefix_space);
  tcase_add_test(tcase_core, long_double_EXP_nan_neg_prefix_space);
  tcase_add_test(tcase_core, long_double_EXP_infinity_prefix_space);
  tcase_add_test(tcase_core, long_double_EXP_infinity_neg_prefix_space);
  tcase_add_test(tcase_core, float_g_nan_prefix_space);
  tcase_add_test(tcase_core, float_g_nan_neg_prefix_space);
  tcase_add_test(tcase_core, float_g_infinity_prefix_space);
  tcase_add_test(tcase_core, float_g_infinity_neg_prefix_space);
  tcase_add_test(tcase_core, double_g_nan_prefix_space);
  tcase_add_test(tcase_core, double_g_nan_neg_prefix_space);
  tcase_add_test(tcase_core, double_g_infinity_prefix_space);
  tcase_add_test(tcase_core, double_g_infinity_neg_prefix_space);
  tcase_add_test(tcase_core, long_double_g_nan_prefix_space);
  tcase_add_test(tcase_core, long_double_g_nan_neg_prefix_space);
  tcase_add_test(tcase_core, long_double_g_infinity_prefix_space);
  tcase_add_test(tcase_core, long_double_g_infinity_neg_prefix_space);
  tcase_add_test(tcase_core, float_G_nan_prefix_space);
  tcase_add_test(tcase_core, float_G_nan_neg_prefix_space);
  tcase_add_test(tcase_core, float_G_infinity_prefix_space);
  tcase_add_test(tcase_core, float_G_infinity_neg_prefix_space);
  tcase_add_test(tcase_core, double_G_nan_prefix_space);
  tcase_add_test(tcase_core, double_G_nan_neg_prefix_space);
  tcase_add_test(tcase_core, double_G_infinity_prefix_space);
  tcase_add_test(tcase_core, double_G_infinity_neg_prefix_space);
  tcase_add_test(tcase_core, long_double_G_nan_prefix_space);
  tcase_add_test(tcase_core, long_double_G_nan_neg_prefix_space);
  tcase_add_test(tcase_core, long_double_G_infinity_prefix_space);
  tcase_add_test(tcase_core, long_double_G_infinity_neg_prefix_space);
  tcase_add_test(tcase_core, float_nan_left_alignment);
  tcase_add_test(tcase_core, float_nan_neg_left_alignment);
  tcase_add_test(tcase_core, float_infinity_left_alignment);
  tcase_add_test(tcase_core, float_infinity_neg_left_alignment);
  tcase_add_test(tcase_core, double_nan_left_alignment);
  tcase_add_test(tcase_core, double_nan_neg_left_alignment);
  tcase_add_test(tcase_core, double_infinity_left_alignment);
  tcase_add_test(tcase_core, double_infinity_neg_left_alignment);
  tcase_add_test(tcase_core, long_double_nan_left_alignment);
  tcase_add_test(tcase_core, long_double_nan_neg_left_alignment);
  tcase_add_test(tcase_core, long_double_infinity_left_alignment);
  tcase_add_test(tcase_core, long_double_infinity_neg_left_alignment);
  tcase_add_test(tcase_core, float_exp_nan_left_alignment);
  tcase_add_test(tcase_core, float_exp_nan_neg_left_alignment);
  tcase_add_test(tcase_core, float_exp_infinity_left_alignment);
  tcase_add_test(tcase_core, float_exp_infinity_neg_left_alignment);
  tcase_add_test(tcase_core, double_exp_nan_left_alignment);
  tcase_add_test(tcase_core, double_exp_nan_neg_left_alignment);
  tcase_add_test(tcase_core, double_exp_infinity_left_alignment);
  tcase_add_test(tcase_core, double_exp_infinity_neg_left_alignment);
  tcase_add_test(tcase_core, long_double_exp_nan_left_alignment);
  tcase_add_test(tcase_core, long_double_exp_nan_neg_left_alignment);
  tcase_add_test(tcase_core, long_double_exp_infinity_left_alignment);
  tcase_add_test(tcase_core, long_double_exp_infinity_neg_left_alignment);
  tcase_add_test(tcase_core, float_EXP_nan_left_alignment);
  tcase_add_test(tcase_core, float_EXP_nan_neg_left_alignment);
  tcase_add_test(tcase_core, float_EXP_infinity_left_alignment);
  tcase_add_test(tcase_core, float_EXP_infinity_neg_left_alignment);
  tcase_add_test(tcase_core, double_EXP_nan_left_alignment);
  tcase_add_test(tcase_core, double_EXP_nan_neg_left_alignment);
  tcase_add_test(tcase_core, double_EXP_infinity_left_alignment);
  tcase_add_test(tcase_core, double_EXP_infinity_neg_left_alignment);
  tcase_add_test(tcase_core, long_double_EXP_nan_left_alignment);
  tcase_add_test(tcase_core, long_double_EXP_nan_neg_left_alignment);
  tcase_add_test(tcase_core, long_double_EXP_infinity_left_alignment);
  tcase_add_test(tcase_core, long_double_EXP_infinity_neg_left_alignment);
  tcase_add_test(tcase_core, float_g_nan_left_alignment);
  tcase_add_test(tcase_core, float_g_nan_neg_left_alignment);
  tcase_add_test(tcase_core, float_g_infinity_left_alignment);
  tcase_add_test(tcase_core, float_g_infinity_neg_left_alignment);
  tcase_add_test(tcase_core, double_g_nan_left_alignment);
  tcase_add_test(tcase_core, double_g_nan_neg_left_alignment);
  tcase_add_test(tcase_core, double_g_infinity_left_alignment);
  tcase_add_test(tcase_core, double_g_infinity_neg_left_alignment);
  tcase_add_test(tcase_core, long_double_g_nan_left_alignment);
  tcase_add_test(tcase_core, long_double_g_nan_neg_left_alignment);
  tcase_add_test(tcase_core, long_double_g_infinity_left_alignment);
  tcase_add_test(tcase_core, long_double_g_infinity_neg_left_alignment);
  tcase_add_test(tcase_core, float_G_nan_left_alignment);
  tcase_add_test(tcase_core, float_G_nan_neg_left_alignment);
  tcase_add_test(tcase_core, float_G_infinity_left_alignment);
  tcase_add_test(tcase_core, float_G_infinity_neg_left_alignment);
  tcase_add_test(tcase_core, double_G_nan_left_alignment);
  tcase_add_test(tcase_core, double_G_nan_neg_left_alignment);
  tcase_add_test(tcase_core, double_G_infinity_left_alignment);
  tcase_add_test(tcase_core, double_G_infinity_neg_left_alignment);
  tcase_add_test(tcase_core, long_double_G_nan_left_alignment);
  tcase_add_test(tcase_core, long_double_G_nan_neg_left_alignment);
  tcase_add_test(tcase_core, long_double_G_infinity_left_alignment);
  tcase_add_test(tcase_core, long_double_G_infinity_neg_left_alignment);
  tcase_add_test(tcase_core, float_nan_leading_zeroes);
  tcase_add_test(tcase_core, float_nan_neg_leading_zeroes);
  tcase_add_test(tcase_core, float_infinity_leading_zeroes);
  tcase_add_test(tcase_core, float_infinity_neg_leading_zeroes);
  tcase_add_test(tcase_core, double_nan_leading_zeroes);
  tcase_add_test(tcase_core, double_nan_neg_leading_zeroes);
  tcase_add_test(tcase_core, double_infinity_leading_zeroes);
  tcase_add_test(tcase_core, double_infinity_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_double_nan_leading_zeroes);
  tcase_add_test(tcase_core, long_double_nan_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_double_infinity_leading_zeroes);
  tcase_add_test(tcase_core, long_double_infinity_neg_leading_zeroes);
  tcase_add_test(tcase_core, float_exp_nan_leading_zeroes);
  tcase_add_test(tcase_core, float_exp_nan_neg_leading_zeroes);
  tcase_add_test(tcase_core, float_exp_infinity_leading_zeroes);
  tcase_add_test(tcase_core, float_exp_infinity_neg_leading_zeroes);
  tcase_add_test(tcase_core, double_exp_nan_leading_zeroes);
  tcase_add_test(tcase_core, double_exp_nan_neg_leading_zeroes);
  tcase_add_test(tcase_core, double_exp_infinity_leading_zeroes);
  tcase_add_test(tcase_core, double_exp_infinity_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_double_exp_nan_leading_zeroes);
  tcase_add_test(tcase_core, long_double_exp_nan_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_double_exp_infinity_leading_zeroes);
  tcase_add_test(tcase_core, long_double_exp_infinity_neg_leading_zeroes);
  tcase_add_test(tcase_core, float_EXP_nan_leading_zeroes);
  tcase_add_test(tcase_core, float_EXP_nan_neg_leading_zeroes);
  tcase_add_test(tcase_core, float_EXP_infinity_leading_zeroes);
  tcase_add_test(tcase_core, float_EXP_infinity_neg_leading_zeroes);
  tcase_add_test(tcase_core, double_EXP_nan_leading_zeroes);
  tcase_add_test(tcase_core, double_EXP_nan_neg_leading_zeroes);
  tcase_add_test(tcase_core, double_EXP_infinity_leading_zeroes);
  tcase_add_test(tcase_core, double_EXP_infinity_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_double_EXP_nan_leading_zeroes);
  tcase_add_test(tcase_core, long_double_EXP_nan_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_double_EXP_infinity_leading_zeroes);
  tcase_add_test(tcase_core, long_double_EXP_infinity_neg_leading_zeroes);
  tcase_add_test(tcase_core, float_g_nan_leading_zeroes);
  tcase_add_test(tcase_core, float_g_nan_neg_leading_zeroes);
  tcase_add_test(tcase_core, float_g_infinity_leading_zeroes);
  tcase_add_test(tcase_core, float_g_infinity_neg_leading_zeroes);
  tcase_add_test(tcase_core, double_g_nan_leading_zeroes);
  tcase_add_test(tcase_core, double_g_nan_neg_leading_zeroes);
  tcase_add_test(tcase_core, double_g_infinity_leading_zeroes);
  tcase_add_test(tcase_core, double_g_infinity_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_double_g_nan_leading_zeroes);
  tcase_add_test(tcase_core, long_double_g_nan_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_double_g_infinity_leading_zeroes);
  tcase_add_test(tcase_core, long_double_g_infinity_neg_leading_zeroes);
  tcase_add_test(tcase_core, float_G_nan_leading_zeroes);
  tcase_add_test(tcase_core, float_G_nan_neg_leading_zeroes);
  tcase_add_test(tcase_core, float_G_infinity_leading_zeroes);
  tcase_add_test(tcase_core, float_G_infinity_neg_leading_zeroes);
  tcase_add_test(tcase_core, double_G_nan_leading_zeroes);
  tcase_add_test(tcase_core, double_G_nan_neg_leading_zeroes);
  tcase_add_test(tcase_core, double_G_infinity_leading_zeroes);
  tcase_add_test(tcase_core, double_G_infinity_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_double_G_nan_leading_zeroes);
  tcase_add_test(tcase_core, long_double_G_nan_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_double_G_infinity_leading_zeroes);
  tcase_add_test(tcase_core, long_double_G_infinity_neg_leading_zeroes);
  tcase_add_test(tcase_core, float_nan_alt_format);
  tcase_add_test(tcase_core, float_nan_neg_alt_format);
  tcase_add_test(tcase_core, float_infinity_alt_format);
  tcase_add_test(tcase_core, float_infinity_neg_alt_format);
  tcase_add_test(tcase_core, double_nan_alt_format);
  tcase_add_test(tcase_core, double_nan_neg_alt_format);
  tcase_add_test(tcase_core, double_infinity_alt_format);
  tcase_add_test(tcase_core, double_infinity_neg_alt_format);
  tcase_add_test(tcase_core, long_double_nan_alt_format);
  tcase_add_test(tcase_core, long_double_nan_neg_alt_format);
  tcase_add_test(tcase_core, long_double_infinity_alt_format);
  tcase_add_test(tcase_core, long_double_infinity_neg_alt_format);
  tcase_add_test(tcase_core, float_exp_nan_alt_format);
  tcase_add_test(tcase_core, float_exp_nan_neg_alt_format);
  tcase_add_test(tcase_core, float_exp_infinity_alt_format);
  tcase_add_test(tcase_core, float_exp_infinity_neg_alt_format);
  tcase_add_test(tcase_core, double_exp_nan_alt_format);
  tcase_add_test(tcase_core, double_exp_nan_neg_alt_format);
  tcase_add_test(tcase_core, double_exp_infinity_alt_format);
  tcase_add_test(tcase_core, double_exp_infinity_neg_alt_format);
  tcase_add_test(tcase_core, long_double_exp_nan_alt_format);
  tcase_add_test(tcase_core, long_double_exp_nan_neg_alt_format);
  tcase_add_test(tcase_core, long_double_exp_infinity_alt_format);
  tcase_add_test(tcase_core, long_double_exp_infinity_neg_alt_format);
  tcase_add_test(tcase_core, float_EXP_nan_alt_format);
  tcase_add_test(tcase_core, float_EXP_nan_neg_alt_format);
  tcase_add_test(tcase_core, float_EXP_infinity_alt_format);
  tcase_add_test(tcase_core, float_EXP_infinity_neg_alt_format);
  tcase_add_test(tcase_core, double_EXP_nan_alt_format);
  tcase_add_test(tcase_core, double_EXP_nan_neg_alt_format);
  tcase_add_test(tcase_core, double_EXP_infinity_alt_format);
  tcase_add_test(tcase_core, double_EXP_infinity_neg_alt_format);
  tcase_add_test(tcase_core, long_double_EXP_nan_alt_format);
  tcase_add_test(tcase_core, long_double_EXP_nan_neg_alt_format);
  tcase_add_test(tcase_core, long_double_EXP_infinity_alt_format);
  tcase_add_test(tcase_core, long_double_EXP_infinity_neg_alt_format);
  tcase_add_test(tcase_core, float_g_nan_alt_format);
  tcase_add_test(tcase_core, float_g_nan_neg_alt_format);
  tcase_add_test(tcase_core, float_g_infinity_alt_format);
  tcase_add_test(tcase_core, float_g_infinity_neg_alt_format);
  tcase_add_test(tcase_core, double_g_nan_alt_format);
  tcase_add_test(tcase_core, double_g_nan_neg_alt_format);
  tcase_add_test(tcase_core, double_g_infinity_alt_format);
  tcase_add_test(tcase_core, double_g_infinity_neg_alt_format);
  tcase_add_test(tcase_core, long_double_g_nan_alt_format);
  tcase_add_test(tcase_core, long_double_g_nan_neg_alt_format);
  tcase_add_test(tcase_core, long_double_g_infinity_alt_format);
  tcase_add_test(tcase_core, long_double_g_infinity_neg_alt_format);
  tcase_add_test(tcase_core, float_G_nan_alt_format);
  tcase_add_test(tcase_core, float_G_nan_neg_alt_format);
  tcase_add_test(tcase_core, float_G_infinity_alt_format);
  tcase_add_test(tcase_core, float_G_infinity_neg_alt_format);
  tcase_add_test(tcase_core, double_G_nan_alt_format);
  tcase_add_test(tcase_core, double_G_nan_neg_alt_format);
  tcase_add_test(tcase_core, double_G_infinity_alt_format);
  tcase_add_test(tcase_core, double_G_infinity_neg_alt_format);
  tcase_add_test(tcase_core, long_double_G_nan_alt_format);
  tcase_add_test(tcase_core, long_double_G_nan_neg_alt_format);
  tcase_add_test(tcase_core, long_double_G_infinity_alt_format);
  tcase_add_test(tcase_core, long_double_G_infinity_neg_alt_format);
  tcase_add_test(tcase_core, float_nan_no_width_no_precision);
  tcase_add_test(tcase_core, float_nan_neg_no_width_no_precision);
  tcase_add_test(tcase_core, float_infinity_no_width_no_precision);
  tcase_add_test(tcase_core, float_infinity_neg_no_width_no_precision);
  tcase_add_test(tcase_core, double_nan_no_width_no_precision);
  tcase_add_test(tcase_core, double_nan_neg_no_width_no_precision);
  tcase_add_test(tcase_core, double_infinity_no_width_no_precision);
  tcase_add_test(tcase_core, double_infinity_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_nan_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_nan_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_infinity_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_infinity_neg_no_width_no_precision);
  tcase_add_test(tcase_core, float_exp_nan_no_width_no_precision);
  tcase_add_test(tcase_core, float_exp_nan_neg_no_width_no_precision);
  tcase_add_test(tcase_core, float_exp_infinity_no_width_no_precision);
  tcase_add_test(tcase_core, float_exp_infinity_neg_no_width_no_precision);
  tcase_add_test(tcase_core, double_exp_nan_no_width_no_precision);
  tcase_add_test(tcase_core, double_exp_nan_neg_no_width_no_precision);
  tcase_add_test(tcase_core, double_exp_infinity_no_width_no_precision);
  tcase_add_test(tcase_core, double_exp_infinity_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_exp_infinity_no_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_infinity_neg_no_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_nan_no_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_nan_neg_no_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_no_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_neg_no_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_nan_no_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_nan_neg_no_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_no_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_EXP_infinity_no_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_infinity_neg_no_width_no_precision);
  tcase_add_test(tcase_core, float_g_nan_no_width_no_precision);
  tcase_add_test(tcase_core, float_g_nan_neg_no_width_no_precision);
  tcase_add_test(tcase_core, float_g_infinity_no_width_no_precision);
  tcase_add_test(tcase_core, float_g_infinity_neg_no_width_no_precision);
  tcase_add_test(tcase_core, double_g_nan_no_width_no_precision);
  tcase_add_test(tcase_core, double_g_nan_neg_no_width_no_precision);
  tcase_add_test(tcase_core, double_g_infinity_no_width_no_precision);
  tcase_add_test(tcase_core, double_g_infinity_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_nan_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_nan_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_infinity_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_infinity_neg_no_width_no_precision);
  tcase_add_test(tcase_core, float_G_nan_no_width_no_precision);
  tcase_add_test(tcase_core, float_G_nan_neg_no_width_no_precision);
  tcase_add_test(tcase_core, float_G_infinity_no_width_no_precision);
  tcase_add_test(tcase_core, float_G_infinity_neg_no_width_no_precision);
  tcase_add_test(tcase_core, double_G_nan_no_width_no_precision);
  tcase_add_test(tcase_core, double_G_nan_neg_no_width_no_precision);
  tcase_add_test(tcase_core, double_G_infinity_no_width_no_precision);
  tcase_add_test(tcase_core, double_G_infinity_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_nan_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_nan_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_infinity_no_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_infinity_neg_no_width_no_precision);
  tcase_add_test(tcase_core, float_nan_no_width_small_precision);
  tcase_add_test(tcase_core, float_nan_neg_no_width_small_precision);
  tcase_add_test(tcase_core, float_infinity_no_width_small_precision);
  tcase_add_test(tcase_core, float_infinity_neg_no_width_small_precision);
  tcase_add_test(tcase_core, double_nan_no_width_small_precision);
  tcase_add_test(tcase_core, double_nan_neg_no_width_small_precision);
  tcase_add_test(tcase_core, double_infinity_no_width_small_precision);
  tcase_add_test(tcase_core, double_infinity_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_nan_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_nan_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_infinity_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_infinity_neg_no_width_small_precision);
  tcase_add_test(tcase_core, float_exp_nan_no_width_small_precision);
  tcase_add_test(tcase_core, float_exp_nan_neg_no_width_small_precision);
  tcase_add_test(tcase_core, float_exp_infinity_no_width_small_precision);
  tcase_add_test(tcase_core, float_exp_infinity_neg_no_width_small_precision);
  tcase_add_test(tcase_core, double_exp_nan_no_width_small_precision);
  tcase_add_test(tcase_core, double_exp_nan_neg_no_width_small_precision);
  tcase_add_test(tcase_core, double_exp_infinity_no_width_small_precision);
  tcase_add_test(tcase_core, double_exp_infinity_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_exp_infinity_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_infinity_neg_no_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_nan_no_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_nan_neg_no_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_no_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_neg_no_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_nan_no_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_nan_neg_no_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_no_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_EXP_infinity_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_infinity_neg_no_width_small_precision);
  tcase_add_test(tcase_core, float_g_nan_no_width_small_precision);
  tcase_add_test(tcase_core, float_g_nan_neg_no_width_small_precision);
  tcase_add_test(tcase_core, float_g_infinity_no_width_small_precision);
  tcase_add_test(tcase_core, float_g_infinity_neg_no_width_small_precision);
  tcase_add_test(tcase_core, double_g_nan_no_width_small_precision);
  tcase_add_test(tcase_core, double_g_nan_neg_no_width_small_precision);
  tcase_add_test(tcase_core, double_g_infinity_no_width_small_precision);
  tcase_add_test(tcase_core, double_g_infinity_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_g_nan_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_g_nan_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_g_infinity_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_g_infinity_neg_no_width_small_precision);
  tcase_add_test(tcase_core, float_G_nan_no_width_small_precision);
  tcase_add_test(tcase_core, float_G_nan_neg_no_width_small_precision);
  tcase_add_test(tcase_core, float_G_infinity_no_width_small_precision);
  tcase_add_test(tcase_core, float_G_infinity_neg_no_width_small_precision);
  tcase_add_test(tcase_core, double_G_nan_no_width_small_precision);
  tcase_add_test(tcase_core, double_G_nan_neg_no_width_small_precision);
  tcase_add_test(tcase_core, double_G_infinity_no_width_small_precision);
  tcase_add_test(tcase_core, double_G_infinity_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_G_nan_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_G_nan_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_double_G_infinity_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_G_infinity_neg_no_width_small_precision);
  tcase_add_test(tcase_core, float_nan_no_width_big_precision);
  tcase_add_test(tcase_core, float_nan_neg_no_width_big_precision);
  tcase_add_test(tcase_core, float_infinity_no_width_big_precision);
  tcase_add_test(tcase_core, float_infinity_neg_no_width_big_precision);
  tcase_add_test(tcase_core, double_nan_no_width_big_precision);
  tcase_add_test(tcase_core, double_nan_neg_no_width_big_precision);
  tcase_add_test(tcase_core, double_infinity_no_width_big_precision);
  tcase_add_test(tcase_core, double_infinity_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_nan_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_nan_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_infinity_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_infinity_neg_no_width_big_precision);
  tcase_add_test(tcase_core, float_exp_nan_no_width_big_precision);
  tcase_add_test(tcase_core, float_exp_nan_neg_no_width_big_precision);
  tcase_add_test(tcase_core, float_exp_infinity_no_width_big_precision);
  tcase_add_test(tcase_core, float_exp_infinity_neg_no_width_big_precision);
  tcase_add_test(tcase_core, double_exp_nan_no_width_big_precision);
  tcase_add_test(tcase_core, double_exp_nan_neg_no_width_big_precision);
  tcase_add_test(tcase_core, double_exp_infinity_no_width_big_precision);
  tcase_add_test(tcase_core, double_exp_infinity_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_exp_infinity_no_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_infinity_neg_no_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_nan_no_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_nan_neg_no_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_no_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_neg_no_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_nan_no_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_nan_neg_no_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_no_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_EXP_infinity_no_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_infinity_neg_no_width_big_precision);
  tcase_add_test(tcase_core, float_g_nan_no_width_big_precision);
  tcase_add_test(tcase_core, float_g_nan_neg_no_width_big_precision);
  tcase_add_test(tcase_core, float_g_infinity_no_width_big_precision);
  tcase_add_test(tcase_core, float_g_infinity_neg_no_width_big_precision);
  tcase_add_test(tcase_core, double_g_nan_no_width_big_precision);
  tcase_add_test(tcase_core, double_g_nan_neg_no_width_big_precision);
  tcase_add_test(tcase_core, double_g_infinity_no_width_big_precision);
  tcase_add_test(tcase_core, double_g_infinity_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_nan_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_nan_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_infinity_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_infinity_neg_no_width_big_precision);
  tcase_add_test(tcase_core, float_G_nan_no_width_big_precision);
  tcase_add_test(tcase_core, float_G_nan_neg_no_width_big_precision);
  tcase_add_test(tcase_core, float_G_infinity_no_width_big_precision);
  tcase_add_test(tcase_core, float_G_infinity_neg_no_width_big_precision);
  tcase_add_test(tcase_core, double_G_nan_no_width_big_precision);
  tcase_add_test(tcase_core, double_G_nan_neg_no_width_big_precision);
  tcase_add_test(tcase_core, double_G_infinity_no_width_big_precision);
  tcase_add_test(tcase_core, double_G_infinity_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_nan_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_nan_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_infinity_no_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_infinity_neg_no_width_big_precision);
  tcase_add_test(tcase_core, float_nan_small_width_no_precision);
  tcase_add_test(tcase_core, float_nan_neg_small_width_no_precision);
  tcase_add_test(tcase_core, float_infinity_small_width_no_precision);
  tcase_add_test(tcase_core, float_infinity_neg_small_width_no_precision);
  tcase_add_test(tcase_core, double_nan_small_width_no_precision);
  tcase_add_test(tcase_core, double_nan_neg_small_width_no_precision);
  tcase_add_test(tcase_core, double_infinity_small_width_no_precision);
  tcase_add_test(tcase_core, double_infinity_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_nan_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_nan_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_infinity_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_infinity_neg_small_width_no_precision);
  tcase_add_test(tcase_core, float_exp_nan_small_width_no_precision);
  tcase_add_test(tcase_core, float_exp_nan_neg_small_width_no_precision);
  tcase_add_test(tcase_core, float_exp_infinity_small_width_no_precision);
  tcase_add_test(tcase_core, float_exp_infinity_neg_small_width_no_precision);
  tcase_add_test(tcase_core, double_exp_nan_small_width_no_precision);
  tcase_add_test(tcase_core, double_exp_nan_neg_small_width_no_precision);
  tcase_add_test(tcase_core, double_exp_infinity_small_width_no_precision);
  tcase_add_test(tcase_core, double_exp_infinity_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_exp_infinity_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_infinity_neg_small_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_nan_small_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_nan_neg_small_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_small_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_neg_small_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_nan_small_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_nan_neg_small_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_small_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_EXP_infinity_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_infinity_neg_small_width_no_precision);
  tcase_add_test(tcase_core, float_g_nan_small_width_no_precision);
  tcase_add_test(tcase_core, float_g_nan_neg_small_width_no_precision);
  tcase_add_test(tcase_core, float_g_infinity_small_width_no_precision);
  tcase_add_test(tcase_core, float_g_infinity_neg_small_width_no_precision);
  tcase_add_test(tcase_core, double_g_nan_small_width_no_precision);
  tcase_add_test(tcase_core, double_g_nan_neg_small_width_no_precision);
  tcase_add_test(tcase_core, double_g_infinity_small_width_no_precision);
  tcase_add_test(tcase_core, double_g_infinity_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_nan_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_nan_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_infinity_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_g_infinity_neg_small_width_no_precision);
  tcase_add_test(tcase_core, float_G_nan_small_width_no_precision);
  tcase_add_test(tcase_core, float_G_nan_neg_small_width_no_precision);
  tcase_add_test(tcase_core, float_G_infinity_small_width_no_precision);
  tcase_add_test(tcase_core, float_G_infinity_neg_small_width_no_precision);
  tcase_add_test(tcase_core, double_G_nan_small_width_no_precision);
  tcase_add_test(tcase_core, double_G_nan_neg_small_width_no_precision);
  tcase_add_test(tcase_core, double_G_infinity_small_width_no_precision);
  tcase_add_test(tcase_core, double_G_infinity_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_nan_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_nan_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_infinity_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_G_infinity_neg_small_width_no_precision);
  tcase_add_test(tcase_core, float_nan_small_width_small_precision);
  tcase_add_test(tcase_core, float_nan_neg_small_width_small_precision);
  tcase_add_test(tcase_core, float_infinity_small_width_small_precision);
  tcase_add_test(tcase_core, float_infinity_neg_small_width_small_precision);
  tcase_add_test(tcase_core, double_nan_small_width_small_precision);
  tcase_add_test(tcase_core, double_nan_neg_small_width_small_precision);
  tcase_add_test(tcase_core, double_infinity_small_width_small_precision);
  tcase_add_test(tcase_core, double_infinity_neg_small_width_small_precision);
  tcase_add_test(tcase_core, long_double_nan_small_width_small_precision);
  tcase_add_test(tcase_core, long_double_nan_neg_small_width_small_precision);
  tcase_add_test(tcase_core, long_double_infinity_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_infinity_neg_small_width_small_precision);
  tcase_add_test(tcase_core, float_exp_nan_small_width_small_precision);
  tcase_add_test(tcase_core, float_exp_nan_neg_small_width_small_precision);
  tcase_add_test(tcase_core, float_exp_infinity_small_width_small_precision);
  tcase_add_test(tcase_core,
                 float_exp_infinity_neg_small_width_small_precision);
  tcase_add_test(tcase_core, double_exp_nan_small_width_small_precision);
  tcase_add_test(tcase_core, double_exp_nan_neg_small_width_small_precision);
  tcase_add_test(tcase_core, double_exp_infinity_small_width_small_precision);
  tcase_add_test(tcase_core,
                 double_exp_infinity_neg_small_width_small_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_nan_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_infinity_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_infinity_neg_small_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_nan_small_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_nan_neg_small_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_small_width_small_precision);
  tcase_add_test(tcase_core,
                 float_EXP_infinity_neg_small_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_nan_small_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_nan_neg_small_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_small_width_small_precision);
  tcase_add_test(tcase_core,
                 double_EXP_infinity_neg_small_width_small_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_nan_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_infinity_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_infinity_neg_small_width_small_precision);
  tcase_add_test(tcase_core, float_g_nan_small_width_small_precision);
  tcase_add_test(tcase_core, float_g_nan_neg_small_width_small_precision);
  tcase_add_test(tcase_core, float_g_infinity_small_width_small_precision);
  tcase_add_test(tcase_core, float_g_infinity_neg_small_width_small_precision);
  tcase_add_test(tcase_core, double_g_nan_small_width_small_precision);
  tcase_add_test(tcase_core, double_g_nan_neg_small_width_small_precision);
  tcase_add_test(tcase_core, double_g_infinity_small_width_small_precision);
  tcase_add_test(tcase_core, double_g_infinity_neg_small_width_small_precision);
  tcase_add_test(tcase_core, long_double_g_nan_small_width_small_precision);
  tcase_add_test(tcase_core, long_double_g_nan_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_g_infinity_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_g_infinity_neg_small_width_small_precision);
  tcase_add_test(tcase_core, float_G_nan_small_width_small_precision);
  tcase_add_test(tcase_core, float_G_nan_neg_small_width_small_precision);
  tcase_add_test(tcase_core, float_G_infinity_small_width_small_precision);
  tcase_add_test(tcase_core, float_G_infinity_neg_small_width_small_precision);
  tcase_add_test(tcase_core, double_G_nan_small_width_small_precision);
  tcase_add_test(tcase_core, double_G_nan_neg_small_width_small_precision);
  tcase_add_test(tcase_core, double_G_infinity_small_width_small_precision);
  tcase_add_test(tcase_core, double_G_infinity_neg_small_width_small_precision);
  tcase_add_test(tcase_core, long_double_G_nan_small_width_small_precision);
  tcase_add_test(tcase_core, long_double_G_nan_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_G_infinity_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_G_infinity_neg_small_width_small_precision);
  tcase_add_test(tcase_core, float_nan_small_width_big_precision);
  tcase_add_test(tcase_core, float_nan_neg_small_width_big_precision);
  tcase_add_test(tcase_core, float_infinity_small_width_big_precision);
  tcase_add_test(tcase_core, float_infinity_neg_small_width_big_precision);
  tcase_add_test(tcase_core, double_nan_small_width_big_precision);
  tcase_add_test(tcase_core, double_nan_neg_small_width_big_precision);
  tcase_add_test(tcase_core, double_infinity_small_width_big_precision);
  tcase_add_test(tcase_core, double_infinity_neg_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_nan_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_nan_neg_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_infinity_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_infinity_neg_small_width_big_precision);
  tcase_add_test(tcase_core, float_exp_nan_small_width_big_precision);
  tcase_add_test(tcase_core, float_exp_nan_neg_small_width_big_precision);
  tcase_add_test(tcase_core, float_exp_infinity_small_width_big_precision);
  tcase_add_test(tcase_core, float_exp_infinity_neg_small_width_big_precision);
  tcase_add_test(tcase_core, double_exp_nan_small_width_big_precision);
  tcase_add_test(tcase_core, double_exp_nan_neg_small_width_big_precision);
  tcase_add_test(tcase_core, double_exp_infinity_small_width_big_precision);
  tcase_add_test(tcase_core, double_exp_infinity_neg_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_infinity_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_infinity_neg_small_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_nan_small_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_nan_neg_small_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_small_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_neg_small_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_nan_small_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_nan_neg_small_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_small_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_neg_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_infinity_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_infinity_neg_small_width_big_precision);
  tcase_add_test(tcase_core, float_g_nan_small_width_big_precision);
  tcase_add_test(tcase_core, float_g_nan_neg_small_width_big_precision);
  tcase_add_test(tcase_core, float_g_infinity_small_width_big_precision);
  tcase_add_test(tcase_core, float_g_infinity_neg_small_width_big_precision);
  tcase_add_test(tcase_core, double_g_nan_small_width_big_precision);
  tcase_add_test(tcase_core, double_g_nan_neg_small_width_big_precision);
  tcase_add_test(tcase_core, double_g_infinity_small_width_big_precision);
  tcase_add_test(tcase_core, double_g_infinity_neg_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_nan_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_nan_neg_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_infinity_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_g_infinity_neg_small_width_big_precision);
  tcase_add_test(tcase_core, float_G_nan_small_width_big_precision);
  tcase_add_test(tcase_core, float_G_nan_neg_small_width_big_precision);
  tcase_add_test(tcase_core, float_G_infinity_small_width_big_precision);
  tcase_add_test(tcase_core, float_G_infinity_neg_small_width_big_precision);
  tcase_add_test(tcase_core, double_G_nan_small_width_big_precision);
  tcase_add_test(tcase_core, double_G_nan_neg_small_width_big_precision);
  tcase_add_test(tcase_core, double_G_infinity_small_width_big_precision);
  tcase_add_test(tcase_core, double_G_infinity_neg_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_nan_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_nan_neg_small_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_infinity_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_G_infinity_neg_small_width_big_precision);
  tcase_add_test(tcase_core, float_nan_big_width_no_precision);
  tcase_add_test(tcase_core, float_nan_neg_big_width_no_precision);
  tcase_add_test(tcase_core, float_infinity_big_width_no_precision);
  tcase_add_test(tcase_core, float_infinity_neg_big_width_no_precision);
  tcase_add_test(tcase_core, double_nan_big_width_no_precision);
  tcase_add_test(tcase_core, double_nan_neg_big_width_no_precision);
  tcase_add_test(tcase_core, double_infinity_big_width_no_precision);
  tcase_add_test(tcase_core, double_infinity_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_nan_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_nan_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_infinity_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_infinity_neg_big_width_no_precision);
  tcase_add_test(tcase_core, float_exp_nan_big_width_no_precision);
  tcase_add_test(tcase_core, float_exp_nan_neg_big_width_no_precision);
  tcase_add_test(tcase_core, float_exp_infinity_big_width_no_precision);
  tcase_add_test(tcase_core, float_exp_infinity_neg_big_width_no_precision);
  tcase_add_test(tcase_core, double_exp_nan_big_width_no_precision);
  tcase_add_test(tcase_core, double_exp_nan_neg_big_width_no_precision);
  tcase_add_test(tcase_core, double_exp_infinity_big_width_no_precision);
  tcase_add_test(tcase_core, double_exp_infinity_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_exp_infinity_big_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_infinity_neg_big_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_nan_big_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_nan_neg_big_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_big_width_no_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_neg_big_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_nan_big_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_nan_neg_big_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_big_width_no_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_EXP_infinity_big_width_no_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_infinity_neg_big_width_no_precision);
  tcase_add_test(tcase_core, float_g_nan_big_width_no_precision);
  tcase_add_test(tcase_core, float_g_nan_neg_big_width_no_precision);
  tcase_add_test(tcase_core, float_g_infinity_big_width_no_precision);
  tcase_add_test(tcase_core, float_g_infinity_neg_big_width_no_precision);
  tcase_add_test(tcase_core, double_g_nan_big_width_no_precision);
  tcase_add_test(tcase_core, double_g_nan_neg_big_width_no_precision);
  tcase_add_test(tcase_core, double_g_infinity_big_width_no_precision);
  tcase_add_test(tcase_core, double_g_infinity_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_nan_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_nan_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_infinity_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_g_infinity_neg_big_width_no_precision);
  tcase_add_test(tcase_core, float_G_nan_big_width_no_precision);
  tcase_add_test(tcase_core, float_G_nan_neg_big_width_no_precision);
  tcase_add_test(tcase_core, float_G_infinity_big_width_no_precision);
  tcase_add_test(tcase_core, float_G_infinity_neg_big_width_no_precision);
  tcase_add_test(tcase_core, double_G_nan_big_width_no_precision);
  tcase_add_test(tcase_core, double_G_nan_neg_big_width_no_precision);
  tcase_add_test(tcase_core, double_G_infinity_big_width_no_precision);
  tcase_add_test(tcase_core, double_G_infinity_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_nan_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_nan_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_infinity_big_width_no_precision);
  tcase_add_test(tcase_core, long_double_G_infinity_neg_big_width_no_precision);
  tcase_add_test(tcase_core, float_nan_big_width_small_precision);
  tcase_add_test(tcase_core, float_nan_neg_big_width_small_precision);
  tcase_add_test(tcase_core, float_infinity_big_width_small_precision);
  tcase_add_test(tcase_core, float_infinity_neg_big_width_small_precision);
  tcase_add_test(tcase_core, double_nan_big_width_small_precision);
  tcase_add_test(tcase_core, double_nan_neg_big_width_small_precision);
  tcase_add_test(tcase_core, double_infinity_big_width_small_precision);
  tcase_add_test(tcase_core, double_infinity_neg_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_nan_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_nan_neg_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_infinity_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_infinity_neg_big_width_small_precision);
  tcase_add_test(tcase_core, float_exp_nan_big_width_small_precision);
  tcase_add_test(tcase_core, float_exp_nan_neg_big_width_small_precision);
  tcase_add_test(tcase_core, float_exp_infinity_big_width_small_precision);
  tcase_add_test(tcase_core, float_exp_infinity_neg_big_width_small_precision);
  tcase_add_test(tcase_core, double_exp_nan_big_width_small_precision);
  tcase_add_test(tcase_core, double_exp_nan_neg_big_width_small_precision);
  tcase_add_test(tcase_core, double_exp_infinity_big_width_small_precision);
  tcase_add_test(tcase_core, double_exp_infinity_neg_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_infinity_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_infinity_neg_big_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_nan_big_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_nan_neg_big_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_big_width_small_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_neg_big_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_nan_big_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_nan_neg_big_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_big_width_small_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_neg_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_infinity_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_infinity_neg_big_width_small_precision);
  tcase_add_test(tcase_core, float_g_nan_big_width_small_precision);
  tcase_add_test(tcase_core, float_g_nan_neg_big_width_small_precision);
  tcase_add_test(tcase_core, float_g_infinity_big_width_small_precision);
  tcase_add_test(tcase_core, float_g_infinity_neg_big_width_small_precision);
  tcase_add_test(tcase_core, double_g_nan_big_width_small_precision);
  tcase_add_test(tcase_core, double_g_nan_neg_big_width_small_precision);
  tcase_add_test(tcase_core, double_g_infinity_big_width_small_precision);
  tcase_add_test(tcase_core, double_g_infinity_neg_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_g_nan_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_g_nan_neg_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_g_infinity_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_g_infinity_neg_big_width_small_precision);
  tcase_add_test(tcase_core, float_G_nan_big_width_small_precision);
  tcase_add_test(tcase_core, float_G_nan_neg_big_width_small_precision);
  tcase_add_test(tcase_core, float_G_infinity_big_width_small_precision);
  tcase_add_test(tcase_core, float_G_infinity_neg_big_width_small_precision);
  tcase_add_test(tcase_core, double_G_nan_big_width_small_precision);
  tcase_add_test(tcase_core, double_G_nan_neg_big_width_small_precision);
  tcase_add_test(tcase_core, double_G_infinity_big_width_small_precision);
  tcase_add_test(tcase_core, double_G_infinity_neg_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_G_nan_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_G_nan_neg_big_width_small_precision);
  tcase_add_test(tcase_core, long_double_G_infinity_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_double_G_infinity_neg_big_width_small_precision);
  tcase_add_test(tcase_core, float_nan_big_width_big_precision);
  tcase_add_test(tcase_core, float_nan_neg_big_width_big_precision);
  tcase_add_test(tcase_core, float_infinity_big_width_big_precision);
  tcase_add_test(tcase_core, float_infinity_neg_big_width_big_precision);
  tcase_add_test(tcase_core, double_nan_big_width_big_precision);
  tcase_add_test(tcase_core, double_nan_neg_big_width_big_precision);
  tcase_add_test(tcase_core, double_infinity_big_width_big_precision);
  tcase_add_test(tcase_core, double_infinity_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_nan_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_nan_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_infinity_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_infinity_neg_big_width_big_precision);
  tcase_add_test(tcase_core, float_exp_nan_big_width_big_precision);
  tcase_add_test(tcase_core, float_exp_nan_neg_big_width_big_precision);
  tcase_add_test(tcase_core, float_exp_infinity_big_width_big_precision);
  tcase_add_test(tcase_core, float_exp_infinity_neg_big_width_big_precision);
  tcase_add_test(tcase_core, double_exp_nan_big_width_big_precision);
  tcase_add_test(tcase_core, double_exp_nan_neg_big_width_big_precision);
  tcase_add_test(tcase_core, double_exp_infinity_big_width_big_precision);
  tcase_add_test(tcase_core, double_exp_infinity_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_exp_nan_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_exp_infinity_big_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_exp_infinity_neg_big_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_nan_big_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_nan_neg_big_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_big_width_big_precision);
  tcase_add_test(tcase_core, float_EXP_infinity_neg_big_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_nan_big_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_nan_neg_big_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_big_width_big_precision);
  tcase_add_test(tcase_core, double_EXP_infinity_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_EXP_nan_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_EXP_infinity_big_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_EXP_infinity_neg_big_width_big_precision);
  tcase_add_test(tcase_core, float_g_nan_big_width_big_precision);
  tcase_add_test(tcase_core, float_g_nan_neg_big_width_big_precision);
  tcase_add_test(tcase_core, float_g_infinity_big_width_big_precision);
  tcase_add_test(tcase_core, float_g_infinity_neg_big_width_big_precision);
  tcase_add_test(tcase_core, double_g_nan_big_width_big_precision);
  tcase_add_test(tcase_core, double_g_nan_neg_big_width_big_precision);
  tcase_add_test(tcase_core, double_g_infinity_big_width_big_precision);
  tcase_add_test(tcase_core, double_g_infinity_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_nan_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_nan_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_g_infinity_big_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_g_infinity_neg_big_width_big_precision);
  tcase_add_test(tcase_core, float_G_nan_big_width_big_precision);
  tcase_add_test(tcase_core, float_G_nan_neg_big_width_big_precision);
  tcase_add_test(tcase_core, float_G_infinity_big_width_big_precision);
  tcase_add_test(tcase_core, float_G_infinity_neg_big_width_big_precision);
  tcase_add_test(tcase_core, double_G_nan_big_width_big_precision);
  tcase_add_test(tcase_core, double_G_nan_neg_big_width_big_precision);
  tcase_add_test(tcase_core, double_G_infinity_big_width_big_precision);
  tcase_add_test(tcase_core, double_G_infinity_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_nan_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_nan_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_double_G_infinity_big_width_big_precision);
  tcase_add_test(tcase_core,
                 long_double_G_infinity_neg_big_width_big_precision);
  tcase_add_test(tcase_core, short_null_no_flags);
  tcase_add_test(tcase_core, short_general_short_no_flags);
  tcase_add_test(tcase_core, short_general_short_neg_no_flags);
  tcase_add_test(tcase_core, short_general_medium_no_flags);
  tcase_add_test(tcase_core, short_general_medium_neg_no_flags);
  tcase_add_test(tcase_core, short_null_prefix_sign);
  tcase_add_test(tcase_core, short_general_short_prefix_sign);
  tcase_add_test(tcase_core, short_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, short_general_medium_prefix_sign);
  tcase_add_test(tcase_core, short_general_medium_neg_prefix_sign);
  tcase_add_test(tcase_core, short_null_prefix_space);
  tcase_add_test(tcase_core, short_general_short_prefix_space);
  tcase_add_test(tcase_core, short_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, short_general_medium_prefix_space);
  tcase_add_test(tcase_core, short_general_medium_neg_prefix_space);
  tcase_add_test(tcase_core, short_null_left_alignment);
  tcase_add_test(tcase_core, short_general_short_left_alignment);
  tcase_add_test(tcase_core, short_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, short_general_medium_left_alignment);
  tcase_add_test(tcase_core, short_general_medium_neg_left_alignment);
  tcase_add_test(tcase_core, short_null_leading_zeroes);
  tcase_add_test(tcase_core, short_general_short_leading_zeroes);
  tcase_add_test(tcase_core, short_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, short_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, short_general_medium_neg_leading_zeroes);
  tcase_add_test(tcase_core, short_null_alt_format);
  tcase_add_test(tcase_core, short_general_short_alt_format);
  tcase_add_test(tcase_core, short_general_short_neg_alt_format);
  tcase_add_test(tcase_core, short_general_medium_alt_format);
  tcase_add_test(tcase_core, short_general_medium_neg_alt_format);
  tcase_add_test(tcase_core, short_null_no_width_no_precision);
  tcase_add_test(tcase_core, short_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, short_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core, short_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core, short_general_medium_neg_no_width_no_precision);
  tcase_add_test(tcase_core, short_null_no_width_small_precision);
  tcase_add_test(tcase_core, short_general_short_no_width_small_precision);
  tcase_add_test(tcase_core, short_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core, short_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core, short_general_medium_neg_no_width_small_precision);
  tcase_add_test(tcase_core, short_null_no_width_big_precision);
  tcase_add_test(tcase_core, short_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, short_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core, short_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core, short_general_medium_neg_no_width_big_precision);
  tcase_add_test(tcase_core, short_null_small_width_no_precision);
  tcase_add_test(tcase_core, short_general_short_small_width_no_precision);
  tcase_add_test(tcase_core, short_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core, short_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core, short_general_medium_neg_small_width_no_precision);
  tcase_add_test(tcase_core, short_null_small_width_small_precision);
  tcase_add_test(tcase_core, short_general_short_small_width_small_precision);
  tcase_add_test(tcase_core,
                 short_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core, short_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core,
                 short_general_medium_neg_small_width_small_precision);
  tcase_add_test(tcase_core, short_null_small_width_big_precision);
  tcase_add_test(tcase_core, short_general_short_small_width_big_precision);
  tcase_add_test(tcase_core, short_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core, short_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core,
                 short_general_medium_neg_small_width_big_precision);
  tcase_add_test(tcase_core, short_null_big_width_no_precision);
  tcase_add_test(tcase_core, short_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, short_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core, short_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core, short_general_medium_neg_big_width_no_precision);
  tcase_add_test(tcase_core, short_null_big_width_small_precision);
  tcase_add_test(tcase_core, short_general_short_big_width_small_precision);
  tcase_add_test(tcase_core, short_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core, short_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core,
                 short_general_medium_neg_big_width_small_precision);
  tcase_add_test(tcase_core, short_null_big_width_big_precision);
  tcase_add_test(tcase_core, short_general_short_big_width_big_precision);
  tcase_add_test(tcase_core, short_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core, short_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core, short_general_medium_neg_big_width_big_precision);
  tcase_add_test(tcase_core, unsigned_short_null_no_flags);
  tcase_add_test(tcase_core, unsigned_short_general_short_no_flags);
  tcase_add_test(tcase_core, unsigned_short_general_short_neg_no_flags);
  tcase_add_test(tcase_core, unsigned_short_general_medium_no_flags);
  tcase_add_test(tcase_core, unsigned_short_general_medium_neg_no_flags);
  tcase_add_test(tcase_core, short_hex_null_no_flags);
  tcase_add_test(tcase_core, short_hex_general_short_no_flags);
  tcase_add_test(tcase_core, short_hex_general_short_neg_no_flags);
  tcase_add_test(tcase_core, short_hex_general_medium_no_flags);
  tcase_add_test(tcase_core, short_hex_general_medium_neg_no_flags);
  tcase_add_test(tcase_core, SHORT_HEX_null_no_flags);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_no_flags);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_neg_no_flags);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_no_flags);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_neg_no_flags);
  tcase_add_test(tcase_core, short_oct_null_no_flags);
  tcase_add_test(tcase_core, short_oct_general_short_no_flags);
  tcase_add_test(tcase_core, short_oct_general_short_neg_no_flags);
  tcase_add_test(tcase_core, short_oct_general_medium_no_flags);
  tcase_add_test(tcase_core, short_oct_general_medium_neg_no_flags);
  tcase_add_test(tcase_core, unsigned_short_null_prefix_sign);
  tcase_add_test(tcase_core, unsigned_short_general_short_prefix_sign);
  tcase_add_test(tcase_core, unsigned_short_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, unsigned_short_general_medium_prefix_sign);
  tcase_add_test(tcase_core, unsigned_short_general_medium_neg_prefix_sign);
  tcase_add_test(tcase_core, short_hex_null_prefix_sign);
  tcase_add_test(tcase_core, short_hex_general_short_prefix_sign);
  tcase_add_test(tcase_core, short_hex_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, short_hex_general_medium_prefix_sign);
  tcase_add_test(tcase_core, short_hex_general_medium_neg_prefix_sign);
  tcase_add_test(tcase_core, SHORT_HEX_null_prefix_sign);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_prefix_sign);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_prefix_sign);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_neg_prefix_sign);
  tcase_add_test(tcase_core, short_oct_null_prefix_sign);
  tcase_add_test(tcase_core, short_oct_general_short_prefix_sign);
  tcase_add_test(tcase_core, short_oct_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, short_oct_general_medium_prefix_sign);
  tcase_add_test(tcase_core, short_oct_general_medium_neg_prefix_sign);
  tcase_add_test(tcase_core, unsigned_short_null_prefix_space);
  tcase_add_test(tcase_core, unsigned_short_general_short_prefix_space);
  tcase_add_test(tcase_core, unsigned_short_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, unsigned_short_general_medium_prefix_space);
  tcase_add_test(tcase_core, unsigned_short_general_medium_neg_prefix_space);
  tcase_add_test(tcase_core, short_hex_null_prefix_space);
  tcase_add_test(tcase_core, short_hex_general_short_prefix_space);
  tcase_add_test(tcase_core, short_hex_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, short_hex_general_medium_prefix_space);
  tcase_add_test(tcase_core, short_hex_general_medium_neg_prefix_space);
  tcase_add_test(tcase_core, SHORT_HEX_null_prefix_space);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_prefix_space);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_prefix_space);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_neg_prefix_space);
  tcase_add_test(tcase_core, short_oct_null_prefix_space);
  tcase_add_test(tcase_core, short_oct_general_short_prefix_space);
  tcase_add_test(tcase_core, short_oct_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, short_oct_general_medium_prefix_space);
  tcase_add_test(tcase_core, short_oct_general_medium_neg_prefix_space);
  tcase_add_test(tcase_core, unsigned_short_null_left_alignment);
  tcase_add_test(tcase_core, unsigned_short_general_short_left_alignment);
  tcase_add_test(tcase_core, unsigned_short_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, unsigned_short_general_medium_left_alignment);
  tcase_add_test(tcase_core, unsigned_short_general_medium_neg_left_alignment);
  tcase_add_test(tcase_core, short_hex_null_left_alignment);
  tcase_add_test(tcase_core, short_hex_general_short_left_alignment);
  tcase_add_test(tcase_core, short_hex_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, short_hex_general_medium_left_alignment);
  tcase_add_test(tcase_core, short_hex_general_medium_neg_left_alignment);
  tcase_add_test(tcase_core, SHORT_HEX_null_left_alignment);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_left_alignment);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_left_alignment);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_neg_left_alignment);
  tcase_add_test(tcase_core, short_oct_null_left_alignment);
  tcase_add_test(tcase_core, short_oct_general_short_left_alignment);
  tcase_add_test(tcase_core, short_oct_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, short_oct_general_medium_left_alignment);
  tcase_add_test(tcase_core, short_oct_general_medium_neg_left_alignment);
  tcase_add_test(tcase_core, unsigned_short_null_leading_zeroes);
  tcase_add_test(tcase_core, unsigned_short_general_short_leading_zeroes);
  tcase_add_test(tcase_core, unsigned_short_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, unsigned_short_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, unsigned_short_general_medium_neg_leading_zeroes);
  tcase_add_test(tcase_core, short_hex_null_leading_zeroes);
  tcase_add_test(tcase_core, short_hex_general_short_leading_zeroes);
  tcase_add_test(tcase_core, short_hex_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, short_hex_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, short_hex_general_medium_neg_leading_zeroes);
  tcase_add_test(tcase_core, SHORT_HEX_null_leading_zeroes);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_leading_zeroes);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_neg_leading_zeroes);
  tcase_add_test(tcase_core, short_oct_null_leading_zeroes);
  tcase_add_test(tcase_core, short_oct_general_short_leading_zeroes);
  tcase_add_test(tcase_core, short_oct_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, short_oct_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, short_oct_general_medium_neg_leading_zeroes);
  tcase_add_test(tcase_core, unsigned_short_null_alt_format);
  tcase_add_test(tcase_core, unsigned_short_general_short_alt_format);
  tcase_add_test(tcase_core, unsigned_short_general_short_neg_alt_format);
  tcase_add_test(tcase_core, unsigned_short_general_medium_alt_format);
  tcase_add_test(tcase_core, unsigned_short_general_medium_neg_alt_format);
  tcase_add_test(tcase_core, short_hex_null_alt_format);
  tcase_add_test(tcase_core, short_hex_general_short_alt_format);
  tcase_add_test(tcase_core, short_hex_general_short_neg_alt_format);
  tcase_add_test(tcase_core, short_hex_general_medium_alt_format);
  tcase_add_test(tcase_core, short_hex_general_medium_neg_alt_format);
  tcase_add_test(tcase_core, SHORT_HEX_null_alt_format);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_alt_format);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_neg_alt_format);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_alt_format);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_neg_alt_format);
  tcase_add_test(tcase_core, short_oct_null_alt_format);
  tcase_add_test(tcase_core, short_oct_general_short_alt_format);
  tcase_add_test(tcase_core, short_oct_general_short_neg_alt_format);
  tcase_add_test(tcase_core, short_oct_general_medium_alt_format);
  tcase_add_test(tcase_core, short_oct_general_medium_neg_alt_format);
  tcase_add_test(tcase_core, unsigned_short_null_no_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_no_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_neg_no_width_no_precision);
  tcase_add_test(tcase_core, short_hex_null_no_width_no_precision);
  tcase_add_test(tcase_core, short_hex_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, short_hex_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core, short_hex_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_medium_neg_no_width_no_precision);
  tcase_add_test(tcase_core, SHORT_HEX_null_no_width_no_precision);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_medium_neg_no_width_no_precision);
  tcase_add_test(tcase_core, short_oct_null_no_width_no_precision);
  tcase_add_test(tcase_core, short_oct_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, short_oct_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core, short_oct_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_medium_neg_no_width_no_precision);
  tcase_add_test(tcase_core, unsigned_short_null_no_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_no_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_neg_no_width_small_precision);
  tcase_add_test(tcase_core, short_hex_null_no_width_small_precision);
  tcase_add_test(tcase_core, short_hex_general_short_no_width_small_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core, short_hex_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_medium_neg_no_width_small_precision);
  tcase_add_test(tcase_core, SHORT_HEX_null_no_width_small_precision);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_no_width_small_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_medium_neg_no_width_small_precision);
  tcase_add_test(tcase_core, short_oct_null_no_width_small_precision);
  tcase_add_test(tcase_core, short_oct_general_short_no_width_small_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core, short_oct_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_medium_neg_no_width_small_precision);
  tcase_add_test(tcase_core, unsigned_short_null_no_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_no_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_neg_no_width_big_precision);
  tcase_add_test(tcase_core, short_hex_null_no_width_big_precision);
  tcase_add_test(tcase_core, short_hex_general_short_no_width_big_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core, short_hex_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_medium_neg_no_width_big_precision);
  tcase_add_test(tcase_core, SHORT_HEX_null_no_width_big_precision);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_no_width_big_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_medium_neg_no_width_big_precision);
  tcase_add_test(tcase_core, short_oct_null_no_width_big_precision);
  tcase_add_test(tcase_core, short_oct_general_short_no_width_big_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core, short_oct_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_medium_neg_no_width_big_precision);
  tcase_add_test(tcase_core, unsigned_short_null_small_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_small_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_neg_small_width_no_precision);
  tcase_add_test(tcase_core, short_hex_null_small_width_no_precision);
  tcase_add_test(tcase_core, short_hex_general_short_small_width_no_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core, short_hex_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_medium_neg_small_width_no_precision);
  tcase_add_test(tcase_core, SHORT_HEX_null_small_width_no_precision);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_small_width_no_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_medium_neg_small_width_no_precision);
  tcase_add_test(tcase_core, short_oct_null_small_width_no_precision);
  tcase_add_test(tcase_core, short_oct_general_short_small_width_no_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core, short_oct_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_medium_neg_small_width_no_precision);
  tcase_add_test(tcase_core, unsigned_short_null_small_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_small_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_neg_small_width_small_precision);
  tcase_add_test(tcase_core, short_hex_null_small_width_small_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_short_small_width_small_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_medium_neg_small_width_small_precision);
  tcase_add_test(tcase_core, SHORT_HEX_null_small_width_small_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_short_small_width_small_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_medium_neg_small_width_small_precision);
  tcase_add_test(tcase_core, short_oct_null_small_width_small_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_short_small_width_small_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_medium_neg_small_width_small_precision);
  tcase_add_test(tcase_core, unsigned_short_null_small_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_small_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_neg_small_width_big_precision);
  tcase_add_test(tcase_core, short_hex_null_small_width_big_precision);
  tcase_add_test(tcase_core, short_hex_general_short_small_width_big_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_medium_neg_small_width_big_precision);
  tcase_add_test(tcase_core, SHORT_HEX_null_small_width_big_precision);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_small_width_big_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_medium_neg_small_width_big_precision);
  tcase_add_test(tcase_core, short_oct_null_small_width_big_precision);
  tcase_add_test(tcase_core, short_oct_general_short_small_width_big_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_medium_neg_small_width_big_precision);
  tcase_add_test(tcase_core, unsigned_short_null_big_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_big_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_neg_big_width_no_precision);
  tcase_add_test(tcase_core, short_hex_null_big_width_no_precision);
  tcase_add_test(tcase_core, short_hex_general_short_big_width_no_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core, short_hex_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_medium_neg_big_width_no_precision);
  tcase_add_test(tcase_core, SHORT_HEX_null_big_width_no_precision);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_big_width_no_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_medium_neg_big_width_no_precision);
  tcase_add_test(tcase_core, short_oct_null_big_width_no_precision);
  tcase_add_test(tcase_core, short_oct_general_short_big_width_no_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core, short_oct_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_medium_neg_big_width_no_precision);
  tcase_add_test(tcase_core, unsigned_short_null_big_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_big_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_neg_big_width_small_precision);
  tcase_add_test(tcase_core, short_hex_null_big_width_small_precision);
  tcase_add_test(tcase_core, short_hex_general_short_big_width_small_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_medium_neg_big_width_small_precision);
  tcase_add_test(tcase_core, SHORT_HEX_null_big_width_small_precision);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_big_width_small_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_medium_neg_big_width_small_precision);
  tcase_add_test(tcase_core, short_oct_null_big_width_small_precision);
  tcase_add_test(tcase_core, short_oct_general_short_big_width_small_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_medium_neg_big_width_small_precision);
  tcase_add_test(tcase_core, unsigned_short_null_big_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_big_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_short_general_medium_neg_big_width_big_precision);
  tcase_add_test(tcase_core, short_hex_null_big_width_big_precision);
  tcase_add_test(tcase_core, short_hex_general_short_big_width_big_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core, short_hex_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core,
                 short_hex_general_medium_neg_big_width_big_precision);
  tcase_add_test(tcase_core, SHORT_HEX_null_big_width_big_precision);
  tcase_add_test(tcase_core, SHORT_HEX_general_short_big_width_big_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core, SHORT_HEX_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core,
                 SHORT_HEX_general_medium_neg_big_width_big_precision);
  tcase_add_test(tcase_core, short_oct_null_big_width_big_precision);
  tcase_add_test(tcase_core, short_oct_general_short_big_width_big_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core, short_oct_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core,
                 short_oct_general_medium_neg_big_width_big_precision);
  tcase_add_test(tcase_core, int_null_no_flags);
  tcase_add_test(tcase_core, int_general_short_no_flags);
  tcase_add_test(tcase_core, int_general_short_neg_no_flags);
  tcase_add_test(tcase_core, int_general_medium_no_flags);
  tcase_add_test(tcase_core, int_general_medium_neg_no_flags);
  tcase_add_test(tcase_core, alt_int_null_no_flags);
  tcase_add_test(tcase_core, alt_int_general_short_no_flags);
  tcase_add_test(tcase_core, alt_int_general_short_neg_no_flags);
  tcase_add_test(tcase_core, alt_int_general_medium_no_flags);
  tcase_add_test(tcase_core, alt_int_general_medium_neg_no_flags);
  tcase_add_test(tcase_core, unsigned_null_no_flags);
  tcase_add_test(tcase_core, unsigned_general_short_no_flags);
  tcase_add_test(tcase_core, unsigned_general_short_neg_no_flags);
  tcase_add_test(tcase_core, unsigned_general_medium_no_flags);
  tcase_add_test(tcase_core, unsigned_general_medium_neg_no_flags);
  tcase_add_test(tcase_core, hex_null_no_flags);
  tcase_add_test(tcase_core, hex_general_short_no_flags);
  tcase_add_test(tcase_core, hex_general_short_neg_no_flags);
  tcase_add_test(tcase_core, hex_general_medium_no_flags);
  tcase_add_test(tcase_core, hex_general_medium_neg_no_flags);
  tcase_add_test(tcase_core, HEX_null_no_flags);
  tcase_add_test(tcase_core, HEX_general_short_no_flags);
  tcase_add_test(tcase_core, HEX_general_short_neg_no_flags);
  tcase_add_test(tcase_core, HEX_general_medium_no_flags);
  tcase_add_test(tcase_core, HEX_general_medium_neg_no_flags);
  tcase_add_test(tcase_core, oct_null_no_flags);
  tcase_add_test(tcase_core, oct_general_short_no_flags);
  tcase_add_test(tcase_core, oct_general_short_neg_no_flags);
  tcase_add_test(tcase_core, oct_general_medium_no_flags);
  tcase_add_test(tcase_core, oct_general_medium_neg_no_flags);
  tcase_add_test(tcase_core, int_null_prefix_sign);
  tcase_add_test(tcase_core, int_general_short_prefix_sign);
  tcase_add_test(tcase_core, int_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, int_general_medium_prefix_sign);
  tcase_add_test(tcase_core, int_general_medium_neg_prefix_sign);
  tcase_add_test(tcase_core, alt_int_null_prefix_sign);
  tcase_add_test(tcase_core, alt_int_general_short_prefix_sign);
  tcase_add_test(tcase_core, alt_int_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, alt_int_general_medium_prefix_sign);
  tcase_add_test(tcase_core, alt_int_general_medium_neg_prefix_sign);
  tcase_add_test(tcase_core, unsigned_null_prefix_sign);
  tcase_add_test(tcase_core, unsigned_general_short_prefix_sign);
  tcase_add_test(tcase_core, unsigned_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, unsigned_general_medium_prefix_sign);
  tcase_add_test(tcase_core, unsigned_general_medium_neg_prefix_sign);
  tcase_add_test(tcase_core, hex_null_prefix_sign);
  tcase_add_test(tcase_core, hex_general_short_prefix_sign);
  tcase_add_test(tcase_core, hex_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, hex_general_medium_prefix_sign);
  tcase_add_test(tcase_core, hex_general_medium_neg_prefix_sign);
  tcase_add_test(tcase_core, HEX_null_prefix_sign);
  tcase_add_test(tcase_core, HEX_general_short_prefix_sign);
  tcase_add_test(tcase_core, HEX_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, HEX_general_medium_prefix_sign);
  tcase_add_test(tcase_core, HEX_general_medium_neg_prefix_sign);
  tcase_add_test(tcase_core, oct_null_prefix_sign);
  tcase_add_test(tcase_core, oct_general_short_prefix_sign);
  tcase_add_test(tcase_core, oct_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, oct_general_medium_prefix_sign);
  tcase_add_test(tcase_core, oct_general_medium_neg_prefix_sign);
  tcase_add_test(tcase_core, int_null_prefix_space);
  tcase_add_test(tcase_core, int_general_short_prefix_space);
  tcase_add_test(tcase_core, int_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, int_general_medium_prefix_space);
  tcase_add_test(tcase_core, int_general_medium_neg_prefix_space);
  tcase_add_test(tcase_core, alt_int_null_prefix_space);
  tcase_add_test(tcase_core, alt_int_general_short_prefix_space);
  tcase_add_test(tcase_core, alt_int_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, alt_int_general_medium_prefix_space);
  tcase_add_test(tcase_core, alt_int_general_medium_neg_prefix_space);
  tcase_add_test(tcase_core, unsigned_null_prefix_space);
  tcase_add_test(tcase_core, unsigned_general_short_prefix_space);
  tcase_add_test(tcase_core, unsigned_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, unsigned_general_medium_prefix_space);
  tcase_add_test(tcase_core, unsigned_general_medium_neg_prefix_space);
  tcase_add_test(tcase_core, hex_null_prefix_space);
  tcase_add_test(tcase_core, hex_general_short_prefix_space);
  tcase_add_test(tcase_core, hex_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, hex_general_medium_prefix_space);
  tcase_add_test(tcase_core, hex_general_medium_neg_prefix_space);
  tcase_add_test(tcase_core, HEX_null_prefix_space);
  tcase_add_test(tcase_core, HEX_general_short_prefix_space);
  tcase_add_test(tcase_core, HEX_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, HEX_general_medium_prefix_space);
  tcase_add_test(tcase_core, HEX_general_medium_neg_prefix_space);
  tcase_add_test(tcase_core, oct_null_prefix_space);
  tcase_add_test(tcase_core, oct_general_short_prefix_space);
  tcase_add_test(tcase_core, oct_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, oct_general_medium_prefix_space);
  tcase_add_test(tcase_core, oct_general_medium_neg_prefix_space);
  tcase_add_test(tcase_core, int_null_left_alignment);
  tcase_add_test(tcase_core, int_general_short_left_alignment);
  tcase_add_test(tcase_core, int_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, int_general_medium_left_alignment);
  tcase_add_test(tcase_core, int_general_medium_neg_left_alignment);
  tcase_add_test(tcase_core, alt_int_null_left_alignment);
  tcase_add_test(tcase_core, alt_int_general_short_left_alignment);
  tcase_add_test(tcase_core, alt_int_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, alt_int_general_medium_left_alignment);
  tcase_add_test(tcase_core, alt_int_general_medium_neg_left_alignment);
  tcase_add_test(tcase_core, unsigned_null_left_alignment);
  tcase_add_test(tcase_core, unsigned_general_short_left_alignment);
  tcase_add_test(tcase_core, unsigned_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, unsigned_general_medium_left_alignment);
  tcase_add_test(tcase_core, unsigned_general_medium_neg_left_alignment);
  tcase_add_test(tcase_core, hex_null_left_alignment);
  tcase_add_test(tcase_core, hex_general_short_left_alignment);
  tcase_add_test(tcase_core, hex_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, hex_general_medium_left_alignment);
  tcase_add_test(tcase_core, hex_general_medium_neg_left_alignment);
  tcase_add_test(tcase_core, HEX_null_left_alignment);
  tcase_add_test(tcase_core, HEX_general_short_left_alignment);
  tcase_add_test(tcase_core, HEX_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, HEX_general_medium_left_alignment);
  tcase_add_test(tcase_core, HEX_general_medium_neg_left_alignment);
  tcase_add_test(tcase_core, oct_null_left_alignment);
  tcase_add_test(tcase_core, oct_general_short_left_alignment);
  tcase_add_test(tcase_core, oct_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, oct_general_medium_left_alignment);
  tcase_add_test(tcase_core, oct_general_medium_neg_left_alignment);
  tcase_add_test(tcase_core, int_null_leading_zeroes);
  tcase_add_test(tcase_core, int_general_short_leading_zeroes);
  tcase_add_test(tcase_core, int_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, int_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, int_general_medium_neg_leading_zeroes);
  tcase_add_test(tcase_core, alt_int_null_leading_zeroes);
  tcase_add_test(tcase_core, alt_int_general_short_leading_zeroes);
  tcase_add_test(tcase_core, alt_int_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, alt_int_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, alt_int_general_medium_neg_leading_zeroes);
  tcase_add_test(tcase_core, unsigned_null_leading_zeroes);
  tcase_add_test(tcase_core, unsigned_general_short_leading_zeroes);
  tcase_add_test(tcase_core, unsigned_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, unsigned_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, unsigned_general_medium_neg_leading_zeroes);
  tcase_add_test(tcase_core, hex_null_leading_zeroes);
  tcase_add_test(tcase_core, hex_general_short_leading_zeroes);
  tcase_add_test(tcase_core, hex_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, hex_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, hex_general_medium_neg_leading_zeroes);
  tcase_add_test(tcase_core, HEX_null_leading_zeroes);
  tcase_add_test(tcase_core, HEX_general_short_leading_zeroes);
  tcase_add_test(tcase_core, HEX_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, HEX_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, HEX_general_medium_neg_leading_zeroes);
  tcase_add_test(tcase_core, oct_null_leading_zeroes);
  tcase_add_test(tcase_core, oct_general_short_leading_zeroes);
  tcase_add_test(tcase_core, oct_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, oct_general_medium_leading_zeroes);
  tcase_add_test(tcase_core, oct_general_medium_neg_leading_zeroes);
  tcase_add_test(tcase_core, int_null_alt_format);
  tcase_add_test(tcase_core, int_general_short_alt_format);
  tcase_add_test(tcase_core, int_general_short_neg_alt_format);
  tcase_add_test(tcase_core, int_general_medium_alt_format);
  tcase_add_test(tcase_core, int_general_medium_neg_alt_format);
  tcase_add_test(tcase_core, alt_int_null_alt_format);
  tcase_add_test(tcase_core, alt_int_general_short_alt_format);
  tcase_add_test(tcase_core, alt_int_general_short_neg_alt_format);
  tcase_add_test(tcase_core, alt_int_general_medium_alt_format);
  tcase_add_test(tcase_core, alt_int_general_medium_neg_alt_format);
  tcase_add_test(tcase_core, unsigned_null_alt_format);
  tcase_add_test(tcase_core, unsigned_general_short_alt_format);
  tcase_add_test(tcase_core, unsigned_general_short_neg_alt_format);
  tcase_add_test(tcase_core, unsigned_general_medium_alt_format);
  tcase_add_test(tcase_core, unsigned_general_medium_neg_alt_format);
  tcase_add_test(tcase_core, hex_null_alt_format);
  tcase_add_test(tcase_core, hex_general_short_alt_format);
  tcase_add_test(tcase_core, hex_general_short_neg_alt_format);
  tcase_add_test(tcase_core, hex_general_medium_alt_format);
  tcase_add_test(tcase_core, hex_general_medium_neg_alt_format);
  tcase_add_test(tcase_core, HEX_null_alt_format);
  tcase_add_test(tcase_core, HEX_general_short_alt_format);
  tcase_add_test(tcase_core, HEX_general_short_neg_alt_format);
  tcase_add_test(tcase_core, HEX_general_medium_alt_format);
  tcase_add_test(tcase_core, HEX_general_medium_neg_alt_format);
  tcase_add_test(tcase_core, oct_null_alt_format);
  tcase_add_test(tcase_core, oct_general_short_alt_format);
  tcase_add_test(tcase_core, oct_general_short_neg_alt_format);
  tcase_add_test(tcase_core, oct_general_medium_alt_format);
  tcase_add_test(tcase_core, oct_general_medium_neg_alt_format);
  tcase_add_test(tcase_core, int_null_no_width_no_precision);
  tcase_add_test(tcase_core, int_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, int_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core, int_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core, int_general_medium_neg_no_width_no_precision);
  tcase_add_test(tcase_core, alt_int_null_no_width_no_precision);
  tcase_add_test(tcase_core, alt_int_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, alt_int_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core, alt_int_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core, alt_int_general_medium_neg_no_width_no_precision);
  tcase_add_test(tcase_core, unsigned_null_no_width_no_precision);
  tcase_add_test(tcase_core, unsigned_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, unsigned_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core, unsigned_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core, unsigned_general_medium_neg_no_width_no_precision);
  tcase_add_test(tcase_core, hex_null_no_width_no_precision);
  tcase_add_test(tcase_core, hex_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, hex_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core, hex_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core, hex_general_medium_neg_no_width_no_precision);
  tcase_add_test(tcase_core, HEX_null_no_width_no_precision);
  tcase_add_test(tcase_core, HEX_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, HEX_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core, HEX_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core, HEX_general_medium_neg_no_width_no_precision);
  tcase_add_test(tcase_core, oct_null_no_width_no_precision);
  tcase_add_test(tcase_core, oct_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, oct_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core, oct_general_medium_no_width_no_precision);
  tcase_add_test(tcase_core, oct_general_medium_neg_no_width_no_precision);
  tcase_add_test(tcase_core, int_null_no_width_small_precision);
  tcase_add_test(tcase_core, int_general_short_no_width_small_precision);
  tcase_add_test(tcase_core, int_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core, int_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core, int_general_medium_neg_no_width_small_precision);
  tcase_add_test(tcase_core, alt_int_null_no_width_small_precision);
  tcase_add_test(tcase_core, alt_int_general_short_no_width_small_precision);
  tcase_add_test(tcase_core,
                 alt_int_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core, alt_int_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core,
                 alt_int_general_medium_neg_no_width_small_precision);
  tcase_add_test(tcase_core, unsigned_null_no_width_small_precision);
  tcase_add_test(tcase_core, unsigned_general_short_no_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core, unsigned_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_medium_neg_no_width_small_precision);
  tcase_add_test(tcase_core, hex_null_no_width_small_precision);
  tcase_add_test(tcase_core, hex_general_short_no_width_small_precision);
  tcase_add_test(tcase_core, hex_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core, hex_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core, hex_general_medium_neg_no_width_small_precision);
  tcase_add_test(tcase_core, HEX_null_no_width_small_precision);
  tcase_add_test(tcase_core, HEX_general_short_no_width_small_precision);
  tcase_add_test(tcase_core, HEX_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core, HEX_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core, HEX_general_medium_neg_no_width_small_precision);
  tcase_add_test(tcase_core, oct_null_no_width_small_precision);
  tcase_add_test(tcase_core, oct_general_short_no_width_small_precision);
  tcase_add_test(tcase_core, oct_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core, oct_general_medium_no_width_small_precision);
  tcase_add_test(tcase_core, oct_general_medium_neg_no_width_small_precision);
  tcase_add_test(tcase_core, int_null_no_width_big_precision);
  tcase_add_test(tcase_core, int_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, int_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core, int_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core, int_general_medium_neg_no_width_big_precision);
  tcase_add_test(tcase_core, alt_int_null_no_width_big_precision);
  tcase_add_test(tcase_core, alt_int_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, alt_int_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core, alt_int_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core, alt_int_general_medium_neg_no_width_big_precision);
  tcase_add_test(tcase_core, unsigned_null_no_width_big_precision);
  tcase_add_test(tcase_core, unsigned_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, unsigned_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core, unsigned_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_medium_neg_no_width_big_precision);
  tcase_add_test(tcase_core, hex_null_no_width_big_precision);
  tcase_add_test(tcase_core, hex_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, hex_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core, hex_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core, hex_general_medium_neg_no_width_big_precision);
  tcase_add_test(tcase_core, HEX_null_no_width_big_precision);
  tcase_add_test(tcase_core, HEX_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, HEX_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core, HEX_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core, HEX_general_medium_neg_no_width_big_precision);
  tcase_add_test(tcase_core, oct_null_no_width_big_precision);
  tcase_add_test(tcase_core, oct_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, oct_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core, oct_general_medium_no_width_big_precision);
  tcase_add_test(tcase_core, oct_general_medium_neg_no_width_big_precision);
  tcase_add_test(tcase_core, int_null_small_width_no_precision);
  tcase_add_test(tcase_core, int_general_short_small_width_no_precision);
  tcase_add_test(tcase_core, int_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core, int_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core, int_general_medium_neg_small_width_no_precision);
  tcase_add_test(tcase_core, alt_int_null_small_width_no_precision);
  tcase_add_test(tcase_core, alt_int_general_short_small_width_no_precision);
  tcase_add_test(tcase_core,
                 alt_int_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core, alt_int_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core,
                 alt_int_general_medium_neg_small_width_no_precision);
  tcase_add_test(tcase_core, unsigned_null_small_width_no_precision);
  tcase_add_test(tcase_core, unsigned_general_short_small_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core, unsigned_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_medium_neg_small_width_no_precision);
  tcase_add_test(tcase_core, hex_null_small_width_no_precision);
  tcase_add_test(tcase_core, hex_general_short_small_width_no_precision);
  tcase_add_test(tcase_core, hex_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core, hex_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core, hex_general_medium_neg_small_width_no_precision);
  tcase_add_test(tcase_core, HEX_null_small_width_no_precision);
  tcase_add_test(tcase_core, HEX_general_short_small_width_no_precision);
  tcase_add_test(tcase_core, HEX_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core, HEX_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core, HEX_general_medium_neg_small_width_no_precision);
  tcase_add_test(tcase_core, oct_null_small_width_no_precision);
  tcase_add_test(tcase_core, oct_general_short_small_width_no_precision);
  tcase_add_test(tcase_core, oct_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core, oct_general_medium_small_width_no_precision);
  tcase_add_test(tcase_core, oct_general_medium_neg_small_width_no_precision);
  tcase_add_test(tcase_core, int_null_small_width_small_precision);
  tcase_add_test(tcase_core, int_general_short_small_width_small_precision);
  tcase_add_test(tcase_core, int_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core, int_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core,
                 int_general_medium_neg_small_width_small_precision);
  tcase_add_test(tcase_core, alt_int_null_small_width_small_precision);
  tcase_add_test(tcase_core, alt_int_general_short_small_width_small_precision);
  tcase_add_test(tcase_core,
                 alt_int_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 alt_int_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core,
                 alt_int_general_medium_neg_small_width_small_precision);
  tcase_add_test(tcase_core, unsigned_null_small_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_short_small_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_medium_neg_small_width_small_precision);
  tcase_add_test(tcase_core, hex_null_small_width_small_precision);
  tcase_add_test(tcase_core, hex_general_short_small_width_small_precision);
  tcase_add_test(tcase_core, hex_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core, hex_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core,
                 hex_general_medium_neg_small_width_small_precision);
  tcase_add_test(tcase_core, HEX_null_small_width_small_precision);
  tcase_add_test(tcase_core, HEX_general_short_small_width_small_precision);
  tcase_add_test(tcase_core, HEX_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core, HEX_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core,
                 HEX_general_medium_neg_small_width_small_precision);
  tcase_add_test(tcase_core, oct_null_small_width_small_precision);
  tcase_add_test(tcase_core, oct_general_short_small_width_small_precision);
  tcase_add_test(tcase_core, oct_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core, oct_general_medium_small_width_small_precision);
  tcase_add_test(tcase_core,
                 oct_general_medium_neg_small_width_small_precision);
  tcase_add_test(tcase_core, int_null_small_width_big_precision);
  tcase_add_test(tcase_core, int_general_short_small_width_big_precision);
  tcase_add_test(tcase_core, int_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core, int_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core, int_general_medium_neg_small_width_big_precision);
  tcase_add_test(tcase_core, alt_int_null_small_width_big_precision);
  tcase_add_test(tcase_core, alt_int_general_short_small_width_big_precision);
  tcase_add_test(tcase_core,
                 alt_int_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core, alt_int_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core,
                 alt_int_general_medium_neg_small_width_big_precision);
  tcase_add_test(tcase_core, unsigned_null_small_width_big_precision);
  tcase_add_test(tcase_core, unsigned_general_short_small_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core, unsigned_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_medium_neg_small_width_big_precision);
  tcase_add_test(tcase_core, hex_null_small_width_big_precision);
  tcase_add_test(tcase_core, hex_general_short_small_width_big_precision);
  tcase_add_test(tcase_core, hex_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core, hex_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core, hex_general_medium_neg_small_width_big_precision);
  tcase_add_test(tcase_core, HEX_null_small_width_big_precision);
  tcase_add_test(tcase_core, HEX_general_short_small_width_big_precision);
  tcase_add_test(tcase_core, HEX_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core, HEX_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core, HEX_general_medium_neg_small_width_big_precision);
  tcase_add_test(tcase_core, oct_null_small_width_big_precision);
  tcase_add_test(tcase_core, oct_general_short_small_width_big_precision);
  tcase_add_test(tcase_core, oct_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core, oct_general_medium_small_width_big_precision);
  tcase_add_test(tcase_core, oct_general_medium_neg_small_width_big_precision);
  tcase_add_test(tcase_core, int_null_big_width_no_precision);
  tcase_add_test(tcase_core, int_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, int_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core, int_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core, int_general_medium_neg_big_width_no_precision);
  tcase_add_test(tcase_core, alt_int_null_big_width_no_precision);
  tcase_add_test(tcase_core, alt_int_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, alt_int_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core, alt_int_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core, alt_int_general_medium_neg_big_width_no_precision);
  tcase_add_test(tcase_core, unsigned_null_big_width_no_precision);
  tcase_add_test(tcase_core, unsigned_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, unsigned_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core, unsigned_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_medium_neg_big_width_no_precision);
  tcase_add_test(tcase_core, hex_null_big_width_no_precision);
  tcase_add_test(tcase_core, hex_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, hex_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core, hex_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core, hex_general_medium_neg_big_width_no_precision);
  tcase_add_test(tcase_core, HEX_null_big_width_no_precision);
  tcase_add_test(tcase_core, HEX_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, HEX_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core, HEX_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core, HEX_general_medium_neg_big_width_no_precision);
  tcase_add_test(tcase_core, oct_null_big_width_no_precision);
  tcase_add_test(tcase_core, oct_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, oct_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core, oct_general_medium_big_width_no_precision);
  tcase_add_test(tcase_core, oct_general_medium_neg_big_width_no_precision);
  tcase_add_test(tcase_core, int_null_big_width_small_precision);
  tcase_add_test(tcase_core, int_general_short_big_width_small_precision);
  tcase_add_test(tcase_core, int_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core, int_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core, int_general_medium_neg_big_width_small_precision);
  tcase_add_test(tcase_core, alt_int_null_big_width_small_precision);
  tcase_add_test(tcase_core, alt_int_general_short_big_width_small_precision);
  tcase_add_test(tcase_core,
                 alt_int_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core, alt_int_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core,
                 alt_int_general_medium_neg_big_width_small_precision);
  tcase_add_test(tcase_core, unsigned_null_big_width_small_precision);
  tcase_add_test(tcase_core, unsigned_general_short_big_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core, unsigned_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_medium_neg_big_width_small_precision);
  tcase_add_test(tcase_core, hex_null_big_width_small_precision);
  tcase_add_test(tcase_core, hex_general_short_big_width_small_precision);
  tcase_add_test(tcase_core, hex_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core, hex_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core, hex_general_medium_neg_big_width_small_precision);
  tcase_add_test(tcase_core, HEX_null_big_width_small_precision);
  tcase_add_test(tcase_core, HEX_general_short_big_width_small_precision);
  tcase_add_test(tcase_core, HEX_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core, HEX_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core, HEX_general_medium_neg_big_width_small_precision);
  tcase_add_test(tcase_core, oct_null_big_width_small_precision);
  tcase_add_test(tcase_core, oct_general_short_big_width_small_precision);
  tcase_add_test(tcase_core, oct_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core, oct_general_medium_big_width_small_precision);
  tcase_add_test(tcase_core, oct_general_medium_neg_big_width_small_precision);
  tcase_add_test(tcase_core, int_null_big_width_big_precision);
  tcase_add_test(tcase_core, int_general_short_big_width_big_precision);
  tcase_add_test(tcase_core, int_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core, int_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core, int_general_medium_neg_big_width_big_precision);
  tcase_add_test(tcase_core, alt_int_null_big_width_big_precision);
  tcase_add_test(tcase_core, alt_int_general_short_big_width_big_precision);
  tcase_add_test(tcase_core, alt_int_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core, alt_int_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core,
                 alt_int_general_medium_neg_big_width_big_precision);
  tcase_add_test(tcase_core, unsigned_null_big_width_big_precision);
  tcase_add_test(tcase_core, unsigned_general_short_big_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core, unsigned_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_general_medium_neg_big_width_big_precision);
  tcase_add_test(tcase_core, hex_null_big_width_big_precision);
  tcase_add_test(tcase_core, hex_general_short_big_width_big_precision);
  tcase_add_test(tcase_core, hex_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core, hex_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core, hex_general_medium_neg_big_width_big_precision);
  tcase_add_test(tcase_core, HEX_null_big_width_big_precision);
  tcase_add_test(tcase_core, HEX_general_short_big_width_big_precision);
  tcase_add_test(tcase_core, HEX_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core, HEX_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core, HEX_general_medium_neg_big_width_big_precision);
  tcase_add_test(tcase_core, oct_null_big_width_big_precision);
  tcase_add_test(tcase_core, oct_general_short_big_width_big_precision);
  tcase_add_test(tcase_core, oct_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core, oct_general_medium_big_width_big_precision);
  tcase_add_test(tcase_core, oct_general_medium_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_null_no_flags);
  tcase_add_test(tcase_core, long_general_short_no_flags);
  tcase_add_test(tcase_core, long_general_short_neg_no_flags);
  tcase_add_test(tcase_core, long_general_long_no_flags);
  tcase_add_test(tcase_core, long_general_long_neg_no_flags);
  tcase_add_test(tcase_core, unsigned_long_null_no_flags);
  tcase_add_test(tcase_core, unsigned_long_general_short_no_flags);
  tcase_add_test(tcase_core, unsigned_long_general_short_neg_no_flags);
  tcase_add_test(tcase_core, unsigned_long_general_long_no_flags);
  tcase_add_test(tcase_core, unsigned_long_general_long_neg_no_flags);
  tcase_add_test(tcase_core, long_hex_null_no_flags);
  tcase_add_test(tcase_core, long_hex_general_short_no_flags);
  tcase_add_test(tcase_core, long_hex_general_short_neg_no_flags);
  tcase_add_test(tcase_core, long_hex_general_long_no_flags);
  tcase_add_test(tcase_core, long_hex_general_long_neg_no_flags);
  tcase_add_test(tcase_core, LONG_HEX_null_no_flags);
  tcase_add_test(tcase_core, LONG_HEX_general_short_no_flags);
  tcase_add_test(tcase_core, LONG_HEX_general_short_neg_no_flags);
  tcase_add_test(tcase_core, LONG_HEX_general_long_no_flags);
  tcase_add_test(tcase_core, LONG_HEX_general_long_neg_no_flags);
  tcase_add_test(tcase_core, long_oct_null_no_flags);
  tcase_add_test(tcase_core, long_oct_general_short_no_flags);
  tcase_add_test(tcase_core, long_oct_general_short_neg_no_flags);
  tcase_add_test(tcase_core, long_oct_general_long_no_flags);
  tcase_add_test(tcase_core, long_oct_general_long_neg_no_flags);
  tcase_add_test(tcase_core, long_null_prefix_sign);
  tcase_add_test(tcase_core, long_general_short_prefix_sign);
  tcase_add_test(tcase_core, long_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, long_general_long_prefix_sign);
  tcase_add_test(tcase_core, long_general_long_neg_prefix_sign);
  tcase_add_test(tcase_core, unsigned_long_null_prefix_sign);
  tcase_add_test(tcase_core, unsigned_long_general_short_prefix_sign);
  tcase_add_test(tcase_core, unsigned_long_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, unsigned_long_general_long_prefix_sign);
  tcase_add_test(tcase_core, unsigned_long_general_long_neg_prefix_sign);
  tcase_add_test(tcase_core, long_hex_null_prefix_sign);
  tcase_add_test(tcase_core, long_hex_general_short_prefix_sign);
  tcase_add_test(tcase_core, long_hex_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, long_hex_general_long_prefix_sign);
  tcase_add_test(tcase_core, long_hex_general_long_neg_prefix_sign);
  tcase_add_test(tcase_core, LONG_HEX_null_prefix_sign);
  tcase_add_test(tcase_core, LONG_HEX_general_short_prefix_sign);
  tcase_add_test(tcase_core, LONG_HEX_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, LONG_HEX_general_long_prefix_sign);
  tcase_add_test(tcase_core, LONG_HEX_general_long_neg_prefix_sign);
  tcase_add_test(tcase_core, long_oct_null_prefix_sign);
  tcase_add_test(tcase_core, long_oct_general_short_prefix_sign);
  tcase_add_test(tcase_core, long_oct_general_short_neg_prefix_sign);
  tcase_add_test(tcase_core, long_oct_general_long_prefix_sign);
  tcase_add_test(tcase_core, long_oct_general_long_neg_prefix_sign);
  tcase_add_test(tcase_core, long_null_prefix_space);
  tcase_add_test(tcase_core, long_general_short_prefix_space);
  tcase_add_test(tcase_core, long_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, long_general_long_prefix_space);
  tcase_add_test(tcase_core, long_general_long_neg_prefix_space);
  tcase_add_test(tcase_core, unsigned_long_null_prefix_space);
  tcase_add_test(tcase_core, unsigned_long_general_short_prefix_space);
  tcase_add_test(tcase_core, unsigned_long_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, unsigned_long_general_long_prefix_space);
  tcase_add_test(tcase_core, unsigned_long_general_long_neg_prefix_space);
  tcase_add_test(tcase_core, long_hex_null_prefix_space);
  tcase_add_test(tcase_core, long_hex_general_short_prefix_space);
  tcase_add_test(tcase_core, long_hex_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, long_hex_general_long_prefix_space);
  tcase_add_test(tcase_core, long_hex_general_long_neg_prefix_space);
  tcase_add_test(tcase_core, LONG_HEX_null_prefix_space);
  tcase_add_test(tcase_core, LONG_HEX_general_short_prefix_space);
  tcase_add_test(tcase_core, LONG_HEX_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, LONG_HEX_general_long_prefix_space);
  tcase_add_test(tcase_core, LONG_HEX_general_long_neg_prefix_space);
  tcase_add_test(tcase_core, long_oct_null_prefix_space);
  tcase_add_test(tcase_core, long_oct_general_short_prefix_space);
  tcase_add_test(tcase_core, long_oct_general_short_neg_prefix_space);
  tcase_add_test(tcase_core, long_oct_general_long_prefix_space);
  tcase_add_test(tcase_core, long_oct_general_long_neg_prefix_space);
  tcase_add_test(tcase_core, long_null_left_alignment);
  tcase_add_test(tcase_core, long_general_short_left_alignment);
  tcase_add_test(tcase_core, long_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, long_general_long_left_alignment);
  tcase_add_test(tcase_core, long_general_long_neg_left_alignment);
  tcase_add_test(tcase_core, unsigned_long_null_left_alignment);
  tcase_add_test(tcase_core, unsigned_long_general_short_left_alignment);
  tcase_add_test(tcase_core, unsigned_long_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, unsigned_long_general_long_left_alignment);
  tcase_add_test(tcase_core, unsigned_long_general_long_neg_left_alignment);
  tcase_add_test(tcase_core, long_hex_null_left_alignment);
  tcase_add_test(tcase_core, long_hex_general_short_left_alignment);
  tcase_add_test(tcase_core, long_hex_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, long_hex_general_long_left_alignment);
  tcase_add_test(tcase_core, long_hex_general_long_neg_left_alignment);
  tcase_add_test(tcase_core, LONG_HEX_null_left_alignment);
  tcase_add_test(tcase_core, LONG_HEX_general_short_left_alignment);
  tcase_add_test(tcase_core, LONG_HEX_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, LONG_HEX_general_long_left_alignment);
  tcase_add_test(tcase_core, LONG_HEX_general_long_neg_left_alignment);
  tcase_add_test(tcase_core, long_oct_null_left_alignment);
  tcase_add_test(tcase_core, long_oct_general_short_left_alignment);
  tcase_add_test(tcase_core, long_oct_general_short_neg_left_alignment);
  tcase_add_test(tcase_core, long_oct_general_long_left_alignment);
  tcase_add_test(tcase_core, long_oct_general_long_neg_left_alignment);
  tcase_add_test(tcase_core, long_null_leading_zeroes);
  tcase_add_test(tcase_core, long_general_short_leading_zeroes);
  tcase_add_test(tcase_core, long_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_general_long_leading_zeroes);
  tcase_add_test(tcase_core, long_general_long_neg_leading_zeroes);
  tcase_add_test(tcase_core, unsigned_long_null_leading_zeroes);
  tcase_add_test(tcase_core, unsigned_long_general_short_leading_zeroes);
  tcase_add_test(tcase_core, unsigned_long_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, unsigned_long_general_long_leading_zeroes);
  tcase_add_test(tcase_core, unsigned_long_general_long_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_hex_null_leading_zeroes);
  tcase_add_test(tcase_core, long_hex_general_short_leading_zeroes);
  tcase_add_test(tcase_core, long_hex_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_hex_general_long_leading_zeroes);
  tcase_add_test(tcase_core, long_hex_general_long_neg_leading_zeroes);
  tcase_add_test(tcase_core, LONG_HEX_null_leading_zeroes);
  tcase_add_test(tcase_core, LONG_HEX_general_short_leading_zeroes);
  tcase_add_test(tcase_core, LONG_HEX_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, LONG_HEX_general_long_leading_zeroes);
  tcase_add_test(tcase_core, LONG_HEX_general_long_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_oct_null_leading_zeroes);
  tcase_add_test(tcase_core, long_oct_general_short_leading_zeroes);
  tcase_add_test(tcase_core, long_oct_general_short_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_oct_general_long_leading_zeroes);
  tcase_add_test(tcase_core, long_oct_general_long_neg_leading_zeroes);
  tcase_add_test(tcase_core, long_null_alt_format);
  tcase_add_test(tcase_core, long_general_short_alt_format);
  tcase_add_test(tcase_core, long_general_short_neg_alt_format);
  tcase_add_test(tcase_core, long_general_long_alt_format);
  tcase_add_test(tcase_core, long_general_long_neg_alt_format);
  tcase_add_test(tcase_core, unsigned_long_null_alt_format);
  tcase_add_test(tcase_core, unsigned_long_general_short_alt_format);
  tcase_add_test(tcase_core, unsigned_long_general_short_neg_alt_format);
  tcase_add_test(tcase_core, unsigned_long_general_long_alt_format);
  tcase_add_test(tcase_core, unsigned_long_general_long_neg_alt_format);
  tcase_add_test(tcase_core, long_hex_null_alt_format);
  tcase_add_test(tcase_core, long_hex_general_short_alt_format);
  tcase_add_test(tcase_core, long_hex_general_short_neg_alt_format);
  tcase_add_test(tcase_core, long_hex_general_long_alt_format);
  tcase_add_test(tcase_core, long_hex_general_long_neg_alt_format);
  tcase_add_test(tcase_core, LONG_HEX_null_alt_format);
  tcase_add_test(tcase_core, LONG_HEX_general_short_alt_format);
  tcase_add_test(tcase_core, LONG_HEX_general_short_neg_alt_format);
  tcase_add_test(tcase_core, LONG_HEX_general_long_alt_format);
  tcase_add_test(tcase_core, LONG_HEX_general_long_neg_alt_format);
  tcase_add_test(tcase_core, long_oct_null_alt_format);
  tcase_add_test(tcase_core, long_oct_general_short_alt_format);
  tcase_add_test(tcase_core, long_oct_general_short_neg_alt_format);
  tcase_add_test(tcase_core, long_oct_general_long_alt_format);
  tcase_add_test(tcase_core, long_oct_general_long_neg_alt_format);
  tcase_add_test(tcase_core, long_null_no_width_no_precision);
  tcase_add_test(tcase_core, long_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, long_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_general_long_no_width_no_precision);
  tcase_add_test(tcase_core, long_general_long_neg_no_width_no_precision);
  tcase_add_test(tcase_core, unsigned_long_null_no_width_no_precision);
  tcase_add_test(tcase_core, unsigned_long_general_short_no_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core, unsigned_long_general_long_no_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_long_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_hex_null_no_width_no_precision);
  tcase_add_test(tcase_core, long_hex_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, long_hex_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_hex_general_long_no_width_no_precision);
  tcase_add_test(tcase_core, long_hex_general_long_neg_no_width_no_precision);
  tcase_add_test(tcase_core, LONG_HEX_null_no_width_no_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_long_no_width_no_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_long_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_oct_null_no_width_no_precision);
  tcase_add_test(tcase_core, long_oct_general_short_no_width_no_precision);
  tcase_add_test(tcase_core, long_oct_general_short_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_oct_general_long_no_width_no_precision);
  tcase_add_test(tcase_core, long_oct_general_long_neg_no_width_no_precision);
  tcase_add_test(tcase_core, long_null_no_width_small_precision);
  tcase_add_test(tcase_core, long_general_short_no_width_small_precision);
  tcase_add_test(tcase_core, long_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_general_long_no_width_small_precision);
  tcase_add_test(tcase_core, long_general_long_neg_no_width_small_precision);
  tcase_add_test(tcase_core, unsigned_long_null_no_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_no_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_long_no_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_long_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_hex_null_no_width_small_precision);
  tcase_add_test(tcase_core, long_hex_general_short_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_hex_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_hex_general_long_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_hex_general_long_neg_no_width_small_precision);
  tcase_add_test(tcase_core, LONG_HEX_null_no_width_small_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_short_no_width_small_precision);
  tcase_add_test(tcase_core,
                 LONG_HEX_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_long_no_width_small_precision);
  tcase_add_test(tcase_core,
                 LONG_HEX_general_long_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_oct_null_no_width_small_precision);
  tcase_add_test(tcase_core, long_oct_general_short_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_oct_general_short_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_oct_general_long_no_width_small_precision);
  tcase_add_test(tcase_core,
                 long_oct_general_long_neg_no_width_small_precision);
  tcase_add_test(tcase_core, long_null_no_width_big_precision);
  tcase_add_test(tcase_core, long_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, long_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_general_long_no_width_big_precision);
  tcase_add_test(tcase_core, long_general_long_neg_no_width_big_precision);
  tcase_add_test(tcase_core, unsigned_long_null_no_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_no_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core, unsigned_long_general_long_no_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_long_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_hex_null_no_width_big_precision);
  tcase_add_test(tcase_core, long_hex_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, long_hex_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_hex_general_long_no_width_big_precision);
  tcase_add_test(tcase_core, long_hex_general_long_neg_no_width_big_precision);
  tcase_add_test(tcase_core, LONG_HEX_null_no_width_big_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_long_no_width_big_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_long_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_oct_null_no_width_big_precision);
  tcase_add_test(tcase_core, long_oct_general_short_no_width_big_precision);
  tcase_add_test(tcase_core, long_oct_general_short_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_oct_general_long_no_width_big_precision);
  tcase_add_test(tcase_core, long_oct_general_long_neg_no_width_big_precision);
  tcase_add_test(tcase_core, long_null_small_width_no_precision);
  tcase_add_test(tcase_core, long_general_short_small_width_no_precision);
  tcase_add_test(tcase_core, long_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_general_long_small_width_no_precision);
  tcase_add_test(tcase_core, long_general_long_neg_small_width_no_precision);
  tcase_add_test(tcase_core, unsigned_long_null_small_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_small_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_long_small_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_long_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_hex_null_small_width_no_precision);
  tcase_add_test(tcase_core, long_hex_general_short_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_hex_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_hex_general_long_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_hex_general_long_neg_small_width_no_precision);
  tcase_add_test(tcase_core, LONG_HEX_null_small_width_no_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_short_small_width_no_precision);
  tcase_add_test(tcase_core,
                 LONG_HEX_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_long_small_width_no_precision);
  tcase_add_test(tcase_core,
                 LONG_HEX_general_long_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_oct_null_small_width_no_precision);
  tcase_add_test(tcase_core, long_oct_general_short_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_oct_general_short_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_oct_general_long_small_width_no_precision);
  tcase_add_test(tcase_core,
                 long_oct_general_long_neg_small_width_no_precision);
  tcase_add_test(tcase_core, long_null_small_width_small_precision);
  tcase_add_test(tcase_core, long_general_short_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core, long_general_long_small_width_small_precision);
  tcase_add_test(tcase_core, long_general_long_neg_small_width_small_precision);
  tcase_add_test(tcase_core, unsigned_long_null_small_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_small_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_long_small_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_long_neg_small_width_small_precision);
  tcase_add_test(tcase_core, long_hex_null_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_hex_general_short_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_hex_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core, long_hex_general_long_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_hex_general_long_neg_small_width_small_precision);
  tcase_add_test(tcase_core, LONG_HEX_null_small_width_small_precision);
  tcase_add_test(tcase_core,
                 LONG_HEX_general_short_small_width_small_precision);
  tcase_add_test(tcase_core,
                 LONG_HEX_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_long_small_width_small_precision);
  tcase_add_test(tcase_core,
                 LONG_HEX_general_long_neg_small_width_small_precision);
  tcase_add_test(tcase_core, long_oct_null_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_oct_general_short_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_oct_general_short_neg_small_width_small_precision);
  tcase_add_test(tcase_core, long_oct_general_long_small_width_small_precision);
  tcase_add_test(tcase_core,
                 long_oct_general_long_neg_small_width_small_precision);
  tcase_add_test(tcase_core, long_null_small_width_big_precision);
  tcase_add_test(tcase_core, long_general_short_small_width_big_precision);
  tcase_add_test(tcase_core, long_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core, long_general_long_small_width_big_precision);
  tcase_add_test(tcase_core, long_general_long_neg_small_width_big_precision);
  tcase_add_test(tcase_core, unsigned_long_null_small_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_small_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_long_small_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_long_neg_small_width_big_precision);
  tcase_add_test(tcase_core, long_hex_null_small_width_big_precision);
  tcase_add_test(tcase_core, long_hex_general_short_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_hex_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core, long_hex_general_long_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_hex_general_long_neg_small_width_big_precision);
  tcase_add_test(tcase_core, LONG_HEX_null_small_width_big_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_short_small_width_big_precision);
  tcase_add_test(tcase_core,
                 LONG_HEX_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_long_small_width_big_precision);
  tcase_add_test(tcase_core,
                 LONG_HEX_general_long_neg_small_width_big_precision);
  tcase_add_test(tcase_core, long_oct_null_small_width_big_precision);
  tcase_add_test(tcase_core, long_oct_general_short_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_oct_general_short_neg_small_width_big_precision);
  tcase_add_test(tcase_core, long_oct_general_long_small_width_big_precision);
  tcase_add_test(tcase_core,
                 long_oct_general_long_neg_small_width_big_precision);
  tcase_add_test(tcase_core, long_null_big_width_no_precision);
  tcase_add_test(tcase_core, long_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, long_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_general_long_big_width_no_precision);
  tcase_add_test(tcase_core, long_general_long_neg_big_width_no_precision);
  tcase_add_test(tcase_core, unsigned_long_null_big_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_big_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core, unsigned_long_general_long_big_width_no_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_long_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_hex_null_big_width_no_precision);
  tcase_add_test(tcase_core, long_hex_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, long_hex_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_hex_general_long_big_width_no_precision);
  tcase_add_test(tcase_core, long_hex_general_long_neg_big_width_no_precision);
  tcase_add_test(tcase_core, LONG_HEX_null_big_width_no_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_long_big_width_no_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_long_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_oct_null_big_width_no_precision);
  tcase_add_test(tcase_core, long_oct_general_short_big_width_no_precision);
  tcase_add_test(tcase_core, long_oct_general_short_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_oct_general_long_big_width_no_precision);
  tcase_add_test(tcase_core, long_oct_general_long_neg_big_width_no_precision);
  tcase_add_test(tcase_core, long_null_big_width_small_precision);
  tcase_add_test(tcase_core, long_general_short_big_width_small_precision);
  tcase_add_test(tcase_core, long_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core, long_general_long_big_width_small_precision);
  tcase_add_test(tcase_core, long_general_long_neg_big_width_small_precision);
  tcase_add_test(tcase_core, unsigned_long_null_big_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_big_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_long_big_width_small_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_long_neg_big_width_small_precision);
  tcase_add_test(tcase_core, long_hex_null_big_width_small_precision);
  tcase_add_test(tcase_core, long_hex_general_short_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_hex_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core, long_hex_general_long_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_hex_general_long_neg_big_width_small_precision);
  tcase_add_test(tcase_core, LONG_HEX_null_big_width_small_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_short_big_width_small_precision);
  tcase_add_test(tcase_core,
                 LONG_HEX_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_long_big_width_small_precision);
  tcase_add_test(tcase_core,
                 LONG_HEX_general_long_neg_big_width_small_precision);
  tcase_add_test(tcase_core, long_oct_null_big_width_small_precision);
  tcase_add_test(tcase_core, long_oct_general_short_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_oct_general_short_neg_big_width_small_precision);
  tcase_add_test(tcase_core, long_oct_general_long_big_width_small_precision);
  tcase_add_test(tcase_core,
                 long_oct_general_long_neg_big_width_small_precision);
  tcase_add_test(tcase_core, long_null_big_width_big_precision);
  tcase_add_test(tcase_core, long_general_short_big_width_big_precision);
  tcase_add_test(tcase_core, long_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_general_long_big_width_big_precision);
  tcase_add_test(tcase_core, long_general_long_neg_big_width_big_precision);
  tcase_add_test(tcase_core, unsigned_long_null_big_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_big_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_long_big_width_big_precision);
  tcase_add_test(tcase_core,
                 unsigned_long_general_long_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_hex_null_big_width_big_precision);
  tcase_add_test(tcase_core, long_hex_general_short_big_width_big_precision);
  tcase_add_test(tcase_core,
                 long_hex_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_hex_general_long_big_width_big_precision);
  tcase_add_test(tcase_core, long_hex_general_long_neg_big_width_big_precision);
  tcase_add_test(tcase_core, LONG_HEX_null_big_width_big_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_short_big_width_big_precision);
  tcase_add_test(tcase_core,
                 LONG_HEX_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_long_big_width_big_precision);
  tcase_add_test(tcase_core, LONG_HEX_general_long_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_oct_null_big_width_big_precision);
  tcase_add_test(tcase_core, long_oct_general_short_big_width_big_precision);
  tcase_add_test(tcase_core,
                 long_oct_general_short_neg_big_width_big_precision);
  tcase_add_test(tcase_core, long_oct_general_long_big_width_big_precision);
  tcase_add_test(tcase_core, long_oct_general_long_neg_big_width_big_precision);
  tcase_add_test(tcase_core, pointer_null_no_flags);
  tcase_add_test(tcase_core, pointer_format_ptr_no_flags);
  tcase_add_test(tcase_core, pointer_null_prefix_sign);
  tcase_add_test(tcase_core, pointer_format_ptr_prefix_sign);
  tcase_add_test(tcase_core, pointer_null_prefix_space);
  tcase_add_test(tcase_core, pointer_format_ptr_prefix_space);
  tcase_add_test(tcase_core, pointer_null_left_alignment);
  tcase_add_test(tcase_core, pointer_format_ptr_left_alignment);
  tcase_add_test(tcase_core, pointer_null_leading_zeroes);
  tcase_add_test(tcase_core, pointer_format_ptr_leading_zeroes);
  tcase_add_test(tcase_core, pointer_null_alt_format);
  tcase_add_test(tcase_core, pointer_format_ptr_alt_format);
  tcase_add_test(tcase_core, pointer_null_no_width_no_precision);
  tcase_add_test(tcase_core, pointer_format_ptr_no_width_no_precision);
  tcase_add_test(tcase_core, pointer_null_no_width_small_precision);
  tcase_add_test(tcase_core, pointer_format_ptr_no_width_small_precision);
  tcase_add_test(tcase_core, pointer_null_no_width_big_precision);
  tcase_add_test(tcase_core, pointer_format_ptr_no_width_big_precision);
  tcase_add_test(tcase_core, pointer_null_small_width_no_precision);
  tcase_add_test(tcase_core, pointer_format_ptr_small_width_no_precision);
  tcase_add_test(tcase_core, pointer_null_small_width_small_precision);
  tcase_add_test(tcase_core, pointer_format_ptr_small_width_small_precision);
  tcase_add_test(tcase_core, pointer_null_small_width_big_precision);
  tcase_add_test(tcase_core, pointer_format_ptr_small_width_big_precision);
  tcase_add_test(tcase_core, pointer_null_big_width_no_precision);
  tcase_add_test(tcase_core, pointer_format_ptr_big_width_no_precision);
  tcase_add_test(tcase_core, pointer_null_big_width_small_precision);
  tcase_add_test(tcase_core, pointer_format_ptr_big_width_small_precision);
  tcase_add_test(tcase_core, pointer_null_big_width_big_precision);
  tcase_add_test(tcase_core, pointer_format_ptr_big_width_big_precision);
  tcase_add_test(tcase_core, char_null_no_flags);
  tcase_add_test(tcase_core, char_general_no_flags);
  tcase_add_test(tcase_core, char_out_of_bounds_no_flags);
  tcase_add_test(tcase_core, char_null_prefix_sign);
  tcase_add_test(tcase_core, char_general_prefix_sign);
  tcase_add_test(tcase_core, char_out_of_bounds_prefix_sign);
  tcase_add_test(tcase_core, char_null_prefix_space);
  tcase_add_test(tcase_core, char_general_prefix_space);
  tcase_add_test(tcase_core, char_out_of_bounds_prefix_space);
  tcase_add_test(tcase_core, char_null_left_alignment);
  tcase_add_test(tcase_core, char_general_left_alignment);
  tcase_add_test(tcase_core, char_out_of_bounds_left_alignment);
  tcase_add_test(tcase_core, char_null_leading_zeroes);
  tcase_add_test(tcase_core, char_general_leading_zeroes);
  tcase_add_test(tcase_core, char_out_of_bounds_leading_zeroes);
  tcase_add_test(tcase_core, char_null_alt_format);
  tcase_add_test(tcase_core, char_general_alt_format);
  tcase_add_test(tcase_core, char_out_of_bounds_alt_format);
  tcase_add_test(tcase_core, char_null_no_width_no_precision);
  tcase_add_test(tcase_core, char_general_no_width_no_precision);
  tcase_add_test(tcase_core, char_out_of_bounds_no_width_no_precision);
  tcase_add_test(tcase_core, char_null_no_width_small_precision);
  tcase_add_test(tcase_core, char_general_no_width_small_precision);
  tcase_add_test(tcase_core, char_out_of_bounds_no_width_small_precision);
  tcase_add_test(tcase_core, char_null_no_width_big_precision);
  tcase_add_test(tcase_core, char_general_no_width_big_precision);
  tcase_add_test(tcase_core, char_out_of_bounds_no_width_big_precision);
  tcase_add_test(tcase_core, char_null_small_width_no_precision);
  tcase_add_test(tcase_core, char_general_small_width_no_precision);
  tcase_add_test(tcase_core, char_out_of_bounds_small_width_no_precision);
  tcase_add_test(tcase_core, char_null_small_width_small_precision);
  tcase_add_test(tcase_core, char_general_small_width_small_precision);
  tcase_add_test(tcase_core, char_out_of_bounds_small_width_small_precision);
  tcase_add_test(tcase_core, char_null_small_width_big_precision);
  tcase_add_test(tcase_core, char_general_small_width_big_precision);
  tcase_add_test(tcase_core, char_out_of_bounds_small_width_big_precision);
  tcase_add_test(tcase_core, char_null_big_width_no_precision);
  tcase_add_test(tcase_core, char_general_big_width_no_precision);
  tcase_add_test(tcase_core, char_out_of_bounds_big_width_no_precision);
  tcase_add_test(tcase_core, char_null_big_width_small_precision);
  tcase_add_test(tcase_core, char_general_big_width_small_precision);
  tcase_add_test(tcase_core, char_out_of_bounds_big_width_small_precision);
  tcase_add_test(tcase_core, char_null_big_width_big_precision);
  tcase_add_test(tcase_core, char_general_big_width_big_precision);
  tcase_add_test(tcase_core, char_out_of_bounds_big_width_big_precision);
  tcase_add_test(tcase_core, long_char_null_no_flags);
  tcase_add_test(tcase_core, long_char_general_no_flags);
  tcase_add_test(tcase_core, long_char_null_prefix_sign);
  tcase_add_test(tcase_core, long_char_general_prefix_sign);
  tcase_add_test(tcase_core, long_char_null_prefix_space);
  tcase_add_test(tcase_core, long_char_general_prefix_space);
  tcase_add_test(tcase_core, long_char_null_left_alignment);
  tcase_add_test(tcase_core, long_char_general_left_alignment);
  tcase_add_test(tcase_core, long_char_null_leading_zeroes);
  tcase_add_test(tcase_core, long_char_general_leading_zeroes);
  tcase_add_test(tcase_core, long_char_null_alt_format);
  tcase_add_test(tcase_core, long_char_general_alt_format);
  tcase_add_test(tcase_core, long_char_null_no_width_no_precision);
  tcase_add_test(tcase_core, long_char_general_no_width_no_precision);
  tcase_add_test(tcase_core, long_char_null_no_width_small_precision);
  tcase_add_test(tcase_core, long_char_general_no_width_small_precision);
  tcase_add_test(tcase_core, long_char_null_no_width_big_precision);
  tcase_add_test(tcase_core, long_char_general_no_width_big_precision);
  tcase_add_test(tcase_core, long_char_null_small_width_no_precision);
  tcase_add_test(tcase_core, long_char_general_small_width_no_precision);
  tcase_add_test(tcase_core, long_char_null_small_width_small_precision);
  tcase_add_test(tcase_core, long_char_general_small_width_small_precision);
  tcase_add_test(tcase_core, long_char_null_small_width_big_precision);
  tcase_add_test(tcase_core, long_char_general_small_width_big_precision);
  tcase_add_test(tcase_core, long_char_null_big_width_no_precision);
  tcase_add_test(tcase_core, long_char_general_big_width_no_precision);
  tcase_add_test(tcase_core, long_char_null_big_width_small_precision);
  tcase_add_test(tcase_core, long_char_general_big_width_small_precision);
  tcase_add_test(tcase_core, long_char_null_big_width_big_precision);
  tcase_add_test(tcase_core, long_char_general_big_width_big_precision);
  tcase_add_test(tcase_core, string_empty_no_flags);
  tcase_add_test(tcase_core, string_len_one_no_flags);
  tcase_add_test(tcase_core, string_general_no_flags);
  tcase_add_test(tcase_core, string_empty_prefix_sign);
  tcase_add_test(tcase_core, string_len_one_prefix_sign);
  tcase_add_test(tcase_core, string_general_prefix_sign);
  tcase_add_test(tcase_core, string_empty_prefix_space);
  tcase_add_test(tcase_core, string_len_one_prefix_space);
  tcase_add_test(tcase_core, string_general_prefix_space);
  tcase_add_test(tcase_core, string_empty_left_alignment);
  tcase_add_test(tcase_core, string_len_one_left_alignment);
  tcase_add_test(tcase_core, string_general_left_alignment);
  tcase_add_test(tcase_core, string_empty_leading_zeroes);
  tcase_add_test(tcase_core, string_len_one_leading_zeroes);
  tcase_add_test(tcase_core, string_general_leading_zeroes);
  tcase_add_test(tcase_core, string_empty_alt_format);
  tcase_add_test(tcase_core, string_len_one_alt_format);
  tcase_add_test(tcase_core, string_general_alt_format);
  tcase_add_test(tcase_core, string_empty_no_width_no_precision);
  tcase_add_test(tcase_core, string_len_one_no_width_no_precision);
  tcase_add_test(tcase_core, string_general_no_width_no_precision);
  tcase_add_test(tcase_core, string_empty_no_width_small_precision);
  tcase_add_test(tcase_core, string_len_one_no_width_small_precision);
  tcase_add_test(tcase_core, string_general_no_width_small_precision);
  tcase_add_test(tcase_core, string_empty_no_width_big_precision);
  tcase_add_test(tcase_core, string_len_one_no_width_big_precision);
  tcase_add_test(tcase_core, string_general_no_width_big_precision);
  tcase_add_test(tcase_core, string_empty_small_width_no_precision);
  tcase_add_test(tcase_core, string_len_one_small_width_no_precision);
  tcase_add_test(tcase_core, string_general_small_width_no_precision);
  tcase_add_test(tcase_core, string_empty_small_width_small_precision);
  tcase_add_test(tcase_core, string_len_one_small_width_small_precision);
  tcase_add_test(tcase_core, string_general_small_width_small_precision);
  tcase_add_test(tcase_core, string_empty_small_width_big_precision);
  tcase_add_test(tcase_core, string_len_one_small_width_big_precision);
  tcase_add_test(tcase_core, string_general_small_width_big_precision);
  tcase_add_test(tcase_core, string_empty_big_width_no_precision);
  tcase_add_test(tcase_core, string_len_one_big_width_no_precision);
  tcase_add_test(tcase_core, string_general_big_width_no_precision);
  tcase_add_test(tcase_core, string_empty_big_width_small_precision);
  tcase_add_test(tcase_core, string_len_one_big_width_small_precision);
  tcase_add_test(tcase_core, string_general_big_width_small_precision);
  tcase_add_test(tcase_core, string_empty_big_width_big_precision);
  tcase_add_test(tcase_core, string_len_one_big_width_big_precision);
  tcase_add_test(tcase_core, string_general_big_width_big_precision);
  tcase_add_test(tcase_core, long_string_empty_no_flags);
  tcase_add_test(tcase_core, long_string_len_one_no_flags);
  tcase_add_test(tcase_core, long_string_general_no_flags);
  tcase_add_test(tcase_core, long_string_empty_prefix_sign);
  tcase_add_test(tcase_core, long_string_len_one_prefix_sign);
  tcase_add_test(tcase_core, long_string_general_prefix_sign);
  tcase_add_test(tcase_core, long_string_empty_prefix_space);
  tcase_add_test(tcase_core, long_string_len_one_prefix_space);
  tcase_add_test(tcase_core, long_string_general_prefix_space);
  tcase_add_test(tcase_core, long_string_empty_left_alignment);
  tcase_add_test(tcase_core, long_string_len_one_left_alignment);
  tcase_add_test(tcase_core, long_string_general_left_alignment);
  tcase_add_test(tcase_core, long_string_empty_leading_zeroes);
  tcase_add_test(tcase_core, long_string_len_one_leading_zeroes);
  tcase_add_test(tcase_core, long_string_general_leading_zeroes);
  tcase_add_test(tcase_core, long_string_empty_alt_format);
  tcase_add_test(tcase_core, long_string_len_one_alt_format);
  tcase_add_test(tcase_core, long_string_general_alt_format);
  tcase_add_test(tcase_core, long_string_empty_no_width_no_precision);
  tcase_add_test(tcase_core, long_string_len_one_no_width_no_precision);
  tcase_add_test(tcase_core, long_string_general_no_width_no_precision);
  tcase_add_test(tcase_core, long_string_empty_no_width_small_precision);
  tcase_add_test(tcase_core, long_string_len_one_no_width_small_precision);
  tcase_add_test(tcase_core, long_string_general_no_width_small_precision);
  tcase_add_test(tcase_core, long_string_empty_no_width_big_precision);
  tcase_add_test(tcase_core, long_string_len_one_no_width_big_precision);
  tcase_add_test(tcase_core, long_string_general_no_width_big_precision);
  tcase_add_test(tcase_core, long_string_empty_small_width_no_precision);
  tcase_add_test(tcase_core, long_string_len_one_small_width_no_precision);
  tcase_add_test(tcase_core, long_string_general_small_width_no_precision);
  tcase_add_test(tcase_core, long_string_empty_small_width_small_precision);
  tcase_add_test(tcase_core, long_string_len_one_small_width_small_precision);
  tcase_add_test(tcase_core, long_string_general_small_width_small_precision);
  tcase_add_test(tcase_core, long_string_empty_small_width_big_precision);
  tcase_add_test(tcase_core, long_string_len_one_small_width_big_precision);
  tcase_add_test(tcase_core, long_string_general_small_width_big_precision);
  tcase_add_test(tcase_core, long_string_empty_big_width_no_precision);
  tcase_add_test(tcase_core, long_string_len_one_big_width_no_precision);
  tcase_add_test(tcase_core, long_string_general_big_width_no_precision);
  tcase_add_test(tcase_core, long_string_empty_big_width_small_precision);
  tcase_add_test(tcase_core, long_string_len_one_big_width_small_precision);
  tcase_add_test(tcase_core, long_string_general_big_width_small_precision);
  tcase_add_test(tcase_core, long_string_empty_big_width_big_precision);
  tcase_add_test(tcase_core, long_string_len_one_big_width_big_precision);
  tcase_add_test(tcase_core, long_string_general_big_width_big_precision);
  tcase_add_test(tcase_core, arbitrary_no_width_no_precision);
  tcase_add_test(tcase_core, arbitrary_no_width_small_precision);
  tcase_add_test(tcase_core, arbitrary_no_width_big_precision);
  tcase_add_test(tcase_core, arbitrary_small_width_no_precision);
  tcase_add_test(tcase_core, arbitrary_small_width_small_precision);
  tcase_add_test(tcase_core, arbitrary_small_width_big_precision);
  tcase_add_test(tcase_core, arbitrary_big_width_no_precision);
  tcase_add_test(tcase_core, arbitrary_big_width_small_precision);
  tcase_add_test(tcase_core, arbitrary_big_width_big_precision);
  tcase_add_test(tcase_core, multiple_formats);
  tcase_add_test(tcase_core, empty_format);
  tcase_add_test(tcase_core, no_specifier_short);
  tcase_add_test(tcase_core, no_specifier_long);
  tcase_add_test(tcase_core, invalid_specifier_short);
  tcase_add_test(tcase_core, invalid_specifier_long);

  suite_add_tcase(suite, tcase_core);
  return suite;
}
