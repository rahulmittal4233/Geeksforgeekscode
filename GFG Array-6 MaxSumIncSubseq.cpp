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
  int a[n],maxs[n]={0};
  int ans=0;
  for (i=0;i<n;i++)
      cin >> a[i];

maxs[0]=a[0];
ans = maxs[0];
for (i=1;i<n;i++)
 {
     for (j=0;j<i;j++)
    {
        if (a[i]>a[j])
            maxs[i]=max(maxs[i],maxs[j]+a[i]);

    ans=max(ans,maxs[i]);
 //   cout << "Answer is: " << ans << endl;

    }
 }

cout << "Answer is: " << ans << endl;

  return 0;
}
