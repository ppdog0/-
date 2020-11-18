int par[MAX_N]; // 父亲
int nrank[MAX_N]; // 树的高度

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


// 化简版

// void init() {
//     for (int i = 0; i < n; i++) {
//         par[i] = i;
//     }
// }

// void unite(int x, int y) {
//     int x = find(x), y = find(y);
//     if(x != y)
//         par[y] = x;
// }

// int find(int x) {
//     if(x == par[x])
//         return x;
//     return par[x] = find(x);
// }

// bool same(int x, int y) {
//     return find(x) == find(y);
// }
