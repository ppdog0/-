#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N;

int main() {
    cin >> N;
    vector<int> nums(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        sum += nums[i];
    }
    int x = floor(sum / N);
    int y = ceil((float)sum / N);
    int ans1 = 0, ans2 = 0;
    for(auto index : nums) {
        ans1 += (index - x) * (index - x);
        ans2 += (index - y) * (index - y);
    }
    cout << min(ans1, ans2) << endl;
    return 0;
    // sort(nums.begin(), nums.end());
    // if( N==0 || nums[0]==nums[nums.size()-1]) {
    //     cout << 0 << endl;
    //     return 0;
    // }

    // int ans = INF;
    // int mid = (0 + nums.size() - 1) >> 1;
    // for (int i = nums[mid]; i <= nums[mid + 1]; i++) {
    //     int cost = 0;
    //     for(auto index : nums) {
    //         int base = index - i;
    //         cost += base * base;
    //     }
    //     ans = min(ans, cost);
    // }
    // cout << ans << endl;
    // return 0;
}