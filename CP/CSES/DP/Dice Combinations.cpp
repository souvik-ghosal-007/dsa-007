#include <bits/stdc++.h>
using namespace std;
#define mod             	1000000007
#define inf             	1e18
#define pq_max          	priority_queue<int>
#define pq_min          	priority_queue<int, vector<int>, greater<int>>
#define loop(i, a, b)   	for(int i = a; i <= b; i++)
#define looprev(i, a, b)	for(int i = a; i <= b; i--)
template <typename T> T 	gcd(T a, T b) {if (a % b) return gcd(b, a % b); return b;}
template <typename T> T 	lcm(T a, T b) {return (a * (b / gcd(a, b)));}


int f(int n)
{
	vector<int> dp(n + 1, 0);

	dp[0] = dp[1] = 1;

	loop(i, 2, n)
	{
		loop(j, 1, 6)
		{
			if (j > i) continue;

			dp[i] = (dp[i] % mod + dp[i - j] % mod) % mod;
		}
	}

	return dp[n] % mod;
}

// int f(int n)
// {
// 	if (n == 0) return 1;
// 	if (n == 1) return 1;

// 	if (dp[n] != -1) return dp[n];

// 	int count = 0;

// 	for (int i = 1; i <= 6; i++)
// 	{
// 		if (n > i) count += f(n - i);
// 	}

// 	return dp[n] = count;
// }

// int f(int n)
// {
// 	if (n == 0) return 1;

// 	if (n == 1) return 1;

// 	int count = 0;

// 	for (int i = n - 1; i >= 0; i--)
// 	{
// 		count += f(i);
// 	}

// 	return count;
// }

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	cout << f(n) << endl;

	return 0;
}