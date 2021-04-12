#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int &x : a)
        cin >> x;
    vector<int> stk;
    for (int i = n - 1; 0 <= i; i--) {
        stk.push_back(a[i]);
    }

    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        for (int i = n-1; 0 <= i; i--) {
            if (stk[i] == x) {
                stk.erase(stk.begin() + i);
                stk.push_back(x);
                cout << n - i << endl;
                break;
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    solve();
}