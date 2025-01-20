#ifndef _STATIC_STACK_H
#define _STATIC_STACK_H
/**
 * MODULE: staticStack
 * FILE: staticStack.h
 * VERSION: 1.0.0
 * HISTORICAL: Created by Eloy Urriens Arpal on 8/6/2024.
 * DESCRIPTION: This module implements the functionalities of a static stack.
 * CC: BY SA
*/

#include <stdbool.h>

#define LIMIT 1000

typedef struct {
    float elements[LIMIT];
    int pos_top;
} staticStack;

/**
 * FUNCTION: newStaticStack
 * INPUT: None
 * REQUIREMENTS: None
 * OUTPUT: An empty static stack.
*/
void newStaticStack(staticStack *);

/**
 * FUNCTION: pushStaticStack
 * INPUT: A stack and a number (float).
 * REQUIREMENTS: The stack had to be initialized and
 *      the stack doesn't have to be full.
 * MODIFIES: The top of the stack is the number.
*/
void pushStaticStack(staticStack *, float);

/**
 * FUNCTION: popStaticStack
 * INPUT: A stack.
 * REQUIREMENTS: The stack had to be initialized and
 *      the stack doesn't have to be empty.
 * MODIFIES: Delete the number at the top.
*/
void popStaticStack(staticStack *);

/**
 * FUNCTION: topStaticStack
 * INPUT: A stack.
 * REQUIREMENTS: The stack had to be initialized and
 *      the stack doesn't have to be empty.
 * OUTPUT: The number at the top.
*/
float topStaticStack(staticStack);

/**
 * FUNCTION: isEmptyStaticStack
 * INPUT: A stack.
 * REQUIREMENTS: The stack had to be initialized.
 * OUTPUT: Empty stack <=> True
*/
bool isEmptyStaticStack(staticStack);

/**
 * FUNCTION: isFullStaticStack
 * INPUT: A stack.
 * REQUIREMENTS: The stack had to be initialized.
 * OUTPUT: Full stack <=> True
*/
bool isFullStaticStack(staticStack);

#endif