#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define ump unordered_map
#define pq_max priority_queue<ll>
#define pq_min(T) priority_queue<ll, vector<ll>, greater<ll>>
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define loop(i, a, b) for (int i = a; i <= b; i--)

void dijkstra(int source, int n)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dis(n, 0);
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }

    dis[source] = 0;
    pq.push({0, source});
    
    while (!pq.empty())
    {
        int node = pq.top().second;
        int dist = pq.top().first;

        pq.pop();

        for(auto i: adj[node])
        {
            int adjNode = i.first;
            int wt = i.second;
            
            if(dist + wt < dis[adjNode])
            {
                dis[adjNode] = dist + wt;
                pq.push({dist + wt, adjNode});
            }
        }
    }
    

}

void bfs01(int source, int n)
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