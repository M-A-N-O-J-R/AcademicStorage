#include<iostream>
using namespace std;
/*
int maxofintnumbers(int a, int b)
{

return (a > b)? a:b;
}
float maxoffloatnumbers(float a, float b)
{

return (a > b)? a:b;
}
char maxofchar(char a, char b)
{

 return (a > b)? a:b;
}
*/
/*template <class T>
T maxoftwo(T a, T b)
{
 return (a>b)? a:b;
}
*/
template <typename T1, typename T2>
T2 maxoftwo(T1 a, T2 b)
{
 //cout<<"b= "<<b<<endl;
 return (a>b)? a:b;

}
int main()
{
 //int max=maxofintnumbers(-2,-3);
 //int max=maxofnumbers(-2.5,-3.8);

 //int max=maxoftwo(-2,-3);
 int max=maxoftwo<int,char>(125,'a');
 cout<<"The maximum of two integer numbers is "<<max<<endl;
 //float max1=maxoffloatnumbers(-2.5,-3.8);
 //cout<<"The maximum of two float numbers is "<<max1<<endl;

 float max1=maxoftwo(-2.5,-3.8);
 cout<<"The maximum of two float numbers is "<<max1<<endl;
 
 //char max2=maxofchar('r', 'j');
 //cout<<"The maximum of two characters is "<<max2<<endl;

 char max2=maxoftwo('c','d');
 cout<<"The maximum of two char numbers is "<<max2<<endl;

 return 0;
}