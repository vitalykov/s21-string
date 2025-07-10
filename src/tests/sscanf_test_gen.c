#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector_str/vector_str.h"

#define FILE_NAME "tests/test_s21_sscanf.c"

#define TEST_NAME_BUF_SIZE 200
#define DEFAULT_BUF_SIZE 1024
#define VAR_NAME_BUF_SIZE 32

#define HEADER \
  "\
#include <stdio.h>\n\
#include <math.h>\n\
#include <wchar.h>\n\
\n\
#include \"s21_string.h\"\n\
#include \"tests/test.h\"\n\
\n\
#define RUN_TEST(var_type, str_val, str_fmt, assert_func)\\\n\
  var_type got_var;\\\n\
  var_type expected_var;\\\n\
  ck_assert_int_eq(s21_sscanf(str_val, str_fmt, &got_var),\\\n\
                   sscanf(str_val, str_fmt, &expected_var));\\\n\
  assert_func(got_var, expected_var);\\\n\
"

#define SUITE_START \
  "\
Suite* suite_s21_sscanf(void) { \n\
  Suite* suite = suite_create(\"s21_sscanf\");\n\
  TCase* tcase_core = tcase_create(\"core of s21_sscanf\");\n\
\n\
"

#define SUITE_END \
  "\
  suite_add_tcase(suite, tcase_core);\n\
  return suite;\n\
} \n\
"

struct TestValue {
  const char* repr;
  const char* name;
};
typedef struct TestValue TestValue;

struct TestFmtOpt {
  const char* fmt;
  const char* name;
};
typedef struct TestFmtOpt TestFmtOpt;

struct TestType {
  const char* fmt;
  const char* type;
  const char* assert_func;
};
typedef struct TestType TestType;

#define WIDTHS_COUNT 4

void GenerateTestsEnumValues(FILE* fp, VectorStr* test_names,
                             const TestValue* values, int values_count,
                             const TestType* specifiers, int spec_count) {
  static const TestFmtOpt widths[WIDTHS_COUNT] = {{"", "no_width"},
                                                  {"10", "small_width"},
                                                  {"25", "medium_width"},
                                                  {"70", "big_width"}};
  for (int spec_i = 0; spec_i < spec_count; ++spec_i) {
    TestType specifier = specifiers[spec_i];
    for (int width_i = 0; width_i < WIDTHS_COUNT; ++width_i) {
      TestFmtOpt width = widths[width_i];
      if (strchr(specifier.fmt, 'c') == NULL || strcmp(width.fmt, "") == 0)
        for (int val_i = 0; val_i < values_count; ++val_i) {
          TestValue value = values[val_i];
          char test_name[TEST_NAME_BUF_SIZE];
          sprintf(test_name, "%s_%s_%s", specifier.fmt, value.name, width.name);
          PushBackStr(test_names, test_name);
          fprintf(fp,
                  "START_TEST(%s) {\n  RUN_TEST(%s, \"%s\", \"%%%s%s\", "
                  "%s);\n}\nEND_TEST\n",
                  test_name, specifier.type, value.repr, width.fmt,
                  specifier.fmt, specifier.assert_func);
        }
    }
  }
}

