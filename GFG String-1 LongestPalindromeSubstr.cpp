#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <string.h>
using namespace std;

void findlon(string s)
{
    int l,r,ll=s.length();
    int ansl,ansr,maxx=0,len=0;

    for (int i=0;i<ll;i++)
    {
        l=i-1; r=i+1; len=1;
        while(l>=0 && r<ll && s[l]==s[r])
        {
            len+=2;
            if (len>maxx)
            {
                ansl=l; ansr=r; maxx=len;
            }
            l--; r++;
        }

        len=0;
        l=i; r=i+1;

        while(l>=0 && r<ll && s[l]==s[r])
        {
            len+=2;
            if (len>maxx)
            {
                ansl=l; ansr=r; maxx=len;
            }
            l--; r++;
        }
    }

    for (int i=ansl;i<=ansr;i++)
        cout << s[i];
    cout << endl;
//    cout << l<< endl;
}


int main()
{

    string s;

    cin >> s;

    findlon(s);
 return 0;
}
