/**
 * MODULE: dynamicList
 * FILE: dynamicList.c
 * VERSION: 1.0.0
 * HISTORICAL: Created by Eloy Urriens Arpal on 11/6/2024.
 * DESCRIPTION: This module is the implement of the dynamic list/vector/array.
 * CC: BY SA
 */

#include "dynamicList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * FUNCTION: errorDynamicList
 * INPUT: Error message.
 * REQUIREMENTS: None
 * MODIFIES: Finish the program.
*/
void errorDynamicList(char error[]) {
    printf("\n\n\nERROR in the module dynamicList: %s\n", error);
    while (true) {
        exit(-1);
    }
}

/**
 * FUNCTION: newDynamicList
 * INPUT: None.
 * REQUIREMENTS: None.
 * OUTPUT: An empty dynamic list.
 */
void newDynamicList(dynamicList *l) {
    l->first = NULL;
    l->last = NULL;
    l->n_elem = 0;
}

/**
 * FUNCTION: appendDynamicList
 * INPUT: A dynamic list and an element (float).
 * REQUIREMENTS: The length of dynamic list < 2^63 - 1
 * MODIFIES: Add the element (float) to the end of the dynamic list.
 */
void appendDynamicList(dynamicList *l, float elem) {
    node *aux;

    unsigned long long lim = 9223372036854775807; // 2^63 - 1
    aux = malloc(sizeof(node));
    if (aux == NULL) {
        errorDynamicList("There isn't more memory to add an element to the list.");
    }
    else if (lengthDynamicList(*l) >= lim) {
        errorDynamicList("The list is too large.");
    }
    
    aux->element = elem;
    aux->next = NULL;
    if (lengthDynamicList(*l) == 0) {
        l->first = aux;
        l->last = aux;
    }
    else {
        (l->last)->next = aux;
        l->last = aux;
    }

    l->n_elem = l->n_elem + 1;
}

/**
 * FUNCTION: searchPos
 * INPUT: A dynamic list and a position (unsigned long long).
 * REQUIREMENTS: lengthDynamicList(list) > 1 and 0 < position < lengthDynamicList(list)
 * OUTPUT: current = A pointer to the memory address of the node whose position is pos.
 *      previous = A pointer to the memory address of the previous node whose position is pos.
 */
void searchPos(node **current, node **previous, dynamicList l, unsigned long long pos) {
    if (lengthDynamicList(l) <= 1) {
        errorDynamicList("A position can't be searched in an empty list or with one element.");
    }
    else if (pos <= 0 || pos >= lengthDynamicList(l)) {
        errorDynamicList("The position is out of range. The position can't be searched.");
    }

    unsigned long long count;

    count = 1;
    *current = (l.first)->next;
    *previous = l.first;
    while ((*current)->next != NULL && count != pos) {
        *previous = *current;
        *current = (*current)->next;
        count++;
    }
}

/**
 * FUNCTION: insertDynamicList
 * INPUT: A dynamic list, a position and an element (float).
 * REQUIREMENTS: 0 < length of dynamic list < 2^64, 0 <= position < length of dinamic list
 * MODIFIES: Add the element (float) at the position.
 */
void insertDynamicList(dynamicList *l, unsigned long long pos, float elem) {
    if (lengthDynamicList(*l) == 0) {
        errorDynamicList("The element cannot be added at the position because the list is empty.");
    }
    else if (pos < 0 || pos >= lengthDynamicList(*l)) {
        errorDynamicList("The position is out of range. The element can't be added.");
    }

    node *aux, *current, *previous;

    aux = malloc(sizeof(node));
    aux->element = elem;
    if (pos == 0) {
        aux->next = l->first;
        l->first = aux;
    }
    else {
        searchPos(&current, &previous, *l, pos);
        previous->next = aux;
        aux->next = current;
    }
    l->n_elem = l->n_elem + 1;
}

/**
 * FUNCTION: deleteDynamicList
 * INPUT: A dynamic list and a position (unsigned long long).
 * REQUIREMENTS: 0 <= position < lengthDynamicList(list) and lengthDynamicList(list) > 0
 * MODIFIES: Delete the element and the position.
 */
void deleteDynamicList(dynamicList *l, unsigned long long pos) {
    if (lengthDynamicList(*l) == 0) {
        errorDynamicList("An element can't be deleted from an empty list.");
    }
    else if (pos < 0 || pos >= lengthDynamicList(*l)) {
        errorDynamicList("The position is out of range. The element can't be deleted.");
    }

    node *current, *previous;
    if (lengthDynamicList(*l) == 1) {
        free(l->first);
        l->first = NULL;
        l->last = NULL;
    }
    else {
        if (pos == 0) {
            current = l->first;
            l->first = (l->first)->next;
            free(current);
        }
        else {
            searchPos(&current, &previous, *l, pos);

            // Always pos = count. REQUIREMENTS and CHECKS
            previous->next = current->next;
            if (current->next == NULL) {
                l->last = previous;
            }
            free(current);
        }
    }
    l->n_elem = l->n_elem - 1;
}

/**
 * FUNCTION: changeElemDynamicList
 * INPUT: A dynamic list, a position (unsigned long long), and an element (float).
 * REQUIREMENTS: 0 <= position < lengthDynamicList(list) and lengthDynamicList(list) > 0
 * MODIFIES: Change the value of the element at the position.
 */
void changeElemDynamicList(dynamicList *l, unsigned long long pos, float elem) {
    if (lengthDynamicList(*l) == 0) {
        errorDynamicList("An element can't be changed in an empty list.");
    }
    else if (pos < 0 || pos >= lengthDynamicList(*l)) {
        errorDynamicList("The position is out of range. The element can't be changed.");
    }

    node *current, *previous;
    if (lengthDynamicList(*l) == 1 || pos == 0) {
        (l->first)->element = elem;
    }
    else {
        searchPos(&current, &previous, *l, pos);
        current->element = elem;
    }
}

/**
 * FUNCTION: consultElemDynamicList
 * INPUT: A dynamic list, and a position (unsigned long long).
 * REQUIREMENTS: 0 <= position < lengthDynamicList(list) and lengthDynamicList(list) > 0
 * OUTPUT: The element (float) at the position.
 */
float consultElemDynamicList(dynamicList l, unsigned long long pos) {
    if (lengthDynamicList(l) == 0) {
        errorDynamicList("An element can't be consulted in an empty list.");
    }
    else if (pos < 0 || pos >= lengthDynamicList(l)) {
        errorDynamicList("The position is out of range. The element can't be consulted.");
    }

    float elem;
    node *current, *previous;
    if (lengthDynamicList(l) == 1 || pos == 0) {
        elem = (l.first)->element;
    }
    else {
        searchPos(&current, &previous, l, pos);
        elem = current->element;
    }

    return elem;
}

/**
 * FUNCTION: lengthDynamicList
 * INPUT: A dynamic list.
 * REQUIREMENTS: None.
 * OUTPUT: The length of the dynamic list.
 */
unsigned long long lengthDynamicList(dynamicList l) {
    return l.n_elem;
}