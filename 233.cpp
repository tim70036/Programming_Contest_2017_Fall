/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/233 */
/* Euler Path */
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#define N 505
using namespace std;

vector<int> nodes;
int adj[N][N];
int degree[N];

stack<int> path;

void DFS(int v)
{
    /* Chech if there are edges that haven't been used */
    for(auto next : nodes)
    {
        if(adj[v][next] >= 1)/* Exist at least one edge */
        {
            adj[v][next]--, adj[next][v]--; /* Use this edge */
            DFS(next);
        }
    }
    path.push(v);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int m; cin >> m;
    int a, b;
    for(int i=0 ; i<m ; i++)
    {
        cin >> a >> b;
        if(find(nodes.begin(), nodes.end(),a) == nodes.end())
            nodes.push_back(a);
        if(find(nodes.begin(), nodes.end(),b) == nodes.end())
            nodes.push_back(b);
        
        /* Add edge */
        adj[a][b]++;
        adj[b][a]++;
        degree[a]++;
        degree[b]++;
    }
    
    sort(nodes.begin(), nodes.end());
    
    /* Find start point, the problem state that there must be >= 1 path */
    bool odd = false;
    int minOdd = 999;
    int minEven = 999;
    for(auto i : nodes)
    {
        if(degree[i] % 2 != 0)
        {
            minOdd = (i < minOdd) ? i : minOdd;
            odd = true;
        }
        else
            minEven = (i<minEven) ? i : minEven;
    }
    
    /* DFS, if odd, try 2 start point */
    if(odd)
        DFS(minOdd);
    else
        DFS(minEven);
    
    while(!path.empty())
    {
        cout << path.top() << "\n";
        path.pop();
    }
}