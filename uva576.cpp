#include <iostream>

using namespace std;

int table[3005];

int main()
{
	/* Construct next term table for 0 ~ 3004 */
    for(int i=0 ; i<3005 ; i++)
    {
        int sum = 0;
        for(int j=1 ; j<=i ; j++)
        {
        	/* Is divisor */
            if(i % j == 0)
            {
            	/* Add each digit to sum */
                int div = j;
                while(div > 0)
                {
                    sum += div%10;
                    div /= 10;
                }
            }
        }
        
        /* Next term for i is sum */
        table[i] = sum;
    }
    
    int a, b;
    int cnt = 1;
    while(cin >> a >> b)
    {
        for(int i=a ; i<=b ; i++)
        {
        	/* Calculating len of DDF for i */
            int maxLen = -1, maxStart = a, len = 1;
            int cur = i;
            for(len = 1 ; cur != table[cur] ; cur = table[cur], len++);
            if(len > maxLen)
            {
            	maxStart = i;
            	maxLen = len;
            }
        }

        cout << "Input" << cnt << ": " << a << " " << b << "\n";
        cout << "Output" << cnt++ << ":";
        for(int cur = maxStart ; cout << " " << cur && cur != table[cur] ;  cur = table[cur]);
    }
}