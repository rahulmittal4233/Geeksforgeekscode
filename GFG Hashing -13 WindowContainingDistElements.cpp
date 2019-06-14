#include <stdlib.h>
#include<map>
#include <vector>
#include<string.h>
#include <iostream>

using namespace std;

int main()
{
    map <int,int> m;
    //vector <int> v;

    int st,k,n,i,dis=0;
    cin >> n >> k;
    int a[n];
    st=0;

    for (i=0;i<n;i++)
        cin >> a[i];

    for (i=0;i<n;i++)
    {
        if(i<k)
        {
            if (m.find(a[i]) == m.end())
            { m[a[i]]=1; dis++; }
            else
            m[a[i]]++;
        continue;
        }
        if (i==k)
        cout << dis << " ";

        if (i>=k)
        {
//            m[a[st]]--;
            if (m[a[st]]==1)
            {
                    dis--;
                m.erase(a[st]);
            }

            else if (m.find(a[st]) != m.end())
                m[a[st]]--;

     //       m[a[st]]--;

            if (m.find(a[i]) == m.end())
            { m[a[i]]=1; dis++; }


            cout << dis << " ";
        st++;
        }
//        cout << dis << " ";
    }
    cout << "" << endl;

   // return 0;
}
