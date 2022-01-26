#include<iostream>
using namespace std;


int main()
{
   int arr[5]={5,3,8,7,1};
   int n=5;
    for(int i=0;i<n-1;i++)
    {
        int min_i=i;
        for(int j=i+1;j<n;j++)
        if(arr[min_i]>arr[j])
        {
           min_i=j;
        }
        swap(arr[min_i],arr[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" "; 
    }

}