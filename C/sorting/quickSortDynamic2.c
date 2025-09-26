#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    // Dynamic pivot selection
    srand(time(0)); // Seed the random number generator
    int random = low + rand() % (high - low + 1); // Random index between low and high

    // Swap A[low] with A[random] to use the random pivot
    int temp = A[low];
    A[low] = A[random];
    A[random] = temp;

    int pivot = A[low];
    int i = low + 1;
    int j = high;

    do
    {
        while (i <= high && A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high)
    {
        partitionIndex = partition(A, low, high); 
        quickSort(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    int A[] = {9, 4, 4, 8, 7, 5, 6};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: ");
    printArray(A, n);

    quickSort(A, 0, n - 1);

    printf("Sorted array: ");
    printArray(A, n);

    return 0;
}
