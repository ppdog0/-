#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> lim;
    vector<int> vul;

    int pos[n + 1] = {0};
    int perm[n] = {0};

    bool visit[n + 1] = {false};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (!visit[x]) {
            perm[i] = x;
            pos[x] = i;
            visit[x] = true;

            lim.push_back(x);
        } else {
            vul.push_back(i);
        }
    }

    vector<int> nums;
    for (int i = 0; i < n; i++) {
        if (!visit[i+1])
            nums.push_back(i + 1);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        int y;
        if (perm[i])
            y = perm[i];
        else
            y = nums[k++];
        cout << y << " ";
    }
    cout << endl;

    int m = nums.size();
    for (int i = 0; i < m; i++) {
        int y = nums.back();
        nums.pop_back();
        int a = *lower_bound(lim.begin(), lim.end(), y);
        int b = pos[a];
        auto c = lower_bound(vul.begin(), vul.end(), b);
        perm[*c] = y;
        vul.erase(c);
    }

    for (int i = 0; i < n; i++) {
        cout << perm[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}