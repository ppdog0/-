#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int fact[N];
int invFact[N];

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

int C(int n, int k) {
    return fact[n] * 1ll * invFact[k] % mod * 1ll * invFact[n - k] % mod;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    for (int &x : a)
        cin >> x;
    sort(a, a + n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i + 1;
        int r = upper_bound(a, a + n, a[i] + k) - a;
        if (m-1 <= r-l)
        ans = (ans + C(r - l, m - 1)) % mod;
    }
    cout << ans << endl;
}

int main()
{
    fact[0] = invFact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * 1ll * i) % mod;
        invFact[i] = fast_pow(fact[i], mod - 2);
    }
    int t;
    cin >> t;
    while (t--)
        solve();
}