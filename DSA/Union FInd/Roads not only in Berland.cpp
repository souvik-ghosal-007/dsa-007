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

class DSU
{
private:
	vector<int> parent;
	vector<int> size;
	vector<int> rank;

public:
	DSU(int n)
	{
		for (int i = 0; i <= n; i++)
		{
			parent.push_back(i);
			size.push_back(1);
			rank.push_back(0);
		}
	}

public:
	int findParent(int node)
	{
		if (parent[node] == node) return node;

		//path compression -> O(log n)
		//path compression and size -> O(4 x alpha) where alpha is almost 1.
		return parent[node] = findParent(parent[node]);
	}

public:
	void unionBySize(int u, int v)
	{
		int parentU = findParent(u);
		int parentV = findParent(v);

		if (parentU == parentV) return;

		if (size[parentU] < size[parentV])
		{
			parent[parentU] = parentV;
			size[parentV] += size[parentU];
		}
		else
		{
			parent[parentV] = parentU;
			size[parentU] += size[parentV];
		}
	}

public:
	void unionByRank(int u, int v)
	{
		int parentU = findParent(u);
		int parentV = findParent(v);

		if (rank[parentU] < rank[parentV])
		{
			parent[parentU] = parentV;
		}
		else if (rank[parentV] < rank[parentU])
		{
			parent[parentV] = parentU;
		}
		else
		{
			parent[parentU] = parentV;
			rank[parentV]++;
		}
	}
};

void roadsInBerland()
{
	int n;
	cin >> n;

	DSU dsu(n + 1);
	vector<pair<int, int>> extraRoads;

	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;

		if (dsu.findParent(u) == dsu.findParent(v))
		{
			extraRoads.push_back({u, v});
		}
		else
		{
			dsu.unionBySize(u, v);
		}
	}

	set<int> disconnectedComponents;
	for (int i = 1; i <= n; i++)
	{
		disconnectedComponents.insert(dsu.findParent(i));
	}

	int noOfComponents = disconnectedComponents.size();

	cout << noOfComponents - 1 << endl;

	vector<int> vec(disconnectedComponents.begin(), disconnectedComponents.end());
	int j = 0;
	for (int i = 1; i < noOfComponents; i++)
	{
		cout << extraRoads[j].first << " " << extraRoads[j].second << " " << vec[i] << " " << vec[i - 1] << endl;
		j++;
	}
}


signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	roadsInBerland();

	return 0;
}