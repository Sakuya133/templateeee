#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char NRP[11];
    char name[30];
    int gender;    
    float IPK;
} Mahasiswa;

typedef struct {
    Mahasiswa *_arr;
    unsigned _size, _capacity;
} VectorBuatan;


void vector_init(VectorBuatan *vec) {
    vec->_capacity = 2u;
    vec->_size = 0u;
    vec->_arr = (Mahasiswa *)malloc(sizeof(Mahasiswa) * vec->_capacity);
}


bool vector_isEmpty(VectorBuatan *vec) {
    return vec->_size == 0;
}


void vector_pushBack(VectorBuatan *vec, Mahasiswa val) {
    if (vec->_size >= vec->_capacity) {
        vec->_capacity *= 2;
        vec->_arr = (Mahasiswa *)realloc(vec->_arr, sizeof(Mahasiswa) * vec->_capacity);
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


