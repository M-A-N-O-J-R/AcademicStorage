#include<iostream>
using namespace std;

int main()
{
    int row=3,col=3;
    cout<<"enter element"<<endl;
    int mat[row][col];
    for(int i=0;i<row;i++)
   { 
    for(int j=0;j<col;j++)
    {
        cin>>mat[i][j];
    }
   }
   cout<<endl;    
    for(int i=0;i<row;i++)
   { 
    for(int j=0;j<col;j++)
    {
        cout<<mat[i][j]<<" ";
    }
    cout<<endl;
   }

   for(int j=0;j<col;j++)
    {
        if(j%2==0)
        {
            for(int i=0;i<row;i++)
            cout<<mat[i][j];
        }
        else
        {
            for(int i=row-1;i>=0;i--)
            cout<<mat[i][j];
        }
    }

}