#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#define INF 0x7fffffff
using namespace std;

const int MAX_N = 15;
const int MAX_M = 40;
// 输入
int n, m, a, b;
int t[MAX_N];
int d[MAX_M][MAX_M]; // 图的邻接矩阵表示

// dp[S][v]:=到达剩下的状态 车票集合为S 并且现在城市为v 所需要的最小花费
double dp[1 << MAX_N][MAX_M];

void solve() {
    for (int i = 0; i < 1 << n; i++) {
        fill(dp[i], dp[i] + m, INF);
    }
    dp[(1 << n) - 1][a - 1] = 0;
    double res = INF;
    for (int S = (1 << n) - 1; S >= 0; S--) {
        res = min(res, dp[S][b - 1]);
        for (int v = 0; v < m; v++) {
            for (int i = 0; i < n; i++) {
                if(S >> i & 1) {
                    for (int u = 0; u < m; u++) {
                        if(d[v][u] >= 0) {
                            // 使用车票i, 从v移动到u
                            dp[S & ~(1 << i)][u] = min(dp[S & ~(1 << i)][u], dp[S][v] + (double)d[v][u] / t[i]);
                        }
                    }
                }
            }
        }
    }
    if(res==INF) {
        // 无法到达
        printf("Impossible\n");
    } else {
        printf("%.3f\n", res);
    }
}

int main() {
    int p;
    while(scanf("%d%d%d%d%d", &n, &m, &p, &a, &b) != EOF) {
        if(!m && !n && !p && !a && !b)  break;
        fill(t, t + n, 0);
        for (int i = 0; i < n; i++) {
            scanf("%d", &t[i]);
        }
        int x, y;
        memset(d, -1, sizeof(d));
        for (int i = 0; i < p; i++) {
            scanf("%d%d", &x, &y);
            scanf("%d", &d[x-1][y-1]);
            d[y - 1][x - 1] = d[x - 1][y - 1];
        }
        solve();
    }
    return 0;
}