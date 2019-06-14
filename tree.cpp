#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    temp->left = temp ->right = NULL;
    return temp;
};
/*
void printpreordertree(struct node *root)
{
    if (root == NULL)
        return;

    cout<< root->data << " ";
    printpreordertree(root->left);
    printpreordertree(root-> right);
}
*/
void leftviewutil(struct node *root, int level ,int *maxlevel)
{
    if (root == NULL)
        return;

    if (level > *maxlevel)
    {
        *maxlevel = level;
    cout << "Level:" << level << "   " << root->data << endl;
    }
    leftviewutil(root->left, level+1, maxlevel);
    leftviewutil(root->right, level+1, maxlevel);
}

void leftview(struct node *root)
{
    int *maxlevel;
    *maxlevel = -1;
    leftviewutil(root, 0, maxlevel);
}

int main ()
{
    struct node *root = newnode(12);
    root->left = newnode(13);
    root->right = newnode(14);
    root->left->left = newnode(15);
    root->left-> right = newnode(16);

    leftview(root);

    return 0;
}
