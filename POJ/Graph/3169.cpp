#include<cstdio>
#include<algorithm>
#define MAX_ML 10005
#define MAX_MD 10005
#define INF 0x7fffffff
using namespace std;
int N, ML, MD;
int AL[MAX_ML], BL[MAX_ML], DL[MAX_ML];
int AD[MAX_MD], BD[MAX_MD], DD[MAX_MD];
int d[1005];
int main() {
    scanf("%d%d%d", &N, &ML, &MD);
    for (int i = 0; i < ML;i++) {
        scanf("%d%d%d", &AL[i], &BL[i], &DL[i]);
    }
    for (int i = 0; i < MD;i++) {
        scanf("%d%d%d", &AD[i], &BD[i], &DD[i]);
    }
    fill(d, d + N, INF);
    d[0] = 0;

    // bellman-ford算法
    for (int k = 0; k < N; k++) {
        //从i+1到i的权值为0
        for (int i = 0; i + 1 < N; i++) {
            if (d[i+1] < INF)
                d[i] = min(d[i], d[i + 1]);
        }
        //从AL到BL的权值为DL
        for (int i = 0; i < ML; i++) {
            if(d[AL[i]-1] < INF){
                d[BL[i] - 1] = min(d[BL[i] - 1], d[AL[i] - 1] + DL[i]);
            }
        }
        //从BD到AD的权值为-DD
        for (int i = 0; i < MD; i++) {
            if(d[BD[i]-1] <INF)  {
                d[AD[i] - 1] = min(d[AD[i] - 1], d[BD[i] - 1] - DD[i]);
            }
        }
    }
    int res = d[N - 1];
    if(d[0]<0) {
        res = -1; //负圈
    } else if (res == INF) {
        res = -2;
    }
    printf("%d\n", res);
    return 0;
}