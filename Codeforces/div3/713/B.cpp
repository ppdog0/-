#include <iostream>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string a[n];
    for (auto &x : a)
        cin >> x;

    int x1 = -1, y1 = -1, x2, y2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == '*') {
                if (x1==-1 && y1==-1) {
                    x1 = i, y1 = j;
                } else {
                    x2 = i, y2 = j;
                    break;
                }
            }
        }
    }

    if (x1 != x2 && y1 != y2) {
        a[x2][y1] = '*', a[x1][y2] = '*';
    } else if (x1 == x2){
        int p;
        for (int i = 0; i < n; i++) {
            if (i != x1) {
                p = i;
                break;
            }
        }
        a[p][y1] = '*', a[p][y2] = '*';
    } else if (y1 == y2) {
        int p;
        for (int i = 0; i < n; i++) {
            if (i != y1) {
                p = i;
                break;
            }
        }
        a[x1][p] = '*', a[x2][p] = '*';
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}