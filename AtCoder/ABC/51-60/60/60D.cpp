#include<iostream>
#include<algorithm>
#include<map>

using namespace std;
const int max_n = 105;

int n, W;
int w[max_n], v[max_n];
map<int, int, greater<int>> dp; // 从后向前迭代，注意顺序

int main() {
    cin >> n >> W;
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (auto &x : dp) {
			if (x.first + w[i] <= W) {
				dp[x.first + w[i]] = max(dp[x.first + w[i]], dp[x.first] + v[i]);
			}
		}
	}
	int ans = 0;
	for (auto &x : dp)
		ans = max(ans, x.second);
	cout << ans << endl;
}

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;

// int n, m, ans = 0;
// map<int, int, greater<int>> dp;

// int main() {
// 	cin >> n >> m;
// 	dp[0] = 0;
// 	for (int i = 0, w, v; i < n; ++i) {
// 		cin >> w >> v;
// 		for (auto &x : dp)
// 			if (x.first + w <= m)
// 				dp[x.first + w] = max(dp[x.first + w], dp[x.first] + v);
// 	}
// 	for (auto &x : dp)
// 		ans = max(ans, x.second);
// 	cout << ans << endl;
// }
