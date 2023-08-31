#include<iostream>
using namespace std;
class item
{
    public:
    int data;
    int priority;
};
class PQ
{
    private:
    item *array;
    int size;
    int itemcount;
    public:
    PQ(int size)
    {
        this->size=size;
        array = new item[size];
        itemcount = -1;
    }
    ~PQ()
    {
        delete[] array;
    }
    void enqueue(int data, int priority)
    {
        
        if(itemcount<size-1)
        {
            itemcount++;
            item newItem;
            newItem.data=data;
            newItem.priority = priority;
            array[itemcount] = newItem;
            
        }
        else{
            cout<<"PQ is full"<<endl;
            return;
        }
        for(int i = itemcount;i>0;i--)
        {
            if(array[i].priority<array[i-1].priority||((array[i].priority==array[i-1].priority && array[i].data>array[i-1].data)))
            {
                swap(array[i],array[i-1]);
            }
        }
    }
    void dequeue()
    {
        if(itemcount>=0)
        {
            itemcount--;
        }
        else{
            cout<<"PQ is empty"<<endl;
        }
    }
    void display()
    {
        for(int i = 0;i<=itemcount;i++)
        {
            cout<<array[i].data<<" "<<array[i].priority<<endl;
        }
    }
};
int main()
{
    PQ i(5);
    i.enqueue(2,1);
    i.enqueue(3,2);
    i.enqueue(4,2);
    i.enqueue(6,3);
    i.enqueue(7,3);
    i.display();
    i.enqueue(7,3);
    i.dequeue();
    i.display();
    i.enqueue(3,1);
    i.display();
}