#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <bits/stdc++.h>

using namespace std;



void joinmerge(int a[], int l, int m, int r)
{
    int ll[m-l+1], rr[r-m];
    int i,j,k;

    for (i=0;i<=m-l;i++)
        ll[i]=a[l+i];

    for (i=0;i<r-m;i++)
        rr[i]=a[m+1+i];

    j=0; k=0; i=l;

    while (j<=(m-l) && k<(r-m))
    {
        if (ll[j]<rr[k])
            a[i]=ll[j++];
        else
            a[i]=rr[k++];
    i++;
    }

    while (j<=(m-l))
        a[i++]=ll[j++];

    while (k<(r-m))
        a[i++]=rr[k++];

}
void mergesort(int a[],int l,int r)
{
    if (l<r)
    {
    int m=l + (r-1)/2;

    mergesort(a,l,m);
    mergesort(a,m+1,r);

    joinmerge(a,l,m,r);
    }

   // return;
}
int main()
{
    int n;
    cin >> n ;
    int a[n];

    for (int i=0;i<n;i++)
        cin >> a[i];

    mergesort(a,0,n-1);

    for (int i=0;i<n;i++)
        cout << a[i];

    return 0;
}
