#include<iostream>
#include<string>
using namespace std;


int main()
{
    bool y=false;
    int n=10;
    string s="";
    while(n>0)
    {
        y=n%2;
        int x=n%2;
        s=char(x+'0')+s;
        n=n>>1;
        
    }
    cout<<s<<endl;
    n=10;
    y=(n&1<<1);
    cout<<y;
}