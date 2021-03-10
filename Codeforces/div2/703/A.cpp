#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

const string Y = "YES";
const string N = "NO";

void solve() {
    int n;
    cin >> n;
    ll sum[n];
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum[i + 1] = x + sum[i];
    }
    if (n==1) {
        cout << Y << endl;
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (sum[i] * 2 < i * (i - 1)) {
            cout << N << endl;
            return;
        }
    }
    cout << Y << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}