/* Problem : https://pc2.tfcis.org/sky/index.php/problem/view/214/ */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> table;
vector<int> cook;
vector<int> eat;

struct Shit{
    bool operator() (const int a, const int b)
    {
        return eat[a] > eat[b];
    }
};

Shit shit;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    while(cin >> n && n != 0)
    {
        table.clear();
        cook.clear();
        eat.clear();
        
        int cookSum = 0;
        int eatMin = 9999999;
        for(int i=0 ; i<n ; i++)
        {
            int c,e;	cin >> c >> e;
            
            cookSum += c;
            eatMin = (e < eatMin) ? e : eatMin;
            
            cook.push_back(c);
            eat.push_back(e);
            table.push_back(i);
        }
        
        sort(table.begin(), table.end(), shit);
        
        int time = 0;
        int maxTime = -1;
        for(auto i : table)
        {
            time += cook[i];
            maxTime = (time+eat[i] > maxTime)? time+eat[i] : maxTime;
        }
        cout << max(cookSum+eatMin, maxTime) << "\n";
    }
    
}