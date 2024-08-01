#include <stdio.h>

#define V 4 // Number of vertices

void warshal(int graph[V][V]) {
    int i, j, k;

    // Create a copy of the graph
    int transitiveClosure[V][V];
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            transitiveClosure[i][j] = graph[i][j];
        }
    }

    // Apply Warshal's algorithm
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                transitiveClosure[i][j] = transitiveClosure[i][j] || (transitiveClosure[i][k] && transitiveClosure[k][j]);
            }
        }
    }

    // Print the transitive closure
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (transitiveClosure[i][j]) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {1, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
    };

    warshal(graph);

    return 0;
}