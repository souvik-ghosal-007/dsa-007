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


int f_SOP(int n, int x, vector<int> &coins)
{
	vector<int> prev(x + 1, 0), cur(x + 1, 0);

	loop(i, 0, x)
	{
		prev[i] = (i % coins[0] == 0);
	}

	loop(i, 1, n - 1)
	{
		loop(j, 0, x)
		{
			int notPick = prev[j] % mod;

			int pick = 0;
			if (j >= coins[i])
			{
				pick = cur[j - coins[i]] % mod;
			}

			cur[j] = (notPick % mod + pick % mod) % mod;
		}

		prev = cur;
	}

	return prev[x] % mod;
}


int f_DP(int n, int x, vector<int> &coins)
{
	vector<vector<int>> dp(n, vector<int> (x + 1, 0));

	vector<int> prev(n, 0), cur(x + 1, 0);

	loop(i, 0, x)
	{
		dp[0][i] = (i % coins[0] == 0);
	}

	loop(i, 1, n - 1)
	{
		loop(j, 0, x)
		{
			int notPick = dp[i - 1][j] % mod;

			int pick = 0;
			if (j >= coins[i])
			{
				pick = dp[i][j - coins[i]] % mod;
			}

			dp[i][j] = (notPick % mod + pick % mod) % mod;
		}
	}

	return dp[n - 1][x] % mod;
}

int f(int ind, int x, vector<int> &coins)
{
	if (x == 0) return 1;

	if (ind == 0)
	{
		if (x % coins[0] == 0) return 1;

		else return 0;
	}

	int notPick = f(ind - 1, x, coins);

	int pick = 0;
	if (x >= coins[ind])
	{
		pick = f(ind, x - coins[ind], coins);
	}

	return pick + notPick;
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

	cout << f_SOP(n, x, coins);

	return 0;
}