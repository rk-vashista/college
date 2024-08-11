#include <stdio.h>

#define MAX_ITEMS 100  // Maximum number of items
#define MAX_CAPACITY 1000  // Maximum knapsack capacity

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using Dynamic Programming
void knapsack(int W, int n, int wt[], int val[]) {
    int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1] = {0};  // Initialize dp array to 0

    // Fill the dp array using the Knapsack logic
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Debugging: Print the dp table
    printf("DP Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            printf("%d ", dp[i][w]);
        }
        printf("\n");
    }

    printf("Maximum value in knapsack: %d\n", dp[n][W]);

    // Find out which items are included in the optimal solution
    int res = dp[n][W];
    int w = W;
    printf("Items included are: ");
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i - 1][w])
            continue;
        else {
            printf("%d ", i); // This item is included
            res -= val[i - 1];
            w -= wt[i - 1];
        }
    }
    printf("\n");
}

int main() {
    int n, W;
    int val[MAX_ITEMS], wt[MAX_ITEMS];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    knapsack(W, n, wt, val);

    return 0;
}
