#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

vector <vector <pair<int,int> > >  v;
vector <bool> ass;

void addedge(int u, int b, int w)
{
    v[u].push_back(make_pair(b,w));
    v[b].push_back(make_pair(u,w)); //if Undirected

}

void printgraph(int n)
{

for (int i=0;i<n;i++)
{
    cout << "Node " << i << endl;;
    for (int j=0;j<v[i].size();j++)
    {
        pair <int,int> it;
        it = v[i][j];
        cout << " makes an edge with Node " << it.first << " with a weight " << it.second << endl;
    }
}
}

void dfsutil(int k)
{
    cout << k << " ";
    ass[k]=true;
    pair <int,int> it;

    for (int j=0;j<v[k].size();j++)
    {
        it = v[k][j];
        if ( ass[it.first] ==false)
            dfsutil(it.first);
    }
}

void dfs(int n)
{
    ass.assign(n,false); //int i=0;
    cout << "DFS of the Graph: ";

    for (int i=0;i<n;i++) //is graph is not connected
    {
       if (ass[i]==false)
        dfsutil(i);
    }
}

void bfs(int n)
{
    ass.assign(n+1,false);
    queue <int> q;
    pair <int,int> it;
    q.push(0);
    int k;
    cout << "BFS Of the Graph: ";
    while(!q.empty())
    {
        k=q.front();
        cout << k << " ";
        q.pop();

        for (int i=0;i<v[k].size();i++)
        {
            it  =v[k][i];
            if (ass[it.first]==false)
            {       q.push(it.first);
                    ass[it.first]=true;
            }
        }
    }
}



int main()
{
        int n=5;
     //   cin >> n;
        v.assign(n,vector < pair<int,int> > () );
    addedge(0, 1, 10);
    addedge(0, 4, 20);
    addedge(1, 2, 30);
    addedge(1, 3, 40);
    addedge(1, 4, 50);
    addedge(2, 3, 60);
    addedge(3, 4, 70);
        printgraph(n);
        dfs(5);
        cout << endl;
        bfs(5);
        cout << endl;

}
