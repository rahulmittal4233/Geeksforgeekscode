#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <string.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    char prev,temp;
    int previ;
    prev='-';

    for (int i=0;i<s.size();i++)
    {
        temp=s[i];
        if (s[i]==prev)
        {
            s[i]='-';
            s[previ]='-';
            continue;
        }
        prev= temp;
        previ= i;
    }


    for (int i=0;i<s.size();i++)
    {
        if (s[i]=='-')
            continue;
        cout << s[i];
    }

        cout << endl;

    return 0;
}
