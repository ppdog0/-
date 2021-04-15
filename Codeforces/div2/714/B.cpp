#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;

    int min1 = *min_element(a, a + n);
    int cnt = 0;

    for (int x:a) {
        if (x == min1)
            cnt++;
        if ((min1 & x) != min1) {
            cout << 0 << endl;
            return;
        }
    }

    int fact = 1;
    for (int i = 1; i <= n - 2; i++)
        fact = (1ll * fact * i) % Mod;
    int ans = (1ll * cnt * (cnt - 1)) % Mod;
    ans = (1ll * ans * fact) % Mod;
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