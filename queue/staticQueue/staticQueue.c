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

void newStaticQueue(staticQueue *q) {
    q->pos_first = 0;
    q->pos_last = 0;
    q->count_elements = 0;
}

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

float firstStaticQueue(staticQueue q) {
    return q.elements[q.pos_first];
}

bool isEmptyStaticQueue(staticQueue q) {
    return q.count_elements == 0;
}

bool isFullStaticQueue(staticQueue q) {
    return q.count_elements == LIMIT;
}