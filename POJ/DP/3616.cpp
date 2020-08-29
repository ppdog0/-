#include<cstdio>
#include<algorithm>
using namespace std;
int N, M, R, dp[1001];
struct node{
    int start, end, effc;
} t[1001];
int cmp(const node a, const node b) {
    if(a.start == b.start)
        return a.end < b.end;
    return a.start < b.start;
}
int main() {
    scanf("%d%d%d", &N, &M, &R);
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &t[i].start, &t[i].end, &t[i].effc);
        t[i].end += R;
    }
    sort(t, t + M, cmp);
    for (int i = 0; i <= M; i++)
    {
        dp[i] = t[i].effc;
        for (int j = 0; j < i; j++)
            if(t[j].end <= t[i].start)
                dp[i] = max(dp[i], dp[j] + t[i].effc);
    }
    printf("%d\n", *max_element(dp, dp+M));
    return 0;
}