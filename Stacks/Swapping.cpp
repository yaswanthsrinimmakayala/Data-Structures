#include<iostream>
#include<stack>
using namespace std;
void swapping(stack<int>& stack1, stack<int>& stack2)
{
    stack<int> tempstack;
    while(!stack1.empty())
    {
        int element=stack1.top();
        stack1.pop();
        tempstack.push(element);
    }
    while(!stack2.empty())
    {
        int element=stack2.top();
        stack2.pop();
        stack1.push(element);
    }
    while(!tempstack.empty())
    {
        int element=tempstack.top();
        tempstack.pop();
        stack2.push(element);
    }
}
int main()
{
    stack<int> stack1,stack2;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack2.push(4);
    stack2.push(5);
    stack2.push(6);
    swapping(stack1,stack2);
    cout << "Stack1 after swapping: ";
    while(!stack1.empty())
    {
        cout<<stack1.top()<<" "<<endl;
        stack1.pop();
    }
    cout << "Stack2 after swapping: "<<endl;
    while(!stack2.empty())
    {
        cout<<stack2.top()<<" "<<endl;
        stack2.pop();
    }


}
