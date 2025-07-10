#ifndef S21_STRING_VECTOR_STR_VECTOR_STR_H_
#define S21_STRING_VECTOR_STR_VECTOR_STR_H_

struct VectorStr {
  char** data;
  int size;
  int capacity;
};
typedef struct VectorStr VectorStr;

VectorStr* NewVectorStr(void);
void DeleteVectorStr(VectorStr* vec);
int SizeOfVectorStr(const VectorStr* vec);
void PushBackStr(VectorStr* vec, const char* str);
char* GetAtStr(const VectorStr* vec, int i);

#endif  // S21_STRING_VECTOR_STR_VECTOR_STR_H_