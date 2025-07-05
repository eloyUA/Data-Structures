/**
 * MODULE: staticGraph
 * FILE: staticGraph.c
 * VERSION: 1.0.0
 * HISTORICAL: 
 *      Created by Eloy Urriens Arpal on 22/1/2025, version 1.0.0
 * DESCRIPTION: This module is the implement of the graph.
 * CC: BY SA
 */

#include "staticGraph.h"
#include <stdio.h>
#include <stdlib.h>

void errorStaticGraph(char *msgError) {
    char msg[512];
	snprintf(msg, sizeof(msg), "ERROR, in the module staticGraph: %s\n", msgError);
	perror(msg);
	exit(1);
}

void newStaticGraph(staticGraph *g, int maxVertices) {
    g->numberVerticesCurrently = 0;
    g->numberEdgesCurrently = 0;
    g->maximumVertices = maxVertices;
    g->vertices = (nodeVertex *) (malloc(maxVertices * sizeof(nodeVertex)));
    if (g->vertices == NULL)
        errorStaticGraph("There isn't memory in the system for reserved.");

    for (int i = 0; i < maxVertices; i++)
        g->vertices[i].exists = false;

    g->edges = (nodeEdge **) (malloc(maxVertices * sizeof(nodeEdge *)));
    if (g->edges == NULL)
        errorStaticGraph("There isn't memory in the system for reserved.");
    
    for (int i = 0; i < maxVertices; i++) {
        g->edges[i] = (nodeEdge *) (malloc((i + 1) * sizeof(nodeEdge)));
        if (g->edges[i] == NULL)
            errorStaticGraph("There isn't memory in the system for reserved.");
    }

    for (int i = 0; i < maxVertices; i++) {
        for (int j = 0; j < i + 1; j++)
            g->edges[i][j].exists = false;
    }
}

void addVertexStaticGraph(staticGraph *g, int idVertex) {
    if (idVertex < 0 || idVertex >= g->maximumVertices) {
        errorStaticGraph(
            "The vertex cannot be added because his id is out of range.");
    }
        
    if (g->vertices[idVertex].exists)
        errorStaticGraph("The vertex cannot be added because it already exists.");

    g->vertices[idVertex].exists = true;
    g->numberVerticesCurrently = g->numberVerticesCurrently + 1;
}

void removeVertexStaticGraph(staticGraph *g, int idVertex) {
    if (idVertex < 0 || idVertex >= g->maximumVertices) {
        errorStaticGraph(
            "The vertex cannot be removed because his id is out of range.");
    }

    if (!g->vertices[idVertex].exists)
        errorStaticGraph("The vertex cannot be removed because it doesn't exist.");

    for (int i = 0; i < g->maximumVertices; i++) {
        if (i < idVertex && g->edges[idVertex][i].exists) {
            g->edges[idVertex][i].exists = false;
            g->numberEdgesCurrently = g->numberEdgesCurrently - 1;
        }
        else if (i >= idVertex && g->edges[i][idVertex].exists){
            g->edges[i][idVertex].exists = false;
            g->numberEdgesCurrently = g->numberEdgesCurrently - 1;
        }
    }

    g->vertices[idVertex].exists = false;
    g->numberVerticesCurrently = g->numberVerticesCurrently - 1;
}

void setVertexValueStaticGraph(staticGraph *g, int idVertex, vertexValueType value) {
    if (idVertex < 0 || idVertex >= g->maximumVertices) {
        errorStaticGraph(
            "The value of the vertex cannot be set because idVertex is out of range.");
    }
        
    if (!g->vertices[idVertex].exists) {
        errorStaticGraph(
            "The value of the vertex cannot be set because the vertex doesn't exist.");
    }
    g->vertices[idVertex].value = value;
}

vertexValueType getVertexValueStaticGraph(staticGraph g, int idVertex) {
    if (idVertex < 0 || idVertex >= g.maximumVertices) {
        errorStaticGraph(
            "The value of the vertex cannot be returned because idVertex is out of range.");
    }   

    if (!g.vertices[idVertex].exists) {
        errorStaticGraph(
            "The value of the vertex cannot be returned because the vertex doesn't exist.");
    }
    return g.vertices[idVertex].value;
}

