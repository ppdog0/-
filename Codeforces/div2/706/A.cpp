#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

const string Y = "YES";
const string N = "NO";

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int same = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n-i-1])
            same++;
        else
            break;
    }
    if (k == 0) {
        cout << Y << endl;
        return;
    }
    if (n % 2 == 0) {
        if (k == n / 2) {
            cout << N << endl;
            return;
        }
    }
    if (k <= same)
        cout << Y << endl;
    else
        cout << N << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}