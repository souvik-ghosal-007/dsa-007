#include <bits/stdc++.h>

using namespace std;

#define ar array
#define ll long long
#define ld long double

#define PI 3.1415926535897932384626433832795l
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int main()
{

#ifndef ONLINE_JUDGE

	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);

#endif

	int t;

	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;

		vector<int> arr;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;

			arr.push_back(x);
		}

		int minSum = 1e9;
		int minSteps = 0;

		for (int i = 0; i < n; i++)
		{
			int sum = 0;
			int stepsCount = 0;

			if (i + k - 1 >= n)
			{
				break;
			}

			for (int j = 0; j < n; j++)
			{
				sum = sum + arr[j];

				if (j + i >= k)
				{
					stepsCount++;
				}
			}

			if (sum <= minSum)
			{
				minSum = sum;
				minSteps = stepsCount;
			}
		}

		cout << minSteps << endl;
	}

	return 0;
}