#include <iostream>

using namespace std;
using ll = long long;

void solve() {
    int x, y;
    cin >> x >> y;
    ll ans = 0;
    for (int i = 1; i * i < x; i++)
        ans += max(min(y, x / i - 1) - i, 0);
    cout << ans << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}

// 区间外
// 除数依次增加

// 区间内
// 模依次递增 [0, n-1]
// 除数不变

// [lo, hi)
// int bin_left(int n, int lo, int hi) {
//     int mi;
//     while (lo < hi) {
//         mi = (lo + hi) >> 1;
//         if (n < mi * 1ll * mi - 1)
//             hi = mi;
//         else
//             lo = mi + 1;
//     }
//     return lo - 1;
// }

// void solve() {
//     int x, y;
//     cin >> x >> y;
//     ll ans = 0;

//     int start = bin_left(x, 1, 1e9 + 1);
//     start = min(start, y);
//     ans += (start - 1) * 1ll * start / 2;

//     if (y * 1ll * y <= x) {
//         cout << ans << endl;
//         return;
//     }

//     for (int m = start + 1; m <= y; m++) {
//         if (x <= m)
//             break;
//         int pos = x / m - 1;
//         pos += x % m >= pos + 1 ? 1 : 0;
//         // cout << min(m - 1, pos) << " ";
//         ans += min(m - 1, pos);
//     }

//     cout << ans << endl;
// }

// int main() {
//     cin.sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
// }

// [lo, hi)
// int bin_right(int n, int lo, int hi) {
//     int mi;
//     while (lo < hi) {
//         mi = (lo + hi) >> 1;
//         if (mi * 2 <= n)
//             lo = mi + 1;
//         else
//             hi = mi;
//     }
//     return lo * 2 > n ? lo - 1 : lo;
// }

// int end = bin_right(x, 1, 1e9 + 1);
// cout << end << endl;

// if (x < y && 3 < x) {
//     ans += x - end - 1;
//     y = end;
// }

// for (int m = start + 1; m <= y; m++) {
//     if (x <= m)
//         break;
//     int pos = x / m - 1;
//     pos += x % m >= pos + 1 ? 1 : 0;
//     ans += min(m - 1, pos);
// }