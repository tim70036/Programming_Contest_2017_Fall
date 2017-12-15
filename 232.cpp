/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/233 */
/* Topological sort using priority queue to produce lexicographically smallest order */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define N 100005
using namespace std;

vector<int> adj[N];
int in[N];
int order[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--)
    {
        int n,m; cin >> n >> m;
        
        /* Reset */
        for(int i=0 ; i<n ; i++)
            adj[i].clear(), in[i] = 0;
        
        int a, b;
        for(int i=0 ; i<m ; i++)
        {
            cin >> a >> b;
            
            /* Add edge */
            adj[a].push_back(b);
            /* In degree */
            in[b]++;
        }
        
        /* Sort */
        for(int i=0 ; i<n ; i++)
            sort(adj[i].begin(), adj[i].end());
        
        /* BFS init */
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i=0 ; i<n ; i++)
            if(in[i] <= 0)
                q.push(i);
        
        /* BFS */
        int index = 0;
        while(!q.empty())
        {
            int cur = q.top();  q.pop();
            
            for(auto v : adj[cur])
            {
                in[v]--;
                if(in[v] == 0)  q.push(v);
            }
            
            order[index++] = cur;
        }
        
        if(index != n)
            cout << "Jinkela\n";
        else
        {
            cout << order[0];
            for(int i=1 ; i<n ; i++)
                cout << " " << order[i];
            cout << "\n";
        }
    }
    
}