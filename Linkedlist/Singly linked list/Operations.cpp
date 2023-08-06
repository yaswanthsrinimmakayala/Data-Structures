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
class LinkedList
{
    private:
    Node *head;
    public:
    LinkedList()
    {
        head=nullptr;
    }
    void insertBegining(int data)
    {
        
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void insertend(int data)
    {
        Node *newNode  =  new Node(data);
        if(head==nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp  = head;
        while(temp->next != nullptr)
        {
            temp=temp->next;
        }
        temp->next = newNode;
    }
    void display()
    {
        Node *temp = head;
        while(temp!=nullptr)
        {
            cout<<temp->data<<" "<<endl;
            temp=temp->next;
        }
    }
    void deletefront()
    {
        if(head==nullptr)
        {
            return;
        }
        Node *temp = head;
        head=head->next;
        delete temp;
    }
    void deleteend()
    {
        if(head==nullptr)
        {
            return;
        }
        if(head->next==nullptr)
        {
            delete head;
            head=nullptr;
            return ;
        }
        Node *temp = head;
        while(temp->next->next!=nullptr)
        {
            temp = temp->next;
        }
        delete temp->next; 
        temp->next=nullptr;
    }
    void deleteval(int num)
    {
        if(head==nullptr)
        {
            return;
        }
        if(head->data==num)
        {
            Node *temp = head;
            head=head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while(temp->next!=nullptr)
        {
            if(temp->next->data==num)
            {
                Node *newptr=temp->next->next;
                delete temp->next;
                temp->next=newptr;
                return;
            }
            temp=temp->next; 
        }
    }
    int search(int num)
    {
        Node *temp = head;
        int count = 0 ;
        while(temp!=nullptr)
        {
            if(temp->data==num)
            {
                temp=temp->next;
                return count;
            }
            else{
                temp=temp->next;
                count++;
            }

        }
        return -1;

    }
    Node* reverseSL()
    {
        Node* ptr1 = head;
        Node* ptr2 = ptr1->next;
        ptr1->next = nullptr;
        while(ptr2!=nullptr)
        {
            Node *temp = ptr2->next;
            ptr2->next = ptr1;
            ptr1=ptr2;
            ptr2=temp;
        }
        head = ptr1;
        return head;
    }
};
int main()
{
    LinkedList list;
    list.insertBegining(10);
    list.insertBegining(11);
    list.insertBegining(12);
    list.insertBegining(13);
    list.insertend(24);
    list.display();
    list.deletefront();
    list.deleteend();
    list.insertend(24);
    cout<<"display"<<endl;
    list.display();
    list.deleteval(12);
    cout<<"display"<<endl;
    list.display();
    list.deleteval(24);
    cout<<"display"<<endl;
    list.display();
    cout<<list.search(11)<<endl;
    list.reverseSL();
    list.display();
}
