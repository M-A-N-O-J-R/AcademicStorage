int majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        map<int,int>_map;
        for(int i=0;i<nums.size();i++)
        {
            int n=nums[i];
            auto itr=_map.find(n);
            if(itr==_map.end())
            {
                _map[n]=1;
            }
            else
            {
                _map[n]++;
            }
        }
        int max_ans=0,max_val=0;
        for(auto itr=_map.begin();itr!=_map.end();++itr)
        {
           if(max_val<itr->second)
           {
              max_val=itr->second;
              max_ans=itr->first;
           }
        }
        
        return max_ans;
    }