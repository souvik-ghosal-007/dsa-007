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

	vector<int> shops;
	ForLoop(i, n)
	{
		int x;
		cin >> x;

		shops.push_back(x);
	}

	sort(shops.begin(), shops.end());

	int q; cin >> q;

	ForLoop(i, q)
	{
		int x; cin >> x;

		int ind = upper_bound(shops.begin(), shops.end(), x) - shops.begin();

		cout << ind << endl;
	}


	return 0;
}