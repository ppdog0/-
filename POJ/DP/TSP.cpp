// 输入
int n;
int d[MAX_N][MAX_N];

int dp[1 << MAX_N][MAX_N];

// 已经访问过的节点集合为S, 当前位置为v
int rec(int S, int v) {
    if(dp[S][v] >= 0) {
        return dp[S][v];
    }

    if (S == (1 << n) - 1 && v == 0) {
        return dp[S][v] = 0;
    }

    int res = INF;
    for (int u = 0; u < n; u++) {
        if(!(S >> u & 1)) {
            // 下一步移动到顶点u
            res = min(res, rec(S | 1 << u, u) + d[v][u]);
        }
    }
    return dp[S][v] = res;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    printf("%d\n", rec(0, 0);)
}