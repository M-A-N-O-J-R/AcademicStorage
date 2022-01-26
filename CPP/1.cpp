#include<iostream>
#include<conio.h>
using namespace std;
class shape
{
 public:
    float area,perimeter;
    string name;
    virtual void findArea()=0;
    virtual void displayDetails()=0;
    virtual void findPerimeter()=0;
};
class Rectangle : public shape{
    public:
    int length;
    int breadth;
    
    Rectangle(int l,int b){
        length=l;
        breadth=b;
        name="rectangle";
        area=0;
        perimeter=0;
    }
    void findArea(){
        area=length*breadth;
    }
    void findPerimeter()
    {
      perimeter=2*(length+breadth);

    }
    void displayDetails()
    {
      cout<<name<<"   Area:"<<area<<"   breadth:"<<breadth<<"   length:"<<length<<"   perimeter:"<<perimeter<<endl;
    }
};
class Circle : public shape{
  public:
  int radius;
  Circle(int r)
  {
      radius = r;
      name="circle";
       area=0;
        perimeter=0;
  }
  void findArea()
  {
      area=3.14*radius*radius;
  }
  void displayDetails()
  {
      cout<<endl;
      cout<<name<<"  Area: "<<area<<"   radius:"<<radius<<"   perimeter:"<<perimeter<<endl;

  }
  void findPerimeter()
    {
      perimeter=2*3.14*radius;

    }
};
int main()
{
    int l,b;
    cout<<"Enter length and breadth";
    cin>>l>>b;
    shape *s;
    Rectangle a(l,b);
    s=&a;
    s->findArea();
    s->findPerimeter();
    s->displayDetails();
    int r;
    cout<<"Enter radius";
    cin>>r;
    Circle a1(r);
    s=&a1;
    s->findArea();
    s->findPerimeter();
    s->displayDetails();
    return 0;
   
}


