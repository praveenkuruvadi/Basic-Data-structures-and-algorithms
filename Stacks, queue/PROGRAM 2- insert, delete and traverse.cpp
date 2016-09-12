#include <iostream>
using namespace std;

struct node{
    int val;
    node *next;
};
node *head = NULL;
node *prev = NULL;
void insertnode(node *&head, node *&prev, int x);
void display(node *current);
void deletenode(node *&head,node *&prev, int x);
int deletecheck(node *current , int x);

void insertnode(node *&head, node *&prev,int x)
{   node *current = head;
    if(head == NULL)
    {
        node *temp = new node;
        temp -> val= x;
        temp -> next = NULL;
        head = temp;
        prev = temp;
        return;
    }
    if(head->val > x  )
    {
        node *temp = new node;
        temp ->val = x;
        temp->next = head;
        prev = head;
        head = temp;
        return;
    }
    if (prev->val < x )
    {
        node *temp = new node;
        temp->val = x;
        temp->next = NULL;
        prev->next = temp;
        prev = temp;
        return;
    }
    else
    {
    while(current != NULL)
    {
        node *temp1 =current;
        node *temp2 = temp1->next;
        if(temp2->val > x)
        {
            node *temp = new node;
            temp -> val = x;
            temp1->next = temp;
            temp->next = temp2;
            return;
        }
        current =current->next;
    }
    }
}
void display(node *current)
{
    if(current == NULL)
        cout<< "List is empty"<<endl;
    else
    {
        cout<< "list is:";
        while(current != NULL)
        {
            cout << current->val << " >>";
            current = current->next;
        }
        cout << endl;
    }
}

int deletecheck(node *current , int x)
{
    while(current != NULL)
        {
            if(current->val == x)
            {
                return 1;
            }
            current = current->next;
        }
    return 0;

}


void deletenode(node *&head,node *&prev, int x)
{   node *y = head;
    node *y1 = head->next;
    int flag =0;
    if(head == NULL)
    {
        cout << "List empty" <<endl;
        return;
    }
    if(head->val == x)
    {
        node *temp = new node;
        temp =  head;
        head = head->next;
        delete temp;
        return;
    }
    else
    {
        while(y1->val != NULL)
        {
            if(y1 ->val == x)
            {
                y->next = y1->next;
                delete y1;
                break;
            }
            else if(y1 == prev)
            {
                prev = y;
                delete y1;
                break;
            }
        y = y1;
        y1 = y1->next;
        }
        return;
    }
}



int main()
{

    char choice;
    int x,temp;
    do{
        cout << "1 - insert, 2 - delete, 3 - display, 0 - exit:    ";
        cin >> choice;
        switch(choice)
        {
            case '1' : cout <<"enter val to add: "<<endl;
                       cin>>  x;
                       insertnode (head,prev, x);
                       break;
            case '2' : cout<< "Enter val to delete" << endl;
                       cin>> x;
                       temp =deletecheck(head, x);
                       if(temp == 1)
                       {
                           deletenode(head,prev, x);
                       }
                       else
                       {
                           cout<<"element not present"<<endl;
                       }
                       break;
            case '3' : display(head);
                       break;

        }
    }while(choice != 0);
    return 0;
}
