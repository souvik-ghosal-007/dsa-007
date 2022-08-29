#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define ump unordered_map
#define pq_max priority_queue<ll>
#define pq_min(T) priority_queue<T, vi, greater<T>>
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define loop(i, a, b) for (int i = a; i <= b; i--)

void dijkstra(int source)
{
    pq_min(pair<int, int>);
}

void bfs01(int source)
{
    deque<pair<int, int>> dq;

    vector<int> dis(n, 0);
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[source] = 0;
    dq.push_front({source, 0});

    while (!dq.empty())
    {
        int node = dq.front().first;
        int dist = dq.front().second;
        dq.pop_front();

        for (auto i : adj[node])
        {
            int adjNode = i.first;
            int wt = i.second;
            if (dist + wt < dis[adjNode])
            {
                dis[adjNode] = dist + wt;

                if (wt == 1)
                {
                    dq.push_back({adjNode, dist + wt});
                }
                else
                {
                    dq.push_front({adjNode, dist + wt});
                }
            }
        }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}