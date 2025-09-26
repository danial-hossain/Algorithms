#include <stdio.h>

// Function to perform binary search to find the minimum element in a subarray
int find_min_index_binary(int arr[], int low, int high) {
    int min_index = low;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the middle element is smaller than the current minimum
        if (arr[mid] < arr[min_index]) {
            min_index = mid;
        }

        // Narrow down the search space
        if (arr[mid] < arr[high]) {
            high = mid - 1;  // Minimum lies in the left half
        } else {
            low = mid + 1;   // Minimum lies in the right half
        }
    }

    return min_index;
}

// Function to perform selection sort with binary search for minimum
void binary_selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted part using binary search
        int min_index = find_min_index_binary(arr, i, n - 1);

        // Swap the found minimum element with the current element
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

// Function to print an array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    print_array(arr, n);

    binary_selection_sort(arr, n);

    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}
