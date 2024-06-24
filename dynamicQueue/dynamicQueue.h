#ifndef _DYNAMIC_QUEUE_H
#define _DYNAMIC_QUEUE_H

/**
 * MODULE: dynamicQueue
 * FILE: dynamicQueue.h
 * VERSION: 1.0.0
 * HISTORICAL: Created by Eloy Urriens Arpal on 9/6/2024.
 * DESCRIPTION: This module implements the functionalities of a dynamic queue.
 * CC: BY SA
 */

#include <stdbool.h>

typedef struct node {
    float element;
    struct node *next;
} node;

typedef struct {
    node *first;
    node *last;
} dynamicQueue;

/**
 * FUNCTION: newDynamicQueue
 * INPUT: None
 * REQUIREMENTS: None
 * OUTPUT: An empty dynamic queue.
*/
void newDynamicQueue(dynamicQueue *);

/**
 * FUNCTION: enqueueDynamicQueue
 * INPUT: A queue and a number (float).
 * REQUIREMENTS: The queue had to be initialized.
 * MODIFIES: The back of the queue is the number.
*/
void enqueueDynamicQueue(dynamicQueue *, float);

/**
 * FUNCTION: dequeueDynamicQueue
 * INPUT: A queue.
 * REQUIREMENTS: The queue had to be initialized and
 *      the queue doesn't have to be empty.
 * MODIFIES: Delete the number at the front.
*/
void dequeueDynamicQueue(dynamicQueue *);

/**
 * FUNCTION: first
 * INPUT: A queue.
 * REQUIREMENTS: The queue had to be initialized and
 *      the queue doesn't have to be empty.
 * OUTPUT: The number at the front.
*/
float firstDynamicQueue(dynamicQueue);

/**
 * FUNCTION: isEmpty
 * INPUT: A queue.
 * REQUIREMENTS: The queue had to be initialized.
 * OUTPUT: Empty queue <=> True
*/
bool isEmptyDynamicQueue(dynamicQueue);

#endif