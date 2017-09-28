#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		if(n==0)	break;

		int in;
		while(cin >> in)
		{
			if(in == 0)	break;

			queue<int> q;
			q.push(in);
			for(int i=0 ; i<n-1 ; i++)
			{
				cin >> in;
				q.push(in);
			}

			/* Simulation */
			stack<int> s;
			for(int i=1 ; i <= n ; i++)
			{
				s.push(i);
				if(!s.empty() && s.top() == q.front())
				{
					s.pop();
					q.pop();
				}
			}

			if(s.empty())	cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		cout << endl;
	}
}