#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices

void floyd(int graph[V][V]) {
    int i, j, k;

    // Create a copy of the graph
    int dist[V][V];
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Apply Floyd's algorithm
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest paths
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == 999) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {999,8,4,999},
        {999, 999, 1, 999},
        {4, 999, 999, 999},
        {999, 2, 9, 999}
    };

    floyd(graph);

    return 0;
}