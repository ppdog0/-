#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;
using ld = long double;

ll count(int a[], int n) {
    sort(a, a + n);
    return a[n / 2] - a[(n - 1) / 2] + 1;
}

void solve() {
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    cout << count(a, n) * count(b, n) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}

// #include <iostream>
// #include <vector>
// #include <map>

// using namespace std;
// using ll = long long;
// using ld = long double;

// ll sum(ll a[], int n, int k) {
//     ll res = 0;
//     for (int i = 0; i < n; i++) {
//         res += abs(a[i] - k);
//     }
//     return res;
// }

// int bin(ll a[], int n, int lo, int hi) {
//     map<ll, vector<int>> rec;
//     for (int i = lo; i <= hi; i++) {
//         rec[sum(a, n, i)].push_back(i);
//     }
//     return (*rec.begin()).second.size();
// }

// void solve() {
//     int n;
//     cin >> n;
//     ll a[n], b[n];
//     ll mx1 = 0, mi1 = INT64_MAX;
//     ll mx2 = 0, mi2 = INT64_MAX;
//     for (int i = 0; i < n; i++) {
//         cin >> a[i] >> b[i];
//         mi1 = min(mi1, a[i]);
//         mx1 = max(mx1, a[i]);
//         mi2 = min(mi2, b[i]);
//         mx2 = max(mx2, b[i]);
//     }
//     int k1 = bin(a, n, mi1, mx1);
//     int k2 = bin(b, n, mi2, mx2);

//     cout << k1 * k2 << endl;
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
// }