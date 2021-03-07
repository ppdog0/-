// #include <iostream>
// #include <algorithm>
// #include <vector>

// using namespace std;
// using ll = long long;
// using ld = long double;

// void solve() {
//     ll n;
//     cin >> n;

//     vector<pair<int, ll>> val;
//     for (ll i = 2; i * i <= n; i++) {
//         int cnt = 0;
//         while (n % i == 0) {
//             cnt++;
//             n /= i;
//         }
//         if (cnt > 0) {
//             val.push_back({cnt, i});
//         }
//     }
//     if (n > 1) {
//         val.push_back({1, n});
//     }

//     sort(val.rbegin(), val.rend());
//     vector<ll> ans(val[0].first, val[0].second);
//     cout << endl;
//     for (int i = 1; i < val.size(); i++) {
//         for (int j = 0; j < val[i].first; j++) {
//             ans.back() *= val[i].second;
//         }
//     }

//     cout << ans.size() << endl;
//     for (auto it:ans)
//         cout << it << " ";
//     cout << endl;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    ll n;
    cin >> n;

    vector<pair<int,ll>> num;
    for (ll i = 2; i * i <= n; i++) {
        ll cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        num.push_back({cnt, i});
    }
    if (1 < n)
        num.push_back({1, n});
    sort(num.rbegin(), num.rend());
    vector<ll> ans(num[0].first, num[0].second);
    for (int i = 1; i < num.size(); i++) {
        for (int j = 0; j < num[i].first; j++)
            ans.back() *= num[i].second;
    }
    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}