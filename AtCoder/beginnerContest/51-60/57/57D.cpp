// 背包问题，用动态规划求解

// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// int N, A, B;

// int main() {
//     cin >> N >> A >> B;
//     vector<long long> values(N);

//     for (int i = 0; i < N; i++)
//         cin >> values[i];

//     sort(values.begin(), values.end());

//     double ans = 0;
//     for (int i = A; i <= B; i++) {
//         for (int j = values.size() - 1; 0 <= j - i + 1; j--) {
//             double sum = 0;
//             for (int k = j; j - i < k; k--) {
//                 sum += values[k];
//             }
//             ans = max(ans, sum / i);
//         }
//     }
//     cout << ans << endl;
// }