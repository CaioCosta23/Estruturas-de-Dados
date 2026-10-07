#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "vector.h"

#define MAX_SIZE_DATA 32

typedef struct Queue Queue;

/**
 * @brief Create (dynamically allocates memory for) a queue;
 * 
 * @return Queue* Pointer to the Abstract Data Type represent a structure that contains (inicialized) informations for a queue;
 */
Queue *queueConstruct();

/**
 * @brief Enqueue (Add) an element in the queue;
 * 
 * @param queue Pointer to the Abstract Data Type represent a structure that contains (update) informations for a queue;
 * @param data Data to be added in the queue;
 */
void queueEnqueue(Queue *queue, dataType data);

/**
 * @brief Enqueue (Remove) ann element in the queue;
 * 
 * @param queue Pointer to the Abstract Data Type represent a structure that contains (update) informations for a queue;
 * @return dataType Data (element) to be removed from the queue;
 */
dataType queueDequeue(Queue *queue);

/**
 * @brief Cheks if the queue is empty;
 * 
 * @param queue Pointer to the Abstract Data Type represent a structure that contains (update) informations for a queue;
 * @return int 1 (true) if queue is empty or 0 (false), otherwhise;
 */
int queueEmpty(Queue *queue);

/**
 * @brief Prints the data from a queue to the screen;
 * 
 * @param queue Pointer to the Abstract Data Type represent a structure that contains (update) informations for a queue;
 */
void queuePrint(Queue *queue);

/**
 * @brief Destroy (dynamically free/desallocates memory for) a queue;
 * 
 * @param queue Pointer to the Abstract Data Type represent a structure that contains (update) informations for a queue;
 */
void queueDestroy(Queue *queue);

#endif