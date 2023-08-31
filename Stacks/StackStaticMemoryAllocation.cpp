// static memory allocation using arrays
#include<iostream>
using namespace std;
const int MAX_SIZE=100;
int stack[MAX_SIZE];
int top=-1;
void push(int x)
{
    if(top==MAX_SIZE-1)
    {
        cout<<"OverFlow condition: Stack is full"<<endl;
    }
    else
    {
        top++;
        stack[top]=x;
        cout<<"Pushed Value: "<<x<<endl;
    }
}
int pop()
{
    if(top==-1)
    {
        cout<<"UnderFlow Condition:Stack is Empty"<<endl;
        return -1;
    }
    else{
        int poped_value = stack[top];
        top--;
        cout<<"Poped_Value"<<poped_value<<endl;
        return poped_value;
    }
}
int peek()
{
    if(top==-1)
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    else{
    return stack[top];
    }
}
bool isempty()
{
    return top==-1;
}
bool isfull()
{
    return top==MAX_SIZE-1;
}
int main()
{
    int size;
    
    while(true)
    {
        cout<<"Maximum size of stack:"<<MAX_SIZE<<endl;
        cout<<"Select Operation:"<<endl;
        cout<<"1.push"<<endl;
        cout<<"2.pop"<<endl;
        cout<<"3.peek"<<endl;
        cout<<"4.isempty"<<endl;
        cout<<"5.isfull"<<endl;
        cout<<"6.Exit"<<endl;
        int choice;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Enter the value to be pushed"<<endl;
            int value;
            cin>>value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            cout<<(isempty()?"true":"false")<<endl;
            break;
        case 5:
            cout<<(isfull()?"true":"false")<<endl;
            break;
        case 6:
            break;
    
}


    }

}
