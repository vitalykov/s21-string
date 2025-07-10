#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "vector_str/vector_str.h"

#define HEADER \
  "\
#include <stdio.h>\n\
#include <wctype.h>\n\
#include <math.h>\n\
\n\
#include \"s21_string.h\"\n\
#include \"tests/test.h\"\n\
\n\
#define RUN_TEST(fmt, ...)                                     \\\n\
  char got_str[1000];                                          \\\n\
  char expected_str[1000];                                     \\\n\
  const char* format = fmt;                                    \\\n\
  int chars_count_s21 = s21_sprintf(got_str, format, ##__VA_ARGS__); \\\n\
  int chars_count_std = sprintf(expected_str, format, ##__VA_ARGS__); \\\n\
  ck_assert_str_eq(got_str, expected_str);                     \\\n\
  ck_assert_int_eq(chars_count_s21, chars_count_std);          \n\
"

#define SUITE_START \
  "\
Suite* suite_s21_sprintf(void) { \n\
  Suite* suite = suite_create(\"s21_sprintf\"); \n\
  TCase* tcase_core = tcase_create(\"core\"); \n\
\n\
"

#define SUITE_END \
  "\
  suite_add_tcase(suite, tcase_core); \n\
  return suite; \n\
} \n\
"

struct TestValue {
  const char* repr;
  const char* name;
};
typedef struct TestValue TestValue;

struct TestFmtOpt {
  const char* format;
  const char* name;
};
typedef struct TestFmtOpt TestFmtOpt;

struct TestType {
  const char* format;
  const char* name;
  const char* suffix;
};
typedef struct TestType TestType;

#define MAX_TEST_NAME_LEN 200

void GenerateFlagsTests(FILE* fp, VectorStr* test_names,
                        const TestType specifiers[], size_t spec_count,
                        const TestValue values[], size_t values_count) {
  static const TestFmtOpt flags[] = {
      {"", "no_flags"},        {"+", "prefix_sign"},    {" ", "prefix_space"},
      {"-", "left_alignment"}, {"0", "leading_zeroes"}, {"#", "alt_format"}};

  size_t flags_count = sizeof(flags) / sizeof(flags[0]);

  for (size_t flag_i = 0; flag_i < flags_count; ++flag_i) {
    TestFmtOpt flag = flags[flag_i];
    for (size_t spec_i = 0; spec_i < spec_count; ++spec_i) {
      TestType specifier = specifiers[spec_i];
      for (size_t val_i = 0; val_i < values_count; ++val_i) {
        TestValue value = values[val_i];
        char test_name[MAX_TEST_NAME_LEN];
        sprintf(test_name, "%s_%s_%s", specifier.name, value.name, flag.name);
        PushBackStr(test_names, test_name);
        fprintf(fp, "START_TEST(%s) ", test_name);
        fprintf(fp, "{RUN_TEST(\"%%%s%s\", %s%s)} END_TEST\n", flag.format,
                specifier.format, value.repr, specifier.suffix);
      }
    }
  }
}

void GenerateWidthPrecisionTests(FILE* fp, VectorStr* test_names,
                                 const TestType specifiers[], size_t spec_count,
                                 const TestValue values[],
                                 size_t values_count) {
  static const TestFmtOpt widths[] = {
      {"", "no_width"}, {"1", "small_width"}, {"50", "big_width"}};
  static const TestFmtOpt precisions[] = {{"", "no_precision"},
                                          {".3", "small_precision"},
                                          {".14", "big_precision"}};

  size_t widths_count = sizeof(widths) / sizeof(widths[0]);
  size_t precisions_count = sizeof(precisions) / sizeof(precisions[0]);

  for (size_t width_i = 0; width_i < widths_count; ++width_i) {
    TestFmtOpt width = widths[width_i];
    for (size_t prec_i = 0; prec_i < precisions_count; ++prec_i) {
      TestFmtOpt precision = precisions[prec_i];
      for (size_t spec_i = 0; spec_i < spec_count; ++spec_i) {
        TestType specifier = specifiers[spec_i];
        for (size_t val_i = 0; val_i < values_count; ++val_i) {
          TestValue value = values[val_i];
          char test_name[MAX_TEST_NAME_LEN];
          sprintf(test_name, "%s_%s_%s_%s", specifier.name, value.name,
                  width.name, precision.name);
          PushBackStr(test_names, test_name);
          fprintf(fp, "START_TEST(%s) ", test_name);
          fprintf(fp, "{RUN_TEST(\"%%%s%s%s\", %s%s)} END_TEST\n", width.format,
                  precision.format, specifier.format, value.repr,
                  specifier.suffix);
        }
      }
    }
  }
}

