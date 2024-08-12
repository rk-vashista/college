#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first element
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 20 == 0) // Print 20 elements per line for better readability
            printf("\n");
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements (n > 5000): ");
    scanf("%d", &n);

    if (n <= 5000) {
        printf("Number of elements must be greater than 5000.\n");
        return 1;
    }

    int arr[n];

    // Generate random integers and fill the array
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Random integers between 0 and 9999
    }

    // Measure the time taken for sorting
    clock_t start = clock();
    selectionSort(arr, n);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}
