#include <bits/stdc++.h>
using namespace std;
int Quick(int arr[], int start, int end)
{
    int pivot = start;
    int i = start + 1;
    int j = end;
    do
    {
        while (arr[pivot] >= arr[i])
        {
            i++;
        }
        while (arr[pivot] < arr[j])
        {
            j--;
        }

        if (i < j)
        {
            int temp;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i < j);
    int temp;
    temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    if (j == (start + end) / 2)
        cout << arr[j];
    return j;
}
void QuickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int pos = Quick(arr, start, end);
        QuickSort(arr, start, pos - 1);
        QuickSort(arr, pos + 1, end);
    }
}
int main()
{
    int arr[] = {2, 4, 1, 9, 4, 3, 6};
    QuickSort(arr, 0, 7 - 1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}