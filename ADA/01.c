#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices

// Structure to represent an edge
typedef struct {
    int u, v, weight;
} Edge;

// Function to find the parent of a vertex in the disjoint set
int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

// Function to perform union of two sets in the disjoint set
void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

// Function to implement Kruskal's algorithm
void kruskal(Edge edges[], int numVertices) {
    int parent[numVertices], rank[numVertices];
    int i, e = 0;
    int minimumCost = 0;

    // Initialize the disjoint set
    for (i = 0; i < numVertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort the edges in non-decreasing order of their weights
    for (i = 0; i < numVertices - 1; i++) {
        int min = i;
        for (int j = i + 1; j < numVertices; j++) {
            if (edges[j].weight < edges[min].weight)
                min = j;
        }
        Edge temp = edges[i];
        edges[i] = edges[min];
        edges[min] = temp;
    }

    // Find the MST
    for (i = 0; i < numVertices - 1; i++) {
        int x = find(parent, edges[i].u);
        int y = find(parent, edges[i].v);

        if (x != y) {
            minimumCost += edges[i].weight;
            printf("%d - %d\n", edges[i].u, edges[i].v);
            unionSet(parent, rank, x, y);
        }
    }

    printf("Minimum Cost: %d\n", minimumCost);
}

int main() {
    Edge edges[] = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

    kruskal(edges, V);

    return 0;
}