bool isThereVertexStaticGraph(staticGraph g, int idVertex) {
    if (idVertex < 0 || idVertex >= g.maximumVertices) {
        errorStaticGraph(
            "In the function isThereVertexStaticGraph (idVertex out of range)");
    }
    return g.vertices[idVertex].exists;
}

void addEdgeStaticGraph(staticGraph *g, int idVertexX, int idVertexY) {
    if (idVertexX < 0 || idVertexX >= g->maximumVertices ||
        idVertexY < 0 || idVertexY >= g->maximumVertices) {
        errorStaticGraph(
            "The edge cannot be added because yours id vertices out of range.");
    }
        
    if (idVertexX < idVertexY) {
        if (g->edges[idVertexY][idVertexX].exists)
            errorStaticGraph("The edge cannot be added because it already exists.");
        g->edges[idVertexY][idVertexX].exists = true;
    }
    else {
        if (g->edges[idVertexX][idVertexY].exists)
            errorStaticGraph("The edge cannot be added because it already exists.");
        g->edges[idVertexX][idVertexY].exists = true;
    }
    g->numberEdgesCurrently = g->numberEdgesCurrently + 1;
}

void removeEdgeStaticGraph(staticGraph *g, int idVertexX, int idVertexY) {
    if (idVertexX < 0 || idVertexX >= g->maximumVertices ||
        idVertexY < 0 || idVertexY >= g->maximumVertices) {
        errorStaticGraph(
            "The edge cannot be removed because yours id vertices out of range.");
    }

    if (idVertexX > idVertexY) {
        if (!g->edges[idVertexX][idVertexY].exists)
            errorStaticGraph("The edge cannot be removed because it doesn't exists.");
        g->edges[idVertexX][idVertexY].exists = false;
    }
    else {
        if (!g->edges[idVertexY][idVertexX].exists)
            errorStaticGraph("The edge cannot be removed because it doesn't exists.");
        g->edges[idVertexY][idVertexX].exists = false;
    }
    g->numberEdgesCurrently = g->numberEdgesCurrently - 1;
}

void setEdgeValueStaticGraph(staticGraph *g, int idVertexX, int idVertexY, edgeValueType value) {
    if (idVertexX < 0 || idVertexX >= g->maximumVertices ||
        idVertexY < 0 || idVertexY >= g->maximumVertices) {
        errorStaticGraph(
            "The value of the edge cannot be set because their id vertex are out of range.");
    }

    if (idVertexX > idVertexY) {
        if (!g->edges[idVertexX][idVertexY].exists)
            errorStaticGraph("The edge cannot be set because it doesn't exists.");
        g->edges[idVertexX][idVertexY].value = value;
    }
    else {
        if (!g->edges[idVertexY][idVertexX].exists)
            errorStaticGraph("The edge cannot be set because it doesn't exists.");
        g->edges[idVertexY][idVertexX].value = value;
    }
}

edgeValueType getEdgeValueStaticGraph(staticGraph g, int idVertexX, int idVertexY) {
    if (idVertexX < 0 || idVertexX >= g.maximumVertices ||
        idVertexY < 0 || idVertexY >= g.maximumVertices) {
        errorStaticGraph(
            "The value of the edge cannot be returned because their id vertex are out of range.");
    }

    if (idVertexX > idVertexY) {
        if (!g.edges[idVertexX][idVertexY].exists)
            errorStaticGraph("The edge cannot be returned because it doesn't exists.");
        return g.edges[idVertexX][idVertexY].value;
    }
    else {
        if (!g.edges[idVertexY][idVertexX].exists)
            errorStaticGraph("The edge cannot be returned because it doesn't exists.");
        return g.edges[idVertexY][idVertexX].value;
    }
}

bool isThereEdgeStaticGraph(staticGraph g, int idVertexX, int idVertexY) {
    if (idVertexX < 0 || idVertexX >= g.maximumVertices ||
        idVertexY < 0 || idVertexY >= g.maximumVertices) {
            errorStaticGraph(
                "The value of the edge cannot be returned because their id vertex are out of range.");
    }

    if (idVertexX > idVertexY)
        return g.edges[idVertexX][idVertexY].exists;

    return g.edges[idVertexY][idVertexX].exists;
}

