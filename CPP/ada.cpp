
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int  n;
    cin>>n;
    vector<int>time(n);
    for(auto itr=time.begin(); itr != time.end();++itr)
     {
         cin>>*itr;
     }
     cout<<endl;
     for(auto itr=time.begin(); itr != time.end();++itr)
     {
         cout<<*itr<<" ";
     }
     int b1=0,b2=0;
     sort(time.rbegin(),time.rend());
     cout<<endl;
        for(auto itr=time.begin(); itr != time.end();++itr)
     {
         cout<<*itr<<" ";
     }
     int time_total=0;
     for(auto itr=time.begin(); itr != time.end();++itr)
     {
        if(b1<b2){
            b1+=*itr;
        }
        else{
            b2+=*itr;
        }
     }
     time_total=max(b1,b2);
     cout<<"\nTime"<<time_total;
}