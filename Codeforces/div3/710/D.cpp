#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    map<int, int> rec;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        rec[x]++;
    }

    vector<int> dup;
    for (auto x: rec) {
        dup.push_back(x.second);
    }
    sort(dup.begin(), dup.end());
    if (dup[dup.size() - 1] > n / 2) {
        cout << dup[dup.size() - 1] * 2 - n << endl;
        return;
    }
    cout << (accumulate(dup.begin(), dup.end() - 1, 0) - dup[dup.size() - 1]) % 2 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}