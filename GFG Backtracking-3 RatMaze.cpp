#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;
int a[10][10];

vector<string> v;

void solvemazeutil(int i, int j, int n,string prev)
{
    if (i==n-1 && j==n-1)
    {
        v.push_back(prev);
        return;
    }
    if (i>=0 && i<n && j>=0 && j<n && a[i][j]==1 )
    {
        solvemazeutil(i+1,j,n,prev+"D");
        solvemazeutil(i,j+1,n,prev+"R");
  //      solvemazeutil(i-1,j,n,prev+"U");
  //      solvemazeutil(i,j-1,n,prev+"L");
    }

    return;
}

void solvemaze(int n)
{
    solvemazeutil(0,0,n,"");

    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++)
        cout << v[i] << " ";
}


int main()
{
    int n;
    cin >> n;

    for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                cin >> a[i][j];

    solvemaze(n);

//    printsol();
}
