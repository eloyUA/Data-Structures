/**
 * MODULE: dynamicQueue
 * FILE: dynamicQueue.c
 * VERSION: 1.0.0
 * HISTORICAL: Created by Eloy Urriens Arpal on 9/6/2024.
 * DESCRIPTION: This module implements the functionalities of a dynamic queue.
 * CC: BY SA
 */

#include "dynamicQueue.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * FUNCTION: errorDynamicQueue
 * INPUT: Error message.
 * REQUIREMENTS: None
 * MODIFIES: Finish the program.
*/
void errorDynamicQueue(char error[]) {
    printf("\n\n\nERROR in the module dynamicQueue: %s\n", error);
    while (true) {
        exit(-1);
    }
}

void newDynamicQueue(dynamicQueue *q) {
    q->first = NULL;
    q->last = NULL;
}

void enqueueDynamicQueue(dynamicQueue *q, float n) {
    node *aux;

    aux = malloc(sizeof(node));
    if (aux == NULL) {
        errorDynamicQueue("There isn't more memory to add an element to the queue.");
    }

    aux->element = n;
    aux->next = NULL;
    if (q->last == NULL) {
        q->last = aux;
        q->first = aux;
    }
    else {
        (q->last)->next = aux;
        q->last = aux;
    }
}

void dequeueDynamicQueue(dynamicQueue *q) {
    if (isEmptyDynamicQueue(*q)) {
        errorDynamicQueue("Can't dequeue an element from an empty queue.");
    }

    node *aux;

    aux = q->first;
    q->first = (q->first)->next;
    if (q->first == NULL) {
        q->last = NULL;
    }
    free(aux);
}

float firstDynamicQueue(dynamicQueue q) {
    return (q.first)->element;
}

bool isEmptyDynamicQueue(dynamicQueue q) {
    return q.first == NULL && q.last == NULL;
}