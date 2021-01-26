#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
} * head, *tail;

void create()
{
    int ch = 1;
    head = 0;
    while (ch)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        cout << "\nEnter Data : \n";
        cin >> newnode->data;
        newnode->next = 0;
        if (head == 0)
        {
            head = tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        tail->next = head;
        cout << "Do you want to continue?";
        cin >> ch;
    }
}

void display()
{
    struct node *temp;

    if (tail == 0)
    {
        cout << "\nList is empty";
    }
    else
    {
        temp = tail->next;
        while (temp->next != tail->next)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << temp->data;
    }
}

int length()
{
    struct node *temp;
    int c = 1;
    if (tail == 0)
    {
        return 0;
    }
    else
    {
        temp = tail->next;
        while (temp->next != tail->next)
        {
            temp = temp->next;
            c++;
        }
    }
    return c;
}

void deletefrombeg()
{
     struct node * temp = tail->next; // = head ;
    if (tail == 0)
    {
        cout<<"\nList is empty !!";
    }
    else if(temp -> next  == temp)
    {
       tail = 0;
       free(temp);
    }
    else{
        tail->next = temp->next;
        free(temp);
    }
}

void deletefromend()
{
    struct node * prev,*curr;
    curr = tail->next;
    if(tail == 0)
    {
        cout<<endl<<"List is empty !!";
    }
    else if(curr->next == curr) // if only one node is there
    {
        tail = 0;
        free(curr);
    }
    else{
        while(curr->next != tail->next)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = tail->next;
        tail = prev;
        free(curr);
    }
}

void deleteatpos()
{
    int pos;
    cout << "\nEnter Position : ";
    cin >> pos;
    if (pos == 1)
    {
        deletefrombeg();
    }
    else if (pos == length())
    {
        deletefromend();
    }
    else if(pos <0 || pos>length())
    {
        cout<<"\nInvalid Position !!!";
    }
    else
    {
        int i = 1;
        struct node *temp = tail->next;
        struct node *del;

        while (i < pos-1)
        {
            temp = temp->next;
            i++;
        }
        del = temp -> next;
        temp->next = del->next;
        free(del);
    }
}

int main()
{
    create();
    display();
    cout << "Linkedlist After Deletion : ";
    // deletefrombeg();
    // deletefromend();
    deleteatpos();
    display();
    return 0;
}