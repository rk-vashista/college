#include <stdio.h>

int cost[10][10], n;

void prim() {
    int visited[10] = {0}; // Track visited vertices
    int mincost = 0, ne = 0; // Minimum cost and number of edges in MST

    // Start from the first vertex
    visited[0] = 1;

    while (ne < n - 1) {
        int min = 999, a = -1, b = -1;

        // Find the nearest neighbor
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        // Include the nearest neighbor in the MST
        if (a != -1 && b != -1) {
            printf("Edge from vertex %d to vertex %d with cost %d\n", a, b, min);
            visited[b] = 1;
            ne++;
            mincost += min;
            cost[a][b] = cost[b][a] = 999; // Mark this edge as used
        }
    }

    printf("Minimum spanning tree cost is %d\n", mincost);
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    prim();
    return 0;
}
