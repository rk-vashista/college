#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000 // Define a maximum array size

// Function to merge two subarrays of arr[]
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int L[MAX_SIZE], R[MAX_SIZE]; // Fixed-size arrays

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Function to implement Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 20 == 0) // Print 20 elements per line for readability
            printf("\n");
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements (n > 5000, max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n <= 5000 || n > MAX_SIZE) {
        printf("Number of elements must be greater than 5000 and less than or equal to %d.\n", MAX_SIZE);
        return 1;
    }

    int arr[MAX_SIZE]; // Fixed-size array

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Random integers between 0 and 9999
    }

    clock_t start = clock();
    mergeSort(arr, 0, n - 1);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
   
    printf("Sorted array:\n");
    printArray(arr, n);

    printf("Time taken to sort %d elements: %f seconds\n", n, time_taken);
    return 0;
}
