// 重合: max(l1, l2) <= min(r1, r2)
// 不重合: R < l || r < L

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    vector<int> L;
    vector<int> R;
    for (auto &[l,r] : a) {
        cin >> l >> r;
        L.push_back(l);
        R.push_back(r);
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    int ans = n - 1;
    for (auto [l, r] : a) {
        int left = lower_bound(R.begin(), R.end(), l) - R.begin();
        int right = max(0, n - (int)(upper_bound(L.begin(), L.end(), r) - L.begin()));
        ans = min(ans, left + right);
    }
    cout << ans << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}

// sort(a.begin(), a.end());
// int res = 0;
// int sum = 0;
// int cur = -1;
// int i = 0;
// while (i < a.size())
// {
//     cur = a[i].first;
//     sum += a[i].second;
//     i++;
//     while (i < n && a[i].first == cur)
//     {
//         sum += a[i].second;
//         i++;
//     }
//     res = max(sum, res);
//     // if (sum == n) {
//     //     ans++;
//     // }
// }
// cout << n - res << endl;