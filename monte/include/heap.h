#ifndef _HEAP_H_
#define _HEAP_H_

typedef struct Heap Heap;

/**
 * @brief Create (dynamically allocated memory for) a heapt;
 * 
 * @return Heap* Pointer to the Abstratct Data Type represents structure that contains (inicialized) information for a heap;
 */
Heap *heapConstruct();

/**
 * @brief Get the size of heap;
 * 
 * @param heap Pointer to the Abstratct Data Type represents structure that contains (update) information for a heap;
 * @return unsigned int 
 */
unsigned int heapSize(Heap *heap);

/**
 * @brief Verify if heap is empty;
 * 
 * @param heap Pointer to the Abstratct Data Type represents structure that contains (update) information for a heap;
 * @return unsigned int 1 (true) if 
 */
unsigned int heapEmpty(Heap *heap);

/**
 * @brief Get the biggest element from the heap;
 * 
 * @param heap Pointer to the Abstratct Data Type represents structure that contains (update) information for a heap;
 * @return void* Pointer to the biggest element from the heap;
 */
void *heapMax(Heap *heap);

/**
 * @brief Get the smallest element from the heap;
 * 
 * @param heap Pointer to the Abstratct Data Type represents structure that contains (update) information for a heap;
 * @return void* Pointer to the smallest element from the heap;
 */
void *heapMin(Heap *heap);

/**
 * @brief Add an element in the heap;
 * 
 * @param heap Pointer to the Abstratct Data Type represents structure that contains (update) information for a heap;
 */
void heapPush(Heap *heap);

/**
 * @brief Remove an element in the heap;
 * 
 * @param heap Pointer to the Abstratct Data Type represents structure that contains (update) information for a heap;
 * @return void* Pointer to the element to be was removed;
 */
void *heapPop(Heap *heap);

/**
 * @brief Places an element in it's correct position by moving up the element tree;
 * 
 * @param heap Pointer to the Abstratct Data Type represents structure that contains (update) information for a heap;
 * @param index Index of element from start de correction (if necessary);
 */
void heapfyUp(Heap *heap, unsigned int index);

/**
 * @brief Places an element in it's correct position by descending the element tree;
 * 
 * @param heap Pointer to the Abstratct Data Type represents structure that contains (update) information for a heap;
 * @param arraySize Size of array o the heap;
 * @param index Index Index of element from start de correction;
 */
void heapfyDown(Heap *heap, unsigned int arraySize, unsigned int index);

/**
 * @brief Sort elements from the heap;
 * 
 * @param heap Pointer to the Abstratct Data Type represents structure that contains (update) information for a heap;
 * @param arraySize Size of array o the heap;
 * @param compare Callback function to compare two elements in the heap;
 */
void heapSort(Heap *heap, unsigned arraySize, unsigned int compare(void*, void*));

/**
 * @brief Destroy (dynamically free/desallocated memory for) a heap;
 * 
 * @param heap Pointer to the Abstratct Data Type represents structure that contains (update) information for a heap;
 */
void heapDestroy(Heap *heap);

#endif