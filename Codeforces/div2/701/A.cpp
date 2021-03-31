#include <iostream>

using namespace std;
using ll = long long;

int count(int n, int k) {
    int res = 0;
    while (n) {
        n /= k;
        res++;
    }
    return res;
}

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = INT32_MAX;
    int res = 0;
    if (b == 1)
        b++, res++;
    while (b * b < a) {
        ans = min(ans, count(a, b) + res);
        b++, res++;
    }
    ans = min(ans, count(a, b) + res);
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