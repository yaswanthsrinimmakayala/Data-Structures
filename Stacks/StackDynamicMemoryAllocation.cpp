#include<iostream>
using namespace std;
int* stack;
int top=-1;
void push(int value,int size)
{
    if(top==size-1)
    {
        cout<<"Overflow. Stack is full"<<endl;
    }
    else
    {
        int pushed_value=value;
        top++;
        stack[top]=value;
        cout<<"Pushed Value"<<pushed_value<<endl;
    }
}
int pop()
{
    if(top==-1)
    {
        cout<<"Underflow. Stack is Empty"<<endl;
        return -1;
    }
    else{
        int poped_value=stack[top];
        top--;
        cout<<"Poped_value: "<<poped_value<<endl;
        return poped_value;
    }
}
int peek()
{
    if(top==-1)
    {
        cout<<"Stack is Empty"<<endl;
        return -1;
    }
    else
    {
        cout<<"Top value: "<<stack[top]<<endl;
        return stack[top];
    }
}
bool isempty()
{
    return top==-1;
}
bool isfull(int size)
{
    return top==size-1;
}
int main()
{
    int size;
    cout<<"Enter the size of stack: ";
    cin>>size;
    stack = new int[size];
    while(true)
    {
        cout<<"Select Operation:"<<endl;
        cout<<"1.Push"<<endl;
        cout<<"2.pop"<<endl;
        cout<<"3.peek"<<endl;
        cout<<"4.isfull"<<endl;
        cout<<"5.isempty"<<endl;
        cout<<"6.exit"<<endl;
        int choice;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            int val;
            cout<<"Enter the value to be pushed: ";
            cin>>val;
            push(val,size);
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            case 4:
            cout<<(isempty()?"true":"false")<<endl;
            break;
            case 5:
            cout<<(isfull(size)?"true":"false")<<endl;
            break;
            case 6:
            break;


        }
        
    }
    delete[] stack; //deallocation of memory
    return 0;



}