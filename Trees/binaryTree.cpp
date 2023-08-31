// using recursion
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
    struct node* newNode = new struct node;
    int x;
    cout<<"x:"<<endl;
    cin>>x;
    if(x==-1)
    {
        return nullptr;
    }
    newNode->data = x;
    cout<<"enter the data for left child of:"<<x<<endl;
    newNode->left = create();
    cout<<"enter the data for right child of:"<<x<<endl;
    newNode->right = create();
    return newNode;
}
int main()
{
    struct node* root;
    root = 0;
    root = create();
    return 0 ;
}