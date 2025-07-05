#ifndef _MAX_HEAP_H
#define _MAX_HEAP_H

/**
 * MODULE: maxHeap
 * FILE: maxHeap.h
 * VERSION: 1.0.0
 * HISTORICAL: Created by Eloy Urriens on 16/1/2025
 * DESCRIPTION: This module is a max-heap.
 *      For more information: https://en.wikipedia.org/wiki/Min-max_heap
 * CC: SA BY
 */

#include <stdbool.h>

typedef int typeElem;
typedef struct {
    int pos;
    int max_numbers;
    typeElem *numbers;
} MaxHeap;

/**
 * FUNCTION: newMaxHeap
 * INPUT: The maximum number of the elements in the maxHeap.
 * REQUIREMENTS: The int > 0.
 * OUTPUT: The empty maxHeap with maximum size (int).
 */
void newMaxHeap(MaxHeap *, int);

/**
 * FUNCTION: insertElemMaxHeap
 * INPUT: The maxHeap and the element.
 * REQUIREMENTS: The maxHeap isn't full and the elem cannot be repeat.
 * OUTPUT: The maxHeap with the element.
 */
void insertElemMaxHeap(MaxHeap *, typeElem);

/**
 * FUNCTION: deleteElemMaxHeap
 * INPUT: The maxHeap and a element to delete.
 * REQUIREMENTS: The maxHeap isn't empty.
 * OUTPUT: The maxHeap without the element. (If it is).
 */
void deleteElemMaxHeap(MaxHeap *, typeElem);

/**
 * FUNCTION: rootMaxHeap
 * INTPUT: The maxHeap
 * REQUIREMENTS: The maxHeap isn't empty.
 * OUTPUT: The root of the maxHeap.
 */
typeElem rootMaxHeap(MaxHeap);

/**
 * FUNCTION: elemInMaxHeap
 * INPUT: The maxHeap and a element.
 * REQUIREMENTS: None
 * OUTPUT: True <=> The element is in the maxHeap
 */
bool elemInMaxHeap(MaxHeap, typeElem);

/**
 * FUNCTION: numberElementsMaxHeap
 * INPUT: The maxHeap.
 * REQUIREMENTS: None.
 * OUTPUT: The number of the elements in maxHeap.
 */
int numberElementsMaxHeap(MaxHeap);

/**
 * FUNCTION: isEmptyMaxHeap
 * INPUT: The maxHeap.
 * REQUIREMENTS: None
 * OUTPUT: True <=> The maxHeap is empty.
 */
bool isEmptyMaxHeap(MaxHeap);

/**
 * FUNCTION: isFulMaxHeap
 * INPUT: The maxHeap.
 * REQUIREMENTS: None
 * OUTPUT: True <=> The maxHeap is full.
 */
bool isFullMaxHeap(MaxHeap);

void show(MaxHeap);

#endif