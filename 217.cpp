/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/217 */

#include <iostream>
using namespace std;

int num[1005];
int table[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--)
    {
        int n,k;	cin >> n >> k;
        for(int i=0 ; i<n ; i++)	cin >> num[i];
        
        int biggest = -1;
        for(int i=0 ; i<n ; i++)
        {
            int maxSum = 0;
            for(int index=i-k ; index >= 0 && index > i-2*k ; index--)
                maxSum = (table[index] > maxSum) ? table[index] : maxSum;
            
            table[i] = num[i]+maxSum;
            biggest = (table[i] > biggest) ? table[i] : biggest;
        }
        
        cout << biggest << "\n";
    }
}