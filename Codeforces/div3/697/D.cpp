#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
using ll = long long;
using ld = long double;

const int INF = (1 << 31) - 1;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a, b;
    vector<int> v(n);
    for (int &x : v)
        cin >> x;
    int y;
    for (int &x : v) {
        cin >> y;
        if (y == 1)
            a.push_back(x); // ==1
        else
            b.push_back(x); // ==2
    }
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    ll curSumA = 0;
    int r = (int)b.size();
    ll curSumB = accumulate(b.begin(), b.end(), 0ll);
    int ans = INT32_MAX;
    for (int l = 0; l <= a.size(); l++) {
        while (0 < r && m <= curSumA + curSumB - b[r-1]) {
            r--;
            curSumB -= b[r];
        }
        if (m <= curSumA + curSumB)
            ans = min(ans, 2 * r + l);
        if (l < a.size())
            curSumA += a[l];
    }
    cout << (ans < INT32_MAX ? ans : -1) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}

// #include <iostream>
// #include <cstring>
// #include <vector>

// using namespace std;
// using ll = long long;
// using ld = long double;

// const int INF = (1ll << 31) - 1;

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     ll a[n], b[n];
//     for (auto &x : a)
//         cin >> x;
//     for (auto &x : b)
//         cin >> x;

//     ll dp[m + 1]; // 空间为>=m时，最小分数
//     memset(dp, 0x7f, sizeof(dp));
//     dp[0] = 0;
//     for (int i = 0; i < n; i++) {
//         if (m < a[i] && b[i] < dp[m])
//             for (int k = 1; k < a[i]; k++)
//                 dp[k] = min(dp[k], b[i]);
//         for (int j = m; a[i] <= j; j--) {
//             ll res = dp[j - a[i]] + b[i];
//             if (res < dp[j]) {
//                 dp[j] = res;
//                 for (int k = 1; k < j; k++)
//                     dp[k] = min(dp[k], dp[j]);
//             }
//         }
//     }
//     if (dp[m] < INF)
//         cout << dp[m] << endl;
//     else
//         cout << -1 << endl;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
// }