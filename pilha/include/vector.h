#ifndef _VECTOR_H_
#define _VECTOR_H_

typedef void* dataType;

typedef struct Vector Vector;

/**
 * @brief Create (dinamically allocates memory for) a vector;
 * 
 * @return Vector* Pointer to the Abstract Data Type represents structure that contains (inicialized) informations for a vector;
 */
Vector *vectorConstruct();

/**
 * @brief Get get size to the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 * @return unsigned int Size of vector;
 */
unsigned int vectorSize(Vector *vector);

/**
 * @brief Copy entire structure (and data) of the type vector; 
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 * @return Vector* Pointer to the Abstract Data Type represents a copty of the structure that contains (update) informations for a vector;
 */
Vector *vectorCopy(Vector *vector);

/**
 * @brief Adds an element on theend of the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 * @param data Data to be added at the end of the vector;
 */
void vectorPushBack(Vector *vector, dataType data);

/**
 * @brief Searchs for an element in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 * @param data Data sought in the vector;
 * @return dataType Sought-after element if found, or -1, otherwise;
 */
dataType vectorFind(Vector *vector, dataType data);

/**
 * @brief Get an especifi element in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 * @param index Index of the sought element in the vector;
 * @return dataType Sought-after element;
 */
dataType vectorGet(Vector *vector, unsigned int index);


/**
 * @brief Replace an elemeent in especific index in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 * @param index Index of position where the element will be added;
 * @param data Element thats replace another in the vector;
 */
void vectorSet(Vector *vector, unsigned int index, dataType data);

/**
 * @brief Searchs the biggest element in the vector and returns your index;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 * @return int Index of biggest element in the vector;
 */
unsigned int vectorArgMax(Vector *vector);

/**
 * @brief Searchs the smallest element in the vector and returns your index;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 * @return int Index of smallest element in the vector;
 */
unsigned int vectorArgMin(Vector *vector);

/**
 * @brief Searchs biggest element in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 * @return dataType* Pointer to the biggest element in the vector;
 */
dataType *vectorMax(Vector *vector);

/**
 * @brief Searchs smallest element in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 * @return dataType* Pointer to the smallest element in the vector;
 */
dataType *vectorMin(Vector *vector);

/**
 * @brief Removes the element of the first position of the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 */
void vectorPopFont(Vector *vector);

/**
 * @brief Removes the element of the last position of the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 */
void vectorPopBack(Vector *vector);

/**
 * @brief Insert an element at the pecific position in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 * @param index Index where element will be added  in the vector;
 * @param data Element to be added in the vector;
 */
void vectorInsert(Vector *vector, unsigned int index, dataType data);

/**
 * @brief Removes an element at the specific position from the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 * @param index 
 * @return dataType 
 */
dataType vectorRemove(Vector *vector, unsigned int index);

/**
 * @brief Sort an vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 */
void vectorSort(Vector *vector);

/**
 * @brief Swap the positions of two elements in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 * @param index1 Index of the position of the first element to be swapped with second in the vector;
 * @param index2 Index of the position of the second element to be swapped with first in the vector;
 */
void vectorSwap(Vector *vector, unsigned int index1, unsigned int index2);

/**
 * @brief Performs a binary search for a element in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 * @param data Element sought in the vector;
 * @return dataType Element found in the vector, or -1, otherwise;
 */
dataType vectorBinarySearch(Vector *vector, dataType data);

/**
 * @brief Clear (removes all elements in the) vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 */
void vectorClear(Vector *vector);

/**
 * @brief Destroy (dynamically free/desallocates memory for) a vector;
 * 
 * @param vector Pointer to the Abstract Data Type represents structure that contains (update) informations for a vector;
 */
void vectorDestroy(Vector *vector);

#endif