#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using ll = long long;

const string Y = "YES";
const string N = "NO";

void solve() {
    int n;
    cin >> n;
    int nums[4];
    for (auto &x : nums)
        cin >> x;

    int m = 4;
    for (int mask = 0; mask < 1 << m; mask++) {
        int cpy[4];
        memcpy(cpy, nums, sizeof(nums));
        for (int i = 0; i < m; i++) {
            if ((mask >> i) & 1) {
                cpy[i]--, cpy[(i + m - 1) % m]--;
            }
        }
        if (*min_element(cpy, cpy + m) >= 0 && *max_element(cpy, cpy + m) <= n - 2) {
            cout << Y << endl;
            return;
        }
    }
    cout << N << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}

// #include <iostream>
// #include <algorithm>

// using namespace std;
// using ll = long long;

// const string Y = "YES";
// const string N = "NO";

// void solve() {
//     int n;
//     cin >> n;
//     int nums[4];
//     for (auto &x:nums)
//         cin >> x;
//     int m = 4;

//     // 退化情况

//     bool used[4] = {false};
//     for (int i = 0; i < m; i++) {
//         if (nums[i] == n) {
//             used[i] = true;
//             used[(i + m - 1) % m] = true;
//         }
//     }

//     for (int i = 0; i < m; i++) {
//         if (used[i]) {
//             nums[i]--, nums[(i + 1) % m]--;
//         }
//     }

//     if (*min_element(nums, nums+m) < 0) {
//         cout << N << endl;
//         return;
//     }

//     for (int i = 0; i < m; i++) {
//         int &x = nums[i], &y = nums[(i + 1) % m];
//         if (x > 0 && y > 0 && !used[i]) {
//             used[i] = true;
//             x--, y--;
//         }
//     }

//     if (*max_element(nums,nums+m) > n-2)
//         cout << N << endl;
//     else
//         cout << Y << endl;
// }

// int main() {
//     cin.sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
// }