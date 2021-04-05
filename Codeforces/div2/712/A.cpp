#include <iostream>
using namespace std;
using ll = long long;

const string Y = "YES";
const string N = "NO";

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int car=-1;
    for (int i = 0; i <= n-1; i++) {
        if (s[i] != 'a') {
            car = i;
            break;
        }
    }

    if (car == -1) {
        cout << N << endl;
        return;
    }

    for (int i = 0; i <= (n - 1) / 2; i++) {
        if (s[i] != s[n - i - 1]) {
            s.insert(n / 2, "a");
            cout << Y << endl;
            cout << s << endl;
            return;
        }
    }

    s.insert(n - car, "a");
    cout << Y << endl;
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