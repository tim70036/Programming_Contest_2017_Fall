/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/230 */
/* http://blog.csdn.net/yoer77/article/details/69236205 */
#include <iostream>
#include <string>
#include <algorithm>
#define N 20005
#define M 20005
using namespace std;

int table[M];/* the amount of coin left for target moeny */
int value[N];
int amount[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--)
    {
        int n,tar; cin >> n >> tar;
        for(int i=1 ; i<=n ; i++)
            cin >> value[i] >> amount[i];
        
        /* Init DP */
        for(int i=0 ; i<=tar ; i++)	table[i] = -1;
        
        /* First row */
        for(int i=0 ; i<=amount[1] && i*value[1] <= tar ; i++)
            table[i*value[1]] = amount[1] - i;
        
        /* DP */
        for(int i=2 ; i<=n ; i++)
        {
            for(int j=0 ; j<=tar ; j++)
            {
                if(table[j] >= 0)
                    table[j] = amount[i]; /* Previous row has solution */
                else if(j<value[i] || table[j-value[i]] <= 0)
                    table[j] = -1; /* No solution */
                else
                    table[j] = table[j-value[i]] - 1;
            }
        }
        
        if(table[tar] >= 0)	cout << "Yes\n";
        else cout << "No\n";
    }
}