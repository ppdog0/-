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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        rec[a[i]] = i;
    }

    int k = n;
    for (int i = n; 0 < i; i--) {
        if (k == 0)
            break;
        if (k <= rec[i])
            continue;
        for (int j = rec[i]; j < k; j++) {
            cout << a[j] << " ";
        }
        k = rec[i];
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}