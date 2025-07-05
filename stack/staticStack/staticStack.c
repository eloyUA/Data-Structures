/**
 * MODULE: staticStack
 * FILE: staticStack.c
 * VERSION: 1.0.0
 * HISTORICAL: Created by Eloy Urriens Arpal on 8/6/2024.
 * DESCRIPTION: This module implements the functionalities of a static stack.
 * CC: BY SA
*/

#include "staticStack.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * FUNCTION: errorStaticStack
 * INPUT: Error message.
 * REQUIREMENTS: None
 * MODIFIES: Finish the program.
*/
void errorStaticStack(char error[]) {
    printf("\n\n\nERROR in the module staticStack: %s\n", error);
    while (true) {
        exit(-1);
    }
}

void newStaticStack(staticStack *s) {
    s->pos_top = -1;
}

void pushStaticStack(staticStack *s, float n) {
    if (isFullStaticStack(*s)) {
        errorStaticStack("Can't be push in a full stack.");
    }

    s->pos_top++;
    s->elements[s->pos_top] = n;
}

void popStaticStack(staticStack *s) {
    if (isEmptyStaticStack(*s)) {
        errorStaticStack("Can't delete on a empty stack.");
    }

    s->pos_top--;
}

float topStaticStack(staticStack s) {
    return s.elements[s.pos_top];
}

bool isEmptyStaticStack(staticStack s) {
    return s.pos_top == -1;
}

bool isFullStaticStack(staticStack s) {
    return s.pos_top == LIMIT - 1;
}