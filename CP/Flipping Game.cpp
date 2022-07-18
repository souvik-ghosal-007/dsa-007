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

	vector<int> v;

	int countOnes = 0;

	ForLoop(i, n)
	{
		int x; cin >> x;

		if (x == 1) countOnes++;

		v.push_back(x);
	}

	vector<int> b;
	ForLoop(i, n)
	{
		if (v[i] == 0) b.push_back(1);
		else b.push_back(-1);
	}

	//kadane's algo
	int sum = 0;
	int maxi = -1e9;

	ForLoop(i, n)
	{
		sum = sum + b[i];
		maxi = max(maxi, sum);

		if (sum < 0)
		{
			sum = 0;
		}

	}

	cout << maxi + countOnes << endl;

	return 0;
}