/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/36 */
#include <iostream>
#include <string>
#include <algorithm>
#define N 210
using namespace std;

int table[N][N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string a,b,c;
    while(cin >> a >> b >> c)
    {
        /* DP */
        for(int i=1 ; i<=a.length() ; i++)
        {
            for(int j=1 ; j<=b.length() ; j++)
            {
                for(int k=1 ; k<=c.length() ; k++)
                {
                    if(a[i-1] == b[j-1] && b[j-1] == c[k-1] && a[i-1] == c[k-1])
                        table[i][j][k] = table[i-1][j-1][k-1] + 1;
                    else
                        table[i][j][k] = max(table[i-1][j][k],max(table[i][j-1][k], table[i][j][k-1]));
                }
            }
        }
        
        cout << table[a.length()][b.length()][c.length()] << "\n";
    }   
}