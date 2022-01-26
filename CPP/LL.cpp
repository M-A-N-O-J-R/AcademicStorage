#include<iostream>
using namespace std;

struct node
{
    int data;
    struct  node *next;
};
struct node*head=NULL;
class list
{
    public:
    void addNode(int ele)
    {
        struct node * newNode=new node;
        newNode->data=ele;
        newNode->next=NULL;
        if(head ==NULL)
        {
            head=newNode;
    
        }
        else
         {
             struct node *temp=head;
             while(temp->next!=NULL)
             {
                 temp=temp->next;
             }
             temp->next=newNode;
         }
    }
    void displayList()
    {
        cout<<endl;
        struct node *temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    void insertBeg(int ele)
    {
        struct node *newNode=new node();
        newNode->data=ele;
        newNode->next=NULL;
        newNode->next=head;
        head=newNode;
    }
    void insertPos(int ele,int pos)
    {
        struct node *temp=head;

        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        struct node *newNode= new node;
        newNode->data=ele;
        newNode->next=temp->next;
        temp->next=newNode;
    }
    void insertEnd(int ele)
    {
        struct node *temp=head;

       while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        struct node *newNode= new node;
        newNode->data=ele;
        temp->next=newNode;
        newNode->next=NULL;
    }
    void deleteBeg()
    {
        struct node *temp=head;
        head= temp->next;
        temp->next=NULL;
    }
    
    void deleteEnd()
    {
        struct node *temp=head;
        while(temp->next->next!=NULL)
        {
           temp = temp->next;
        }
        temp->next=NULL;
    }
    void deletePos(int pos)
    {
        struct node *temp=head;
        for(int i=0;i<pos-1;i++)
        {
            temp=temp->next;
        }
        struct node *temp2=temp->next;
        temp->next=temp2->next;
        temp2->next=NULL;
        delete(temp2);

    }
};

int main()
{
    list l1;
    l1.addNode(5);
    l1.addNode(6);
    l1.insertBeg(10);
    l1.insertPos(25,3);
    l1.insertEnd(9);
    l1.displayList();
    l1.deleteBeg();
    l1.displayList();
    l1.deleteEnd();
    l1.displayList();
    l1.deletePos(1);
    l1.displayList();
    
}