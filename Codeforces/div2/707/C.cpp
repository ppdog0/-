#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

const string Y = "YES";
const string N = "NO";
const int M = 2e7;

int I[M], J[M];

void solve() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x = a[i] + a[j];
            if (I[x] && J[x] && I[x]!=i+1 && I[x]!=j+1 &&J[x]!=j+1 &&J[x]!=i+1) {
                cout << Y << endl;
                cout << i + 1 << " " << j + 1 << " " << I[x] << " " << J[x] << endl;
                return;
            }
            I[x] = i+1;
            J[x] = j+1;
        }
    }
    cout << N << endl;
}

int main() {
    solve();
}

// #include <iostream>
// #include <algorithm>

// using namespace std;
// using ll = long long;
// using ld = long double;

// const string Y = "YES";
// const string N = "NO";

// void solve() {
//     int n;
//     cin >> n;
//     int a[n];
//     for (int &x : a)
//         cin >> x;
//     int rec[n*n] = {0};
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             rec[i*n+j] = a[i] + a[j];
//         }
//     }
//     sort(rec, rec + n * n);
//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             int res = a[i] + a[j];
//             int k = upper_bound(rec, rec + n * n, res) - lower_bound(rec, rec + n * n, res);
//             if (k > 1) {
//                 cout << Y << endl;
//                 return;
//             }
//         }
//     }
//     cout << N << endl;
// }

// int main() {
//     solve();
// }