#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>value{7,1,3,6,4};
    int profit=0,buy=value[0];
    for(int i=1;i<value.size();i++)
    {
       if(value[i]<value[i-1])
       {
           profit+=value[i-1]-buy;
           buy=value[i];
       }
       cout<<profit<<endl;
    }
    profit=profit+(value.back()-buy);
    cout<<profit;
    return 0;
}