#include<cstdio>
#include<algorithm>
using namespace std;
int T, W, t[1005], dp[1005][35];
int main() {
    scanf("%d%d", &T, &W);
    for (int i = 1; i <= T; i++)
        scanf("%d", &t[i]);
    for (int i = 1; i <= T; i++) {
        for (int j = 0; j <= W; j++) {
            if(j == 0)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]);
            if(j%2 + 1 == t[i])
                dp[i][j]++;
        }
    }
    printf("%d\n", *(max_element(dp[T], dp[T] + 31 + 1)) );
    return 0;
}