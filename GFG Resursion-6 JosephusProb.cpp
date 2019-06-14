#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main ()
{
    int n,k,i;
    cin >> n >> k;
    k=k-1;
    int a[n+1];
    int t=0;
    int l=n;

    //    a[i]=0;

    for (i=1;i<=n;i++)
        a[i]=1;

//    for (i=1;i<=n;i++)
    i=1;
        while(1)
        {
            if (a[i]==1)
            {
                if (t==k)
                {
                    a[i]=0;
                    t=0; l--;

                    if (l==1)
                        break;
                    else
                   {
                   i++;
                    if (i>n)
                        i=1;
                        continue;
                   }
                }
            t++;
            }
        i++;
        if (i>n)
            i=1;
        }

    for (i=1;i<=n;i++)
        if (a[i]==1)
            cout << "Ans is " << i << endl;
}
