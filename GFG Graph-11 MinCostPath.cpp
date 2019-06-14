#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
vector <vector<int> > ar;
vector <vector<int> > dist;


void mincostpath(int n)
{
    int a[4]={1,-1,0,0};
    int b[4]={0,0,1,-1};
    int p,q,n1,n2;
    queue <pair<int,int> > qu;
    qu.push(make_pair(0,0));
    pair <int,int> cur;
    dist[0][0] = ar[0][0];
    while(!qu.empty())
    {
        cur=qu.front();
        p=cur.first;
        q=cur.second;
   //     cout << p << " " << q;
        qu.pop();
        for (int i=0;i<4;i++)
        {
            n1= p + a[i];
            n2= q + b[i];
            if (n1>=0 && n2>=0 && n1<n && n2<n && (dist[n1][n2]>(dist[p][q]+ ar[n1][n2])) )
            {
             dist[n1][n2] = dist[p][q]+ ar[n1][n2];
            qu.push(make_pair(n1,n2));
            }
        }
    }

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cout << dist[i][j] << " ";

      cout << "Minimum Cost is: " << dist[n-1][n-1] << endl;
}





int main ()
{
    int n,m,t;
    cin >>n;
    ar.assign(n,vector <int> () );
    dist.assign(n,vector <int> () );
    //int dist[n][n];

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin >> t;
            ar[i].push_back(t);
            dist[i].push_back(99999);
        }
    }


    //for (int i=0;i<n;i++)
  //      for (int j=0;j<n;j++)
//            cout << dist[i][j] << " ";

    mincostpath(n);

    return 0;
}
