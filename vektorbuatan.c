#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char ID[10];
    char nama[30];
    char jenisDagangan[30];
    float omzetPerHari;
} Pedagang;

typedef struct {
    Pedagang *_arr;
    unsigned _size, _capacity;
} VectorBuatan;

void vector_init(VectorBuatan *vec) {
    vec->_capacity = 2u;
    vec->_size = 0u;
    vec->_arr = (Pedagang *)malloc(sizeof(Pedagang) * vec->_capacity);
}

bool vector_isEmpty(VectorBuatan *vec) {
    return vec->_size == 0;
}

void vector_pushBack(VectorBuatan *vec, Pedagang val) {
    if (vec->_size >= vec->_capacity) {
        vec->_capacity *= 2;
        vec->_arr = (Pedagang *)realloc(vec->_arr, sizeof(Pedagang) * vec->_capacity);
    }
    vec->_arr[vec->_size++] = val;
}

void vector_deleteAt(VectorBuatan *vec, unsigned index) {
    if (index >= vec->_size) return;
    for (unsigned i = index; i < vec->_size - 1; ++i) {
        vec->_arr[i] = vec->_arr[i + 1];
    }
    vec->_size--;
}

void vector_free(VectorBuatan *vec) {
    free(vec->_arr);
    vec->_arr = NULL;
    vec->_size = 0;
    vec->_capacity = 0;
}


