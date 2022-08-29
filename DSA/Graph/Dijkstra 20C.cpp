#include <bits/stdc++.h>
using namespace std;
//#define int              	long long int
#define mod             	1000000007
#define inf             	1e18
#define pq_max          	priority_queue<int>
#define pq_min          	priority_queue<int, vector<int>, greater<int>>
#define loop(i, a, b)   	for(int i = a; i <= b; i++)
#define looprev(i, a, b)	for(int i = a; i <= b; i--)
template <typename T> T 	gcd(T a, T b) {if (a % b) return gcd(b, a % b); return b;}
template <typename T> T 	lcm(T a, T b) {return (a * (b / gcd(a, b)));}


void dikjstra(int source, int n, vector<pair<int, int>> adj[])
{
	vector<int> parent(n + 1, -1);

	vector<int> dis(n + 1 , 1e9);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({0, source});
	parent[source] = 1;
	dis[source] = 0;

	while (!pq.empty())
	{
		int node = pq.top().second;
		int dist = pq.top().first;
		pq.pop();

		for (auto i : adj[node])
		{
			int adjNode = i.first;
			int wt = i.second;

			if (dist + wt < dis[adjNode])
			{
				dis[adjNode] = dist + wt;
				parent[adjNode] = node;
				pq.push({dist + wt, adjNode});
			}
		}
	}

	vector<int> path;

	int x = n;
	if (parent[n] == -1)
	{
		cout << -1 << " ";

		return;
	}
	path.push_back(x);

	while (x != 1)
	{
		x = parent[x];

		path.push_back(x);
	}

	for (int i = path.size() - 1; i >= 0; i--)
	{
		cout << path[i] << " ";
	}
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> adj[n + 1];

	for (int i = 0; i < m; i++)
	{
		int x, y, wt;
		cin >> x >> y >> wt;

		adj[x].push_back({y, wt});
		adj[y].push_back({x, wt});
	}


	dikjstra(1, n, adj);

	return 0;
}