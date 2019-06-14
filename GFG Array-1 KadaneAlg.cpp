#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,k,n,maxx=0;
    cin >>n;
    int a[n],sum[n],en=0,st=0;
    for (i=0;i<n;i++)
    {
    cin >> a[i];
    if (i==0)
        sum[i]=a[i];
    else
    {
        if ((sum[i-1]+a[i])>a[i])
        {
            sum[i]=sum[i-1]+a[i];
            if (maxx<sum[i])
            {
            en=i;
            maxx=sum[i];
            }

        }
        else
        {
            sum[i]=a[i]; st=i;
            if (maxx<sum[i])
            { en=i;
            maxx=sum[i];
            }
        }
    }

    }

    cout << "MAX Sum is: " << maxx << endl;
    cout << "Array is " ;
    for (i=st;i<=en;i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
