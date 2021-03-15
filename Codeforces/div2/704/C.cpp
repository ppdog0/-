#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int a[m], b[m];
    int l = 0, r = m - 1;
    for (int i = 0; i < n; i++) {
        if (s[i]==t[l])
            a[l++] = i;
        if (l==n)
            break;
    }
    for (int i = n-1; 0 <= i; i--) {
        if(s[i]==t[r])
            b[r--] = i;
        if (r<0)
            break;
    }
    int ans = 0;
    for (int i = 1; i < m; i++) {
        ans = max(ans, b[i] - a[i - 1]);
    }
    cout << ans << endl;
}

int main() {
    solve();
}

// int dp[n][m];
// for (int i = 0, j = 0; i < n && j < m; i++)
// {
//     if (s[i] == t[j])
//     {
//         dp[i + 1][j + 1] = dp[i][j] + 1;
//         j++;
//     }
//     else
//     {
//         dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
//     }
// }