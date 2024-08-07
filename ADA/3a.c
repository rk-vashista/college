#include <stdio.h>

#define V 4 // Number of vertices

void floydWarshall(int graph[V][V]) {
    int dist[V][V];
    int i, j, k;

    // Initialize the distance matrix with the input graph
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest path matrix
    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (dist[i][j] == 999) {
                printf("999 ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {

    printf("Enter the cost matrix \n");

    int graph[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    // int graph[V][V] = {
    //     {999, 8, 4, 999},
    //     {999, 999, 1, 999},
    //     {4, 999, 999, 999},
    //     {999, 2, 9, 999}
    // };

    floydWarshall(graph);

    return 0;
}
