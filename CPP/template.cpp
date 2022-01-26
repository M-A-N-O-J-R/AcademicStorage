#include<iostream>
#include<vector>
using namespace std;

template<typename T>

void bubbleSort(vector<T> arr)
{
    cout<<"BEFORE SORTING"<<endl;
    for(int i = 0; i < arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int count=0;
    for(int i = 0; i < arr.size()-1;i++)
    {

        for(int j = 0; j < arr.size()-1-i;j++)
        {
            count++;
            if(arr[j]>arr[j+1])
            {
                arr[j]=arr[j+1]+arr[j];
                arr[j+1]=arr[j]-arr[j+1];
                arr[j]=arr[j]-arr[j+1];
            }
        }
    }
    cout<<" count "<<count<<endl;
    cout<<"AFTER SORTING"<<endl;
    for(int i = 0; i < arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    cout<<endl<<endl;
    vector<int>arr;
    bubbleSort<int>({9,56,3,25,2});
    cout<<endl<<endl;
    bubbleSort<char>({'g','y','a','r','i'});
    cout<<endl<<endl;
    bubbleSort<float>({3.55,6.77,5.66,9.00,4.66});
    cout<<endl<<endl;
}