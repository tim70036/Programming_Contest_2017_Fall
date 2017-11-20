/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/121 */
#include <iostream>
#include <string>
using namespace std;

int parent[500009];
bool used[500009];

int FindRoot(int node)
{
    /* Find it */
    if(parent[node] == node)	return node;
    
    /* Keep going up */
    return parent[node] = FindRoot(parent[node]);
}

void Union(int a, int b)
{
    parent[FindRoot(a)] = FindRoot(b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    /* Initialize */
    for(int i=1; i<=n ; i++)	parent[i] = 0, used[i] = false;
    
    string act, dum, rel;
    int a, b;
    while(cin >> act >> dum >> rel >> a >> b)
    {
        if(act == "are")
        {
            /* Assigned ? */
            if(!used[a] || !used[b])
            {
                cout << "nope\n";
                continue;
            }
            
            bool isFriend = (FindRoot(a) == FindRoot(b));
            if( (rel == "friends" && isFriend) || (rel == "enemies" && !isFriend))
                cout << "yeap\n";
            else
                cout << "nope\n";
        }
        else if(act == "you")
        {
            if(rel == "friends")
            {
                /* Check */
                if(used[a] && used[b] && (FindRoot(a) != FindRoot(b)) )
                {
                    cout << "angry\n";
                    continue;
                }
                
                /* Union */
                used[a] = used[b] = true;
                Union(a,b);
            }
            else /* enemy */
            {
                /* Check */
                if(used[a] && used[b] && FindRoot(a) == FindRoot(b))
                {
                    cout << "angry\n";
                    continue;
                }
                used[a] = used[b] = true;
                parent
            }
        }
    }
}