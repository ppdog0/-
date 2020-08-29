#include<cstdio>
#include<algorithm>
#include<cmath>
#define INF 0x7fffffff
using namespace std;
const int MAX_N=10000+100;
int N, K;
double L[MAX_N];

//判断是否满足条件
bool C(double x) {
    int num = 0;
    for (int i = 0; i < N; i++)
        num += (int)(L[i] / x);
    return num >= K;
}

void solve() {
    double lb = 0, ub = INF;

    for (int i = 0; i < 100; i++)
    {
        double mid = (lb + ub) / 2;
        if(C(mid))
            lb = mid;
        else
            ub = mid;
    }
    printf("%.2f\n", floor(ub * 100) / 100);
}

int main()
{
    while(scanf("%d%d",&N,&K)!=EOF){
        for(int i=0;i<N;i++)
            scanf("%lf",&L[i]);
        solve();
    }
    return 0;
}