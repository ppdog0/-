#include <iostream>

using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    int t = (n - 1) / 2;
    if (k == 0) {
        for (int i = 0; i < n; i++)
            cout << i + 1 << endl;
        return;
    } else if (n < 3 || t < k) {
        cout << -1 << endl;
        return;
    }

    int nums[n];
    int m = 0;
    nums[m++] = 1;
    for (int i = 1; i <= k; i++) {
        nums[m++] = 2 * i + 1;
        nums[m++] = 2 * i;
    }
    for (int i = m; i < n; i++) {
        nums[i] = i + 1;
    }

    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
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