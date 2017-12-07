/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/212 */ 
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, in;
    while(cin >> n && n != 0)
    {
        priority_queue<long long, vector<long long> , greater<long long>> q;
        for(int i=0 ; i<n ; i++)
        {
            cin >> in;
            q.push(in);
        }
        
        /* Greedy */
        long long ans = 0;
        while(q.size() > 1)
        {
            long long a = q.top(); q.pop();
            long long b = q.top(); q.pop();
            
            ans += a+b;
            q.push(a+b);
        }
        cout << ans << "\n";
    }
}