void GenerateTests(FILE* fp, VectorStr* test_names, const TestType specifiers[],
                   int spec_count, const TestValue values[], int values_count) {
  GenerateFlagsTests(fp, test_names, specifiers, spec_count, values,
                     values_count);
  GenerateWidthPrecisionTests(fp, test_names, specifiers, spec_count, values,
                              values_count);
  fprintf(fp, "\n");
}

#define GENERATE_TESTS(specifiers, values)                        \
  size_t spec_count = sizeof(specifiers) / sizeof(specifiers[0]); \
  size_t values_count = sizeof(values) / sizeof(values[0]);       \
  GenerateTests(fp, test_names, specifiers, spec_count, values, values_count);

void GenerateFloatTests(FILE* fp, VectorStr* test_names) {
  TestType float_specifiers[] = {{"f", "float", "f"},
                                 {"e", "float_exp", "f"},
                                 {"E", "float_EXP", "f"},
                                 {"g", "float_g", "f"},
                                 {"G", "float_G", "f"}};
  TestValue float_values[] = {
      {"0.0", "null"},
      {"-0.0", "null_neg"},
      {"0.1234567", "fraction_short"},
      {"1234.567", "general_short"},
  };
  GENERATE_TESTS(float_specifiers, float_values);
}

void GenerateDoubleTests(FILE* fp, VectorStr* test_names) {
  TestType double_specifiers[] = {{"lf", "double", ""},
                                  {"le", "double_exp", ""},
                                  {"lE", "double_EXP", ""},
                                  {"lg", "double_g", ""},
                                  {"lG", "double_G", ""}};
  TestValue double_values[] = {{"0.0", "null"},
                               {"-0.0", "null_neg"},
                               {"0.123456789101112", "fraction_medium"},
                               {"1234.56789101112", "general_medium"}};
  GENERATE_TESTS(double_specifiers, double_values);
}

void GenerateLongDoubleTests(FILE* fp, VectorStr* test_names) {
  TestType long_double_specifiers[] = {{"Lf", "long_double", "L"},
                                       {"Le", "long_double_exp", "L"},
                                       {"LE", "long_double_EXP", "L"},
                                       {"Lg", "long_double_g", "L"},
                                       {"LG", "long_double_G", "L"}};
  TestValue long_double_values[] = {{"0.0", "null"},
                                    {"-0.0", "null_neg"},
                                    {"0.12356789101112131415", "fraction_long"},
                                    {"12345678.9101112131415", "general_long"}};
  GENERATE_TESTS(long_double_specifiers, long_double_values);
}

void GenerateFloatSpecialTests(FILE* fp, VectorStr* test_names) {
  TestType special_specifiers[] = {{"f", "float", ""},
                                   {"lf", "double", ""},
                                   {"Lf", "long_double", ""},
                                   {"e", "float_exp", ""},
                                   {"le", "double_exp", ""},
                                   {"Le", "long_double_exp", ""},
                                   {"E", "float_EXP", ""},
                                   {"lE", "double_EXP", ""},
                                   {"LE", "long_double_EXP", ""},
                                   {"g", "float_g", ""},
                                   {"lg", "double_g", ""},
                                   {"Lg", "long_double_g", ""},
                                   {"G", "float_G", ""},
                                   {"lG", "double_G", ""},
                                   {"LG", "long_double_G", ""}};
  TestValue special_values[] = {{"NAN", "nan"},
                                {"-NAN", "nan_neg"},
                                {"INFINITY", "infinity"},
                                {"-INFINITY", "infinity_neg"}};
  GENERATE_TESTS(special_specifiers, special_values);
}

void GenerateShortIntTests(FILE* fp, VectorStr* test_names) {
  TestType int_specifiers[] = {{"hd", "short", ""}};
  TestValue int_values[] = {{"(short)0", "null"},
                            {"(short)8192", "general_short"},
                            {"(short)-8192", "general_short_neg"},
                            {"(short)2000000001", "general_medium"},
                            {"(short)-2000000001", "general_medium_neg"}};
  GENERATE_TESTS(int_specifiers, int_values);
}

