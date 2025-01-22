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

/**
 * FUNCTION: newStaticGraph
 * INPUT: The maximum number of vertices (int).
 * OUTPUT: A staticGraph with 0 vertices and 0 edges.
 */
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

/**
 * FUNCTION: addVertexStaticGraph
 * INPUT: The graph and the id vertex.
 * REQUIREMENTS: 
 *      The id vertex has to be unique (The vertex doesn't exist yet)
 *      0 <= id vertex < maximum number of vertices
 *      The number of the vertices currently < The maximum number of the vertices in the graph (The graph isn't full)
 * OUTPUT: The graph with the vertex.
 */
void addVertexStaticGraph(staticGraph *g, int idVertex) {
    if (idVertex < 0 || idVertex >= g->maximumVertices)
        errorStaticGraph("The vertex cannot be added because his id is out of range.");

    if (g->vertices[idVertex].exists)
        errorStaticGraph("The vertex cannot be added because it already exists.");

    g->vertices[idVertex].exists = true;
    g->numberVerticesCurrently = g->numberVerticesCurrently + 1;
}

/**
 * FUNCTION: removeVertexStaticGraph
 * INPUT: A staticGraph and id vertex
 * REQUIREMENTS:
 *      The vertex has to exist.
 *      0 <= id vertex < maximum number of vertices
 * MODIFIES: The vertex with id (int) is removed
 */
