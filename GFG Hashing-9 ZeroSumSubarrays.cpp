#include <stdlib.h>
#include<map>
#include <vector>
#include<string.h>
#include <iostream>
using namespace std;

int main()
{
    int n,flag=0,sum=0,j,ans=0;
    cin >>n;
    int a[n];
    map <int,int> m;
    vector <int> v;

    for (int i=0;i<n;i++)
    {
        cin >> a[i];
        sum+=a[i];
        if (a[i]==0 && flag>=0)
            flag++;

        if (a[i]!=0 && flag>0)
        { v.push_back(flag); flag=0;}

        if (a[i]==0)
            continue;

        if(m.find(sum)!=m.end())
        { m[sum]++; continue; }

        m[sum]=1;
    }

    if (flag>0)
        v.push_back(flag);

    map<int,int> ::iterator it;

    for(it=m.begin();it!=m.end();it++)
    {
        j=it->second;
        ans+=(j*(j-1))/2;
    }

//        vector <int> ::iterator t;
        for (int i=0;i<v.size();i++)
        {
            j=v[i];
            ans+=(((j*(j-1))/2)+j);
        }
        cout << "Answer is " << ans << endl;
}
