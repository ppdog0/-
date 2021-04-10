#include <iostream>
#include <map>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;

    map<int,int> nums;
    vector<int> pos;
    for (int i = 0; i < n; i++)
    {
        nums[a[i]]++;
        if (nums[a[i]] == 1) {
            pos.push_back(i);
        }
    }

    for (auto x:nums) {
        if (x.second == 1) {
            for (auto y:pos) {
                if (a[y] == x.first) {
                    cout << y+1 << endl;
                }
            }
            return;
        }
    }
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}