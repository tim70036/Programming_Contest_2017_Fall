/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/227 */
#include <iostream>
#include <string>
#include <algorithm>
#define N 105
using namespace std;

int table[N][N];
int num[N];
int MemorizeDP(int start, int end)
{
    /* Done it before */
    if(table[start][end] != -1)
        return table[start][end];
    
    /* Not yet */
    int sum = 0;
    for(int i=start ; i<=end ; i++) sum += num[i];
    
    int minCost = 999999999;
    for(int i = start ; i< end ; i++)
    {
        int cost = MemorizeDP(start, i) + MemorizeDP(i+1, end) + sum;
        minCost = min(cost, minCost);
    }
    
    return table[start][end] = minCost;
}

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        /* Reset */
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<n ; j++)
                table[i][j] = -1;
        
        /* DP */
        for(int i=0 ; i<n ; i++)
        {
            cin >> num[i];
            table[i][i] = 0; /* Cost of single num is 0 */
        }
        cout <<  MemorizeDP(0,n-1) << "\n";
    }
}