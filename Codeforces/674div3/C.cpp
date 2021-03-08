#include <iostream>
#include <cmath>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    int ans = n - 1;
    int k = 1;
    while (k < n) {
        int res = ceil((n - k) * 1.0 / k) + k - 1;
        k++;
        if (res <= ans)
            ans = res;
        else
            break;
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}