void GenerateUnsingedShortIntTests(FILE* fp, VectorStr* test_names) {
  TestType int_specifiers[] = {
      {"hu", "unsigned_short", "u"},
      {"hx", "short_hex", "u"},
      {"hX", "SHORT_HEX", "u"},
      {"ho", "short_oct", "u"},
  };
  TestValue int_values[] = {
      {"(unsigned short)0", "null"},
      {"(unsigned short)8192", "general_short"},
      {"(unsigned short)-8192", "general_short_neg"},
      {"(unsigned short)2000000001", "general_medium"},
      {"(unsigned short)-2000000001", "general_medium_neg"}};
  GENERATE_TESTS(int_specifiers, int_values);
}

void GenerateIntTests(FILE* fp, VectorStr* test_names) {
  TestType int_specifiers[] = {
      {"d", "int", ""},  {"i", "alt_int", ""}, {"u", "unsigned", "u"},
      {"x", "hex", "u"}, {"X", "HEX", "u"},    {"o", "oct", "u"},
  };
  TestValue int_values[] = {{"0", "null"},
                            {"8192", "general_short"},
                            {"-8192", "general_short_neg"},
                            {"2000000001", "general_medium"},
                            {"-2000000001", "general_medium_neg"}};
  GENERATE_TESTS(int_specifiers, int_values);
}

void GenerateLongIntTests(FILE* fp, VectorStr* test_names) {
  TestType long_specifiers[] = {{"ld", "long", "l"},
                                {"lu", "unsigned_long", "lu"},
                                {"lx", "long_hex", "l"},
                                {"lX", "LONG_HEX", "l"},
                                {"lo", "long_oct", "l"}};
  TestValue long_values[] = {{"0", "null"},
                             {"8192", "general_short"},
                             {"-8192", "general_short_neg"},
                             {"9223372036854775000", "general_long"},
                             {"-9223372036854775000", "general_long_neg"}};
  GENERATE_TESTS(long_specifiers, long_values);
}

void GenerateCharsTests(FILE* fp, VectorStr* test_names) {
  TestType chars_specifiers[] = {{"c", "char", ""}};
  TestValue chars_values[] = {
      {"'\\0'", "null"}, {"'a'", "general"}, {"'\\250'", "out_of_bounds"}};
  GENERATE_TESTS(chars_specifiers, chars_values);
}

void GenerateLongCharsTests(FILE* fp, VectorStr* test_names) {
  TestType long_chars_specifiers[] = {{"lc", "long_char", ""}};
  TestValue long_chars_values[] = {{"(wint_t)'\\0'", "null"},
                                   {"(wint_t)'a'", "general"}};
  GENERATE_TESTS(long_chars_specifiers, long_chars_values);
}

void GenerateStringTests(FILE* fp, VectorStr* test_names) {
  TestType string_specifiers[] = {{"s", "string", ""}};
  TestValue string_values[] = {
      {"\"\"", "empty"},
      {"\"a\"", "len_one"},
      {"\"hello\"", "general"},
  };
  GENERATE_TESTS(string_specifiers, string_values);
}

void GenerateLongStringTests(FILE* fp, VectorStr* test_names) {
  TestType long_string_specifiers[] = {{"ls", "long_string", ""}};
  TestValue long_string_values[] = {
      {"L\"\"", "empty"},
      {"L\"a\"", "len_one"},
      {"L\"hello\"", "general"},
  };
  GENERATE_TESTS(long_string_specifiers, long_string_values);
}

void GeneratePointerTests(FILE* fp, VectorStr* test_names) {
  TestType pointer_specifiers[] = {{"p", "pointer", ""}};
  TestValue pointer_values[] = {{"S21_NULL", "null"}, {"format", "format_ptr"}};
  GENERATE_TESTS(pointer_specifiers, pointer_values);
}

struct TestArbitraryFmtOpt {
  const char* format;
  const char* value;
  const char* name;
};
typedef struct TestArbitraryFmtOpt TestArbitraryFmtOpt;

