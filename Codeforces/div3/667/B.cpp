#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    int t1 = a - x, t2 = b - y;
    if (t1 + t2 <= n) {
        cout << x * 1ll * y << endl;
        return;
    }
    int m1 = a - min(n, t1), m2 = b - min(n, t2);
    if (m1 <= m2) {
        a -= min(t1, n);
        b -= n - min(t1, n);
    } else {
        b -= min(t2, n);
        a -= n - min(t2, n);
    }
    cout << a * 1ll * b << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}

// t1 = min(n, t1), t2 = min(n, t2);
// ll ans = INT64_MAX;
// for (int i = 0; i <= t1; i++) {
//     ll res;
//     if (n - i <= t2)
//         res = (a-i) * 1ll * (b - (n - i));
//     else
//         res = (a - i) * 1ll * b;
//     ans = min(ans, res);
// }
// cout << ans << endl;