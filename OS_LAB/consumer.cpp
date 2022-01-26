#include <bits/stdc++.h>
using namespace std;
#define MAX 10

vector<int> semaphore(3);
vector<int> buffer(MAX, 0);
int in = 0, out = 0, counter = 0;

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
int producer(int p)
{
    wait(semaphore[0]);
    wait(semaphore[2]);

    buffer[in] = p;
    cout<<"\n Item Produced "<<p;
    in=(in+1)%MAX;
    counter++;

    signal(semaphore[1]);
    signal(semaphore[2]);
    return p;
}

int consumer()
{
    wait(semaphore[1]);
    wait(semaphore[2]);

    int p = buffer[out];
    cout<<"\n Item Consumed "<<p;
    out=(out+1)%MAX;
    counter--;

    signal(semaphore[0]);
    signal(semaphore[2]);
    return p;
}

int main()
{
    srand(time(NULL));
    semaphore[0] = MAX; // empty semaphore
    semaphore[1] = 0;   // full semaphore
    semaphore[2] = 1;   // binary semaphore
    for(int i=0;i<10;i++)
    {
        int x = rand()%100
        if(x%2==0)//producer process
        {
            if(semaphore[1]==MAX)
            {
                cout<<"\n Buffer FULL";
            }
            else
            {
                producer(in+1);
            }
        }
        else
        {
            if(semaphore[0]==MAX)
            {
                cout<<"\n Buffer Empty";
            }
            else
            {
                consumer();
            }
        }
        
    }
    return 0;
}