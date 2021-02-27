#include <iostream>
#include <map>

typedef long long ll;
using namespace std;

void solve()
{
    int n;
    cin >> n;
    map<int, int> rec;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        rec[x]++;
    }

    map<int, int> groupRec;
    for (auto[x, y] : rec) {
        groupRec[y]++;
    }

    int res = n;
    int left = 0, right = n, rightCnt = rec.size();
    for (auto[x, y] : groupRec) {
        res = min(res, left + right - rightCnt * x);
        left += x * y;
        right -= x * y;
        rightCnt -= y;
    }
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}