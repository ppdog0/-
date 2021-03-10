#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

ll fact(int n) {
    ll res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;
    return res;
}

ll C(int n, int k) {
    return fact(n) / fact(k) / fact(n - k);
}

void solve() {
    int n;
    cin >> n;
    int k = n / 2;
    ll p = fact(k) / k;
    cout << (C(n, k) / 2) * p * p << endl;
}

int main() {
    solve();
}