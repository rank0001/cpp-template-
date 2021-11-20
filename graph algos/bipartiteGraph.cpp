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
ll gcd(ll a, ll b)
{
	return __gcd(a, b);
}
inline void normal(ll &a)
{
	a %= mod;
	(a < 0) && (a += mod);
}
inline ll modMul(ll a, ll b)
{
	a %= mod, b %= mod;
	normal(a), normal(b);
	return (a * b) % mod;
}
ll lcm(ll a, ll b)
{
	return a * b / gcd(a, b);
}
ll val(ll size)
{
	ll a = 1, i;
	while (size--)
		a = modMul(a, 2);
	return a;
}
bitset<100000001> isSieve;
vi prime;
void sieve(ll n)
{
	ll maxN = n;
	for (ll i = 3; i <= maxN; i += 2)
		isSieve[i] = 1;
 
	isSieve[2] = 1;
 
	for (ll i = 3; i * i <= maxN; i += 2)
	{
		if (isSieve[i])
		{
			for (ll j = i * i; j <= maxN; j += (i + i))
				isSieve[j] = 0;
		}
	}
	for (ll i = 2; i <= maxN; i++)
	{
		if (isSieve[i])
			prime.pb(i);
	}
}
long combi(int n, int k)
{
	long ans = 1;
	k = k > n - k ? n - k : k;
	int j = 1;
	for (; j <= k; j++, n--)
	{
		if (n % j == 0)
		{
			ans *= n / j;
		}
		else if (ans % j == 0)
		{
			ans = ans / j * n;
		}
		else
		{
			ans = (ans * n) / j;
		}
	}
	return ans;
}
ll nod(ll n)
{
	ll res = 1;
	for (auto it : prime)
	{
		if (it * it > n)
			break;
 
		if (n % it == 0)
		{
			ll count = 1;
			while (n % it == 0)
			{
				n /= it;
				count++;
			}
			res *= count;
		}
	}
	if (n > 1)
		res *= 2;
	return res;
}
inline ll modPow(ll b, ll p)
{
	ll r = 1;
	while (p)
	{
		if (p & 1)
			r = modMul(r, b);
		b = modMul(b, b);
		p >>= 1;
	}
	return r;
}
bool isPrime(ll n)
{
	if (n == 1)
		return false;
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
ll cal(ll k)
{
	ll a;
	if (k % 2 == 0)
	{
		a = k / 2;
		a = modMul(a, k + 1);
	}
	else
	{
		a = (k + 1) / 2;
		a = modMul(k, a);
	}
	return a;
}
inline ll modInverse(ll a) { return modPow(a, mod - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
 
void addEdge(vector<ll> adj[], ll u, ll v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
 
bool DFSUtil(ll u, vector<ll> adj[],
			 vector<bool> &visited, vector<ll> &v, ll color)
{
	visited[u] = true;
	v[u] = color;
	for (auto it : adj[u])
	{
		if (!visited[it])
		{
 
			if (!DFSUtil(it, adj, visited, v, !v[u]))
				return false;
		}
		else
		{
			if (v[it] == v[u])
				return false;
		}
	}
	return true;
}
 
bool DFS(vector<ll> adj[], ll V, vector<ll> &v)
{
	vector<bool> visited(V + 1, false);
	for (int i = 1; i <= V; i++)
	{
		if (!visited[i])
		{
			bool ans = DFSUtil(i, adj, visited, v, !v[i]);
			if (!ans)
				return false;
		}
	}
	return true;
}
 
int main()
{
	rank0001();
	ll n, i, j, m, k, x, r, cnt = 0, a, b, c, e, d, f, sm1 = 0, sm2 = 0;
	j = 1;
	w(t)
	{
		cin >> n;
		vector<ll> v[n + 1];
		cin >> k;
		fo(i, k)
		{
			cin >> a >> b;
			addEdge(v, a, b);
		}
		vi v1(n + 1);
		bool value = DFS(v, n, v1);
		cout << "Scenario #" << j++ << ':' << endl;
		if (!value)
			cout << "Suspicious bugs found!" << endl;
		else
			cout << "No suspicious bugs found! " << endl;
	}
}
 
