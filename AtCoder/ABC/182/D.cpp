#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;

int main() {
    cin >> N;
    int nums[N];
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    long long ans = 0, res = 0;
    long long s = 0, x = 0;
    for (int i = 0; i < N; i++) {
        s += nums[i];
        res = max(res, s);
        ans = max(ans, x + res);
        x += s;
    }
    cout << ans << endl;
}

// #include <bits/stdc++.h>

// using namespace std;
// using ll = long long;

// #define rep(i, n) for (int i = 0; i < (int)(n); ++i)

// int main() {
//   int n;
//   cin >> n;
//   int a[n];
//   rep(i, n) cin >> a[i];
//   ll ans = 0;
//   ll x = 0, s = 0, mxs = 0;
//   rep(i, n) {
//     s += a[i];
//     mxs = max(mxs, s);
//     ans = max(ans, x + mxs);
//     x += s;
//   }

//   cout << ans << endl;
//   return 0;
// }
