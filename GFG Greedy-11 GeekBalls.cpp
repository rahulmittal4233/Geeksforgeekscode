#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int maxballs(int a[], int b[], int n,int m)
{
    int i=0,j=0,s1=0,s2=0,ans=0;

    while(i<n && j<m)
    {
        if (a[i]>b[j])
            s2+=b[j++];


        else if (a[i]<b[j])
            s1+=a[i++];


        else
        {
        s1+=a[i];
        s2+=b[j];

        if (s1>s2)
        {
            ans+=s1;
            while (i+1<n && a[i]==a[i+1])
                ans+=a[i++];
        }

        if (s1<s2)
        {   ans+=s2;
            while (j<=m && b[j]==b[j+1])
                ans+=b[j++];
        }

        i++; j++;
        s1=s2=0;
        }
    }
        while(i<n)
            s1+=a[i++];

        while(j<m)
            s2+=b[j++];

        ans+=max(s1,s2);
  cout << "Answer is :" << ans << endl;

    return ans;
}


int main()
{
    int n,m;
    cin >> n >> m;
    int a[n], b[m];

    int i,ans;

    for (i=0;i<n;i++)
        cin >> a[i];

    for (i=0;i<m;i++)
        cin >> b[i];

    ans = maxballs(a,b,n,m);

    cout << "Answer is :" << ans << endl;

    return 0;
}
