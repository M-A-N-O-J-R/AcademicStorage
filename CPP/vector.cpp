#include<iostream>
#include<vector>

using namespace std;

int main()
{
 int n=5;
 vector <int> arr;
 map<int,int> map_pos;
 map_pos.insert(pair<int,int>(0,10));
 map_pos.insert(pair<int,int>(2,20));
 map_pos.insert(pair<int,int>(3,30));
 map_pos.insert(pair<int,int>(4,40));
 map_pos[5]=50;
 for(auto itr=map_pos.begin();itr!=map_pos.end();++itr)
 {
     cout<<itr->first<<" "<<itr->second<<endl;
 }
}
  