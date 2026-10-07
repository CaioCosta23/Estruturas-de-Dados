#ifndef _VECTOR_H_
#define _VECTORR_H_

typedef int dataType; // Determina o dado como tipo "int" (inteiro) - |Alterável|;

typedef struct {
    dataType *data;
    unsigned int size, allocated;
} Vector;

/**
 * @brief Create (dynamically allocates memory for) a vector;
 * 
 * @return Vector* Pointer to the Abstract Data Type represent a structure that contains the (inicialized) information for a vector;
 */
Vector *vectorConstruct();

/**
 * @brief Get the size vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @return unsigned int Size of vector;
 */
unsigned int vectorSize(Vector *vector);

/**
 * @brief Copy a vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @return Vector* Pointer to the Abstract Data Type represent a structure taht contains the (update) information for a vector copied;
 */
Vector *vectorCopy(Vector *vector);

/**
 * @brief Adds an element on the end of the vector; 
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @param data Data to be added in final of the vector;
 */
void vectorPushBack(Vector *vector, dataType data);

/**
 * @brief Searchs for an element in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @param data Data sought in the vector;
 * @return dataType Sought-after element if found, or -1 otherwise; 
 */
dataType vectorFind(Vector *vector, dataType data);

/**
 * @brief Get an specific element in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @param index Index of the sought element in the vector;
 * @return dataType Sought-after element;
 */
dataType vectorGet(Vector *vector, unsigned int index);

/**
 * @brief Replace an element in especific index in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @param index Index of position where the nes element will be added;
 * @param data Element thats replace another in the vector;
 */
void vectorSet(Vector *vector, unsigned int index, dataType data);

/**
 * @brief Searchs the biggest element and return your index in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @return int Index of the biggest element in the vector;
 */
unsigned int vectorArgMax(Vector *vector);

/**
 * @brief Searchs the smallest element and return your index in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @return int Index of the smallest element in the vector;
 */
unsigned int vectorArgMin(Vector *vector);

/**
 * @brief Searchs biggest element in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @return dataType Biggest element in the vector;
 */
dataType vectorMax(Vector *vector);

/**
 * @brief Searchs biggest element in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @return dataType Smallest element in the vector;
 */
dataType vectorMin(Vector *vector);

/**
 * @brief Removes the element of the first position of the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 */
void vectorPopFront(Vector *vector);

/**
 * @brief Removes the element of the last position from the vector; 
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 */
void vectorPopBack(Vector *vector);

/**
 * @brief Insert a element at a specific position in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @param index Index where element will be added in the vector;
 * @param data Element to added in the vector;
 */
void vectorInsert(Vector *vector, unsigned int index, dataType data);

/**
 * @brief Removes an element at a specific position from the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @param index Index where element will be removed in the vector;
 * @return dataType Element removed from the vector;
 */
dataType vectorRemove(Vector *vector, unsigned int index);

/**
 * @brief Sort an vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 */
void vectorSort(Vector *vector);

/**
 * @brief Swap the positions of two elements in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @param index1 Index of the position of the first element to be swapped with second in the vector;
 * @param index2 Index of the position of the second element to be swapped with first in the vector;
 */
void vectorSwap(Vector *vector, unsigned int index1, unsigned int index2);

/**
 * @brief Peforms a binary search for a element in the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 * @param data Element sought in the vector;
 * @return unsigned int Index of element found in the vector, or -1 otherwise;
 */
unsigned int vectorBinarySearch(Vector *vector, dataType data);

/**
 * @brief Reverse the vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 */
void vectorReverse(Vector *vector);

/**
 * @brief Clear (removes all elements in the) vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 */
void vectorClear(Vector *vector);

/**
 * @brief Destroy (dynamically free/desallocates memory for) a vector;
 * 
 * @param vector Pointer to the Abstract Data Type represent a structure that contains the (update) information for a vector;
 */
void vectorDestroy(Vector *vector);

#endif