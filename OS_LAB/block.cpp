#include <bits/stdc++.h>
using namespace std;


int firstfit(int b,int p,vector<int>block,vector<int>process)
{
    for(int i=0;i<p;i++)
    {
        int flag = false;
        for(int j=0;j<b;j++)
        {
            if(process[i]<=block[j])
            {
                flag=true;
                cout<<"\n"<<block[j]<<"KB Block allocated to Process "<<process[i];
                block[j]-=process[i];
                if(block[j]>0)
                {
                    cout<<"\n"<<block[j]<<"KB Hole Created";
                }
                break;
            }
        }
        if(!flag)
        {
            cout<<"\n Unable to Allocate Memory For Process "<<process[i]<<'\n';
        }
    }
    return p;
}
static bool compare(int a, int b)
{
    return a<b;
}
int bestfit(int b,int p,vector<int>block,vector<int>process)
{

    // for(int i=0;i<b;i++)
    // {
    //     cout<<block[i]<<" ";
    // }
    cout<<'\n';
    for(int i=0;i<p;i++)
    {
        int flag = false;
        sort(block.begin(),block.end());
        for(int j=0;j<b;j++)
        {
            //cout<<'\n'<<process[i]<<" "<<block[j]<<"\n";
            if(process[i]<=block[j])
            {
                flag=true;
                cout<<"\n"<<block[j]<<"KB Block allocated to Process "<<process[i];
                block[j]-=process[i];
                if(block[j]>0)
                {
                    cout<<"\n"<<block[j]<<"KB Hole Created";
                }
                break;
            }
        }
        if(!flag)
        {
            cout<<"\n Unable to Allocate Memory For Process "<<process[i]<<'\n';
        }
    }
    return p;
}


int worstfit(int b,int p,vector<int>block,vector<int>process)
{

    for(int i=0;i<p;i++)
    {
        int flag = false;
        sort(block.begin(),block.end(),greater<int>());
        for(int j=0;j<b;j++)
        {
            if(process[i]<=block[j])
            {
                flag=true;
                cout<<"\n"<<block[j]<<"KB Block allocated to Process "<<process[i];
                block[j]-=process[i];
                if(block[j]>0)
                {
                    cout<<"\n"<<block[j]<<"KB Hole Created";
                }
                break;
            }
        }
        if(!flag)
        {
            cout<<"\n Unable to Allocate Memory For Process "<<process[i]<<'\n';
        }
    }
    return p;
}


int main()
{
    int p, b, choice;
    cout << "\n Enter the number of Memory Blocks";
    cin >> b;
    vector<int> block(b, 0);
    for (int i = 0; i < b; i++)
    {
        cout << "\nEnter Block " << i + 1 << " Size in KB";
        cin >> block[i];
    }
    cout << "\n Enter the number of Process";
    cin >> p;
    vector<int> process(p, 0);
    for (int i = 0; i < p; i++)
    {
        cout << "\nEnter Process " << i + 1 << " Size in KB";
        cin >> process[i];
    }
    while (1)
    {
        cout << "\n1.First Fit\n2.Best Fit\n3.Worst Fit\n4.Break";
        cin >> choice;
        switch (choice)
        {
        case 1:
            firstfit(b, p, block, process);
            break;
        case 2:
            bestfit(b, p, block, process);
            break;
        case 3:
            worstfit(b, p, block, process);
            break;
        case 4:
            exit(1);
            break;
        }
    }
    return 0;
}