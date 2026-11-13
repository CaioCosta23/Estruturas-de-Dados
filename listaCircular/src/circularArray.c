#include <stdio.h>
#include <stdlib.h>

#include "../include/circularArray.h"


#define INITIAL_CAPACITY 10


typedef void (*fptr)(void*);


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
    void **temporaryArray;

    newCapacity = circularArray->capacity * TWO;

    circularArray->data = (void**)realloc(temporaryArray, newCapacity *sizeof(void*));

    if (temporaryArray == NULL) {
        printf("Error Dynamically reallocation of memory of array of data in cicular array fail.\n");

        return 0;
    } else {
        circularArray->capacity = newCapacity;
        circularArray->data = temporaryArray;

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

    circularArray->data = (void**)malloc(sizeof(void*));

    if (circularArray->data == NULL) {
        printf("Erroe! Dynamically allocation for array of data in circular array fail.\n");
        circularArrayDestroy(circularArray);
    }

    circularArray->size = 0;
    circularArray->capacity = INITIAL_CAPACITY;
    circularArray->start = 0;
    circularArray->end = 0;
    circularArray->destroy = NULL;

    return circularArray;
}

unsigned int circularArrayGetSize(CircularArray *circularArray) {
    return circularArray->size;
}


void circularArrayPush(CircularArray *circularArray, void *data, fptr *freeElement) {
    unsigned short necessaryReallocation = 0;
    unsigned int reallocationSuccessfully;

    if (circularArrayIsFull(circularArray)) {
        necessaryReallocation = 1;
        reallocationSuccessfully = reallocCircularArray(circularArray);
    }

    if (necessaryReallocation) {
        if (reallocationSuccessfully) {
            circularArray->end = (circularArray->start + circularArray->size) % circularArray->capacity;
            circularArray->data[circularArray->end];
            circularArray->destroy[circularArray->end] = freeElement;
            circularArray->size++;
        }else {
            printf("Element not add for circular array is full.\n");
        }
    }else {
        circularArray->end = (circularArray->start + circularArray->size) % circularArray->capacity;
        circularArray->data[circularArray->end];
        circularArray->destroy[circularArray->end] = freeElement;
        circularArray->size++;
    }
}

void *circularArrayPop(CircularArray *circularArray) {
    void *elementRemoved;

    elementRemoved = circularArray->data[circularArray->end];
    circularArray->data[circularArray->end] = NULL;
    circularArray->destroy[circularArray->end] = NULL;
    circularArray->size--;
    circularArray->end = (circularArray->start + circularArray->size) % circularArray->capacity;

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
            free(circularArray->data);
            circularArray->data = NULL;
        }
        free(circularArray);
        circularArray = NULL;
    }
}