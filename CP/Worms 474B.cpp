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

	int n;
	cin >> n;

	vector<int> a;
	ForLoop(i, n)
	{
		int x; cin >> x;

		a.push_back(x);
	}

	int m;
	cin >> m;

	vector<int> b;
	ForLoop(i, m)
	{
		int x; cin >> x;

		b.push_back(x);
	}

	vector<int> arr;
	int num = 1;
	arr.push_back(num);
	ForLoop(i, n)
	{
		num = num + a[i];

		arr.push_back(num);
	}

	ForLoop(i, m)
	{
		int ind = upper_bound(arr.begin(), arr.end(), b[i]) - arr.begin();

		cout << ind << endl;
	}

	return 0;
}