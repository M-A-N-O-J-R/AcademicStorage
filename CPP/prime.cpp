#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    for(int i=2;i<100;i++)
    {
        int flag=1;
        int k=sqrt(i);
        for(int j=2;j<=k;j++)
        {
            if(i%j==0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        cout<<i<<endl;
    }
    return 0;
}