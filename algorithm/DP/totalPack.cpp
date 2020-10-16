// 完全背包问题

// 有n种重量和价值分别为wi,vi的物品
// 从这些物品中挑选总重量不超过W的物品
// 求挑选物品价值总和的最大值

// 同一种类的物品可以选择任意多件

// dp[w + k * w[i]] = max(dp[w + k * w[i]], dp[w] + k * v[i]);

int n;
int w[max_n], v[max_n];
int dp[max_W];

void solve() {
    fill(dp, 0, dp + W);
    for (int i = 0; i < n; i++)
        for (int j = 0; j + w[i] < W; j++) {
            for (int k = 0; j + k * w[i] < W; k++) {
                dp[j + k * w[i]] = max(dp[j + k * w[i]], dp[j] + k * v[i]);
            }
        }
    cout << dp[W] << endl;
}