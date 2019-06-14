#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,k,small,big,add,sub,ans;
    cin >> k;
    cin >> n;
    int a[n];

    for (i=0;i<n;i++)
        cin >> a[i];

        sort(a,a+n);

        //    for (i=0;i<n;i++)
          //      cout  << a[i] << " ";

        small = a[0] + k;
        big = a[n-1] - k;
        cout  << small << " " << big <<endl ;
        if (small>big)
            swap (small,big);

        for (i=1;i<n-1;i++) //neglecting both corners as they are covered in small, big.
        {
            sub = a[i]-k;
            add = a[i]+k;

            if (sub >= small || add <= big)
                continue;

            if ( (big-sub) >= (add-small) )
          {
                 big = add;
                 cout << "big: " << big << endl;
          }

            else
            {   small = sub;
                 cout << "small: " << small << endl;
            }
        }

        ans =  (big-small); //a[n-1]-a[0] that is if K is always added etc so there wont be difference in the difference.
       cout << small << "   " << big-small << endl;

        return 0;
}
