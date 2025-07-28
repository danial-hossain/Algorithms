#include <bits/stdc++.h>
using namespace std;
void InsertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j=i-1;
        int key=arr[i];
        while( j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main()
{
    int arr[] = {2, 4, 1, 9, 4, 3, 6};
    InsertionSort(arr, 7);
    for(auto i:arr)
    {
        cout<<i << " ";
    }
}