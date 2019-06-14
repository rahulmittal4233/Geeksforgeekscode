
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

bool identicalTrees(struct node*root1, struct node *root2)
{
    if (root1 && root2)
    {
         if (root1->data == root2->data)
        {
            if(identicalTrees(root1->left,root2->left) && identicalTrees(root1->right,root2->right))
            return true;
        }

    }
    if (root1==NULL && root2==NULL)
        return true;

            return false;


}

int main()
{
    node *root1 = newnode(1);
    node *root2 = newnode(1);
    root1->left = newnode(2);
    root1->right = newnode(3);
    root1->left->left = newnode(4);
    root1->left->right = newnode(5);

    root2->left = newnode(2);
    root2->right = newnode(3);
    root2->left->left = newnode(4);
    root2->left->right = newnode(5);

    if(identicalTrees(root1, root2))
        cout << "Both tree are identical.";
    else
        cout << "Trees are not identical.";

return 0;
}
