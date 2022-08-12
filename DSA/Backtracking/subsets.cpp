#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ForLoop(i, n) for(int i = 0; i < n; i++)

vector<vector<int>> f(int ind, vector<int> &v, vector<int> &ds, vector<vector<int>> &ans)
{
	if (ind < 0)
	{
		ans.push_back(ds);

		return ans;
	}

	ds.push_back(v[ind]);
	f(ind - 1, v, ds, ans);

	ds.pop_back();

	f(ind - 1, v, ds, ans);

	return ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n; cin >> n;

	vector<int> v;
	ForLoop(i, n)
	{
		int x; cin >> x;

		v.push_back(x);
	}

	vector<int> ds;
	vector<vector<int>> ans;

	f(v.size() - 1, v, ds, ans);

	for (auto i : ans)
	{
		for (auto j : i)
		{
			cout << j << " ";
		}

		cout << endl;
	}

	return 0;
}