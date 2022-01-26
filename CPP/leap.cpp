#include <iostream>
using namespace std;
void leapYear(int year)
{
    if(year%4==0)
    {
        if(year%100==0)
        {
           if(year%400==0)
           {
               cout<<"Leap Year"<<" "<<year<<endl;
           }
           else
          cout<<"NOT LEAP YEAR"<<" "<<year<<endl;;
        }  
        else
          cout<<"LEAP YEAR"<<" "<<year<<endl;;
    }
    else{
        cout<<"NOt Leap Year"<<" "<<year<<endl;;
    }
}
int main()
{

    for(int i =1950;i<=2000;i++){
         leapYear(i);
    }

}