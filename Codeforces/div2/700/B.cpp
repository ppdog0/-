#include <iostream>

using namespace std;
using ll = long long;

const string Y = "YES";
const string N = "NO";

void solve() {
    int A, B, n;
    cin >> A >> B >> n;

    int mx = 0, k;
    int a[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        if (mx < x) {
            mx = x;
            k = i;
        }
    }
    int b[n];
    for (int &x : b)
        cin >> x;
    
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int t = (A + b[i] - 1) / A;
        ll hurt = t * 1ll * a[i];
        sum += hurt;
    }
    sum = sum - a[k] + 1;

    cout << (sum > B ? N : Y) << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}