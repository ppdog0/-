#include<cstdio>
#include<algorithm>
const int INF = 1e9 + 1;
int N, M;
int G[305][305];
int movie[105];
using namespace std;
int main() {
    while(~scanf("%d%d", &N, &M))
    {
        for (int i = 0; i < 301; i++)
            for (int j = 0; j < 301; j++)
                if(i!=j)
                    G[i][j] = INF;
        while(M--)
        {
            int x;
            scanf("%d", &x);
            for (int i = 0; i < x; i++)
                scanf("%d", &movie[i]);
            for (int i = 0; i < x; i++)
                for (int j = i + 1; j < x; j++)
                    G[movie[i]][movie[j]] = G[movie[j]][movie[i]] = 1;
        }
        for(int k=1;k<=N;k++)
            for(int i=1;i<=N;i++)
                for(int j=1;j<=N;j++)
                    if(G[i][k]<INF&&G[k][j]<INF)
                        G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
        int ans = INF;
        for(int i=1;i<=N;i++) {
            int maxn=0;
            for(int j=1;j<=N;j++)
                if(i!=j)
                    maxn+=G[i][j];                 
            ans = min(ans,maxn);
        }
        printf("%d\n",(100*ans)/(N-1));
    }
    return 0;
}