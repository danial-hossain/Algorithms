#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int arr[],int start,int end,int key)
{
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(key==arr[mid])
        {
            return mid;
        }
        if(key<arr[mid])
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
}
void InsertionSortBS(int arr[],int size)
{
    for(int i=1;i<=size;i++)
    {
        int j=i-1;
        int key=arr[i];
        int loc=BinarySearch(arr,0,j,key);
        while(j>=loc)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
int main()
{
    int arr[]={1,2,4,1,2,3,5};
    InsertionSortBS(arr,6);
    for(auto i: arr)
    {
        cout<<i<< " ";
    }
}