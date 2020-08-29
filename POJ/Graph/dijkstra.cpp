int cost[MAX_V][MAX_V]; //边
int d[MAX_V]; //顶点s出发的最短距离
bool used[MAX_V];
int V;

//从顶点s出发到各个顶点的最短距离
void dijkstra(int s) {
    fill(d, d + V, INF);
    fill(used, used + V, false);
    d[s] = 0;

    while(true)
    {
        int v = -1;
        for (int u = 0; u < V; u++)
        {
            if(!used[v]&&(v==-1||d[u]<d[v]))
                v = u;
        }
        if(v==-1)
            break;
        used[v] = true;
        for (int u = 0; u < V; u++)
        {
            d[u] = min(d[u], d[v] + cost[u][v]);
        }
    }
}