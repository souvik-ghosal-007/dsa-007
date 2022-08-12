#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ForLoop(i, n) for(int i = 0; i < n; i++)

void findAnagrams(string s, string p)
{
	vector<int> ans;

	int n = s.length();
	int k = p.length();

	unordered_map<char, int> pat;
	ForLoop(i, p.length())
	{
		pat[p[i]]++;
	}

	int i = 0, j = 0;
	int count = pat.size();

	//cout << count;

	while (j < n)
	{
		if (pat.count(s[j]) != 0)
		{
			pat[s[j]]--;

			if (pat[s[j]] == 0) count--;
		}

		if ((j - i + 1) == k)
		{
			if (count == 0) ans.push_back(i);

			if (pat.count(s[i]) != 0)
			{
				pat[s[i]]++;

				if (pat[s[i]] == 1)
				{
					count++;
				}
			}

			i++;
			j++;
		}

		else j++;


		ForLoop(i, ans.size())
		{
			cout << ans[i] << " ";
		}
	}
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s, p;
	cin >> s;
	cin >> p;

	findAnagrams(s, p);


	return 0;
}