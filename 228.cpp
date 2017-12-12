/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/228 */
#include <iostream>
#include <string>
#include <algorithm>
#define N 105
#define M 10005
using namespace std;

int table[2][M];
int value[N];
int weight[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--)
    {
        /* Init */
        table[0][0] = 0;
        for(int i=1 ; i<=M ; i++) table[0][i] = 999999999;
        
        int n,m; cin >> n >> m;
        int valSum = 0;
        for(int i=1 ; i<=n ; i++)
        {
            cin >> weight[i] >> value[i];
            valSum += value[i];
        }

        /* DP */
        int maxValue = 0;
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=0 ; j <= valSum ; j++)
            {
                /* Can't choose item i */
                if(j<value[i])
                    table[i%2][j] = table[(i-1)%2][j];
                /* Can choose item i */
                else
                    table[i%2][j] = min(table[(i-1)%2][j], table[(i-1)%2][j-value[i]]+weight[i]);
                
                if(table[i%2][j] <= m)
                    maxValue = max(maxValue, j);
            }
        }
        
        cout << maxValue << "\n";
    }
    
}