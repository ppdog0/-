#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;

const string Y = "YES";
const string N = "NO";

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    int dp[n] = {0}; // 从n出发所取得的分数
    for (int i = n - 1; 0 <= i; i--) {
        dp[i] += a[i];
        int m = a[i] + i;
        if (m < n)
            dp[i] += dp[m];
    }
    cout << *max_element(dp, dp + n) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}