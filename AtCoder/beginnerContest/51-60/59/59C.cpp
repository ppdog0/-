#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int n;

int main() {
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    long long curr = 0, prev = 0;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        prev = curr;
        curr += nums[i];
        if (curr == 0) {
            ans++;
            if(prev<0)
                curr++;
            else
                curr--;
        }
        if (0 < curr * prev) {
            ans += abs(curr) + 1; 
            if(prev<0)
                curr = 1;
            else
                curr = -1;
        }
    }
    cout << ans << endl;
}

// #include<iostream>
// #include<vector>
// #include<cmath>

// using namespace std;

// int n;

// int main() {
//     cin >> n;
//     vector<long long> nums(n);
//     for (int i = 0; i < n; i++)
//         cin >> nums[i];
//     bool flag = false;
//     long long sum = 0;
//     long long ans1 = 0;
//     for (int i = 0; i < n; i++) {
//         sum += nums[i];
//         if(flag) {
//             if(0 <= sum) {
//                 ans1 += sum + 1;
//                 sum = -1;
//             }
//         } else if(sum <= 0) {
//             ans1 += 1 - sum;
//             sum = 1;
//         }
//         flag = !flag;
//     }
//     sum = 0;
//     long long ans2 = 0;
//     flag = true;
//     for (int i = 0; i < n; i++) {
//         sum += nums[i];
//         if(flag) {
//             if(0 <= sum) {
//                 ans2 += sum + 1;
//                 sum = -1;
//             }
//         } else if(sum <= 0) {
//             ans2 += 1 - sum;
//             sum = 1;
//         }
//         flag = !flag;
//     }
//     cout << min(ans1, ans2) << endl;
// }