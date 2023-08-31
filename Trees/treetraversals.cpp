#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node*left;
    struct node*right;
};
struct node* create()
{
    struct node* newnode = new struct node;
    int x;
    cin>>x;
    if(x==-1)
    {
        return nullptr;
    }
    newnode->data=x;
    cout<<"Enter the left child of "<<x;
    newnode->left=create();
    cout<<"Enter the right child of "<<x;
    newnode->right = create();
    return newnode;
}
void preordertraversal(struct node * root)
{
    if(root==nullptr)
    {
        return;
    }
    cout<<root->data<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);
}
void inordertraversal(struct node* root)
{
    if(root==nullptr)
    {
        return ;
    }
    inordertraversal(root->left);
    cout<<root->data<< " ";
    inordertraversal(root->right);
}
void postordertraversal(struct node* root)
{
    if(root==nullptr)
    {
        return ;
    }
    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
}
int main()
{
    struct node * root;
    root =0;
    root = create();
    preordertraversal(root);
    cout<<endl;
    inordertraversal(root);
    cout<<endl;
    postordertraversal(root);
    cout<<endl;

}