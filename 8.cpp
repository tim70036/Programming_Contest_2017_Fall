/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/8 */
/* Inversion Count */
#include <iostream>
#define N 1000005
using namespace std;

int num[N];
int tmp[N];

int Merge(int beg, int mid, int end)
{
    for(int i=beg ; i<=end ; i++)
        tmp[i] = num[i];
    
    int a = beg;
    int b = mid+1;
    int inv = 0, index = beg;
    while(a<=mid && b<=end)
    {
        if(tmp[a] < tmp[b])
        {
            num[index++] = tmp[a++];
        }
        else
        {
            num[index++] = tmp[b++];
            inv += (mid-a+1); /* the number after tmp[a] and tmp[a] will cause a inversion */
        }
    }
    
    while(a <= mid)	num[index++] = tmp[a++];
    while(b <= end)	num[index++] = tmp[b++];
    
    return inv;
}

int Inversion(int beg, int end)
{
    if(beg >= end)	return 0;
    
    int mid = (beg+end)/2;
    int inv = 0;
    inv += Inversion(beg, mid);
    inv += Inversion(mid+1, end);
    inv += Merge(beg, mid, end);
    
    return inv;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, t=1;
    while(cin >> n && n != -1)
    {
        for(int i=0 ; i<n ; i++)
            cin >> num[i];
        
        cout << "Case #" << t++ << ": ";
        cout << Inversion(0, n-1) << "\n";
    }
}