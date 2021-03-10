#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

const string Y = "YES";
const string N = "NO";

struct tile {
    int a, b, c, d;
};

void solve() {
    int n, m;
    cin >> n >> m;
    tile a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
    }
    if (m % 2 != 0) {
        cout << N << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (a[i].b == a[i].c) {
            cout << Y << endl;
            return;
        }
    }
    cout << N << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}