#include<iostream>
#include<cstring>

using namespace std;

class student{
    public:
     string name;
     int reg_no;
    student()
    {
        name="manoj";
        reg_no=195002071;
    }
    void stud_detail()
    {
        cout<<"\n"<<name<<"\t"<<reg_no<<endl;
    }
};

int main()
{
    system("cls");
    student s1;
    s1.name="raghu";
    s1.reg_no=25;
    s1.stud_detail();
    student s2;
    s2=s1;
    s2.stud_detail();
    return 0;
}