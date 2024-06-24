#ifndef _STATIC_QUEUE_H
#define _STATIC_QUEUE_H

/**
 * MODULE: staticQueue
 * FILE: staticQueue.h
 * VERSION: 1.0.0
 * HISTORICAL: Created by Eloy Urriens Arpal on 9/6/2024.
 * DESCRIPTION: This module implements the functionalities of a static queue.
 * CC: BY SA
 */

#include <stdbool.h>

#define LIMIT 1000

typedef struct {
    float elements[LIMIT];
    int pos_first, pos_last;
    int count_elements;
} staticQueue;

/**
 * FUNCTION: newStaticQueue
 * INPUT: None
 * REQUIREMENTS: None
 * OUTPUT: An empty static queue.
*/
void newStaticQueue(staticQueue *);

/**
 * FUNCTION: enqueueStaticQueue
 * INPUT: A queue and a number (float).
 * REQUIREMENTS: The queue had to be initialized and
 *      the queue doesn't have to be full.
 * MODIFIES: The back of the queue is the number.
*/
void enqueueStaticQueue(staticQueue *, float);

/**
 * FUNCTION: dequeueStaticQueue
 * INPUT: A queue.
 * REQUIREMENTS: The queue had to be initialized and
 *      the queue doesn't have to be empty.
 * MODIFIES: Delete the number at the front.
*/
void dequeueStaticQueue(staticQueue *);

/**
 * FUNCTION: firstStaticQueue
 * INPUT: A queue.
 * REQUIREMENTS: The queue had to be initialized and
 *      the queue doesn't have to be empty.
 * OUTPUT: The number at the front.
*/
float firstStaticQueue(staticQueue);

/**
 * FUNCTION: isEmptyStaticQueue
 * INPUT: A queue.
 * REQUIREMENTS: The queue had to be initialized.
 * OUTPUT: Empty queue <=> True
*/
bool isEmptyStaticQueue(staticQueue);

/**
 * FUNCTION: isFullStaticQueue
 * INPUT: A queue.
 * REQUIREMENTS: The queue had to be initialized.
 * OUTPUT: Full queue <=> True
*/
bool isFullStaticQueue(staticQueue);

#endif