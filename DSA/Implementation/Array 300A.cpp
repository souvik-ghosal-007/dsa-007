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

	int n; cin >> n;

	int arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int nega = 0;
	int posi = 0;
	int zero = 0;

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 0) nega++;

		else if (arr[i] > 0) posi++;

		else zero++;
	}

	int nNega = 0;
	int nPosi = 0;


	if (posi == 0)
	{
		if (nega % 2 == 0)
		{
			nPosi = 2;
			nNega = nega - nPosi - 1;
			nZero = 1;
		}
		else
		{
			nPosi = 2;
			nNega = nega - nPosi;
			nZero = 0;
		}
	}
	else
	{
		if (nega % 2 == 0)
		{
			nPosi = 0;
			nNega = nega - 1;
			nZero = 1;
		}
		else
		{
			nPosi = 0;
			nNega = nega;
			nZero = 0;
		}
	}

	vector<int> pos;
	vector<int> neg;
	vector<int> zer;

	int i = nPosi;

	while (i >= 0)
	{
		ifpos.push_back()
	}

	return 0;
}