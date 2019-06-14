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

void topsortutil(int k, stack <int> &s)
{
    vis[k]=true;

    for (int i=0;i<v[k].size();i++)
    {
        if (vis[v[k][i]]==false)
            topsortutil(v[k][i],s);
    }
    s.push(k);
}



void topsort()
{
    stack <int> s;
    cout << "Topological Order is: ";
    for (int i=0;i<v.size();i++)
    {
        if (vis[i]==false)
            topsortutil(i,s);
    }

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}





int main()
{
    v.assign(6,vector <int> ());
    vis.assign(6,false);
    addedge(5,2);
    addedge(5,0);
    addedge(4,0);
    addedge(4,1);
    addedge(2,3);
    addedge(3,1);
    topsort();
    return 0;
}








