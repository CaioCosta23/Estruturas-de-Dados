#include <stdio.h>
#include <stdlib.h>

#include "../include/vector.h"

#define INITIAL_SIZE_ALLOCATED 50

#define SMALL -1
#define EQUALS 0
#define BIG 1

/**
 * @brief Check which data is biggest than other data;
 * 
 * @param data1 First data to be compare with second;
 * @param data2 Second data to be compare with first;
 * @return unsigned short int 1 if first data is biggest than second data or -1 if second data are biggest than first or 0 (false), otherwise;
 */
static unsigned short int compare(dataType data1, dataType data2) {
    if (data1 < data2)
        return SMALL;
    else if (data1 == data2)
        return EQUALS;
    else
        return BIG;
}

/**
 * @brief Find de index of an element (biggest or smallest element);
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @param getElement Callback function where get the element (biggest or smallest) for get the index of this element;
 * @return unsigned int Index of element sought (biggest or smallest element);
 */
static unsigned int findIndex(Vector *vector, dataType getElement(Vector *vector)) {
    unsigned int d;

    for(d = 0; d < vectorSize(vector); d++)
        if (compare(vectorGet(vector, d), getElement(vector)) == 0)
            return d;
}

/**
 * @brief Get the relevant value (biggest or smalles value in the vector);
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @param  characteristicSearch Characterist of element to be compare and search;
 * @return short int Element relevant in the vector (biggest or smalles element);
 */
static short int getRelevantValue(Vector *vector, short int characteristicSearch) {
    unsigned int d;
    dataType marker;

    marker = vectorGet(vector, 0);

    for(d = 0; d < vectorSize(vector); d++)
        if (compare(vectorGet(vector, d), marker) == characteristicSearch)
            marker = vectorGet(vector, d);
    
    return marker;
}

/**
 * @brief Push back an element to the last position of vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @param index Index of element to be push  to the last position in the vector;
 */
static void pushBackElements(Vector *vector, unsigned int index) {
    unsigned int d;

    for(d = (vector->size - 1); d >= index; d--)
        vectorSwap(vector, d, (d + 1));
}

/**
 * @brief Realloc the memory of vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 */
static void vectorReallocation(Vector *vector) {
    vector->allocated = (dataType*)realloc(vector->data, vector->allocated * sizeof(dataType));

    if (vector->data == NULL) {
        printf("Erro! Realocacao de memoria de dadaos do vetor mal-sucedida.\n");
        vectorDestroy(vector);
        exit(1);
    }
}


Vector *vectorConstruct() {
    Vector *vector = NULL;

    vector = (Vector*)malloc(sizeof(Vector));

    if (vector == NULL) {
        printf("Eroo! Alocacao de memoria de vetor (vector) mal-sucedida.\n");
        exit(1);
    }

    vector->data = (dataType*)malloc(INITIAL_SIZE_ALLOCATED * sizeof(dataType));

    if (vector->data == NULL) {
        printf("Erro! Alocacao de memoria de vetor de dados da estrutura do vetor (vectorr) mal-sucedida.\n");
        vectorDestroy(vector);
        exit(1);
    }

    vector->size = 0;
    vector->allocated = INITIAL_SIZE_ALLOCATED;

    return vector;
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
    return findIndex(vector, vectorMax);
}


dataType vectorMax(Vector *vector) {
    return getRelevantValue(vector, BIG);
}

dataType vectorMin(Vector *vector) {
    return getRelevantValue(vector, SMALL);
}

void vectorPopFront(Vector *vector) {
    dataType dataRemoved;

    dataRemoved = vectorRemove(vector, (vector->size - 1));
}

void vectorPopBack(Vector *vector) {
    vector->size -= 1;
}

void vectorInsert(Vector *vector, unsigned int index, dataType data) {
    if (vector->size == vector->allocated)
        vectorReallocation(vector);

    vector->size += 1;

    pushBackElements(vector, index);

    vector->data[index] = data;
}

dataType vectorRemove(Vector *vector, unsigned int index) {
    pushBackElements(vector, index);
    vectorPopBack(vector);

    return vector->data[vector->size];
}


void vectorSort(Vector *vector) {
    unsigned int d1, d2;

    for(d1 = 0; d1 < (vector->size - 1); d1++)
        for(d2 = d1 + 1; d2 < vector->size; d2++)
            if (compare(vector->data[d1], vector->data[d2]) == 1)
                vectorSwap(vector, d1, d2);

}

void vectorSwap(Vector *vector, unsigned int index1, unsigned int index2) {
    dataType auxiliar;

    auxiliar = vector->data[index1];
    vector->data[index1] = vector->data[index2];
    vector->data[index2] = auxiliar;
}

unsigned int vectorBinarySearch(Vector *vector, dataType data) {
    const int NOT_FOUND = -1;
    unsigned int inicio, meio, fim;

    vectorSort(vector);

    inicio = 0;
    fim = vectorSize(vector);

    while(inicio <= fim) {
        meio = inicio + (fim - inicio) / 2;

        if (vector->data[meio] == data)
            return vector->data;

        if (vector->data[meio] < data)
            fim = meio -1;
        else
            inicio = meio + 1;
    }

    return NOT_FOUND;
}

void vectorReverse(Vector *vector) {
    unsigned int d1, d2;
    
    for(d1 = 0; d1 < (vector->size - 1); d1++)
        for(d2 = d1 + 1; d2 < vector->size; d2++)
            vectorSwap(vector, d1, d2);
}

void vectorClear(Vector *vector) {
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