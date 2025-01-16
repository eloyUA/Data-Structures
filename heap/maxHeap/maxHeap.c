/**
 * MODULE: maxHeap
 * FILE: maxHeap.c
 * VERSION: 1.0.0
 * HISTORICAL: Created by Eloy Urriens on 16/1/2025
 * DESCRIPTION: This module is a max-heap. For more information: https://en.wikipedia.org/wiki/Min-max_heap
 * CC: SA BY
 */

#include "maxHeap.h"
#include <stdio.h>
#include <stdlib.h>

void errorMaxHeap(char *msg) {
    perror("ERROR in maxHeap.c: %s\n");
    exit(1);
}

/**
 * FUNCTION: newMaxHeap
 * INPUT: The maximum number of the elements in the maxHeap.
 * REQUIREMENTS: The int > 0.
 * OUTPUT: The empty maxHeap with maximum size (int).
 */
void newMaxHeap(MaxHeap *m, int maxN) {
    m->numbers = (typeElem *) (malloc(maxN * sizeof(typeElem)));
    if (m->numbers == NULL)
        errorMaxHeap("The maxHeap couldn't be created.");

    m->max_numbers = maxN;
    m->pos = -1;
}

/**
 * FUNCTION: insertElemMaxHeap
 * INPUT: The maxHeap and the element.
 * REQUIREMENTS: The maxHeap isn't full and the elem cannot be repeat.
 * OUTPUT: The maxHeap with the element.
 */
void insertElemMaxHeap(MaxHeap *m, typeElem elem) {
    if (isFullMaxHeap(*m))
        errorMaxHeap("The element couldn't be inserted because the maxHeap is full.");

    m->pos = m->pos + 1;
    m->numbers[m->pos] = elem;
    if (m->pos > 0) {
        typeElem auxElem;
        int posChild = m->pos;
        int posParent = (posChild - 1) / 2;
        while (posParent >= 0 && m->numbers[posChild] > m->numbers[posParent]) {
            auxElem = m->numbers[posParent];
            m->numbers[posParent] = m->numbers[posChild];
            m->numbers[posChild] = auxElem;

            posChild = posParent;
            posParent = (posChild - 1) / 2;
        }
    }
}

/**
 * FUNCTION: deleteElemMaxHeap
 * INPUT: The maxHeap and a element to delete.
 * REQUIREMENTS: The maxHeap isn't empty.
 * OUTPUT: The maxHeap without the element. (If it is).
 */
void deleteElemMaxHeap(MaxHeap *m, typeElem elem) {
    if (isEmptyMaxHeap(*m))
        errorMaxHeap("The element couldn't be deleted because the maxHeap is empty.");

    int posDelete = 0;
    while (posDelete < m->pos && m->numbers[posDelete] != elem) {
        posDelete++;
    }

    if (m->numbers[posDelete] != elem)
        return;

    if (m->pos == 0) {
        m->pos = m->pos - 1;
        return;
    }
    
    typeElem auxElem = m->numbers[m->pos];
    m->numbers[m->pos] = m->numbers[posDelete];
    m->numbers[posDelete] = auxElem;
    m->pos = m->pos - 1;

    int posElem = posDelete;
    int posParent = (posElem - 1) / 2;
    int posChildLeft = 2*posElem + 1, posChildRight = 2*posElem + 2;
    if (posParent >= 0 && m->numbers[posElem] > m->numbers[posParent]) {
        while (posParent >= 0 && m->numbers[posElem] < m->numbers[posParent]) {
            auxElem = m->numbers[posParent];
            m->numbers[posParent] = m->numbers[posElem];
            m->numbers[posElem] = auxElem;

            posElem = posParent;
            posParent = (posElem - 1) / 2;
        }
    }
    else if ((posChildLeft <= m->pos || posChildRight <= m->pos) && (m->numbers[posElem] < m->numbers[posChildLeft] || m->numbers[posElem] < m->numbers[posChildRight])) {
        int auxPos;
        while (posChildRight <= m->pos && (m->numbers[posElem] < m->numbers[posChildLeft] || m->numbers[posElem] < m->numbers[posChildRight])) {
            if (m->numbers[posChildLeft] < m->numbers[posChildRight]) {
                auxPos = posChildRight;
            }
            else {
                auxPos = posChildLeft;
            }

            auxElem = m->numbers[auxPos];
            m->numbers[auxPos] = m->numbers[posElem];
            m->numbers[posElem] = auxElem;

            posElem = auxPos;
            posChildLeft = 2*posElem + 1;
            posChildRight = 2*posElem + 2;
        }

        if (posChildRight > m->pos && posChildLeft <= m->pos && m->numbers[posElem] < m->numbers[posChildLeft]) {
            auxElem = m->numbers[posChildLeft];
            m->numbers[posChildLeft] = m->numbers[posElem];
            m->numbers[posElem] = auxElem;
        }
    }
}

/**
 * FUNCTION: rootMaxHeap
 * INTPUT: The maxHeap
 * REQUIREMENTS: The maxHeap isn't empty.
 * OUTPUT: The root of the maxHeap.
 */
typeElem rootMaxHeap(MaxHeap m) {
    if (isEmptyMaxHeap(m))
        errorMaxHeap("There isn't root in the maxHeap.");

    return m.numbers[0];
}

/**
 * FUNCTION: elemInMaxHeap
 * INPUT: The maxHeap and a element.
 * REQUIREMENTS: None
 * OUTPUT: True <=> The element is in the maxHeap
 */
bool elemInMaxHeap(MaxHeap m, typeElem elem) {
    int i = 0;
    while (i < m.pos && m.numbers[i] != elem) {
        i++;
    }

    return m.numbers[i] == elem;
}

/**
 * FUNCTION: numberElementsMaxHeap
 * INPUT: The maxHeap.
 * REQUIREMENTS: None.
 * OUTPUT: The number of the elements in maxHeap.
 */
int numberElementsMaxHeap(MaxHeap m) {
    return m.pos + 1;
}

/**
 * FUNCTION: isEmptyMaxHeap
 * INPUT: The maxHeap.
 * REQUIREMENTS: None
 * OUTPUT: True <=> The maxHeap is empty.
 */
bool isEmptyMaxHeap(MaxHeap m) {
    return m.pos == -1;
}

/**
 * FUNCTION: isFulMaxHeap
 * INPUT: The maxHeap.
 * REQUIREMENTS: None
 * OUTPUT: True <=> The maxHeap is full.
 */
bool isFullMaxHeap(MaxHeap m) {
    return m.pos + 1 == m.max_numbers;
}

void show(MaxHeap m) {
    for (int i = 0; i <= m.pos; i++) {
        printf("%d ", m.numbers[i]);
    }
}