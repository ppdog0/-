#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

// n = 5
// 2 3 4 5 1
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int k = (i + 1) % (n + 1);
        if (k==0)
            k = 1;
        cout <<k << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}