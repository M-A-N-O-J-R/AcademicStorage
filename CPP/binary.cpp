#include<iostream>
using namespace std;

string binary_sum(string num1, string num2)
{
    int i=num1.length()-1;
    int j=num2.length()-1;
    int s=0;
    string result="";
    while(i>=0 || j>=0|| s==1)
    {
        if(i>=0){
            s=s+(num1[i]-'0');
        }
        if(j>=0)
        {
            s=s+(num2[j]-'0');
        }
        result = char(s%2+'0') + result;
        s=s/2;
        i--;
        j--;
    }
    return result;
}


int main()
{
    string num1,num2;
    cin>>num1>>num2;
    string num3=binary_sum(num1,num2);
    cout<<num3<<endl;

}