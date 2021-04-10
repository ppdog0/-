#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int a,b;
    cin >> a >> b;
    string s;
    cin >> s;
    ll n = a + b;

    ll rec = 0;
    ll count[2]={0};
    vector<int> pos;
    for (int i = 0; i < n / 2; i++) {
        if (s[i]!=s[n-i-1]) {
            if (s[i] == '?') {
                s[i] = s[n - i - 1];
            } else if (s[n - i - 1] == '?') {
                s[n - i - 1] = s[i];
            } else {
                cout << -1 << endl;
                return;
            }
            count[s[i] - '0'] += 2;
        } else if (s[i] == '?') {
            rec++;
            pos.push_back(i);
        } else {
            count[s[i] - '0'] += 2;
        }
    }

    bool flag=false;
    if (n % 2 == 0) {
        if (a % 2 != 0 || b % 2 != 0) {
            cout << -1 << endl;
            return;
        }
    } else {
        if (s[n/2] == '?') {
            flag = true;
            rec++;
        } else {
            count[s[n / 2] - '0']++;
        }
    }
    if (a < count[0] || b < count[1]) {
        cout << -1 << endl;
        return;
    }

    ll d1 = a - count[0], d2 = b - count[1];
    if (!flag) {
        if (d1%2==1 || d2%2==1) {
            cout << -1 << endl;
            return;
        }
    }

    d1 = (d1 + 1) / 2, d2 = (d2 + 1) / 2;
    if (d1 + d2 == rec) {
        int t1 = d1, t2 = d2;
        if (flag) {
            if (a%2==1) {
                t1--;
                s[n / 2] = '0';
            } else {
                t2--;
                s[n / 2] = '1';
            }
        }
        for (int i = 0; i < pos.size(); i++) {
            if (t1 > 0) {
                s[pos[i]] = s[n - pos[i] - 1] = '0';
                t1--;
            } else {
                s[pos[i]] = s[n - pos[i] - 1] = '1';
                t2--;
            }
        }
    } else {
        cout << -1 << endl;
        return;
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