void GenerateIntegrationTest(FILE* fp, VectorStr* test_names,
                             const char* test_name, const char* str_val,
                             const char* str_fmt, const TestType* specifiers,
                             int spec_count) {
  char decl_buf[DEFAULT_BUF_SIZE] = {0};
  char assert_buf[DEFAULT_BUF_SIZE] = {0};
  char got_args[DEFAULT_BUF_SIZE] = {0};
  char expected_args[DEFAULT_BUF_SIZE] = {0};

  for (int i = 0; i < spec_count; ++i) {
    char var_name[VAR_NAME_BUF_SIZE];
    snprintf(var_name, sizeof(var_name), "var%d", (int)i + 1);

    strcat(decl_buf, "  ");
    strcat(decl_buf, specifiers[i].type);
    strcat(decl_buf, " got_");
    strcat(decl_buf, var_name);
    strcat(decl_buf, ", expected_");
    strcat(decl_buf, var_name);
    strcat(decl_buf, ";\n");

    strcat(assert_buf, "  ");
    strcat(assert_buf, specifiers[i].assert_func);
    strcat(assert_buf, "(got_");
    strcat(assert_buf, var_name);
    strcat(assert_buf, ", expected_");
    strcat(assert_buf, var_name);
    strcat(assert_buf, ");\n");

    if (i > 0) {
      strcat(got_args, ", ");
      strcat(expected_args, ", ");
    }
    strcat(got_args, "&got_");
    strcat(got_args, var_name);
    strcat(expected_args, "&expected_");
    strcat(expected_args, var_name);
  }

  fprintf(fp,
          "START_TEST(%s) {\n"
          "%s"
          "  ck_assert_int_eq(s21_sscanf(\"%s\", \"%s\", %s),\n"
          "                   sscanf(\"%s\", \"%s\", %s));\n"
          "%s"
          "}\n"
          "END_TEST\n",
          test_name, decl_buf, str_val, str_fmt, got_args, str_val, str_fmt,
          expected_args, assert_buf);

  PushBackStr(test_names, test_name);
}

void GenerateFloatTests(FILE* fp, VectorStr* test_names) {
  TestType float_specifiers[] = {{"f", "float", "ck_assert_float_eq"},
                                 {"lf", "double", "ck_assert_float_eq"},
                                 {"Lf", "long double", "ck_assert_float_eq"},
                                 {"e", "float", "ck_assert_float_eq"},
                                 {"E", "float", "ck_assert_float_eq"},
                                 {"le", "double", "ck_assert_float_eq"},
                                 {"lE", "double", "ck_assert_float_eq"},
                                 {"Le", "long double", "ck_assert_float_eq"},
                                 {"LE", "long double", "ck_assert_float_eq"},
                                 {"g", "float", "ck_assert_float_eq"},
                                 {"G", "float", "ck_assert_float_eq"},
                                 {"lg", "double", "ck_assert_float_eq"},
                                 {"lG", "double", "ck_assert_float_eq"},
                                 {"Lg", "long double", "ck_assert_float_eq"},
                                 {"LG", "long double", "ck_assert_float_eq"}};
  int float_spec_count = sizeof(float_specifiers) / sizeof(float_specifiers[0]);

  TestValue float_values[] = {
      {"0.0", "null"},
      {"-0.0", "null_neg"},
      {"0.1234567", "fraction_short"},
      {"0.123456789101112", "fraction_medium"},
      {"0.12356789101112131415", "fraction_long"},
      {"1234.567", "general_short"},
      {"1234.56789101112", "general_medium"},
      {"12345678.9101112131415", "general_long"},
      {"INFINITY", "infinity"},
      {"-INFINITY", "infinity_neg"},
  };
  int values_count = sizeof(float_values) / sizeof(float_values[0]);

  GenerateTestsEnumValues(fp, test_names, float_values, values_count,
                          float_specifiers, float_spec_count);

  fprintf(fp, "\n");
}

void GenerateDecIntegerTests(FILE* fp, VectorStr* test_names) {
  TestType dec_specifiers[] = {
      {"d", "int", "ck_assert_int_eq"},
      {"hd", "short", "ck_assert_int_eq"},
      {"ld", "long int", "ck_assert_int_eq"},
      {"i", "int", "ck_assert_int_eq"},
      {"hi", "short", "ck_assert_int_eq"},
      {"li", "long int", "ck_assert_int_eq"},
      {"u", "unsigned int", "ck_assert_uint_eq"},
      {"hu", "unsigned short", "ck_assert_uint_eq"},
      {"lu", "unsigned long int", "ck_assert_uint_eq"},
  };
  const int dec_spec_count = sizeof(dec_specifiers) / sizeof(dec_specifiers[0]);

  TestValue dec_values[] = {
      {"0", "null"},
      {"-0", "null_neg"},
      {"1", "int_short"},
      {"-1", "int_short_neg"},
      {"12345", "int_medium"},
      {"-12345", "int_medium_neg"},
      {"123456789", "int_long"},
      {"-123456789", "int_long_neg"},
  };
  const int dec_values_count = sizeof(dec_values) / sizeof(dec_values[0]);

  GenerateTestsEnumValues(fp, test_names, dec_values, dec_values_count,
                          dec_specifiers, dec_spec_count);

  fprintf(fp, "\n");
}

