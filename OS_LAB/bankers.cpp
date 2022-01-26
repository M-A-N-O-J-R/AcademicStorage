#include <bits/stdc++.h>
using namespace std;

int allocated[100][100];
int maximum[100][100];
int need[100][100];
vector<int> available(10, 0);
vector<int> work(10, 0);
vector<bool> finished(100, false);
vector<int> res;

int safety(int n, int m)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (!finished[i])
            {
                int flag = true;
                for (int j = 0; j < m; j++)
                {
                    if (work[j] < need[i][j])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    for (int j = 0; j < m; j++)
                    {
                        work[j] += allocated[i][j];
                    }
                    finished[i] = true;
                    res.push_back(i + 1);
                }
            }
        }
    }
    if (res.size() != n)
    {
        cout << "\n Deadlocks.....!";
    }
    else
    {
        cout << "\n Safe State --> ";
        for (auto i : res)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return n;
}

int main()
{
    int n, m;
    cout << "\n Enter ther number of process";
    cin >> n;
    cout << "\n Enter ther number of Resources";
    cin >> m;
    cout << "\n Enter the Available Resources";
    for (int i = 0; i < m; i++)
    {
        cin >> available[i];
        work[i] = available[i];
    }
    cout << "\n Enter the Allocated Resources";

    for (int i = 0; i < n; i++)
    {
        cout << "\n Process " << i + 1 << '\n';
        for (int j = 0; j < m; j++)
        {
            cin >> allocated[i][j];
        }
    }

    cout << "\n Enter the Maximum Required Resources";

    for (int i = 0; i < n; i++)
    {
        cout << "\n Process " << i + 1 << '\n';
        for (int j = 0; j < m; j++)
        {
            cin >> maximum[i][j];
            need[i][j] = maximum[i][j] - allocated[i][j];
        }
    }
    safety(n, m);
    return 0;
}