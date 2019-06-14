#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int main()
{

 int n,k,minn=0,maxx=0,i,en,st;
 cin >> n >> k;
 int a[n];

 for (i=0;i<n;i++)
        cin >> a[i];

 sort (a,a+n);
en=n;
for (i=0;i<en;i++)
{
    minn+=a[i];
    en-=k;
}
st=0;
for (i=n-1;i>=st;i--)
{
    maxx+=a[i];
    st+=k;
}

cout << minn << " " << maxx << endl;




    return 0;
}
