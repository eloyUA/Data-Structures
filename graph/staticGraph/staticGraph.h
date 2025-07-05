#ifndef _STATIC_GRAPH_H
#define _STATIC_GRAPH_H

/**
 * MODULE: staticGraph
 * FILE: staticGraph.h
 * VERSION: 1.0.0
 * HISTORICAL: 
 *      Created by Eloy Urriens Arpal on 22/1/2025, version 1.0.0
 * DESCRIPTION: This module is the implement of the graph.
 * CC: BY SA
 */

#include <stdbool.h>

typedef float vertexValueType;
typedef float edgeValueType;

typedef struct {
    vertexValueType value;
    bool exists;
} nodeVertex;

typedef struct {
    edgeValueType value;
    bool exists;
} nodeEdge;

typedef struct {
    int maximumVertices;
    int numberVerticesCurrently;
    int numberEdgesCurrently;
    nodeVertex *vertices;
    nodeEdge **edges;
} staticGraph;

/**
 * FUNCTION: newStaticGraph
 * INPUT: The maximum number of vertices (int).
 * OUTPUT: A staticGraph with 0 vertices and 0 edges.
 */
void newStaticGraph(staticGraph *, int);

/**
 * FUNCTION: addVertexStaticGraph
 * INPUT: The graph and the id vertex.
 * REQUIREMENTS: 
 *      The id vertex has to be unique (The vertex doesn't exist yet)
 *      0 <= id vertex < maximum number of vertices
 *      The number of the vertices currently < The maximum number of the vertices
 *      in the graph (The graph isn't full)
 * OUTPUT: The graph with the vertex.
 */
void addVertexStaticGraph(staticGraph *, int);

/**
 * FUNCTION: removeVertexStaticGraph
 * INPUT: A staticGraph and id vertex
 * REQUIREMENTS:
 *      The vertex has to exist.
 *      0 <= id vertex < maximum number of vertices
 * MODIFIES: The vertex with id (int) is removed
 */
void removeVertexStaticGraph(staticGraph *, int);

/**
 * FUNCTION: setVertexValueStaticGraph
 * INPUT: A staticGraph, a id vertex and the vertexValue
 * REQUIREMENTS: 
 *      0 <= id vertex < maximum number of vertices
 *      The vertex has to exist.
 * MODIFIES: The vertexValueType of the vertex with id (int) is set
 */
void setVertexValueStaticGraph(staticGraph *, int, vertexValueType);

/**
 * FUNCTION: getVertexValueStaticGraph
 * INPUT: A staticGraph and a id vertex
 * REQUIREMENTS: 
 *      0 <= id vertex < maximum number of vertices
 *      The vertex has to exist.
 * OUTPUT: The vertexValueType of the vertex with id (int).
 */
vertexValueType getVertexValueStaticGraph(staticGraph, int);

/**
 * FUNCTION: isThereVertexStaticGraph
 * INPUT: A staticGraph and a id vertex
 * REQUIREMENTS: 0 <= id vertex < maximum number of vertices
 * OUTPUT: True <=> The vertex exist in the graph.
 */
bool isThereVertexStaticGraph(staticGraph, int);

/**
 * FUNCTION: addEdgeStaticGraph
 * INPUT: A graph and two vertices (idVertex, idVertex) (int, int)
 * REQUIREMENTS: 
 *      0 <= idVertex, idVertex < maximum number of vertices
 *      The edge doesn't exist yet
 * MODIFIES: The vertices are connected by an edge.
 */
void addEdgeStaticGraph(staticGraph *, int, int);

/**
 * FUNCTION: removeEdgeStaticGraph
 * INPUT: A staticGraph and two vertices
 * REQUIREMENTS: 
 *      0 <= idVertex, idVertex < maximum number of vertices
 *      The edge has to exist.
 * MODIFIES: The edge that connects the two vertices is removed
 */
void removeEdgeStaticGraph(staticGraph *, int, int);

/**
 * FUNCTION: setEdgeValueStaticGraph
 * INPUT: A staticGraph, two vertices and the value.
 * REQUIREMENTS: 
 *      0 <= idVertex, idVertex < maximum number of vertices
 *      The edge has to exist.
 * MODIFIES:
 *      The edgeValueType of the edge that connects the vertices (int, int) is set
 */
void setEdgeValueStaticGraph(staticGraph *, int, int, edgeValueType);

/**
 * FUNCTION: getEdgeValueStaticGraph
 * INPUT: A staticGraph and two vertices
 * REQUIREMENTS: 
 *      0 <= idVertex, idVertex < maximum number of vertices
 *      The edge has to exist.
 * OUTPUT: The edgeValueType of the edge that connects the vertices (int, int).
 */
edgeValueType getEdgeValueStaticGraph(staticGraph, int, int);

/**
 * FUNCTION: isThereEdgeStaticGraph
 * INPUT: A staticGraph and two vertices
 * REQUIREMENTS: 0 <= idVertex, idVertex < maximum number of vertices
 * OUTPUT: True <=> Both vertices are connected by an edge
 */
bool isThereEdgeStaticGraph(staticGraph, int, int);

/**
 * FUNCTION: isFullStaticGraph
 * OUTPUT: True <=> No more vertices can be added. The staticGraph is full.
 */
bool isFullStaticGraph(staticGraph);

/**
 * FUNCTION: getMaximumNumberVerticesStaticGraph
 * OUTPUT: The maximum number of vertices in the graph.
 */
int getMaximumNumberVerticesStaticGraph(staticGraph);

/**
 * FUNCTION: getNumberOfVerticesCurrently
 * OUTPUT: The number of vertices in the graph.
 */
int getNumberOfVerticesCurrentlyStaticGraph(staticGraph);

/**
 * FUNCTION: getNumberOfEdgesCurrently
 * OUTPUT: The number of edges in the graph.
 */
int getNumberOfEdgesCurrentlyStaticGraph(staticGraph);

/**
 * FUNCTION: getNeighborsStaticGraph
 * INPUT: 
 *      A neighbors array, a lenght of the neighbors array,
 *      graph and the idVertex (int)
 * REQUIREMENTS:
 *      The lenght of the neighbors array >= The number of vertices currently
 * MODIFIES: 
 *      The int array (neighbors) with idsVertex connected to idVertex (int).
 *      The nNeighbors (int *) in the array.
 * EXAMPLE:
 *      The neighbors of idVertex = 3:
 *      int neighbors[getNumberOfVerticesCurrentlyStaticGraph(graph)]; // Reserved
 *      getNeighborsStaticGraph(
 *          &nNeighbors,
 *          neighbors,
 *          getNumberOfVerticesCurrentlyStaticGraph(graph),
 *          graph,
 *          3
 *      );
 *      Output (it has 5 neighbors):
 *          neighbors = [idVertex0, idVertex1, idVertex2, idVertex3,
 *                      idVertex4, randomNumber, ..., randomNumber]
 *          nNeighbors = 5
 */
void getNeighborsStaticGraph(int *nNeighbors, int *neighArray, int lenght,
                            staticGraph, int idVertex);

/**
 * FUNCTION: freeMemoryStaticGraph
 * MODIFIES: Free memory of the staticGraph
 */
void freeMemoryStaticGraph(staticGraph *);

/**
 * FUNCTION: isConnectedStaticGraph
 * OUTPUT: True <=> The graph is connected.
 */
bool isConnectedStaticGraph(staticGraph);

#endif