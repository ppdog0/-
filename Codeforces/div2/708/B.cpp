#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n, m;
    cin >> n >> m;
    int mod[m] = {0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mod[x % m]++;
    }
    int ans = 0;
    if (mod[0] != 0)
        ans++;
    for (int i = 1; i <= m / 2; i++) {
        int x = mod[i];
        int y = mod[m - i];
        if (x==0 && y==0)
            continue;
        // ans += 1 + max(0, abs(x - y) - 1);
        if (1 < abs(x-y)) {
            ans += abs(x - y) - 1;
        }
        ans++;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}