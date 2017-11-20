/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/19 */
/* TLE : input need break early */
#include <iostream>
#include <cstdio>
using namespace std;

int qr[2000000];
int qc[2000000];
int rear, front;

char map[1500][1500];
int pr[1500][1500];
int pc[1500][1500];
bool visit[1500][1500];
int dir[4][2] = { {-1,0}, {1, 0}, {0, 1}, {0 , -1}};
int ansR=0, ansC=0;
int n,m;

int str[2000000];
int stc[2000000];
int top;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    /* Input map */
    int sr,sc;
    bool found = false;
    scanf("%d %d",&n,&m);
    for(int i=0 ; i<n ; i++)
    {
        scanf("%s", map[i]);
        for(int j =0 ; !found && j <m ; j++)
            if(map[i][j] == '&')
                sr = i, sc = j, found = true;
    }
    
    /* BFS */
    
    /* Init */
    visit[sr][sc] = true;
    pr[sr][sc] = pc[sr][sc] = -1;
    qr[front] = sr; qc[front] = sc;
    front = (front+1) % 2000000;
    
    while(rear != front)
    {
        /* pop 1 */
        int r = qr[rear];
        int c = qc[rear];
        rear = (rear+1) % 2000000;
        
        if(map[r][c] == '@')
        {
            ansR = r;
            ansC = c;
            break;
        }
        
        /* 4 dir */
        for(int i=0 ; i<4 ; i++)
        {
            int nextR = r + dir[i][0];
            int nextC = c + dir[i][1];
            
            if(nextR >= n || nextR < 0 || nextC >= m || nextC < 0)
                continue;
            if(visit[nextR][nextC] == true)
                continue;
            if(map[nextR][nextC] == '#')
                continue;
            
            visit[nextR][nextC] = true;
            pr[nextR][nextC] = r, pc[nextR][nextC] = c;
            qr[front] = nextR, qc[front] = nextC;
            front = (front+1) % 2000000;
        }
    }
    
    /* Output */
    while(ansR != -1)
    {
        int curR = ansR, curC = ansC;
        str[top] = curR, stc[top] = curC, top++;
        ansR = pr[curR][curC];
        ansC = pc[curR][curC];
    }
    
    printf("%d\n",top);
    while(top > 0)
    {
        top--;
        printf("(%d,%d)\n",str[top],stc[top]);
    }
}