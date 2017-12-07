/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/32 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string line;
    while(cin >> line)
    {
        vector<char> ans;
        
        /* Check */
        int i = 0, j = line.size()-1;
        while(i <= j)
        {
            /* Front */
            if(line[i] < line[j])
            {
                ans.push_back(line[i]);
                i++;
            }
            /* Back */
            else if(line[i] > line[j])
            {
                ans.push_back(line[j]);
                j--;
            }
            /* Same, then check inside */
            else
            {
                int a = i, b = j;
                bool done = false;
                while(a <= b)
                {
                    if(line[a] < line[b])
                    {
                        ans.push_back(line[i]);
                        i++;
                        done = true;
                        break;
                    }
                    else if(line[a] > line[b])
                    {
                        ans.push_back(line[j]);
                        j--;
                        done = true;
                        break;
                    }
                    a++;
                    b--;
                }
                if(!done)
                {
                    ans.push_back(line[i]);
                    i++;
                }
            }
        }
        
        for(auto c : ans)
            cout << c;
        cout << "\n";
    }
}