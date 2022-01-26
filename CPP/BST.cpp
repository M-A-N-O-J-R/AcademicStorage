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
};


Node* Node::search(Node* root, int key) 
{
        if(root == NULL || root->data == key)        
            return root;

        // Key is greater than root's data 
        if(root->data < key) 
            return search(root->right,key);

        // Key is smaller than root's data 
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
            cout<<"\neLEMENT NOT FOUND";
        }
        else
        {
            cout<<"\nElement is found";
        }
    }
    int main()
    {
    Node Tree(0);
    Node* root = NULL;
    int t;
    cout<<"Enter the Number of nodes to be inserted";
    cin>>t;
    while(t--)
    {
        int data;
        cin>>data;
        root = Tree.insert(root,data);
    }
    Tree.inorder(root);
    //Searching data
    cout <<"\nEnter the data to find:";
    int data;
    cin>>data;
    Node* find_element = Tree.search(root,data);
    found(find_element);
    int delete_data;
    cout<<"\nEnter element to be deleted:";
    cin>>delete_data;
    Node* deleteelement = Tree.deletenode(root,delete_data);
    cout<<"\nAfter deletion:";
    Tree.inorder(root);
    cout<<endl;
    Tree.postorder(root);
    cout<<endl;
    Tree.preorder(root);
    return 0;
}