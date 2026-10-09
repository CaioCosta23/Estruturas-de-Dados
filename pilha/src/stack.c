#include <stdio.h>
#include <stdlib.h>

#include "../include/stack.h"

struct Stack {
    Vector *vector;
};

Stack *stackConstruct() {
    Stack *stack = NULL;

    stack = (Stack*)malloc(sizeof(Stack));

    if (stack == NULL) {
        printf("Erro! Alocacao de memoria de pilha mal-sucedida.\n");
        exit(1);
    }
    stack->vector = vectorConstruct();

    return stack;
}

void stackPush(Stack *stack, dataType data) {
    vectorPushBack(stack->vector, data);
}

dataType stackPop(Stack *stack) {
    return vectorRemove(stack->vector, (vectorSize(stack->vector) - 1));
}

unsigned short int stackEmpty(Stack *stack) {
    return vectorSize(stack->vector) == 0;
}

void stackDestroy(Stack *stack) {
    if (stack != NULL) {
        vectorDestroy(stack->vector);

        free(stack);

        stack = NULL;
    }
}