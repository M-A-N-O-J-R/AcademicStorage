
#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
    Node* insert(Node* root, int data); 
    Node* deletenode(Node* root, int k); 
    Node* search(Node* root, int key);
    
    void inorder(Node* root); 
    void preorder(Node* root); 
    void postorder(Node* root); 
    void findMin(Node* root);

};


Node* Node::search(Node* root, int key) 
{
        if(root == NULL || root->data == key)        
            return root;

       
        if(root->data < key) 
            return search(root->right,key);

        
        return search(root->left,key);
}

Node* Node:: insert(Node* root, int data) 
{
        if(root == NULL)
        {
            return new Node(data);
        }
     else{
            Node* cur;
            if(data <= root->data) 
            {
                cur= insert(root->left, data);
                root->left = cur;
            }
            else 
            {
                cur = insert(root->right, data);
                root->right = cur;
            }
        return root;
     }
   }
    
   Node* Node:: deletenode(Node* root, int k) 
    { 
        
        if (root == NULL) 
            return root; 
        
        if(root->data > k)
        { 
            root->left = deletenode(root->left, k); 
            return root; 
        } 
        else if(root->data < k)
        { 
            root->right = deletenode(root->right, k); 
            return root; 
        } 
  

       
        if (root->left == NULL) 
        { 
            Node* temp = root->right;
            delete root; 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            Node* temp = root->left; 
            delete root; 
            return temp; 
        } 

        else 
        {
          Node* Parent = root;
          // Find successor of the node
          Node *succ = root->right; 
          while (succ->left != NULL) 
          { 
              Parent = succ; 
              succ = succ->left; 
          } 

          if (Parent != root) 
              Parent->left = succ->right; 
          else
              Parent->right = succ->right; 

          // Copy Successor Data  
          root->data = succ->data; 

          // Delete Successor and return root 
          delete succ;          
          return root; 
      } 
  } 

  void Node::inorder(Node* root)
  {
        if(root == NULL)
            return;
        
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }


void Node::preorder(Node* root)
  {
        if(root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
void Node::postorder(Node* root)
  {
        if(root == NULL)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }

    void found(Node* t)
    {
        if(t==NULL)
        {
            cout<<"\nELEMENT NOT FOUND";
        }
        else
        {
            cout<<"\nElement is found";
        }
    }
    void Node::findMin(Node* root)
  {
       
        Node* temp = root;
        while(temp!=NULL && temp->left != NULL)
        {
            temp=temp->left;
        }
        cout<<temp->data<<" ";
    }
    int main()
    {
    Node Tree(0);
    Node* root = NULL;
    int choice=1;
    while(choice!=7)
   {

       cout<<"\n\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Delete\n7.min\n\n";
       cin>>choice;
       switch(choice)
       {
           case 1: {
                      int data;
                      cin>>data;
                      root = Tree.insert(root,data);

                    }
                    break;
            case 2: {
                         Tree.inorder(root);
                    }    break;
            case 3: 
                    {
                         Tree.postorder(root);
                        
                     }  break;
            case 4: 
                    {
                        Tree.preorder(root);
                        
                     }  break;
            case 5: 
                    {
                        cout <<"\nEnter the data to find:";
                        int data;
                        cin>>data;
                        Node* t = Tree.search(root,data);
                        if(t==NULL)
                        {
                            cout<<"\nELEMENT NOT FOUND";
                        }
                        else
                        {
                            cout<<"\nElement is found";
                        }
                        //found(t);
                     }  break;
            case 6: 
                    {
                        int delete_data;
                        cout<<"\nEnter element to be deleted:";
                        cin>>delete_data;
                        Node* deleteelement = Tree.deletenode(root,delete_data);
                        deleteelement=findMin(root);
                      }  break;  
            
            default:  {
                         cout<<"Wrong choice";
                      }

       }

   } 
    return 0;
}