#include <iostream>
#include <queue>
#include <stack>
#include <utility>
using namespace std;

char map[1500][1500];
int par[1500][1500][2];
bool visit[1500][1500];
int dir[4][2] = { {-1,0}, {1, 0}, {0, 1}, {0 , -1}};
int ansR=0, ansC=0;
int n,m;

void BFS()
{
    /* BFS init */
    queue<pair<int,int>> q;

    par[sr][sc][0] = par[sr][sc][1] = -1;
    visit[sr][sc] = true;
    q.push(make_pair(sr,sc));
    
    /* BFS */
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        
        /* Start walk, 4 direction */
        for(int i=0 ; i<4 ; i++)
        {
            int r = cur.first + dir[i][0];
            int c = cur.second + dir[i][1];
            
            /* Invalid? */
            if(r >= n || r < 0 || c >=m || c < 0 )
                continue;
            if(visit[r][c] == true)
                continue;
            if(map[r][c] == '#')
                continue;
            
            /* End ? */
            if(map[r][c] == '@')
            {
                ansR = r;
                ansC = c;
                return;
            }

            
            /* If valid, into queue */
            par[r][c][0] = cur.first;
            par[r][c][1] = cur.second;
            visit[r][c] = true;
            q.push(make_pair(r,c));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    /* Input map */
    int sr,sc;
    cin >> n >> m;
    for(int i=0 ; i<n ; i++)
    {
        for(int j =0 ; j <m ; j++)
        {
            cin >> map[i][j];
            if(map[i][j] == '&')
                sr = i, sc = j;
        }
    }
    
    BFS();
    
    stack<pair<int,int>> st;
    while(ansR != -1)
    {
        int curR = ansR, curC = ansC;
        st.push(make_pair(curR, curC));
        ansR = par[curR][curC][0];
        ansC = par[curR][curC][1];
    }
    
    cout << st.size() << "\n";
    while(!st.empty())
    {
        int r = st.top().first;
        int c = st.top().second;
        cout << "(" << r << "," << c << ")\n";
        st.pop();
    }
}