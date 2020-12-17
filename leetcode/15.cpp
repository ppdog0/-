#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
        if (0 < nums[i])
            return ans;
        if (0 <i && nums[i] == nums[i-1])
            continue;
        int l = i + 1, r = n - 1;
        while (l<r) {
            if (nums[i]+nums[l]+nums[r] ==0) {
                ans.push_back(vector<int>{nums[i], nums[l], nums[r]});
                while(l<r && nums[l]==nums[l+1])
                    l++;
                while(l<r&&nums[r]==nums[r-1])
                    r--;
                l++;
                r--;
            } else if (nums[i] + nums[l] + nums[r] > 0) {
                l++;
            } else
                r--;
        }
    }
    return ans;
}

int main () {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    vector<vector<int>> ans = threeSum(nums);
    for (auto it : ans) {
        for (auto it1 : it) {
            cout << it1 << " ";
        }
        cout << endl;
    }
}