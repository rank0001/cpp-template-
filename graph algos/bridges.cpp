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
#define Fo(i, k, n) for (i = k; i < n; i++)
#define sr(i, n) for (i = 0; i < n.length(); i++)

void rank0001()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void addEdge(vector<ll> adj[], ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vi inTime(1000001), lcaTime(1000001);
vector<ll> adj[1000001];
vector<bool> visited(1000001, false);
ll timer;
void dfs(ll child, ll parent)
{
    visited[child] = true;
    inTime[child] = lcaTime[child] = timer;
    timer++;
    for (auto it : adj[child])
    {
        if (it == parent)
            continue;
        if (visited[it])
        {
            //calculating lca and checking backedge
            lcaTime[child] = min(lcaTime[child], inTime[it]);
        }
        else
        {
            dfs(it, child);
            if (lcaTime[it] > inTime[child])
            {
                cout << child << " " << it << " has a bridge!";
            }
            lcaTime[child] = min(lcaTime[child], lcaTime[it]);
        }
    }
}

int main()
{

    rank0001();

    ll n, i, j, m, k, count = 0, a, b, c, d, v, e, sum1 = 0, sum2 = 0;
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b;
        addEdge(adj, a, b);
    }
    dfs(1, -1);
}
