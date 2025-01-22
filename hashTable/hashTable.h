#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

/**
 * MODULE: hashTable
 * FILE: hashTable.h
 * VERSION: 1.0.1
 * HISTORICAL: 
 *      Created by Eloy Urriens Arpal on 18/6/2024, version 1.0.0
 *      Modifies by Eloy Urriens Arpal on 22/1/2024, version 1.0.1:
 *          Some names have been changed.
 * DESCRIPTION: This module is the implement of a hashTable.
 * CC: BY SA
 */

#define MAXLENGTHKEY 256
#define N 500009 // A prime

#include <stdbool.h>

typedef struct node {
    char key[MAXLENGTHKEY];
    float value;
    struct node *next;
} node;

typedef node *HashTable[N];

/**
 * FUNCTION: newHashTable
 * INPUT: None.
 * REQUIREMENTS: None.
 * OUTPUT: A hashTable.
 */
void newHashTable(HashTable);

/**
 * FUNCTION: loadElemHashTable
 * INPUT: A hashTable, a key and a real number.
 * REQUIREMENTS: None.
 * MODIFIES: The element, whose key is key (char[]), is modificated or created by the
 *      new real number.
 */
void loadElemHashTable(HashTable, char[], float);

/**
 * FUNCTION: downloadElemHashTable
 * INPUT: A hashTable, a key.
 * REQUIREMENTS: The key must be associated with an element.
 * OUTPUT: The element (float) that is associated with the key.
 */
void downloadElemHashTable(HashTable, char[], float *);

/**
 * FUNCTION: deleteElemHashTable
 * INPUT: A hashTable, a key.
 * REQUIREMENTS: The key must be associated with an element.
 * MODIFIES: Delete the element that is associated with the key.
 */
void deleteElemHashTable(HashTable, char []);

/**
 * FUNCTION: isAssociated
 * INPUT: A hashTable, a key.
 * REQUIREMENTS: None.
 * OUTPUT: True <=> The key is associated with some value.
 */
bool isAssociated(HashTable, char[]);

#endif