#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Choosing the pivot element
    int start = low;
    int end = high;
    int k = high;

    // Iterate from the end of the array to the start
    for (int i = high; i > low; i--) {
        // If the current element is greater than the pivot,
        // swap it with the element at index k and decrement k
        if (arr[i] > pivot)
            swap(&arr[i], &arr[k--]);
    }

    // Swap the pivot element with the element at index k
    swap(&arr[low], &arr[k]);

    return k; // Return the index of the pivot element after partitioning
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array and get the index of the pivot element
        int idx = partition(arr, low, high);

        // Recursively sort the subarrays before and after the pivot element
        quickSort(arr, low, idx - 1);
        quickSort(arr, idx + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Call quickSort to sort the array
    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}