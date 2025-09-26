#include <stdio.h>

// Function to perform binary search within a subarray to find the minimum element
int find_min_index(int arr[], int low, int high) {
    int min_index = low;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] < arr[min_index]) {
            min_index = mid;
        }

        if (arr[mid] <= arr[low]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return min_index;
}

// Function to perform binary selection sort
void binary_selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Find the minimum element in the unsorted part using binary search
        int min_index = find_min_index(arr, i, n - 1);
      printf("%d \n",arr[min_index]);
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
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    print_array(arr, n);

    binary_selection_sort(arr, n);

    printf("Sorted array:\n");
    print_array(arr, n);

    return 0;
}