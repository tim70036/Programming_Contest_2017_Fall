#include <iostream>

using namespace std;

int ggg[505][505];

int gcd(int x, int y)
{
    return (x % y == 0) ? y : gcd(y, x % y);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    /* Table */
    for(int i=1 ; i<505 ; i++)
        for(int j=1 ; j<505 ; j++)
            ggg[i][j] = gcd(i,j);
    
    int n;
    while(cin >> n && n != 0)
    {
        int sum = 0;
        for(int i=1 ; i<n ; i++)
            for(int j=i+1 ; j<=n ; j++)
                sum += ggg[i][j];
        cout << sum << "\n";
    }
}