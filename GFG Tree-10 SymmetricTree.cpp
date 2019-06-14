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

bool isSymmetricUtil(struct node *a,struct node *b )
{
 if (a && b)
 {
    if (a->data == b->data)
    {   if (isSymmetricUtil(a->left,b->right) && isSymmetricUtil(a->right,b->left) )
        return true;
    }
 }
 if (a== NULL && b==NULL)
    return true;
 return false;
}
bool isSymmetric(struct node *root)
{
    return isSymmetricUtil(root->left,root->right);
}

int main()
{
    node *root     = newnode(1);
    root->left        = newnode(2);
    root->right       = newnode(2);
    root->left->left  = newnode(3);
    root->left->right = newnode(4);
    root->right->left  = newnode(4);
    root->right->right = newnode(3);

    cout << isSymmetric(root);

    return 0;
}
