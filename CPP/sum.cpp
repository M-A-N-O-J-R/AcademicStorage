#include<iostream>
#include<vector>
using namespace std;


int main()
{
    vector<int>arr{1,2,3,4};
    for(auto itr=arr.begin();itr!=arr.end();++itr)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;
    vector<int>arr2(arr.size());
    arr2[0]=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        arr2[i]=arr[i]+arr2[i-1];
    }
    for(auto itr=arr2.begin();itr!=arr2.end();++itr)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;
    int n=arr.size();
    vector<int>arr3(n+1,0);
    arr3[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        arr3[i]=arr[i]+arr3[i+1];
    }
    for(auto itr=arr3.begin();itr!=arr3.end();++itr)
    {
        cout<<*itr<<" ";
    }
    cout<<endl;
}