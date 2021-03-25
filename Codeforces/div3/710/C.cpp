#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    string a, b;
    cin >> a >> b;
    if (a==b) {
        cout << 0 << endl;
        return;
    }
    int n = a.size(), m = b.size();
    int res = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = i, y = j;
            while (x<n && y<m && a[x] == b[y]) {
                x++, y++, count++;
                res = max(res, count);
            }
            count = 0;
        }
    }
    cout << n-res+m-res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}