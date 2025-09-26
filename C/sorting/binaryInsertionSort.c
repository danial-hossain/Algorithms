#include <stdio.h>

// Iterative binary search function to find the correct position for insertion
int binarySearch(int array[], int low, int high, int key) {
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;

        if (key == array[mid]) {
            return mid + 1; // If the key matches, insert after the match
        } else if (key < array[mid]) {
            high = mid - 1; // Search in the left half
        } else {
            low = mid + 1; // Search in the right half
        }
    }

    return low; // Return the position to insert the key
}

// Function to sort array using binary insertion sort
void insertionSort(int array[], int n) {
    for (int i = 1; i <= n-1; i++) {
        int key = array[i];
        int j = i - 1;

        // Find the location where the key should be inserted
        int loc = binarySearch(array, 0, j, key);

        // Shift elements to the right to create space for the key
        while (j >= loc) {
            array[j + 1] = array[j];
            j--;
        }

        // Place the key at the correct position
        array[j + 1] = key;
    }
}

// Utility function to print an array
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Driver code
int main() {
    int array[] = {37, 23, 0, 17, 17, 72, 31, 46, 100, 88, 54};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Original array: ");
    printArray(array, n);

    insertionSort(array, n);

    printf("Sorted array: ");
    printArray(array, n);

    return 0;
}
