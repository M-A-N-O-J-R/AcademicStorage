#include<iostream>
using namespace std;

class room
{
    int r_type;
    int r_no;
    float r_area;
    int ACmachine;
  public:  
    room()
   {
       r_type =101;
       r_no=0;
       r_area =0;
       ACmachine=0;
   } 
   room(int no,int type)
   {
       r_no=no;
       r_type = type;
        r_area =0;
       ACmachine=0;
   }
  friend room operator ++(room r1);
  void display_data()
   {
       cout<<"r_no"<<" "<<r_no<<endl<<"r_type"<<" "<<r_type<<endl<<"r_area"<<" "<<r_area<<endl<<"ACmachine"<<" "<<ACmachine<<endl;
   }
  void set_data();
  friend void displyInfo(room r);

  void operator -(){
      r_no=r_no+1;
  }
  room operator +(room r2);
};
 room room::operator +(room r2)
 {
     room r3;
     r3.r_no=r_no+r2.r_no;
     r3.r_type=r_type+r2.r_type;
     return r3;
 }
  void room::set_data()
   {
       cout<<" ENTER L B AC";
       int l,b;      
       cin>>l>>b>>ACmachine;
       r_area=l*b;
   }
   void displyInfo(room r)
   {
       cout<<"r_no"<<" "<<r.r_no<<endl<<"r_type"<<" "<<r.r_type<<endl<<"r_area"<<" "<<r.r_area<<endl<<"ACmachine"<<" "<<r.ACmachine<<endl;
   }
   room operator ++(room r1)
   {
      r1.r_type=400;
      return r1;  
   }
void swap(int *a,int *b)
{
    cout<<"BEFORE SWAP  ";
    cout<<"a :"<<*a<<" "<<"b: "<<*b<<endl;
    int temp=*a;
    *a=*b;
    *b=temp;
    cout<<"AFTER SWAP  ";
    cout<<"a :"<<*a<<" "<<"b: "<<*b<<endl;
}
int sum(int a,int b,int c)
{
    return a+b+c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//   int a=10,b=20;
//   cout<<"BEFORE SWAP CALL  ";
//   cout<<"a :"<<a<<" "<<"b: "<<b<<endl;
//   swap(&a,&b);
//   cout<<"AFTER SWAP CALL  ";
//   cout<<"a :"<<a<<" "<<"b: "<<b<<endl;  
room r1(1,100);
room r2(2,200);
room r3;
r3=r1+r2;
room r4 =++r1;
r4.display_data();
}