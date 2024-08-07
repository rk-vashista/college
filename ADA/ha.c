#include <stdio.h>

int cost[10][10],n;

void prims(){
    int visited[10]={0};
    int mincost=0,ne=0;

    visited[0]=1;

    while(ne<n-1){
        int min=999, a=-1,b=-1;

        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=0;j<n;j++){
                    if(!visited[j] && cost[i][j]<min){
                        min=cost[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }

        if(a!=-1 && b!=-1){
            printf("Edge from %d to %d| Cost: %d \n", a,b,min);
            mincost+=min;
            ne++;
            visited[b]=1;
            cost[a][b]=cost[b][a]=999;
        }
    }
    printf("The total cost is %d ",mincost);
}

void main(){
    printf("Enter the number of vertices: ");
    scanf("%d",&n);

    printf("Enter the cost matrix \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
        }
    }

    prims();
}