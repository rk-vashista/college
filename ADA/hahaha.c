#include <stdio.h>
#include <stdbool.h>
#define MAX 20

int board[MAX][MAX];

int solutionCount=0;
void printBoard( int n)
{
    int i, j;
    printf("Solution %d: \n",++solutionCount);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                printf(" Q ");
            }
            else
            {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int borad[MAX][MAX], int row, int col, int n){

    for(int i=0;i<n;i++){
        if(board[i][col]==1)
        return false;
    }

    for(int i=row,j=col;i>=0,j>=0;i--,j--){
        if(board[i][j]==1)
        return false;
    }

    for(int i=row,j=col;i>=0,j<n;i--,j++){
        if(board[i][j]==1)
        return false;
    }

    return true;
}


void Qween(int board[MAX][MAX], int row, int n){
    if(row>=n){
        printBoard(n);
        return;
    }

    for(int col=0;col<n;col++){
        if(isSafe(board,row,col,n))
        {
            board[row][col]=1;

            Qween(board,row+1,n);

            board[row][col]=0;
        }
    }
}

void main(){
    printf("ENter the number of queens:\n");
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            board[i][j]=0;
        }
    }

    Qween(board,0,n);

    if(solutionCount==0){
        printf("No solution");
    }
}