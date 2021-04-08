#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    ll ans = 0;
    ll price = 0;
    for (int i = 1; i < n; i++) {
        price += p[i - 1];
        ll inf = ceil((ll)p[i] * 100.0 / k);

        if (inf <= price) continue;

        ans += inf - price;
        price = inf;
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