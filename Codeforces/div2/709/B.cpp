#include <iostream>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int mx=0;
    for (int &x : a) {
        cin >> x;
        mx = max(mx, x);
    }

    set<int> rec;
    for (int i = 1; i < n; i++) {
        int dif = a[i] - a[i - 1];
        rec.insert(dif);
    }

    if (n == 1 || rec.size() == 1) {
        cout << 0 << endl;
        return;
    } else if (rec.size() > 2) {
        cout << -1 << endl;
        return;
    }

    auto it = rec.begin();
    int x = *it, y = *(++it);
    if (x * 1ll * y >= 0) {
        cout << -1 << endl;
        return;
    }

    ll m = abs(x - y);
    ll c = abs(x + y + m) / 2;
    if (m <= mx) {
        cout << -1 << endl;
        return;
    }
    cout << m << " " << c << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}

// int curr = -1;
// int m = -1, c = -1;
// for (int i = 1; i < n; i++) {
//     if (curr == a[i] - a[i - 1]) {
//         c = curr;
//         break;
//     }
//     curr = a[i] - a[i - 1];
// }
// for (int i = 1; i < n; i++) {
//     if (curr != a[i] - a[i - 1]) {
//         m = a[i - 1] + c - a[i];
//     }
//     curr = a[i] - a[i - 1];
// }
// cout << c << " " << m << endl;