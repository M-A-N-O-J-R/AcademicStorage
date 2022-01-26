#include <iostream>//mail questions
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    string line;
    for(int i=0;i<t;i++)
    {
      int k,n,j=1;
      cin>>n>>k;
      vector<long long int>qs(n);
      long long int sum=1;
      
      while(sum>0)
      {
          if(j==1)
          {
              sum=0;
          }
        if(j<=n)
        {
          cin>>qs[j];
          cout<<qs[j]<<" ";
          sum=sum+qs[j];
          
        }
        j++;
        sum=sum-k;
      }
      cout<<"sum :"<<sum<<" "<<" count "<<j<<endl;
    }
	return 0;
}
