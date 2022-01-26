#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n=9;
    string s="";
    while(n>0)
    {
        int x=n%2;
        s=char(x+'0')+s;
        n=n/2;
    }
   cout<<s;
    return 0;
}

