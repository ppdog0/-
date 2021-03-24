#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int a, b;
    cin >> a >> b;
    int ans = 0;
    int sub = abs(a - b);
    int div = 10;
    while (sub) {
        int x = sub / div;
        ans += x;
        sub -= x * div;
        div--;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}