void GenerateOctIntegerTests(FILE* fp, VectorStr* test_names) {
  TestType oct_specifiers[] = {
      {"o", "unsigned int", "ck_assert_uint_eq"},
      {"ho", "unsigned short", "ck_assert_uint_eq"},
      {"lo", "unsigned long int", "ck_assert_uint_eq"},
  };
  const int oct_spec_count = sizeof(oct_specifiers) / sizeof(oct_specifiers[0]);

  TestValue oct_values[] = {
      {"0", "oct_null"},
      {"0755", "oct_medium"},
      {"01234567", "oct_long"},
  };
  const int oct_values_count = sizeof(oct_values) / sizeof(oct_values[0]);

  GenerateTestsEnumValues(fp, test_names, oct_values, oct_values_count,
                          oct_specifiers, oct_spec_count);

  fprintf(fp, "\n");
}

void GenerateHexIntegerTests(FILE* fp, VectorStr* test_names) {
  TestType hex_specifiers[] = {
      {"x", "unsigned int", "ck_assert_uint_eq"},
      {"X", "unsigned int", "ck_assert_uint_eq"},
      {"hx", "unsigned short", "ck_assert_uint_eq"},
      {"hX", "unsigned short", "ck_assert_uint_eq"},
      {"lx", "unsigned long int", "ck_assert_uint_eq"},
      {"lX", "unsigned long int", "ck_assert_uint_eq"},
  };
  const int hex_spec_count = sizeof(hex_specifiers) / sizeof(hex_specifiers[0]);

  TestValue hex_values[] = {
      {"0x0", "hex_null"},
      {"0x1a", "hex_short"},
      {"0XDEAA", "hex_medium"},
      {"123abc", "hex_no_prefix"},
      {"0x123456789ABCDEF", "hex_long"},
  };
  const int hex_values_count = sizeof(hex_values) / sizeof(hex_values[0]);

  GenerateTestsEnumValues(fp, test_names, hex_values, hex_values_count,
                          hex_specifiers, hex_spec_count);

  fprintf(fp, "\n");
}

void GeneratePointerTests(FILE* fp, VectorStr* test_names) {
  TestType ptr_specifier = {"p", "void*", "ck_assert_ptr_eq"};

  TestValue ptr_values[] = {
      {"0x0", "zero_ptr"},
      {"0x1234", "small_ptr"},
      {"0xdeadbeef", "medium_ptr"},
      {"0x7fff12345678", "large_ptr"},
  };
  const int ptr_values_count = sizeof(ptr_values) / sizeof(ptr_values[0]);

  GenerateTestsEnumValues(fp, test_names, ptr_values, ptr_values_count,
                          &ptr_specifier, 1);

  fprintf(fp, "\n");
}

void GenerateCharTests(FILE* fp, VectorStr* test_names) {
  TestType char_specifiers[] = {
      {"c", "char", "ck_assert_int_eq"},
  };
  const int char_spec_count =
      sizeof(char_specifiers) / sizeof(char_specifiers[0]);

  TestValue char_values[] = {
      {"a", "lowercase"}, {"Z", "uppercase"},        {"9", "digit"},
      {"@", "symbol"},    {"\\n", "newline"},        {"\\t", "tab"},
      {" ", "space"},     {"aaa", "multiple_chars"},
  };
  const int char_values_count = sizeof(char_values) / sizeof(char_values[0]);

  GenerateTestsEnumValues(fp, test_names, char_values, char_values_count,
                          char_specifiers, char_spec_count);

  fprintf(fp, "\n");
}

