#include<cstdio>
#include<algorithm>
#define INF 0x7fffffff
#define MAX_N 1005
#define MAX_E 20005
using namespace std;
struct edge {
    int u, v, cost;
};
bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}
edge es[MAX_E];
int V, E; //顶点数、边数

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
    if (x == y)
        return;
        par[x] = y;
}

// 判断x和y是否属于同一个集合
bool same(int x, int y) {
    return find(x) == find(y);
}

int kruskal() {
    sort(es, es + E, comp); //从小到大
    init(V); //并查集
    int res = 0;
    for (int i = 0; i < E; i++) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}

int main() {
    int i,ans,z;
    while(scanf("%d%d",&V,&E)!=-1)
    {
        for(i=0;i<E;i++)
        {
            scanf("%d%d%d",&es[i].u,&es[i].v,&es[i].cost);
            es[i].cost = -es[i].cost;
        }
        ans=kruskal();
        int z = 0;
        for (int i = 0; i < V; i++)
            if(i == find(i))
                z++;
        if(z>1)
            printf("%d\n", -1);
        else
            printf("%d\n", -ans);
    }
    return 0;
}