void removeVertexStaticGraph(staticGraph *g, int idVertex) {
    if (idVertex < 0 || idVertex >= g->maximumVertices)
        errorStaticGraph("The vertex cannot be removed because his id is out of range.");

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

/**
 * FUNCTION: setVertexValueStaticGraph
 * INPUT: A staticGraph, a id vertex and the vertexValue
 * REQUIREMENTS: 
 *      0 <= id vertex < maximum number of vertices
 *      The vertex has to exist.
 * MODIFIES: The vertexValueType of the vertex with id (int) is set
 */
void setVertexValueStaticGraph(staticGraph *g, int idVertex, vertexValueType value) {
    if (idVertex < 0 || idVertex >= g->maximumVertices)
        errorStaticGraph("The value of the vertex cannot be set because idVertex is out of range.");

    if (!g->vertices[idVertex].exists)
        errorStaticGraph("The value of the vertex cannot be set because the vertex doesn't exist.");

    g->vertices[idVertex].value = value;
}

/**
 * FUNCTION: getVertexValueStaticGraph
 * INPUT: A staticGraph and a id vertex
 * REQUIREMENTS: 
 *      0 <= id vertex < maximum number of vertices
 *      The vertex has to exist.
 * OUTPUT: The vertexValueType of the vertex with id (int).
 */
vertexValueType getVertexValueStaticGraph(staticGraph g, int idVertex) {
    if (idVertex < 0 || idVertex >= g.maximumVertices)
        errorStaticGraph("The value of the vertex cannot be returned because idVertex is out of range.");

    if (!g.vertices[idVertex].exists)
        errorStaticGraph("The value of the vertex cannot be returned because the vertex doesn't exist.");
    
    return g.vertices[idVertex].value;
}

/**
 * FUNCTION: isThereVertexStaticGraph
 * INPUT: A staticGraph and a id vertex
 * REQUIREMENTS: 0 <= id vertex < maximum number of vertices
 * OUTPUT: True <=> The vertex exist in the graph.
 */
bool isThereVertexStaticGraph(staticGraph g, int idVertex) {
    if (idVertex < 0 || idVertex >= g.maximumVertices)
        errorStaticGraph("In the function isThereVertexStaticGraph (idVertex out of range)");
    
    return g.vertices[idVertex].exists;
}

/**
 * FUNCTION: addEdgeStaticGraph
 * INPUT: A graph and two vertices (idVertex, idVertex) (int, int)
 * REQUIREMENTS: 
 *      0 <= idVertex, idVertex < maximum number of vertices
 *      The edge doesn't exist yet
 * MODIFIES: The vertices are connected by an edge.
 */
void addEdgeStaticGraph(staticGraph *g, int idVertexX, int idVertexY) {
    if (idVertexX < 0 || idVertexX >= g->maximumVertices || idVertexY < 0 || idVertexY >= g->maximumVertices)
        errorStaticGraph("The edge cannot be added because yours id vertices out of range.");

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

/**
 * FUNCTION: removeEdgeStaticGraph
 * INPUT: A staticGraph and two vertices
 * REQUIREMENTS: 
 *      0 <= idVertex, idVertex < maximum number of vertices
 *      The edge has to exist.
 * MODIFIES: The edge that connects the two vertices is removed
 */
void removeEdgeStaticGraph(staticGraph *g, int idVertexX, int idVertexY) {
    if (idVertexX < 0 || idVertexX >= g->maximumVertices || idVertexY < 0 || idVertexY >= g->maximumVertices)
        errorStaticGraph("The edge cannot be removed because yours id vertices out of range.");

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

/**
 * FUNCTION: setEdgeValueStaticGraph
 * INPUT: A staticGraph, two vertices and the value.
 * REQUIREMENTS: 
 *      0 <= idVertex, idVertex < maximum number of vertices
 *      The edge has to exist.
 * MODIFIES: The edgeValueType of the edge that connects the vertices (int, int) is set
 */
void setEdgeValueStaticGraph(staticGraph *g, int idVertexX, int idVertexY, edgeValueType value) {
    if (idVertexX < 0 || idVertexX >= g->maximumVertices || idVertexY < 0 || idVertexY >= g->maximumVertices)
        errorStaticGraph("The value of the edge cannot be set because their id vertex are out of range.");

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

/**
 * FUNCTION: getEdgeValueStaticGraph
 * INPUT: A staticGraph and two vertices
 * REQUIREMENTS: 
 *      0 <= idVertex, idVertex < maximum number of vertices
 *      The edge has to exist.
 * OUTPUT: The edgeValueType of the edge that connects the vertices (int, int).
 */
edgeValueType getEdgeValueStaticGraph(staticGraph g, int idVertexX, int idVertexY) {
    if (idVertexX < 0 || idVertexX >= g.maximumVertices || idVertexY < 0 || idVertexY >= g.maximumVertices)
        errorStaticGraph("The value of the edge cannot be returned because their id vertex are out of range.");

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

/**
 * FUNCTION: isThereEdgeStaticGraph
 * INPUT: A staticGraph and two vertices
 * REQUIREMENTS: 0 <= idVertex, idVertex < maximum number of vertices
 * OUTPUT: True <=> Both vertices are connected by an edge
 */
bool isThereEdgeStaticGraph(staticGraph g, int idVertexX, int idVertexY) {
    if (idVertexX < 0 || idVertexX >= g.maximumVertices || idVertexY < 0 || idVertexY >= g.maximumVertices)
        errorStaticGraph("The value of the edge cannot be returned because their id vertex are out of range.");

    if (idVertexX > idVertexY)
        return g.edges[idVertexX][idVertexY].exists;

    return g.edges[idVertexY][idVertexX].exists;
}

/**
 * FUNCTION: isFullStaticGraph
 * OUTPUT: True <=> No more vertices can be added. The staticGraph is full.
 */
bool isFullStaticGraph(staticGraph g) {
    return g.maximumVertices == g.numberVerticesCurrently;
}

/**
 * FUNCTION: getMaximumNumberVerticesStaticGraph
 * OUTPUT: The maximum number of vertices in the graph.
 */
int getMaximumNumberVerticesStaticGraph(staticGraph g) {
    return g.maximumVertices;
}

/**
 * FUNCTION: getNumberOfVerticesCurrently
 * OUTPUT: The number of vertices in the graph.
 */
int getNumberOfVerticesCurrentlyStaticGraph(staticGraph g) {
    return g.numberVerticesCurrently;
}

/**
 * FUNCTION: getNumberOfEdgesCurrently
 * OUTPUT: The number of edges in the graph.
 */
int getNumberOfEdgesCurrentlyStaticGraph(staticGraph g) {
    return g.numberEdgesCurrently;
}

/**
 * FUNCTION: getNeighborsStaticGraph
 * INPUT: A neighbors array, a lenght of the neighbors array, graph and the idVertex (int)
 * REQUIREMENTS: The lenght of the neighbors array >= The number of vertices currently in the graph
 * MODIFIES: 
 *      The int array (neighbors) with idsVertex connected to idVertex (int).
 *      The nNeighbors (int *) in the array.
 * EXAMPLE:
 *      The neighbors of idVertex = 3:
 *      int neighbors[getNumberOfVerticesCurrentlyStaticGraph(graph)]; // Reserved
 *      getNeighborsStaticGraph(&nNeighbors, neighbors, getNumberOfVerticesCurrentlyStaticGraph(graph), graph, 3);
 *      Output (it has 5 neighbors):
 *          neighbors = [idVertex0, idVertex1, idVertex2, idVertex3, idVertex4, randomNumber, ..., randomNumber]
 *          nNeighbors = 5
 */
void getNeighborsStaticGraph(int *nNeighbors,  int *neighbors, int maxNeighbors, staticGraph g, int idVertex) {
    if (maxNeighbors < g.numberVerticesCurrently)
        errorStaticGraph("In the function getNeighborsStaticGraph (The maxNeighbors has to be equal to maximum number of vertices)");

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

/**
 * FUNCTION: freeMemoryStaticGraph
 * MODIFIES: Free memory of the staticGraph
 */
void freeMemoryStaticGraph(staticGraph *g) {
    free(g->vertices);
    for (int i = 0; i < g->maximumVertices; i++)
        free(g->edges[i]);
    free(g->edges);
}

/**
 * FUNCTION: isConnectedStaticGraph
 * OUTPUT: True <=> The graph is connected.
 */
bool isConnectedStaticGraph(staticGraph g) {
    // Trivial cases
    if (getNumberOfVerticesCurrentlyStaticGraph(g) == 0 || getNumberOfVerticesCurrentlyStaticGraph(g) == 1)
        return true;

    if (getNumberOfVerticesCurrentlyStaticGraph(g) > 0 && getNumberOfEdgesCurrentlyStaticGraph(g) == 0)
        return false;

    // Reserves (array neighbors, queue and auxGraph)
    int *neighbors = (int *) (malloc(getNumberOfVerticesCurrentlyStaticGraph(g) * sizeof(int)));
    if (neighbors == NULL)
        errorStaticGraph("There isn't memory in the system for reserved.");
    
    int start = 0, end = 0;
    int *queueIdsVertices = (int *) (malloc(getNumberOfVerticesCurrentlyStaticGraph(g) * sizeof(int)));
    if (queueIdsVertices == NULL)
        errorStaticGraph("There isn't memory in the system for reserved.");

    staticGraph auxGraph;
    newStaticGraph(&auxGraph, getMaximumNumberVerticesStaticGraph(g));

    // The first vertex is found and it is added to auxGraph and the queue
    int firstIdVertex = 0;
    while (firstIdVertex < getMaximumNumberVerticesStaticGraph(g) - 1 && !isThereVertexStaticGraph(g, firstIdVertex))
        firstIdVertex++;

    addVertexStaticGraph(&auxGraph, firstIdVertex);
    queueIdsVertices[end] = firstIdVertex;
    end++;

    // The queue is processed with g and auxGraph
    int i;
    int nNeighbors;
    do {
        getNeighborsStaticGraph(neighbors, &nNeighbors, getNumberOfVerticesCurrentlyStaticGraph(g), g, queueIdsVertices[start]);
        for (i = 0; i < nNeighbors; i++) {
            if (!isThereVertexStaticGraph(auxGraph, neighbors[i])) {
                addVertexStaticGraph(&auxGraph, neighbors[i]);
                queueIdsVertices[end] = neighbors[i];
                end++;
            }
        }
        start++;
    } while (start != end);

    bool b = getNumberOfVerticesCurrentlyStaticGraph(auxGraph) == getNumberOfVerticesCurrentlyStaticGraph(g);
    free(neighbors);
    free(queueIdsVertices);
    freeMemoryStaticGraph(&auxGraph);
    return b;
}