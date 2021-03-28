#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const string Y = "YES";
const string N = "NO";

void solve() {
    int n, m;
    cin >> n >> m;
    int lim = (m + 1) / 2;

    vector<int> a[n + 1];
    vector<int> b[m];
    int fre[n + 1] = {0};
    int day[m];
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            fre[x]++;
            a[x].push_back(i);
            b[i].push_back(x);
        }
        day[i] = b[i].front();
    }

    int mx = max_element(fre + 1, fre + n + 1) - fre;
    if (fre[mx] <= lim) {
        cout << Y << endl;
        for (int i = 0; i < m; i++) {
            cout << day[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (fre[i] <= lim)
            continue;
        int y = fre[i];
        for (int j = 0; j < a[i].size(); j++) {
            int d = a[i][j];
            day[d] = i;
            if (lim < y)
            for (int k = 0; k < b[d].size(); k++) {
                if (b[d][k] != i) {
                    day[d] = b[d][k];
                    y--;
                    break;
                }
            }
        }
        if (y <= lim) {
            cout << Y << endl;
            for (int i = 0; i < m; i++) {
                cout << day[i] << " ";
            }
            cout << endl;
            return;
        }
    }
    cout << N << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}

// #include <bits/stdc++.h>

// int main()
// {
//     int T;
//     scanf("%d", &T);
//     while (T--)
//     {
//         int n, m;
//         scanf("%d%d", &n, &m);
//         int lim = m / 2 + (m % 2);
//         std::vector<int> cnt(n + 1), ans(m + 1);
//         std::vector<std::queue<int>> frds(m + 1);
//         int mx = 0;
//         for (int i = 0; i < m; ++i)
//         {
//             int k, f;
//             scanf("%d", &k);
//             scanf("%d", &f);
//             --k;
//             ans[i] = f;
//             ++cnt[f];
//             if (cnt[f] > cnt[mx])
//                 mx = f;
//             while (k--)
//             {
//                 scanf("%d", &f);
//                 frds[i].push(f);
//             }
//         }
//         for (int i = 0; i < m; ++i)
//         {
//             if (cnt[mx] <= lim)
//                 break;
//             if (ans[i] != mx || frds[i].empty())
//                 continue;
//             ans[i] = frds[i].front();
//             --cnt[mx];
//         }
//         if (cnt[mx] > lim)
//             printf("NO\n");
//         else
//         {
//             printf("YES\n");
//             for (int i = 0; i < m; ++i)
//                 printf("%d ", ans[i]);
//             puts("");
//         }
//     }
//     return 0;
// }