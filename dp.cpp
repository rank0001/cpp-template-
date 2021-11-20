#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <vector>
typedef long long ll;
using namespace std;
ll arr1[100005];

ll fac(ll arr[], ll i, ll n)
{
    if (arr1[i + 1] != -1)
        return arr1[i + 1];
    if (i == n - 1)
        return 0;
    else if (i == n - 2)
        return arr1[i + 1] = abs(arr[i] - arr[i + 1]);
    return arr1[i + 1] = min(abs(arr[i] - arr[i + 1]) + fac(arr, i + 1, n), abs(arr[i] - arr[i + 2]) + fac(arr, i + 2, n));
}

int knapsack(int wt[], int val[], int n, int w)
{
    int arr[n + 1][w + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 || j == 0)
                arr[i][j] = 0;
            else if (wt[i - 1] <= w)
            {
                arr[i][j] = max(val[i - 1] + arr[i - 1][j - wt[i - 1]], arr[i - 1][w]);
            }
            else
            {
                arr[i][j] = arr[i - 1][w];
            }
        }
    }
     
    return arr[n][w];
}

int main()
{
    int wt[] = {10,20,30};
    int val[] = {60,100,120};
    int w = 50;
    int n = 3;
    cout << knapsack(wt, val, n, w) << endl;
}