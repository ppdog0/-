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