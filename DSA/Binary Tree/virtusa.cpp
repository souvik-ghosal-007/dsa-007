#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ForLoop(i, n) for(int i = 0; i < n; i++)

int findXth(int x)
{
	int n = 2;
	while (x > 0)
	{
		int c = 0;
		for (int i = 1; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				c++;
				if (i != n / i) c++;
			}
		}
		if (c == 2) x--;

		if (x == 0)
		{
			return n;
		}
		else n++;
	}

	return 0;
}

int f(int ind, vector<int> v, int target)
{
	if (ind == 0) return 1;
	if (ind < 0) return 0;

	int notPick = f(ind - 1, v, target);
	int pick = 0;
	if (target >= v[ind])
	{
		pick = f(ind, v, target - v[ind]);
	}

	return pick + notPick;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x; cin >> x;

	int target = findXth(x);

	cout << target << endl;

	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(11);
	v.push_back(13);
	v.push_back(17);
	v.push_back(19);

	cout << f(v.size() - 1, v, target) << endl;

	return 0;
}