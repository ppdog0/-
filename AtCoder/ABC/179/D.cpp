#include<iostream>
#include<vector>
#include<cstring>

using namespace std;
const int MOD = 998244353;

int N, K;
vector<pair<int, int>> A;

int main() {
    cin >> N >> K;
    int x, y;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        A.push_back(make_pair(x, y));
    }

    long long dp[N] = {0};
    long long sum[N+1] = {0};

    dp[0] = 1;
    sum[1] = sum[0] + dp[0];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int l, r;
            l = A[j].first;
            r = A[j].second;
            int left, right;
            left = max(i - r, 0);
            right = i - l;
            if (0 <= right) {
                dp[i] += sum[right + 1] - sum[left];
                dp[i] %= MOD;
            }
        }
        sum[i + 1] = sum[i] + dp[i];
    }
    cout << dp[N - 1] << endl;
}

// int main() {
//     cin >> N >> K;
//     int l, r;
//     long long dp[N+1]; // 到N的路径数
//     for (int i = 0; i < K; i++) {
//         cin >> l >> r;
//         for (int j = l; j <= r; j++)
//             record.push_back(j);
//     }
//     memset(dp, 0, sizeof(dp));
//     dp[1] = 1;
//     for (int i = 1; i <= N; i++) {
//         for (int k = 0; k < record.size(); k++) {
//             if (record[k] + i <= N)
//                 dp[i + record[k]] += dp[i];
//         }
//     }
//     cout << dp[N] % MOD << endl;
// }

// ***************************************************

// #include <bits/stdc++.h>

// #define rep(i, a) for (int i = 0; i < (a); i++)

// typedef pair<int, int> P;
// typedef long long ll;

// const int INF = 1001001001;
// const int MOD = 998244353;
// const double PI = acos(-1);

// int main()
// {
//     int N, K;
//     cin >> N >> K;
//     vector<pair<int, int>> A;
//     rep(i, K)
//     {
//         int l, r;
//         cin >> l >> r;
//         A.push_back(make_pair(l, r));
//     }

//     vector<ll> dp(N, 0);
//     vector<ll> sum(N + 1, 0);

//     rep(i, N)
//     {
//         if (i == 0)
//         {
//             dp[i] = 1;
//             sum[i + 1] = sum[i] + dp[i];
//         }
//         else
//         {
//             rep(k, K)
//             {
//                 int l, r;
//                 l = A[k].first;
//                 r = A[k].second;
//                 int left, right;
//                 left = max(i - r, 0);
//                 right = i - l;
//                 if (right >= 0)
//                 {
//                     dp[i] += sum[right + 1] - sum[left];
//                     dp[i] %= MOD;
//                 }
//             }
//             sum[i + 1] = sum[i] + dp[i];
//         }
//     }
//     cout << dp[N - 1] << endl;
// }
