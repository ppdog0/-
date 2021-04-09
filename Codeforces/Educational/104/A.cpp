#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    sort(a, a + n);

    if (a[0] == a[n-1]) {
        cout << 0 << endl;
        return;
    }

    int ans = 0, mx = a[n-1];
    for (int i = n - 1; 0 <= i; i--) {
        if (a[i] > a[0])
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