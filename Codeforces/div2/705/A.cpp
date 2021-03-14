#include <iostream>
#include <set>
#include <cmath>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> nums;
    for (int i = n; k < i; i--) {
        nums.insert(i);
    }
    int sum = 0;
    if (k == 2)
        nums.insert(1);
    else
        for (int i = ceil(k * 1.0 / 2); i < k; i++) {
            nums.insert(i);
        }
    cout << nums.size() << endl;
    for (auto x:nums)
        cout << x << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}