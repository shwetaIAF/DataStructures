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

void insertatbeg()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    cout << "\nEnter Data : ";
    cin >> newnode->data;
    newnode->next = 0;
    if (tail == 0)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

void insertatend()
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    cout << "\nEnter Data : ";
    cin >> newnode->data;
    newnode->next = 0;
    newnode->next = tail->next;
    tail->next = newnode;
    tail = newnode;
}

void insertatpos()
{
    int pos;
    cout << "\nEnter Position : ";
    cin >> pos;
    if (pos == 1)
    {
        insertatbeg();
    }
    else if (pos == length())
    {
        insertatend();
    }
    else if(pos <0 || pos>length())
    {
        cout<<"\nInvalid Position !!!";
    }
    else
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        cout<<"\nEnter Data : ";
        cin>>newnode->data;
        newnode->next = 0;
        int i = 1;
        struct node *temp = tail->next;
        while (i < pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

int main()
{
    create();
    display();
    cout << "\nLinkedlist After Insertion : ";
    // insertatbeg();
    // insertatend();
    insertatpos();
    display();
    return 0;
}