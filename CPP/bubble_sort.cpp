#include<iostream>
#include<vector>
using namespace std;

vector <int> bubbleSort(vector<int> arr)
{
    for(int i=0;i<arr.size()-1;i++,cout<<endl)
    for(int j=0;j<arr.size()-1-i;j++)
    {
        cout<<i<<j<<" ";
        if(arr[j]>arr[j+1])
        {
            int temp =arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }

    }
    return arr;
}
vector<int> inputArray(int n)
{
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    return arr;
} 
int displayArr(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<"\t";
    }
    return 0;
}


int main()
{
    int n;
    cout<<"\nEnter Size";
    cin>>n;
    vector<int>arr(n);
    arr=inputArray(n);
    cout<<"\nBefore Sorting\n";
    displayArr(arr);
    cout<<"\n";
    arr=bubbleSort(arr);
    cout<<"\nAfter Sorting\n";
    displayArr(arr);
    return 0;
}