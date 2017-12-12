/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/230 */
#include <iostream>
#include <string>
#include <algorithm>
#define N 20005
#define M 20005
using namespace std;

bool table[2][M];
int value[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--)
    {
        int n,tar; cin >> n >> tar;
        int index = 1;
        for(int i=0 ; i<n ; i++)
        {
            int c, k; cin >> c >> k;
            /* View each coin as a item */
            while(k--)	value[index++] = c;
        }
        
        /* Init DP */
        table[0][0] = true;
        for(int i=1 ; i<=tar ; i++)	table[0][i] = false;
        
        /* DP */
        for(int i=1 ; i<index ; i++)
        {
        	
            for(int j=0 ; j<=tar ; j++)
            {
                if(j < value[i])
                    table[i%2][j] = table[(i-1)%2][j];
                else
                    table[i%2][j] = table[(i-1)%2][j] || table[(i-1)%2][j-value[i]];
            }
        }
        
        if(table[(index-1)%2][tar])	cout << "Yes\n";
        else cout << "No\n";
    }
}