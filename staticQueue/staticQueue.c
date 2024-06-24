/**
 * MODULE: staticQueue
 * FILE: staticQueue.h
 * VERSION: 1.0.0
 * HISTORICAL: Created by Eloy Urriens Arpal on 9/6/2024.
 * DESCRIPTION: This module implements the functionalities of a static queue.
 * CC: BY SA
 */

#include "staticQueue.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * FUNCTION: errorStaticQueue
 * INPUT: Error message.
 * REQUIREMENTS: None
 * MODIFIES: Finish the program.
*/
void errorStaticQueue(char error[]) {
    printf("\n\n\nERROR in the module staticQueue: %s\n", error);
    while (true) {
        exit(-1);
    }
}

/**
 * FUNCTION: newStaticQueue
 * INPUT: None
 * REQUIREMENTS: None
 * OUTPUT: An empty static queue.
*/
void newStaticQueue(staticQueue *q) {
    q->pos_first = 0;
    q->pos_last = 0;
    q->count_elements = 0;
}

/**
 * FUNCTION: enqueueStaticQueue
 * INPUT: A queue and a number (float).
 * REQUIREMENTS: The queue had to be initialized and
 *      the queue doesn't have to be full.
 * MODIFIES: The back of the queue is the number.
*/
void enqueueStaticQueue(staticQueue *q, float n) {
    if (isFullStaticQueue(*q)) {
        errorStaticQueue("Can't enqueue in a full queue.");
    }

    q->elements[q->pos_last] = n;
    q->pos_last = q->pos_last + 1;
    if (q->pos_last == LIMIT) {
        q->pos_last = 0;
    }
    q->count_elements = q->count_elements + 1;
}

/**
 * FUNCTION: dequeueStaticQueue
 * INPUT: A queue.
 * REQUIREMENTS: The queue had to be initialized and
 *      the queue doesn't have to be empty.
 * MODIFIES: Delete the number at the front.
*/
void dequeueStaticQueue(staticQueue *q) {
    if (isEmptyStaticQueue(*q)) {
        errorStaticQueue("Can't delete on an empty queue.");
    }

    q->pos_first = q->pos_first + 1;
    if (q->pos_first == LIMIT) {
        q->pos_first = 0;
    }
    q->count_elements = q->count_elements - 1;
}

/**
 * FUNCTION: firstStaticQueue
 * INPUT: A queue.
 * REQUIREMENTS: The queue had to be initialized and
 *      the queue doesn't have to be empty.
 * OUTPUT: The number at the front.
*/
float firstStaticQueue(staticQueue q) {
    return q.elements[q.pos_first];
}

/**
 * FUNCTION: isEmptyStaticQueue
 * INPUT: A queue.
 * REQUIREMENTS: The queue had to be initialized.
 * OUTPUT: Empty queue <=> True
*/
bool isEmptyStaticQueue(staticQueue q) {
    return q.count_elements == 0;
}

/**
 * FUNCTION: isFullStaticQueue
 * INPUT: A queue.
 * REQUIREMENTS: The queue had to be initialized.
 * OUTPUT: Full queue <=> True
*/
bool isFullStaticQueue(staticQueue q) {
    return q.count_elements == LIMIT;
}