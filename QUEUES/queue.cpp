#include<iostream>
using namespace std;
class Queue
{
    private:
    int front;
    int rear;
    int *array;
    int capacity;
    int count;
    public:
    Queue(int size)
    {
        capacity  =size;
        array = new int[capacity];
        front = -1;
        rear =-1;
        count = 0;
    }
    bool isFull()
    {
        return count == capacity;
    }
    bool isEmpty()
    {
        return count ==0;
    }
    void enqueue(int data)
    {
        if(rear == capacity-1)
        {
            cout<<"Overflow"<<endl;
            return;
        }
        else if (rear == -1 & front ==-1)
        {
            rear=0;
            front=0;
            array[rear]=data;
            count++;
        }
        else
        {
            rear++;
            array[rear] = data;
            count++;
        }
    }
    void dequeue()
    {
        if(rear == -1 & front ==-1 )
        {
            cout<<"EMPTY"<<endl;
        }
        else if (rear==front)
        {
            rear=-1;
            front=-1;
            count--;
        }
        else
        {
            front++;
            count--;
        }
    }
    void display()
    {
        if(front==-1&rear==-1)
        {
            cout<<"empty"<<endl;
            return;
        }
        else
        {
            for(int i = front;i<rear+1;i++)
            {
                cout<<array[i]<<endl;
            }

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
    void cap()
    {
        cout<<count<<endl;
    }
};
int main()
{
    Queue q(3);
    q.enqueue(10);
    q.enqueue(11);
    q.enqueue(12);
    cout<<"display"<<endl;
    q.display();
    q.enqueue(13);
    q.dequeue();
    q.display();
    cout<<"peek"<<endl;
    q.peek();
    cout<<"getrear"<<endl;
    q.getrear();
    cout<<"display"<<endl;
    q.display();
    cout<<"size"<<endl;
    q.cap();
    q.dequeue();
    

    bool x=q.isEmpty();
    cout<<x<<endl;
    q.display();


}

/// once deleted the values are not able to replaced by new values
// this is replaced by circular queue