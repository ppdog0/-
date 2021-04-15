#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;
const int N = 2e5 + 1;
int dp[N];

void solve() {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    while (n) {
        int d = n % 10;
        ans += (d + m) < 10 ? 1 : dp[d + m - 10];
        ans %= Mod;
        n /= 10;
    }
    cout << ans << endl;
}

int main() {
    // 10
    for (int i = 0; i < 9; i++)
        dp[i] = 2;
    dp[9] = 3;
    for (int i = 10; i < N; i++)
        dp[i] = (dp[i - 9] + dp[i - 10]) % Mod;

    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}