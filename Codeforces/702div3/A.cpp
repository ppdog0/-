#include <iostream>
#include<vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    int pos = 0, ans = 0;
    while(true) {
        if (pos==a.size()-1)
            break;
        if (a[pos]*2<a[pos+1]) {
            a.insert(a.begin() + pos + 1, a[pos] * 2);
            ans++;
            pos++;
        }
        else if (a[pos + 1] * 2 < a[pos]) {
            a.insert(a.begin() + pos + 1, a[pos + 1] * 2);
            ans++;
        } else
            pos++;
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}