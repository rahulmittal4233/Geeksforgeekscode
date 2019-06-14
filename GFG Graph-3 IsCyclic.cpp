#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

vector <vector <int> > v;
vector <bool> vis;

void addedge(int u,int b)
{
    v[u].push_back(b);
}

int iscyclicutil(int i)
{
    vis[i]=true;
    int k=0;

    for (int j=0;j<v[i].size();j++)
    {
        if (vis[v[i][j]]==true)
        {
        cout << "Cycle Exisits" << endl;
        return 1;
        }
        if (vis[v[i][j]]==false)
        k = iscyclicutil(v[i][j]);

        if (k==1)
            return 1;
    }
    return 0;
}

void iscyclic()
{
    int k=0;
    for (int i=0;i<v.size() && v.size()!=0;i++)
    {
        if (vis[i]==false)
           k =  iscyclicutil(i);
        if(k==1)
        {
//        cout << i <<  "Cycle Exisits" << endl;
        break;
        }
    }
    if (k==0)
        cout << "cycle doesn't exist" << endl;
}

void printgraph()
{
    int i=0;
    for (i=0;i<v.size();i++)
    {
        cout << i << " adjacent nodes: ";
        for (int j=0;j<v[i].size() && v.size()!=0;j++)
        {
            cout << v[i][j] << " ";
        }
    cout << endl;
    }
}


int main()
{
    v.assign(4,vector <int> () );
    vis.assign(4,false);
    addedge(0,1);
    addedge(0,2);
    addedge(1,2);
    addedge(2,0);
    addedge(2,3);
    addedge(3,3);
    printgraph();
    iscyclic();

    return 0;
}
