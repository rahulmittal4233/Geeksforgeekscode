#include <bits/stdc++.h>
#include <map>
#include <string.h>
#include <iostream>
using namespace std;

struct node
{
    int data; //hd;
    struct node *left, *right;
};

struct node *newnode(int item)
{
    struct node *temp = new node;
    temp-> data =item;
    temp->left = temp -> right = NULL;
    return temp;
};


void printBottomViewUtil(struct node *root, int curht, int hd, map<int, pair<int,int> > &m)  //IMPORTANT "&m" and not m as we are passing address of map and not copying the map
{
    if (root)
    {
        if (m.find(hd) == m.end())
        {
         /* DOESNT WORK
            pair <int,int> p;
            p.first = root-> data;
            cout << p.first << " ";
            p.second = curht;
            m[hd] = p;
            */
            m[hd] = make_pair(root->data, curht);  //NOTICE the syntax
        // cout << m[hd].first << " ";
        }
        if (m.find(hd)!=m.end())
        {
            pair <int,int> p = m[hd];
            if (p.second < curht )
            {
             m[hd].second = curht;
             m[hd].first = root->data;
            // cout << m[hd].first << " ";
            }
        }
        printBottomViewUtil(root->left,curht+1,hd-1,m);
        printBottomViewUtil(root->right,curht+1,hd+1,m);

    }
}



void printBottomView(node * root)
{

    // Map to store Horizontal Distance,
    // Height and Data.
    map < int, pair < int, int > > m;

    printBottomViewUtil(root, 0, 0, m);

     // Prints the values stored by printBottomViewUtil()
    map < int, pair < int, int > > ::iterator it;        //NOTICE the syntax
    for (it = m.begin(); it != m.end(); ++it)
    {
        pair < int, int > p = it -> second;
        cout << p.first << " ";
    }
}
int main()
{
struct node *root = newnode(20);
    root -> left = newnode(8);
    root -> right = newnode(22);
    root -> left -> left = newnode(5);
    root -> left -> right = newnode(3);
    root -> right -> left = newnode(4);
    root -> right -> right = newnode(25);
    root -> left -> right -> left = newnode(10);
    root -> left -> right -> right = newnode(14);
    cout << "Bottom view of the given binary tree :\n";
    printBottomView(root);
    return 0;

}
