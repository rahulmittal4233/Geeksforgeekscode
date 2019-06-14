#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <stdlib.h>

using namespace std;

int main ()
{
    map <int,char> m;
    int n,i,j,minn=0,maxx=0;
    cin >> n;
    map <int,char> ::iterator it;

    for (i=0;i<n;i++ )
    {
         cin >> j;
         m[j]='A';
    }

    for (i=0;i<n;i++ )
    {
         cin >> j;
         m[j]='D';
    }

    it=m.begin();

    for (it=m.begin();it!=m.end();it++)
    {
        if (it->second=='A')
            minn++;
        if (it->second=='D')
            minn--;
        if (minn>maxx)
            maxx = minn;
    }

cout << maxx << endl;

}
