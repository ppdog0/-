#include <iostream>
#include <map>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    int a[n];
    map<int, int> rec;
    for (int &x : a) {
        cin >> x;
        rec[x]++;
    }
    for (auto x:rec) {
        if (x.second == 1) {
            for (int i = 0; i < n; i++) {
                if (a[i]==x.first)
                    cout << i + 1 << endl;
            }
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}