#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> nums;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < 500; i++) {
        if (n < i*2020)
            break;
        int res = n - i * 2020;
        if(find(nums.begin(),nums.end(),res) != nums.end()) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
    return;
}

int main() {
    for (int i = 0; i < 500; i++)
        nums.push_back(i * 2021);

    int t;
    cin >> t;
    while (t--)
        solve();
}

// const int mxN = 1e6 + 6;
// int dp[mxN];

// void init()
// {
//     memset(dp, -1, sizeof(dp));
//     dp[2020] = 1;
//     dp[2021] = 1;
//     for (int i = 2022; i < 1e6 + 6; i++)
//     {
//         dp[i] = max(dp[i - 2020], dp[i - 2021]);
//     }
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     string aa = "YES", bb = "NO";

//     debug(dp[n]);
//     cout << (dp[n] == 1 ? aa : bb) << endl;
// }