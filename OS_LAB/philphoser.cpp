#include <bits/stdc++.h>
using namespace std;
#define MAX 5

vector<int> semaphore(5, 1); // 1---->Available   0--->Not-Available
vector<int> ph(5, 0);      // 0--->Thinking   1---->Hungry  2----> Eating

int wait(int &s)
{
    while (s <= 0)
        ;
    s--;
    return s;
}
int signal(int &s)
{
    s++;
    return s;
}
int philosopher(int p)
{
    ph[p] = 1;
    cout << "\nPhilsopher " << p + 1 << " Hungry";
    wait(semaphore[p]);
    wait(semaphore[(p + 1) % 5]);

    ph[p] = 2;
    cout << "\nPhilsopher " << p + 1 << " Eating";

    signal(semaphore[p]);
    signal(semaphore[(p + 1) % 5]);

    ph[p] = 0;
    cout << "\nPhilsopher " << p + 1 << " Thinking";
    return p;
}
int main()
{
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        int x = rand();
        x = x % 5;
        switch (x)
        {
        case 0:
        {
            philosopher(x);
        }
        break;

        case 1:
        {
            philosopher(x);
        }
        break;

        case 2:
        {
            philosopher(x);
        }
        break;
        case 3:
        {
            philosopher(x);
        }
        break;
        case 4:
        {
            philosopher(x);
        }
        break;
        }
        cout<<"\n\n";
    }
    return 0;
}