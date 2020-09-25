#include<iostream>
#include<vector>
#include<string>

using namespace std;

string str;

// 二进制思想，枚举所有状态
int main() {
    cin >> str;

    int N = str.size();
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        nums[i] = str[i] - '0';

    long long sum = 0;
    for (int i = 1<<(N-1); i < (1 << N); i++) {
        long long ans = 0;
        for (int j = 0; j < N; j++) {
            ans = ans * 10 + nums[j];
            if(i&(1<<j)) {
                sum += ans;
                ans = 0;
            }
        }
    }
    cout << sum << endl;
    return 0;
}