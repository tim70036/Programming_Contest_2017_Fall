/* Problem: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1031 */
#include <iostream>

using namespace std;
typedef long long ll;

ll gcd(ll x, ll y, ll* a, ll* b)
{
    ll s0 = 1, s1 = 0;
    ll t0 = 0, t1 = 1;
    ll r0 = x, r1 = y;
    
    while(1)
    {
        ll q = r0 / r1, r = r0 % r1;
        if(r == 0)	break;
        
        ll t;
        r0 = r1, r1 = r;
        t = s0; s0 = s1; s1 = t - s1 * q;
        t = t0; t0 = t1; t1 = t - t1 * q;
    }
    
    *a = s1;
    *b = t1;
    return r1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n;
    while(cin >> n && n != 0)
    {
        ll n1,n2,c1,c2;
        cin >> c1 >> n1 >> c2 >> n2;
        
        ll a, b;
        /* n1 * a + n2 * b = gcd(n1,n2) */
        ll g = gcd(n1,n2,&a,&b);
        
        if(n % g != 0)
        {
            cout << "failed\n";
            continue;
        }
        
        /* n1 * a + n2 * b = n */
        ll q = n / g;
        a *= q;
        b *= q;
        
        ll k1 = n1 * n2 / g / n1;
        ll k2 = n2 * n1 / g / n2;
        
        /* adjust a, b */
        ll k = a / k1;
        if(a < 0)
        {
            k = -(a/k1) + (a%k1 != 0);
            a += k1 * k;
            b -= k2 * k;
        }
        if(b < 0)
        {
            k = -(b/k2) + (b%k2 != 0);
            a -= k1 * k;
            b += k2 * k;
        }
        
        if(a < 0 || b < 0)
        {
            cout << "failed\n";
            continue;
        }
        
        
        ll minA, maxB;
        ll maxA, minB;
        /* Min a */
        k = a / k1;
        a -= k * k1;    minA = a;
        b += k * k2;    maxB = b;
        //cout << "min a : ";
        //cout << n << " = " << a << "*" << n1 << " + "<< b << "*" << n2 << "\n";
        
        /* Min b */
        k = b / k2;
        a += k * k1;    maxA = a;
        b -= k * k2;    minB = b;
        //cout << "min b : ";
        //cout << n << " = " << a << "*" << n1 << " + "<< b << "*" << n2 << "\n";
        
        if(c1*minA + c2*maxB < c1*maxA + c2*minB)
            cout << minA << " " << maxB << "\n";
        else
            cout << maxA << " " << minB << "\n";
    }
    
}