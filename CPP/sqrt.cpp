#include<iostream>
using namespace std;

int findSqrt(int x)
{
    int low=0,high=x,mid=0,ans;
    while(low<=high)
    {
        mid=(low+high)/2;
        cout<<"\n"<<mid;
        if((mid*mid)==x)
        {
            ans=mid;
            break;
            
        }
        else if(mid*mid>x)
        {
            high=mid-1;
            ans=mid;
        }
        else
        {
            low=mid+1;
            ans=mid;
        }
    }
    return mid;
}

int main()
{
    int x=8;
    int y = 15,flag=0;
    int low=0,high=5;
    y=findSqrt(x);
    cout<<endl<<y;
    return 0;
}