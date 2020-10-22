// 01背包问题

// n个重量和价值分别为wi,vi的物品
// 从这些物品中挑选出总重量不超过W的物品
// 求所有挑选方案中价值总和的最大值

// dp[w]: 总重量不超过w时, 最大的价值
// dp[w + w[i]] = max(dp[w + w[i]], dp[w] + v[i]);
// 输出dp[W]

int W, n;
int w[max_n], v[max_n];
int dp[max_W];

void solve() {
    fill(dp, 0, dp + max_W);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < W; j++) {
            if(j + w[i] < W) {
                dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]); // 迭代次序错误，这应该算完全背包
            }
        }
    }
    cout << dp[W] << endl;
}

// 最长公共子序列

// 给定两个字符串s1s2...sn和t1t2...tm
// 求出这两个字符串最长的公共子序列长度

// dp[i][j]: s前i个字符和t前m个字符最长的子序列长度
// dp[i+1][j+1] = dp[i][j] + 1
// dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);

int n, m;
char s[max_n], t[max_m];
int dp[max_n][max_m];

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
}

// 01背包问题之2
// 问题同上，但w数值较大，远大于v
// 可考虑针对不同的价值计算最小的重量
// dp[v+v[i]] = min(dp[v+v[i]], dp[v]+w[i]);

int dp[MAX_N * MAX_V + 1];

void solve() {
    fill(dp, dp + MAX_N * MAX_V + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j + v[i] <= N * MAX_V + 1; j++) {
            dp[j + v[i]] = min(dp[j + v[i]], dp[j] + w[i]);
        }
}

// 多重部分和问题
// 有n种不同大小的数字ai，每种各mi个，判断是否可以选出若干数字使它们的和恰好为K

// 最长上升子序列问题
// 有一个长为n的数列a0,a1,...,an-1
// 求出这个序列中最长的上升子序列的长度(ai<aj, i<j)

// dp[i] = a[j] < a[i] ? max(dp[i],dp[j]+1) : dp[i]

int n;
int a[MAX_N];

int dp[MAX_N];

void solve() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) 
            if(a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        res = max(res, dp[i]);
    }
    cout << res << endl;
}


// 计数问题

// 划分数
// 有n个无区别的物品，将它们划分成不超过m组

// 多重组合数
// 有n种物品，第i种物品ai个。不同种类的物品可以相互区分但相同种类的无法区分
// 从这些物品取出m个，有多少种取法