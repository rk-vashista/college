#include <stdio.h>
#include <stdbool.h>

void printSubset(int subset[], int subsetSize)
{
    printf("{");
    for (int i = 0; i < subsetSize; i++)
    {
        if (i == subsetSize - 1)
        {
            printf("%d } \n", subset[i]);
            break;
        }
        printf("%d , ", subset[i]);
    }
}

void findSubsets(int arr[], int n, int sum, int subset[], int subsetSize)
{

    if (sum == 0)
    {
        printSubset(subset, subsetSize);
        return;
    }

    if (n == 0 || sum < 0)
        return;

    findSubsets(arr, n - 1, sum, subset, subsetSize);
    subset[subsetSize] = arr[n - 1];
    findSubsets(arr, n - 1, sum - arr[n - 1], subset, subsetSize + 1);
}

void main()
{
    int n, d;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the integers:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &d);

    int subset[n]; // Array to hold the current subset
    printf("Subsets with the given sum:\n");
    findSubsets(arr, n, d, subset, 0);
}