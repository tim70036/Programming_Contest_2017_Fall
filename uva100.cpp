#include <iostream>

using namespace std;

int ans[10005];

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
    for(int i=0 ; i<10005 ; i++) ans[i] = -1;
    while(cin >> a >> b)
    {
        int max = -1;
        for(int i=a ; i<=b ; i++)
        {
            if(ans[i] == -1)
                run(i);
            max = (ans[i] > max) ? ans[i] : max;
        }
        cout << a << " " << b << " " << max << endl;
    }
}