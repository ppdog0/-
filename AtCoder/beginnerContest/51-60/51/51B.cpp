/*
 * Created Date: Saturday, September 26th 2020, 3:04:33 pm
 * Author: ppdog
 */

#include<iostream>
#include<algorithm>

using namespace std;

int K, S;

int main() {
    cin >> K >> S;

    long long ans = 0;

    for (int i = 0; i <= K; i++)
        for (int j = 0; j <= K; j++) {
            if(0<=S-i-j&&S-i-j<=K)
                ans++;
        }
    cout << ans << endl;
    return 0;
}

// int sum[2505 * 2505];

// int main() {
//     cin >> K >> S;
//     for (int i = 0; i <= K; i++)
//         for (int j = 0; j <= K; j++)
//             sum[i * (K + 1) + j] = i + j;

//     long long res = 0;
//     int size = (K + 1) * (K + 1);
//     sort(sum, sum + size);
//     for (int i = 0; i <= K; i++) {
//         int num = S - i;
//         res += upper_bound(sum, sum + size, num) - lower_bound(sum, sum + size, num);
//     }

//     cout << res << endl;
//     return 0;
// }