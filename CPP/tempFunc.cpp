#include<iostream>
#include<vector>
#include<string>
using namespace std;



template<typename T>
vector<T> inputArr()  //TEMPLATE FUNCTION 1
{
    int n;
    cout<<"\nNo of elements -->";
    cin>>n;
    cout<<endl;
    vector<T> arr(n);
     for (int i = 0; i<n;i++)
    {
        cout<<"Element "<<i+1<<"-->";
        cin>>arr[i];
    }
    return arr;
}

template<typename T>
void printArr(vector<T> arr)//TEMPLATE FUNCTION 2
{
    for (int i = 0; i < arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

template<typename T>
vector<T> bubbleSort(vector<T> arr)//TEMPLATE FUNCTION 3
{
    for(int i = 0; i < arr.size()-1;i++)
    for(int j = 0; j < arr.size()-1-i;j++)
    {
        if(arr[j]>arr[j+1])
        {
            swap(arr[j],arr[j+1]);
        }

    } 
    return arr;
}

int main()
{
   int choice=1;
   while(choice!=4)
{
   cout<<"\n\n ENTER CHOICE \n1.INTEGER \n2.CHAR \n3.FLOAT \n4.EXIT";
   cin>>choice;
   switch(choice)
   {
       case 1:{
                cout<<"\nINTEGER ARRAY\n";
                vector<int> arr;
                arr=inputArr<int>();
                cout<<"\nBEFORE SORTING INTEGER ARRAY\n";
                printArr<int>(arr);
                arr=bubbleSort<int>(arr);
                cout<<"\nAFTER SORTING INTEGER ARRAY\n";
                printArr<int>(arr);
             }
             break;

       case 2:{
                cout<<"\nCHAR ARRAY\n";
                vector<char> arr;
                arr=inputArr<char>();
                cout<<"\nBEFORE SORTING CHAR ARRAY\n";
                printArr<char>(arr);
                arr=bubbleSort<char>(arr);
                cout<<"\nAFTER SORTING CHAR ARRAY\n";
                printArr<char>(arr);
             }
             break;
        
        case 3:{
                cout<<"\nFLOAT ARRAY\n";
                vector<float> arr;
                arr=inputArr<float>();
                cout<<"\nBEFORE SORTING float ARRAY\n";
                printArr<float>(arr);
                arr=bubbleSort<float>(arr);
                cout<<"\nAFTER SORTING float ARRAY\n";
                printArr<float>(arr);
             }
             break;

        case 4: cout<<"\nQuitting..\n";
                break;
        default: cout<<"Wrong choice Enter Again";       
   }
}
 return 0;  
}