#include<iostream>
using namespace std;

int factorial(int n)
{
    if(n==0)
    return 1;
    else
    return n*factorial(n-1);
}

int fibo(int n)
{
    if(n==0 ||n==1)
    return n;
    else 
    return fibo(n-1)+fibo(n-2);
}

int power(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    else return a*power(a,b-1);
}
void decrease(int n)
{
    if(n==1)
    cout<<1<<" ";
    else
   { cout<<n<<" ";
    decrease(n-1);
   }
}

void increase(int n)
{
    if(n==1)
    {
        cout<<1<<" ";
    }
    else
    { 
        increase(n-1);
        cout<<n<<" ";
    }
}
int main()
{
  int x=6;
  //int y=factorial(x);
//   int y=fibo(x);
// int y = power(7,3);
  decrease(5);
  cout<<endl;
  increase(7);
}