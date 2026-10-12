#ifndef _CIRCULAR_ARRAY_H_
#define _CIRCULAR_ARRAY_H_

typedef struct CircularArray CircularArray;

/**
 * @brief Create (dynamically allocated memory for) a circular array;
 * 
 * @return CircularArray* Pointer to the Abstract Data Type represents sructure that contains (inicialized) information to the circular array;
 */
CircularArray *circularArrayConstruct();

/**
 * @brief Get size to the circular array;
 * 
 * @param circularArray Pointer to the Abstract Data Type represents sructure that contains (update) information to the circular array;
 * @return unsigned int Size of circular array;
 */
unsigned int circularArrayGetSize(CircularArray *circularArray);

/**
 * @brief Add an element in the ccircular array;
 * 
 * @param circularArray Pointer to the Abstract Data Type represents sructure that contains (update) information to the circular array;
 */
void circularArrayPush(CircularArray *circularArray);

/**
 * @brief Remove an element in the circular array;
 * 
 * @param circularArray Pointer to the Abstract Data Type represents sructure that contains (update) information to the circular array;
 */
void circularArrayPop(CircularArray *circularArray);

/**
 * @brief Destroy (dynamically free/desallocated memory for) a circular array;
 * 
 * @param circularArray Pointer to the Abstract Data Type represents sructure that contains (update) information to the circular array;
 */
void circularArrayDestroy(CircularArray *circularArray);

#endif