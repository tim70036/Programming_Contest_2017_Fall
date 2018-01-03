/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/108 */
/* Shortest path, inverse graph */
#include <iostream>
#include <vector>
#include <queue>
#define N 1000005
#define INF 0x3f3f3f
using namespace std;

int n,m;
vector<int> adj[N];
vector<int> adjInv[N];
vector<int> w[N];
vector<int> wInv[N];

long long  SPFA()
{
    /* SPFA, find shortest path that starts from vertex 1 */
    queue<int> q;
    int  dis[n+2];
    int  par[n+2];
    bool inQ[n+2];
    for(int i=1 ; i<=n ; i++) dis[i] = INF, inQ[i] = false;
    
    dis[1] = 0;
    par[1] = 1;
    inQ[1] = true;
    q.push(1);
    
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        inQ[cur] = false;
        
        if(inQ[par[cur]]) continue;
        
        for(int i=0 ; i<adj[cur].size() ; i++)
        {
            int next = adj[cur][i];
            if(dis[cur]+w[cur][i] < dis[next])
            {
                dis[next] = dis[cur]+w[cur][i];
                par[next] = cur;
                
                if(!inQ[next])
                {
                    inQ[next] = true;
                    q.push(next);
                }
            }
        }
    }
    
    /* Add to answer and check */
    bool valid = true;
    long long  sum = 0;
    for(int i=2 ; i<=n ; i++)
    {
        if(dis[i] >= INF)
        {
            valid = false;
            break;
        }
        sum += dis[i];
    }
    
    /* Some vertex can't be reached from vertex 1 */
    if(!valid)
        return -1;
    
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    while(m--)
    {
        int a,b,d; cin >> a >> b >> d;
        adj[a].push_back(b); /* Normal */
        w[a].push_back(d);
        adjInv[b].push_back(a);  /* Inverse edge */
        wInv[b].push_back(d);
    }
    
    /* SPFA from vertex 1 and check if there are vertex that can't be reached */
    long long  sum1 = SPFA();
    if(sum1 <= -1)
    {
        cout << "0\n";
        return 0;
    }
    
    /* Reverse all edge, so that we can find shortest from all vertex back to vertex 1 */
    for(int i=1 ; i<=n ; i++)
        adj[i] = adjInv[i], w[i] = wInv[i];
    
    /* SPFA from vertex 1 and check if there are vertex that can't be reached */
    long long sum2 = SPFA();
    if(sum2 <= -1)
    {
        cout << "0\n";
        return 0;
    }
    cout << sum1+sum2 << "\n";
    
}