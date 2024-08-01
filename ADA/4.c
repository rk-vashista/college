#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int visited[V];

    // Initialize distances and visited array
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        int min = INT_MAX;
        int minIndex;

        // Find the vertex with minimum distance
        for (int j = 0; j < V; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                minIndex = j;
            }
        }

        visited[minIndex] = 1;

        // Update distances of adjacent vertices
        for (int j = 0; j < V; j++) {
            if (!visited[j] && graph[minIndex][j] && dist[minIndex] + graph[minIndex][j] < dist[j]) {
                dist[j] = dist[minIndex] + graph[minIndex][j];
            }
        }
    }

    // Print the shortest distances
    printf("Vertex\tDistance\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0},
        {4, 0, 8, 0, 0},
        {0, 8, 0, 7, 0},
        {0, 0, 7, 0, 9},
        {0, 0, 0, 9, 0}
    };

    int src = 0;

    dijkstra(graph, src);

    return 0;
}