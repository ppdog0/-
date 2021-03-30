#include <iostream>

using namespace std;
using ll = long long;

ll dig(ll n) {
    ll res = 0;
    while (n) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

ll gcd(ll n, ll m) {
    if (m == 0) {
        return n;
    }
    return gcd(m, n % m);
}

void solve() {
    ll n;
    cin >> n;
    for (ll i = n; i < 1e18+1; i++) {
        if (gcd(i,dig(i)) > 1) {
            cout << i << endl;
            return;
        }
    }
    cout << (ll)1e18 + 2 << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}