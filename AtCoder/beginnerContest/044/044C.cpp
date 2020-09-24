#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, A;
long long dp[51][51 * 51]; // dp[i][j]:前i个数相加值为j的方案数

int main() {
    cin >> N >> A;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    dp[0][0] = 1;
    for (int k = 1; k <= N; k++) { //N个物品
        for (int i = k - 1; 0 <= i; i--) {
            for (int j = 0; j <= 50 * i; j++) {
                dp[i + 1][j + nums[k - 1]] += dp[i][j];
            }
        }
    }

    long long res = 0;
    for (int i = 1; i <= N; i++) {
        int val = i * A;
        res += dp[i][val];
    }
    cout << res << endl;
    return 0;
}