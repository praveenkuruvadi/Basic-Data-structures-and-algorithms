#include <iostream>

using namespace std;

int en[10];
int de[10];
int flag =-1;
int deflag = -1;


void pushen(int y)
{
    if(flag >10)
    {
        cout<<"stack is full"<<endl;
        return;
    }
    en[++flag] = y;
    cout<<"item<"<<y<<"> enqueued"<<endl;
    cout<<endl;
    return;
}
void pushde(int y)
{
    if(deflag >10)
    {
        cout<<"stack is full"<<endl;
        return;
    }
    de[++deflag] = y;
    return;
}

int popen(void)
{   int temp;
    if(flag<0)
    {
        cout<<"stack is empty"<<endl;
        return 0;
    }
    temp = en[flag--];
//    cout<<"Element popped: "<<temp<<endl;
    return temp;
}
void displayen()
{
    if(flag<0)
    {
        cout<<"stack empty"<<endl;
        return;
    }
    for(int i=flag;i>=0;i--)
    {
        cout<<en[i]<<endl;
    }
    return;
}
void popde()
{   int temp;
    if(deflag<0)
    {
        for(int i=flag;i>=0;i--)
        {
            temp = popen();
            pushde(temp);
        }
    }
    cout<<"item<"<<de[deflag--]<<"> dequeued"<<endl;
    cout<<endl;
    return;
}
void displayde()
{
    if(deflag<0)
    {
        cout<<"stack empty"<<endl;
        return;
    }
    for(int i=deflag;i>=0;i--)
    {
        cout<<de[i]<<endl;
    }
    return;
}
int main()
{

    int x,y,z;
    while(1)
    {
    cout<< "Enter operation : 1- enqueue , 2- dequeue , 3- display:  ";
    cin >>x;
    switch(x)
    {
        case 1 : cout<< "Enter element:  ";
                 cin>> y;
                 pushen(y);
                 break;
        case 2: popde();
                break;
        case 3: displayde();
                break;
    }
    }

    return 0;
}
