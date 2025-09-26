#include<stdio.h>
int binarySearch(int array[],int n,int find){
   int beg=0,end=n-1,result=-1;
   int mid;
   while(beg<=end)
   {
        mid=(beg+end)/2;
        if(find==array[mid])
       {
        result=mid;
        return result;

       }
       else if(find<array[mid])
       {
           end=mid-1;
       }
       else{
        beg=mid+1;
       }
   }


   return result;


}
int main()
{
    int array[]={1,3,5,7,10,12};
    int n=sizeof(array)/sizeof(array[1]);
   // int n=7;
    int find=7;
    printf("%d",binarySearch(array,n,find));
}
