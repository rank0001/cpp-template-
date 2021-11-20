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

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void DFSUtil(int u, vector<int> adj[],
             vector<bool> &visited)
{
    visited[u] = true;
    cout << u << " ";
    for (int i = 0; i < adj[u].size(); i++)
        if (!visited[adj[u][i]])
            DFSUtil(adj[u][i], adj, visited);
}

void DFS(vector<int> adj[], int V)
{
    vector<bool> visited(V, false);
    for (int u = 0; u < V; u++)
        if (!visited[u])
            DFSUtil(u, adj, visited);
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    DFS(adj, V);
    return 0;
}