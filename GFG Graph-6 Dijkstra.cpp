#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

vector <vector <int> > v;
vector <bool> vis;
vector <int> dis;  //dis[i] contains shortest distance of i node from source node. Is updated continuously

int mindist(int n)  //Returns index of node which is closest to the current finalized Minimum Spanning Tree
{
    int minn=9999,index;
    for (int i=0;i<n;i++)
    {   if (vis[i]==false && dis[i]<minn )
        {
            minn=dis[i];
            index=i;
        }
    }
return index;
}

void dijstra(int s,int n)  //Gives shortest distance of each node from Source node
{
    dis[s]=0; //distance of source updated to Zero

    for (int i=0;i<n;i++)       //Each time we pick the closest node and the distance of all the nodes is updated to new value. We keep doing this unless all nodes are covered.
    {
        int u = mindist(n);   //Currently closest node to MST taken
        vis[u]=true;        // Updated
        for (int a=0;a<n;a++)
        {
            if (vis[a]!=true && v[u][a] && (dis[u]+v[u][a])<dis[a] )  //If not visited, edge exists, distance of node 'a' is updated to current distance it has from MST
                dis[a]=dis[u]+v[u][a];
        }
    }
}


void printgraph()
{
    for (int i=0;i<v.size();i++)
    {
        for (int j=0;j<v[i].size();j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    v.assign(n,vector <int> ());
    vis.assign(n,false);
    dis.assign(n,99999);

    int t;

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin >> t;
            v[i].push_back(t);  // Adjacency Matrix Representation
        }
    }
    int s;
    cin >> s;
    printgraph();
    dijstra(s,n);
cout << endl;
    for (int i=0;i<n;i++)
        cout << dis[i] << " ";
}
