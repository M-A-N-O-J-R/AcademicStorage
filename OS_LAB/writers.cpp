#include <bits/stdc++.h>
using namespace std;
#define MAX 10

int wrt_mutex = 1;
int mutex = 1;
int r_count = 0;
vector<int>buffer(100,0);

int wait(int &s)
{
    while (s <= 0);
    s--;
    return s;
}
int signal(int &s)
{
    s++;
    return s;
}

int writers()
{
    wait(wrt_mutex);
    int x = rand()%10;
     int val=rand();
    cout<<"\n Writers's Process writing "<<x<<"  "<<val;
   
    buffer[x]=val; 
    signal(wrt_mutex);
    return 1;
}

int readers()
{
    wait(mutex);
    r_count++;
    if(r_count ==1)
    {
        wait(wrt_mutex);
    }
    signal(mutex);
    int x=rand()%10;
    cout<<"\nReader Process Reading  "<<x<<"  "<<buffer[x];
    wait(mutex);
    r_count--;
    if(r_count ==0)
    {
        signal(wrt_mutex);
    }
    signal(mutex);
    return 1;
}
int main()
{
    buffer={10,9,8,7,6,5,4,3,2,1};
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int x=rand();
        if(x%2==0)//reader process
        {
            if(mutex==1)
            {
                readers();
            }
            else
            {
                cout<<"\n Currently Writing";
            }
        }
        else
        {
            if(mutex==1&&wrt_mutex==1)
            {
                writers();
            }
            else
            {
                cout<<"\n Currently Reading";
            }
        }

    }
    return 0;
}