#include <iostream>

using namespace std;
using ll = long long;
const int N = 1e5 + 1;

int a[N];

void ask(int k, int n) {
    if (1 <= k && k <= n) {
        cout << "? " << k << endl;
        cin >> a[k];
    }
}

int give(int k) {
    cout << "! " << k << endl;
}

void solve() {
    int n;
    cin >> n;
    a[0] = a[n + 1] = n + 1; // +∞
    int l = 1, r = n;
    while (l < r) {
        int m = (l + r) >> 1;
        ask(m, n);
        ask(m + 1, n);
        if (a[m] < a[m+1])
            r = m;
        else
            l = m + 1;
    }
    cout << "! " << l << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    solve();
}