/* https://pc2.tfcis.org/sky/index.php/problem/view/102 */
#include <iostream>
#include <set>
using namespace std;
typedef unsigned long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while(t--)
	{
		ll a, n;
		cin >> a >> n;

		set<ll> s;
		exp = a;
		while(1)
		{
			exp = (exp * a) % n;
			if(s.find(exp) != s.end())
			{
				cout << exp << "\n";
			}
			s.insert(exp);
		}
	}
}