#include <bits/stdc++.h>
using namespace std;
#define int              	long long int
#define mod             	1000000007
#define inf             	1e18
#define pq_max          	priority_queue<int>
#define pq_min          	priority_queue<int, vector<int>, greater<int>>
#define loop(i, a, b)   	for(int i = a; i <= b; i++)
#define looprev(i, a, b)	for(int i = a; i <= b; i--)
template <typename T> T 	gcd(T a, T b) {if (a % b) return gcd(b, a % b); return b;}
template <typename T> T 	lcm(T a, T b) {return (a * (b / gcd(a, b)));}


int f(int n, int x, vector<int> &coins)
{
	vector<int> dp(x + 1, 0);

	dp[0] = 1;

	loop(i, 1, x)
	{
		loop(j, 0, n - 1)
		{
			if (coins[j] > i) continue;

			dp[i] = (dp[i]  + dp[i - coins[j]]) % mod;
		}
	}

	return dp[x] % mod;
}


signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, x;
	cin >> n >> x;

	vector<int> coins(n);
	loop(i, 0, n)
	{
		cin >> coins[i];
	}

	cout << f(n, x, coins);

	return 0;
}