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
int n,k;
cin >>n;
vector <vector<int> > v;

for (int i=0;i<n;i++)
{
    cin >> k;
    newnode(k);
}
    cin >>k;
    k=k%n;

reversee();

struct node *curr;
curr = head;
int i=0,j=0,t=0;

v.push_back(vector<int>());

while(t<n)
{
    t++;
    v[i].push_back(curr->data);
    curr=curr->next;
    if (t%k==0)
     {
       i++;
       v.push_back(vector<int>());
     }
}
t=0; i=0;

while (t<n)
{
    cout << v[i][j++] <<" ";
    if (j==k)
    {
        i++; j=0;
    }
t++;
}
cout << endl;
i=0; t=0;
curr=head;
while (t<n)
{
        j=v[i].size() - 1;

    while (j>=0)
    {
    curr->data = v[i][j--];
    curr=curr->next;
    t++;
    }
i++;

}

display();




return 0;
}





