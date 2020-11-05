// 找出满足条件的序列后，依次缩小前端，然后扩大后端

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
