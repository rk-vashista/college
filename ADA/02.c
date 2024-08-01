#include <stdio.h>
#include <limits.h>

#define V 5 

int graph[V][V] = {
    {0, 2, 3, 1},
    {2, 0, 4,0},
    {3,4, 0,5},
    {1, 0, 5, 0}
};

int visited[V] = {0};
int parent[V];
int totalCost = 0; // To store the total cost of the MST

int minKey(int key[], int mstSet[]) {
    int min = INT_MAX, minIndex;
    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST() {
    int key[V]; 
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
    }

    key[0] = 0; 

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, visited); 
        visited[u] = 1; 

        printf("%d - %d\n", parent[u], u); 
        totalCost += key[u]; // Add the edge weight to the total cost

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && visited[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u; 
                key[v] = graph[u][v]; 
            }
        }
    }
}

int main() {
    primMST();
    printf("Total cost of MST: %d\n", totalCost);
    return 0;
}