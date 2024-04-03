// Adjacency List
#include <stdio.h>
#include <stdlib.h>

// Node structure for the adjacency list
typedef struct Node {
    int vertex;  // The vertex number
    struct Node* next;  // Pointer to the next node
} Node;

// [
//     [vertex0] -> Node0[vertex1]-> Node1[vertex2]->NULL
//     [vertex1] -> []->NULL
//     [vertex2] -> []->NULL
// ]

// Graph structure using an adjacency list
typedef struct {
    int numVertices;  // Number of vertices
    Node** adjLists;  // Array of pointers to the first node of each linked list // double pointer means that its a pointer who stores all the pointers that start separate linked list
} GraphList;

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;  // Next pointer is initialized to NULL
    return newNode;
}

// Function to initialize the graph
GraphList* createGraphList(int vertices) {
    GraphList* graph = (GraphList*) malloc(sizeof(GraphList));
    graph->numVertices = vertices;

    // Allocate memory for adjacency lists
    graph->adjLists = (Node**) malloc(vertices * sizeof(Node*));
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;  // Initialize each list as NULL
    }

    return graph;
}

// Function to add an edge
void addEdgeList(GraphList* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // newNode1 -> NULL
    // newNode2 -> NULL

    // 0th [newNode2 -> newNode1 -> NULL]
    // 1st [NULL]
    // 2nd [NULL]

    // Add edge from dest to src for undirected graph
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph
void printGraphList(GraphList* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp != NULL) {  // Traverse until the end of the list
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");  // Indicate end of the list
    }
}

// Main function
int main() {
    GraphList* graph = createGraphList(5);
    addEdgeList(graph, 0, 1);
    addEdgeList(graph, 0, 2);
    addEdgeList(graph, 1, 3);
    addEdgeList(graph, 2, 4);
    // [
    //     0 -> [2, 1]
    //     1 -> [3, 0]
    //     2 -> [4, 0]
    //     3 -> [1]
    //     4 -> [2]
    // ]

    printf("Adjacency List Representation:\n");
    printGraphList(graph);

    return 0;
}

