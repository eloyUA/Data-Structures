#ifndef _DICTIONARY_H
#define _DICTIONARY_H

/**
 * MODULE: dictionary
 * FILE: dictionary.h
 * VERSION: 1.0.0
 * HISTORICAL: Created by Eloy Urriens Arpal on 18/6/2024
 * DESCRIPTION: This module is the implement of a dictionary.
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

typedef node *Dictionary[N];

/**
 * FUNCTION: newDictionary
 * INPUT: None.
 * REQUIREMENTS: None.
 * OUTPUT: A dictionary.
 */
void newDictionary(Dictionary);

/**
 * FUNCTION: loadElemDictionary
 * INPUT: A dictionary, a key and a real number.
 * REQUIREMENTS: None.
 * MODIFIES: The element, whose key is key (char[]), is modificated or created by the
 *      new real number.
 */
void loadElemDictionary(Dictionary, char[], float);

/**
 * FUNCTION: downloadElemDictionary
 * INPUT: A dictionary, a key.
 * REQUIREMENTS: The key must be associated with an element.
 * OUTPUT: The element (float) that is associated with the key.
 */
void downloadElemDictionary(Dictionary, char[], float *);

/**
 * FUNCTION: deleteElemDictionary
 * INPUT: A dictionary, a key.
 * REQUIREMENTS: The key must be associated with an element.
 * MODIFIES: Delete the element that is associated with the key.
 */
void deleteElemDictionary(Dictionary, char []);

/**
 * FUNCTION: isAssociated
 * INPUT: A dictionary, a key.
 * REQUIREMENTS: None.
 * OUTPUT: True <=> The key is associated with some value.
 */
bool isAssociated(Dictionary, char[]);

#endif