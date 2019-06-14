#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

vector <vector <int> > g;
vector <vector <int> > tg;
vector <bool> vis;
stack <int> s;

void addedge(int a, int b)
{
    g[a].push_back(b);
}

void printgraph(int n)
{
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<g[i].size();j++)
            cout << g[i][j] << " ";
    cout << endl;
    }
}

void printTGgraph(int n)
{
    cout << "Transpose Graph: " << endl;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<tg[i].size();j++)
            cout << tg[i][j] << " ";
    cout << endl;
    }
}

void transpose_graph(int n)
{
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<g[i].size();j++)
        {
            tg[g[i][j]].push_back(i);
        }
    }
}

void addtostack(int k)  //here, for all nodes to which edge exists from k,
{                        //are called again recursively and in the end k is entered in the stack. i.e all the components connected to k are added first in stack and k is entered later.

    vis[k]=true;

    for (int i=0;i<g[k].size();i++)
    {
        if (vis[g[k][i]]!=true)
            addtostack(g[k][i]);
    }
    s.push(k);
}

void markingviswithstack(int k)  //we basically mark all the components strongly connected to k as visited
{
    vis[k]=true;

    for (int i=0;i<tg[k].size();i++)
    {
        if (!vis[tg[k][i]])
        {
            cout << tg[k][i] << " " ;
            markingviswithstack(tg[k][i]);
        }
    }
}

void kosaraju(int n)
{
    vis.assign(n+1,false);

    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
            addtostack(i);
    }

    vis.assign(n+1,false);
    int cur,res=0;

    while (!s.empty()) //stack is not empty
    {
        cur = s.top();
        s.pop();
        if (!vis[cur])
        {
            res++;
             cout << res << " Connected Component: " << cur << " ";
             markingviswithstack(cur);
            cout << endl;
        }
    }
    cout << "Total Strongly connected components are: " << res << endl;
}

int main()
{
    int n,m,t1,t2;
    cin >> n >> m;
    g.assign(n+1,vector <int> () );
    tg.assign(n+1,vector <int> () );

    for (int i=1;i<=n;i++)
    {
        cin >> t1 >> t2;
        addedge(t1,t2);
    }

    printgraph(n);
    transpose_graph(n);
    printTGgraph(n);

    kosaraju(n);

    return 0;
}






