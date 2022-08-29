#include <bits/stdc++.h>
using namespace std;

#define ll                 long long int
#define mod                1000000007
#define inf                1e18
#define ump                unordered_map
#define pq_max             priority_queue<ll>
#define pq_min             priority_queue<ll, vi, greater<ll>>
#define loop(i, a, b)      for(int i = a; i <= b; i++)
#define looprev(i, a, b)   for(int i = a; i <= b; i--)
template <typename T> T gcd(T a, T b) {if (a % b) return gcd(b, a % b); return b;}
template <typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}

int f(int n)
{
    vector<int> dp(n + 1, 0);

    dp[0] = 0;

    loop(i, 1, n)
    {
        int steps = 1e9;

        int num = i;

        for(int j = num; j != 0; j = j / 10)
        {
            int digit = j % 10;

            if(digit == 0) continue;

            steps = min(1 + dp[i - digit], steps);
        }

        dp[i] = steps;
    }

    return dp[n];
}

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;

    int ans = f(n);
    cout << ans;

    return 0;
}
