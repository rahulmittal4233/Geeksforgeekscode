#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int lcs (string a, string b, int m, int n);
int main ()
{
while (1)
{
string a,b;
cin >> a;
cin >> b;
int m,n,res;
m = a.size();
n = b.size();

res = lcs(a,b,m,n);

cout << "Length of longest common substing is " << res << endl;
//cout << n << endl;

}
return 0;

}



int lcs (string a, string b, int m, int n)
{
int len[m+1][n+1];
int resu=0;
for (int i=0;i<=m;i++)
    for (int j=0;j<=n;j++)
    len[i][j]=0;

for (int i=1;i<=m;i++)
{
    for (int j=1;j<=n;j++)
    {
        if (a[i-1]==b[j-1])
        {
        len[i][j]=len[i-1][j-1]+1;
        resu=max(resu,len[i][j]);
        }

        else
            len[i][j]=0;
    }
}
return resu;

}

// Strings can be passed in functions simply by string name,
// Take care of corner cases and string size should be handled carefully.











