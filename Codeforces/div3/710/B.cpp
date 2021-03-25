#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int visit[n] = {false};
    int count = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (count == 0 && s[i] == '*') {
            ans++;
            count++;
            visit[i] = true;
        }
        int pos = 0;
        bool flag = false;
        if (visit[i]) {
            for (int j = i + 1; j <= i + k; j++) {
                if (j < n && s[j]=='*') {
                    pos = j;
                    flag = true;
                }
            }
            if (flag) {
                visit[pos] = true;
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}