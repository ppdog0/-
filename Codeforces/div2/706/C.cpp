#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    int l = 0, r = 0;
    for (int i = 0; i < 2 * n; i++) {
        int x, y;
        cin >> x >> y;
        if (x == 0)
            a[l++] = abs(y);
        else
            b[r++] = abs(x);
    }
    sort(a, a + n);
    sort(b, b + n);
    double ans = INT64_MAX;

    do {
        double res = 0;
        for (int i = 0; i < n; i++) {
            res += sqrt(a[i] * a[i] + b[n - i - 1] * b[n - i - 1]);
        }
        ans = min(ans, res);
    } while (next_permutation(b, b + n));
    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}