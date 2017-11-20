/* Problem: https://pc2.tfcis.org/sky/index.php/problem/view/1 */
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int gcd(int x, int y)
{
    if(x % y == 0)  return y;
    else return gcd(y , x % y);
}

int main()
{
    int nu, de;
    while(scanf("%d/%d = ?", &nu, &de) != EOF)
    {   
        /* Divisible */
        if( nu % de == 0)
        {
            cout << nu / de << endl;
            continue;
        }

        /* Abs */
        bool neg = false;
        if(nu < 0)
        {
            nu *= -1;
            neg = !neg;
        }
        if(de < 0)
        {
            de *= -1;
            neg = !neg;
        }
            
        /* Integer part of answer */
        long long int a1 = nu / de;
        
        /* Simple fraction */
        long long int n = nu % de;
        long long int d = de;
        long long int g = gcd(d, n);
        n /= g;
        d /= g; 
        
        /* Count 2 and 5 */
        int cnt2 = 0, cnt5= 0;
        long long int dd = d;
        while(1)
        {
            if( dd % 2 == 0)         dd /= 2, cnt2++;
            else if( dd % 5 == 0)    dd /= 5, cnt5++;
            else                    break;
            
        }
        
        /* Non-recurring part of answer */
        int cnt = (cnt2 > cnt5) ? cnt2 : cnt5;

        /* Output integer and non-recurring part */
        if(neg) cout << "-";
        cout << a1 << ".";
        while(cnt--)
        {
            n *= 10;
            cout << n / d;
            n %= d;
        }
        
        /* Finite ? */
        if(dd != 1)
        {
            /* Recurring */
            long long int originN = n;
            cout << "(";
            do
            {
                n *= 10;
                cout << n / d;
                n %= d;
            }while(n != originN);
            cout << ")";
        }
        cout << endl;
    }
    return 0;
}