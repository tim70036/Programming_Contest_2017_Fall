/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/200 */
#include <iostream>
#include <vector>
#define N 3005
using namespace std;

vector<int> adj[N];
bool visit[N];

void DFS(int v)
{
	visit[v] = true;
	for(auto i: adj[v])
		if(visit[i] == false)
			DFS(i);
}

int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m,t; cin >> t;
    while(t--)
    {
    	cin >> n >> m;

    	/* Reset */
    	for(int i=0 ; i<n ; i++) adj[i].clear(), visit[i] = false;

    	/* Add edge */
    	while(m--)
    	{
    		int a, b; cin >> a >> b;
    		adj[a].push_back(b);
    		adj[b].push_back(a);
    	}

    	/* DFS */
    	int cnt = 0;
    	for(int i=0 ; i<n  ; i++)
    	{
    		if(visit[i] == false)
    		{
    			cnt++;
    			DFS(i);
    		}
    	}
    }
}