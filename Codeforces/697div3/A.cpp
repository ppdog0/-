#include<iostream>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    if (n & 1)
    {
        cout << "Yes" << endl;
        return;
    }
    while (n)
    {
        if (n == 1)
        {
            cout << "No" << endl;
            return;
        }
        if (n & 1)
        {
            cout << "Yes" << endl;
            return;
        }
        n >>= 1;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}

// bool flag = false;
// for (long long i = 2; i * i <= n; i += 1)
// {
//     if ((n % i == 0) && (i & 1 || (n / i) & 1))
//     {
//         flag = true;
//         break;
//     }
// }
// if (flag)
//     cout << "Yes" << endl;
// else
//     cout << "No" << endl;