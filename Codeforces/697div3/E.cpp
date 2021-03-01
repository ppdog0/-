#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;

int fast_pow(int n, int k) {
    int res = 1;
    while (k) {
        if (k & 1) {
            res = res * 1ll * n % mod;
        }
        n = n * 1ll * n % mod;
        k >>= 1;
    }
    return res;
}

int fact(int n) {
    int res = 1;
    while (n) {
        res = res * 1ll * n % mod;
        n--;
    }
    return res;
}

ll C(int n, int k) {
    return fact(n) * 1ll * fast_pow(fact(k), mod - 2) % mod * 1ll * fast_pow(fact(n - k), mod - 2) % mod;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int x, cnt[n + 1] = {0};
    for (int i = 0; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    for (int i = n; 1 <= i; i--) {
        if (k <= cnt[i]) {
            cout << C(cnt[i], k) << endl;
            return;
        }
        k -= cnt[i];
    }
    cout << 1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}