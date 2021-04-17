#include <iostream>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        if (m % 2 == 0)
            a[x++] = m;
        else
            b[y++] = m;
    }
    for (int i = 0; i < x; i++)
        cout << a[i] << " ";
    for (int i = 0; i < y; i++)
        cout << b[i] << " ";
    cout << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
