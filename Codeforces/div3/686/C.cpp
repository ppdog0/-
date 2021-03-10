#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it:a)
        cin >> it;
    n = unique(a.begin(), a.end()) - a.begin();
    a.resize(n);

    map<int, int> pos;
    for (int i = 0; i < n; i++) {
        pos[a[i]] = 1;
    }
    for (int i = 0; i < n; i++) {
        pos[a[i]]++;
    }
    pos[a[0]]--;
    pos[a[n - 1]]--;

    int ans = (n+1) / 2;
    for(auto i:pos) {
        ans = min(ans, i.second);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}