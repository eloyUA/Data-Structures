/**
 * MODULE: minHeap
 * FILE: minHeap.c
 * VERSION: 1.0.0
 * HISTORICAL: Created by Eloy Urriens on 16/1/2025
 * DESCRIPTION: This module is a min-heap.
 *      For more information:https://en.wikipedia.org/wiki/Min-max_heap
 * CC: SA BY
 */

#include "minHeap.h"
#include <stdio.h>
#include <stdlib.h>

void errorMinHeap(char *msgError) {
    char msg[512];
	snprintf(msg, sizeof(msg), "ERROR, in the module minHeap: %s", msgError);
	perror(msg);
	exit(1);
}

void newMinHeap(MinHeap *m, int maxN) {
    m->numbers = (typeElem *) (malloc(maxN * sizeof(typeElem)));
    if (m->numbers == NULL)
        errorMinHeap("The minHeap couldn't be created.");

    m->max_numbers = maxN;
    m->pos = -1;
}

void insertElemMinHeap(MinHeap *m, typeElem elem) {
    if (isFullMinHeap(*m))
        errorMinHeap("The element couldn't be inserted because the minHeap is full.");

    m->pos = m->pos + 1;
    m->numbers[m->pos] = elem;
    if (m->pos > 0) {
        typeElem auxElem;
        int posChild = m->pos;
        int posParent = (posChild - 1) / 2;
        while (posParent >= 0 && m->numbers[posChild] < m->numbers[posParent]) {
            auxElem = m->numbers[posParent];
            m->numbers[posParent] = m->numbers[posChild];
            m->numbers[posChild] = auxElem;

            posChild = posParent;
            posParent = (posChild - 1) / 2;
        }
    }
}

void deleteElemMinHeap(MinHeap *m, typeElem elem) {
    if (isEmptyMinHeap(*m))
        errorMinHeap("The element couldn't be deleted because the minHeap is empty.");

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
    if (posParent >= 0 && m->numbers[posElem] < m->numbers[posParent]) {
        while (posParent >= 0 && m->numbers[posElem] < m->numbers[posParent]) {
            auxElem = m->numbers[posParent];
            m->numbers[posParent] = m->numbers[posElem];
            m->numbers[posElem] = auxElem;

            posElem = posParent;
            posParent = (posElem - 1) / 2;
        }
    }
    else if ((posChildLeft <= m->pos || posChildRight <= m->pos) &&
        (m->numbers[posElem] > m->numbers[posChildLeft] ||
        m->numbers[posElem] > m->numbers[posChildRight])) {

        int auxPos;
        while (posChildRight <= m->pos &&
            (m->numbers[posElem] > m->numbers[posChildLeft] ||
            m->numbers[posElem] > m->numbers[posChildRight])) {
                    
            if (m->numbers[posChildLeft] > m->numbers[posChildRight]) {
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

        if (posChildRight > m->pos && posChildLeft <= m->pos &&
            m->numbers[posElem] > m->numbers[posChildLeft]) {

            auxElem = m->numbers[posChildLeft];
            m->numbers[posChildLeft] = m->numbers[posElem];
            m->numbers[posElem] = auxElem;
        }
    }
}

typeElem rootMinHeap(MinHeap m) {
    if (isEmptyMinHeap(m))
        errorMinHeap("There isn't root in the minHeap.");

    return m.numbers[0];
}

bool elemInMinHeap(MinHeap m, typeElem elem) {
    int i = 0;
    while (i < m.pos && m.numbers[i] != elem) {
        i++;
    }

    return m.numbers[i] == elem;
}

int numberElementsMinHeap(MinHeap m) {
    return m.pos + 1;
}

bool isEmptyMinHeap(MinHeap m) {
    return m.pos == -1;
}

bool isFullMinHeap(MinHeap m) {
    return m.pos + 1 == m.max_numbers;
}