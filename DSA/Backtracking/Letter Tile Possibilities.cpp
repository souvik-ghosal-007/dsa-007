#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ForLoop(i, n) for(int i = 0; i < n; i++)

int f(unordered_map<char, int> &map)
{
	int sum = 0;
	for (auto i : map) sum += i.second;

	if (sum <= 0) return 0;

	int ans = 0;
	for (auto i : map)
	{
		if (i.second <= 0) continue;

		map[i.first] -= 1;
		ans += 1 + f(map);
		map[i.first] += 1;
	}

	return ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;

	unordered_map<char, int> map;

	ForLoop(i, s.length())
	{
		map[s[i]]++;
	}

	cout << f(map);

	return 0;
}