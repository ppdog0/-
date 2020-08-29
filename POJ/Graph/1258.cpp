#include<cstdio>
#include<algorithm>
#define INF 0x7fffffff
#define MAX_V 105
using namespace std;
int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V;

int prim() {
    for (int i = 0; i < V; ++i) {
        mincost[i] = INF;
        used[i] = false;
    }
    mincost[0] = 0;
    int res = 0;

    while(true) {
        int v = -1;
        for (int u = 0; u < V; u++) {
            if(!used[u] && (v==-1 || mincost[u] < mincost[v]))
                v = u;
        }
        if(v==-1)
            break;
        used[v] = true;
        res += mincost[v];
        for (int u = 0; u < V; u++) {
            mincost[u] = min(mincost[u], cost[v][u]);
        }
    }
    return res;
}
int main() {
    while(~scanf("%d",&V))
    {
        int ans = 0;
        for(int i=0; i<V; i++)
            for(int j=0; j<V; j++)
            {
                scanf("%d",&cost[i][j]);
            }
        ans = prim();
        printf("%d\n",ans);
    }
    return 0;
}