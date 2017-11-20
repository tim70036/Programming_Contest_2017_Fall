/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/125 */
#include <iostream>
#include <string>

using namespace std;

int n;
int cnt[20];
char out[20];
string in;

void perm(int depth, int nowChar)
{
    if(depth < n)
    {
        for(int i = nowChar ; i < 11 ; i++)
        {
            if(cnt[i] >= 1)
            {
                cnt[i]--;
                out[depth] = 'A' + i;
                perm(depth + 1, i);
                cnt[i]++;
            }
        }
    }
    else
    {
        /* Output */
        cout << out << endl;
    }
}

int main()
{
    
    bool first = true;
    while(cin >> in >> n)
    {
        if(!first) cout << endl;
        else first = false;
        
        /* Reset */
        for(int i=0 ; i < 20 ; i++)
            cnt[i] = out[i] = 0;
        
        /* Counting */
        for(auto i : in)
            cnt[i-'A']++;
        
        perm(0, 0);
        
    }
}