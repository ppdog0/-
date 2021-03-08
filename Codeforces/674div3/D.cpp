#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    int a[n];
    ll sum[n + 1]; // 前n个数之和
    sum[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum[i + 1] = sum[i] + a[i];
    }

    int ans = 0;
    vector<pair<int, int>> pos;
    for (int k = 2; k <= n; k++) {
        for (int i = 0; i + k <= n; i++) {
            int curSum = sum[i + k] - sum[i];
            if (curSum == 0) {
                bool flag = true;
                for (auto &[x,y]:pos) {
                    //if (max(x,i) < min(y,i+k-1) ) {
                    if (i<=x && y<=i+k-1) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    pos.push_back({i, i + k - 1});
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    solve();
}

// priority_queue<int, vector<int>, greater<int>> L;
// priority_queue<int, vector<int>, less<int>> R;

// if ((L.empty() || i + k - 1 <= L.top()) ||
//     (R.empty() || R.top() <= i))
// {
//     // cout << i << " " << i + k - 1<<endl;
//     ans++;
//     L.push(i);
//     R.push(i + k - 1);
// }

// int ans = 0;
// int curSum = 0;
// int l = 0, r = 0;
// while (true) {
//     if (n <= r)
//         break;
//     curSum += a[r];
//     if (curSum == 0)
//         ans++;
//     while (l < r && curSum != 0) {
//         curSum -= a[l];
//         l++;
//     }
//     r++;
// }