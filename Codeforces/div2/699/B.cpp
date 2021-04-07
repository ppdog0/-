#include <iostream>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int &x : a)
        cin >> x;

    if (n == 1 || k > (n-1) * 99) {
        cout << -1 << endl;
        return;
    }

    int ans = n + 1;
    for (int b = 0; b < k; b++) {
        int to = -2;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] < a[i + 1]) {
                to = i;
                break;
            }
        }
        ans = to + 1;
        if (to == -2)
            break;
        a[to]++;
    }
    cout << ans << '\n';
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}