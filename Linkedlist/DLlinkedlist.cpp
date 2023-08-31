#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
class DLinkedlist
{
    private:
    Node *head;
    public:
    DLinkedlist()
    {
        head=nullptr;
    }
// created some functions like 
// insert_at_head()
// inssert_at_last()
// insertbefore()
// insertafter()
// DisplayfromFront() 
// delete_at_head()
// delete_at_end()
// ReverseDL()
// search()
// delete_num()
    void insert_at_head(int data)
    {
        Node *newNode = new Node(data);
        if(head==nullptr)
        {
            head = newNode;
            newNode->prev=newNode;
            return;
        }
        newNode-> next=head;
        head =newNode;
        newNode->prev = head;

    }
    void insert_at_last(int data)
    {
        Node *newNode = new Node(data);
        if(head == nullptr)
        {
            head = newNode;
            newNode->prev=newNode;
            return;
        }
        else
        {
            Node *temp = head;
            while(temp->next!=nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        
    }
    void Displayfromfront()
    {
        Node *temp = head;
        cout<<"head";
        while(temp->next!=nullptr)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data;
        cout<<"nullptr"<<endl;
    }
    void insertafter(int num, int data)
    {
         Node *temp = head;
         while(temp->data!=num)
         {
            temp = temp->next;
         }
         Node *newNode=new Node(data);
         newNode->next = temp->next;
         temp->next=newNode;
         newNode->prev = temp;
    }
    void insertbefore(int num,int data)
    {
        Node *temp = head;
        while(temp->data!=num)
        {
            temp = temp->next;
        }
        Node *newNode = new Node(data);
        newNode->next=temp->prev->next;
        temp->prev->next=newNode;
        newNode->prev = newNode;
    }
    void deleteathead()
    {
        Node *temp=head;
        if(head==nullptr)
        {
            return;
        }
        head = temp->next;
        temp->prev=temp;
        delete temp;
    }
    void deleteatend()
    {
        Node *temp = head;
        if(head==nullptr)
        {
            return;
        }
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->prev->next=nullptr;
        delete temp;
    }
    Node* reverseDL()
{
    Node *temp = head;
    if(temp == nullptr or temp->next == nullptr)
    {
        return head;
    }
    else
    {
        Node *ptr1 = head;
        Node *ptr2 = ptr1->next;
        ptr1->prev = ptr2;
        ptr1->next = nullptr;
        while(ptr2 != nullptr)
        {
            Node *temp = ptr2->next;
            ptr2->prev = temp;
            ptr2->next = ptr1;
            ptr1= ptr2;
            ptr2=temp;
        }
        head = ptr1;
        return head;
    } 
}
int search(int num)
{
    int count = 0;
    Node *temp=head;
    while(temp!=nullptr)
    {
        if(temp->data==num)
        {
            return count;
        }
        else{
            count++;
            temp=temp->next;
        }
    }
    return -1;
}
void delete_num(int num)
{
    Node *temp = head;
    if(head->data==num)
        {
        head = head->next;
        head->next->prev = nullptr;
        return;
        }
    while(temp!=nullptr)
    {
        
        if(temp->data == num)
        {
            temp->prev->next = temp->next;
            delete temp;            
        }
        else
        {
            temp=temp->next;
        
        }
        
    }

}
};
int main()
{
    DLinkedlist list;
    // insert_at_head()
// inssert_at_last()
// insertbefore()
// insertafter()
// DisplayfromFront() 
// delete_at_head()
// delete_at_end()
// ReverseDL()
// search()
// delete_num()
    list.insert_at_head(1);
    list.insert_at_last(2);
    list.insert_at_last(4);
    list.insertbefore(4,3);
    list.insertafter(4,5);
    list.Displayfromfront();
    list.reverseDL();
    list.Displayfromfront();
    list.search(2);
    list.deleteathead();
    list.deleteatend();
    list.delete_num(3);
}