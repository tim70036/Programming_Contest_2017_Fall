#include <iostream>
#include <algorithm>
#define N 10000000
using namespace std;

int ans[N];

void run(int n)
{
    int step = 1;
    int index = n;
    while(n > 1)
    {
        if(n % 2 == 1)	n = 3 * n + 1;
        else			n /= 2;
        step++;
    }
    ans[index] = step;
}

int main()
{
    int a , b;
    for(int i=0 ; i<N ; i++) ans[i] = -1;
    while(scanf("%d %d",&a,&b) != EOF)
    {
        int from = a, to = b;
        if(a > b) swap(from, to);

        int max = -1;
        for(int i=from ; i<=to ; i++)
        {
            if(ans[i] == -1)
                run(i);
            max = (ans[i] > max) ? ans[i] : max;
        }
        cout << a << " " << b << " " << max << endl;
    }
}