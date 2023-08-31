#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int *stack1;
int *stack2;
int top1 = -1;
int top2 = -1;
void enqueue(int data,int size)
{
    if(top1==size-1)
    {
        cout<<"Stack1 is Full"<<endl;
        return;
    }
    top1++;
    stack1[top1]=data;
    return;
}
void push(int data)
{
    stack2[top2++]=data;
}

void dequeue(int size)
{
    while(top1!=-1)
    {
        top2++;
        stack2[top2] = stack1[top1];
        top1--;
    }
    top2=top2-1;
    while(top2!=-1)
    {
        ++top1;
        stack1[top1] = stack2[top2];
        top2--;
    }

    
}
void display()
{
    int z =top1;
    while(z!=-1)
    {
        cout<<stack1[z]<<" ";
        z--;
    }
    cout<<endl;
    
}
int main()
{
    int capacity,size;
    cout<<"Enter Size:";
    cin>>capacity;
    size = capacity;
    stack1  = new int[capacity];
    stack2  = new int[capacity]; 
    enqueue(5,size);
    enqueue(2,size);
    enqueue(3,size);
    display();
    dequeue(size);
    display();
    return 0;
}