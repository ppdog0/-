#include <iostream>
#include <numeric>

using namespace std;
using ll = long long;

void solve() {
    int n, q, k;
    cin >> n >> q >> k;
    int a[n + 1]; // 0, 1,...,n
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << k - 1 << endl;
            continue;
        }
            cout << k + a[r] - a[l] - 2 * r + 2 * l - 1 << endl;
        }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    solve();
}