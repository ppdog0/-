#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    vector<int> a(3), b(3);
    for (int &x : a)
        cin >> x;
    for (int &x : b)
        cin >> x;
    vector<pair<int, int>> ord;
    ord.push_back({0, 0});
    ord.push_back({0, 2});
    ord.push_back({1, 1});
    ord.push_back({1, 0});
    ord.push_back({2, 2});
    ord.push_back({2, 1});
    sort(ord.begin(), ord.end());
    int ans1 = INT32_MAX;
    do {
        vector<int> a1 = a, b1 = b;
        for (int i = 0; i < ord.size(); i++) {
            int cnt = min(a1[ord[i].first], b1[ord[i].second]);
            a1[ord[i].first] -= cnt;
            b1[ord[i].second] -= cnt;
        }
        int cur = min(a1[0], b[1]) + min(a1[1], b1[2]) + min(a1[2], b1[0]);
        ans1 = min(ans1, cur);
    } while (next_permutation(ord.begin(), ord.end()));
    int ans2 = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
    cout << ans1 << " " << ans2 << endl;
}

int main() {
    solve();
}

// int ma = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
// int mi = 0;
// while (true) {
//     int k1 = min_element(b, b + 3) - b;
//     int count = 0;
//     while ((a[k1]==0 && a[(k1+1)%3]==0) || b[k1]==0) {
//         k1 = (k1 + 1) % 3;
//         count++;
//         if (count >= 3) {
//             cout << n - mi << " " << ma << endl;
//             return;
//         }
//     }
//     int k2 = a[(k1 + 1) % 3] <= a[k1] ? k1 : (k1 + 1) % 3;
//     int x1 = min(b[k1], a[k2]);
//     b[k1] -= x1;
//     a[k2] -= x1;
//     mi += x1;
//     if (b[k1] != 0) {
//         k2 = k2 == k1 ? (k1 + 1) % 3 : k1;
//         x1 = min(a[k2], b[k1]);
//         b[k1] -= x1;
//         a[k2] -= x1;
//         mi += x1;
//     }
// }