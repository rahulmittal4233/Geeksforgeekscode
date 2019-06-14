#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

vector <vector <int> > v;
vector <bool> vis;

void addedge (int a, int b)
{
    v[a].push_back(b);
 //   v[b].push_back(a);
}



void dfs(int t)
{
    vis[t]=true;

    for (int i=0;i<v[t].size();i++)
    {
        if (vis[v[t][i]]==false)
            dfs(v[t][i]);
    }
}

void noofislands(int n)
{
    int ans=0;
    for (int i=0;i<n;i++)
    {
        if(v[i].size()!=0 && vis[i]==false)
        {
            dfs(i); ans++;
        }
    }
    cout << "No. of Islands are: " << ans << endl;
}

void printgraph()
{
    for (int i=0;i<v.size();i++)
    {
        cout << "Node " << i <<" ";
        for (int j=0;j<v[i].size();j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n,m,s;
    cin >> n >> m;
    if (n>=m)
        s=n;
    else
        s=m;

    v.assign(s,vector <int> ());
    vis.assign(s,false);
    int t;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin >> t;
            if (t==1)
               addedge(i,j);
        }
    }
    printgraph();
    noofislands(s);
}
