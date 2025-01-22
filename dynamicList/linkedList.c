/**
 * MODULE: linkedList
 * FILE: linkedList.c
 * VERSION: 1.0.1
 * HISTORICAL: 
 *      Created by Eloy Urriens Arpal on 11/6/2024, version 1.0.0
 *      Modified by Eloy Urriens Arpal on 22/22/2025, version 1.0.1
 *          Some names are changed.
 * DESCRIPTION: This module is the implement of the linked list.
 * CC: BY SA
 */

#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * FUNCTION: errorLinkedList
 * INPUT: Error message.
 * REQUIREMENTS: None
 * MODIFIES: Finish the program.
*/
void errorLinkedList(char error[]) {
    printf("\n\n\nERROR in the module linkedList: %s\n", error);
    while (true) {
        exit(-1);
    }
}

/**
 * FUNCTION: newLinkedList
 * INPUT: None.
 * REQUIREMENTS: None.
 * OUTPUT: An empty dynamic list.
 */
void newLinkedList(linkedList *l) {
    l->first = NULL;
    l->last = NULL;
    l->n_elem = 0;
}

/**
 * FUNCTION: appendLinkedList
 * INPUT: A dynamic list and an element (float).
 * REQUIREMENTS: The length of dynamic list < 2^63 - 1
 * MODIFIES: Add the element (float) to the end of the dynamic list.
 */
void appendLinkedList(linkedList *l, float elem) {
    node *aux;

    unsigned long long lim = 9223372036854775807; // 2^63 - 1
    aux = malloc(sizeof(node));
    if (aux == NULL) {
        errorLinkedList("There isn't more memory to add an element to the list.");
    }
    else if (lengthLinkedList(*l) >= lim) {
        errorLinkedList("The list is too large.");
    }
    
    aux->element = elem;
    aux->next = NULL;
    if (lengthLinkedList(*l) == 0) {
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
 * REQUIREMENTS: lengthLinkedList(list) > 1 and 0 < position < lengthLinkedList(list)
 * OUTPUT: current = A pointer to the memory address of the node whose position is pos.
 *      previous = A pointer to the memory address of the previous node whose position is pos.
 */
void searchPos(node **current, node **previous, linkedList l, unsigned long long pos) {
    if (lengthLinkedList(l) <= 1) {
        errorLinkedList("A position can't be searched in an empty list or with one element.");
    }
    else if (pos <= 0 || pos >= lengthLinkedList(l)) {
        errorLinkedList("The position is out of range. The position can't be searched.");
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
 * FUNCTION: insertLinkedList
 * INPUT: A dynamic list, a position and an element (float).
 * REQUIREMENTS: 0 < length of dynamic list < 2^64, 0 <= position < length of dinamic list
 * MODIFIES: Add the element (float) at the position.
 */
void insertLinkedList(linkedList *l, unsigned long long pos, float elem) {
    if (lengthLinkedList(*l) == 0) {
        errorLinkedList("The element cannot be added at the position because the list is empty.");
    }
    else if (pos < 0 || pos >= lengthLinkedList(*l)) {
        errorLinkedList("The position is out of range. The element can't be added.");
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
 * FUNCTION: deleteLinkedList
 * INPUT: A dynamic list and a position (unsigned long long).
 * REQUIREMENTS: 0 <= position < lengthLinkedList(list) and lengthLinkedList(list) > 0
 * MODIFIES: Delete the element and the position.
 */
void deleteLinkedList(linkedList *l, unsigned long long pos) {
    if (lengthLinkedList(*l) == 0) {
        errorLinkedList("An element can't be deleted from an empty list.");
    }
    else if (pos < 0 || pos >= lengthLinkedList(*l)) {
        errorLinkedList("The position is out of range. The element can't be deleted.");
    }

    node *current, *previous;
    if (lengthLinkedList(*l) == 1) {
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
 * FUNCTION: changeElemLinkedList
 * INPUT: A dynamic list, a position (unsigned long long), and an element (float).
 * REQUIREMENTS: 0 <= position < lengthLinkedList(list) and lengthLinkedList(list) > 0
 * MODIFIES: Change the value of the element at the position.
 */
void changeElemLinkedList(linkedList *l, unsigned long long pos, float elem) {
    if (lengthLinkedList(*l) == 0) {
        errorLinkedList("An element can't be changed in an empty list.");
    }
    else if (pos < 0 || pos >= lengthLinkedList(*l)) {
        errorLinkedList("The position is out of range. The element can't be changed.");
    }

    node *current, *previous;
    if (lengthLinkedList(*l) == 1 || pos == 0) {
        (l->first)->element = elem;
    }
    else {
        searchPos(&current, &previous, *l, pos);
        current->element = elem;
    }
}

/**
 * FUNCTION: consultElemLinkedList
 * INPUT: A dynamic list, and a position (unsigned long long).
 * REQUIREMENTS: 0 <= position < lengthLinkedList(list) and lengthLinkedList(list) > 0
 * OUTPUT: The element (float) at the position.
 */
float consultElemLinkedList(linkedList l, unsigned long long pos) {
    if (lengthLinkedList(l) == 0) {
        errorLinkedList("An element can't be consulted in an empty list.");
    }
    else if (pos < 0 || pos >= lengthLinkedList(l)) {
        errorLinkedList("The position is out of range. The element can't be consulted.");
    }

    float elem;
    node *current, *previous;
    if (lengthLinkedList(l) == 1 || pos == 0) {
        elem = (l.first)->element;
    }
    else {
        searchPos(&current, &previous, l, pos);
        elem = current->element;
    }

    return elem;
}

/**
 * FUNCTION: lengthLinkedList
 * INPUT: A dynamic list.
 * REQUIREMENTS: None.
 * OUTPUT: The length of the dynamic list.
 */
unsigned long long lengthLinkedList(linkedList l) {
    return l.n_elem;
}