#include "vector_str/vector_str.h"

#include <stdlib.h>
#include <string.h>

#define INIT_CAPACITY 8

VectorStr* NewVectorStr(void) {
  VectorStr* vec = malloc(sizeof(VectorStr));
  if (vec != NULL) {
    vec->data = malloc(INIT_CAPACITY * sizeof(char*));
    vec->size = 0;
    vec->capacity = INIT_CAPACITY;

    if (vec->data == NULL) {
      free(vec);
      vec = NULL;
    }
  }
  return vec;
}

void DeleteVectorStr(VectorStr* vec) {
  for (int i = 0; i < vec->size; ++i) {
    free(vec->data[i]);
  }
  free(vec->data);
  free(vec);
}

int SizeOfVectorStr(const VectorStr* vec) { return vec->size; }

void PushBackStr(VectorStr* vec, const char* str) {
  int size = vec->size;
  int capacity = vec->capacity;

  if (size == capacity) {
    vec->data = realloc(vec->data, 2 * capacity * sizeof(char*));
    vec->capacity *= 2;
  }

  vec->data[size] = malloc((strlen(str) + 1) * sizeof(char));
  strcpy(vec->data[size], str);
  vec->size += 1;
}

char* GetAtStr(const VectorStr* vec, int i) { return vec->data[i]; }