/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/23 */
#include <iostream>
#include <iomanip>
using namespace std;

int n;
double root[20];

inline double F(double x)
{
    double res = -1;
    for(int i=0 ; i<n ; i++)
        res *= (x - root[i]);
    return res;
}

double TriSearch(double left, double right)
{
    while(right - left > 1e-12)
    {
        double mid  = (left+right)/2.0;
        double midRight = (mid+right)/2.0;
        
        if(F(mid) < F(midRight))	left  = mid;
        else 						right = midRight;
    }
    return left;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=0 ; i<n ; i++)
        cin >> root[i];
    int p; cin >> p;
    
    cout << fixed << setprecision(6);
    cout << TriSearch(root[p], root[p+1]) << "\n";
}