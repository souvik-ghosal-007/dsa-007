#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ForLoop(i, n) for(int i = 0; i < n; i++)


signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;

	while (t--)
	{
		int n, m;
		cin >> n >> m;

		vector<int> v;

		ForLoop(i, n)
		{
			int x; cin >> x;

			v.push_back(x);
		}

		string s;
		ForLoop(i, m)
		{
			s.push_back('B');
		}

		ForLoop(i, n)
		{
			int left = v[i];
			int right = m + 1 - v[i];

			if (left <= right)
			{
				if (s[left - 1] == 'B')
					s[left - 1] = 'A';
				else if (s[right - 1] == 'B')
					s[right - 1] = 'A';
			}
			else if (left >= right)
			{
				if (s[right - 1] == 'B')
					s[right - 1] = 'A';
				else if (s[left - 1] == 'B')
					s[left - 1] = 'A';
			}
		}

		cout << s << endl;
	}

	return 0;
}