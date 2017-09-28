/* Bug : didn't use long long int */

#include <iostream>
#include <stack>

using namespace std;
stack<long long int> h;
stack<long long int> pos;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long int n;
    while(cin >> n)
    {
        if(n <= 0)
        {
            cout << 0 << "\n";
            continue;
        }
        /* First */
        long long int max = 0;
        long long int in;			cin >> in;
        h.push(in);
        pos.push(0);
        
        for(int i=1 ; i<n ; i++)
        {
            cin >> in;
            
            if(in > h.top())
            {
                h.push(in);
                pos.push(i);
            }
            else if(in < h.top())
            {
                long long int lastPos = 0;
                while(!h.empty() && in < h.top())
                {
                    lastPos = pos.top();
                    long long int area = h.top() * (i - pos.top());
                    //cout << h.top() << " * " << i - pos.top() << " = " << area << "\n";
                    max = (area > max) ? area : max;
                    
                    h.pop();
                    pos.pop();
                }
                
                if(h.empty() || in >  h.top())
                {
                    h.push(in);
                    pos.push(lastPos);
                }
            }
        }
        
        while(!h.empty())
        {
            long long int area = h.top() * (n - pos.top());
            //cout << h.top() << " * " << n - pos.top() << " = " << area << "\n";
            max = (area > max) ? area : max;
            
            
            h.pop();
            pos.pop();
        }
        
        cout << max << "\n";
    }
}