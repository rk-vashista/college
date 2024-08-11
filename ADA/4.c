#include <stdio.h>

#define V 5       // Number of vertices
#define INF 99999 // A large number to represent infinity

void dijkstra(int graph[V][V], int src)
{
    int dist[V];    // Array to store the shortest distances
    int visited[V]; // Array to track visited vertices

    // Initialize distances and visited array
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0; // Distance to the source is 0

    for (int i = 0; i < V - 1; i++)
    {
        int min = INF;
        int minIndex = -1;

        // Find the unvisited vertex with the minimum distance
        for (int j = 0; j < V; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                minIndex = j;
            }
        }

        visited[minIndex] = 1; // Mark the picked vertex as visited

        // Update distances of adjacent vertices
        for (int j = 0; j < V; j++)
        {
            if (!visited[j] && graph[minIndex][j] != 0 && dist[minIndex] + graph[minIndex][j] < dist[j])
            {
                dist[j] = dist[minIndex] + graph[minIndex][j];
            }
        }
    }

    // Print the shortest distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main()
{
    int graph[V][V] = {
        {0, 3, 1, 999, 999},
        {3, 0, 7, 5, 1},
        {1, 7, 0, 2, 999},
        {999, 5, 2, 0, 7},
        {999, 1, 999, 7, 0}};

    int src = 0; // Starting vertex

    dijkstra(graph, src);

    return 0;
}
