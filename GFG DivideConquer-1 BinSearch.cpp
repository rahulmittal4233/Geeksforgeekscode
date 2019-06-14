#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int binsearch(int a[], int l, int r, int k)
{
    if (l<r && r>=1)
    {
    int mid = l + (r-1)/2;

    if (a[mid]>k)
       return binsearch (a,l,mid,k);

    else if (a[mid]<k)
       return binsearch (a,mid,r,k);

    else
        return mid;

    return -1;
    }

}




int main()
{
    int n,k;
    cin >> n >> k;
    int a[n];

    for (int i=0;i<n;i++)
        cin >> a[i];

int     an = binsearch(a,0,n,k);
    cout << an << endl;
    return 0 ;
}
