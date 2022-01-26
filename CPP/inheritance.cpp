#include<iostream>
using namespace std;

class shape
{
    protected:
    float area;
    public:
    shape()
    {
        cout<<"shape default constructor"<<endl;
        area=0;
    }
    shape(int x)
    {
        cout<<"shape parametrized constructor"<<endl;
        area=x;
    }
};
class rectangle:protected shape
{
    public:
    int length,breadth;
    rectangle()
    {
        cout<<"rectangle default constructor"<<endl;
        length=0;
        breadth=0;
    }
     rectangle(int x,int y,int z)
    {
        cout<<"rectangle parametrized constructor"<<endl;
        length=x;
        breadth=y;
        shape::area=z;
    }
    void display_data()
    {
        cout<<"rectangle display"<<endl;
       cout<<"length : "<<length<<" "<<"breadth : "<<breadth<<" "<<"area"<<area<<endl;
    }
};
class square:public rectangle
{
  int side; 
  public:
  square()
  {
      side=0;
  }
  square(int side2)
  {
      cout<<"parametrized square"<<endl;
      side=side2;
  }
   void display_data()
    {
        cout<<"square display"<<endl;
       cout<<"side : "<<side<<" "<<"area"<<shape::area<<endl;
    }
};
int main()
{
    shape s;
    rectangle r;
    r.display_data();
    square s2;
    s2.rectangle::display_data();
    shape s3(2);
    rectangle r3(2,3,5);
    r3.display_data();
    square s5(2);
    return 0;

}