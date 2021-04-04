#include <iostream>

using namespace std;
using ll = long long;

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (i & 1) {
            s[i] = s[i] == 'z' ? s[i] - 1 : 'z';
        } else {
            s[i] = s[i] == 'a' ? s[i] + 1 : 'a';
        }
    }
    cout << s << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}