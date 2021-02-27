#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    ll a[n], res = 0, tol = 0;
    int curInd = 0;
    vector<ll> pref;
    vector<int> ind;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tol += a[i];
        res = max(res, tol);
        if (pref.empty() || tol > pref.back()) {
            pref.push_back(tol);
            ind.push_back(curInd);
        }
        curInd++;
    }

    for (int i = 0; i < m; i++) {
        ll x;
        cin >> x;
        if (res < x && tol <= 0) {
            cout << -1 << " ";
            continue;
        }

        ll times = 0;
        if (res < x) {
            times = (x - res + tol - 1) / tol;
        }
        x -= times * tol;
        cout << times * n + ind[lower_bound(pref.begin(), pref.end(), x) - pref.begin()] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}