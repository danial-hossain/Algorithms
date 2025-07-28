#include <bits/stdc++.h>
using namespace std;
int BinarySearch(int arr[], int size, int key)
{
    int pos = -1;
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            pos = mid;
            break;
        }

        if (arr[mid] < key)
            start = mid + 1;
        if (arr[mid] > key)
        {
            end = mid - 1;
        }
    }
    return pos;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int flag = BinarySearch(arr, 7, 1);
    if (flag == -1)
        cout << "Not Found";
    else
    {
        cout << "Found at " << flag;
    }
}