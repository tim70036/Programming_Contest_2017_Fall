/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/17 */
/* About inversion check :  https://pc2.tfcis.org/sky/index.php/chal/result/31712 
http://skycab.pixnet.net/blog/post/25458480-2%5En-1-puzzle-problem*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

int dr[4] = {1, -1, 0,  0};
int dc[4] = {0,  0, 1, -1};

int InPlaceReverseSum(int arr[3][3])
{
    int check[10];
    int index = 0;
    
    for(int i=0 ; i<3 ; i++)
        for(int j=0 ; j<3 ; j++)
            if(arr[i][j] > 0)
                check[index++] = arr[i][j];
    
    int cnt = 0;
    for(int i=0 ; i<index ; i++)
        for(int j=0 ; j<i ; j++)
            if(check[j] > check[i]) cnt++;
    
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int mapping[10];
    int tar[3][3];
    int tarState = 0;
    
    int t;  cin >> t;
    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            cin >> tar[i][j];
            tarState = tarState*10 + tar[i][j];
            mapping[tar[i][j]] = (i*3+j+1) % 9;
        }
    }
    
    int tarInPlaceSum = InPlaceReverseSum(tar);
    
    while(t--)
    {
        int in[3][3];
        int curState = 0;
        for(int i=0 ; i<3 ; i++)
        {
            for(int j=0 ; j<3 ; j++)
            {
                cin >> in[i][j];
                curState = curState*10 + in[i][j];
            }
        }
        
        /* Exist Solution? */
        int curInPlaceSum = InPlaceReverseSum(in);
        if(curInPlaceSum%2 != tarInPlaceSum%2)
        {
            cout << "MS\n";
            continue;
        }
        
        /* BFS Init */
        int cur[3][3];
        queue<int> q;
        map<int, int> d;
        
        q.push(curState);
        d[curState] = 0;
        
        while(!q.empty())
        {
            curState = q.front(); q.pop();
            
            /* Finsih ? */
            if(curState == tarState)
            {
                cout << d[curState] << "\n";
                break;
            }
            
            /* Unhash to Map and Find 0 */
            int zeroR,zeroC;
            int tmp = curState;
            for(int i=2 ; i>=0 ; i--)
            {
                for(int j=2 ; j>=0 ; j--)
                {
                    cur[i][j] = tmp%10, tmp/=10;
                    if(cur[i][j] == 0)  zeroR = i, zeroC = j;
                }
            }
            
            /* Expand */
            for(int k=0 ; k<4 ; k++)
            {
                int nextR = zeroR+dr[k] ,nextC = zeroC+dc[k];
                
                /* Valid move ? */
                if(nextR < 0 || nextR > 2 || nextC < 0 || nextC > 2)    continue;
                
                /* Move it */
                swap(cur[nextR][nextC], cur[zeroR][zeroC]);
                
                /* Hash */
                int nextState = 0;
                for(int i=0 ; i<3 ; i++)
                    for(int j=0 ; j<3 ; j++)
                        nextState = nextState*10 + cur[i][j];
                
                /* Not Repeat State Then Push to Queue  */
                if(d.find(nextState) == d.end())
                {
                    q.push(nextState);
                    d[nextState] = d[curState] + 1;
                }
                
                /* Restore */
                swap(cur[nextR][nextC], cur[zeroR][zeroC]);
                
            }
        }
    }
}