/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/67 */
#include <iostream>
#include <map>
#include <utility>
using namespace std;

int a,b;

inline bool check(int tar)
{
    int remainA = a - tar;
    int remainB = b - tar;
    if(remainA < 0 || remainB < 0) return false;
    if(remainA+remainB < tar) return false;
    return true;
}

inline int BinarySearch(int left, int right)
{
    while(left+1 < right)
    {
        int mid = (left+right)/2;
        
        if(check(mid) == true)	left  = mid;
        else					right = mid;
    }
    return left;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    map<pair<int,int>,int> pool;
    
    while(cin >> a >> b)
    {
        auto p = make_pair(a,b);
        /* Search and Record Answer */
        if(pool.find(p) == pool.end())
            pool[p] = BinarySearch(0, 1000000000);
        
        cout << pool[p] << "\n";
    }
}