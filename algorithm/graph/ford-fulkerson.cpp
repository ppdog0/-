// ford-fulkerson算法
// 定义一条边的残存容量为：
//         | c_max-f if (u,v)属于E 
// c(u,v) =| f       if (v,u)属于E
//         | 0       其他

// 对于每一条边，既包括正向边和其容量，也包括反向边和其残存容量
// 每次搜索都会更新容量和残存容量
// 直到流不再增加时终止

#include<vector>
using namespace std;

// 表示边的结构体(终点、容量、反向边)
struct edge {
    int to, cap, rev;
};

vector<edge> G[MAX_V]; // 图的邻接表示，每个点对应一个vector边集
bool used[MAX_V]; // DFS中用到的访问标记

// 向图中增加一条从s到t容量为cap的边
void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, G[to].size()}); // 正向边
    G[to].push_back((edge){from, 0, G[from].size() - 1}); // 反向边
}

// 通过DFS寻找增广路
int dfs(int v, int t, int f) {
    if (v == t) return f;
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if(!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap)); // 容量和f的最小值
            if(d > 0) {
                e.cap -= d; // 容量
                G[e.to][e.rev].cap += d; // 残存容量，e为正向边: e.rev = e.to.size()-1; e为反向边: e.rev = e.from.size()
                return d;
            }
        }
    }
    return 0;
}

// 求解从s到t的最大流
int max_flow(int s, int t) {
    int flow = 0;
    for (;;) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if (f==0)
            return flow; // 流不再增加
        flow += f;
    }
}