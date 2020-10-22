// 只算了最大值,没算方法数

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<map>

using namespace std;
const int max_n = 55;

int N, A, B;
long long nums[max_n], dp[max_n];

int main() {
    cin >> N >> A >> B;
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    double ans = 0;
    for (int k = A; k <= B; k++) {
        fill(dp, dp + N, 0);
        for (int i = 0; i < N; i++)
            for (int j = k; 1 <= j; j--)
                dp[j] = max(dp[j], dp[j - 1] + nums[i]);
        ans = max(ans, (double)dp[k] / k);
    }
    cout << fixed << setprecision(6) << ans << endl;
}