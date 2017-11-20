/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/2 */
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n,m,k, in, max = 0;
    cin >> n >> m >> k;
    
    for(int i=0 ; i < n*m ; i++)
    {
        cin >> in;
        max = (in > max) ? in : max;
    }
    cout << fixed << setprecision(k);
    cout << double(max) << endl;
}