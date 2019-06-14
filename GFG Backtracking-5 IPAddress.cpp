#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <string>
using namespace std;

/*An IP address is a set of numbers that identify your computer on a network.
IPV4, the traditional numbering scheme, uses four integers ranging from zero
 to 255 and
set apart by periods. For example, "204.120.0.15" is a valid IPV4 address.
*/
vector <string> v;
void checkip(string n)
{

for (int i=1;i<=3;i++)
        for (int j=1;j<=3;j++)
            for (int k=1;k<=3;k++)
                for (int m=1;m<=3;m++)
                {
                    if ((i+j+k+m)==n.size())
                    {
                       int  a =stoi(n.substr(0,i,n));
                       int  b =stoi(n.substr(i,i+j,n));
                       int  c =stoi(n.substr(i+j,i+j+k,n));
                       int  d =stoi(n.substr(i+j+k,i+j+k+m,n));
                    if (a<=255 && b<=255 && c<=255 && d<=255)
                    {
                        string str= a + "." + b + "."+ c + "." +d;
                        v.push_back(str);
                    }
                    }

                }
}

int main()
{
    string n;
    cin >> n;

    checkip(n);

for (int t=0;i<v.size();i++)
    cout << v[0] << "  ";

}
