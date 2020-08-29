#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX_N = 5e3 + 10;
//输入
int N;
int dir[MAX_N]; //牛的方向(0:F, 1:B)

int f[MAX_N]; //区间[i,i+K-1]是否反转

//固定K, 求对应的最小操作回数
//无解的话返回-1
int calc(int K) {
    memset(f, 0, sizeof(f));
    int res = 0;
    int sum = 0;
    for (int i = 0; i + K <= N; i++)
    {
        //计算区间[i,i+K-1]
        if((dir[i]+sum) % 2 !=0)
        {
            res++;
            f[i] = 1;
        }
        sum += f[i];
        if(i-K+1>=0)
            sum -= f[i - K + 1];
    }

    for (int i = N - K + 1; i < N; i++)
    {
        if((dir[i]+sum)%2!=0)
            return -1; //无解
        if(i-K+1>=0)
            sum -= f[i - K + 1];
    }

    return res;
}

void solve() {
    int K = 1, M = N;
    for (int k = 1; k <= N; k++)
    {
        int m = calc(k);
        if(0<=m&&m<M)
        {
            K = k;
            M = m;
        }
    }
    printf("%d %d\n", K, M);
}

int main() {
    scanf("%d", &N);
    char temp[2];
    for (int i = 0; i < N; i++)
    {
        scanf("%s", &temp);
        if(temp[0]=='F')
            dir[i] = 0;
        else
            dir[i] = 1;
    }
    solve();
    return 0;
}