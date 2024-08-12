//Do not run!!

#include <stdio.h>

#define V 5  // Number of vertices

// Function to perform DFS
void DFS(int graph[V][V], int v, int visited[V], int stack[V], int *index) {
    visited[v] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[v][i] && !visited[i]) {
            DFS(graph, i, visited, stack, index);
        }
    }

    stack[(*index)++] = v;  // Push current vertex to stack
}

// Function to perform Topological Sort
void TopologicalSort(int graph[V][V]) {
    int visited[V] = {0};  // Array to mark visited vertices
    int stack[V];  // Array to store the topological order
    int index = 0;  // Index to track the position in the stack

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(graph, i, visited, stack, &index);
        }
    }

    // Print the topological order in reverse
    printf("Topological Order: ");
    for (int i = V - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int graph[V][V];  // Declare the adjacency matrix

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    TopologicalSort(graph);

    return 0;
}
