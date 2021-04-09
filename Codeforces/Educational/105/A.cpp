#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

const string Y = "YES";
const string N = "NO";

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int count[3] = {0};
    for (int i = 0; i < n; i++) {
        count[s[i] - 'A']++;
    }

    // 退化情况
    int mx = max_element(count, count + 3) - count;
    if (count[mx] != n / 2 || 
    s[0] == s[n - 1] || 
    (s[0] != mx + 'A' && s[n - 1] != mx + 'A')) {
        cout << N << endl;
        return;
    }

    int l = 0, r = 0;
    if (s[0]-'A' == mx) {
        for (int i = 0; i < n; i++) {
            if (s[i] - 'A' == mx) l++;
            else r++;
            if (l < r) {
                cout << N << endl;
                return;
            }
        }
    } else {
            for (int i = 0; i < n; i++) {
                if (s[i]-'A' == mx) l++;
                else r++;
                if (r < l) {
                    cout << N << endl;
                    return;
                }
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

// #include <bits/stdc++.h>

// using namespace std;

// bool solve()
// {
//     string s;
//     cin >> s;
//     vector<int> d(3);
//     int x = s[0] — 'A';
//     int y = s.back() — 'A';
//     if (x == y)
//         return false;
//     d[x] = 1;
//     d[y] = -1;
//     if (count(s.begin(), s.end(), 'A' + x) == s.length() / 2)
//         d[3 ^ x ^ y] = -1;
//     else
//         d[3 ^ x ^ y] = 1;
//     int bal = 0;
//     for (char c : s)
//     {
//         bal += d[c — 'A'];
//         if (bal < 0)
//             return false;
//     }
//     return bal == 0;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         cout << (solve() ? "YES\n" : "NO\n");
//     }
// }