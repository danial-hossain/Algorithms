#include <bits/stdc++.h>
using namespace std;
void Merge(int arr[], int start, int end, int mid)
{
    int i = start;
    int j = mid + 1;
    int k = start;
    int brr[100];
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            brr[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            brr[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        brr[k] = arr[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        brr[k] = arr[j];
        k++;
        j++;
    }
    for (int i = 0; i <= end; i++)
    {
        arr[i] = brr[i];
    }
}
void MergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        int mid1 = (start + mid) / 2;
        int mid2 = (mid + end) / 2;
        MergeSort(arr, start, mid1);
        MergeSort(arr, mid1 + 1, mid2);
        MergeSort(arr, mid2 + 1, end);
        Merge(arr, start, end, mid);
    }
}
int main()
{
    int arr[] = {2, 1, 4, 5, 6, 7, 9};
    MergeSort(arr, 0, 7 - 1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}