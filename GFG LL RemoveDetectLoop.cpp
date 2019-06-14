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


void newnode(int k) //inserts at the beginning of the LL
{
    struct node *temp=new node;
    temp->data = k;
    temp->next =head;
    head = temp;
}

void display(struct node *th)
{
    while(th!=NULL)
    {
        cout << th->data <<" ";
        th=th->next;
    }
}

void rev()
{
    struct node *temp,*prev,*curr;
    curr = head;
    prev=NULL;

    while(curr!=NULL)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;
    display(head);
}
void removeloop(struct node *th)
{
    map<struct node*,bool> loop;
    struct node *curr,*next;
    curr=th;

    while(loop.find(curr)==loop.end())
    {
            loop[curr]=true;
       //     cout << loop[curr] << " ";
            next=curr;
            curr=curr->next;
    }
    next->next=NULL;

    display(th);
}

void detectloop(struct node *th)
{
    struct node *slow,*fast;
    slow=th; fast=th->next;
    int flag=0;

    while(fast!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast)
        {
            flag=1;
            break;
        }
    }


    if (flag==0)
        cout << "Loop is not present" << endl;
    else
    {
        cout << "Loop is present" << endl;
     removeloop(th);
    }

}




int main()
{
    int n,k;
    cin >>n;
    for (int i=0;i<n;i++)
    {
        cin >> k;
        newnode(k);
    }
    cin >> k;

    rev();

    struct node *last,*curr;
    last=head;

    while((last->next)!=NULL)
        last=last->next;
    cout << "last" <<last->data <<endl;
    curr=head;

    while(k>1)
    {
    curr=curr->next;
    k--;
    }
    cout << "curr" <<curr->data <<endl;

    last->next=curr;
    detectloop(head);

return 0;
}














