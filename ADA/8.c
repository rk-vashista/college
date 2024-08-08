#include <stdio.h>
#include <stdbool.h>

// Function to print a subset
void printSubset( int subset[], int subsetSize) {
    printf("{ ");
    for (int i = 0; i < subsetSize; i++) {
        if(i==subsetSize-1){
        printf("%d ", subset[i]);
        break;
        }
        printf("%d , ", subset[i]);
    }
    printf("}\n");
}

// Recursive function to find and print subsets with the given sum
void findSubsetsWithSum(int arr[], int n, int sum, int subset[], int subsetSize) {
    // Base case
    if (sum == 0) {
        printSubset( subset, subsetSize);
        return;
    }
    if (n == 0 || sum < 0) return;

    // Exclude the last element and recurse
    findSubsetsWithSum(arr, n-1, sum, subset, subsetSize);

    // Include the last element in the subset and recurse
    subset[subsetSize] = arr[n-1];
    findSubsetsWithSum(arr, n-1, sum-arr[n-1], subset, subsetSize + 1);
}

int main() {
    int n, d;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the integers:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &d);

    int subset[n];  // Array to hold the current subset
    printf("Subsets with the given sum:\n");
    findSubsetsWithSum(arr, n, d, subset, 0);

    return 0;
}
