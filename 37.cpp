#include <iostream>
#include <algorithm>
using namespace std;

int adj[20][20];
long long table[20][1 << 20];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        /* vertex starts from 0 */
        for(int i=0 ; i<n-1 ; i++)
        {
            for(int j=i+1 ; j<=n-1 ; j++)
            {
                cin >> adj[i][j];
                adj[j][i] = adj[i][j];
            }
        }
        
        int maxSet = (1 << n) - 1; /* 1111..11111 (1*n) */
        for(int i=0 ; i<n ; i++)
            for(int j=0 ; j<= maxSet ; j++)
                table[i][j] = 199999999999;
        
        /* Start point is 0, with set{2^0} */
        table[0][1] = 0;
        
        /* Set must increment by 2 and start from 1, to ensure that set always contain 2^0 */
        /* For each vertex i , check if j to i is better, with each possible set */
        for(int set=1 ; set <= maxSet ; set+=2)
            for(int i=1 ; i<n ; i++)
                if((set & (1<<i)) != 0) /* Check if i is in set */
                    for(int j=0 ; j<n ; j++)
                        if((set & (1<<j)) != 0) /* Check if j is in set */
                        /* Check whether j to i is better */
                            table[i][set] = min(table[i][set], table[j][set^(1<<i)] +  adj[j][i]);
        
        /* Find min length(go to vertex 0) among 1~n-1 */
        long long minLen = 199999999999;
        for(int i=1 ; i<n ; i++)
            minLen = min(minLen, table[i][maxSet] + adj[i][0]);
        
        /* n might be 1 */
        if(minLen == 199999999999) minLen = 0;
        cout << minLen << "\n";
    }
}