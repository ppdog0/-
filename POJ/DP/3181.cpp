#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int N, K, dp[1001][101];
int main() {
    scanf("%d%d", &N, &K);
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= K; i++)
        dp[1][i] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            for (int k = 0; k * j <= i; k++)
            {
                dp[i][j] += dp[i - k * j][j - 1];
            }
        }
    }
    printf("%d\n", dp[N][K]);
    return 0;
}