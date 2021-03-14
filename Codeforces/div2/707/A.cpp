#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    int d[n];
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    int arr = 0, lev = 0;
    for (int i = 0; i < n; i++) {
        if (1 <= i) {
            arr = lev + d[i] + a[i] - b[i - 1];
        } else {
            arr = a[i] + d[i];
        }
        int wait = ceil((b[i] - a[i]) * 1.0 / 2);
        lev = b[i] < arr + wait ? arr + wait : b[i];
    }
    cout << arr << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}