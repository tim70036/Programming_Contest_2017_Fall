#include <iostream>
#include <queue>
#include <map>
using namespace std;

int cup[8];
int curState[8];
int nextState[8];
int t,tar;

queue<int> q;
map<int,int> dis;

int encode()
{
    int ret = 0;
    for(int i=0 ; i<t ; i++)
    {
        ret *= 51;
        ret += nextState[i];
    }
    return ret;
}

bool decode(int v)
{
    bool ret = false;
    for(int i=t-1 ; i>=0 ; i--)
    {
        curState[i] = v % 51;
        v /= 51;
        if(curState[i] == tar)	ret = true;
    }
    return ret;
}

int main()
{
    
    cin >> t;
    for(int i=0 ; i<t ; i++)
        cin >> cup[i];
    cin >> tar;
    
    /* Init BFS */
    q.push(0);
    dis[0] = 0;
    
    bool found = false;
    while(!q.empty())
    {
        int cur = q.front();	q.pop();
        
        /* decode and Check if Finish */
        if(decode(cur))
        {
            cout << dis[cur] << endl;
            found = true;
            break;
        }
        
        
        for(int i=0 ; i<t ; i++)	nextState[i] = curState[i];
        /* Fill or Pour One Cup */
        for(int i=0 ; i<t ; i++)
        {
            /* Fill */
            nextState[i] = cup[i];
            int h = encode();
            /* Repeat State ? */
            if(dis.find(h) == dis.end())
            {
                q.push(h);
                dis[h] = dis[cur] + 1;
            }
            
            /* Pour */
            nextState[i] = 0;
            h = encode();
            /* Repeat State ? */
            if(dis.find(h) == dis.end())
            {
                q.push(h);
                dis[h] = dis[cur] + 1;
            }
            
            /* Recover */
            nextState[i] = curState[i];
        }
        
        /* Fill Other Cup */
        for(int i=0 ; i<t ; i++)
        {
            if(curState[i] <= 0) continue;
            for(int j=0 ; j<t ; j++)
            {
                if(j == i)	continue;
                int amount = min(curState[i], cup[j] - curState[j]);
                nextState[i] -= amount, nextState[j] += amount;
                
                /* Repeat State ? */
                int h = encode();
                if(dis.find(h) == dis.end())
                {
                    q.push(h);
                    dis[h] = dis[cur] + 1;
                }
                
                /* Recover */
                nextState[i] += amount, nextState[j] -= amount;
            }
        }
    }
    
    if(!found)	cout << -1 << endl;
}