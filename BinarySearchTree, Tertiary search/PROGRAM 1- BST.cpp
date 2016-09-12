#include <iostream>

using namespace std;

//Keep the first element of the array as 0 for the logic to apply
int bstest(int i);
void printree( int start, int last);
int asccheck(void);
int num=0;
//input array size here
int arraysize= 32;
int ar1[32] = {0};
//it is a bst
int ar[32]= { 0,50 ,35, 65,  20,  -1,  60,  75,  10,  25,  -1,  -1,  58,  63,  -1,  80,  8,  -1,  23,  27,  -1,  -1,  -1,  -1,  55,  59,  62,  64,  -1,  -1,  79,  81};

//Not a bst
//int ar[32]= {0,50, 35, 65,  20,  -1,  60,  75,  10,  25,  -1,  -1,  58,  63,  -1,  80,  8,  -1,  23,  27,  -1,  -1,  -1,  -1,  55,  56,  62,  64,  -1,  -1,  79,  81};
int main()
{
    int test1,test2;
    cout<<"The array representing a tree is: "<<endl;
    for(int i= 0;i<arraysize;i++)
    {
        cout<< ar[i]<<",";
    }
    cout<<endl;
    test1 = bstest(1);
    cout<<"The array sorted from Leftmost node to Rightmost node excluding Null nodes is: "<<endl;
    printree(1,arraysize-1);
    test2= asccheck();
    if ((test1 == 1)&&(test2 ==1))
        cout<<"It is bst"<<endl;
    else if((test1 == 0)&&(test2==0))
        cout<<"it is not bst"<<endl;
    else
        cout<<"it is not bst"<<endl;
    return 0;
}

//checking each subtree
int bstest(int i)
{
    if(ar[2*i+2]== NULL)
        return 1;
    else if((ar[2*i]== -1)&&(ar[i]<ar[2*i+1]))
        return bstest(i+1);
    else if((ar[2*i+1]== -1)&&(ar[i]>ar[2*i]))
        return bstest(i+1);
    else if(ar[i]== -1)
        return bstest(i+1);
    else if((ar[i]>ar[2*i])&&(ar[i]<ar[2*i+1]))
        return bstest(i+1);
    else
        return 0;
}

//check the left and the right subtrees of the bst and sort them
//IF IT IS BST THEN THE NODES FROM LEFT to RIGHT SHOULD BE IN ASCENDING ORDER
void printree( int start, int last)
{
  if(start > last)
    return;

  printree( start*2 , last);


  if(ar[start] != -1)
  {
      ar1[num] = ar[start];
      cout<<ar1[num]<<endl;
      num=num+1;
  }

  printree( start*2 + 1, last);
}

int asccheck(void)
{
    for(int i=0;i<num-1;i++)
    {
        if(ar1[i]>ar1[i+1])
        {
            return 0;
        }
    }
    return 1;
}



