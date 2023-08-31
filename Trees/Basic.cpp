#include<iostream>
using namespace std;
class  Node
{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int data)
    {
        this->data = data;
    }
};
class Tree
{
    private:
    Node* next;
    public:
    Tree()
    {
        next = nullptr;
    }
};
int main()
{
   Tree t;
   Node *root = new Node(10);
   root->left=new Node(2);
   root->right=new Node(5);
   root->left->left=new Node(1);
   root->left->right=new Node(2);
   root->right->left=new Node(1);
   root->right->right=new Node(5);
   cout<<root<<endl;
}