void GenerateStringTests(FILE* fp, VectorStr* test_names) {
  TestType string_specifiers[] = {
      {"s", "char*", "ck_assert_str_eq"},
  };
  const int string_spec_count =
      sizeof(string_specifiers) / sizeof(string_specifiers[0]);
  TestValue string_values[] = {
      {"hello", "basic"},
      {"hello world", "with_space"},
      {"12345", "digits"},
      {"a b c d e", "multiple_spaces"},
      {"  leading", "leading_spaces"},
      {"trailing  ", "trailing_spaces"},
      {"!@#$%^&*()", "symbols"},
      {"", "empty_string"},
      {"verylongstringverylongstringverylongstringverylongstring", "very_long"},
      {"        ", "only_spaces"},
  };
  const int string_values_count =
      sizeof(string_values) / sizeof(string_values[0]);
  static const TestFmtOpt widths[WIDTHS_COUNT] = {{"1023", "default_width"},
                                                  {"1", "small_width"},
                                                  {"5", "medium_width"},
                                                  {"70", "big_width"}};
  for (int spec_i = 0; spec_i < string_spec_count; ++spec_i) {
    TestType specifier = string_specifiers[spec_i];
    for (int width_i = 0; width_i < WIDTHS_COUNT; ++width_i) {
      TestFmtOpt width = widths[width_i];
      for (int val_i = 0; val_i < string_values_count; ++val_i) {
        TestValue value = string_values[val_i];
        char test_name[TEST_NAME_BUF_SIZE];
        sprintf(test_name, "%s_%s_%s", specifier.fmt, value.name, width.name);
        PushBackStr(test_names, test_name);
        fprintf(
            fp,
            "START_TEST(%s) {\n"
            "  char got_str[1024] = \"\";\n"
            "  char expected_str[1024] = \"\";\n"
            "  ck_assert_int_eq(s21_sscanf(\"%s\", \"%%%s%s\", got_str),\n"
            "                   sscanf(\"%s\", \"%%%s%s\", expected_str));\n"
            "  ck_assert_str_eq(got_str, expected_str);\n"
            "}\n"
            "END_TEST\n",
            test_name, value.repr, width.fmt, specifier.fmt, value.repr,
            width.fmt, specifier.fmt);
      }
    }
  }
}

void GenerateLStringTests(FILE* fp, VectorStr* test_names) {
  TestType string_specifiers[] = {
      {"ls", "wchar_t", "ck_assert_str_eq"},
  };
  const int string_spec_count =
      sizeof(string_specifiers) / sizeof(string_specifiers[0]);
  TestValue string_values[] = {
      {"hello", "basic"},
      {"hello world", "with_space"},
      {"12345", "digits"},
      {"a b c d e", "multiple_spaces"},
      {"  leading", "leading_spaces"},
      {"trailing  ", "trailing_spaces"},
      {"!@#$%^&*()", "symbols"},
      {"", "empty_string"},
      {"verylongstringverylongstringverylongstringverylongstring", "very_long"},
      {"        ", "only_spaces"},
  };
  const int string_values_count =
      sizeof(string_values) / sizeof(string_values[0]);
  static const TestFmtOpt widths[WIDTHS_COUNT] = {{"1023", "default_width"},
                                                  {"1", "small_width"},
                                                  {"5", "medium_width"},
                                                  {"70", "big_width"}};
  for (int spec_i = 0; spec_i < string_spec_count; ++spec_i) {
    TestType specifier = string_specifiers[spec_i];
    for (int width_i = 0; width_i < WIDTHS_COUNT; ++width_i) {
      TestFmtOpt width = widths[width_i];
      for (int val_i = 0; val_i < string_values_count; ++val_i) {
        TestValue value = string_values[val_i];
        char test_name[TEST_NAME_BUF_SIZE];
        sprintf(test_name, "%s_%s_%s", specifier.fmt, value.name, width.name);
        PushBackStr(test_names, test_name);
        fprintf(
            fp,
            "START_TEST(%s) {\n  %s got_wstr[1024] = L\"\";\n  %s "
            "expected_wstr[1024] = L\"\";\n"
            "  ck_assert_int_eq(s21_sscanf(\"%s\", \"%%%s%s\", got_wstr),\n"
            "                   sscanf(\"%s\", \"%%%s%s\", expected_wstr));\n"
            "  ck_assert(wcscmp(got_wstr, expected_wstr) == 0);\n"
            "}\nEND_TEST\n",
            test_name, specifier.type, specifier.type, value.repr, width.fmt,
            specifier.fmt, value.repr, width.fmt, specifier.fmt);
      }
    }
  }
  fprintf(fp, "\n");
}

