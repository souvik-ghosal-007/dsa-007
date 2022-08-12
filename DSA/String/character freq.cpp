#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ForLoop(i, n) for(int i = 0; i < n; i++)

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;

	unordered_map<char, int> map;
	queue<char> q;
	unordered_set<char> chars;
	for (int i = 0; i < s.length(); i++)
	{
		auto pos = chars.find(s[i]);

		if (pos == chars.end())
		{
			chars.insert(s[i]);
			q.push(s[i]);
		}
	}

	for (int i = 0; i < s.length(); i++)
	{
		map[s[i]]++;
	}

	vector<int> ans;
	while (!q.empty())
	{
		ans.push_back(map[q.front()]);
		q.pop();
	}


	return 0;
}