/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/231 */
/* https://psychicalcoder.github.io/2017/07/18/tioj1142/ */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define N 100005
using namespace std;

int weight[N];
vector<int> adj[N];
int in[N];

int dis[N];
vector<int> par[N];
bool visited[N];
int cnt;

void DFS(int v)
{
    cnt++;
    visited[v] = true;
    for(auto parent : par[v])
        if(visited[parent] == false)
            DFS(parent);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m; cin >> n >> m;
    for(int i=1 ; i<=n ; i++)
        cin >> weight[i];
    
    /* Add edge */
    int a, b;
    for(int i=0 ; i<m ; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        in[b]++;
    }
    
    /* SPFA, but longest */
    queue<int> q;
    for(int i=1 ; i<=n ; i++) dis[i] = -1;
    
    /* Push all points with 0 degree into queue */
    for(int i=1 ; i<=n ; i++)
    {
        if(in[i] == 0)
        {
            q.push(i);
            dis[i] = weight[i];
        }
    }
    
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        
        for(auto next : adj[cur])
        {
            /* Relax */
            int d = dis[cur] + weight[next];
            if(d > dis[next])
            {
                par[next].clear();
                dis[next] = d;
            }
            
            if(d == dis[next])
                par[next].push_back(cur);
            
            in[next]--;
            if(in[next] == 0) q.push(next);
        }
    }
    
    /* Find all max point */
    vector<int> maxNode;
    int maxDis = -1;
    for(int i=1 ; i<=n ; i++)
    {
        if(dis[i] > maxDis)
        {
            maxDis = dis[i];
            maxNode.clear();
        }
        
        if(dis[i] == maxDis)
            maxNode.push_back(i);
    }
    
    /* Backtrack and Count */
    cnt = 0;
    for(auto start : maxNode)
        if(visited[start] == false)
            DFS(start);
    
    cout << cnt << "\n";
}