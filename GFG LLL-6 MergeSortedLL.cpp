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

struct node *head, *head2,*headh;


void newnode(int t)
{
    struct node *temp = new node;
    temp->data = t;
    temp -> next = head;
    head = temp;
}

void newnode2(int t)
{
    struct node *temp = new node;
    temp->data = t;
    temp -> next = head2;
    head2 = temp;
}

void newnodeh(int t)
{
    struct node *temp = new node;
    temp->data = t;
    temp -> next = headh;
    headh = temp;
}


void display(struct node *th)
{
    struct node *curr;
    curr=th;
    while(curr!=NULL)
    {
        cout << curr->data <<" ";
        curr=curr-> next;
    }
    cout << endl;
}

void reversee(struct node *th)
{
    struct node *temp,*curr, *prev;
    prev=NULL;
    curr=th;
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    th = prev;
display(th);
}

void joinsort(struct node *a, struct node *b)
{
    struct node *t1,*t2,*newh;
    t1=a; t2=b;
    int m;
    while(t1!=NULL && t2!=NULL)
    {
    if ((t1->data) < (t2->data))
    {
        m=t1->data;
        newnodeh(m);
        t1=t1->next;
        continue;
    }
    if ((t1->data) == (t2->data))
    {
        m=t1->data;
        newnodeh(m);
        newnodeh(m);
        t2=t2->next;
        t1=t1->next;
        continue;
    }
    if ((t1->data) > (t2->data))
    {
        m=t2->data;
        newnodeh(m);
        t2=t2->next;
        continue;
    }
    }

    while(t1!=NULL)
    {
        newnodeh(t1->data);
        t1=t1->next;
    }

    while(t2!=NULL)
    {
        newnodeh(t2->data);
        t2=t2->next;
    }

    struct node *temp,*curr, *prev;
    prev=NULL;
    curr=headh;
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    headh = prev;

    display(headh);
}











int main()
{
int n1,n2,k,i;
cin >>n1 >> n2;

for (i=0;i<n1;i++)
{
    cin >> k;
    newnode(k);
}
head2 =NULL;
for (i=0;i<n2;i++)
{
    cin >> k;
    newnode2(k);
}

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

    prev=NULL;
    curr=head2;
    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head2 = prev;

display(head);
display(head2);


joinsort(head,head2);

}
