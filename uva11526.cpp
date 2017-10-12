#include <iostream>
#include <cmath>
using namespace std;

typedef long long l;

l h(l n)
{
	l ans = 0;
	l sqt = sqrt(n)
	for(int i=1 ; i <= sqt ; i++)
		ans += n / i;
	ans = ans * 2 - sqt * sqt;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t; cin >> t;
	while(cin >> t)
	{
		l n; cin >> n;
		cout << h(n) << "\n";
	}
}