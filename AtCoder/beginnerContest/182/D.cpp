#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;

int main() {
    cin >> N;
    int x;
    vector<int> nums;
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        cin >> x;
        nums.push_back(x);
    }
    int res = 0;
    dp[0][0] = nums[0];
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if(0 < j)
                dp[i][j] = dp[i][j - 1] + nums[j];
            else
                dp[i][j] = dp[i - 1][i - 1] + nums[0];
            res = max(res, dp[i][j]);
        }
    }
    cout << res << endl;
}