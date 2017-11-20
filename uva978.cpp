/* Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=919 */
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    while(n--)
    {
        /* Input */
        int b, sg, sb; cin >> b >> sg >> sb;
        priority_queue<int> green;
        priority_queue<int> blue;
        for(int i=0 ; i<sg ; i++)
        {
            int v; cin >> v;
            green.push(v);
        }
        for(int i=0 ; i<sb ; i++)
        {
            int v; cin >> v;
            blue.push(v);
        }
        
        /* Simulate */
        while(!green.empty() && !blue.empty())
        {
            int times = min(green.size(), blue.size());
            times = min(b, times);
            
            /* For each battle field */
            vector<int> greenRemain;
            vector<int> blueRemain;
            while(times--)
            {
                /* Choose Soldier */
                int greenS = green.top();	green.pop();
                int blueS = blue.top();		blue.pop();
                
                /* Battle */
                if(greenS > blueS)
                {
                    greenS -= blueS;
                    greenRemain.push_back(greenS);
                }
                else if(greenS < blueS)
                {
                    blueS -= greenS;
                    blueRemain.push_back(blueS);
                }
            }
            
            
            /* Put back */
            for(auto i : greenRemain)  green.push(i);
            for(auto i : blueRemain)   blue.push(i);
        }
        
        /* Output */
        if(blue.empty() && green.empty())
            cout << "green and blue died\n";
        else if(!green.empty())
        {
            cout << "green wins\n";
            for( ; !green.empty() ; green.pop())	cout << green.top() << "\n";
        }
        else
        {
            cout << "blue wins\n";
            for( ; !blue.empty() ; blue.pop())	cout << blue.top() << "\n";
        }
        
        if(n > 0) cout << "\n";
    }
}