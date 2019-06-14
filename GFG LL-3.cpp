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

struct node *head;

void newnode(int t)
{
    struct node *temp = new node;
    temp->data = t;
    temp -> next = head;
    head = temp;
}

void display()
{
    struct node *curr;
    curr=head;
    while(curr!=NULL)
    {
        cout << curr->data <<" ";
        curr=curr-> next;
    }
    cout << endl;
}

void reversee()
{
    struct node *temp,*curr, *prev;
    prev=NULL;
    curr=head;
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head = prev;
display();
}

int main()
{
    int n,j;
    cin >> n;

    for (int i=0;i<n;i++)
    {
        cin >>j;
        newnode(j);
    }
    display();
    reversee();
    return 0;
}








