#include <bits/stdc++.h>
#include <map>
#include <string.h>
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left, *right;
};
struct node *newnode(int item)
{
    struct node *temp = new node;
    temp->data = item;
    temp->left=temp->right = NULL;
    return temp;
};

void printVerticalOrderUtil(struct node *root,int hd,map <int, vector<int> >&m)
{
    if (root)
    {
        m[hd].push_back(root->data);

        printVerticalOrderUtil(root->left,hd-1,m);
        printVerticalOrderUtil(root->right,hd+1,m);
        return;
    }
    else
        return;
}

void printVerticalOrder(struct node *root)
{
    map <int, vector<int> > m;

    printVerticalOrderUtil(root,0,m);

    map <int, vector <int> > ::iterator it;
    for(it = m.begin();it!=m.end();it++)
    {
        cout << "Level " << it->first << " -->";
        vector<int> v = it->second;
        for (int i=0;i<v.size();i++)
            cout<< v[i] <<" ";
        cout << endl;
    }
}


int main ()
{
    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    root->right->left = newnode(6);
    root->right->right = newnode(7);
    root->right->left->right = newnode(8);
    root->right->right->right = newnode(9);
    cout << "Vertical order traversal is "<<endl;
    printVerticalOrder(root);
    return 0;
}
