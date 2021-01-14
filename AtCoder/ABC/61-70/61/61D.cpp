// bellman-ford算法
// 1. 判断是否有负圈 2. 更新最长路径

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const long long INF = -1e9-5;
const int MAX_N = 1005;
struct edge {
    int u, v;
    long long cost;
};

int N, M;
long long d[MAX_N];
edge graph[MAX_N];

bool find_negative_loop() {
    fill(d, d + N + 1, INF);
    d[1] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            edge e = graph[j];
            if( d[e.u] != INF && d[e.v] < d[e.u] + e.cost) {
                d[e.v] = d[e.u] + e.cost;

                if (i == N - 1)
                    return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> graph[i].u >> graph[i].v >> graph[i].cost;
    }
    if (find_negative_loop())
        cout << "inf" << endl;
    else
        cout << d[N] << endl;
}

// long long longest_path() {
//     fill(d, d + N + 1, INF);
//     d[1] = 0;
//     while (true) {
//         bool update = false;
//         for (int i = 0; i < M; i++) {
//             edge e = graph[i];
//             if (d[e.u] != INF && d[e.v] < d[e.u] + e.cost) {
//                 d[e.v] = d[e.u] + e.cost;
//                 update = true;
//             }
//         }
//         if (!update)
//             break;
//     }
//     return d[N];
// }

// int par[MAX_N];

// bool comp(const edge& e1, const edge& e2) {
//     return e2.cost < e1.cost;
// }

// void init(int n) {
//     for (int i = 0; i < n; i++)
//         par[i] = i;
// }

// int find(int x) {
//     if (par[x] == x) {
//         return x;
//     } else {
//         return par[x] = find(par[x]);
//     }
// }

// void unite(int x, int y) {
//     x = find(x);
//     y = find(y);
//     if (x == y)
//         return;
//     par[x] = y;
// }

// bool same(int x, int y) {
//     return find(x) == find(y);
// }

// long long kruskal() {
//     sort(graph, graph + M, comp);
//     init(N);
//     long long res = 0;
//     for (int i = 0; i < M; i++) {
//         edge e = graph[i];
//         if(!same(e.u,e.v)) {
//             unite(e.u, e.v);
//             res += e.cost;
//         }
//     }
//     return res;
// }