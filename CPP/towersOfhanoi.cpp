#include<iostream>
using namespace std;

void towersOfhanoi(int n,char A,char B,char C)
{
    if(n==0)
    {
        return;
    }
    towersOfhanoi(n-1,A,C,B);
    cout<<"Move Disk"<<n<<"From"<<A<<"To"<<C<<endl<<endl;
    towersOfhanoi(n-1,B,A,C);
}
int main()
{
    int n=3;
    towersOfhanoi(n,'A','B','C');
}