#include<iostream>
#include<vector>

using namespace std;

int N;
long long x;

int main() {
    cin >> N >> x;
    vector<long long> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    long long ans = 0;
    for (int i = 1; i < N; i++) {
        long long diff = nums[i - 1] + nums[i] - x;
        if (0 < diff) {
            nums[i] -= diff;
            nums[i - 1] -= max(0 - nums[i], (long long)0);
            nums[i] = max(nums[i], (long long)0);
            ans += diff;
        }
    }
    cout << ans << endl;
    return 0;
}