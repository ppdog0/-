#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

int sum(ll n, int digits[], int& m) {
    int res = 0;
    while (n) {
        digits[m++] = n % 10;
        res += n % 10;
        n /= 10;
    }
    return res;
}

void solve() {
    int s;
    ll n;
    cin >> n >> s;
    int m = 0;
    int digits[19] = {0};
    if (sum(n, digits, m) <= s) {
        cout << 0 << endl;
        return;
    }

    int count = m;
    while (digits[count - 1] < s) {
        s -= digits[count - 1];
        count--;
    }
    ll num = 0;
    if (count == m) {
        num = 1;
        for (int i = 0; i < m; i++) {
            num *= 10;
        }
    }
    else {
        digits[count]++;
        for (int i = m; count < i; i--) {
            num = num * 10 + digits[i - 1];
        }
        for (int i = 0; i < count; i++) {
            num = num * 10;
        }
    }
    cout << num - n << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}