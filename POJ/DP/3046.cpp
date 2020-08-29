#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int T, A, S, B, ans = 0, num[1001], dp[1001][10001];
int main() {
    scanf("%d%d%d%d", &T, &A, &S, &B);
    int t;
    for (int i = 0; i < A; i++) {
        scanf("%d", &t);
        num[t]++;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= num[1]; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= T; i++) {
        for (int j = 0; j <= B; j++) {
            for (int k = 0; k <= num[i]; k++) {
                if(k <= j) {
                    dp[i][j] += dp[i - 1][j - k];
                    dp[i][j] %= 1000000;
                }
            }
        }
    }
    for (int i = S; i <= B; i++) {
        ans += dp[T][i];
        ans %= 1000000;
    }
    printf("%d\n", ans);
    return 0;
}

// #include<cstdio>
// using namespace std;
// #define MOD 1000000
// int T, A, S, B, ant[1005], dp[2][100000];
// int ans = 0;
// int main()
// {
//     scanf("%d%d%d%d", &T, &A, &S, &B);
//     int aa;
//     for (int i = 1; i <= A; i++)
//     {
//         scanf("%d", &aa);
//         ant[aa]++;
//     }
//     dp[0][0] = dp[1][0] = 1;
//     for (int i = 1; i <= T; i++)
//         for (int j = 1; j <= B; j++)
//             if (j - ant[i] - 1 >= 0) dp[i % 2][j] = (dp[(i - 1) % 2][j] + dp[i % 2][j - 1] - dp[(i - 1) % 2][j - ant[i] - 1] + MOD) % MOD;      //在取模时若出现了减法运算则需要先+Mod再对Mod取模，防止出现负数（如5%4-3%4为负数）
//             else dp[i % 2][j] = (dp[(i - 1) % 2][j] + dp[i % 2][j - 1]) % MOD;
//     for (int i = S; i <= B; i++)
//         ans = (ans + dp[T % 2][i]) % MOD;
//     printf("%d\n", ans);
//     return 0;
// }