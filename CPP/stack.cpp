#include<iostream>
using namespace std;


struct node
{
    int data;
    struct node* next;
   
};
struct node* top=NULL;

class stack
{
    public:
    void push(int value)
    {
        struct node *newNode =new node;
        newNode->data = value;
        newNode->next = NULL;
        if(top==NULL)
        {
            top = newNode;
        }
        else
        {
            newNode->next =top;
            top=newNode;
        }
    }
    void pop()
    {
        struct node *temp=top;
        top=top->next;
        cout<<endl<<"elemnt poped "<<temp->data<<endl;
        temp->next=NULL;
    }
    void display()
    {
        struct node *temp = top;   
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

};
int main(){
    stack s;
    s.push(5);
    s.push(10);
    s.push(40);
    s.display();
    s.pop();
    s.display();
}