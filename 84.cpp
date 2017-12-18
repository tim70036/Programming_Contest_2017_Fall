/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/84 */
#include <iostream>
#include <algorithm>
#define N 100005
using namespace std;

int n,k;
int weight[N];

bool check(int cap)
{
    int cnt = 1;
    int curWeight = 0;
    for(int i=0 ; i<n ; i++)
    {
        /* Not enough to contain 1 customer */
        if(cap < weight[i])	 return false;
        
        curWeight += weight[i];
        if(curWeight > cap)
        {
            cnt++;
            curWeight = weight[i];
        }
    }
    
    if(cnt <= k)    return true;
    return false;
}

int BinarySearch(int left, int right)
{
    /* Lower bound */
    //if(check(right) == false) return -1;
    //if(check(left) == true) return left;
    
    while(left+1 < right)
    {
        int mid = (left+right)/2;

        bool valid = check(mid);
        if(valid)
            right = mid;
        else
            left = mid;
    }
    return right;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--)
    {
        cin >> n >> k;
        int id, w;
        for(int i=0 ; i<n ; i++)
        {
            cin >> id >> w;
            weight[id] = w;
        }
        
        /* Search Answer */
        cout << BinarySearch(0, N) << "\n";
        
    }
}