void GenerateArbitraryWidthPrecisionTests(FILE* fp, VectorStr* test_names) {
  TestArbitraryFmtOpt widths[] = {{"", "", "no_width"},
                                  {"*", "1, ", "small_width"},
                                  {"*", "20, ", "big_width"}};
  TestArbitraryFmtOpt precisions[] = {{"", "", "no_precision"},
                                      {".*", "2, ", "small_precision"},
                                      {".*", "14, ", "big_precision"}};
  size_t widths_count = sizeof(widths) / sizeof(widths[0]);
  size_t prec_count = sizeof(precisions) / sizeof(precisions[0]);

  for (size_t width_i = 0; width_i < widths_count; ++width_i) {
    TestArbitraryFmtOpt width = widths[width_i];
    for (size_t prec_i = 0; prec_i < prec_count; ++prec_i) {
      TestArbitraryFmtOpt precision = precisions[prec_i];
      char test_name[MAX_TEST_NAME_LEN];
      sprintf(test_name, "arbitrary_%s_%s", width.name, precision.name);
      PushBackStr(test_names, test_name);
      fprintf(fp, "START_TEST(%s) ", test_name);
      fprintf(fp, "{RUN_TEST(\"%%%s%s%s\", %s%s%s)} END_TEST\n", width.format,
              precision.format, "lf", width.value, precision.value,
              "20.123124432423");
    }
  }
}

void GenerateMultipleFormatTests(FILE* fp, VectorStr* test_names) {
  const char* fmt =
      "\"|%+15ld|%0.5u|%10.20lx|%-020lX|%#20o|%25p|"
      "%f|%+20.5Le|%+015.10lE|%#-10.0lg|%G|%c|%.3s|%%|\"";
  const char* values =
      "96485L, 3243U, -12312312L, 0L, 256, S21_NULL, 3.1415, 6.02214076E23L, "
      "6.62607015e-34, 1048576.0, 0.001, 'M', L\"Good\"";
  PushBackStr(test_names, "multiple_formats");
  fprintf(fp, "START_TEST(%s) ", "multiple_formats");
  fprintf(fp, "{RUN_TEST(%s, %s)} END_TEST\n", fmt, values);
}

void GenerateErrorTests(FILE* fp, VectorStr* test_names) {
  TestFmtOpt formats[] = {{"%", "empty_format"},
                          {"%l", "no_specifier_short"},
                          {"%+-#20.5h", "no_specifier_long"},
                          {"%lr", "invalid_specifier_short"},
                          {"%+-#20.5lr", "invalid_specifier_long"}};

  size_t fmt_count = sizeof(formats) / sizeof(formats[0]);
  for (size_t i = 0; i < fmt_count; ++i) {
    TestFmtOpt format = formats[i];
    PushBackStr(test_names, format.name);
    fprintf(fp, "START_TEST(%s) {\n", format.name);
    fprintf(fp, "  char str[100];\n");
    fprintf(fp, "  ck_assert_int_eq(s21_sprintf(str, \"%s\", 123), -1);\n",
            format.format);
    fprintf(fp, "} END_TEST\n");
  }
}

void AddTestsToSuite(FILE* fp, const VectorStr* test_names) {
  int size = SizeOfVectorStr(test_names);
  for (int i = 0; i < size; ++i) {
    fprintf(fp, "  tcase_add_test(tcase_core, %s);\n", GetAtStr(test_names, i));
  }
  fprintf(fp, "\n");
}

int main(int argc, char** argv) {
  bool ok = true;
  if (argc != 2) {
    ok = false;
    fprintf(stderr, "Incorrect usage. Try: %s test_s21_function.c", argv[0]);
  }

  if (ok) {
    const char* filename = argv[1];
    FILE* fp = fopen(filename, "w");

    if (fp != NULL) {
      fprintf(fp, "%s\n", HEADER);
      VectorStr* test_names = NewVectorStr();

      GenerateFloatTests(fp, test_names);
      GenerateDoubleTests(fp, test_names);
      GenerateLongDoubleTests(fp, test_names);
      GenerateFloatSpecialTests(fp, test_names);

      GenerateShortIntTests(fp, test_names);
      GenerateUnsingedShortIntTests(fp, test_names);
      GenerateIntTests(fp, test_names);
      GenerateLongIntTests(fp, test_names);
      GeneratePointerTests(fp, test_names);

      GenerateCharsTests(fp, test_names);
      GenerateLongCharsTests(fp, test_names);
      GenerateStringTests(fp, test_names);
      GenerateLongStringTests(fp, test_names);

      GenerateArbitraryWidthPrecisionTests(fp, test_names);
      GenerateMultipleFormatTests(fp, test_names);
      GenerateErrorTests(fp, test_names);

      fprintf(fp, SUITE_START);
      AddTestsToSuite(fp, test_names);
      fprintf(fp, SUITE_END);

      fclose(fp);
      DeleteVectorStr(test_names);
    } else {
      fprintf(stderr, "No such file: %s\n", filename);
    }
  }

  return 0;
}
