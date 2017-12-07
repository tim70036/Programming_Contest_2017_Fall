/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/216 */
#include <iostream>
#define N 100005

using namespace std;

int t,n;
/* RGB -> 0,1,2 */
int r[N][3]; /* First is red */
int b[N][3]; /* First is blue */
int g[N][3]; /* First is green */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    /* Init */
    b[1][0] = b[1][1] = g[1][0] = g[1][2] = r[1][1] = r[1][2] = 0;
    b[1][2] = g[1][1] = r[1][0] = 1;
    
    /* DP */
    for(int i=2 ; i < N ; i++)
    {
        /* First is red */
        r[i][0] = (r[i-1][0] + r[i-1][1] + r[i-1][2]) % 1000007;
        r[i][1] = (r[i-1][0] + r[i-1][1]) % 1000007;
        r[i][2] = (r[i-1][0] + r[i-1][2]) % 1000007;
        
        /* First is blue */
        b[i][0] = (b[i-1][0] + b[i-1][1] + b[i-1][2]) % 1000007;
        b[i][1] = (b[i-1][0] + b[i-1][1]) % 1000007;
        b[i][2] = (b[i-1][0] + b[i-1][2]) % 1000007;
        
        /* First is green */
        g[i][0] = (g[i-1][0] + g[i-1][1] + g[i-1][2]) % 1000007;
        g[i][1] = (g[i-1][0] + g[i-1][1]) % 1000007;
        g[i][2] = (g[i-1][0] + g[i-1][2]) % 1000007;
    }
    
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << (b[n][0]+b[n][2] + g[n][0]+g[n][1] + r[n][0]+r[n][1]+r[n][2]) % 1000007 << "\n";
    }
}