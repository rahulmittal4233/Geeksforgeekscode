#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include<map>
#include<string.h>
using namespace std;

int main()
{
    int dif=0,prev,y,z;
    string st;
    cin >> st;
    map<char,int> m;

    for (int i=0;i<st.size();i++)
    {
        m[st[i]]++;
       // cout<<m[st[i]] << endl;
    }
    map <char,int> ::iterator it;

    for(it=m.begin();it!=m.end();it++)
    {
        if (it == m.begin())
            prev=it->second;
      //cout << prev;
       y=it->second;
        dif = abs(y - prev);
    if (dif>1)
    {
        cout << "00";
        break;
    }
    if (dif==0)
        continue;
    }

//    if (dif==0)
        cout<< "01";
    return 0;
}
