#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const int Mod = 1e9 + 7;

struct stage{
    vector<int> scope;
    int energe; // (1,k-1]
};

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        cout << 1 << endl;
        return;
    }
    else if (n == 1) {
        cout << 2 << endl;
        return;
    }

    vector<stage> rec;
    vector<int> scope;
    ll ans = 1 + n;
    for (int i = 0; i < n - 1; i++) {
        scope.push_back(i + 1);
    }
    rec.push_back({scope, k - 1});
    while (rec.size()) {
        stage s = rec.back();
        rec.pop_back();

        if (1 < s.energe) {
            vector<int> tep(n - 1, 0);
            ll sum = 0;
            for (int i = n-2; 0 <= i; i--) {
                sum = (sum + s.scope[i]) % Mod;
                tep[n-2-i] = sum;
            }
            ans = (ans + sum) % Mod;
            rec.push_back({tep, s.energe - 1});
        }
    }

    cout << ans << endl;
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}

// struct particle {
//     int energy; // [1, n]
//     int pos; // [1, k]
//     bool direction; // 右 true 左 false
// };

// void solve() {
//     int n, k;
//     cin >> n >> k;
//     if (k == 1) {
//         cout << 1 << endl;
//         return;
//     } else if (n == 1) {
//         cout << 2 << endl;
//         return;
//     }

//     vector<particle> pars;
//     bool direction = true;
//     int ans = 1;
//     for (int i = 0; i < n; i++) {
//         ans++;
//         if (1 < k - 1)
//             pars.push_back({k - 1, i + 1, !direction});
//     }
//     while (pars.size()) {
//         particle p = pars.back();
//         pars.pop_back();
//         if (p.direction) {
//             if (p.energy - 1 == 1) {
//                 ans = (ans + n - p.pos) % Mod;
//                 continue;
//             }
//             for (int i = p.pos; i < n; i++) {
//                 pars.push_back({p.energy - 1, p.pos + 1, !p.direction});
//             }
//         } else {
//             if (p.energy - 1 == 1) {
//                 ans = (ans + p.pos - 1) % Mod;
//                 continue;
//             }
//             for (int i = p.pos; 1 < i; i--) {
//                 pars.push_back({p.energy - 1, p.pos - 1, !p.direction});
//             }
//         }
//     }
//     cout << ans << endl;
// }