void GenerateTestNumberInTheStart(FILE* fp, VectorStr* test_names) {
  TestType specifiers[] = {
      {"n", "int", "ck_assert_int_eq"},
      {"c", "char", "ck_assert_int_eq"},
      {"f", "float", "ck_assert_float_eq"},
      {"d", "int", "ck_assert_int_eq"},
  };
  const int specs_count = sizeof(specifiers) / sizeof(specifiers[0]);

  const char* test_name = "number_in_the_start";
  const char* str_val = "Sometest w 1.234 and a bit more 1234567";
  const char* str_fmt = "%n Sometest %c %f and a bit more %d";

  GenerateIntegrationTest(fp, test_names, test_name, str_val, str_fmt,
                          specifiers, specs_count);
}

void GenerateTestNumberInTheMiddle(FILE* fp, VectorStr* test_names) {
  TestType specifiers[] = {
      {"c", "char", "ck_assert_int_eq"},
      {"f", "float", "ck_assert_float_eq"},
      {"n", "int", "ck_assert_int_eq"},
      {"d", "int", "ck_assert_int_eq"},
  };
  const int specs_count = sizeof(specifiers) / sizeof(specifiers[0]);

  const char* test_name = "number_in_the_middle";
  const char* str_val = "Sometest w 1.234 and a bit more 1234567";
  const char* str_fmt = "Sometest %c %f %n and a bit more %d";

  GenerateIntegrationTest(fp, test_names, test_name, str_val, str_fmt,
                          specifiers, specs_count);
}

void GenerateTestNumberInTheEnd(FILE* fp, VectorStr* test_names) {
  TestType specifiers[] = {
      {"c", "char", "ck_assert_int_eq"},
      {"f", "float", "ck_assert_float_eq"},
      {"d", "int", "ck_assert_int_eq"},
      {"n", "int", "ck_assert_int_eq"},
  };
  const int specs_count = sizeof(specifiers) / sizeof(specifiers[0]);

  const char* test_name = "number_in_the_end";
  const char* str_val = "Sometest w 1.234 and a bit more 1234567";
  const char* str_fmt = "Sometest %c %f and a bit more %d %n";

  GenerateIntegrationTest(fp, test_names, test_name, str_val, str_fmt,
                          specifiers, specs_count);
}

void GenerateNumberTests(FILE* fp, VectorStr* test_names) {
  GenerateTestNumberInTheStart(fp, test_names);
  GenerateTestNumberInTheMiddle(fp, test_names);
  GenerateTestNumberInTheEnd(fp, test_names);
  fprintf(fp, "\n");
}

void GenerateIntegrationTestPercentInTheMiddle(FILE* fp,
                                               VectorStr* test_names) {
  TestType specifiers[] = {
      {"i", "int", "ck_assert_int_eq"},
      {"g", "float", "ck_assert_float_eq"},
      {"o", "int", "ck_assert_int_eq"},
  };
  const int specs_count = sizeof(specifiers) / sizeof(specifiers[0]);

  const char* test_name = "percent_in_the_middle";
  const char* str_val = "   -123 % 1.234e-1 texttextetext 1234567";
  const char* str_fmt = "  %i %% %g texttextetext %d";

  GenerateIntegrationTest(fp, test_names, test_name, str_val, str_fmt,
                          specifiers, specs_count);
}

void GenerateIntegrationTestPercentScan(FILE* fp, VectorStr* test_names) {
  TestType specifiers[] = {
      {"c", "char", "ck_assert_int_eq"},
  };
  const int specs_count = sizeof(specifiers) / sizeof(specifiers[0]);

  const char* test_name = "percent_scan";
  const char* str_val = "%%";
  const char* str_fmt = "%% %c";

  GenerateIntegrationTest(fp, test_names, test_name, str_val, str_fmt,
                          specifiers, specs_count);
}

void GeneratePercentTests(FILE* fp, VectorStr* test_names) {
  GenerateIntegrationTestPercentInTheMiddle(fp, test_names);
  GenerateIntegrationTestPercentScan(fp, test_names);
  fprintf(fp, "\n");
}

