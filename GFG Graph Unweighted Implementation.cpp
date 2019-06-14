#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
vector <vector <int> > v;

void addedge(int a, int b)
{
    v[a].push_back(b);
    v[b].push_back(a);  //is it is undirected
}

void printgraph(int n)
{
    int i=0;
    for (i=1;i<=n;i++)
    {
        cout << i << " adjacent nodes: ";
        for (int j=0;j<v[i].size();j++)
        {
            cout << v[i][j] << " ";
        }
    cout << endl;
    }
}

void dfsutil(vector <bool> &vis , int k) //NEEDED & before vis [array name] as address is to be passed
{
     cout << k <<" ";
    vis[k]=true;

    for (int i=0;i<v[k].size();i++)
    {
        if (vis[v[k][i]]==false)
            dfsutil(vis,v[k][i]);
    }
}

void dfs(int n)
{
    vector <bool> vis;
    vis.assign(n+1 ,false);  //Careful with N i.e it is "N+1" as nodes start from 1

    cout << "DFS of the graph: ";
   // dfsutil(vis,1);   //will be enough for dfs is graph is connected

    for (int i=1;i<=n;i++)  //Needed if Graph is not connected
    {
        if (vis[n]==false)
            dfsutil(vis,i);
    }
}

void bfs(int n)
{
    queue <int> q;
    vector <bool> vis;
    vis.assign(n+1,false);
    cout << "BFS of the Graph: ";
    q.push(1);
    vis[1]=true;
    int k;

    while(!q.empty())
    {
        k=q.front();        // returns front element, it is printed, deleted from the queue and all its adjacent elements are inserted in the queue.
        cout << k << " ";
        q.pop();

        for (int i=0;i<v[k].size();i++) //Inserts all the Adjacent nodes in the queue
        {
            if (vis[v[k][i]]==false)
            {
            q.push(v[k][i]);
            vis[v[k][i]]=true;
            }
        }
    }

cout << endl;
}

int main ()
{
    int n,e,k,j;
  // cin >> n ;//>> e; //no. of edges
    n=5; e=7;    //Take care of size of graph, i.e it sharts with 1 and not 0. so initialize till <=n
    v.assign(6,vector <int> () );  //VERY HANDY IF No. OF NODES ARE KNOWN
  //  n=5;
    //for (int i=0;i < e; i++)
    //{
     //   cin >>j >> k;
  //      addedge(j,k);
  //      addedge(k,j);  //if graph is undirected

        addedge(1,2);
        addedge(1,3);
        addedge(1,4);
        addedge(3,5);
//        addedge(4,2);
  //      addedge(3,1);
    //    addedge(2,4);
//    }
//cout << v[1][0];
printgraph(n);
cout << endl;
dfs(n);
cout << endl;
bfs(n);
    return 0;
}
