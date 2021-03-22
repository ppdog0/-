#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n % 2 != 0)
        cout << 1 << " " << n / 2 << " " << n / 2 << endl;
    else if (n % 4 == 0)
        cout << n / 2 << " " << n / 4 << " " << n / 4 << endl;
    else
        cout << 2 << " " << n / 2 - 1 << " " << n / 2 - 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}