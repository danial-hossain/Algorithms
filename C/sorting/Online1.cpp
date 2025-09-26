#include<stdio.h>
int firstbinarySearch(int array[],int n,int find){
   int beg=0,end=n-1,result=-1;
   int mid;
   while(beg<=end)
   {
        mid=(beg+end)/2;
        if(find==array[mid])
       {

        end=mid-1;
        result=mid;

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
int lastbinarySearch(int array[],int n,int find){
   int beg=0,end=n-1,result=-1;
   int mid;
   while(beg<=end)
   {
        mid=(beg+end)/2;
        if(find==array[mid])
       {

        beg=mid+1;
        result=mid;

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
void binarySearch(int array[],int n,int find)
{
    int total=lastbinarySearch(array,n,find)-firstbinarySearch(array,n,find)+1;
    printf("%d",total);

}
int main()
{
    int array[]={0,0,1,1,1,1};
    int n=sizeof(array)/sizeof(array[1]);
   // int n=7;
    int find=1;
    binarySearch(array,n,find);
}