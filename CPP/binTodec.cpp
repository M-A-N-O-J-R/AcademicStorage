#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;


int main()
{
    string s="1000";
    int j = s.length()-1;
    int i=0;
    int res=0,x=0;
    while(j>=0)
    {
       int x= s[j]-'0';
       x=x*pow(2,i);
       j--;
       i++;
       res+=x;
    }
     cout<<res<<endl;
return 0;
}