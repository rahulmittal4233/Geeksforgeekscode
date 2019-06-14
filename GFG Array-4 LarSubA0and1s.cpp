#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <stdlib.h>

using namespace std;

int main()
{
    int n,i,j,st=0,en=0,ll=0,maxx=0;
    cin >> n;
    int a[n],s[n];
    map <int,int> m;
    map <int,int> ::iterator it;

    for (i=0;i<n;i++)
    {
        cin >> j;
      if (j==0)
        a[i]=-1;
        else
        a[i]=j;

    if (i>0)
        s[i]=s[i-1]+ a[i];
    else
        s[i]=a[i];

    if (m.find(s[i])== m.end())
        m[s[i]]=i;
    else
    {
        st=m[s[i]];
        ll=i-st;
        if (ll>maxx)
            maxx=ll;
    }

    }
       for (i=0;i<n;i++)
       {
           if (s[i]==0)
            maxx=max(maxx,i+1);
       }

    for (it=m.begin();it!=m.end();it++)
        cout << it->first << " " << it->second <<endl;

 cout << "Lenght of Sub array is: " << maxx << endl;
    return 0;
}
