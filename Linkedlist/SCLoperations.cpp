#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};
class SCL
{
    private:
    Node *last;
    public:
    SCL()
    {
        last = nullptr;
    }
    void insertFront(int data)
    {
        Node* newNode = new Node(data);
        if(last == nullptr)
        {
            last = newNode;
            newNode->next = last;
        }
        newNode->next = last->next;
        last->next = newNode;
    }
    void insertEnd(int data)
    {
        Node* newNode = new Node(data);
        if(last == nullptr)
        {
            last = newNode;
            newNode->next = last;
        }
        newNode->next = last->next;
        last->next =newNode;
        last = newNode;
    }
    void display()
    {
        if(last==nullptr)
        {
            cout<<"list Empty"<<endl;
            return;
        }
        Node *temp = last->next;
        do
        {
           cout<<temp->data<<" ";
           temp=temp->next; 
        }
        while(temp!=last->next);
    }
    void reverse()
    {
        if(last == nullptr)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* current = last->next;
        Node* next;
        Node* prev = last;
        Node* front = last->next;
        if(!last || last == last->next)
        {
            return;
        }
        do
        {
            next=current->next;
            current->next = prev;
            prev = current;
            current = next;
        }while(current!=front); 
        last = front;
    }
    void search(int num)
    {
        if(last == nullptr)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        Node *temp = last->next;
        int count=-1;
        do
        {
            if(temp->data == num)
            {
                count++;
                cout<<"Found at index: "<<count<<endl;
                temp = temp->next;
            }
            else
            {
                count++;
                temp = temp->next;
            }
        }
        while(temp!=last->next);
    }
    void deletehead()
    {
        if(last==nullptr)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        if(last->next==last)
        {
            delete last;
            last = nullptr;
            return ;
        }
        Node *temp = last->next;
        last->next = temp->next;
        delete temp;

    }
    void deleteEnd()
    {
        if(last == nullptr)
        {
            cout<<"List Empty"<<endl;
            return;
        }
        if(last->next == last)
        {
            delete last;
            last =nullptr;
            return;
        }
        Node *current = last->next;
        do
        {
            current = current->next;
        } while (current->next!=last);
        current->next = last->next;
        delete last;
        last = current;
        
    }
    void deletekthfromend(int k)
    {
        if(last == nullptr)
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        if(last->next==last)
        {
            if(k==1)
            {
                delete last;
                last=nullptr;
                return;
            }
            else{
            cout<<"There is only one element"<<endl;
            }
        }
        reverse();
        Node *current = last->next;
        Node *prev;
        while(k-1>0)
        {
            prev = current;
            current = current->next;
            k--;
        }
        prev->next=current->next;
        delete current;
        reverse();
        
    }

};
int main()
{
    SCL list;
    list.display();
    list.reverse();
    list.insertFront(10);
    list.insertEnd(12);
    list.insertFront(9);
    list.insertEnd(11);
    list.display();
    cout<<"\n"<<endl;
    list.insertEnd(11);
    list.display();
    cout<<"\n"<<endl;
    list.search(11);
    list.deletehead();
    list.display();
    cout<<"CHECKPOINT\n"<<endl;
    list.deleteEnd();
    cout<<"CHECKPOINT1\n"<<endl;
    list.display();
    list.deletekthfromend(2);
    cout<<"CHECKPOINT\n"<<endl;
    list.display();
}