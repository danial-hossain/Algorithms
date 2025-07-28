#include <bits/stdc++.h>
using namespace std;
int MergeSort(int arr[], int start, int end, int mid)
{
    int i = start;
    int j = mid + 1;
    int k = start;
    int brr[200];
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            brr[k] = arr[i];
            i++;
            k++;
        }
      else
        {
            brr[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        brr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        brr[k] = arr[j];
        j++;
        k++;
    }

    for (int i = 0; i <= end; i++)
    {
        arr[i] = brr[i];
    }
}
void Merge(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        Merge(arr, start, mid);
        Merge(arr, mid + 1, end);
        MergeSort(arr, start, end, mid);
    }
}
int main()
{
    int arr[] = {2, 4, 1, 9, 4, 3, 6};
    Merge(arr, 0, 7 - 1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}