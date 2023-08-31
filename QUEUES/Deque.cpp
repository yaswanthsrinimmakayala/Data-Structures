#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class deque
{
    private:
    int front;
    int rear;
    int *array;
    int size;
    public:
    deque(int size)
    {
        this->size =size;
        array = new int[size];
        front = -1;
        rear  = -1;
    }
    void enqueue_front(int data)
    {
        if((front==rear+1)  || (front==0 && rear==size-1))
        {
            cout<<"deque is full"<<endl;
            return;
        }
        else if (front == -1 &&rear ==-1)
        {
            front = 0 ; rear = 0; array[front] = data;
            return;

        }
        else if(front==0)
        {
            front = size-1;
            array[front] = data;
            return;
        }
        else
        {
            front--;
            array[front] = data;
            return;

        }
        
    }
    void enqueue_rear(int data)
    {
        if(((front==0)&&(rear=size-1)))
        {
            cout<<"Deque is Full "<<endl;
            return;
        }
        else if ((front == -1) && (rear = -1))
        {
            front=0;
            rear =0;
            array[rear]= data;
            return;

        }
        else if (rear == size-1)
        {
            rear = (rear+1)%size;
            array[rear]=data;
            return;

        }
        else
        {
            rear++;
            array[rear] = data;
            return;

        }
    }
    void dequeue_front()
    {
        if(front==-1 and rear==-1)
        {
            cout<<"Deque is Empty"<<endl;
            return;

        }
        else if(front==size-1)
        {
            front = 0;
            return;

        }
        else if(front==rear)
        {
            front=-1;
            rear=-1;
            return;

        }
        else
        {
            front++;
            return;

        }
    }
    void dequeue_rear()
    {
        if(front==-1 and rear==-1)
        {
            cout<<"Deque is Empty"<<endl;
            return;

        }
        else if (rear == 0)
        {
            rear = size-1;     
            return;

        }
        else if(front==rear)
        {
            front=-1;
            rear=-1;
            return;

        }        
        else
        {
            rear--;
            return;

        }
    }
    void display()
    {
        if(front==-1 and rear==-1)
        {
            cout<<"Deque is Empty"<<endl;
            return;

        }
        else
        {
            int i = front;
            while(i!=rear)
            {
                cout<<array[i]<<" ";
                i = (i+1)%size;
            }
            cout<<array[rear]<<endl;
            return;

        }
        
    }
};
int main()
{
    deque q(5);
    q.enqueue_front(2);
    q.enqueue_front(5);
    q.enqueue_rear(-1);
    q.enqueue_rear(7);
    q.enqueue_rear(0);
    q.display();

    q.enqueue_front(1207);

    q.display();
    q.dequeue_front();
    q.display();

    q.dequeue_rear();
    q.display();

    q.enqueue_front(23);
    q.display();

    q.enqueue_rear(32);
    q.display();
    return 0;
}