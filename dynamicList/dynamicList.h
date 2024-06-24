#ifndef _DYNAMIC_LIST_H
#define _DYNAMIC_LIST_H

/**
 * MODULE: dynamicList
 * FILE: dynamicList.h
 * VERSION: 1.0.0
 * HISTORICAL: Created by Eloy Urriens Arpal on 11/6/2024.
 * DESCRIPTION: This module is the implement of the dynamic list/vector/array.
 * CC: BY SA
 */

typedef struct node {
    float element;
    struct node *next;
} node;

typedef struct {
    unsigned long long n_elem;
    node *first, *last;
} dynamicList;

/**
 * FUNCTION: newDynamicList
 * INPUT: None.
 * REQUIREMENTS: None.
 * OUTPUT: An empty dynamic list.
 */
void newDynamicList(dynamicList *);

/**
 * FUNCTION: appendDynamicList
 * INPUT: A dynamic list and an element (float).
 * REQUIREMENTS: The length of dynamic list < 2^64
 * MODIFIES: Add the element (float) to the end of the dynamic list.
 */
void appendDynamicList(dynamicList *, float);

/**
 * FUNCTION: insertDynamicList
 * INPUT: A dynamic list, a position and an element (float).
 * REQUIREMENTS: The length of dynamic list < 2^64, 0 <= position < length of dinamic list
 * MODIFIES: Add the element (float) at the position.
 */
void insertDynamicList(dynamicList *, unsigned long long, float);

/**
 * FUNCTION: deleteDynamicList
 * INPUT: A dynamic list and a position (unsigned long long).
 * REQUIREMENTS: 0 <= position < lengthDynamicList(list)
 * MODIFIES: Delete the element and the position.
 */
void deleteDynamicList(dynamicList *, unsigned long long);

/**
 * FUNCTION: changeElemDynamicList
 * INPUT: A dynamic list, a position (unsigned long long), and an element (float).
 * REQUIREMENTS: 0 <= position < lengthDynamicList(list).
 * MODIFIES: Change the value of the element at the position.
 */
void changeElemDynamicList(dynamicList *, unsigned long long, float);

/**
 * FUNCTION: consultElemDynamicList
 * INPUT: A dynamic list, and a position (unsigned long long).
 * REQUIREMENTS: 0 <= position < lengthDynamicList(list).
 * OUTPUT: The element (float) at the position.
 */
float consultElemDynamicList(dynamicList, unsigned long long);

/**
 * FUNCTION: lengthDynamicList
 * INPUT: A dynamic list.
 * REQUIREMENTS: None.
 * OUTPUT: The length of the dynamic list.
 */
unsigned long long lengthDynamicList(dynamicList);

#endif