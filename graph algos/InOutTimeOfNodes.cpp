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
int timer=1;
void dfs(vector<ll> adj[], vector<bool> &visited, ll i,vector<ll> &v,vector<ll> &v1)
{
    visited[i] = true;
    v[i]=timer++;
    for (ll vis : adj[i])
    {
        if (!visited[vis])
            dfs(adj, visited, vis,v,v1);
    }
    v1[i]=timer++;
}

int main()
{

    rank0001();

    ll n, i, j, m, k, count = 0, a, b, c, d, v, e, sum1 = 0, sum2 = 0;
    multiset<pair<ll, pair<ll, ll>>> st;
    cin >> v >> e;
    vector<ll> adj[v + 1];
    while (e--)
    {
        cin >> a >> b;
        addEdge(adj, a, b);
    }
    count = 0;
    vector<bool> visited(v + 1, false);
    vi v1(n + 1),v2(n+1);
    for (ll i = 1; i <= v; i++)
    {
        if (!visited[i])
            dfs(adj, visited, i,v1,v2);
    }
    //at the end if among the given two nodes, one's in time is less
    // and out time greater than the other then they are in same subtree
    
}
