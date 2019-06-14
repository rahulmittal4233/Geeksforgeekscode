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


void printSpiralUtil(struct node *root, int l, int cl, int flag)
{
    if(root)
    {
        if(cl==l)
        {
            cout<< root->data << " ";
        return ;
        }
        if (flag ==0)
        {
        printSpiralUtil(root->left,l,cl+1,flag);
        printSpiralUtil(root->right,l,cl+1,flag);
        }
        if (flag ==1)
        {
        printSpiralUtil(root->right,l,cl+1,flag);
        printSpiralUtil(root->left,l,cl+1,flag);
        }
    }
}

int height(struct node *root)
{
    if (!root)
        return 0;

    return max(height(root->left),height(root->right)) + 1;
}

printSpiral(struct node *root)
{
    int iheight = height(root);
    int flag = 1;
    for(int i=0;i<iheight;i++)
    {
        printSpiralUtil(root,i,0,flag);
        cout << endl;
    if (flag==0)
    {
        flag=1; continue; }
    if (flag==1)
    {
        flag=0;
    }

}}

int main()
{
    struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(7);
    root->left->right = newnode(6);
    root->right->left = newnode(5);
    root->right->right = newnode(4);
    printf("Spiral Order traversal of binary tree is \n");
    printSpiral(root);

    return 0;

}
