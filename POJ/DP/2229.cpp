#include<cstdio>
#include<algorithm>

using namespace std;

int N, dp[1000001];

int main() {
    scanf("%d", &N);
    dp[1] = 1;
    for (int i = 2; i <= N; i++)
        if(i & 1)
            dp[i] = dp[i - 1];
        else {
            dp[i] = dp[i - 1] + dp[i / 2];
            dp[i] %= 1000000000;
        }
    printf("%d", dp[N]);
    return 0;
}