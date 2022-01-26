#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<int, int>_map;
    vector <int>prime_vector{2,3,5,7,9,11,13};
    int n,k=0,i=0;
    cin>>n;
    vector <int>qs(n);
    for(auto itr=qs.begin();itr!=qs.end();++itr)
    {
        cin>>*itr;
    }
    vector <int>ans(n);
    for(auto itr=qs.begin();itr!=qs.end();++itr,i++)
    {
        auto itr2=find(_map.begin(),_map.end(),*itr);
        if(itr2==_map.end())
        {
            _map[*itr]=prime_vector[k];
            ans[i]=prime_vector[k];
            k++;
        }
        else
        {
           ans[i]=_map[*itr];
        }
    }
    cout<<"\n Question\n";
    for(auto itr=qs.begin();itr!=qs.end();++itr)
    {
        cout<<" "<<*itr;

    }
    cout<<"\nMap\n";
    for(auto itr=_map.begin();itr!=_map.end();++itr)
    {
        cout<<itr->first<<" "<<itr->second;

    }
    cout<<"\n Answer\n";
    for(auto itr=ans.begin();itr!=ans.end();++itr)
    {
        cout<<" "<<*itr;

    }
}