#include <bits/stdc++.h>
using namespace std;
#define int long long

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
		int n;
		cin >> n;

		vector<int> v;

		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;

			v.push_back(x);
		}

		int odd = 0, even = 0;

		for (int i = 0; i < n; i++)
		{
			if (i % 2 != v[i] % 2)
			{
				if (i % 2 == 0) even++;
				else odd++;
			}
		}

		if (even == odd) cout << odd << endl;

		else cout << -1 << endl;

	}

	return 0;
}