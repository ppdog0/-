#include<iostream>

using namespace std;

int n, m, k;

int main() {
    cin >> n >> m >> k;
    int a[k];
    for (int i = 0; i < k; i++)
        cin >> a[i];
}

// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i, n) for (int i = 0; i < n; i++)
// using ll = long long;
// using P = pair<int, int>;

// const ll INF = 1e18;
// const int MX = 2005;

// struct L
// {
//     double a, b;
//     L(double a = 0, double b = 0) : a(a), b(b) {}
//     L operator+(const L &x) const
//     {
//         return L(a + x.a, b + x.b);
//     }
//     L operator-(const L &x) const
//     {
//         return L(a - x.a, b - x.b);
//     }
//     L operator/(int x) const
//     {
//         return L(a / x, b / x);
//     }
// };

// int main()
// {
//     int n, m, k;
//     cin >> n >> m >> k;
//     vector<int> f(n + 1);
//     rep(i, k)
//     {
//         int p;
//         cin >> p;
//         f[p] = 1;
//     }
//     vector<L> dp(n + 1);
//     L s;
//     for (int i = n - 1; i >= 0; i--)
//     {
//         if (f[i])
//             dp[i] = L(1, 0);
//         else
//             dp[i] = s / m + L(0, 1);
//         s = s + dp[i];
//         if (i + m <= n)
//             s = s - dp[i + m];
//     }
//     double a = dp[0].a, b = dp[0].b;
//     if (a + 1e-6 > 1)
//     {
//         cout << -1 << endl;
//         return 0;
//     }
//     double ans = b / (1 - a);
//     cout << ans << endl;
//     return 0;
// }