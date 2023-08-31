#include<iostream>
using namespace std;
class Node
{
    public:
    int  data;
    Node* next;
    Node* prev;
    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
class DCL
{
    private:
    Node* head;
    public:
    DCL()
    {
        head=nullptr;
    }
    void insertHead(int data)
    {
        Node *newNode = new Node(data);
        if(head == nullptr)
        {
            head = newNode;
            newNode->prev = head;
            newNode->next = head;
            return;
        }
        newNode->next=head;
        newNode->prev=head->prev;
        head->prev->next=newNode;
        head->prev = newNode;
        head=newNode;
    }
    void insertEnd(int data)
    {
        Node *newNode = new Node(data);
        if(head==nullptr)
        {
            head=newNode;
            newNode->next = head;
            newNode->prev = head;
            return;
        }
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev= newNode;
    }
    void display()
{
    if (head == nullptr)
    {
        cout << "Empty" << endl;
        return;
    }
    Node *temp = head;
    do
    {
        cout << temp->data << endl;
        temp = temp->next;
    } while (temp != head);
}

    void reverse()
{
    if (head == nullptr)
    {
        cout << "list is empty" << endl;
        return;
    }
    if (head->next == head)
    {
        return;
    }
    Node* current = head;
    Node* temp;
    do
    {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    } while (current != head);
    head = head->next;
}

    void deleteFront()
    {
        if(head==nullptr)
        {
            cout<<"Empty list"<<endl;
            return;
        }
        if(head->next==head)
        {
            delete head;
            head = nullptr;
        }
        Node *temp;
        temp=head->next;
        head->prev->next=temp;
        temp->prev=head->prev;
        delete head;
        head= temp;
    }
    void search(int data)
    {
        Node *temp=head;
        int count=-1;
        do
        {
            
            if(temp->data==data)
            {
                count++;
                cout<<"Found at: "<<count<<endl;
                temp=temp->next;
            }
            else{
            count++;
            temp=temp->next;
            }
        } while (temp!=head);
        
    }
};
int main()
{
    DCL list;
    list.insertHead(11);
    list.insertHead(10);    
    list.insertHead(9);
    list.display();
    list.insertEnd(12);
    cout<<" "<<endl;
    list.display();
    cout<<"reverse"<<endl;
    list.reverse();
    list.display();
    cout<<"delete"<<endl;
    list.deleteFront();
    list.display();
    cout<<"reverse"<<endl;
    list.reverse();
    list.display();
    list.insertEnd(11);
    list.search(11);
    list.display();

}