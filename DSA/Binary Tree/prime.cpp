#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ForLoop(i, n) for(int i = 0; i < n; i++)

void cnt_divisors()
{
	int n; cin >> n;

	int c = 0;
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			c++;
			if (i != n / i) c++;
		}
	}

	cout << c << endl;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	cnt_divisors();


	return 0;
}