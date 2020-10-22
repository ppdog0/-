// 判断是否有圈bellman-ford算法
// 最小生成树kruskal算法

#include<iostream>
#include<vector>

using namespace std;
const int MAX_N = 1001;

int N, M;

int par[MAX_N];

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

int main() {
    cin >> N >> M;
    vector<vector<int>> graph(N, vector<int>(N, 0));
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
}