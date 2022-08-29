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
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if (a == 0 || b == 0 || c == 0 || d == 0)
		{
			cout << 1 << endl;
			continue;
		}

		//reduce the fractions
		int x = gcd(a, b);
		int y = gcd(c, d);

		a = a / x;
		b = b / x;

		c = c / y;
		d = d / y;

		int count = 0;

		if (a != c || b != d)
		{
			int lcm1 = lcm(a, c);
			int lcm2 = lcm(b, d);

			if (a != lcm1)
			{
				count++;
			}

			if (c != lcm1)
			{
				count++;
			}

			if (b != lcm2)
			{
				count++;
			}

			if (d != lcm2)
			{
				count++;
			}
		}

		cout << count << endl;
	}
	return 0;
}