#include<cstdio>
#include<algorithm>
using namespace std;
const int MAX_N = 1e5 + 10;

//输入
int C;
int n, S;
int a[MAX_N];

int sum[MAX_N + 1];

void solve() {
    int res = n + 1;
    int s = 0, t = 0, sum = 0;
    for (;;)
    {
        while(t<n&&sum<S)
        {
            sum += a[t++];
        }
        if(sum<S)
            break;
        res = min(res, t - s);
        sum -= a[s++];
    }
    if(res>n)
        res = 0;
    printf("%d\n", res);
}

int main() {
    scanf("%d", &C);
    while(C--)
    {
        scanf("%d%d", &n, &S);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        solve();
    }
    return 0;
}

// void solve() {
//     //计算sum
//     for (int i = 0; i < n; i++)
//     {
//         sum[i + 1] = sum[i] + a[i];
//     }

//     if(sum[n]<S)
//     {
//         printf("0\n");
//         return;
//     }

//     int res = n;
//     for (int s = 0; sum[s] + S <= sum[n]; s++)
//     {
//         //利用二分搜索求出t
//         int t = lower_bound(sum + s, sum + n, sum[s] + S) - sum;
//         res = min(res, t - s);
//     }

//     printf("%d\n", res);
// }