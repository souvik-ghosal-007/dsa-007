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
		int a, b;
		cin >> a >> b;

		for (int i = a; i <= b; i++)
		{
			int count = 0;
			for (int j = 1; j * j <= i; j++)
			{
				if (i % j == 0)
				{
					count++;

					if (j != (i / j)) count++;

				}
			}

			if (count == 2) cout << i << endl;
		}

		cout << endl;
	}

	return 0;
}