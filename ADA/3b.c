#include <stdio.h>

#define V 4 // Number of vertices

void warshall(int graph[V][V]) {
    int i, j, k;

    // Apply Warshall's algorithm directly on the input graph
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }

    // Print the transitive closure
    printf("Transitive closure of the given graph:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
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
    
    warshall(graph);

    return 0;
}
