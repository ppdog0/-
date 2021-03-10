#include <iostream>
#include <set>
#include <cmath>

using namespace std;
using ll = long long;
using ld = long double;

int small(set<int> rec, int mx) {
    for (int i = 0; i <= mx; i++) {
        if (rec.count(i) == 0)
            return i;
    }
    return mx + 1;
}

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> rec;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx, x);
        rec.insert(x);
    }
    for (int i = 0; i < k; i++) {
        int k1 = rec.size();
        int me = small(rec, mx);
        int mi = ceil((me + mx)*1.0 / 2);

        if (mx < mi) {
            cout << rec.size() + k - i << endl;
            return;
        }

        rec.insert(mi);
        int k2 = rec.size();
        if (k1 == k2) {
            cout << rec.size() << endl;
            return;
        }
    }
    cout << rec.size() << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}