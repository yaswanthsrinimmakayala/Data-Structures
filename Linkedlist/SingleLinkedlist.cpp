#include<iostream>
using namespace std;
class Node//here class  Node represents the node in linkedlist
{
    public:
    int data;  // data in the node
    Node* next;// here next stores the address of next node, in place of datatype we used the Node because it is datatype we are refering here.
    Node(int data)// constructer
    {
        this->data=data; // when we created new node with data as the parameter 
        // then it will store the parameter in the node as data 
        this->next=nullptr;// sets the address of next pointer as null
    }
};
class LinkedList
{
    private:
    Node* head;// it store the address of first node in head
    public:
    LinkedList()//constructer
    {
        this->head=nullptr;//linkedlist created is empty , there is no values in it, so head set to null
    }
    void InsertAtBegining(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void InsertAtEnd(int data)
    {
        Node *newNode=new Node(data);
        if(head==nullptr)
        {
            head=newNode;
            return;
        }
        Node *temp = head;
        while(temp->next!=nullptr)
        {
            temp=temp->next;
        }
        temp->next = newNode;
    }
    
};
