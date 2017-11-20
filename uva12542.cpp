/* Problem: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3987 */
#include <iostream>
#include <string>
#include <cmath>
#define N 100005
using namespace std;

bool table[N];
int prime[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    /* Table */
    for(int i=0 ; i<N ; i++)	table[i] = true;
    
    for(int i = 2 ; i <= sqrt(N) ; i++)
        if(table[i] == true)
            for(int j = i * i ; j < N ; j += i)
                table[j] = false;
    
    int top = 0;
    for(int i=0 ; i < N ; i++)
        if(table[i]) prime[top++] = i;
    
    /* Input */
    string in;
    while(cin >> in && in != "0")
    {
        for(int i = top-1 ; i >= 0 ; i--)
        {
            string s = to_string(prime[i]);
            if(in.find(s) != string::npos)
            {
                cout << s << "\n";
                break;
            }
        }
    }
}