#include <iostream>

using namespace std;
using ll = long long;

int bin(int lo, int hi, int k) {}

void solve() {
    int n, k;
    cin >> n >> k;

    ll mi = n;
    if (n % k == 0) {
        cout << 1 << endl;
        return;
    } else if (n < k) {
        mi = k;
    } else {
        mi += k - (n % k);
    }

    cout << (mi + (n - 1)) / n << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}