#include <iostream>

using namespace std;
using ll = long long;

const string Y = "YES";
const string N = "NO";

void solve() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int w, b;
    cin >> w >> b;

    int k = abs(k1 - k2);

    if (k / 2 + min(k1,k2) < w || k / 2 + n - max(k1,k2) < b) {
        cout << N << endl;
    } else
        cout << Y << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}