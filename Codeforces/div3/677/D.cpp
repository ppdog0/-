#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;

const string Y = "YES";
const string N = "NO";

void dfs(int k, int n, bool visit[], int a[]) {
    visit[k] = true;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (!visit[i] && a[k] != a[i]) {
            flag = false;
            cout << k + 1 << " " << i + 1 << endl;
            dfs(i, n, visit, a);
        }
    }
    if (flag)
        return;
}

void solve() {
    int n;
    cin >> n;
    bool visit[n] = {false};
    int a[n];
    set<int> rec;
    for (auto &x : a) {
        cin >> x;
        rec.insert(x);
    }
    if (rec.size() == 1) {
        cout << N << endl;
        return;
    }
    cout << Y << endl;
    dfs(0, n, visit, a);
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}