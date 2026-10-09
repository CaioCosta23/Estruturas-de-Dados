#include <stdio.h>
#include <stdlib.h>

#include "../include/vector.h"

#define SIZE_ALLOCATED 50

#define SMALL -1
#define EQUAL 0
#define BIG 1

typedef short int (*fptr)(dataType*, dataType*);

struct Vector{
    dataType *data;
    unsigned int size, allocated;
    fptr compare;
};

/**
 * @brief Realloc memory for a vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 */
static void vectorRealocation(Vector *vector) {
    vector->allocated *= 2;

    vector->data = (dataType*)realloc(vector->data, vector->allocated * sizeof(dataType));

    if (vector->data == NULL) {
        printf("Erro! Realocacao de memoria de vetor da estrutura de vetor mal-sucedida.\n");
        vectorDestroy(vector);
        exit(1);
    }
}

/**
 * @brief Get the Relevant Value object
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 * @param characteristic Characteristic of element to be compare and search;
 * @return int Element relevant (biggest or smallest) in the vector;
 */
static dataType getRelevantValue(Vector *vector, short int characteristicSearch) {
    unsigned int d;
    dataType marker;

    for(d = 0; d < vector->size; d++)
        if (compare(vector->data[d], vector->data[d + 1]) == characteristicSearch)
            marker = vector->data[d];
    
    return marker;
}

static unsigned int findIndex(Vector *vector, dataType (getElement)(Vector*)) {
    unsigned int d;

    for(d = 0; d < vector->size; d++) {
        if (vector->compare(vector->data[d], getElement(vector)) == 0)
            return d;
    }
}


Vector *vectorConstruct() {
    Vector *vector = NULL;

    vector = (Vector*)malloc(sizeof(struct Vector));

    if (vector == NULL) {
        printf("Erro! Alocacao de memoria de estrutura de vetor mal-sucedida.\n");
        exit(1);
    }

    vector->data = NULL;

    // dataType* = void**;
    vector->data = (dataType*)malloc(SIZE_ALLOCATED * sizeof(dataType));
    if (vector->data == NULL) {
        printf("Erro! Alocacao de memoria de vetor de dadaos da estrutura vetor mal-sucedida.\n");
        vectorDestroy(vector);
        exit(1);
    }

    vector->size = 0;
    vector->allocated = SIZE_ALLOCATED;
    vector->compare = NULL;

    return vector;
}

void vectorSetCompareFunction(Vector *vector, fptr function) {
    vector->compare = function;
}

unsigned int vectorSize(Vector *vector) {
    return vector->size;
}

Vector *vectorCopy(Vector *vector) {
    Vector *vectorCopy;

    vectorCopy = vectorConstruct();

    unsigned int d;

    for(d = 0; d < vector->size; d++)
        vectorPushBack(vectorCopy, vector->data[d]);

    return vectorCopy;
}

void vectorPushBack(Vector *vector, dataType data) {
    if (vector->size == vector->allocated)
        vectorReallocation(vector);

    vector->data[vector->size++] = data;
}

dataType vectorFind(Vector *vector, dataType data) {
    return vectorBinarySearch(vector, data);
}

dataType vectorGet(Vector *vector, unsigned int index) {
    return vector->data[index];
}

void vectorSet(Vector *vector, unsigned int index, dataType data) {
    vector->data[index] = data;
}

unsigned int vectorArgMax(Vector *vector) {
    return findIndex(vector, vectorMax);
}

unsigned int vectorArgMin(Vector *vector) {
    return findIndex(vector, vectorMin);
}

dataType *vectorMax(Vector *vector) {
    return getRelevantValue(vector, BIG);
}

dataType *vectorMin(Vector *vector) {
    return getRelevantValue(vector, SMALL);
}

void vectorPopFont(Vector *vector) {
    dataType dataRemoved;

    dataRemoved = vectorRemove(vector, 0);
}

void vectorPopBack(Vector *vector) {
    vector->size -= 1;
}

void vectorInsert(Vector *vector, unsigned int index, dataType data) {
    if (vector->size == vector->allocated)
        vectorReallocation(vector);

    unsigned int d;

    for(d = (vector->size - 1); d >= index; d--)
        vectorSwap(vector, d, (d + 1));

    vector->size +=1;

    vector->data[index] = data;
}

dataType vectorRemove(Vector *vector, unsigned int index) {
    unsigned int d;

    for(d = index; d < (vector->size - 1); d++)
        vectorSwap(vector, d, (d + 1));

    vectorPopBack(vector);

    return vector->data[vector->size];
}

void vectorSort(Vector *vector) {
    unsigned int d1, d2;

    for(d1 = 0; d1 < (vector->size- 1); d1++)
        for(d2 = (d1 + 1); d2 < vector->size; d2++)
            if (vector->compare(vector->data[d1], vector->data[d2]) == 1)
                vectorSwap(vector, d1, d2);
}

void vectorSwap(Vector *vector, unsigned int index1, unsigned int index2) {
    dataType auxiliar;

    auxiliar =  vector->data[index1];
    vector->data[index1] = vector->data[index2];
    vector->data[index2] = auxiliar;
}

dataType vectorBinarySearch(Vector *vector, dataType data) {
    const int NOT_FOUND = 1;
    unsigned int inicio, meio, fim;

    vectorSort(vector);

    inicio = 0;
    fim = vector->size;

    while(inicio <= fim) {
        meio = inicio + (fim - inicio) / 2;

        if (vector->data[meio] == data)
            return vector->data;
        else if (vector->data[meio] < data)
            fim = meio - 1;
        else
            inicio = meio + 1;
    }
    return NOT_FOUND;
}

void vectorClear(Vector *vector)  {
    vector->size = 0;
}

void vectorDestroy(Vector *vector) {
    if (vector != NULL) {
        if (vector->data != NULL) {
            free(vector->data);

            vector->data = NULL;
        }
        free(vector);

        vector = NULL;
    }
}