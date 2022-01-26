#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p, fs, f, add = 5000;
    cout << "\nEnter The Number Of Pages";
    cin >> p;
    cout << "\nEnter The Number Of Frames";
    cin >> f;
    cout << "\nEnter The Frame Size";
    cin >> fs;
    int page[p], hash[f],f_addr[f];
    memset(hash, -1, sizeof(hash));
    for (int i = 0; i < p; i++)
    {
        page[i] = -1;
    }
    for(int i=0;i<f;i++)
    {
        f_addr[i] = add;
        add+=fs;
    }
    int fn = rand() % f, i = 0, pg, off, flag = 1;
    while (i < p)
    {
        if (hash[fn] == -1)
        {
            page[i] = fn;
            hash[fn]=1;
            i++;
        }
        fn = rand() % f;
    }
    cout << "\nPAGE"
         << "\t\t"
         << "F_NO"
         << "\t\t"
         << "B_ADDR"
         << "\t\t";
    for (int i = 0; i < p; i++)
    {
        cout << "\n"
             << i + 1 << "\t\t" << page[i]+1 << "\t\t" << f_addr[page[i]] << "\t\t";
    }

    while (flag == 1)
    {
        cout << "\nEnter The Page Number";
        cin >> pg;
        if (pg > p)
        {
            cout << "\nInvalid Page Number";
        }
        else
        {
            flag = 0;
            break;
        }
    }
    flag = 1;
    while (flag == 1)
    {
        cout << "\nEnter The Offset";
        cin >> off; 
        if (off > fs-1)
        {
            cout << "\nInvalid Offset ";
        }
        else
        {
            flag = 0;
            break;
        }
    }
    int addr=0;
    addr=f_addr[page[pg-1]]+off;
    cout<<"\n Physical address: "<<addr<<"\n";
    return 0;
}