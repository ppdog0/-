#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n, m;
    ll x;
    cin >> n >> m >> x;
    ll row;
    ll column = (x + n - 1) / n;
    if (x % n == 0) {
        row = n;
    } else {
        row = x % n;
    }
    ll ans;
    if (column != m)
        ans = (row - 1) * m + column;
    else
        ans = row * 1ll * m;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}