#include<stdio.h>
#include<stdlib.h>

void bfs(int[20][20],int,int[20],int);
void dfs(int[20][20],int,int[20],int);

void main()
{
    int a[20][20],source,n,visted[20],i,j;
    printf("Enter the number of nodes\n");
    scanf("%d",&n);
    printf("Enter the adjaency Matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    for(i=1;i<=n;i++)
    {
        visted[i]=0;
    }

    printf("Enter the source\n");
    scanf("%d",&source);

    visted[source]=1;

    bfs(a,source,visted,n);
    for(i=1;i<=n;i++)
    {
        if(visted[i]!=0)
        printf("The node %d is connected\n ",i);
        else
        printf("The node %d is not connected \n",i);
    }

    dfs(a,source,visted,n);
    for(i=1;i<=n;i++)
    {
        if(visted[i]==0)
        {
            printf("The Graph is not connected");
            exit(0);
        }
    }
    printf("The graph is connected");
}



void bfs(int a[20][20],int source,int visted[20],int n)
{
    int f,r,u,v,queue[20];
    f=0;
    r=-1;
    queue[++r]=source;

    while(f<=r)
    {
        u=queue[f++];
        for(v=1;v<=n;v++)
        {
            if(a[u][v]==1&&visted[v]==0)
            {
                queue[++r]=v;
                visted[v]=1;
            }
        }
    }
}


void dfs(int a[20][20],int u, int visted[20],int n)
{
    int v;
    visted[u]=1;
    for(v=1;v<=n;v++)
    {
        if(a[u][v]==1&&visted[v]==0)
        dfs(a,v,visted,n);
    }
}