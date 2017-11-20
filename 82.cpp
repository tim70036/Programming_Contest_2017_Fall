/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/82 */
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#define N 105005
using namespace std;

string name[N];
int status[N];
long long int age[N];
/* Sort only idx */
int idx[N];

class cmp
{
public:
    bool operator()(const int a,const int b)
    {
        /* Status first */
        if(status[a] != status[b]) return status[a] < status[b];
        /* Age second */
        if(age[a] != age[b])
        {
            /* it is not appentice */
            if(status[a] != 5)	return age[a] > age[b];
            /* it is appentice */
            return age[a] < age[b];
        }
        /* Name third */
        return name[a] < name[b];
    }
};
cmp shit;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    /* Mapping from status to a number */
    map<string, int> table;
    table["elder"] = 1;
    table["nursy"] = 2;
    table["kit"] = 3;
    table["warrior"] = 4;
    table["appentice"] = 5;
    table["medicent"] = 6;
    table["deputy"] = 7;
    table["leader"] = 8;
    
    /* Input */
    int n,m,inAge;
    while(cin >> n >> m)
    {
        string inName, inSatus;
        for(int i=0 ; i<n ; i++)
        {
            cin >> inName >> inSatus >> inAge;
            name[i] = inName;
            status[i] = table[inSatus];
            age[i] = inAge;
            idx[i] = i;
        }
        
        /* Sort, using idx table */
        sort(idx, idx+n, shit);
        int cnt = (n<m)? n : m;
        for(int i=0 ; i < cnt ; i++)
            cout << name[idx[i]] << "\n";

    }
}