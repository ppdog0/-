#include<cstdio>
#include<algorithm>
using namespace std;
int N, dp[351][351];
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= i; j++) {
            scanf("%d", &dp[i][j]);
            dp[i][j] = dp[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
        }
    printf("%d\n", *(max_element(dp[N], dp[N] + N + 1)) );
    return 0;
}

// #include <algorithm>
// #include <stdio.h>
// using namespace std;
// int dp[355][355];
// int main(){
// 	int n;
// 	scanf("%d", &n);
// 	for(int i = 0; i < n; i++)
// 		for(int j = 0; j < i + 1; j++){
// 			scanf("%d", &dp[i][j]);
// 			if(i > 0){
// 				if(j - 1 >= 0)
// 					dp[i][j] = dp[i][j] + max(dp[i-1][j], dp[i - 1][j - 1]);
// 				else
// 					dp[i][j] = dp[i][j] + dp[i - 1][j];
// 			}
// 		}
// 	printf("%d\n", *(max_element(dp[n - 1], dp[n - 1] + n)));
// 	return 0;
// }