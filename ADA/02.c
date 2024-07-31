#include <stdio.h>
#include <limits.h>

#define MAX 100

int findMinVertex(int cost[], int visited[], int V) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (visited[v] == 0 && cost[v] < min) {
            min = cost[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(int graph[MAX][MAX], int V) {
    int parent[V]; 
    int cost[V];   
    int visited[V];  

    for (int i = 0; i < V; i++) {
        cost[i] = INT_MAX;
        visited[i] = 0;
    }

    cost[0] = 0;      
    parent[0] = -1;   

    for (int count = 0; count < V - 1; count++) {
        int u = findMinVertex(cost, visited, V);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && visited[v] == 0 && graph[u][v] < cost[v]) {
                parent[v] = u;
                cost[v] = graph[u][v];
            }
        }
    }

    int totalCost = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }
    printf("Total cost of MST: %d\n", totalCost);
}

int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    int graph[MAX][MAX];
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph, V);

    return 0;
}
