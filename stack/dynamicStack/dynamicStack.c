/**
 * MODULE: dynamicStack
 * FILE: dynamicStack.c
 * VERSION: 1.0.0
 * HISTORICAL: Created by Eloy Urriens Arpal on 9/6/2024.
 * DESCRIPTION: This module implements the functionalities of a dynamic stack.
 * CC: BY SA
 */

#include "dynamicStack.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * FUNCTION: errorDynamicStack
 * INPUT: Error message.
 * REQUIREMENTS: None
 * MODIFIES: Finish the program.
*/
void errorDynamicStack(char error[]) {
    printf("\n\n\nERROR in the module dynamicStack: %s\n", error);
    while (true) {
        exit(-1);
    }
}

void newDynamicStack(dynamicStack *s) {
    *s = NULL;
}

void pushDynamicStack(dynamicStack *s, float n) {
    node *aux;

    aux = malloc(sizeof(node));
    if (aux == NULL) {
        errorDynamicStack("There isn't more memory to add an element to the stack.");
    }

    aux->element = n;
    aux->next = *s;
    *s = aux;
}

void popDynamicStack(dynamicStack *s) {
    if (isEmptyDynamicStack(*s)) {
        errorDynamicStack("Can't delete on a empty stack.");
    }

    node *aux;

    aux = (*s)->next;
    free(*s);
    *s = aux;
}

float topDynamicStack(dynamicStack s) {
    return s->element;
}

bool isEmptyDynamicStack(dynamicStack s) {
    return s == NULL;
}