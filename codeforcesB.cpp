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
// bitset<100000001> isSieve;
// vi prime;
// void sieve(ll n)
// {
//     ll maxN = n;
//     for (ll i = 3; i <= maxN; i += 2)
//         isSieve[i] = 1;

//     isSieve[2] = 1;

//     for (ll i = 3; i * i <= maxN; i += 2)
//     {
//         if (isSieve[i])
//         {
//             for (ll j = i * i; j <= maxN; j += (i + i))
//                 isSieve[j] = 0;
//         }
//     }
//     for (ll i = 2; i <= maxN; i++)
//     {
//         if (isSieve[i])
//             prime.pb(i);
//     }
// }
// long combi(int n, int k)
// {
//     long ans = 1;
//     k = k > n - k ? n - k : k;
//     int j = 1;
//     for (; j <= k; j++, n--)
//     {
//         if (n % j == 0)
//         {
//             ans *= n / j;
//         }
//         else if (ans % j == 0)
//         {
//             ans = ans / j * n;
//         }
//         else
//         {
//             ans = (ans * n) / j;
//         }
//     }
//     return ans;
// }
// ll nod(ll n)
// {
//     ll res = 1;
//     for (auto it : prime)
//     {
//         if (it * it > n)
//             break;

//         if (n % it == 0)
//         {
//             ll count = 1;
//             while (n % it == 0)
//             {
//                 n /= it;
//                 count++;
//             }
//             res *= count;
//         }
//     }
//     if (n > 1)
//         res *= 2;
//     return res;
// }
// inline ll modPow(ll b, ll p)
// {
//     ll r = 1;
//     while (p)
//     {
//         if (p & 1)
//             r = modMul(r, b);
//         b = modMul(b, b);
//         p >>= 1;
//     }
//     return r;
// }
// ll cal(ll k)
// {
//     ll a;
//     if (k % 2 == 0)
//     {
//         a = k / 2;
//         a = modMul(a, k + 1);
//     }
//     else
//     {
//         a = (k + 1) / 2;
//         a = modMul(k, a);
//     }
//     return a;
// }
// inline ll modInverse(ll a) { return modPow(a, mod - 2); }
// inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

// void addEdge(vector<ll> adj[], ll u, ll v)
// {
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }
// ll count = 0, d = 1;
// vi v1(1000001);
// vector<ll> adj[1000001];
// vector<bool> visited(1000001, false);
// void dfs(ll par)
// {
//     visited[par] = true;
//     for (ll vis : adj[par])
//     {
//         if (!visited[vis])
//         {
//             d *= 2;
//             dfs(vis);
//         }
//     }
// }

// void BFS(vector<pair<ll, ll>> v)
// {
//     queue<pair<ll, ll>> q;
//     for (auto it : v)
//     {
//         q.push(mp(it.ff, it.ss));
//         visited[it.ff] = true;
//     }
//     while (!q.empty())
//     {
//         ll a = q.front().ff;
//         ll rr = q.front().ss;
//         q.pop();
//         if (rr != 0)
//         {
//             for (auto it : adj[a])
//             {
//                 if (!visited[it])
//                 {
//                     visited[it] = true;
//                     q.push(mp(it, rr - 1));
//                 }
//             }
//         }
//     }
// }
// vi vvv(10000001);
// ll fibo(ll n)
// {
//     if (n == 0)
//         return 1;
//     else if (n < 0)
//         return 0;
//     if (vvv[n] != 0)
//         return vvv[n];
//     ll a = fibo(n - 1) + fibo(n - 2) + fibo(n - 3);
//     return vvv[n] = a % mod;
// }
int main()
{
    rank0001();
    ll n, i, j, m, k, x = 1, r, cnt = 0, a, b, c, e, f, sm1 = 0, sm2 = 0;
    string s;
    cin >> s;
    map<string, ll> mp1;
    fo(i, 10)
    {
        string r1;
        cin >> r1;
        mp1[r1] = i;
    }
    string r2;
    fo(i, s.length())
    {
        r2 += s[i];
        if ((i + 1) % 10 == 0)
        {
            cout << mp1[r2];
            r2 = "";
        }
    }
    cout << endl;
}