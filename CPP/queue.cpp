#include<iostream>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *back=NULL;
class queue
{
    public:
    void push(int ele)
    {
        struct node *newNode=new node;
        newNode->next=NULL;
        newNode->data=ele;
        if(front==NULL)
        {
            front = newNode;
            back=newNode;
        }
        else
        {
           back->next=newNode;
           back=newNode; 
        }       
    }
    void pop()
    {
        struct node* temp=front;
        front=front->next;
        cout<<"\nElement pop-->"<<temp->data;
        temp->next=NULL;
    }
    void peep()
    {
        struct node* temp=front;
        cout<<"\nElement peep-->"<<temp->data;
        delete temp;
    }
      void display()
      {
          struct node* temp=front;
          while(temp!=NULL)
          {
              cout<<temp->data<<" ";
              temp=temp->next;
          }
      } 
};

int main()
{
    queue a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.display();
    a.pop();
    a.display();
    
}