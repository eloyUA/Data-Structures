/**
 * MODULE: hashTable
 * FILE: hashTable.c
 * VERSION: 1.0.1
 * HISTORICAL: 
 *      Created by Eloy Urriens Arpal on 18/6/2024, version 1.0.0
 *      Modifies by Eloy Urriens Arpal on 22/1/2024, version 1.0.1:
 *          Some names have been changed.
 * DESCRIPTION: This module is the implement of a hashTable.
 * CC: BY SA
 */

#include "hashTable.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define FNV_OFFSET_BASIS 0xcbf29ce484222325
#define FNV_PRIME 0x100000001b3

/**
 * FUNCTION: errorHashTable
 * INPUT: A error message.
 * REQUIREMENTS: None.
 * MODIFIES: Exit the program.
 */
void errorHashTable(char error[]) {
    printf("\n\n\nERROR in the module hashTable: %s\n", error);
    while (true) {
        exit(-1);
    }
}

/**
 * FUNCTION: newHashTable
 * INPUT: None.
 * REQUIREMENTS: None.
 * OUTPUT: A hashTable.
 */
void newHashTable(HashTable d) {
    for (int i = 0; i < N; i++) {
        d[i] = NULL;
    }
}

/**
 * FUNCTION: hashFunctionFNV1
 * INPUT: A key.
 * REQUIREMENTS: None.
 * OUTPUT: A value (unsigned long long) associated to the key.
 */
unsigned long long hashFunctionFNV1(char key[]) {
    unsigned long long hash;

    hash = FNV_OFFSET_BASIS;
    for (int i = 0; i < strlen(key); i++) {
        hash = hash * FNV_PRIME;
        hash = hash^key[i];
    }

    return hash;
}

/**
 * FUNCTION: loadElemHashTable
 * INPUT: A hashTable, a key and a real number.
 * REQUIREMENTS: None.
 * MODIFIES: The element, whose key is key (char[]), is modificated or created by the
 *      new real number.
 */
void loadElemHashTable(HashTable d, char key[], float value) {
    unsigned long long pos;

    pos = hashFunctionFNV1(key) % N;
    if (d[pos] == NULL) {
        d[pos] = malloc(sizeof(node));
        strcpy(d[pos]->key, key);
        d[pos]->value = value;
        d[pos]->next = NULL;
    }
    else {
        node *aux;
        
        aux = d[pos];
        while (aux->next != NULL && strcmp(aux->key, key) != 0) {
            aux = aux->next;
        }

        if (strcmp(aux->key, key) != 0) {
            aux->next = malloc(sizeof(node));
            strcpy((aux->next)->key, key);
            (aux->next)->value = value;
            (aux->next)->next = NULL;
        }
        else {
            aux->value = value;
        }
    }
}

/**
 * FUNCTION: downloadElemHashTable
 * INPUT: A hashTable, a key.
 * REQUIREMENTS: The key must be associated with an element.
 * OUTPUT: The element (float) that is associated with the key.
 */
void downloadElemHashTable(HashTable d, char key[], float *value) {
    unsigned long long pos;

    pos = hashFunctionFNV1(key) % N;
    if (d[pos] == NULL) {
        errorHashTable("The key isn't associated with any value.");
    }
    else {
        node *aux;
        
        aux = d[pos];
        while (aux->next != NULL && strcmp(aux->key, key) != 0) {
            aux = aux->next;
        }

        if (strcmp(aux->key, key) != 0) {
            errorHashTable("The key isn't associated with any value.");
        }
        else {
            *value = aux->value;
        }
    }
}

/**
 * FUNCTION: deleteElemHashTable
 * INPUT: A hashTable, a key.
 * REQUIREMENTS: The key must be associated with an element.
 * MODIFIES: Delete the element that is associated with the key.
 */
void deleteElemHashTable(HashTable d, char key[]) {
    unsigned long long pos;

    pos = hashFunctionFNV1(key) % N;
    if (d[pos] == NULL) {
        errorHashTable("The key isn't associated with any value.");
    }
    else {
        if (d[pos]->next == NULL) {
            if (strcmp(d[pos]->key, key) != 0) {
                errorHashTable("The key isn't associated with any value.");
            }
            else {
                free(d[pos]);
                d[pos] = NULL;
            }
        }
        else {
            node *current, *previous;

            previous = d[pos];
            current = d[pos]->next;
            while (current->next != NULL && strcmp(current->key, key) != 0) {
                previous = current;
                current = current->next;
            }

            if (strcmp(current->key, key) != 0) {
                errorHashTable("The key isn't associated with any value.");
            }
            else {
                previous->next = current->next;
                free(current);
            }
        }
    }
}

/**
 * FUNCTION: isAssociated
 * INPUT: A hashTable, a key.
 * REQUIREMENTS: None.
 * OUTPUT: True <=> The key is associated with some value.
 */
bool isAssociated(HashTable d, char key[]) {
    bool associated;
    unsigned long long pos;

    pos = hashFunctionFNV1(key) % N;
    if (d[pos] == NULL) {
        associated = false;
    }
    else {
        node *aux;
        
        aux = d[pos];
        while (aux->next != NULL && strcmp(aux->key, key) != 0) {
            aux = aux->next;
        }
        associated = strcmp(aux->key, key) == 0;
    }

    return associated;
}