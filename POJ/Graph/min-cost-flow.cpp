// prevv 和 preve 保存已经使用的路
// 对于每一次循环，循环条件为f > 0，首先设置最小距离为INF
// 然后从0点开始，更新相连的边，从中找到最小费用的边，保存使用的边和最小距离
// 距离为INF，表明已经没有增广路径，直接退出
// 否则，使用这条路径的最小容量
// 计算费用，缩小流，增加反向路径

#include<vector>
using namespace std;

// 用于表示边的结构体(终点、容量、费用、反向边)
struct edge {
    int to, cap, cost, rev;
};

int V; // 顶点数
vector<edge> G[MAX_V]; // 图的邻接表表示
int dist[MAX_V]; // 最短距离
int prevv[MAX_V], preve[MAX_V]; // 最短路中的前驱节点和对应的边

// 向图中增加一条从s到t容量为cap的边
void add_edge(int from, int to, int cap, int cost) {
    G[from].push_back((edge){to, cap, cost, G[to].size()});
    G[to].push_back((edge){from, 0, -cost, G[from].size() - 1});
}

// 求解从s到t流量为f的最小费用流
// 如果不能再增广则返回-1
int min_cost_flow(int s, int t, int f) {
    int res = 0;
    while(f > 0) {
        // 利用Bellman-Ford算法求s到t的最短路
        fill(dist, dist + V, INF);
        dist[s] = 0;
        bool update = true;
        while(update) {
            update = false;
            for (int v = 0; v < V; v++) {
                if(dist[v] == INF)
                    continue;
                for (int i = 0; i < G[v].size(); i++) {
                    edge &e = G[v][i];
                    if(e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
                        dist[e.to] = dist[v] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        update = true;
                    }
                }
            }
        }
        if(dist[t] == INF) {
            // 不能再增广
            return -1;
        }

        // 沿s到t的最短路尽量增广
        int d = f;
        for (int v = t; v != s; v = prevv[v]) {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * dist[t];
        for (int v = t; v != s; v = prevv[v]) {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}