// Adjacency Matrix Representation of a Graph
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 5  // Maximum number of vertices in the graph

// Graph structure using an adjacency matrix
typedef struct {
    int graph[MAX_VERTICES][MAX_VERTICES];
} GraphMatrix; // Adjacency Matrix

// Initialize the graph
void initGraphMatrix(GraphMatrix *g) {
    for (int i = 0; i < MAX_VERTICES; i++)
        for (int j = 0; j < MAX_VERTICES; j++)
            g->graph[i][j] = 0;
}

// Add edge to the graph
void addEdgeMatrix(GraphMatrix *g, int start, int end) {
    g->graph[start][end] = 1;
    g->graph[end][start] = 1;  // For undirected graph. Remove for directed graph.
}

// Print the graph
void printGraphMatrix(GraphMatrix *g) {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            printf("%d ", g->graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    GraphMatrix g;  //create an object
    initGraphMatrix(&g);
    addEdgeMatrix(&g, 0, 1);
    addEdgeMatrix(&g, 0, 2);
    addEdgeMatrix(&g, 1, 3);
    addEdgeMatrix(&g, 2, 4);

    printf("\nAdjacency Matrix Representation:\n");
    printGraphMatrix(&g);

    return 0;
}

