#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    for (int &x : a) {
        cin >> x;
        sum += x;
    }

    for (int i = n; 0 < i; i--) {
        if (sum % i == 0) {
            bool flag = true;
            int needSum = sum / i;
            int curSum = 0;
            for (int j = 0; j < n; j++) {
                curSum += a[j];
                if (curSum == needSum) {
                    curSum = 0;
                }
                else if (needSum < curSum) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                cout << n - i << endl;
                return;
            }
        }
    }
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
// #include <algorithm>

// using namespace std;
// using ll = long long;
// using ld = long double;

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<int> a(n);
//     map<int,int> rec;
//     for (int &x : a) {
//         cin >> x;
//         rec[x]++;
//     }
//     if (rec.size() == 1) {
//         cout << 0 << endl;
//         return;
//     }
//     int ans = 0;
//     while (true) {
//         if (rec.size() == 1)
//             break;
//         int m = min_element(a.begin(), a.end()) - a.begin();
//         int mn1 = m - 1, mn2 = m + 1;
//         int amn = -1;
//         if (mn1 < 0 || a.size() <= mn1)
//             amn = mn2;
//         else if (mn2 < 0 || a.size() <= mn2)
//             amn = mn1;
//         else
//             amn = a[mn1] <= a[mn2] ? mn1 : mn2;
//         rec[a[amn]]--;
//         if (rec[a[amn]]==0)
//             rec.erase(a[amn]);
//         rec[a[m]]--;
//         if (rec[a[m]] == 0)
//             rec.erase(a[m]);
//         a[amn] += a[m];
//         rec[a[amn]]++;
//         a.erase(a.begin() + m);
//         ans++;
//     }
//     cout << ans << endl;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
// }