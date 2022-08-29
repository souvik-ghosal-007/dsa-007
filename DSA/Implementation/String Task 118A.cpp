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

	string s;
	cin >> s;

	vector<int> vowelInd;

	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case 'a':
		case 'A': vowelInd.push_back(i); break;

		case 'e':
		case 'E': vowelInd.push_back(i); break;

		case 'i':
		case 'I': vowelInd.push_back(i); break;

		case 'o':
		case 'O': vowelInd.push_back(i); break;

		case 'u':
		case 'U': vowelInd.push_back(i); break;

		case 'y':
		case 'Y': vowelInd.push_back(i); break;

		default: break;
		}
	}

	for (int i = 0; i < vowelInd.size(); i++)
	{
		s.erase(s.begin() + vowelInd[i] - i);
	}

	vector<int> conInd;
	for (int i = 0; i < s.size(); i++)
	{
		s[i] = tolower(s[i]);
		conInd.push_back(i);
	}

	for (int i = 0; i < conInd.size(); i++)
	{
		s.insert(conInd[i] + i, ".");
	}



	cout << s << " ";

	return 0;
}