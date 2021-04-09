#include <iostream>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    if (n % 2 == 0) {
        int p = k % n;
        cout << (p == 0 ? n : p) << endl;
        return;
    }

    k--;
    cout << (k + k / (n / 2)) % n + 1 << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}