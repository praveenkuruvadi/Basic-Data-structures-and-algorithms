#include <iostream>
using namespace std;

void tsearch(int ar[], int n, int high, int low);
int main()
{
    int x,y;
    int n;
    cout<<"enter length of array"<<endl;
    cin>> x;
    int ar[x];
    int low= 0;
    int high = x-1;
    cout<<"enter the elements"<<endl;
    for(int i=0; i<x;i++)
    {
        cin>> ar[i];
    }
    cout<< "array is:"<<endl;
    for(int i=0;i<x;i++)
    {
        cout<< ar[i]<<",";
    }
    cout<<endl;
    cout<<"enter element to be searched"<<endl;
    cin>> n;
    if((n < ar[low])||(n>ar[high]))
        cout<<"not found"<<endl;
    else
        tsearch( ar, n, 0 , (x-1));
    return 0;
}

void tsearch(int ar[], int n, int high, int low)
{
    int mid1= low+ ((high-low)/3);
    int mid2= high-((high-low)/3);
        if (n == ar[mid1])
        {
            cout<<"found at "<<mid1+1<<endl;
            return;
        }
        else if(n == ar[mid2])
        {
            cout<<"found at "<<mid2+1<<endl;
            return;
        }
        else if(n < ar[mid1])
            return tsearch( ar, n, low, (mid1-1));
        else if(n > ar[mid2])
            return tsearch( ar, n, (mid2+1), high);
        else if((n> mid1)&&(n< mid2))
            return tsearch( ar, n, (mid1+1), (mid2-1));
        else if(low>high)
        {
            cout<<"Not found"<<endl;
        }

}
