/* Problem: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=310 */
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long int B, P, M;
    while(cin >> B >> P >> M)
    {
        /* Into binary scale */
        int digit[50];
        int top = 0;
        while(P > 0)
        {
            digit[top++] = P % 2;
            P /= 2;
        }
        
        /* Mod M */
        long long int ans = 1;
        for(int i=top-1 ; i >= 0 ; i--)
        {
            ans = (ans*ans) % M;
            if(digit[i] == 1)
                ans = (ans * B) % M;
        }
        cout << ans << "\n";
    }
}