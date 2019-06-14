#include <stdio.h>
#include <stdlib.h>
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
temp-> data = item;
temp -> left = temp-> right = NULL;
return temp;
};

bool isBST(struct node *root)
{
    if (root)
    {
        //IMPORTANT
        static struct node *prev=NULL;  //Static variables when used inside function
        //are initialized only once, and then they hold there value even through
        //function calls. These static variables are stored on static storage area ,
        // not in stack.

        if (!isBST(root->left))
            return false;

        if (prev!=NULL && prev->data>=root->data)
            return false;
        prev = root;

        return isBST(root->right);

    }
}
//here, calls are made to left child until it reaches the last left node, which is stored
//in prev and then compared with the root's data value of its parent and so on
// that is why prev's nodes value should be less than current root's valus
// UNDERSTAND CALL FLOW

int main ()
{
    struct node *root = newnode(3);
//    root-> data = 11;
    root->left     = newnode(2);
    root->right     = newnode(5);
    root->left->left = newnode(1);
    root->left->right = newnode(4);

    if (isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";
        return 0;
}
