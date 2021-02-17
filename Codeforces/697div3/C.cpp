// 二分图匹配

#include <iostream>
#include<algorithm>

using namespace std;

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    pair<int, int> couple[k];
    for (int i = 0; i < k; i++)
        cin >> couple[i].first >> couple[i].second;
    sort(couple, couple + k);
    int ans = 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}