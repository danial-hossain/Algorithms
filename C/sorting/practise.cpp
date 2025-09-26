#include <bits/stdc++.h>
using namespace std;
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high, int n)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
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

   
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    if (j == n / 2)
    {
        cout << A[j]<<endl;
    }
    return j;
}

void quickSort(int A[], int low, int high, int n)
{
    int partitionIndex; 

    if (low < high)
    {
        partitionIndex = partition(A, low, high, n);
        quickSort(A, low, partitionIndex - 1, n); 
        quickSort(A, partitionIndex + 1, high, n); 
    }
}

int main()
{
    
    int A[] = {9, 4, 4, 8, 7, 5, 6};
 
    int
        n = 7;
    printArray(A, n);
    quickSort(A, 0, n - 1, n);
    printArray(A,n);

    return 0;
}
