#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    n += 2;
    int b[n];
    for (int &x : b)
        cin >> x;
    sort(b, b + n);

    // x > sum
    // x = sum
    // x < sum

    ll sum = 0;
    for (int i = 0; i < n - 1; i++) 
        sum += b[i];
    // sum = b[n-1] 或 b[n-2]
    for (int k = 0; k < 2; k++) {
        ll res;
        for (int i = 0; i < n - 1; i++) {
            res = sum - b[i];
            if (res > 1e9) 
                continue;
            if (res == b[n - 1]) {
                for (int j = 0; j < n; j++) {
                    if (j == i || j == n-1)
                        continue;
                    cout << b[j] << " ";
                }
                cout << endl;
                return;
            }
        }
        sum = sum - b[n - 2] + b[n - 1];
        swap(b[n - 1], b[n - 2]);
    }
    cout << -1 << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}