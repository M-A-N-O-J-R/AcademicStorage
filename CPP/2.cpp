#include<iostream>
#include<cstring>

using namespace std;

class student{
    public:
     string name;
     int reg_no;
     void student(string s,int x)
     {
         name = s;
         reg_no = x;
     }
    void displayDetails()
    {
        cout<<"\n"<<name<<"\t"<<reg_no<<endl;
    }
    void inputDetails(string text,int no)
    {
        name=text;
        reg_no=no;
    }
};

int main()
{
    system("cls");
    student s1,s2;
    s1.inputDetails("suresh",10);
    s1.displayDetails();
    s2.inputDetails("ramesh",20);
    s2.displayDetails();
    return 0;
}