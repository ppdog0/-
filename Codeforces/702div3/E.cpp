#include <iostream>
#include <algorithm>
#include <cstring>

typedef long long ll;
using namespace std;

bool check(ll *a, int n, int m) {
    ll res = a[m];
    int l = m - 1, r = m + 1;
    while (r < n) {
        while (res < a[r]) {
            if (0 <= l)
                res += a[l--];
            else
                break;
        }
        if (a[r]<=res)
            res += a[r++];
        else
            return false;
    }
    return true;
}

int bin(ll *a, int n, int l, int r) {
    int mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(a, n, mid))
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

void solve() {
    int n;
    cin >> n;
    long long a[n];
    for (ll &x:a)
        cin >> x;
    ll b[n];
    memcpy(b, a, sizeof(a));
    sort(b, b + n);
    int ans = bin(b, n, 0, n);
    cout << n - ans << endl;
    for (int i = 0; i < n; i++) {
        if (b[ans] <= a[i])
            cout << i + 1 << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}