#include <stdio.h>

#define MAX 100

// Structure to represent an item
typedef struct {
    int value;
    int weight;
    double ratio;
} Item;

// Function to sort items based on value-to-weight ratio in descending order
void sortItems(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Function to solve the discrete knapsack problem using a greedy approximation
void discreteKnapsack(int W, int n, Item items[]) {
    int totalValue = 0;
    int totalWeight = 0;
    int taken[n];  // Array to keep track of taken items

    // Initialize taken items
    for (int i = 0; i < n; i++) {
        taken[i] = 0;
    }

    // Sort items based on their ratio
    sortItems(items, n);

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= W) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
            taken[i] = 1;
        }
    }

    printf("Maximum value in knapsack (discrete): %d\n", totalValue);
}

// Function to solve the continuous knapsack problem using a greedy approach
void fractionalKnapsack(int W, int n, Item items[]) {
    double totalValue = 0.0;
    int totalWeight = 0;

    // Sort items based on their ratio
    sortItems(items, n);

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= W) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            int remainingWeight = W - totalWeight;
            totalValue += items[i].value * ((double)remainingWeight / items[i].weight);
            break;
        }
    }

    printf("Maximum value in knapsack (fractional): %.2f\n", totalValue);
}

int main() {
    int n, W;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];
    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
        items[i].ratio = (double)items[i].value / items[i].weight;
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    // Solve discrete knapsack problem
    discreteKnapsack(W, n, items);

    // Solve fractional knapsack problem
    fractionalKnapsack(W, n, items);

    return 0;
}
