#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <stdlib.h>

using namespace std;

int main()
{
    int n,i,j;
    cin >> n;
    int a[n];

    for (i=0;i<n;i++)
        cin >>a[i];
    int s=1;

    while (s!=0)
    {
    s=0;
    for (i=1;i<n-1;i+=2)
    {
     if (a[i-1]>a[i])
     {
        swap (a[i-1],a[i]);
        s++;
     }

     if (a[i+1]>a[i])
      {
        swap(a[i],a[i+1]);
      s++;
      }
      if (a[i+2]<a[i+1])
      {
        swap(a[i+2],a[i+1]);
      s++;
      }
      }
    }

for (i=0;i<n;i++)
    cout << a[i] << " ";

    return 0;
}
