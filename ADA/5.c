#include <stdio.h>
#include <stdlib.h>

#define V 5 // Number of vertices

// Structure to represent a graph
typedef struct {
    int V;
    int *adj;
} Graph;

// Function to create a graph
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adj = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        graph->adj[i] = 0;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int u, int v) {
    graph->adj[u] = v;
}

// Function to perform DFS
void DFS(Graph* graph, int v, int* visited, int* stack) {
    visited[v] = 1;
    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[v] == i && !visited[i]) {
            DFS(graph, i, visited, stack);
        }
    }
    stack[graph->V - 1] = v;
    graph->V--;
}

// Function to perform Topological Sort
void TopologicalSort(Graph* graph) {
    int* visited = (int*)malloc(graph->V * sizeof(int));
    int* stack = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < graph->V; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, stack);
        }
    }
    printf("Topological Order: ");
    for (int i = 0; i < graph->V; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    Graph* graph = createGraph(5);
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    TopologicalSort(graph);
    return 0;
}