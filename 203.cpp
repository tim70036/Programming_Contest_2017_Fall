#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#define N 2005
using namespace std;

vector<int> adj[N];
bool visit[N];
double speed[N];

bool valid;
int start, startSpeed;
int n;
int x[N];
int y[N];
double r[N];

void DFS(int v, int p)
{
    visit[v] = true;
    
    for(auto i : adj[v])
    {
        /* Calculate Speed for Neighbor */
        double sp = (speed[v]/r[i]*r[v]) * -1;
        //cout << "speed for " << i << " is " << sp << "\n";
        
        if(visit[i] == true && i != p && speed[i] != sp)
        {
            valid = false;
            return;
        }
        else if(visit[i] == false)
        {
            
            speed[i] = sp;
            DFS(i, v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--)
    {
        /* Input */
        cin >> n;
        for(int i=1 ; i<=n ; i++)
            cin >> x[i] >> y[i] >> r[i];
        cin >> start >> startSpeed;
        
        /* Reset */
        for(int i=1 ; i<=n ; i++) adj[i].clear(), speed[i] = 0, visit[i] = false;
        valid = true;
        
        /* Edge ? */
        for(int i=1 ; i<=n ; i++)
        {
            for(int j=i+1 ; j <= n ; j++)
            {
                if(pow(r[j]+r[i],2) ==  pow(x[j] - x[i], 2) + pow(y[j] - y[i],2))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                    //cout << i << " to " << j << endl;
                }
            }
        }
        
        /* DFS */
        speed[start] = startSpeed;
        DFS(start, -1);
        
        if(!valid)
        {
            cout << "X\n";
            continue;
        }
        double sum=0;
        for(int i=1 ; i<=n ; i++)
            sum += speed[i];
        
        cout << fixed << setprecision(2);
        cout << sum << "\n";
    }
}