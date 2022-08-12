#include <bits/stdc++.h>
using namespace std;
#define ll              	long long int
#define ld              	long double
#define mod             	1000000007
#define inf             	1e18
#define pb              	push_back
#define vi              	vector<ll>
#define vs              	vector<string>
#define pii             	pair<ll ,ll>
#define ump             	unordered_map
#define mp              	make_pair
#define pq_max          	priority_queue<ll>
#define pq_min          	priority_queue<ll, vi, greater<ll>>
#define all(n)          	n.begin(), n.end()
#define ff              	first
#define ss              	second
#define mid(l, r)       	(l+(r-l)/2)
#define loop(i, a, b)   	for(int i = a; i <= b; i++)
#define looprev(i, a, b)	for(int i = a; i <= b; i--)
template <typename T> T 	gcd(T a, T b) {if (a % b) return gcd(b, a % b); return b;}
template <typename T> T 	lcm(T a, T b) {return (a * (b / gcd(a, b)));}


//partition
int partition(vi &arr, int pivot, int left, int right)
{
	int i = left, j = left;

	while (i <= right)
	{
		if (arr[i] <= pivot)
		{
			swap(arr[i], arr[j]);
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}

	return j - 1;
}

//quickselect
int quickselect(vi &arr, int left, int right, int k)
{
	//if k is smaller than size of array
	if (k > 0 && k <= right - left + 1)
	{
		int pivot = partition(arr, pivot, left, right);

		if (k - 1 > pivot)
		{
			return quickselect(arr, pivot + 1, right, k);
		}
		else if (k - 1 < pivot)
		{
			//smaller element needed
			return quickselect(arr, left, pivot - 1, k);
		}
		else
		{
			//found
			return pivot;
		}
	}

	return -1;
}



signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	vi arr;
	loop(i, 0, n - 1)
	{
		int x; cin >> x;

		arr.pb(x);
	}

	int k;
	cin >> k;

	cout << quickselect(arr, 0, n - 1, k);


	return 0;
}