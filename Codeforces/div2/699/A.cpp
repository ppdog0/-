#include <iostream>

using namespace std;
using ll = long long;

const string Y = "YES";
const string N = "NO";

void solve() {
    int x, y;
    cin >> x >> y;
    string s;
    cin >> s;

    int n = s.size();
    int u=0, d=0, l=0, r=0;
    for (int i = 0; i < n; i++) {
        if (s[i]=='U')
            u++;
        else if (s[i]=='D')
            d++;
        else if (s[i]=='L')
            l++;
        else
            r++;
    }

    bool flag = true;
    if (x > 0) {
        if (x > r)
            flag = false;
    } else {
        if (abs(x) > l)
            flag = false;
    }

    if (y > 0) {
        if (y > u)
            flag = false;
    }
    else {
        if (abs(y) > d)
            flag = false;
    }

    cout << (flag ? Y : N) << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}