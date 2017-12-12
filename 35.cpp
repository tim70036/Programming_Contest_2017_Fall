/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/35 */
/* Minimum edit distance : https://www.youtube.com/watch?v=We3YDTzNXEk */
#include <iostream>
#include <string>
#include <algorithm>
#define N 1005
using namespace std;

long long table[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string tar, in;
    int costI, costD, costS;
    cin >> costI >> costD >> costS;

    while(cin >> in >> tar)
    {
    	int inL = in.length(), tarL = tar.length();

    	/* Init , table's row is tar, table's col is in */
    	table[0][0] = 0;
    	for(int i=1 ; i<=inL ; i++)
    		table[0][i] = i * costD;
    	for(int i=1 ; i<=tarL ; i++)
    		table[i][0] = i * costI;


    	/* DP */
    	for(int i=1 ; i<=inL ; i++)
    	{
    		for(int j=1 ; j<=tarL ; j++)
    		{
    			if(in[i-1] == tar[j-1])
    				table[j][i] = table[j-1][i-1];
    			else
    				table[j][i] = min(table[j-1][i-1]+costS, min(table[j-1][i]+costI, table[j][i-1]+costD));
    		}
    	}

    	cout << table[tarL][inL] << "\n";
    }
}