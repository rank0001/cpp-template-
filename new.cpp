#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ff first
#define ss second
#define ll long long
#define pb push_back
#define mp make_pair
#define pr pair<ll, ll>
#define vi vector<ll>
#define mi map<ll, ll>
#define pqb priority_queue<int>
#define pqs priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define mod 1000000007
#define inf 1e18
#define endl '\n'
#define all(a) a.begin(), a.end()
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define fo(i, n) for (i = 0; i < n; i++)
#define fo1(i, a, n) for (i = a; i <= n; i++)
#define Fo(i, k, n) for (i = k; i < n; i++)
#define sr(i, n) for (i = 0; i < n.length(); i++)
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const double eps = 1e-9;

void rank0001()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

//ll count = 0, d = 0, k;
int N = 1e5 + 4;
vector<int> d1(N);
vector<vector<int>> a(N);
int n, k, d;
void dfs(ll par, ll child, ll value)
{
    if (value > k)
        return;
    int c = 1;
    for (ll vis : a[child])
    {
        if (vis!=par)
        {
            c = 0;
            dfs(child, vis, (value + 1) * d1[vis]);
        }
    }
    if (c)
        d++;
}

int main()
{
    rank0001();
    //ll n, i, j, m, x, r, cnt = 0, a, b, c, e, f, sm1 = 0, sm2 = 0;
    int i;
    cin >> n >> k;
    vi v(n + 1), v2(n + 1);

    fo1(i, 1, n)
    {
        cin >> d1[i];
    }

    fo(i, n - 1)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, 1, d1[1]);
    cout << d << endl;
}