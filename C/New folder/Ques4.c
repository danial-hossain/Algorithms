#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    int indexOfMin, indexOfMax, temp;
    printf("Running Selection sort...\n");
    for (int i = 0; i < n / 2; i++)
    {
        indexOfMin = i;
        indexOfMax = i;

        // Find the indices of the minimum and maximum elements in the unsorted portion
        for (int j = i; j < n - i; j++)
        {
            if (A[j] < A[indexOfMin])
            {
                indexOfMin = j;
            }
            if (A[j] > A[indexOfMax])
            {
                indexOfMax = j;
            }
        }

        // Swap the minimum element with the first element of the unsorted portion
        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;

        // If the maximum element was swapped, adjust its index
        if (indexOfMax == i)
        {
            indexOfMax = indexOfMin;
        }

        // Swap the maximum element with the last element of the unsorted portion
        temp = A[n - i - 1];
        A[n - i - 1] = A[indexOfMax];
        A[indexOfMax] = temp;
    }
}

int main()
{
    // Input array
    int A[] = {3, 5, 2, 13, 12};
    int n = 5;

    // Print the original array
    printArray(A, n);

    // Perform selection sort
    selectionSort(A, n);

    // Print the sorted array
    printArray(A, n);

    return 0;
}
