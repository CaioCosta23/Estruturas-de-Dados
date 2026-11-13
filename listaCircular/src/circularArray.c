#include <stdio.h>
#include <stdlib.h>

#include "../include/circularArray.h"


#define INITIAL_CAPACITY 10

struct CircularArray {
    void **data;
    unsigned int start, end, size, capacity;
    fptr *destroy;
};


/**
 * @brief Realloc (dynamically) the memory or array of data in circular array;
 * 
 * @param circularArray Pointer to the Abstract Data Type represents sructure that contains (update) information to the circular array;
 * @return unsigned short int 1 (true) if reallocation was succefully or 0 (false), everywhere;
 */
static unsigned short int reallocCircularArray(CircularArray *circularArray) {
    const unsigned short int TWO = 2;
    unsigned int newCapacity;
    void **temporaryArrayData = NULL;
    fptr *temporaryArrayFree = NULL;

    newCapacity = circularArray->capacity * TWO;

    temporaryArrayData = (void**)realloc(circularArray->data, newCapacity * sizeof(void*));
    temporaryArrayFree = (fptr*)realloc(circularArray->destroy, newCapacity * sizeof(fptr));

    if ((temporaryArrayData == NULL) || temporaryArrayFree == NULL) {
        printf("Error Dynamically reallocation of memory of array of data or array of function pointers for free elements in cicular array, fail.\n");

        return 0;
    } else {
        unsigned int d, oldIndex;

        // "Refaz" a lista colocando os elementos de forma contígua (sequencial) no 'array' circular (agora, com tamanho novo);
        for (d = 0; d < circularArray->size; d++) {
            oldIndex = (circularArray->start + d) % circularArray->capacity;

            temporaryArrayData[d] = circularArray->data[oldIndex];
            temporaryArrayFree[d] = circularArray->destroy[oldIndex];
        }

        /*
        // Verifica se o vetor está após o início local (sequencial) do 'array';

        // Move os elementos que estavam no funal da lista circular (mas no início do veto - fisicamente) para trás dos elementos que estavam
        // no final do vetor (fisicamente) mantendo a concordância da ordem dos elementos na lista (mesmo com o aumento do 'array'
        // sedo contíguo - sequncial - o que quebra em teoria aordem dos elementos de uma lista circular);
            if (circularArray->start > 0) {
                for (d = 0; d < circularArray->start; d++) {
                    temporaryArrayData[circularArray->capacity + d] = circularArray->data[d];
                    temporaryArrayFree[circularArray->capacity + d] = circularArray->destroy[d];
                }
            }
        */
        
        circularArray->capacity = newCapacity;
        circularArray->data = temporaryArrayData;
        circularArray->destroy = temporaryArrayFree;

        return 1;
    }
}



CircularArray *circularArrayConstruct() {
    CircularArray *circularArray = NULL;

    circularArray = (CircularArray*)malloc(sizeof(CircularArray));
    
    if (circularArray == NULL) {
        printf("Error! Dinamically allocation of memort for circular array fail.\n");
        exit(1);
    }

    circularArray->data = NULL;

    circularArray->data = (void**)malloc(INITIAL_CAPACITY * sizeof(void*));

    if (circularArray->data == NULL) {
        printf("Erroe! Dynamically allocation for array of data in circular array fail.\n");
        circularArrayDestroy(circularArray);
        exit(1);
    }

    circularArray->destroy = NULL;

    circularArray->destroy = (fptr*)malloc(INITIAL_CAPACITY * sizeof(fptr));

    if (circularArray->destroy == NULL) {
        printf("Error! Dynamically allocation of memory for array of function pointers for free elements in array, fail.\n");
        circularArrayDestroy(circularArray);
        exit(1);
    }

    circularArray->size = 0;
    circularArray->capacity = INITIAL_CAPACITY;
    circularArray->start = 0;
    circularArray->end = 0;

    return circularArray;
}

unsigned int circularArrayGetSize(CircularArray *circularArray) {
    return circularArray->size;
}


void circularArrayPush(CircularArray *circularArray, void *data, fptr freeElement) {
    unsigned short necessaryReallocation = 0;
    unsigned int reallocationSuccessfully;

    if (circularArrayIsFull(circularArray)) {
        necessaryReallocation = 1;
        reallocationSuccessfully = reallocCircularArray(circularArray);
    }

    if (necessaryReallocation) {
        if (reallocationSuccessfully) {
            circularArray->end = (circularArray->start + circularArray->size) % circularArray->capacity;
            circularArray->data[circularArray->end] = data;
            circularArray->destroy[circularArray->end] = freeElement;
            circularArray->size++;
        }else {
            printf("Element not add for circular array is full.\n");
        }
    }else {
        circularArray->end = (circularArray->start + circularArray->size) % circularArray->capacity;
        circularArray->data[circularArray->end] = data;
        circularArray->destroy[circularArray->end] = freeElement;
        circularArray->size++;
    }
}

void *circularArrayPop(CircularArray *circularArray) {
    void *elementRemoved;

    elementRemoved = circularArray->data[circularArray->start];
    circularArray->data[circularArray->start] = NULL;
    circularArray->destroy[circularArray->start] = NULL;
    circularArray->start = (circularArray->start + 1) % circularArray->capacity;
    circularArray->size--;

    return elementRemoved;
}

unsigned short int circularArrayIsEmpty(CircularArray *circularArray) {
    return (circularArray->size == 0);
}

unsigned short int circularArrayIsFull(CircularArray *circularArray) {
    return (circularArray->size == circularArray->capacity);
}

void circularArrayDestroy(CircularArray *circularArray) {
    if (circularArray != NULL) { 
        if (circularArray->data != NULL) {
            if (!(circularArrayIsEmpty(circularArray)))  {
                unsigned int d;

                for(d = 0; d < circularArray->size; d++) 
                    circularArray->destroy[(circularArray->start + d) % circularArray->capacity](circularArray->data[(circularArray->start + d) % circularArray->capacity]);
            }
            free(circularArray->destroy);
            circularArray->destroy = NULL;

            free(circularArray->data);
            circularArray->data = NULL;
        }
        free(circularArray);
        circularArray = NULL;
    }
}