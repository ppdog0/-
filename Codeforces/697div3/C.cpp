#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

void solve() {
    int A, B, k;
    cin >> A >> B >> k;
    int a[A] = {0}, b[B] = {0};
    vector<pair<int, int>> edges(k);
    for (auto &[x,y] : edges) {
        cin >> x;
    }
    for (auto &[x, y] : edges) {
        cin >> y;
    }
    for (auto &[x, y] : edges) {
        x--;
        y--;
        a[x]++;
        b[y]++;
    }
    ll ans = 0;
    for (auto &[x,y]:edges) {
        ans += k - (a[x] + b[y] - 1);
    }
    cout << ans / 2 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}