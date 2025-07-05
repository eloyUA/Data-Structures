#ifndef _MIN_HEAP_H
#define _MIN_HEAP_H

/**
 * MODULE: minHeap
 * FILE: minHeap.h
 * VERSION: 1.0.0
 * HISTORICAL: Created by Eloy Urriens on 16/1/2025
 * DESCRIPTION: This module is a min-heap.
 *      For more information: https://en.wikipedia.org/wiki/Min-max_heap
 * CC: SA BY
 */

#include <stdbool.h>

typedef int typeElem;
typedef struct {
    int pos;
    int max_numbers;
    typeElem *numbers;
} MinHeap;

/**
 * FUNCTION: newMinHeap
 * INPUT: The maximum number of the elements in the minHeap.
 * REQUIREMENTS: The int > 0.
 * OUTPUT: The empty minHeap with maximum size (int).
 */
void newMinHeap(MinHeap *, int);

/**
 * FUNCTION: insertElemMinHeap
 * INPUT: The minHeap and the element.
 * REQUIREMENTS: The minHeap isn't full and the elem cannot be repeat.
 * OUTPUT: The minHeap with the element.
 */
void insertElemMinHeap(MinHeap *, typeElem);

/**
 * FUNCTION: deleteElemMinHeap
 * INPUT: The minHeap and a element to delete.
 * REQUIREMENTS: The minHeap isn't empty.
 * OUTPUT: The minHeap without the element. (If it is).
 */
void deleteElemMinHeap(MinHeap *, typeElem);

/**
 * FUNCTION: rootMinHeap
 * INTPUT: The minHeap
 * REQUIREMENTS: The minHeap isn't empty.
 * OUTPUT: The root of the minHeap.
 */
typeElem rootMinHeap(MinHeap);

/**
 * FUNCTION: elemInMinHeap
 * INPUT: The minHeap and a element.
 * REQUIREMENTS: None
 * OUTPUT: True <=> The element is in the minHeap
 */
bool elemInMinHeap(MinHeap, typeElem);

/**
 * FUNCTION: numberElementsMinHeap
 * INPUT: The minHeap.
 * REQUIREMENTS: None.
 * OUTPUT: The number of the elements in minHeap.
 */
int numberElementsMinHeap(MinHeap);

/**
 * FUNCTION: isEmptyMinHeap
 * INPUT: The minHeap.
 * REQUIREMENTS: None
 * OUTPUT: True <=> The minHeap is empty.
 */
bool isEmptyMinHeap(MinHeap);

/**
 * FUNCTION: isFulMinHeap
 * INPUT: The minHeap.
 * REQUIREMENTS: None
 * OUTPUT: True <=> The minHeap is full.
 */
bool isFullMinHeap(MinHeap);

#endif