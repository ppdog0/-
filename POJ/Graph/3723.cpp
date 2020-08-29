#include<cstdio>
#include<algorithm>
#include<utility> //pair
#include<queue> //priority_queue
#include<vector>
#define MAX_N 20005
#define MAX_R 50005
using namespace std;
struct edge {   int u, v, cost; };
int T, N, M, R;
edge G[MAX_R];

// 并查集
int par[MAX_N]; // 父亲
void init(int n) {
    for (int i = 0; i < n; i++)
        par[i] = i;
}
int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
        return;
    par[x] = y;
}
bool same(int x, int y) {
    return find(x) == find(y);
}

//kruskal
bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}
int kruskal() {
    sort(G, G + R, comp); //从小到大
    init(N+M); //并查集
    int res = 0;
    for (int i = 0; i < R; i++) {
        edge e = G[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &N, &M, &R);
        for (int i = 0; i < R; i++) {
            edge e;
            scanf("%d%d%d", &e.u, &e.v, &e.cost);
            e.v += N;
            e.cost = -e.cost;
            G[i] = e;
        }
        printf("%d\n", 10000*(N+M) + kruskal());
    }
    return 0;
}
