// 01背包问题
// 对于n个物品，重量和价值分别为wi,vi
// 从中选取物品，总重量不超过W，求价值的最大值

// 使用蛮力法
// next_permutation

// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;
// const int max_n = 100;

// int n, W;
// int w[max_n], v[max_n];

// int main() {
//     cin >> n >> W;
//     for (int i = 0; i < n; i++) {
//         cin >> w[i] >> v[i];
//     }
//     int ans = 0;
//     for (int i = 1; i < 1 << n; i++) {
//         int wp = 0, vp = 0;
//         for (int j = 0; j < n; j++) {
//             if(i & (1<<j)) {
//                 wp += w[j];
//                 vp += v[j];
//             }
//         }
//         if(wp < W)
//             ans = max(ans, vp);
//     }
//     cout << ans << endl;
// }

// 使用动态规划
// dp[w]:总重量不超过w的物品，价值的最大值
// dp[w+w[i]]==max(dp[w+w[i]], dp[w]+v[i]);
// 复杂度o(nsum(W/w[i]))=o(nW)

// #include<iostream>
// #include<cstring>
// #include<algorithm>

// using namespace std;
// const int max_n = 100;

// int n, W;
// int w[max_n], v[max_n];
// int dp[max_n];

// int main() {
//     memset(dp, 0, sizeof(dp));
//     cin >> n >> W;
//     for (int i = 0; i < n; i++)
//         cin >> w[i] >> v[i];
//     for (int i = 0; i < n; i++) {
//         for (int j = W; w[i] <= j; j--) {
//             dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
//         }
//     }
//     // for (int i = 0; i < n; i++) {
//     //     for (int j = 0; j + w[i] <= W; j++) {
//     //         dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
//     //     }
//     // }
//     cout << dp[W] << endl;
// }

// 旅行商问题

// 暴力枚举

// #include<iostream>
// #include<algorithm>

// using namespace std;

// const int INF = 10e7;
// int n = 4;
// //存储城市之间的距离
// int g[4][4] = { {INF,3,   6,  7},
//                 {12, INF, 2,  8},
//                 {9,  6,   INF,2},
//                 {3,  7,   6,  INF} };
// int place[4] = {0, 1, 2, 3};

// int main () {
//     // cin >> n;
//     int ans = INF;
//     do {
//         int cost = 0;
//         for (int i = 0; i < n-1; i++)
//             if (g[place[i]][place[i+1]] != INF)
//                 cost += g[place[i]][place[i + 1]];
//         cost += g[place[3]][place[0]];
//         ans = min(ans, cost);
//     } while (next_permutation(place, place + n));
//     cout << ans << endl;
// }

// 动态规划
 
#include<iostream>
#include<algorithm>

using namespace std;

const int INF = 10e7;
int n = 4;
//存储城市之间的距离
int g[4][4] = { {INF,3,   6,  7},
                {12, INF, 2,  8},
                {9,  6,   INF,2},
                {3,  7,   6,  INF} };
int dp[1 << 4][4];

int main() {
    for (int S = 0; S < 1 << n; S++)
        fill(dp[S], dp[S] + n, INF);
    dp[(1 << n) - 1][0] = 0;
    for (int S = (1 << n) - 2; 0 <= S; S--)
        for (int v = 0; v < n; v++)
            for (int u = 0; u < n; u++) {
                if( !(S >> u & 1) ) {
                    dp[S][v] = min(dp[S][v], dp[S | 1 << u][u] + g[v][u]);
                }
            }
    cout << dp[0][0] << endl;
}