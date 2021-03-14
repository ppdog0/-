#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    int l1, r1, l2 = 0, r2 = 0;
    vector<pair<int, int>> rec;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        l1 = max(0, i - x + 1);
        r1 = i;

        if (max(l1,l2) < min(r1,r2)) {
            rec.pop_back();
            l1 = min(l1, l2);
            r1 = max(r1, r2);
        }
        rec.emplace_back(l1, r1);
        l2 = l1, r2 = r1;
    }
    bool visit[n] = {false};
    for (auto [l,r] : rec) {
        for (int i = l; i <= r; i++) {
            visit[i] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (visit[i])
            cout << 1 << " ";
        else
            cout << 0 << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}