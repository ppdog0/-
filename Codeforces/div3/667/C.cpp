#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    if (n == 2) {
        cout << x << " " << y << endl;
        return;
    }
    int sub = y - x;
    for (int i = n - 2; 0 <= i; i--) {
        if (sub % (i+1) == 0) {
            int res = sub / (i + 1);
            int l = x;
            for (int j = n - i - 2; 1 <= j; j--) {
                if (0 < x - j * res) {
                    l = x - j * res;
                    break;
                }
            }
            for (int k = 0; k < n; k++) {
                cout << l + k * res << " ";
            }
            cout << endl;
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}