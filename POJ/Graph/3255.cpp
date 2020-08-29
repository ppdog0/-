#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
#define MAX_N 5002
#define INF 0x7fffffff
using namespace std;
typedef pair<int, int> P;
struct edge {  int to, cost; };
int N, R;
vector<edge> G[MAX_N];
int dist[MAX_N], dist2[MAX_N];
int main() {
    scanf("%d%d", &N, &R);
    for (int i = 1; i <= R; i++) {
        int u, v; edge e;
        scanf("%d%d%d", &u, &v, &e.cost);
        e.to = v;
        G[u].push_back(e);
        e.to = u;
        G[v].push_back(e);
    }
    priority_queue<P, vector<P>, greater<P>> que;
    fill(dist, dist + MAX_N, INF);
    fill(dist2, dist2 + MAX_N, INF);
    dist[1] = 0;
    que.push(P(0, 1));
    while(!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second, d = p.first;
        if (dist2[v] < d)
            continue;
        for (int i = 0; i < G[v].size(); i++) {
            edge &e = G[v][i];
            int d2 = d + e.cost;
            if (dist[e.to] > d2) {
                swap(dist[e.to], d2);
                que.push(P(dist[e.to], e.to));
            }
            if (d2 != INF && dist2[e.to] > d2 && dist[e.to] < d2) {
                dist2[e.to] = d2;
                que.push(P(dist2[e.to], e.to));
            }
        }
    }
    printf("%d\n", dist2[N]);
    return 0;
}