#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n=7;
    int temp=n;
    string str="";
    while(n)
    {
        int x=n%2;
        
        str=char(x+'0')+str;
        n/=2;
    }
    cout<<str<<endl;
    int count=0;
    while(temp)
    {
        if(temp&1!=0)
        count++;
        temp=temp>>1;
    }
    cout<<count<<endl;
}