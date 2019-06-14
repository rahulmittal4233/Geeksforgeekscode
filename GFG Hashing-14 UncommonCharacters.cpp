#include <stdlib.h>
#include<map>
#include <vector>
#include<string.h>
#include <iostream>
using namespace std;

int main()
{

    int i,j,k,ab[150];

    vector <char> ans;
    int anu[150];

    string a,b;
    cin >> a >> b;
  //  i=a[i]-97;

    for (i=0;i<150;i++)
{       ab[i]=0; anu[i]=0;
}
    for (i=0;i<a.size();i++)
        ab[a[i]]++;

    for (i=0;i<b.size();i++)
    {
        if (ab[b[i]]>=1)
        {
         ab[b[i]]=1223;
         continue;

        }
        else
        {
            if (anu[b[i]]!=1)
            {   ans.push_back(b[i]);
                anu[b[i]]=1;
            }
        }
    }

    for (i=0;i<a.size();i++)
    {
       if ( ab[a[i]] == 1223)
            continue;
        else
        {
            if (anu[a[i]]!=1)
            {   ans.push_back(a[i]);
                anu[a[i]]=1;
            }
        }
    }

    for (i=0;i<ans.size();i++)
        cout << ans[i] << " ";

    cout << endl;


        return 0;
}
