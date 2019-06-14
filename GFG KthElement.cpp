#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int kthelement(int a[], int b[],int a1, int an, int b1, int bn, int k )
{
int mid1,mid2;
mid1 = (an-a1)/2;
mid2 = (bn-b1)/2;

if (a1==an)
   return a[k];// << endl;

if (b1==bn)
    return b[k];//<< endl;

if (k > (mid1 + mid2))
{
    if (a[mid1]>b[mid2])
      return  kthelement(a,b,a1,an,mid2+1,bn,k-mid2-1);
    else
        return kthelement(a,b,mid1+1,an,b1,bn,k-mid1-1);
}

else
{
    if (a[mid1]>b[mid2])
        return kthelement(a,b,a1,mid1,b1,bn,k);
    else
        return kthelement(a,b,a1,an,b1,mid2,k);
}

}


int main ()
{
    int n,m,k;
    cin >> n >> m;
    int a[n],b[m];

    for (int i=0;i<n;i++)
        cin >>a[i];

    for (int i=0;i<m;i++)
        cin >>b[i];
    cin >> k;
    cout << kthelement(a,b,0,n,0,m,k-1) << endl;

    return 0;
}
