#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans(n);
    vector<int> pos0, pos1;
    for (int i = 0; i < n; i++) {
        int newpos = pos0.size() + pos1.size();
        if (s[i] == '0') {
            if (pos1.empty()) {
                pos0.push_back(newpos);
            } else {
                newpos = pos1.back();
                pos1.pop_back();
                pos0.push_back(newpos);
            }
        } else {
            if (pos0.empty()) {
                pos1.push_back(newpos);
            } else {
                newpos = pos0.back();
                pos0.pop_back();
                pos1.push_back(newpos);
            }
        }
        ans[i] = newpos;
    }
    cout << pos0.size() + pos1.size() << endl;
    for (auto it:ans)
        cout << it + 1 << " ";
    cout << endl;
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
// #include <vector>

// using namespace std;
// using ll = long long;

// void solve() {
//     int n;
//     cin >> n;
//     string s;
//     cin >> s;

//     // [l,r]
//     vector<pair<int, int>> nums[2];
//     int res = 0, prev = s[0]-'0';
//     int l = 0, r = 0;
//     int mi = n;
//     for (int i = 0; i < n; i++) {
//         int x = s[i] - '0';
//         res += x;

//         if (x != prev) {
//             nums[prev].emplace_back(l, r);
//             int len = r - l;
//             mi = min(mi, len);
//             l = r;
//             prev = x;
//         }
//         r++;
//     }
//     nums[prev].emplace_back(l, r);
//     mi = min(mi, r - l);

//     // 退化情况
//     if (res == n || 0) {
//         cout << n << endl;
//         for (int i = 0; i < n; i++)
//             cout << i + 1 << " ";
//         cout << endl;
//         return;
//     }

//     int count = 0, visit[n + 1] = {0}; // 位置
//     int cur = 0; // 所在链
//     int y = s[0] - '0'; // 选择数
//     while (true) {
//         if (count == n)
//             break;

//         cur++;
//         int c1 = 0, c2 = 0; // 区间选取
//         while (true) { // 一次寻找一条链
//             int c;
//             if (y == 0) c = c1;
//             else c = c2;

//             if (nums[y].size() <= c) {
//                 y = (y + 1) % 2;
//                 break;
//             }

//             int m = nums[y][c].second - nums[y][c].first;
//             if (m < cur) {
//                 nums[y].erase(nums[y].begin() + c);
//                 continue;
//             }

//             // c++;
//             if (y == 0) c1++;
//             else c2++;

//             int pos = nums[y][c].first + cur - 1;
//             visit[pos] = cur; // 选的位置
//             count++;
//             y = (y + 1) % 2; // 下个数字
//         }
//     }

//     cout << cur << endl;
//     for (int i = 0; i < n; i++)
//         cout << visit[i] << " ";
//     cout << endl;

//     // 一般情况
//     // int y = s[0] - '0';
//     // int c1 = 0, c2 = 0; // 区间选取
//     // while (true) {
//     //     int c;
//     //     if (y == 0) c = c1;
//     //     else c = c2;

//     //     //int m = 
//     //     if (m < cur) {
//     //         nums[y].erase(nums[y].begin() + c);
//     //         continue;
//     //     }

//     //     int len = nums[y][c].second - nums[y][c].first;
//     //     mi = min(mi, len);
//     //     y = (y + 1) % 2;
//     // }
// }

// int main() {
//     cin.sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
// }

// // int count = 0, visit[n + 1] = {0}; // 位置
// // int cur = 0; // 所在链
// // int y = s[0] - '0'; // 选择数
// // while (true) {
// //     if (count == n)
// //         break;

// //     cur++;
// //     int c1 = 0, c2 = 0; // 区间选取
// //     while (true) { // 一次寻找一条链
// //         int c;
// //         if (y == 0) c = c1;
// //         else c = c2;

// //         if (nums[y].size() <= c) {
// //             y = (y + 1) % 2;
// //             break;
// //         }

// //         int m = nums[y][c].second - nums[y][c].first;
// //         if (m < cur) {
// //             nums[y].erase(nums[y].begin() + c);
// //             continue;
// //         }

// //         // c++;
// //         if (y == 0) c1++;
// //         else c2++;

// //         int pos = nums[y][c].first + cur - 1;
// //         visit[pos] = cur; // 选的位置
// //         count++;
// //         y = (y + 1) % 2; // 下个数字
// //     }
// // }

// // cout << cur << endl;
// // for (int i = 0; i < n; i++)
// //     cout << visit[i] << " ";
// // cout << endl;