#include <bits/stdc++.h>
using namespace std;
#define ll              long long int
#define ld              long double
#define mod             1000000007
#define inf             1e18
#define pb              push_back
#define vi              vector<ll>
#define vs              vector<string>
#define pii             pair<ll ,ll>
#define ump             unordered_map
#define mp              make_pair
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll, vi, greater<ll>>
#define all(n)          n.begin(), n.end()
#define ff              first
#define ss              second
#define mid(l, r)       (l+(r-l)/2)
#define loop(i, a, b)   for(int i = a; i <= b; i++)
#define loop(i, a, b)   for(int i = a; i <= b; i--)
template <typename T> T gcd(T a, T b) {if (a % b) return gcd(b, a % b); return b;}
template <typename T> T lcm(T a, T b) {return (a * (b / gcd(a, b)));}



signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;

    while (t--)
    {
        int n, H, M;
        cin >> n >> H >> M;

        int flag = 0;

        int ansH = 0, ansM = 0;
        int minH = 1e9, minM = 1e9;

        for (int i = 0; i < n; i++)
        {
            int h, m;
            cin >> h >> m;

            if (h == H && m == M)
            {
                cout << 0 << " " << 0 << endl;

                flag = 1;

                break;
            }

            if (H > h)
            {
                int t1 = 24 - H;

                ansH = h + t1;
            }
            else ansH = abs(H - h);

            ansM = abs(60 - M) + m;

            if (ansM >= 60)
            {
                ansM = abs(60 - ansM);

                ansH = ansH + 1;
            }
            else if (ansM < 60)
            {
                ansH--;
            }

            // minH = min(ansH, minH);
            // minM = min(ansM, minM);
        }

        if (flag == 0) cout << ansH << " " << ansM << endl;
    }



    return 0;
}