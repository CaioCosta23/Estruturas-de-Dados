#include <stdio.h>
#include <stdlib.h>

#include "../include/queue.h"

struct Queue {
    Vector *vector;
};

Queue *queueConstruct() {
    Queue *queue = NULL;

    queue = (Queue*)malloc(sizeof(Queue));

    if (queue == NULL) {
        printf("Erro! Alocacao de memoria de fila mal-sucedida.\n");
        exit(1);
    }
    queue->vector= vectorConstruct();

    return queue;
}

void queueEnqueue(Queue *queue, dataType data) {
    vectorPushBack(queue->vector, data);
}

dataType queueDequeue(Queue *queue) {
    vectorPopFront(queue->vector);
}

int queueEmpty(Queue *queue) {
    return vectorSize(queue->vector) == 0;
}

void queueDestroy(Queue *queue) {
    if (queue != NULL) {
        vectorDestroy(queue->vector);

        free(queue);

        queue = NULL;
    }
}