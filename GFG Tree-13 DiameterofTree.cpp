#include <bits/stdc++.h>
#include <map>
#include <string.h>
#include <iostream>
int mx=0;
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

int diameter(struct node *root)
{
    if (root)
    {
      int   l=diameter(root->left);
       int r=diameter(root->right);
    if (mx<max(l,r)+1)
        mx=max(l,r)+1;
        return max(l,r)+1;
    }

    return 0;
}

int main()
{
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    diameter(root);
    printf("Diameter is %d\n", mx+1);

    return 0;
}
