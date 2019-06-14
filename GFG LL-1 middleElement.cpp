#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <string.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *head= NULL;

void newnode(int t) //nodes are added at the front of the LL. So, if the input is 1 2 3 4, they are stored as 4 3 2 1 [1 is stored first and 4 is stored last]
{
    struct node *temp = new node;
    temp->data = t;
    temp-> next = head;
    head = temp;
}

void getmiddle()
{
    struct node *slow,*fast;
    slow = head; fast = head;
    while(fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout <<"Middle Element is " << slow->data << endl;
}

void reversell()
{
    struct node *prev,*curr,*temp;
    curr=head;
    prev=NULL;
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next = prev;
         cout << curr-> data << "rev " << curr->next->data << endl ;
        prev=curr;
        curr=temp;

    }

    head = prev;
    curr = head;
    while(curr!=NULL)
    {
    cout << curr->data << " ";
    curr=curr->next;
    }

 //   return prev;
}

int main()
{
    struct node *curr;

    int n,t;
    cin >> n;

    for (int i=0;i<n;i++)
    {
        cin >> t;
         newnode(t);
        //curr=curr->next;
    }
    curr=head;

    while(curr!=NULL)
    {
    cout << curr->data << " ";
    curr=curr->next;
    }
    cout << endl;

    getmiddle();

     reversell();

    return 0;
}
