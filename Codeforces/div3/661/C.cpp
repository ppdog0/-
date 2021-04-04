#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    sort(a, a + n);

    int mi = a[0] + a[1], mx = a[n - 1] + a[n - 2];
    int ans = 0;
    for (int s = mi; s <= mx; s++) {
        int res = 0;
        int l = 0, r = n;
        while (1 < r - l) {
            int dis = s - a[l];
            int k = upper_bound(a, a + r, dis) - a - 1;
            if (l < k && a[k] == dis) {
                res++;
                r = k;
                l++;
            } else {
                l = upper_bound(a, a + n, a[l]) - a;
            }
        }
        ans = max(ans, res);
    }
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