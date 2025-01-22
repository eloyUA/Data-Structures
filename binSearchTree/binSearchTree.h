#ifndef _BIN_SEARCH_TREE_H
#define _BIN_SEARCH_TREE_H

/**
 * MODULE: binSearchTree
 * FILE: binSearchTree.h
 * VERSION: 1.0.0
 * HISTORICAL: 
 *      Created by Eloy Urriens Arpal on 18/1/2025, version 1.0.0
 * DESCRIPTION: This module is the implement of the binary search tree.
 * CC: BY SA
 */

#include <stdbool.h>

typedef int typeElem; // It has to be a number
typedef struct nodeBinSearchTree {
    typeElem elem;
    struct nodeBinSearchTree *leftTree;
    struct nodeBinSearchTree *rightTree;
} nodeBinSearchTree;
typedef nodeBinSearchTree *BinSearchTree;

/**
 * FUNCTION: newBinSearchTree
 * OUTPUT: A binSearchTree.
 */
void newBinSearchTree(BinSearchTree *);

/**
 * FUNCTION: insertBinSearchTree
 * INPUT: A binSearchTree and an element.
 * OUTPUT: The binSearchTree with the element.
 */
void insertBinSearchTree(BinSearchTree *, typeElem);

/**
 * FUNCTION: deleteBinSearchTree
 * INPUT: A binSearchTree and an element.
 * REQUIREMENTS: The binSearchTree isn't empty.
 * OUTPUT: The binSearchTree without the element. (If the element is in the binSearchTree)
 */
void deleteBinSearchTree(BinSearchTree *, typeElem);

/**
 * FUNCTION: searchInBinSearchTree
 * INPUT: A binSearchTree and an element.
 * OUTPUT: True <=> element is in the tree
 */
bool searchInBinSearchTree(BinSearchTree, typeElem);

/**
 * FUNCTION: rootBinSearchTree
 * INPUT: A binSearchTree
 * REQUIREMENTS: The tree cannot be empty.
 * OUTPUT: The root of the tree.
 */
typeElem rootBinSearchTree(BinSearchTree);

/**
 * FUNCTION: leftChildBinSearchTree
 * INPUT: A binSearchTree.
 * REQUIREMENTS: The binSearchTree isn't empty.
 * OUTPUT: The left child of the binSearchTree. (ISN'T TO COPY, therefore if
 *      the returned tree is modified, then the binSheachTree changes)
 */
BinSearchTree* leftChildBinSearchTree(BinSearchTree);

/**
 * FUNCTION: rightChildBinSearchTree
 * INPUT: A binSearchTree.
 * REQUIREMENTS: The binSearchTree isn't empty.
 * OUTPUT: The right child of the binSearchTree. (ISN'T TO COPY, therefore if
 *      the returned tree is modified, then the binSheachTree changes)
 */
BinSearchTree* rightChildBinSearchTree(BinSearchTree);

/**
 * FUNCTION: isEmptyBinSearchTree
 * INPUT: A binSearchTree
 * OUTPUT: True <=> In the tree there aren't elements.
 */
bool isEmptyBinSearchTree(BinSearchTree);

#endif