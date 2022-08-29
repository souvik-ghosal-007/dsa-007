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

	string s1, s2;
	cin >> s1;
	cin >> s2;

	for (int i = 0; i < s1.size(); i++)
	{
		s1[i] = tolower(s1[i]);
		s2[i] = tolower(s2[i]);
	}

	int n = s1.size();

	int order = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		if (s1[i] < s2[i])
		{
			order = -1;
			continue;
		}

		else if (s1[i] > s2[i])
		{
			order = 1;
			continue;
		}

		else order = 0;
	}

	cout << order << endl;
	return 0;
}