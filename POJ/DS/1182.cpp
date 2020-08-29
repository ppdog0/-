#include<cstdio>
#include<algorithm>
#define MAX_K 100001
#define MAX_N 50001
using namespace std;
int N, K;
int D[MAX_K], X[MAX_K], Y[MAX_K];
int par[MAX_N * 3]; // 父亲
int nrank[MAX_N * 3]; // 树的高度

// 初始化n个元素
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        nrank[i] = 0;
    }
}

// 查询树的根
int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

// 合并x和y所属的集合
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    if (nrank[x] < nrank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (nrank[x] == nrank[y])
            nrank[x]++;
    }
}

// 判断x和y是否属于同一个集合
bool same(int x, int y) {
    return find(x) == find(y);
}

int main() {
    scanf("%d%d", &N, &K);
    for (int i = 0; i < K; i++) {
        scanf("%d%d%d", &D[i], &X[i], &Y[i]);
    }
    init(N * 3);

    int ans = 0;
    for (int i = 0; i < K; i++) {
        int d = D[i];
        int x = X[i] - 1, y = Y[i] - 1;

        if (x < 0 || N <= x || y < 0 || N <= y) {
            ans++;
            continue;
        }

        if (d == 1) {
            if (same(x, y + N) || same(x , y + 2 * N)) {
                ans++;
            }
            else {
                unite(x, y);
                unite(x + N, y + N);
                unite(x + N * 2, y + N * 2);
            }
        } else {
            if (same(x, y) || same(x, y + 2 * N)) {
                ans++;
            }
            else {
                unite(x, y + N);
                unite(x + N, y + N * 2);
                unite(x + N * 2, y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}