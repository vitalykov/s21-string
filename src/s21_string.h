#ifndef S21_STRING_S21_STRING_H_
#define S21_STRING_S21_STRING_H_

#define S21_NULL ((void*)0)
typedef unsigned long s21_size_t;

void* s21_memchr(const void* str, int c, s21_size_t n);
int s21_memcmp(const void* str1, const void* str2, s21_size_t n);

__attribute__((__nonnull__(1, 2))) void* s21_memcpy(void* dest, const void* src,
                                                    s21_size_t n);

__attribute__((__nonnull__(1))) void* s21_memset(void* str, int c,
                                                 s21_size_t n);

char* s21_strncat(char* dest, const char* src, s21_size_t n);
char* s21_strchr(const char* str, int c);
int s21_strncmp(const char* str1, const char* str2, s21_size_t n);

__attribute__((__nonnull__(1, 2))) char* s21_strncpy(char* dest,
                                                     const char* src,
                                                     s21_size_t n);

s21_size_t s21_strcspn(const char* str1, const char* str2);
char* s21_strerror(int errnum);
s21_size_t s21_strlen(const char* str);
char* s21_strpbrk(const char* str1, const char* str2);
char* s21_strrchr(const char* str, int c);
char* s21_strstr(const char* haystack, const char* needle);

__attribute__((__nonnull__(2))) char* s21_strtok(char* str, const char* delim);

int s21_sscanf(const char* str, const char* format, ...);
int s21_sprintf(char* str, const char* format, ...);

void* s21_to_upper(const char* str);
void* s21_to_lower(const char* str);
void* s21_insert(const char* src, const char* str, s21_size_t start_index);
void* s21_trim(const char* src, const char* trim_chars);

char* s21_strcpy(char* destination, const char* source);
__attribute__((__nonnull__(1, 2))) int s21_strncasecmp(const char* str1,
                                                       const char* str2,
                                                       s21_size_t n);

#endif  // S21_STRING_S21_STRING_H_
