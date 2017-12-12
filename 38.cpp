/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/38 */
#include <iostream>
#include <string>
#include <algorithm>
#define N 1005
using namespace std;

int table[N][N];

int main()
{
    string in;
    while(cin >> in)
    {
        /* Reverse the string */
        string rev = in;
        reverse(rev.begin(), rev.end());
        
        /* LCS of in and rev */
        /* Init dummy */
        for(int i=0 ; i<=in.length() ; i++) table[i][0] = table[0][i] = 0;
        /* DP */
        for(int i=1 ; i<=in.length() ; i++)
        {
            for(int j=1 ; j<=rev.length() ; j++)
            {
                if(in[i-1] == rev[j-1])
                    table[i][j] = table[i-1][j-1] + 1;
                else
                    table[i][j] = max(table[i-1][j], table[i][j-1]);
            }
        }
        
        /* Require num of char to make it palindrome -> length of in -  LCS of rev,in */
        int LCS = table[in.length()][rev.length()];
        cout << in.length() - LCS << "\n";
    }
}