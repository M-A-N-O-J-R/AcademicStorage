#include <bits/stdc++.h>
using namespace std;

int fifo(vector<int> pages, int pg, int capacity)
{
    int fault = 0, pos = 0;
    vector<int> pg_table(capacity, -1);

    for (int i = 0; i < pg; i++)
    {
        int flag = 1;
        if (i < capacity)
        {
            pg_table[i] = pages[i];
            fault++;
        }
        else
        {
            for (int j = 0; j < capacity; j++)
            {
                if (pages[i] == pg_table[j])
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                pg_table[fault % capacity] = pages[i];
                fault++;
            }
        }
        if (flag)
        {
            for (int i = 0; i < capacity; i++)
            {
                cout << pg_table[i] << "   ";
            }
            cout << "page fault\n";
        }
        else
        {
            for (int i = 0; i < capacity; i++)
            {
                cout << pg_table[i] << "   ";
            }
            cout << '\n';
        }
    }
    return fault;
}
int lru(vector<int> pages, int pg, int capacity)
{
    int fault = 0, time = 0;
    vector<pair<int, int>> pg_table(capacity, {-1, -1});

    for (int i = 0; i < pg; i++)
    {
        int flag = 1;
        if (i < capacity)
        {
            pg_table[i].first = pages[i];
            pg_table[i].second = time++;
            fault++;
        }
        else
        {
            for (int j = 0; j < capacity; j++)
            {
                if (pages[i] == pg_table[j].first)
                {
                    flag = 0;
                    pg_table[j].second=time++;
                    break;
                }
            }
            if (flag)
            {
                int min_i=-1,minValue=INT_MAX;
                for (int j = 0; j < capacity; j++)
                {
                    if (pg_table[j].second<minValue)
                    {
                        min_i=j;
                        minValue=pg_table[j].second;
                    }
                }
                pg_table[min_i].first=pages[i];
                pg_table[min_i].second=time++;
                fault++;
            }
        }
        if (flag)
        {
            for (int i = 0; i < capacity; i++)
            {
                cout << pg_table[i].first << "   ";
            }
            cout << "page fault\n";
        }
        else
        {
            for (int i = 0; i < capacity; i++)
            {
                cout << pg_table[i].first << "   ";
            }
            cout << '\n';
        }
    }
    return fault;
}
int main()
{
    int capacity, pg;
    cout << "\n Enter Capacity ";
    cin >> capacity;

    cout << "\n Enter Number of Pages ";
    cin >> pg;
    vector<int> pages(pg, 0);
    cout << "\n Enter of Page Sequence ";

    for (int i = 0; i < pg; i++)
    {
        cin >> pages[i];
    }

    vector<int> fault(3, 0);
    cout<<"\nFIFO\n";
    fault[0] = fifo(pages, pg, capacity);
    cout<<"\nLRU\n";
    fault[1] = lru(pages, pg, capacity);

    cout << "\n\n Page Fault \n";
    cout << "\nFifo : " << fault[0];
    cout << "\nLru : " << fault[1];

    return 0;
}