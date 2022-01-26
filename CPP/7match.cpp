#include<bits/stdc++.h>
using namespace std;


int main()
{
	map<int,int>_map;
	_map.insert(pair<int,int>(0,6));
	_map.insert(pair<int,int>(1,2));
	_map.insert(pair<int,int>(2,5));
	_map.insert(pair<int,int>(3,5));
	_map.insert(pair<int,int>(4,4));
	_map.insert(pair<int,int>(5,5));
	_map.insert(pair<int,int>(6,6));
	_map.insert(pair<int,int>(7,3));
	_map.insert(pair<int,int>(8,7));
	_map.insert(pair<int,int>(9,6));
	long long int t,y=0;
	long long int total;
	long long int  ans;
    string n;
	cin>>t;
	while(t--)
	{
		total=0,ans=0;
		cin>>n;
		int j=0;
		while(n[j]!='\0')
		{
			y=(n[j]-'0')%10;
			total+=_map[y];
			j++;
		}
		while(total!=0)
		{
          if(total%2==0)
		  {
            ans=ans*10+1;
			total=total-2;
		  }
		  else
		  {
		    ans=ans*10+7;
			total=total-3;
		  }
          
		}
		cout<<ans<<endl;
	}

}