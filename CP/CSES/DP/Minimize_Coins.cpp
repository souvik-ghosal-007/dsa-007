#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define mod 1000000007
#define inf 1e18
#define ump unordered_map
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vi, greater<ll>>
#define loop(i, a, b) for (int i = a; i <= b; i++)
#define looprev(i, a, b) for (int i = a; i <= b; i--)

int f_DP(int x, vector<int> &coins)
{
    vector<int> dp(x + 1, 1e9);

    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        int steps = 1e9;
        for (int j = 0; j < coins.size(); j++)
        {
            if (i >= coins[j])
                steps = min(1 + dp[i - coins[j]], steps);
        }

        dp[i] = steps;
    }

    return dp[x];
}

int f(int x, vector<int> &coins, vector<int> &dp)
{
    if (x == 0)
        return 0;

    if (dp[x] != -1)
        return dp[x];

    int steps = 0;

    int minSteps = 1e9;

    for (int i = 0; i < coins.size(); i++)
    {
        if (x >= coins[i])
            steps = 1 + f(x - coins[i], coins, dp);

        minSteps = min(minSteps, steps);
    }

    return dp[x] = minSteps;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, x;
    cin >> n >> x;

    vector<int> coins(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    // vector<int> dp(x + 1, -1);

    int ans = f_DP(x, coins);

    if(ans == 1e9) cout << -1;
    else cout << ans;


    return 0;
}
