#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x:a)
        cin >> x;

    vector<int> cnt(3, 0);
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < n; j++) {
            if (a[j] % 3 == i)
                cnt[i]++;
        }

    int res = 0;
    while(*min_element(cnt.begin(),cnt.end())!=n/3) {
        for (int i = 0; i < 3; i++) {
            if (cnt[i]>n/3) {
                cnt[i]--;
                cnt[(i + 1) % 3]++;
                res++;
            }
        }
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