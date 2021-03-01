#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;

const int N = 2e5 + 1;

void solve()
{
    int n;
    cin >> n;
    int cnt[N] = {0};
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    int dp[N] = {0};
    for (int i = 1; i < N; i++) {
        dp[i] += cnt[i];
        for (int j = 2 * i; j < N; j += i) {
            dp[j] = max(dp[i], dp[j]);
        }
    }
    cout << (n - *max_element(dp, dp + N)) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}