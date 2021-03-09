#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    set<ll> s;
    int h1, h2;
    ll cur = 0;
    s.insert(0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        h1 = s.size();
        cur += x;
        s.insert(cur);
        h2 = s.size();

        if (h1 == h2) {
            ans++;
            cur = x;
            s.clear();
            s.insert(0);
            s.insert(cur);
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
}

// #include <iostream>
// #include <vector>

// using namespace std;
// using ll = long long;
// using ld = long double;

// void solve() {
//     int n;
//     cin >> n;
//     ll sum[n + 1]; // 前n个数之和
//     sum[0] = 0;
//     for (int i = 0; i < n; i++) {
//         int x;
//         cin >> x;
//         sum[i + 1] = sum[i] + x;
//     }

//     int ans = 0;
//     vector<pair<int, int>> pos;
//     for (int k = 2; k <= n; k++) {
//         for (int i = 0; i + k <= n; i++) {
//             int curSum = sum[i + k] - sum[i];
//             if (curSum == 0) {
//                 bool flag = true;
//                 for (int j= 0; j < pos.size(); j++) {
//                     int x = pos[j].first, y = pos[j].second;
//                     int mx = max(x, i), mi = min(y, i + k - 1);
//                     if (mx < mi) {
//                         pos.erase(pos.begin() + j);
//                         pos.emplace_back(mx, mi);
//                         flag = false;
//                         break;
//                     }
//                 }
//                 if (flag) {
//                     pos.emplace_back(i, i + k - 1);
//                     ans++;
//                 }
//             }
//         }
//     }
//     cout << ans << endl;
// }

// int main() {
//     solve();
// }

/****************************************************8*/

// priority_queue<int, vector<int>, greater<int>> L;
// priority_queue<int, vector<int>, less<int>> R;

// if ((L.empty() || i + k - 1 <= L.top()) ||
//     (R.empty() || R.top() <= i))
// {
//     // cout << i << " " << i + k - 1<<endl;
//     ans++;
//     L.push(i);
//     R.push(i + k - 1);
// }

// int ans = 0;
// int curSum = 0;
// int l = 0, r = 0;
// while (true) {
//     if (n <= r)
//         break;
//     curSum += a[r];
//     if (curSum == 0)
//         ans++;
//     while (l < r && curSum != 0) {
//         curSum -= a[l];
//         l++;
//     }
//     r++;
// }