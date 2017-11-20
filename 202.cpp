/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/202 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<char, int> table1;
map<char, int> table2;

vector<int> adj1[10];
vector<int> adj2[10];

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n, m;	cin >> n >> m;
        
        /* Reset */
        int index1 = 0, index2 = 0;
        for(int i=0 ; i<n ; i++) adj1[i].clear(), adj2[i].clear();
        table1.clear();
        table2.clear();
        
        /* Map1 */
        //cout << "Map1 :\n";
        for(int i=0 ; i<m ; i++)
        {
            /* Input */
            char a,b; cin >> a >> b;
            
            /* Table */
            if(table1.find(a) == table1.end())
                table1[a] = index1++;
            if(table1.find(b) == table1.end())
                table1[b] = index1++;
            
            /* Add edge */
            int v1 = table1[a];
            int v2 = table1[b];
            //cout << "adding :" << v1 << " <-> " << v2 << endl;
            adj1[v1].push_back(v2);
            adj1[v2].push_back(v1);
            
        }
        /* Map2 */
        //cout << "Map2 :\n";
        for(int i=0 ; i<m ; i++)
        {
            /* Input */
            char a,b; cin >> a >> b;
            
            /* Table */
            if(table2.find(a) == table2.end())
                table2[a] = index2++;
            if(table2.find(b) == table2.end())
                table2[b] = index2++;
            
            /* Add edge */
            int v1 = table2[a];
            int v2 = table2[b];
            //cout << "adding :" << v1 << " <-> " << v2 << endl;
            adj2[v1].push_back(v2);
            adj2[v2].push_back(v1);
            
        }
        
        if(index1 != index2)
        {
            //cout << index1 << " != " << index2 << endl;
            cout << "no\n";
            continue;
        }
        
        /* Permutation */
        vector<int> map;
        for(int i=0 ; i<index1 ; i++)	map.push_back(i);
        
        /* Check */
        bool gg = true;
        do
        {
//            for(int i=0 ; i<index1; i++) cout << map[i] << " ";
//            cout << "\n";
            
            bool valid = true;
            for(int i=0 ; i<index1 ; i++)
            {
                int index = map[i];
                if(adj1[i].size() != adj2[index].size())
                {
                    valid = false;
                    break;
                }
                
                for(auto e: adj1[i])
                {
                    //cout << "For Map1: " << i << " -> " << e << endl;
                    if(find(adj2[index].begin(), adj2[index].end(), map[e]) == adj2[index].end())
                    {
                        valid = false;
                        break;
                    }
                }
                if(!valid) break;
            }
            
            if(valid)
            {
                gg = false;
                cout << "yes\n";
                break;
            }
        } while(next_permutation(map.begin(), map.end()));
        
        if(gg) cout << "no\n";
    }
}