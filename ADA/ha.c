#include <stdio.h>

int cost[10][10], n;

void kruskal()
{
    int parent[10], ne = 0, mincost=0;

    for (int i = 0; i < n; i++)
        parent[i] = -1;

    while (ne < n - 1)
    {
        int min = 999, u = -1, v = -1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        int root_u = u, root_v = v;
        while (parent[root_u] != -1)
        {
            root_u = parent[root_u];
        }

        while (parent[root_v] != -1)
        {
            root_v = parent[root_v];
        }

        if (root_u != root_v)
        {
            printf("Edge from %d to %d | Cost: %d \n", u, v, min);
            mincost += min;
            ne++;
            parent[root_v] = root_u;
        }

        cost[u][v] = cost[v][u] = 999;
    }

    printf("Total cost : %d", mincost);
}

void main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal();
}