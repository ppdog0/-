#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    int mx = *max_element(a, a + n);
    for (int i = 0; i < n; i++) {
        if (a[i] == mx) {
            if ((0<=i-1 && a[i-1]<a[i]) || (i+1<n && a[i+1]<a[i])) {
                cout << i + 1 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}