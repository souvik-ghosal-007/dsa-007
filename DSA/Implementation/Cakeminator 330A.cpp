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

	int r, c;
	cin >> r >> c;

	char cake[r][c];

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> cake[i][j];
		}
	}

	int arr[r][c];

	unordered_set<int> row;
	unordered_set<int> col;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (cake[i][j] == 'S')
			{
				arr[i][j] = -1;

				row.insert(i);
				col.insert(j);
			}

			else arr[i][j] = 1;
		}
	}

	int sum = 0;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (row.find(i) != row.end()) break;

			sum = sum + arr[i][j];
			arr[i][j] = 0;
		}
	}

	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < r; j++)
		{
			if (col.find(i) != col.end()) break;

			sum = sum + arr[j][i];
			arr[j][i] = 0;
		}
	}

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}

	cout << sum << " ";

	return 0;
}