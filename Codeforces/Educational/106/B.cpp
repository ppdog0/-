#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const string Y = "YES";
const string N = "NO";

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int prev = -1;
    vector<int> pos0, pos1;
    for (int i = 0; i < n; i++) {
        if (s[i]-'0' == prev) {
            if (prev == 0) pos0.push_back(i);
            else pos1.push_back(i);
        }
        prev = s[i]-'0';
    }

    // for (auto x:pos0)
    //     cout << x << " ";
    // cout << endl;
    // for (auto x : pos1)
    //     cout << x << " ";

    if (pos0.empty() || pos1.empty()) {
        cout << Y << endl;
        return;
    }

    if (pos0[pos0.size()-1] < pos1[0])
        cout << Y << endl;
    else
        cout << N << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}