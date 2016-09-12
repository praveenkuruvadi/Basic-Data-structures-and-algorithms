#include <iostream>

using namespace std;

void maxheap(int *a,int i, int n)
{
    int l= 2*i;
    int r= 2*i + 1;
    int lar,temp;
    if ((l<n) && (a[l]>a[i]))
        lar = l;
    else
        lar = i;
    if((r<n)&&(a[r]>a[lar]))
       lar = r;

    if (lar != i)
    {
        temp= a[i];
        a[i]= a[lar];
        a[lar]= temp;
        maxheap(a,lar,n);
    }
}
void buildheap(int *a, int n)
{
    for(int i= n/2;i >=1; i--)
        maxheap(a,i,n);
}
void heapsort(int *a,int n)
{
    int temp;
    for(int i=n; i >= 1; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] =temp;
        maxheap(a,1,i);
    }
}
int main()
{
    int n;
    cout << "Enter the number of elements" << endl;
    cin >> n;
    int a[n];
    a[0]=0;
    cout<<"enter the elements"<<endl;
    for(int j =1;j<=n;j++)
    {   cin>> a[j];}
    cout<<"Unsorted array is:"<<endl;
    for(int j =1;j<=n;j++)
    {   cout<< a[j]<<", ";}
    cout<<endl;
    buildheap(a,n);
//    cout<<"Array after build heap"<<endl;
//    for(int j= 1;j<=n;j++)
//        cout<<a[j]<<", ";
    heapsort(a,n);
    cout<<endl;
    cout<<"sorted array"<<endl;
    for(int j= 1;j<=n;j++)
        cout<<a[j]<<", ";
return 0;
}
