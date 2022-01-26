#include <bits/stdc++.h>
using namespace std;

int sequential(vector<int> &files)
{
    int blk, len, cnt = 0;
    cout << "\n Enter Starting Block";
    cin >> blk;
    cout << "\n Enter Total Size";
    cin >> len;
    for (int i = blk; i < blk + len; i++)
    {
        if (files[i] == -1)
        {
            cnt++;
        }
    }
    if (cnt == len)
    {
        cout << "\nSequential allocation \n";
        for (int i = blk; i < (blk + len); i++)
        {
            files[i] = 1;
            cout << i << "\t\t" << files[i] << "\n";
        }
    }
    else
    {
        cout << "\n Sequential allocation not Possible\n";
    }
    return true;
}
int indexed(vector<int> &files)
{
    int idx, size, cnt = 0;
    vector<int> index(50, -1);
x:
    cout << "\n Enter the Index Block";
    cin >> idx;
    if (files[idx] == -1)
    {
        cout << "\n Enter the Size";
        cin >> size;
    }
    else
    {
        cout << "\n Memory not Available";
        goto x;
    }
y:
    cout << "\n Enter the File Numbers";
    cnt = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> index[i];
        if (files[index[i]] != -1)
        {
            cout << "\n Memory not Available";
            goto y;
        }
        cnt++;
    }
    cout << "\n Indexed Memory Allocation\n";
    if (cnt == size)
    {
        for (int i = 0; i < size; i++)
        {
            files[index[i]] =1;
            cout << idx << " ----> " << index[i] << " : " << files[index[i]] << '\n';
        }
    }
    else
    {
        cout << "\n Memory not Available";
        goto y;
    }
    return true;
}
int main()
{
    vector<int> files(200, -1);
    sequential(files);
    indexed(files);
    return 0;
}