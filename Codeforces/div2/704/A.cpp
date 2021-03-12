#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    ll p, a[3];
    cin >> p;
    for (ll &x : a)
        cin >> x;
    ll ans = INT64_MAX;
    for (int i = 0; i < 3; i++) {
        if (p % a[i] == 0) {
            cout << 0 << endl;
            return;
        }
        ll k = p / a[i];
        ans = min(ans, (k + 1) * a[i] - p);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}