CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -I. #$(shell pkg-config --cflags check) # CHANGED FOR IOS REMOVE AFTER
GCOV_FLAG=--coverage
CHECK_LIB_FLAGS=$(shell pkg-config --cflags --libs check)

SRC_DIR=.
TEST_DIR=tests

S21_STRING_SRC=$(shell find $(SRC_DIR) -name "s21_*.c") $(shell find $(SRC_DIR)/s21_sprintf -name "*.c") $(shell find $(SRC_DIR)/s21_strlib -name "*.c")
S21_STRING_OBJ=$(S21_STRING_SRC:.c=.o)
S21_STRING_LIB=s21_string.a

VECTOR_STR_OBJ=$(SRC_DIR)/vector_str/vector_str.o

TEST_SRC=$(shell find $(TEST_DIR) -type f -name "test*.c")
SPRINTF_TEST_GEN_OBJ=$(TEST_DIR)/sprintf_test_gen.o
SPRINTF_TEST_GEN_EXEC=$(TEST_DIR)/sprintf_test_gen
SPRINTF_TEST_SRC=$(TEST_DIR)/test_s21_sprintf.c

SSCANF_TEST_GEN_OBJ=$(TEST_DIR)/sscanf_test_gen.o
SSCANF_TEST_GEN_EXEC=$(TEST_DIR)/sscanf_test_gen
SSCANF_TEST_SRC=$(TEST_DIR)/test_s21_sscanf.c

TEST_OBJ=$(TEST_SRC:.c=.o) $(SPRINTF_TEST_SRC:.c=.o) $(SSCANF_TEST_SRC:.c=.o)
TEST_EXEC=test

GCOV_DIR=gcov
GCOV_TEST_EXEC=$(addprefix $(GCOV_DIR)/,coverage)
GCOV_COVERAGE_INFO=$(addprefix $(GCOV_DIR)/,full_coverage.info)
GCOV_S21_STRING_INFO=$(addprefix $(GCOV_DIR)/,s21_string_coverage.info)
GCOV_HTML_DIR=html_report

.PHONY: all

all: $(S21_STRING_LIB)

$(SPRINTF_TEST_GEN_EXEC): $(SPRINTF_TEST_GEN_OBJ) $(VECTOR_STR_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(SPRINTF_TEST_SRC): $(SPRINTF_TEST_GEN_EXEC)
	./$^ $@
	clang-format -i $@

$(SSCANF_TEST_GEN_EXEC): $(SSCANF_TEST_GEN_OBJ) $(VECTOR_STR_OBJ)
	$(CC) $(CFLAGS) $^ -o $@

$(SSCANF_TEST_SRC): $(SSCANF_TEST_GEN_EXEC)
	./$^ $@
	clang-format -i $@

.PHONY: test

test: $(TEST_EXEC)

$(TEST_EXEC): $(TEST_OBJ) $(S21_STRING_LIB)
	$(CC) $(CFLAGS) -o $@ $^ $(CHECK_LIB_FLAGS)

.PHONY: s21_string.a

$(S21_STRING_LIB): $(S21_STRING_OBJ)
	ar rc $@ $^

.PHONY: gcov_report

gcov_report: $(S21_STRING_SRC) $(TEST_SRC)
	mkdir -p $(GCOV_DIR)
	$(CC) $(CFLAGS) $(GCOV_FLAG) -o $(GCOV_TEST_EXEC) $^ $(CHECK_LIB_FLAGS)
	./$(GCOV_TEST_EXEC)
	lcov -t "$(GCOV_TEST_EXEC)" -o $(GCOV_COVERAGE_INFO) -c -d . 
	lcov --extract $(GCOV_COVERAGE_INFO) "*/s21_*.c" -o $(GCOV_S21_STRING_INFO)
	genhtml $(GCOV_S21_STRING_INFO) -o $(GCOV_HTML_DIR)

$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $(CHECK_LIB_FLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: rebuild

rebuild: clean all

.PHONY: clean

clean: 
	rm -f $(S21_STRING_OBJ) $(TEST_OBJ) $(TEST_EXEC) $(SPRINTF_TEST_GEN_OBJ) $(SPRINTF_TEST_GEN_EXEC) $(SSCANF_TEST_GEN_OBJ) $(SSCANF_TEST_GEN_EXEC) $(S21_STRING_LIB) $(VECTOR_STR_OBJ)
	rm -rf $(GCOV_DIR) $(GCOV_HTML_DIR)

.PHONY: clang-format

clang-format:
	find . -type f -name "*.[ch]" -exec clang-format -i {} +

.PHONY: cppcheck

cppcheck:
	cppcheck . --enable=all --std=c11 -I . --suppress=missingIncludeSystem
