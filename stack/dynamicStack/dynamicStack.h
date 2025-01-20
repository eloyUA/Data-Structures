#ifndef _DYNAMIC_STACK_H
#define _DYNAMIC_STACK_H

/**
 * MODULE: dynamicStack
 * FILE: dynamicStack.h
 * VERSION: 1.0.0
 * HISTORICAL: Created by Eloy Urriens Arpal on 9/6/2024.
 * DESCRIPTION: This module implements the functionalities of a dynamic stack.
 * CC: BY SA
*/

#include <stdbool.h>

typedef struct node {
    float element;
    struct node *next;
} node;

typedef node *dynamicStack;

/**
 * FUNCTION: newDynamicStack
 * INPUT: None
 * REQUIREMENTS: None
 * OUTPUT: An empty dynamic stack.
*/
void newDynamicStack(dynamicStack *);

/**
 * FUNCTION: pushDynamicStack
 * INPUT: A stack and a number (float).
 * REQUIREMENTS: The stack had to be initialized.
 * MODIFIES: The top of the stack is the number.
*/
void pushDynamicStack(dynamicStack *, float);

/**
 * FUNCTION: popDynamicStack
 * INPUT: A stack.
 * REQUIREMENTS: The stack had to be initialized and
 *      the stack doesn't have to be empty.
 * MODIFIES: Delete the number at the top.
*/
void popDynamicStack(dynamicStack *);

/**
 * FUNCTION: topDynamicStack
 * INPUT: A stack.
 * REQUIREMENTS: The stack had to be initialized and
 *      the stack doesn't have to be empty.
 * OUTPUT: The number at the top.
*/
float topDynamicStack(dynamicStack);

/**
 * FUNCTION: isEmptyDynamicStack
 * INPUT: A stack.
 * REQUIREMENTS: The stack had to be initialized.
 * OUTPUT: Empty stack <=> True
*/
bool isEmptyDynamicStack(dynamicStack);

#endif