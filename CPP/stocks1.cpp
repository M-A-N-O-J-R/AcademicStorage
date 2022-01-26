#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>value{7,1,5,3,8,4};
    int profit=0,min_price=value[0];
    for(auto itr=value.begin()+1;itr!=value.end();++itr)
    {
       if(min_price>*itr)
       {
           min_price=*itr;
       }
       else
       {
           if(*itr-min_price>profit)
           {
               profit=*itr-min_price;
           }
       }
       cout<<profit<<endl;
    }
    return 0;
}