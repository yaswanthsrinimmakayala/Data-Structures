#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node*next;
    Node(int data)
    {
        this->data=data;
        this->next =nullptr;
    }
};
class Queue
{
    private:
    Node* front;
    Node* tail;
    public:
    Queue()
    {
        front=nullptr;
        tail=nullptr;
    }
    void enqueue(int data)
    {
        Node *newNode = new Node(data);
        if(front==nullptr)
        {
            front = newNode;
            newNode->next = nullptr;
            tail =newNode;
        }
        if(front->next == nullptr)
        {
            front->next = newNode;
            newNode->next=nullptr;
            tail=newNode;
            return;
        }
        tail->next = newNode;
        newNode->next=nullptr;
        tail=newNode;
    }
    void  dequeue()
    {
        if(front == nullptr)
        {
            cout<<"Empty"<<endl;
            return;
        }
        if(front->next == nullptr)
        {
            delete front;
            delete tail;
            front = nullptr;
            tail=nullptr;
        }
        Node *temp =front;
        front=temp->next ;
        delete temp;
    }
    void display()
    {
        if(front==nullptr)
        {
            cout<<"Empty"<<endl;
            return ;
        }
        Node *temp = front;
        do
        {
            cout<<temp->data<<endl;
            temp=temp->next;
        } while (temp!=nullptr);
        
    }
    void peek()
    {
        cout<<front->data<<endl;
    }
    void rear()
    {
        cout<<tail->data<<endl;
    }

};
int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);
    cout<<"Display"<<endl;
    q.display();
    cout<<"Delete"<<endl;
    q.dequeue();
    cout<<"Display"<<endl;
    q.display();
    cout<<"peak"<<endl;
    q.peek();
    cout<<"rear"<<endl;
    q.rear();
}