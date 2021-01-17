#include<iostream>

using namespace std;

int N;

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

int main() {
    cin >> N;
    long long ans = 1;
    for (int i = 2; i <= N; i++)
        ans = lcm(ans, i);
    cout << ans + 1 << endl;
}


// int used[31];

// int main() {
//     cin >> N;
//     long long ans = 1;
//     int res;
//     for (int i = N; 2 <= i; i--) {
//         res = i;
//         for (int k = i; 2 <= k; k--) {
//             if (used[k] && res % k == 0) {
//                 int y = res;
//                 int x = 0;
//                 while (2<=y && y%k==0) {
//                     x++;
//                     y /= k;
//                 }
//                 int m = min(x, used[k]);
//                 for (int n = 0; n < m; n++)
//                     res /= k;
//             }
//         }
//         if (2 <= res) {
//             ans *= res;
//             for (int j = res; 2 <= j; j--) {
//                 if (res % j == 0) {
//                     int y = res;
//                     while (2 <= y && y % j==0) {
//                         used[j]++;
//                         y /= j;
//                     }
//                 }
//             }
//         }
//     }
//     cout << ans + 1 << endl;
// }