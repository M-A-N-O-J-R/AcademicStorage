
#include <iostream> 
using namespace std; 
  
template <typename T> 
class Array { 
  T *ptr; 
  int size; 
public: 
    Array(T arr[], int n); //constructor
    void bsort(); //Bubble sort fn
    void print(); 
}; 
  
template <typename T> //Template fn for array creation
Array<T>::Array(T arr[], int n) { 
    ptr = new T[n]; 
    size = n; 
    for(int i = 0; i < size; i++) 
        ptr[i] = arr[i]; 
} 

template <typename T>
void Array<T>::bsort(){// Template fn for Bsort
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
  
template <typename T> //Template fn for print
void Array<T>::print() { 
    for (int i = 0; i < size; i++) 
        cout<<" "<<*(ptr + i); 
    cout<<endl; 
} 
  
int main() { 
    int arr[5] = {5, 4, 3, 2, 1}; 
    char arr1[6]={'m','a','d','e','i','n'};
    Array<int> a(arr, 5); 
    Array<char> b(arr1,6);
    cout<< "before sorting: ";
    a.print();
    a.bsort();
    cout<< "after sorting: ";
    a.print();
    cout<< endl<<"before sorting: "; 
    b.print();
    b.bsort();
    cout<< "after sorting: ";
    b.print();
    return 0; 
} 

 
