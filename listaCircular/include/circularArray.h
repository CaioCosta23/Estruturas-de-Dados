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
 * @param data Data to addef in circular array;
 */
void circularArrayPush(CircularArray *circularArray, void *data);

/**
 * @brief Remove an element in the circular array;
 * 
 * @param circularArray Pointer to the Abstract Data Type represents sructure that contains (update) information to the circular array;
 */
void *circularArrayPop(CircularArray *circularArray);

/**
 * @brief Get an element of circular array;
 * 
 * @param circularArray Pointer to the Abstract Data Type represents sructure that contains (update) information to the circular array;
 * @param index Index of element in circular array;
 */
void circularArrayGetElement(CircularArray *circularArray, unsigned int index);

/**
 * @brief Check if circular array is empty;
 * 
 * @param circularArray Pointer to the Abstract Data Type represents sructure that contains (update) information to the circular array;
 * @return unsigned short int 1 (true) if circular array is empty or 0 (false) everywhere;
 */
unsigned short int circularArrayIsEmpty(CircularArray *circularArray);

/**
 * @brief Check if circular array is full;
 * 
 * @param circularArray Pointer to the Abstract Data Type represents sructure that contains (update) information to the circular array;
 * @return unsigned short int 1 (true) if circular array is full or 0 (false) everywhere;
 */
unsigned short int circularArrayIsFull(CircularArray *circularArray);

/**
 * @brief Destroy (dynamically free/desallocated memory for) a circular array;
 * 
 * @param circularArray Pointer to the Abstract Data Type represents sructure that contains (update) information to the circular array;
 */
void circularArrayDestroy(CircularArray *circularArray);

#endif