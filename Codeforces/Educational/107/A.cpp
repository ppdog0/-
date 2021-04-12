#include <iostream>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 2) {
            continue;
        }
        ans++;
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