#include <iostream>
#include <vector>
#define N 100005
using namespace std;

class Node{
public:
    int gender;
    vector<int> neighbor;
};

bool strange;
bool visit[N];
Node node[N];

void DFS(int v, int sex)
{
    visit[v] = true;
    node[v].gender = sex;
    for(auto i : node[v].neighbor)
    {
        
        if(visit[i] == false)
        {
            DFS(i, sex*-1);
        }
        /* Same gender ? */
        else if(node[i].gender == sex)
        {
            strange = true;
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    while(cin >> n && n != 0)
    {
        /* Reset */
        for(int i=0 ; i<n ; i++) visit[i] = false, node[i].gender = 0, node[i].neighbor.clear();
        strange = false;
        
        cin >> m;
        while(m--)
        {
            int a,b; cin >> a >> b;
            
            /* Add edge */
            node[a].neighbor.push_back(b);
            node[b].neighbor.push_back(a);
        }
        
        /* DFS */
        for(int i=0 ; i<n ; i++)
            if(visit[i] == false)
                DFS(i, 1);
        
        if(strange) cout << "RAINBOW.\n";
        else cout << "NORMAL.\n";
    }
    
}