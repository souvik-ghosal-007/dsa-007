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

vector<int> numberOfIslands2(int m, int n, vector<vector<int>> &positions)
{
	DSU dsu(m * n + 1);

	vector<vector<int>> grid(m, vector<int>(n, 0));

	int count = 0;

	vector<int> ans;

	int dx[] = { -1, 1, 0, 0};
	int dy[] = {0, 0, 1, -1};

	for (auto i : positions)
	{
		int x = i[0];
		int y = i[1];

		if (grid[x][y] == 1)
		{
			ans.push_back(count);
			continue;
		}

		count++;

		grid[x][y] = 1;

		int ind1 = x * n + (y + 1);
		for (int dir = 0; dir < 4; dir++)
		{
			int newX = x + dx[dir];
			int newY = y + dy[dir];

			int ind2 = newX * n + (newY + 1);

			if (newX >= 0 && newX < m && newY >= 0 && newY < n
			        && grid[newX][newY] == 1
			        && dsu.findParent(ind1) != dsu.findParent(ind2))
			{
				count--;
				dsu.unionBySize(ind1, ind2);
			}
		}

		ans.push_back(count);
	}

	return ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int m, n, noOfQueries;
	cin >> m >> n >> noOfQueries;


	vector<vector<int>> positions;
	for (int i = 0; i < noOfQueries; i++)
	{
		vector<int> temp;
		for (int j = 0; j < 2; j++)
		{
			int x;
			cin >> x;

			temp.push_back(x);
		}

		positions.push_back(temp);
	}

	vector<int> ans = numberOfIslands2(m, n, positions);

	for (auto i : ans)
	{
		cout << i << " ";
	}

	return 0;
}