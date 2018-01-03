/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/110 */
/* LIS Robinson-Schensted-Knuth Algorithm */
#include <iostream>
#include <vector>
#define N 300005
using namespace std;

int n;
int num[N];
int pos[N];
vector<int> record;

/* Return the pos of lower bound of tar in record */
int LowerBound(int left, int right, int tar)
{
    /* Special case */
    if(record[left] >= tar) return left;
    if(record[right] < tar) return -1; /* not exist */
    
    while(left+1 < right)
    {
        int mid = (left+right)/2;
        if(record[mid] >= tar) right = mid;
        else 				   left  = mid;
    }
    return right;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    while(cin >> n)
    {
        record.clear();
        
        for(int i=0 ; i<n ; i++)
            cin >> num[i];
        
        /* Init */
        record.push_back(num[0]);
        pos[0] = record.size()-1;
        
        /* Greedy */
        for(int i=1 ; i<n ; i++)
        {
            int cur = num[i];
            if(cur > record.back())
            {
                record.push_back(cur);
                pos[i] = record.size()-1;
            }
            else
            {
                int lowerBoundPos = LowerBound(0, record.size()-1, cur);
                record[lowerBoundPos] = cur;
                pos[i] = lowerBoundPos;
            }
        }
        
        /* output */
        int maxLen = record.size()-1;
        int index;
        for(index = n-1 ; index>=0 ; index--)
            if(pos[index] == maxLen)
                break;
        
        vector<int> ans;
        for(int i = index ; maxLen >=0 ; i--)
        {
            if(pos[i] == maxLen)
            {
                ans.push_back(num[i]);
                maxLen--;
            }
        }
        
        for(int i = ans.size()-1 ; i>=0 ; i--)
            cout << ans[i] << " ";
        cout << "\n";
    }
}