/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/215 */
#include <iostream>
#define N 100005

using namespace std;

int t,n;
int table[N][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    /* Init */
    table[0][0] = 1;
    table[0][1] = table[1][0] = 0;
    table[1][1] = 2;
    
    /* DP, bottom-up */
    for(int i=2 ; i<N ; i++)
    {
        /* Fill all */
        table[i][0] = (table[i-2][0] + table[i-1][1]) % 1000007;
        /* Fill all and 1 extra square */
        table[i][1] = (table[i-1][0] * 2 + table[i-2][1]) % 1000007;
    }
    
    /* Input */
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << table[n][0] << "\n";
    }
}