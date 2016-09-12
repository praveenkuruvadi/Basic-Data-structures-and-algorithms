#include <iostream>


using namespace std;
void countSort(int a[], int n, int exp)
{
    int output[n];
    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[(a[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

int maxofarr(int a[], int n)
{
    int temp = a[0];
    int i =1;
    while(i<n)
    {
        if (a[i] > temp)
            temp = a[i];
        i++;
    }
    return temp;
}
void radix(int a[], int n)
{
    int maximum = maxofarr(a, n);
    int exp = 1;
    while((maximum / exp) > 0)
    {
        countSort(a, n, exp);
        exp = exp*10;
    }
}


int main()
{
    int n = 15;
    int a[] = {1700, 4523, 7555, 9021, 8027, 2411, 2088, 6677,7500,9421,1111,7800,4000,1234,4321};
    cout<<"Array before sorting:"<<endl;
    for(int i=0 ;i<n;i++)
    {
        cout<< a[i] << " ";
    }
    cout<<endl;
    cout<<"Array after sorting:"<<endl;
    radix(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] <<endl;
    return 0;
}
