#include <stdio.h>

int cost[10][10], n;

void kruskal() {
    int parent[10];
    int ne = 0, mincost = 0;

    // Initialize parent array
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }

    // While there are less than (n-1) edges in the result
    while (ne < n - 1) {
        int min = 999, u = -1, v = -1;

        // Find the minimum cost edge
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // Find the root of the sets u and v belong to
        int root_u = u, root_v = v;
        while (parent[root_u] != -1) {
            root_u = parent[root_u];
        }
        while (parent[root_v] != -1) {
            root_v = parent[root_v];
        }

        // If u and v are in different sets, add this edge to the result
        if (root_u != root_v) {
            printf("Edge: %d - %d | Cost: %d\n", u, v, min);
            mincost += min;
            parent[root_v] = root_u;
            ne++;
        }

        // Mark this edge as used
        cost[u][v] = cost[v][u] = 999;
    }

    printf("Minimum cost: %d\n", mincost);
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

    kruskal();
    return 0;
}
