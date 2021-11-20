#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <vector>
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
#define pqb priority_queue<ll>
#define pqs priority_queue<ll, vi, greater<ll>>
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define MOD 1000000007
#define inf 1e18
#define endl '\n'
#define ye cout << "YES" << endl;
#define no cout << "NO" << endl;
#define ye1 cout << "Yes" << endl
#define no1 cout << "No" << endl
#define all(a) a.begin(), a.end()
#define ps(x, y) fixed << setprecision(y) << x
#define mk(arr, n, type) type *arr = new type[n];
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)
#define fo(i, n) for (i = 0; i < n; i++)
#define fo1(i, n) for (i = 1; i < n; i++)
#define Fo(i, k, n) for (i = k; i < n; i++)
#define sr(i, n) for (i = 0; i < n.length(); i++)

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

const double eps = 1e-9;

void rank0001()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool sortbysec(const pair<ll, ll> &a,
               const pair<ll, ll> &b)
{
    if (a.second < b.second || (a.second == b.second && a.first > b.first))
        return 1;

    else
        return 0;
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
bool isVowel(char c)
{
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
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
ll sod(ll n)
{
    ll c = 1, j, b;
    for (auto it : prime)
    {
        if (it * it > n)
            break;
        if (n % it == 0)
        {
            j = 1;
            b = 1;
            while (n % it == 0)
            {
                b += pow(it, j++);
                n /= it;
            }
            c *= b;
        }
    }
    if (n > 1)
        c *= n + 1;
    return c;
}
ll snod(ll n)
{
    ll res = 0;
    ll u = sqrt(n);
    for (int i = 1; i <= u; i++)
        res += (n / i) - i; //Step 1

    res *= 2; //Step 2
    res += u; //Step 3
    return res;
}

int maxSubArraySum(int a[], int size)
{
    int max_so_far = a[0];
    int curr_max = a[0];

    for (int i = 1; i < size; i++)
    {
        curr_max = max(a[i], curr_max + a[i]);
        max_so_far = max(max_so_far, curr_max);
    }
    return max_so_far;
}

ll gcd(ll a, ll b)
{
    return __gcd(a, b);
}
ll lcm(ll a, ll b)
{
    return a * (b * gcd(a, b));
}

inline void normal(ll &a)
{
    a %= MOD;
    (a < 0) && (a += MOD);
}
inline ll modMul(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    return (a * b) % MOD;
}
inline ll modAdd(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    return (a + b) % MOD;
}
inline ll modSub(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    a -= b;
    normal(a);
    return a;
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
inline ll modInverse(ll a) { return modPow(a, MOD - 2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
void addEdge(vector<ll> adj[], ll u, ll v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<ll> adj[], vector<bool> &visited, ll i)
{
    visited[i] = true;
    for (ll vis : adj[i])
    {
        if (!visited[vis])
            dfs(adj, visited, vis);
    }
}
ll phi(ll i)
{
    ll res = i;
    for (auto it : prime)
    {
        if (it * it > i)
            break;
        if (i % it == 0)
        {
            res /= it;
            res *= (it - 1);
            while (i % it == 0)
                i /= it;
        }
    }
    if (i > 1)
    {
        res /= i;
        res *= (i - 1);
    }
    return res;
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

int main()
{
    rank0001();
    ll n, i, j, m, k, r, count = 0, a, b, c, d, e = 1, sm1 = 0, sm2 = 0;
    sieve(1e8);
    w(t)
    {
        cin >> n;
        d = n;
        c = 1;
        for (auto it : prime)
        {
            if (it * it > n)
                break;
            if (n % it == 0)
            {
                j = 1;
                b = 1;
                while (n % it == 0)
                {
                    b += pow(it, j++);
                    n /= it;
                }
                c *= b;
            }
        }
        if (n > 1)
            c *= n + 1;

        cout << c - d << endl;
    }
}
