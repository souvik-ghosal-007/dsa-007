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

void solve()
{
	DSU dsu(n);
}


signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	return 0;
}