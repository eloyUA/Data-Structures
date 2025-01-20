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

/**
 * FUNCTION: newStaticStack
 * INPUT: None
 * REQUIREMENTS: None
 * OUTPUT: An empty static stack.
*/
void newStaticStack(staticStack *s) {
    s->pos_top = -1;
}

/**
 * FUNCTION: pushStaticStack
 * INPUT: A stack and a number (float).
 * REQUIREMENTS: The stack had to be initialized and
 *      the stack doesn't have to be full.
 * MODIFIES: The top of the stack is the number.
*/
void pushStaticStack(staticStack *s, float n) {
    if (isFullStaticStack(*s)) {
        errorStaticStack("Can't be push in a full stack.");
    }

    s->pos_top++;
    s->elements[s->pos_top] = n;
}

/**
 * FUNCTION: popStaticStack
 * INPUT: A stack.
 * REQUIREMENTS: The stack had to be initialized and
 *      the stack doesn't have to be empty.
 * MODIFIES: Delete the number at the top.
*/
void popStaticStack(staticStack *s) {
    if (isEmptyStaticStack(*s)) {
        errorStaticStack("Can't delete on a empty stack.");
    }

    s->pos_top--;
}

/**
 * FUNCTION: topStaticStack
 * INPUT: A stack.
 * REQUIREMENTS: The stack had to be initialized and
 *      the stack doesn't have to be empty.
 * OUTPUT: The number at the top.
*/
float topStaticStack(staticStack s) {
    return s.elements[s.pos_top];
}

/**
 * FUNCTION: isEmptyStaticStack
 * INPUT: A stack.
 * REQUIREMENTS: The stack had to be initialized.
 * OUTPUT: Empty stack <=> True
*/
bool isEmptyStaticStack(staticStack s) {
    return s.pos_top == -1;
}

/**
 * FUNCTION: isFullStaticStack
 * INPUT: A stack.
 * REQUIREMENTS: The stack had to be initialized.
 * OUTPUT: Full stack <=> True
*/
bool isFullStaticStack(staticStack s) {
    return s.pos_top == LIMIT - 1;
}