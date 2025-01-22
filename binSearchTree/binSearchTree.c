/**
 * MODULE: binSearchTree
 * FILE: binSearchTree.c
 * VERSION: 1.0.0
 * HISTORICAL: 
 *      Created by Eloy Urriens Arpal on 18/1/2025, version 1.0.0
 * DESCRIPTION: This module is the implement of the binary search tree.
 * CC: BY SA
 */

#include "binSearchTree.h"
#include <stdio.h>
#include <stdlib.h>

void errorBinSearchTree(char *msgError) {
    char msg[512];
	snprintf(msg, sizeof(msg), "ERROR, in the module binSearchTree: %s", msgError);
	perror(msg);
	exit(1);
}

/**
 * FUNCTION: newBinSearchTree
 * OUTPUT: A binSearchTree.
 */
void newBinSearchTree(BinSearchTree *t) {
    *t = NULL;
}

/**
 * FUNCTION: insertBinSearchTree
 * INPUT: A binSearchTree and an element.
 * OUTPUT: The binSearchTree with the element.
 */
void insertBinSearchTree(BinSearchTree *t, typeElem elem) {
    if (isEmptyBinSearchTree(*t)) {
        nodeBinSearchTree *auxNode = (nodeBinSearchTree *) (malloc(sizeof(nodeBinSearchTree)));
        if (auxNode == NULL)
            errorBinSearchTree("The element cannot be inserted because there isn't more memory in the system.");

        auxNode->elem = elem;
        auxNode->leftTree = NULL;
        auxNode->rightTree = NULL;

        (*t) = auxNode;
    }
    else {
        if ((*t)->elem > elem) {
            insertBinSearchTree(&((*t)->leftTree), elem);
        }
        else if ((*t)->elem < elem) {
            insertBinSearchTree(&((*t)->rightTree), elem);
        }
    }
}

/**
 * FUNCTION: deleteBinSearchTree
 * INPUT: A binSearchTree and an element.
 * REQUIREMENTS: The binSearchTree isn't empty.
 * OUTPUT: The binSearchTree without the element. (If the element is in the binSearchTree)
 */
void deleteBinSearchTree(BinSearchTree *t, typeElem elem) {
    if (isEmptyBinSearchTree(*t)) {
        
    }
    else {
        if ((*t)->elem > elem) {
            deleteBinSearchTree(&((*t)->leftTree), elem);
        }
        else if ((*t)->elem < elem) {
            deleteBinSearchTree(&((*t)->rightTree), elem);
        }
        else {
            if (isEmptyBinSearchTree((*t)->leftTree) && isEmptyBinSearchTree((*t)->rightTree)) { // Without child
                free(*t);
                *t = NULL;
            }
            else if (isEmptyBinSearchTree((*t)->leftTree)) { // Only right child
                nodeBinSearchTree *auxNode = *t;
                *t = (*t)->rightTree;
                free(auxNode);   
            }
            else if (isEmptyBinSearchTree((*t)->rightTree)) { // Only left child
                nodeBinSearchTree *auxNode = *t;
                *t = (*t)->leftTree;
                free(auxNode);
            }
            else { // Two childs
                if (isEmptyBinSearchTree(((*t)->rightTree)->leftTree)) {
                    nodeBinSearchTree *auxNode = *t;
                    *t = (*t)->rightTree;
                    (*t)->leftTree = auxNode->leftTree;
                    free(auxNode);
                }
                else {
                    nodeBinSearchTree **aux, *auxNode;
                    aux = &((*t)->rightTree);
                    while(!isEmptyBinSearchTree((*aux)->leftTree))
                        aux = &((*aux)->leftTree);
                    
                    auxNode = *t;
                    *t = *aux;
                    *aux = NULL;

                    (*t)->leftTree = auxNode->leftTree;
                    (*t)->rightTree = auxNode->rightTree;
                    free(auxNode);
                }
            }
        }
    }
}

/**
 * FUNCTION: searchInBinSearchTree
 * INPUT: A binSearchTree and an element.
 * OUTPUT: True <=> element is in the tree
 */
bool searchInBinSearchTree(BinSearchTree t, typeElem elem) {
    bool searched;
    if (isEmptyBinSearchTree(t)) {
        searched = false;
    }
    else {
        if (t->elem > elem) {
            searched = searchInBinSearchTree(t->leftTree, elem);
        }
        else if (t->elem < elem) {
            searched = searchInBinSearchTree(t->rightTree, elem);
        }
        else {
            searched = true;
        }
    }
    return searched;
}

/**
 * FUNCTION: rootBinSearchTree
 * INPUT: A binSearchTree
 * REQUIREMENTS: The tree cannot be empty.
 * OUTPUT: The root of the tree.
 */
typeElem rootBinSearchTree(BinSearchTree t) {
    if (isEmptyBinSearchTree(t))
        errorBinSearchTree("There isn't root in a empty tree.");

    return t->elem;
}

/**
 * FUNCTION: leftChildBinSearchTree
 * INPUT: A binSearchTree.
 * REQUIREMENTS: The binSearchTree isn't empty.
 * OUTPUT: The left child of the binSearchTree. (ISN'T TO COPY, therefore if
 *      the returned tree is modified, then the binSheachTree changes)
 */
BinSearchTree* leftChildBinSearchTree(BinSearchTree t) {
    if (isEmptyBinSearchTree(t))
        errorBinSearchTree("There isn't left child in a empty tree.");

    return &(t->leftTree);
}

/**
 * FUNCTION: rightChildBinSearchTree
 * INPUT: A binSearchTree.
 * REQUIREMENTS: The binSearchTree isn't empty.
 * OUTPUT: The right child of the binSearchTree. (ISN'T TO COPY, therefore if
 *      the returned tree is modified, then the binSheachTree changes)
 */
BinSearchTree* rightChildBinSearchTree(BinSearchTree t) {
    if (isEmptyBinSearchTree(t))
        errorBinSearchTree("There isn't right child in a empty tree.");

    return &(t->rightTree);
}

/**
 * FUNCTION: isEmptyBinSearchTree
 * INPUT: A binSearchTree
 * OUTPUT: True <=> In the tree there aren't elements.
 */
bool isEmptyBinSearchTree(BinSearchTree t) {
    return t == NULL;
}