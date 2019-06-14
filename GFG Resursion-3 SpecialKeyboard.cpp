#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int findopt(int n)
{
    if (n<=7)
        return n;
    int ans=0,i;
    int maxm=0;
    for (i=n-3;i>1;i--)
    {
        ans=(n-i-2)*findopt(i);
        if (ans>maxm)
            maxm=ans;
    }
    return maxm;
}






int main ()
{
    int n;
    cin >> n;

    int res;
    res= findopt(n);

    cout << res << endl;

    return 0;
}
