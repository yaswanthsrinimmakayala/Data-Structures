#include<iostream>
using namespace std;
char findparentofchild(int index, char arr[])
{
    return arr[(index-1)/2];
}
char findleftchild(int index,char arr[])
{
    return arr[2*index+1];
}
char findrightchild(int index,char arr[])
{
    return arr[2*index+2];
}
int main()
{
    int size;
    cin>>size;
    char arr[size];
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
    char x;
    x = findleftchild(1,arr);
    cout<<x;
    return 0;

}