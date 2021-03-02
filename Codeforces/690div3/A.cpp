#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

void solve()
{
    int n;
    cin >> n;
    int b[n];
    for (int &x : b)
        cin >> x;
    int i = 0, l = 0, r = n - 1;
    int a[n];
    while (l < r) {
        a[i++] = b[l++];
        a[i++] = b[r--];
    }
    if (n%2 != 0)
        a[n - 1] = b[l];
    for (auto x:a)
        cout << x << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}