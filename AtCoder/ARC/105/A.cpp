#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int A, B, C, D;
vector<int> nums(4);

int main() {
    for (int i = 0; i < 4; i++)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    if(nums[0]+nums[3]==nums[1]+nums[2] || nums[3]==nums[0]+nums[1]+nums[2])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}