void GenerateIntegrationTestStar(FILE* fp, VectorStr* test_names) {
  TestType specifiers[] = {
      {"d", "int", "ck_assert_int_eq"},
      {"d", "int", "ck_assert_int_eq"},
  };
  const int specs_count = sizeof(specifiers) / sizeof(specifiers[0]);

  const char* test_name = "star";
  const char* str_val = "123 ignore 456";
  const char* str_fmt = "%d %*s %d";

  GenerateIntegrationTest(fp, test_names, test_name, str_val, str_fmt,
                          specifiers, specs_count);
}

void GenerateErrorTests(FILE* fp, VectorStr* test_names) {
  const char* test_name = "wrong_specif";
  const char* str_val = "a";
  const char* str_fmt = "a %r";
  PushBackStr(test_names, test_name);
  fprintf(fp,
          "START_TEST(%s) {\n"
          "  char got_str[1024] = \"\";\n"
          "  ck_assert_int_eq(s21_sscanf(\"%s\", \"%s\", got_str),\n"
          "                   -1);\n"
          "}\n"
          "END_TEST\n",
          test_name, str_val, str_fmt);
  fprintf(fp, "\n");
}

void GenerateIntegrationLotsOfSpecifs(FILE* fp, VectorStr* test_names) {
  TestType specifiers[] = {
      {"c", "char", "ck_assert_int_eq"},
      {"hd", "short", "ck_assert_int_eq"},
      {"ld", "long", "ck_assert_int_eq"},
      {"i", "int", "ck_assert_int_eq"},
      {"e", "float", "ck_assert_float_eq"},
      {"E", "float", "ck_assert_float_eq"},
      {"f", "float", "ck_assert_float_eq"},
      {"g", "float", "ck_assert_float_eq"},
      {"Le", "long double", "ck_assert_float_eq"},
      {"o", "unsigned int", "ck_assert_uint_eq"},
      {"u", "unsigned int", "ck_assert_uint_eq"},
      {"x", "unsigned int", "ck_assert_uint_eq"},
      {"X", "unsigned int", "ck_assert_uint_eq"},
      {"c", "char", "ck_assert_int_eq"},
      {"n", "int", "ck_assert_int_eq"},
  };
  const int specs_count = sizeof(specifiers) / sizeof(specifiers[0]);

  const char* test_name = "sscanf_all_specifiers";
  const char* str_val =
      "A -12345 987654321 0x1a3 1.2345e6 1.2345E6 3.14159 6.022e23 "
      "3.141592653589793238 755 4294967295 1a3b 1A3B W %";

  const char* str_fmt = "%c %hd %ld %i %e %E %f %g %Le %o %u %x %X %c %% %n";

  GenerateIntegrationTest(fp, test_names, test_name, str_val, str_fmt,
                          specifiers, specs_count);
}

void AddTestsToSuite(FILE* fp, const VectorStr* test_names) {
  int size = SizeOfVectorStr(test_names);
  for (int i = 0; i < size; ++i) {
    fprintf(fp, "  tcase_add_test(tcase_core, %s);\n", GetAtStr(test_names, i));
  }
  fprintf(fp, "\n");
}

int main() {
  FILE* fp = fopen(FILE_NAME, "w");
  fprintf(fp, "%s\n", HEADER);
  VectorStr* test_names = NewVectorStr();
  GenerateFloatTests(fp, test_names);
  GenerateDecIntegerTests(fp, test_names);
  GenerateOctIntegerTests(fp, test_names);
  GenerateHexIntegerTests(fp, test_names);
  GeneratePointerTests(fp, test_names);
  GenerateCharTests(fp, test_names);
  GenerateStringTests(fp, test_names);
  GenerateLStringTests(fp, test_names);
  GenerateNumberTests(fp, test_names);
  GeneratePercentTests(fp, test_names);
  GenerateIntegrationTestStar(fp, test_names);
  GenerateErrorTests(fp, test_names);
  GenerateIntegrationLotsOfSpecifs(fp, test_names);
  fprintf(fp, SUITE_START);
  AddTestsToSuite(fp, test_names);
  fprintf(fp, SUITE_END);

  DeleteVectorStr(test_names);
  fclose(fp);
  return 0;
}
