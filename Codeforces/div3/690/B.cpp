#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

const string Y = "YES";
const string N = "NO";

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;

    for (int i = 0; i <= 4; i++) {
        if (a.substr(0,i)+a.substr(n-4+i,4-i)=="2020") {
            cout << Y << endl;
            return;
        }
    }

    cout << N << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}

// for (int i = 0; i < a.size(); i++) {
//     for (int j = i; j < a.size() - i; j++) {
//         string b = a;
//         if (b.erase(i, j) == "2020") {
//             cout << Y << endl;
//             return;
//         }
//     }
// }

// int i = 0, j = 0;
// while (i < a.size() && j < res.size()) {
//     if (a[i] == res[j]) {
//         j++;
//     }
//     i++;
// }
// if (res.size()<=j && a.size()<=i)
//     cout << Y << endl;
// else
//     cout << N << endl;