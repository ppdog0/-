#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;
using ld = long double;

// n!
ll fact(int n) {
    ll res = 1;
    while (n) {
        res *= n;
        n--;
    }
    return res;
}

// (n-1)(n) / k
ll C(int n, int k) {
    return (n - 1) * 1ll * n / k;
    // return fact(n) / fact(k) / fact(n - k);
}

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a) {
        cin >> x;
    }
    sort(a, a + n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = upper_bound(a, a + n, a[i] + 2) - a;
        if (2 <= r - l)
            ans += C(r - l, 2);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}

// int cur = -1;
// map<int, int> rec;
// for (int i = 0; i < n; i++) {
//     if (cur != a[i]) {
//         rec[a[i]] = i;
//         cur = a[i];
//     }
// }
// ll ans = 0;
// for (auto it : rec) {
//     int m = it.second;
//     int k = bin(a, it.first + 2, m, n);
//     if (0 < k && 2 <= k - m)
//         ans += C(k - m + 1, 3);
// }

// [lo, hi)
// int bin(int a[], int x, int lo, int hi) {
//     int n = hi;
//     int mid;
//     while (lo < hi) {
//         mid = (lo + hi) >> 1;
//         if (a[mid] < x)
//             lo = mid + 1;
//         else
//             hi = mid;
//     }
//     return lo == n || x < a[lo] ? lo - 1 : lo;
// }

// #include <bits/stdc++.h>

// using namespace std;
// using ll = long long;

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<ll> cnt(n + 1);
//     for (int i = 0; i < n; i++)
//     {
//         int x;
//         cin >> x;
//         cnt[x]++;
//     }
//     ll ans = 0;
//     for (int i = 2; i < n; i++)
//     {
//         ans += cnt[i - 1] * cnt[i] * cnt[i + 1];
//     }
//     for (int i = 1; i < n; i++)
//     {
//         ans += cnt[i] * (cnt[i] - 1) / 2 * cnt[i + 1];
//     }
//     for (int i = 2; i <= n; i++)
//     {
//         ans += cnt[i - 1] * cnt[i] * (cnt[i] - 1) / 2;
//     }
//     for (int i = 2; i < n; i++)
//     {
//         ans += cnt[i - 1] * cnt[i + 1] * (cnt[i + 1] - 1) / 2;
//     }
//     for (int i = 2; i < n; i++)
//     {
//         ans += cnt[i + 1] * cnt[i - 1] * (cnt[i - 1] - 1) / 2;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         ans += cnt[i] * (cnt[i] - 1) * (cnt[i] - 2) / 6;
//     }
//     cout << ans << "\n";
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
// }