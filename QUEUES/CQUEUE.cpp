#include<iostream>
using namespace std;
class Queue
{
    public:
    int data;
    int* array;
    int front;
    int rear;
    int capacity;
    Queue(int size)
    {
        capacity = size;
        array = new int[capacity];
        front=-1;
        rear=-1;
    }
    ~Queue()
    {
        delete[] array;
    }
    void enqueue(int data)
    {
        if(front ==-1 && rear==-1)
        {
            front =0;
            rear  =0;
            array[rear]=data;
            return;
        }
        if(front==(rear+1)%capacity)
        {
            cout<<"Full"<<endl;
            return;
        }
        else{
            rear=(rear+1)%capacity;
            array[rear]=data;
        }

    }
    void dequeue()
    {
        if(rear==front)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front+1)%capacity;
            
        }
    }
    void display()
    {
        if(front==-1&&rear ==-1)
        {
            cout<<"Empty"<<endl;
        }
        else
        {
            int i=front;cout<<"the queue is :"<<endl;
            while(i!=rear)
            {
                cout<<array[i]<<endl;
                i = (i+1)%capacity;
            }
            cout<<array[i]<<endl;
        }
    }
    void peek()
    {
        cout<<array[front]<<endl;
    }
    void getrear()
    {
        cout<<array[rear]<<endl;
    }
    bool isFull()
    {
       if(front==(rear+1)%capacity)
       {
        return true;
       } 
       return false;
    }
    bool isEmpty()
    {
        if(rear==-1 && front==-1)
        {
            return true;
        }
        return false;
    }
};
int main()
{
    Queue q(5);
    cout<<q.isEmpty()<<endl;
    cout<<q.isFull()<<endl;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(6);
    q.display();
    q.peek();
    q.getrear();

}
