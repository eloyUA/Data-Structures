#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

/**
 * MODULE: linkedList
 * FILE: linkedList.h
 * VERSION: 1.0.1
 * HISTORICAL: 
 *      Created by Eloy Urriens Arpal on 11/6/2024, version 1.0.0
 *      Modified by Eloy Urriens Arpal on 22/22/2025, version 1.0.1
 *          Some names are changed.
 * DESCRIPTION: This module is the implement of the linked list.
 * CC: BY SA
 */

typedef struct node {
    float element;
    struct node *next;
} node;

typedef struct {
    unsigned long long n_elem;
    node *first, *last;
} linkedList;

/**
 * FUNCTION: newLinkedList
 * INPUT: None.
 * REQUIREMENTS: None.
 * OUTPUT: An empty dynamic list.
 */
void newLinkedList(linkedList *);

/**
 * FUNCTION: appendLinkedList
 * INPUT: A dynamic list and an element (float).
 * REQUIREMENTS: The length of dynamic list < 2^64
 * MODIFIES: Add the element (float) to the end of the dynamic list.
 */
void appendLinkedList(linkedList *, float);

/**
 * FUNCTION: insertLinkedList
 * INPUT: A dynamic list, a position and an element (float).
 * REQUIREMENTS: The length of dynamic list < 2^64, 0 <= position < length of dinamic list
 * MODIFIES: Add the element (float) at the position.
 */
void insertLinkedList(linkedList *, unsigned long long, float);

/**
 * FUNCTION: deleteLinkedList
 * INPUT: A dynamic list and a position (unsigned long long).
 * REQUIREMENTS: 0 <= position < lengthLinkedList(list)
 * MODIFIES: Delete the element and the position.
 */
void deleteLinkedList(linkedList *, unsigned long long);

/**
 * FUNCTION: changeElemLinkedList
 * INPUT: A dynamic list, a position (unsigned long long), and an element (float).
 * REQUIREMENTS: 0 <= position < lengthLinkedList(list).
 * MODIFIES: Change the value of the element at the position.
 */
void changeElemLinkedList(linkedList *, unsigned long long, float);

/**
 * FUNCTION: consultElemLinkedList
 * INPUT: A dynamic list, and a position (unsigned long long).
 * REQUIREMENTS: 0 <= position < lengthLinkedList(list).
 * OUTPUT: The element (float) at the position.
 */
float consultElemLinkedList(linkedList, unsigned long long);

/**
 * FUNCTION: lengthLinkedList
 * INPUT: A dynamic list.
 * REQUIREMENTS: None.
 * OUTPUT: The length of the dynamic list.
 */
unsigned long long lengthLinkedList(linkedList);

#endif