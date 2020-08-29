#include<cstdio>
#include<cmath>
#include<vector>
#define MAX_N 1005
using namespace std;
int N, D;
int X[MAX_N], Y[MAX_N];
vector<int> work;

int par[MAX_N]; // 父亲

// 初始化n个元素
void init(int n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
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
    par[x] = y;

}

// 判断x和y是否属于同一个集合
bool same(int x, int y) {
    return find(x) == find(y);
}

bool distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1-x2, 2) + pow(y1-y2, 2)) <= D;
}

int main() {
    scanf("%d%d", &N, &D);
    for (int i = 1; i <= N; i++) {
        scanf("%d%d", &X[i], &Y[i]);
    }
    init(N);
    char cmd[2];
    int x, y;
    while(scanf("%s", cmd)!=EOF) {
        if (cmd[0] == 'O') {
            scanf("%d", &x);
            work.push_back(x);
            for (int i = 0; i < work.size(); i++)
                if (same(x, work[i]))
                    continue;
                else
                    if (distance(X[x], Y[x], X[work[i]], Y[work[i]]))
                        unite(x, work[i]);
        } else {
            scanf("%d%d", &x, &y);
            if (same(x, y))
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }
    return 0;
}