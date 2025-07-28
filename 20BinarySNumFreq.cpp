#include<bits/stdc++.h>
using namespace std;
int BinaryFreqCountL(int arr[],int start,int end,int key){
    int count=0;
    while(start<=end)
    {
     
        int mid=(start+end)/2;
     
        if(key==arr[mid])
        {
           
            ++count;
            end=mid-1;
        }
       else if(key<arr[mid])
        {
           
            end=mid-1;
        }
        else if(key>arr[mid])
        {
            
            start=mid+1;
        }
    }
    return count;
}
int BinaryFreqCountR(int arr[],int start,int end,int key){
    int count=0;
    while(start<=end)
    {
     
        int mid=(start+end)/2;
     
        if(key==arr[mid])
        {
           
            ++count;
            start=mid+1;
        }
       else if(key<arr[mid])
        {
           
            end=mid-1;
        }
        else if(key>arr[mid])
        {
            
            start=mid+1;
        }
    }
    return count;
}
int main()
{
    int arr[]={0,0,1,1,0};
    int count1=BinaryFreqCountL(arr,0,5-1,1);
    int count2=BinaryFreqCountR(arr,0,5-1,1);
    cout<<(count1+count2-1);
}