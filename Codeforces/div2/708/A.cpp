#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    int rec[101] = {0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        rec[x]++;
    }
    int k = 0;
    int count = 0;
    while (true) {
        if (rec[k % 101] != 0) {
            cout << k % 101 << " ";
            rec[k % 101]--;
            count++;
        }
        k++;
        if (count==n)
            break;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}