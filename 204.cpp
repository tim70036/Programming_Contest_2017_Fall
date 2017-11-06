#include <iostream>
#include <vector>
#define N 100005
using namespace std;

vector<int> adj[N];
int treeSize[N];
int centroid;
int n;
int smallest;

void DFS(int v, int p)
{
    treeSize[v] = 1;
    int maxSubTree = 0;
    
    
    for(auto i : adj[v])
    {
        if(i != p)
        {
            DFS(i,v);
            
            /* Record Tree Size and Biggest Subtree Size */
            treeSize[v] += treeSize[i];
            maxSubTree = (treeSize[i] > maxSubTree) ? treeSize[i] : maxSubTree;
        }
    }
    
    /* Another Possible Subtree */
    maxSubTree = (n-treeSize[v] > maxSubTree) ?  n-treeSize[v] : maxSubTree;
    
    /* Is node v the centroid ? */
    if(maxSubTree < smallest)
    {
        centroid = v;
        smallest = maxSubTree;
    }
    else if(maxSubTree == smallest && v < centroid)
    {
        centroid = v;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--)
    {
        cin>>n;
        
        /* Reset */
        for(int i=0 ; i<n ; i++)	adj[i].clear();
        smallest = 666666;
        
        /* Add edge */
        for(int i=0 ; i<n-1 ; i++)
        {
            int a,b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        /* DFS tree */
        DFS(0, -1);
        
        cout << centroid << "\n";
    }
}