bool isFullStaticGraph(staticGraph g) {
    return g.maximumVertices == g.numberVerticesCurrently;
}

int getMaximumNumberVerticesStaticGraph(staticGraph g) {
    return g.maximumVertices;
}

int getNumberOfVerticesCurrentlyStaticGraph(staticGraph g) {
    return g.numberVerticesCurrently;
}

int getNumberOfEdgesCurrentlyStaticGraph(staticGraph g) {
    return g.numberEdgesCurrently;
}

void getNeighborsStaticGraph(int *nNeighbors,  int *neighbors, int maxNeighbors,
                            staticGraph g, int idVertex) {
    if (maxNeighbors < g.numberVerticesCurrently) {
        errorStaticGraph("In the function getNeighborsStaticGraph.");
    }

    int i = 0;
    *nNeighbors = 0;
    while (i < g.maximumVertices) {
        if (i < idVertex && g.edges[idVertex][i].exists) {
            neighbors[*nNeighbors] = i;
            *nNeighbors = *nNeighbors + 1;
        }
        else if (i >= idVertex && g.edges[i][idVertex].exists) {
            neighbors[*nNeighbors] = i;
            *nNeighbors = *nNeighbors + 1;
        }
        i++;
    }
}

void freeMemoryStaticGraph(staticGraph *g) {
    free(g->vertices);
    for (int i = 0; i < g->maximumVertices; i++)
        free(g->edges[i]);
    free(g->edges);
}

bool isConnectedStaticGraph(staticGraph g) {
    // Trivial cases
    if (getNumberOfVerticesCurrentlyStaticGraph(g) == 0 ||
        getNumberOfVerticesCurrentlyStaticGraph(g) == 1) {
        return true;
    }

    if (getNumberOfVerticesCurrentlyStaticGraph(g) > 0 &&
        getNumberOfEdgesCurrentlyStaticGraph(g) == 0) {
            return false;
    }

    // Reserves (array neighbors, queue and auxGraph)
    int vertices = getNumberOfVerticesCurrentlyStaticGraph(g);
    int *neighbors = (int *) (malloc(vertices * sizeof(int)));
    if (neighbors == NULL)
        errorStaticGraph("There isn't memory in the system for reserved.");
    
    int start = 0, end = 0;
    int *queueIdsVertices = (int *) (malloc(vertices * sizeof(int)));
    if (queueIdsVertices == NULL)
        errorStaticGraph("There isn't memory in the system for reserved.");

    staticGraph auxGraph;
    newStaticGraph(&auxGraph, getMaximumNumberVerticesStaticGraph(g));

    // The first vertex is found and it is added to auxGraph and the queue
    int firstIdVertex = 0;
    while (firstIdVertex < getMaximumNumberVerticesStaticGraph(g) - 1 &&
        !isThereVertexStaticGraph(g, firstIdVertex)) {
        firstIdVertex++;
    }   

    addVertexStaticGraph(&auxGraph, firstIdVertex);
    queueIdsVertices[end] = firstIdVertex;
    end++;

    // The queue is processed with g and auxGraph
    int i;
    int nNeighbors;
    do {
        getNeighborsStaticGraph(
            neighbors,
            &nNeighbors,
            getNumberOfVerticesCurrentlyStaticGraph(g),
            g,
            queueIdsVertices[start]
        );

        for (i = 0; i < nNeighbors; i++) {
            if (!isThereVertexStaticGraph(auxGraph, neighbors[i])) {
                addVertexStaticGraph(&auxGraph, neighbors[i]);
                queueIdsVertices[end] = neighbors[i];
                end++;
            }
        }
        start++;
    } while (start != end);

    int v1 = getNumberOfVerticesCurrentlyStaticGraph(auxGraph);
    int v2 = getNumberOfVerticesCurrentlyStaticGraph(g);
    bool b = v1 == v2;

    free(neighbors);
    free(queueIdsVertices);
    freeMemoryStaticGraph(&auxGraph);
    return b;
}