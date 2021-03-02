#include <iostream>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;

int sum(int x) {
    int res = 0;
    while(x) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    if (n < 10) {
        cout << n << endl;
        return;
    } else if (45 < n) {
        cout << -1 << endl;
        return;
    }
    string s = "";
    int mx = 9;
    while (true) {
        s = to_string(mx) + s;
        mx--;
        string b = to_string(mx)+s;
        if (n <= sum(stoi(b))) {
            b = to_string(n - sum(stoi(s))) + s;
            cout << stoi(b) << endl;
            return;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}