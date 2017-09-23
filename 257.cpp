#include <string>
#include <iostream>
#include <set>

using namespace std;

int main()
{
    string in;
    while(cin >> in)
    {
        int len = in.length();
        set<string> store;
        
        /* Check len of 3, 4 */
        for(int i = 0 ; i < len - 2; i++)
        {
            if(in[i] == in[i+2])	store.insert(in.substr(i,3));
            else if(i+3 < len && in[i] == in[i+3] && in[i+1] == in[i+2])	store.insert(in.substr(i,4));
        }
        
        if(store.size() > 1) cout << in << endl;
    }
}