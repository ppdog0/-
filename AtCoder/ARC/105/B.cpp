#include<iostream>
#include<vector>

using namespace std;

int n;

int gcd(int a, int b) {
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main() {
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int res = nums[0];
    for (int i = 0; i < n; i++)
        res = gcd(res, nums[i]);
    cout << res << endl;
    return 0;
}

// #include<iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// int N;

// int main() {
//     cin >> N;
//     vector<long long> nums(N);
//     for (int i = 0; i < N; i++)
//         cin >> nums[i];
//     sort(nums.begin(), nums.end());
//     nums.erase(unique(nums.begin(), nums.end()), nums.end());
//     N = nums.size();
//     long long max_n = nums[N-1], min_n = nums[0];
//     while (min_n != max_n) {
//         nums[N - 1 ] = max_n - min_n;
//         int i = 0;
//         while((nums[N-1] < nums[N-2-i]) && (i < N-1) ) {
//             i++;
//         }
//         swap(nums[N - 1], nums[N - 1 - i]);
//         min_n = nums[0];
//         max_n = nums[N - 1];
//     }
//     cout << max_n << endl;
//     return 0;
// }