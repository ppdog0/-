#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

typedef pair<int, int> P;

const int MAX_N = 303;
const int INF = 60001;

int M;
int panel[MAX_N][MAX_N];
int d[MAX_N][MAX_N];
int x, y, t;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int bfs(int nx, int ny) {
    if(panel[nx][ny]==0)
        return -1;

    queue<P> q;
    q.push(P(nx, ny));
    d[nx][ny] = 0;

    while(!q.empty()) {
        P p = q.front();
        q.pop();

        nx = p.first;
        ny = p.second;
        if(panel[nx][ny]==INF)
            return d[nx][ny];
        for (int i = 0; i < 4; i++) {
            int m = nx + dx[i];
            int n = ny + dy[i];
            if( (0<=m) && (0<=n) && (d[nx][ny] + 1<panel[m][n]) && (d[m][n]==INF) ) {
                q.push(P(m, n));
                d[m][n] = d[nx][ny] + 1;
            }
        }
    }
    return -1;
}

int main(void) {
    for (int i = 0; i < MAX_N; i++) {
        fill(panel[i], panel[i] + MAX_N, INF);
        fill(d[i], d[i] + MAX_N, INF);
    }

    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &x, &y, &t);
        panel[x][y] = min(panel[x][y], t);
        getchar();
        for (int j = 0; j < 4; j++) {
            int m = x + dx[j];
            int n = y + dy[j];
            if ( (0<=m) && (0<=n) )
                panel[m][n] = min(panel[m][n], t);
        }
    }

    printf("%d\n", bfs(0, 0));
    return 0;
}