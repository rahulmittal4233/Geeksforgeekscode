#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

vector <vector <int> > v;
vector <vector <bool> > ch;
int ans = INT_MAX;

bool issafe(int i,int j, int n,int m)
{
    if (i>=0 && j>=0 && i<n && j<m && v[i][j]==1 && ch[i][j]==false )
        return true;
    return false;
}

void findpath(int i, int j,int n, int m, int x, int y, int cur)
{
    if (i==x && j==y)
    {
        if (cur < ans)
            ans = cur;
    }

    ch[i][j]=true;

    if (issafe(i+1,j,n,m) )
        findpath(i+1,j,n,m,x,y,cur+1);
    if (issafe(i-1,j,n,m) )
        findpath(i-1,j,n,m,x,y,cur+1);
    if (issafe(i,j+1,n,m) )
        findpath(i,j+1,n,m,x,y,cur+1);
    if (issafe(i,j-1,n,m) )
        findpath(i,j-1,n,m,x,y,cur+1);
}


int main ()
{
    int n,m,t;
    cin >> n >>m;
    v.assign(n,vector <int> () );
    ch.assign(n,vector <bool> () );

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin >> t;
            v[i].push_back(t);
            ch[i].push_back(false);
        }
    }
    int x,y;
    cin >> x >> y;

    if (v[0][0]==0 || v[x][y]==0 )
        cout << "No path can exist.";

    findpath(0,0,n,m,x,y,1);

   cout << "Shortest Source to Destination Path is of Length: " << ans << endl;


    return 0;
}
