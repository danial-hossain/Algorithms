#include <bits/stdc++.h>
using namespace std;
int sum1(int n)
{

    int sum = 0;

    while (n != 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }

    return sum;
}
void Merge(int arr[], int start, int end, int mid)
{
    int i = start;
    int j = mid + 1;
    int k = start;
    int brr[100];
    while (i <= mid && j <= end)
    {
        if (sum1(arr[i]) < sum1(arr[j]))
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
    for (int i = start; i <= end; i++)
    {
        arr[i] = brr[i];
    }
}
void MergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
            int mid = (start + end) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, end, mid);
    }
}
int main()
{
    int arr[] = {9,21,7,25,31};
    MergeSort(arr, 0, 5 - 1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
}