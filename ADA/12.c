#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int board[MAX][MAX];
int solutionCount = 0;

// Function to print the chessboard
void printBoard(int n) {
    printf("Solution %d:\n", ++solutionCount);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Check if it's safe to place a queen at board[row][col]
bool isSafe(int board[MAX][MAX], int row, int col, int n) {
    int i, j;

    // Check the same column
    for (i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    // Check upper right diagonal
    for (i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

// Recursive function to solve the N-Queens problem
void solveNQueens(int board[MAX][MAX], int row, int n) {
    if (row >= n) {
        printBoard(n);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 1;

            solveNQueens(board, row + 1, n);

            board[row][col] = 0; // Backtrack
        }
    }
}

int main() {
    int n;
    printf("Enter the number of queens (N): ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Number of queens must be between 1 and %d.\n", MAX);
        return 1;
    }

    // Initialize the board with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    solveNQueens(board, 0, n);

    if (solutionCount == 0) {
        printf("No solutions exist.\n");
    }

    return 0;
}
