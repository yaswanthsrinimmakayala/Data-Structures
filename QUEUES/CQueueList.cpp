#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
         this->data=data;
         this->next=nullptr;
    }
};
class CQueue
{
    private:
    Node* front;
    Node* tail;
    public:
    CQueue()
    {
        front=nullptr;
        tail=nullptr;
    }
    void enQueue(int data)
    {
        Node* newnode = new Node(data);
        if(front == nullptr)
        {
            front = newnode;
            front->next = front;
            tail = front;
            return;
        }
        tail->next = newnode;
        newnode->next = front;
        tail = newnode;
    }
    void dequeue()
    {
        if(front==nullptr)
        {
            cout<<"Empty"<<endl;
        }
        Node *temp = front;
        front=temp->next;
        tail->next=front;
        delete temp;
    }
    void display()
    {
        if(front==nullptr)
        {
            cout<<"EMPTY"<<endl;
            return;
        }
        Node *temp=front;
        do
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        } while (temp!=front);
        
    }
    void peek()
    {
        cout<<front->data<<endl;
    }
    void getrear()
    {
        cout<<tail->data<<endl;
    }
};
int main()
{
    CQueue q;
    q.display();
    q.enQueue(10);
    q.enQueue(11);
    q.enQueue(110);
    q.display();
    q.getrear();
    q.peek();
    q.dequeue();
    q.display();

    
}