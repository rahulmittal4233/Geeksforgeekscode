#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>

 using namespace std;

 int main ()
 {
     int i,sz,j,n;
     cin >> n;
     int a[n];

     for (i=0;i<n;i++)
        cin >> a[i];

     cin >> sz;
     int ans,st;
     ans=sz;
     st=0;

     map <int,int> m;
    map <int,int> ::iterator it;

     for (i=0;i<n;i++)
     {
         if (i<sz)
         {
            m[a[i]]++;
            cout << i << " " << a[i] << " --  " << ans << m[a[i]]<< endl;
            continue;
         }

         if (i>=sz)
        {
            it = m.find(a[st]);
            m.erase(it);
            st++;

            for (it=m.begin(); it!=m.end();it++)
                cout << " Map Value: " << it->first << " " << it-> second << endl;

            if (m.find(a[i])!=m.end())
                    continue;
            else
            {
                m[a[i]]++;
                ans++;
                cout << i << " " << a[i] << " " << ans << endl;
            }
        }
     }

     cout << ans << endl;

     return 0;
 }
