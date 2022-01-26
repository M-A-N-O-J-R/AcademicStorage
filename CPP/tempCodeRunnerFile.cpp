#include <iostream> 
using namespace std; 
  
template <typename T> 
class arrayClass { 
  T *ptr; 
  int size; 
public: 
    arrayClass(T arr[], int n); 
    void bubbleSort();
    void printArr(); 
}; 
  
template <typename T> 
arrayClass<T>::arrayClass(T arr[], int n) { 
    ptr = new T[n]; 
    size = n; 
    for(int i = 0; i < size; i++) 
        ptr[i] = arr[i]; 
} 

template <typename T>
void arrayClass<T>::bubbleSort(){
  {
	for(int i=0;i<size-1;++i){
		for(int j=0;j<size-i-1;++j){
			if(ptr[j]>ptr[j+1]){
				T temp = ptr[j+1];
				ptr[j+1] = ptr[j];
				ptr[j] = temp;
			}
		}
	}
}

}
  
template <typename T> 
void arrayClass<T>::printArr() { 
    for (int i = 0; i < size; i++) 
        cout<<" "<<*(ptr + i); 
    cout<<endl; 
} 
  

int menu()
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
                int n;
                cout<<"\nNo of elements -->";
                cin>>n;
                cout<<endl;
                int arr[n];
                for (int i = 0; i<n;i++)
                 {
                    cout<<"Element "<<i+1<<"-->";
                    cin>>arr[i];
                 }
                arrayClass<int>a(arr,n);
                cout<<"\nBEFORE SORTING INTEGER ARRAY\n";
                a.printArr();
                a.bubbleSort();
                cout<<"\nAFTER SORTING INTEGER ARRAY\n";
                a.printArr();
             }
             break;

       case 2:{
                cout<<"\nCHAR ARRAY\n";
                int n;
                cout<<"\nNo of elements -->";
                cin>>n;
                cout<<endl;
                char arr[n];
                for (int i = 0; i<n;i++)
                 {
                    cout<<"Element "<<i+1<<"-->";
                    cin>>arr[i];
                 }
                arrayClass<char>a(arr,n);
                cout<<"\nBEFORE SORTING INTEGER ARRAY\n";
                a.printArr();
                a.bubbleSort();
                cout<<"\nAFTER SORTING INTEGER ARRAY\n";
                a.printArr();
                
             }
             break;
        
        case 3:{
                cout<<"\nFLOAT ARRAY\n";
                int n;
                cout<<"\nNo of elements -->";
                cin>>n;
                cout<<endl;
                float arr[n];
                for (int i = 0; i<n;i++)
                 {
                    cout<<"Element "<<i+1<<"-->";
                    cin>>arr[i];
                 }
                arrayClass<float>a(arr,n);
                cout<<"\nBEFORE SORTING INTEGER ARRAY\n";
                a.printArr();
                a.bubbleSort();
                cout<<"\nAFTER SORTING INTEGER ARRAY\n";
                a.printArr();
                
             }
             break;

        case 4: cout<<"\nQuitting..\n";
                break;
        default: cout<<"Wrong choice Enter Again";       
   }
}
 return 0;  
}

int main()
{
    menu();
    return 0;
}