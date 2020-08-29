struct edge {
    int u, v, cost;
};

bool comp(const edge& e1, const edge& e2) {
    return e1.cost < e2.cost;
}

edge es[MAX_E];
int V, E; //顶点数、边数

int kruskal() {
    sort(es, es + E, comp); //从小到大
    init_union_find(V); //并查集
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