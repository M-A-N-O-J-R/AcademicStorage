#include <iostream>
using namespace std;
bool isSorted(int arr[],int n)
{
    if(n==0||n==1) 
    return true;
     if(arr[0]<arr[1]&&isSorted(arr+1,n-1))
     {
         return true;
     }
     return false;
}
int linearSearch(int arr[],int n,int key,int i)
{
    if(i==n)
    {
        return -1;
    }
    if(arr[i]==key)
    {
        return i;
    }
    return linearSearch(arr,n,key,i+1);
}
int main() 
{
    int arr[5]={1,2,3,8,15};
    bool x = isSorted(arr,5);
    int pos = linearSearch(arr,5,159,0);
    cout<<pos;
}