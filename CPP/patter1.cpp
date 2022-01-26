#include<iostream>
using namespace std;

int main()
{
    int n=6;
    for(int i=n-1;i>=0;i--,cout<<endl)
    {
        for(int j=0;j<i;j++)
        {
            cout<<" ";
        }
        for(int j=i;j<n;j++)
        {
            cout<<'*';
        }
        
    }
    return 0;
}