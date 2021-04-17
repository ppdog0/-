#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const string Y = "YES";
const string N = "NO";

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> pos;
    int m = 0;
    int l = 0;
    int x[n];
    for (int i = 0; i < n; i++) {
        if (s[i] == 'M') {
            m++;
            x[i] = l;
            pos.push_back(i);
        } else
            l++;
    }
    if (m != n / 3) {
        cout << N << endl;
        return;
    }

    int r = 0;
    int y[n];
    for (int i = n - 1; 0 <= i; i--) {
        if (s[i] == 'M') {
            y[i] = r;
        } else
            r++;
    }

    int d = pos.size();
    for (int i = 0; i < d; i++) {
        int a = x[pos[i]], b = y[pos[i]];
        if (a < i + 1 || b < d - i) {
            cout << N << endl;
            return;
        }
    }
    cout << Y << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}