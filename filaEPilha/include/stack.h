#ifndef _STACK_H_
#define _STACK_H__

#include "vector.h"

typedef struct Stack stack;

/**
 * @brief Create (dynamically allocated memory for) a stack; 
 * 
 * @return Stack* Pointer to the Abstract Data Type represents structure that contains (inicialized) information to the stack;
 */
Stack *stackConstruct();

/**
 * @brief Add an element in the stack;
 * 
 * @param stack Pointer to the Abstract Data Type represents structure that contains (update) information to the stack;
 * @param data Data (element) to be added in the stack;
 */
void stackPush(Stack *stack, dataType data);

/**
 * @brief Remove an element from the stack;
 * 
 * @param stack Pointer to the Abstract Data Type represents structure that contains (update) information to the stack;
 * @return dataType Data (element) to be removed frm the stack;
 */
dataType stackPop(Stack *stack);

/**
 * @brief Checks if stack is empty;
 * 
 * @param stack Pointer to the Abstract Data Type represents structure that contains (update) information to the stack;
 * @return int 1 (true) if stack is empty or 0 (false), otherwise;
 */
int stackEmpty(Stack *stack);

/**
 * @brief Destroy (dynamically free/desallocates memory for) a stack;
 * 
 * @param stack Pointer to the Abstract Data Type represents structure that contains (update) information to the stack;
 */
void stackDestroy(Stack *stack);

#endif