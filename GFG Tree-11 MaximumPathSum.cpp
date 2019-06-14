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


int maxPathSumUtil(struct node *root)
{
    if(root)
    {
    if(root->left==NULL && root->right==NULL)
        return root->data;

    if (root->left ==NULL)
        return maxPathSumUtil(root->right)+root->data;

    if (root->right ==NULL)
        return maxPathSumUtil(root->left)+root->data;


    int r=maxPathSumUtil(root->right);
    int l = maxPathSumUtil(root->left);

    if (mx < (r+l+(root->data)))
        mx=r+l+(root->data);

    return (max(r,l) + root->data);
    }

return 0;
}

int maxPathSum(struct node *root)
{
 //  static int mx=0;
    return maxPathSumUtil(root);
}

int main()
{
    struct node *root = newnode(-15);
    root->left = newnode(5);
    root->right = newnode(6);
    root->left->left = newnode(-8);
    root->left->right = newnode(1);
    root->left->left->left = newnode(2);
    root->left->left->right = newnode(6);
    root->right->left = newnode(3);
    root->right->right = newnode(9);
    root->right->right->right= newnode(0);
    root->right->right->right->left= newnode(4);
    root->right->right->right->right= newnode(-1);
    root->right->right->right->right->left= newnode(10);
    maxPathSum(root);
    cout << "Max pathSum of the given binary tree is "
         << mx;
    return 0;
}
