#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll = long long;

void solve() {
    int n, W;
    cin >> n >> W;
    //vector<int> count(20, 0);
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        //count[log2(x)]++;
        a.emplace_back(x);
        sum += x;
    }
    if (sum <= W) {
        cout << 1 << endl;
        return;
    }

    sort(a.begin(),a.end());

    int ans = 1;
    while (true) {
        int res = W;
        while (a.size()) {
            int k = lower_bound(a.begin(), a.end(), res) - a.begin();
            if (k == a.size())
                k--;
            if ((a[k] <= res) || (0 <= --k && a[k] <= res)) {
                res -= a[k];
                a.erase(a.begin() + k);
            }
            else 
                break;
        }

        if (a.size())
            ans++;
        else
            break;
    }

    cout << ans << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}

// int ans = 1, space = W;

// for (int i = 0; i < n; i++) {
//     int mx = -1;

//     for (int j = 19; 0 <= j; j--) {
//         if (count[j] && (1<<j) <= space) {
//             mx = j;
//             break;
//         }
//     }

//     if (mx == -1) {
//         space = W;
//         ans++;
//         for (int j = 19; 0 <= j; j--) {
//             if (count[j] && (1 << j) <= space) {
//                 mx = j;
//                 break;
//             }
//         }
//     }

//     count[mx]--;
//     space -= 1 << mx;
// }

// cout << ans << endl;