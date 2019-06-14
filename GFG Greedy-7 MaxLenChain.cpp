#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b;
    cin >>n;
    vector < pair<int,int> > p;

    for (int i=0;i<n;i++)
    {
        cin >> a;
        cin >> b;
        p.push_back(make_pair(a,b));
    }

    sort(p.begin(),p.end());

  int i,j,maxx=1;
    int ml[n]={0};

    for (i=0;i<n;i++)
        ml[i]=1;

    for (i=1;i<n;i++)
        for (j=0;j<i;j++)
    {
        if (p[j].second < p[i].first && ml[i]<(ml[j]+1) )
        {
             ml[i]=ml[j]+1;
            if (maxx<ml[i])
                maxx=ml[i];
        }
    }
    cout << maxx << endl;
    return 0;
}
