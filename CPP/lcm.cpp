#include<iostream>
using namespace std;

int findLcm(int a=3,int b=2) 
{

    int lcm=max(a,b);
    int flag=0;
    while(flag==0)
    {
        if(lcm%a==0 &&lcm%b==0)
        {
            flag=1;
            break;
        }
        else
        lcm++;
    }
    cout<<"LCM  "<<lcm<<endl;
    return lcm; 
}
int main()
{
    int x=5;
    x=findLcm(4);
}