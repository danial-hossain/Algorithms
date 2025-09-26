#include<stdio.h>

// Recursive binary search function
int binarySearch(int array[], int beg, int end, int find) {
    if (beg > end) {
        return -1;  // Element not found
    }

    int mid = (beg + end) / 2;

    if (array[mid] == find) {
        return mid;  // Element found at mid
    }

    // If the element is smaller, search in the left half
    if (find < array[mid]) {
        return binarySearch(array, beg, mid - 1, find);
    }
    // If the element is larger, search in the right half
    return binarySearch(array, mid + 1, end, find);
}

int main() {
    int array[] = {1, 3, 5, 7, 10, 12};
    int n = sizeof(array) / sizeof(array[0]);  // Size of the array
    int find = 7;

    int result = binarySearch(array, 0, n - 1, find);

    // Printing the result
    if (result != -1) {
        printf("Element %d found at index %d\n", find, result);
    } else {
        printf("Element %d not found in the array\n", find);
    }

    return 0;
}
